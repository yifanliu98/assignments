package exer9

import (
	"math"
	"math/rand"
	"reflect"
	"sort"
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
)

func TestRandomArrays(t *testing.T) {
	length := 1000
	maxint := 100
	arr1 := RandomArray(length, maxint)
	assert.Equal(t, length, len(arr1))
	for _, v := range arr1 {
		assert.True(t, 0 <= v, "contains a negative integer")
		assert.True(t, v < maxint, "contains an integer >=maxint")
	}

	// check that different calls return different results
	arr2 := RandomArray(length, maxint)
	assert.False(t, reflect.DeepEqual(arr1, arr2))
}

func TestArrayStatParallel(t *testing.T) {
	length := 30000000
	maxint := 10000
	arr2 := RandomArray(length, maxint)

	// call MeanStddev single-threaded
	start := time.Now()
	mean2, stddev2 := MeanStddev(arr2, 1)
	end := time.Now()
	dur1 := end.Sub(start)

	// now turn on cuncurrency and make sure we get the same results, but faster
	start = time.Now()
	mean3, stddev3 := MeanStddev(arr2, 3)
	end = time.Now()
	dur2 := end.Sub(start)

	speedup := float64(dur1) / float64(dur2)
	assert.True(t, speedup > 1.25, "Running MeanStddev with concurrency didn't speed up as expected. Sped up by %g.", speedup)
	assert.Equal(t, float32(mean2), float32(mean3)) // compare as float32 to avoid rounding differences
	assert.Equal(t, float32(stddev2), float32(stddev3))
}

// copied from https://golang.org/src/math/rand/rand.go?s=7456:7506#L225 for Go <1.10 compatibility
func shuffle(n int, swap func(i, j int)) {
	r := rand.New(rand.NewSource(time.Now().UTC().UnixNano()))
	if n < 0 {
		panic("invalid argument to shuffle")
	}

	i := n - 1
	for ; i > 1<<31-1-1; i-- {
		j := int(r.Int63n(int64(i + 1)))
		swap(i, j)
	}
	for ; i > 0; i-- {
		j := int(r.Int31n(int32(i + 1)))
		swap(i, j)
	}
}

func benchmarkSorting(b *testing.B, sort func(arr []float64)) {
	const length = 1000
	arr := make([]float64, length)
	for i := 0; i < length; i++ {
		arr[i] = float64(i)
	}

	// run the benchmark
	for n := 0; n < b.N; n++ {
		shuffle(length, func(i, j int) {
			arr[i], arr[j] = arr[j], arr[i]
		})
		sort(arr)
	}
}

func BenchmarkInsertionSort(b *testing.B) { benchmarkSorting(b, InsertionSort) }
func BenchmarkQuickSort(b *testing.B)     { benchmarkSorting(b, QuickSort) }
func BenchmarkFloat64s(b *testing.B)      { benchmarkSorting(b, sort.Float64s) }

func TestPointScaling(t *testing.T) {
	p := Point{1, 2}
	p.Scale(5)
	assert.Equal(t, 5.0, p.x)
	assert.Equal(t, 10.0, p.y)
}

func TestPointRotate(t *testing.T) {
	p := Point{1, 0}
	p.Rotate(math.Pi / 4)
	assert.Equal(t, float32(math.Sqrt(2)/2), float32(p.x))
	assert.Equal(t, float32(math.Sqrt(2)/2), float32(p.y))
	p.Rotate(math.Pi / 2)
	assert.Equal(t, float32(-math.Sqrt(2)/2), float32(p.x))
	assert.Equal(t, float32(math.Sqrt(2)/2), float32(p.y))
}

func TestMeanStddev(t *testing.T) {
	length := 30000000
	maxint := 10000
	arr := RandomArray(length, maxint)

	// call MeanStddev single-threaded
	start := time.Now()
	mean1, stddev1 := MeanStddev(arr, 1)
	end := time.Now()
	dur1 := end.Sub(start)

	// now turn on cuncurrency and make sure we get the same results, but faster
	start = time.Now()
	mean2, stddev2 := MeanStddev(arr, 3)
	end = time.Now()
	dur2 := end.Sub(start)

	speedup := float64(dur1) / float64(dur2)
	assert.True(t, speedup > 1.25, "Running MeanStddev with concurrency didn't speed up as expected. Sped up by %g.", speedup)
	assert.Equal(t, float32(mean1), float32(mean2)) // compare as float32 to avoid rounding differences
	assert.Equal(t, float32(stddev1), float32(stddev2))

}

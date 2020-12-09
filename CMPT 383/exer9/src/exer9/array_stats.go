package exer9

import (
	"math"
	"math/rand"
	"time"
)

func RandomArray(length int, maxInt int) []int {
	rand.Seed(time.Now().UnixNano())
	arr := make([]int, length)
	for i := 0; i < length; i++ {
		arr[i] = rand.Intn(maxInt)
	}
	return arr
}

type Sum struct {
	sum, sumSquare float64
}

func MeanStddev(arr []int, chunks int) (mean, stddev float64) {
	if len(arr)%chunks != 0 {
		panic("You promised that chunks would divide slice size!")
	}
	// TODO: calculate the mean and population standard deviation of the array, breaking the array into chunks segments
	// and calculating on them in parallel.

	ch := make(chan Sum)

	length := len(arr)
	size := length / chunks
	for i := 0; i < chunks; i++ {
		subarr := arr[i*size : (i+1)*size]
		go calculation(subarr, ch)
	}

	var sum float64 = 0
	var sumSquare float64 = 0

	for i := 0; i < chunks; i++ {
		partial := <-ch
		sum += partial.sum
		sumSquare += partial.sumSquare
	}

	mean = sum / float64(length)
	stddev = math.Sqrt(sumSquare/float64(length) - mean*mean)

	return mean, stddev
}

func calculation(arr []int, ch chan Sum) {

	var sum, sumSquare float64
	length := len(arr)
	for i := 0; i < length; i++ {
		value := arr[i]
		sum += float64(value)
		sumSquare += float64(value * value)
	}
	ch <- Sum{sum, sumSquare}
}

package exer9

import (
	"math/rand"
)

// Partition the slice arr around a random pivot (in-place), and return the pivot location.
func partition(arr []float64) int {
	// Adapted from https://stackoverflow.com/a/15803401/6871666
	left := 0
	right := len(arr) - 1

	// Choose random pivot
	pivotIndex := rand.Intn(len(arr))

	// Stash pivot at the right of the slice
	arr[pivotIndex], arr[right] = arr[right], arr[pivotIndex]

	// Move elements smaller than the pivot to the left
	for i := range arr {
		if arr[i] < arr[right] {
			arr[i], arr[left] = arr[left], arr[i]
			left++
		}
	}

	// Place the pivot after the last-smaller element
	arr[left], arr[right] = arr[right], arr[left]
	return left
}

func InsertionSort(arr []float64) {
	length := len(arr)
	if length <= 1 {
		return
	}
	for i := 1; i < length; i++ {
		value := arr[i]
		j := i - 1
		for j >= 0 && value < arr[j] {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = value
	}
}

const insertionSortCutoff = 10000

func QuickSort(arr []float64) {
	length := len(arr)
	if length < 2 {
		return
	} else if length < insertionSortCutoff {
		InsertionSort(arr)
	} else {
		pivotIndex := partition(arr)
		smaller := arr[0:pivotIndex]
		larger := arr[pivotIndex+1 : length]
		QuickSort(smaller)
		QuickSort(larger)
	}
}

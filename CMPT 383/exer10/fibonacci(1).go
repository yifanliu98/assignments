// package exer10
package main

import (
	"fmt"
	"time"
)

func Fib(n uint, cutoff uint) uint {

	// calculates Fibonacci numbers
	if n > cutoff {
		var number = make(chan uint, 1)
		FibCurrent(n, number)
		return <-number
	} else {
		return FibSequence(n)
	}

}

func FibSequence(n uint) uint {
	if n == 1 || n == 0 {
		return 1
	} else {
		return FibSequence(n-1) + FibSequence(n-2)
	}
}

func FibCurrent(n uint, currentNum chan uint) {

	if n == 1 || n == 0 {
		currentNum <- 1
		return
	}
	fib_1 := make(chan uint, 1)
	fib_2 := make(chan uint, 1)
	go FibCurrent(n-1, fib_1)
	go FibCurrent(n-2, fib_2)
	fib1 := <-fib_1
	fib2 := <-fib_2
	currentNum <- fib1 + fib2
	return

}

func Fibonacci(n uint) uint {
	return Fib(n, 0)
}

func main() {
	start := time.Now()
	num := Fibonacci(40)
	end := time.Now()
	dur := end.Sub(start)
	fmt.Println(dur)
	fmt.Println(num)
}

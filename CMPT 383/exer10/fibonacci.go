// package exer10
package main

import (
	"fmt"
	"time"
)

type SubNums struct {
	sub1, sub2 uint
}

func Fibonacci(n uint) uint {
	return Fib(n, 40)
}

func Fib(n uint, cutoff uint) uint {
	if n <= 1 {
		return uint(1)
	}
	if n <= cutoff {
		return Fib(n-1, cutoff) + Fib(n-2, cutoff)
	}
	// concurrent steps
	ch := make(chan SubNums)
	go calculation(n, ch)
	partial := <-ch
	return partial.sub1 + partial.sub2
}

// func Fib(n uint, cutoff uint) uint {
// 	if n <= 1 {
// 		return uint(1)
// 	}
// 	if n <= cutoff {
// 		return Fib(n-1, cutoff) + Fib(n-2, cutoff)
// 	}
// 	// concurrent steps
// 	ch := make(chan SubNums)
// 	go calculation(n, ch)
// 	partial := <-ch
// 	return partial.sub1 + partial.sub2
// }

// func calculation(n uint, ch chan SubNums) {
// 	ch <- SubNums{Fibonacci(n - 1), Fibonacci(n - 2)}
// }

func main() {
	start := time.Now()
	num := Fibonacci(40)
	end := time.Now()
	dur := end.Sub(start)
	fmt.Println(dur)
	fmt.Println(num)
}

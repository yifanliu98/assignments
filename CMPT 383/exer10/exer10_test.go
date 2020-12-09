package exer10

import (
	"fmt"
	"testing"
	"time"
)

func TestFibonacci(t *testing.T) {

	// call MeanStddev single-threaded
	start := time.Now()
	num := Fibonacci(10)
	end := time.Now()
	dur := end.Sub(start)
	fmt.Println(dur)
	fmt.Println(num)

}

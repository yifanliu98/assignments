package main

import (
	"fmt"
	"strings"
)

func main() {
	// for loop
	for i := 0; i < 10; i++ {

	}

	i := 0
	for i < 10 {
		i++
	}

	for {
		break
	}

	// if
	x := 0
	if x < 0 {

	} else {

	}

	if v := 0; v < x {
		fmt.Println(v)
	} else if v < 10 {

	} else {
		fmt.Println(v)
	}

	// switch case
	switch flag := true; flag {
	case true:
		fmt.Println("flag is true")
	case false:
		fmt.Println("flag is false")
	default:
		fmt.Println("unreachable case")
	}

	switch {
	case x < 0:

	case x < 1:
	default:

	}

	// defer : stacck
	// fmt.Println("counting")
	// for i := 0; i < 10; i++ {
	// 	defer fmt.Println(i)
	// }
	// fmt.Println("done")

	// pointer (nil is nullptr) *T
	var p *int
	value := 10
	p = &value
	*p = 20

	// structs: a collection of fields
	type Vertex struct {
		X int
		Y int
	}
	fmt.Println(Vertex{1, 2})
	v := Vertex{1, 2}
	v.X = 4
	fmt.Println(v)
	pV := &v
	pV.Y = 5
	fmt.Println(v)
	var pVec *Vertex = &Vertex{3, 4}
	fmt.Println(*pVec)

	// array: static
	// 	var arr [10]int
	// slice: dynamic array
	primes := [6]int{2, 3, 5, 7, 11, 13}
	var s []int = primes[1:4] // reference of primes

	// length and capacity
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)

	// slices of slices
	board := [][]string{
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
	}
	board[0][0] = "X"
	board[2][2] = "O"
	board[1][2] = "X"
	board[1][0] = "O"
	board[0][2] = "X"
	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}

	// range
	var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}
}

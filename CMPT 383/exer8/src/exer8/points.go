package exer8

import (
	"fmt"
	"math"
)

// TODO: The Point struct, NewPoint function, .String and .Norm methods

type Point struct {
	x, y float64
}

func (point Point) String() string {
	return fmt.Sprintf("(%v, %v)", point.x, point.y)
}

func (point Point) Norm() float64 {
	sum := point.x*point.x + point.y*point.y
	return math.Sqrt(sum)
}

func NewPoint(x, y float64) Point {
	return Point{x, y}
}

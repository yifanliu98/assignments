package exer10

import (
	"fmt"
	"math"
)

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

func (point *Point) Scale(factor float64) {
	point.x *= factor
	point.y *= factor
}

func (point *Point) Rotate(angle float64) {
	sin, cos := math.Sincos(angle)
	oldX := point.x
	oldY := point.y
	point.x = oldX*cos - oldY*sin
	point.y = oldX*sin + oldY*cos
}

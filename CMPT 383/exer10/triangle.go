package exer10

import "fmt"

type Triangle struct {
	A, B, C Point
}

func (t Triangle) String() string {
	return fmt.Sprintf("[%s %s %s]", t.A, t.B, t.C)
}

func (t *Triangle) Scale(factor float64) {
	t.A.Scale(factor)
	t.B.Scale(factor)
	t.C.Scale(factor)
}

func (t *Triangle) Rotate(angle float64) {
	t.A.Rotate(angle)
	t.B.Rotate(angle)
	t.C.Rotate(angle)
}

type Transformable interface {
	Scale(float64)
	Rotate(float64)
}

func TurnDouble(t Transformable, angle float64) {
	t.Scale(2)
	t.Rotate(angle)
}

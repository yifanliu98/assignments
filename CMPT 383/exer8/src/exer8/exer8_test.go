package exer8

import (
	"reflect"
	"testing"
)

// Test the Hailstone function
func TestHailstone(t *testing.T) {
	h17 := Hailstone(17)
	if h17 != uint(52) {
		t.Error("Wrong Hailstone(17) result:", h17)
	}

	h18 := Hailstone(18)
	if h18 != uint(9) {
		t.Error("Wrong Hailstone(18) result:", h18)
	}
}

// Basic test for the HailstoneSequence* functions
func TestHailstoneSeq(t *testing.T) {
	hail5 := []uint{5, 16, 8, 4, 2, 1}
	seqapp := HailstoneSequenceAppend(5)
	if !reflect.DeepEqual(seqapp, hail5) {
		t.Error("Incorrect HailstoneSequenceAppend(5):", seqapp)
	}

	seqlen := HailstoneSequenceAllocate(5)
	if !reflect.DeepEqual(seqlen, hail5) {
		t.Error("Incorrect HailstoneSequenceAllocate(5):", seqlen)
	}
}

// Make sure the two HailstoneSeq* functions return the same results for a variety of situations.
func TestHailstoneSame(t *testing.T) {
	nums := []uint{18, 4, 12345, 2912, 686901248, 228, 1}
	for _, n := range nums {
		app := HailstoneSequenceAppend(n)
		alloc := HailstoneSequenceAllocate(n)
		if !reflect.DeepEqual(app, alloc) {
			t.Errorf("Different HailstoneSequence* results for n=%v", n)
		}
	}
}

// Helper to time a HailstoneSeq* function, making sure we run each the same way.
func benchmarkHailSeq(b *testing.B, hailstoneSeq func(uint) []uint) {
	for n := 0; n < b.N; n++ {
		hailstoneSeq(17)
		hailstoneSeq(11)
		hailstoneSeq(686901248)
		hailstoneSeq(1)
	}
}

// Benchmark the two HailstoneSeq* functions to compare running time.
func BenchmarkHailSeqAppend(b *testing.B) {
	benchmarkHailSeq(b, HailstoneSequenceAppend)
}
func BenchmarkHailSeqAllocate(b *testing.B) {
	benchmarkHailSeq(b, HailstoneSequenceAllocate)
}

// Test the constructor function for a Point vs the struct literal creation.
func TestPointConstruct(t *testing.T) {
	ptConst := NewPoint(3, 4)
	ptLit := Point{3, 4}
	if ptConst != ptLit {
		t.Error("Constructor doesn't build the correct struct")
	}
}

// Test the Point.String() method.
func TestPointString(t *testing.T) {
	pt := NewPoint(3, 4.5)
	s := pt.String()
	if s != "(3, 4.5)" {
		t.Errorf("Wrong string representation of Point: %#v", s)
	}

	pt = NewPoint(-10.5, 0)
	s = pt.String()
	if s != "(-10.5, 0)" {
		t.Errorf("Wrong string representation of Point: %#v", s)
	}
}

// Test the Point.Norm() method.
func TestPointNorm(t *testing.T) {
	ptConst := NewPoint(3, 4)

	if ptConst.Norm() != 5.0 {
		t.Error("Wrong point norm:", ptConst.Norm())
	}

	pt2 := Point{12.34, 23.45}
	if pt2.Norm() != 26.4986433615006 {
		t.Error("Wrong point norm:", pt2.Norm())
	}
}

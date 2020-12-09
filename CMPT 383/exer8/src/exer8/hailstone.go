package exer8

// TODO: your Hailstone, HailstoneSequenceAppend, HailstoneSequenceAllocate functions
func Hailstone(n uint) uint {
	if n%2 == 0 {
		return n / 2
	} else {
		return 3*n + 1
	}
}

func HailstoneSequenceAppend(n uint) []uint {
	seq := []uint{}
	for ; n != 1; n = Hailstone(n) {
		seq = append(seq, n)
	}
	return append(seq, n)
}

func HailstoneSequenceAllocate(n uint) []uint {
	length := 1
	next := n
	for ; next != 1; next = Hailstone(next) {
		length++
	}

	seq := make([]uint, length)
	for i, _ := range seq {
		seq[i] = n
		n = Hailstone(n)
	}

	return seq
}

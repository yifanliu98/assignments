package blockchain

import (
	"encoding/hex"
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestInitial(t *testing.T) {
	block := Initial(2)
	assert.True(t, block.Data == "", "Data initialized incorrectly")
	assert.True(t, block.Difficulty == 2, "Difficulty initialized incorrectly")
	assert.True(t, block.Generation == 0, "Generation initialized incorrectly")
	for _, v := range block.PrevHash {
		assert.True(t, v == '\x00', "PrevHash initialized incorrectly")
	}
}

func TestNext(t *testing.T) {
	b0 := Initial(19)
	b0.SetProof(87745)
	b1 := b0.Next("hash example 1234")
	b1.SetProof(1407891)
	assert.False(t, b1.ValidHash())

	b1.SetProof(346082)
	assert.False(t, b1.ValidHash())

}

func TestCalcHash(t *testing.T) {
	b0 := Initial(16)
	b0.Mine(1)
	b1 := b0.Next("message")
	b1.Mine(1)
}

func TestMine(t *testing.T) {
	b0 := Initial(16)
	fmt.Println(b0.Proof, hex.EncodeToString(b0.PrevHash))
	b0.Mine(1)
	fmt.Println(b0.Proof, hex.EncodeToString(b0.Hash))
	b1 := b0.Next("message")
	b1.Mine(1)
	fmt.Println(b1.Proof, hex.EncodeToString(b1.Hash))
}

func TestMine2(t *testing.T) {
	b0 := Initial(16)
	b0.Mine(1)
	fmt.Println(b0.Proof, hex.EncodeToString(b0.Hash))
	b1 := b0.Next("this is an interesting message")
	b1.Mine(1)
	fmt.Println(b1.Proof, hex.EncodeToString(b1.Hash))
	b2 := b1.Next("this is not interesting")
	b2.Mine(1)
	fmt.Println(b2.Proof, hex.EncodeToString(b2.Hash))
}

package blockchain

import (
	"crypto/sha256"
	"fmt"
)

// Block is a representation of a block in the chain
type Block struct {
	PrevHash   []byte
	Generation uint64
	Difficulty uint8
	Data       string
	Proof      uint64
	Hash       []byte
}

// Create new initial (generation 0) block.
func Initial(difficulty uint8) Block {
	block := Block{
		Generation: 0,
		Difficulty: difficulty,
		Data:       "",
		PrevHash:   make([]byte, 64),
	}
	return block
}

// Create new block to follow this block, with provided data.
func (prev_block Block) Next(data string) Block {
	block := Block{
		Generation: prev_block.Generation + 1,
		Difficulty: prev_block.Difficulty,
		Data:       data,
		PrevHash:   prev_block.Hash,
	}
	return block
}

// Calculate the block's hash.
// learnt from https://stackoverflow.com/questions/10701874/generating-the-sha-hash-of-a-string-using-golang
func (blk Block) CalcHash() []byte {
	str := fmt.Sprintf("%x:%d:%d:%s:%d", blk.PrevHash, blk.Generation, blk.Difficulty, blk.Data, blk.Proof)
	hash := sha256.New()
	hash.Write([]byte(str))
	return hash.Sum(nil)
}

// Is this block's hash valid?
func (blk Block) ValidHash() bool {
	ends := blk.Hash[len(blk.Hash)-int(blk.Difficulty/uint8(8)):]
	for _, bit := range ends {
		if bit != 0 {
			return false
		}
	}
	return true
}

// Set the proof-of-work and calculate the block's "true" hash.
func (blk *Block) SetProof(proof uint64) {
	blk.Proof = proof
	blk.Hash = blk.CalcHash()
}

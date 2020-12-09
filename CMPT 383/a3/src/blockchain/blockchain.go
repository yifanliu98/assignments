package blockchain

import "reflect"

type Blockchain struct {
	Chain []Block
}

func (chain *Blockchain) Add(blk Block) {
	// You can remove the panic() here if you wish.
	if !blk.ValidHash() {
		panic("adding block with invalid hash")
	}
	chain.Chain = append(chain.Chain, blk)
}

func (chain Blockchain) IsValid() bool {
	if chain.Chain[0].Generation != 0 {
		return false
	}

	for _, v := range chain.Chain[0].PrevHash {
		if v != 0 {
			return false
		}
	}

	diff := chain.Chain[0].Difficulty
	for gen, blk := range chain.Chain {
		if gen == 0 {
			continue
		}
		if blk.Generation != uint64(gen) {
			return false
		}
		if blk.Difficulty != diff {
			return false
		}
		if !reflect.DeepEqual(blk.PrevHash, chain.Chain[gen-1].Hash) {
			return false
		}
		if !reflect.DeepEqual(blk.Hash, blk.CalcHash()) {
			return false
		}

		if !blk.ValidHash() {
			return false
		}
	}
	return true
}

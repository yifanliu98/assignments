package blockchain

import (
	"work_queue"
)

type miningWorker struct {
	work_queue.Worker
	rangeArr []uint64
	block    Block
}

type MiningResult struct {
	Proof uint64 // proof-of-work value, if found.
	Found bool   // true if valid proof-of-work was found.
}

func (mine *miningWorker) Run() interface{} {
	for _, v := range mine.rangeArr {
		mine.block.SetProof(v)
		if mine.block.ValidHash() {
			return MiningResult{v, true}
		}
	}
	return MiningResult{Found: false}
}

// Mine the range of proof values, by breaking up into chunks and checking
// "workers" chunks concurrently in a work queue. Should return shortly after a result
// is found.
func (blk Block) MineRange(start uint64, end uint64, workers uint64, chunks uint64) MiningResult {
	queue := work_queue.Create(uint(workers), uint(chunks))
	size := (end - start + 1) / chunks
	elem := start
	for i := uint64(0); i < chunks; i++ {
		arr := make([]uint64, size)
		for j := uint64(0); j < size; j++ {
			arr[j] = elem
			elem++
		}
		mine := new(miningWorker)
		mine.rangeArr = arr
		mine.block = blk
		queue.Enqueue(mine)
	}
	for {
		result := <-queue.Results
		mineRes := result.(MiningResult)
		if mineRes.Found {
			queue.Shutdown()
			return mineRes
		}
	}
}

// Call .MineRange with some reasonable values that will probably find a result.
// Good enough for testing at least. Updates the block's .Proof and .Hash if successful.
func (blk *Block) Mine(workers uint64) bool {
	reasonableRangeEnd := uint64(4 * 1 << blk.Difficulty) // 4 * 2^(bits that must be zero)
	mr := blk.MineRange(0, reasonableRangeEnd, workers, 4321)
	if mr.Found {
		blk.SetProof(mr.Proof)
	}
	return mr.Found
}

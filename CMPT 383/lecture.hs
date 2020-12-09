import System.Random

bigCalculation :: Integer -> Integer
bigCalculation n = n^n^n

threeRand :: IO [Int]
threeRand = do
    gen <- newStdGen
    return $ take 3 $ randomRs (1, 100) gen

randInts :: Int -> Int -> Int -> IO [Int]
randInts n min max = do
    gen <- newStdGen
    return $ take n $ randomRs (min, max) gen

histogram :: (Enum a, Eq a, Ord a) => [a] -> [String]
histogram vals = bars
    where
        counts = [length $ filter (==i) vals | i <- [(minimum vals)..maximum vals]]
        bars = [take n $ repeat 'X' | n <- counts]

printHisto :: IO ()
printHisto = do
    vals <- randInts 1000 1 20
    let bars = histogram vals
    mapM_ putStrLn bars
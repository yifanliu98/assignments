import Data.Ratio
import Data.List.Split

-- Rational Numbers
rationalSum :: Int -> [Ratio Int]
rationalSum n = [i % j | i <- [1..n], j <- [1..n], i + j == n]

-- Lowest Terms Only
rationalSumLowest :: Int -> [Ratio Int]
rationalSumLowest n = [i % j | i <- [1..n], j <- [1..n], i + j == n, (gcd i j) == 1]

-- All Rational Numbers
rationals :: [Ratio Int]
rationals = func 2
    where
        func n = rationalSumLowest n ++ func (n + 1)

-- Input/Output
sumFile :: IO ()
sumFile = do
    x <- readFile "input.txt"
    let numbers = getNum x
    let result = sum numbers
    print result
        where 
            readInt x = read x :: Int
            getNum str = map readInt (lines str)

import Data.Time.Calendar
import Data.Time.Calendar.OrdinalDate

-- Merging
merge :: Ord t => [t] -> [t] -> [t]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x < y = x : merge xs (y:ys)
    | otherwise = y : merge (x:xs) ys

-- Tail Recursive Hailstone
hailstone :: Int -> Int
hailstone n
    | even n = n `div` 2
    | otherwise = 3 * n + 1

hailLen :: Int -> Int
hailLen n = hailTail 0 n
    where
        hailTail a 1 = a
        hailTail a n = hailTail (a+1) (hailstone n)

-- Factorial
fact :: Int -> Int
fact n = factTail 1 n
    where
        factTail a 0 = a
        factTail a n = factTail (a*n) (n-1)

-- Factorial with a fold
fact' :: Int -> Int
fact' n = foldl (*) 1 [1..n]

-- Haskell Library and Dates
daysInYear :: Integer -> [Day]
daysInYear y = [jan1..dec31]
    where jan1 = fromGregorian y 1 1
        dec31 = fromGregorian y 12 31

isFriday :: Day -> Bool
isFriday day = snd (mondayStartWeek day) == 5

isPrimeDay :: Day -> Bool
isPrimeDay day = isPrime (getDay (toGregorian day))
    where
        getDay (y,m,d) = d
        isPrime 1 = False
        isPrime 2 = True
        isPrime n = [i | i <- [2..(n `div` 2)], n `mod` i == 0] == []

primeFridays :: Integer -> [Day]
primeFridays year = filter isFriday (filter isPrimeDay (daysInYear year))

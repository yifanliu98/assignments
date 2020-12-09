hailstone n
    | even n = n `div` 2
    | otherwise = 3 * n + 1

hailLen 1 = 0
hailLen n = 1 + hailLen (hailstone n)

divisors :: Int -> [Int]
divisors n = [i | i <- [2..(n `div` 2)], n `mod` i == 0]
primes :: Int -> [Int]
primes n = [i | i <- [2..n], divisors i == []]

join _ [] = ""
join _ (list:[]) = list
join string (first:rest) = (first ++ string) ++ (join string rest)

pythagorean :: Int -> [(Int, Int, Int)]
pythagorean n = [(a,b,c) | a <- [1..n], b <- [a..n], c <- [b..n], a^2 + b^2 == c^2]
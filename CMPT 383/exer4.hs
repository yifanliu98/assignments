hailstone :: Int -> Int
hailstone n
    | even n = n `div` 2
    | otherwise = 3 * n + 1

hailSeq :: Int -> [Int]
hailSeq 1 = [1]
hailSeq n = n : hailSeq (hailstone n)

hailSeq' :: Int -> [Int]
hailSeq' n = takeWhile (/= 1) (iterate hailstone n)

join :: [Char] -> [[Char]] -> [Char]
join _ [] = ""
join _ (x:[]) = x
join str (x:y) = foldl1 (\x z -> x ++ str ++ z) (x:y) 

merge :: Ord t => [t] -> [t] -> [t]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x < y = x : merge xs (y:ys)
    | otherwise = y : merge (x:xs) ys

mergeSort :: Ord t => [t] -> [t]
mergeSort [] = []
mergeSort (x:[]) = [x]
mergeSort x = merge (mergeSort firstHalf) (mergeSort secondHalf)
    where
        firstHalf = take (div (length x) 2) x
        secondHalf = drop (div (length x) 2) x

findElt :: Eq t => t -> [t] -> Maybe Int
findElt target list
    | index == (-1) = Nothing
    | otherwise = Just index
        where 
            index = indexElt 0 target list
            indexElt _ _ [] = (-1)
            indexElt index target (x:xs)
                | x == target = index
                | otherwise = indexElt (index+1) target xs
-- Built-In Functions

myIterate :: Num a => (a -> a) -> a -> [a]
myIterate f x = x:(myIterate f (f x))

myTakeWhile :: Num a => (a -> Bool) -> [a] -> [a]
myTakeWhile f [] = []
myTakeWhile f (x:xs)
    | f x = x:myTakeWhile f xs
    | otherwise = []

-- Pascal's Triangle

-- method 1
-- pascal :: Int -> [Int]
-- pascal 0 = [1]
-- pascal n = add2Lists prepend append
--     where
--         prepend = [0] ++ (pascal (n-1))
--         append = (pascal (n-1)) ++ [0]
--         add2Lists [] [] = []
--         add2Lists (x:xs) (y:ys) = (x+y):(add2Lists xs ys)

-- method 2
pascal :: Int -> [Int]
pascal 0 = [1]
pascal n = [1] ++ middle ++ [1]
    where
        first = pascal (n-1)
        second = tail first
        combine = zip first second
        addTuples [] = []
        addTuples (x:xs) = ((fst x) + (snd x)) : (addTuples xs)
        middle = addTuples combine

-- Pointfree Addition
addPair :: (Int, Int) -> Int
addPair = uncurry (+)

-- Pointfree Filtering
withoutZeros :: [Int] -> [Int]
withoutZeros = filter (/=0)


-- Exploring Fibonacci

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = (fib (n-1)) + (fib (n-2))

fibs = map fib [0..]

-- Something Else
things :: [Integer]
things = 0 : 1 : zipWith (+) things (tail things)

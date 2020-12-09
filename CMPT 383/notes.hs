describeList lst = "The list is " ++ case lst of
  _:_:_:_:_  -> "fairly long"     --  >= 4 elements
  _:_        -> "short"           --  >= 1 element
  []         -> "empty"

qs [] = []
qs (x:xs) = smaller ++ [x] ++ larger
  where 
    smaller = qs [a | a<-xs, a<=x]
    larger = qs [a | a<-xs, a>x]

myConcat xs = foldl (++) [] xs
myReverse xs = foldl prefix [] xs
  where 
    prefix xs x = x:xs

myReverse' (x:xs) = (myReverse' xs) ++ [x]

myPowerTailRec, myPowerTailStrict :: Int -> Int -> Int -> Int
myPowerTailRec a _ 0 = a
myPowerTailRec a x y = myPowerTailRec (x*a) x (y-1)

myPowerTailStrict a _ 0 = a
myPowerTailStrict a x y = (myPowerTailStrict $! (a*x)) x (y-1) 

calcA = a + b
    where a = calculation 1
          b = calculation 2

calcB = (a `par` b) `pseq` (a + b)
    where a = calculation 1
          b = calculation 2

index :: Eq t => Int -> [t] -> t
index 0 (x:xs) = x 
index i (x:xs) = (index $! (i-1)) xs


isNice n = True

-- recursive implementation
sumNice x y = mySum x y 0
  where 
    mySum [] [] a = a
    mySum (x:xs) (y:ys) sum
      | (isNice x) && (isNice y)  = mySum xs ys (sum + x + y)
      | otherwise                 = mySum xs ys sum


sumNice' x y = zipWith (+) (filter isNice x) (filter isNice y)

positionSum list = sumTail list 0 1
  where
    sumTail [] sum _ = sum
    sumTail (x:xs) sum pos = sumTail xs (sum+pos*x) (pos+1)
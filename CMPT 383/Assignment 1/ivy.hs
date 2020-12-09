-- Assignment 1: Rainbow Tables with Haskell

import RainbowAssign
import Data.Maybe as Maybe
import qualified Data.Map as Map

-- Parameters
pwLength, nLetters, width, height :: Int
filename :: FilePath
pwLength = 8            -- length of each password
nLetters = 5            -- number of letters to use in passwords: 5 -> a-e
width = 40              -- length of each chain in the table
height = 1000           -- number of "rows" in the table
filename = "table.txt"  -- filename to store the table

-- When testing your assignment, we will change these values, so make sure you don't assume they are always as above.

-- Compiling the Code
main :: IO ()
main = do
  generateTable
  res <- test2 1000
  print res



-- Hashing & Reducing
-- pwReduce function to map a hash back into a possible password.

-- some initial password ->(convert to) Hash value
-- First, using fromEnum to convert the hashValue to Int.(To convert an Int32 to an Int in the obvious way, use fromEnum.) 
-- Second, getting the pwLength
-- Third, using toLetter to converts an integer to the corresponding letter.
-- Fourth, reverse the list

-- Example!!!!!
-- Operation                                      Value
-- some initial password                          "abcdeabc"
-- apply pwHash                                   1726491528 (base 10 integer)
-- convert to base nLetters                       …000012013440212103 (left-padded with 0s)
-- take pwLength least significant digits         40212103
-- convert digits to letters                      "eacbcbad

pwReduce :: RainbowAssign.Hash -> RainbowAssign.Passwd
pwReduce hashValue = reverse(map toLetter(take pwLength(hashResult (fromEnum hashValue))))
       where hashResult n = [n `mod` nLetters] ++ hashResult (n `div` nLetters)



-- The Map Data Structure 
mapData :: Int -> [RainbowAssign.Passwd] -> [RainbowAssign.Hash]
mapData 0 listPassword = map pwHash listPassword
mapData n listPassword = mapData (n-1) (hashpwReduce listPassword)
    where hashpwReduce listPword = map pwReduce (map pwHash listPword)



-- Building the Table
rainbowTable :: Int -> [Passwd] -> Map.Map Hash Passwd
rainbowTable tWidth listPassword = Map.fromList(zip (mapData tWidth listPassword) listPassword)



-- Creating, Reading, and Writing Tables
-- two functions given
generateTable :: IO ()
generateTable = do
  table <- buildTable rainbowTable nLetters pwLength width height
  writeTable table filename

-- test1 = do
--   table <- readTable filename
--   return (Map.lookup 0 table)



-- Reversing Hashes
hashRdPwsd :: RainbowAssign.Passwd -> RainbowAssign.Passwd
hashRdPwsd n = pwReduce (pwHash n)

checknext :: RainbowAssign.Hash -> RainbowAssign.Passwd -> (RainbowAssign.Hash, RainbowAssign.Passwd)
checknext hash newPasswd = (hash, newPasswd)

checkEveryRow :: (RainbowAssign.Hash, RainbowAssign.Passwd) -> Int -> RainbowAssign.Hash -> (RainbowAssign.Hash, RainbowAssign.Passwd)
checkEveryRow x 0 _ = x
checkEveryRow x tWidth hashValue
    | (pwHash (snd (x))) == hashValue   = x  
    | otherwise                         = checkEveryRow (checknext (fst x) (hashRdPwsd (snd (x)))) (tWidth-1) hashValue



findPwdInTable :: [(RainbowAssign.Hash, RainbowAssign.Passwd)] -> Int -> RainbowAssign.Hash -> Maybe RainbowAssign.Passwd
findPwdInTable [] _ _ = Nothing
findPwdInTable (x:xs) tWidth hashValue 
  | tWidth == 0 && (pwHash (snd x)) == hashValue                 = Just ((snd x))
  | (pwHash(snd(checkEveryRow x tWidth hashValue))) == hashValue = Just (snd (checkEveryRow x tWidth hashValue)) 
  | otherwise                                                    = findPwdInTable xs tWidth hashValue
 

findPassword :: Map.Map Hash Passwd -> Int -> RainbowAssign.Hash -> Maybe RainbowAssign.Passwd
findPassword listPasswd tWidth hashValue = findPwdInTable (Map.toList(listPasswd)) tWidth hashValue



-- Experimenting
test2 :: Int -> IO ([Passwd], Int)
test2 n = do
  table <- readTable filename
  pws <- randomPasswords nLetters pwLength n
  let hs = map pwHash pws
  let result = Maybe.mapMaybe (findPassword table width) hs
  return (result, length result)
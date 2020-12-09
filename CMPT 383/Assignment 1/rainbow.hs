import RainbowAssign
import qualified Data.Map as Map
import Data.Maybe as Maybe

pwLength, nLetters, width, height :: Int
filename :: FilePath
pwLength = 8            -- length of each password
nLetters = 5            -- number of letters to use in passwords: 5 -> a-e
width = 40              -- length of each chain in the table
height = 1000           -- number of "rows" in the table
filename = "table.txt"  -- filename to store the table

-- convert to base nLetters
convertBase :: Hash -> [Int]
convertBase x = mod32 x ++ convertBase rest
    where
        mod32 x = [mod (fromEnum x) nLetters]
        div32 x = div (fromEnum x) nLetters
        rest = toEnum (div32 x) :: Hash

-- take pwLength least significant digits
takeDigits :: Hash -> [Int]
takeDigits hash = reverse (take pwLength (convertBase hash))

-- convert digits to letters
listToStr :: [Int] -> String
listToStr [] = []
listToStr (x:xs) = [toLetter x] ++ listToStr xs

-- convert a hash value back to a possible password
pwReduce :: Hash -> Passwd
pwReduce = listToStr.takeDigits

toHash :: Int -> [Passwd] -> [Hash]
toHash 0 passwords = map pwHash passwords
toHash w passwords = toHash (w-1) (map (pwReduce.pwHash) passwords)

rainbowTable :: Int -> [Passwd] -> Map.Map Hash Passwd
rainbowTable w passwords =  Map.fromList (zip (toHash w passwords) passwords)


generateTable :: IO ()
generateTable = do
    table <- buildTable rainbowTable nLetters pwLength width height
    writeTable table filename


checkRow :: Passwd -> Int -> Hash -> Maybe Passwd
checkRow pass w hash 
    | (pwHash pass) == hash     = Just pass
    | w == 0                    = Nothing
    | otherwise                 = checkRow ((pwReduce.pwHash) pass) (w-1) hash

findPass :: Map.Map Hash Passwd -> Int -> Hash -> Hash -> Maybe Passwd
findPass _ (-1) _ _ = Nothing
findPass table w hash nextHash
    | thePass == Nothing = findPass table (w-1) hash ((pwHash.pwReduce) nextHash)
    | otherwise          = checkRow (fromJust thePass) width hash
        where thePass = Map.lookup nextHash table

findPassword :: Map.Map Hash Passwd -> Int -> Hash -> Maybe Passwd
findPassword table w hash = findPass table w hash hash

test1 = do
    table <- readTable filename
    return (Map.lookup 0 table)

test2 :: Int -> IO ([Passwd], Int)
test2 n = do
    table <- readTable filename
    pws <- randomPasswords nLetters pwLength n
    let hs = map pwHash pws
    let result = Maybe.mapMaybe (findPassword table width) hs
    return (result, length result)

main :: IO ()
main = do
    generateTable
    res <- test2 10000
    print res
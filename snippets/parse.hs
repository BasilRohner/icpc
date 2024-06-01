import System.IO
import System.Environment
import System.Directory  (getDirectoryContents, doesDirectoryExist, doesFileExist)
import System.FilePath   ((</>))
import Control.Monad     (forM, filterM, mapM)
import Data.List         (isSuffixOf)

sanitize :: [Char] -> [Char]
sanitize [] = []
sanitize (x:xs)
    | x == '\n' = '\n' : sanitize xs
    | x == '"'  = '"' : sanitize xs
    | x == '$'  = '$' : sanitize xs
    | otherwise = x : sanitize xs

format :: [[Char]] -> [Char] -> [Char]
format x y = do
    let result = unlines $ map ((++ "\",") . ("\"" ++)) x
    result

readLines :: FilePath -> IO [String]
readLines filePath = do
    content <- readFile filePath
    return (lines content)

writeListToFile :: [String] -> FilePath -> IO ()
writeListToFile strings filename = writeFile filename (unlines strings)

main :: IO()
main = do
    let pth = "./"
    exists <- doesDirectoryExist pth
    if  exists
        then do
            all <- getDirectoryContents pth
            content <- mapM (readLines . (pth ++)) $ filter ( isSuffixOf ".cpp" ) all
            let sanit = map (map sanitize) content
            let res = zipWith format sanit all
            writeListToFile res "result.txt"
            putStrLn $ "Directory " ++ pth ++ " exists."
    else putStrLn $ "Directory " ++ pth ++ " does not exists."
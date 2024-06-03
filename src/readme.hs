import System.IO
import System.Environment
import System.Directory  (getDirectoryContents, doesDirectoryExist, doesFileExist, getHomeDirectory)
import System.FilePath   ((</>), takeFileName)
import Control.Monad     (forM, filterM, mapM)
import Data.List         (isSuffixOf)
import Data.Char         (toLower)

splitOnDot :: String -> (String, String)
splitOnDot str = (beforeDot, afterDot)
  where
    (beforeDot, rest) = break (== '.') str
    afterDot = if null rest then "" else tail rest

writeReadme :: [String] -> String -> IO ()
writeReadme s pth = writeFile pth $ "# ICPC - Competitive Programming Template\n\n" 
                                    ++ "This project provides a collection of competitive programming templates for the International Collegiate Programming Contest (ICPC) and a Haskell snippet parser that automatically generates Visual Studio Code (VSCode) snippets from these templates. "
                                    ++ "This tool is designed to streamline the coding process for competitive programmers by offering ready-to-use code snippets.\n\n"
                                    ++ "## Features\n\n" 
                                    ++ unlines s
                                    ++ "\n\n## Haskell Snippet Parser\n\n"
                                    ++ "Additionally find the custom [Haskell-Snippet-Parser](./src/parse.hs) that allows you to automatically generate vscode-snippets."
                                    ++ "To use the snippet-parser please edit the [configuration](./src/config.json)-file and then run `.parse`. Please find an example below:\n\n"
                                    ++ "```cpp\n"
                                    ++ "// Template.cpp\n\n"
                                    ++ "#include <iostream>\n"
                                    ++ "using namespace std;\n\n"
                                    ++ "int main() {\n"
                                    ++ "  cout << \"Hello World!\" << endl;\n"
                                    ++ "}\n```\n"
                                    ++ "```json\n"
                                    ++ "// icpc.code-snippets\n\n"
                                    ++ "{\n"
                                    ++ "  \"Template\": {\n"
                                    ++ "    \"prefix\": \"template\",\n"
                                    ++ "    \"scope\": \"cpp\",\n"
                                    ++ "    \"body\": [\n"
                                    ++ "      \"#include <iostream>\",\n"
                                    ++ "      \"using namespace std;\",\n"
                                    ++ "      \"\",\n"
                                    ++ "      \"int main() {\",\n"
                                    ++ "      \"  cout << \\\"Hello World!\\\" << endl;\",\n"
                                    ++ "      \"}\"\n   ]\n"
                                    ++ "  }\n}"

parse :: String -> String -> String
parse pref src = "- [?] ["++pref++"]("++src++")"

main :: IO()
main = do

    -- Parameters
    let pth = "../templates/"                                                                       -- rel path of the code templates
    let trg = "../README.md"      -- target file 
    let ext = [".cpp", ".py", ".hs"]                                                     -- src template file extensions
    let pre = "$"                                                                        -- prefix for template prefix
    let tab = "    "

    exists <- doesDirectoryExist pth
    if  exists
        then do

            all <- getDirectoryContents pth
            let files = filter (\f -> any (`isSuffixOf` f) ext) all
            let names = map (splitOnDot . takeFileName) files
            let pref = map fst names
            let src = map ((pth ++) . takeFileName) files
            let enum = zipWith parse pref src
            writeReadme enum trg

    else error "Path does not exist"

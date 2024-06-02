# ICPC - Competitive Programming Template

This project provides a collection of competitive programming templates for the International Collegiate Programming Contest (ICPC) and a Haskell snippet parser that automatically generates Visual Studio Code (VSCode) snippets from these templates. This tool is designed to streamline the coding process for competitive programmers by offering ready-to-use code snippets.

## Features

- [Template](../templates/Template.cpp)
- [LazySegmentTree](../templates/LazySegmentTree.cpp)
- [SegmentTree](../templates/SegmentTree.cpp)
- [FenwickTree2d](../templates/FenwickTree2d.cpp)
- [linear_sieve](../templates/linear_sieve.cpp)
- [gcd](../templates/gcd.cpp)
- [fast_fourier](../templates/fast_fourier.cpp)
- [SparseTable](../templates/SparseTable.cpp)
- [FenwickTree](../templates/FenwickTree.cpp)
- [z_function](../templates/z_function.cpp)


## Haskell Snippet Parser

Additionally find the custom [Haskell-Snippet-Parser](./src/parse.hs) that allows you to automatically generate vscode-snippets.To use the snippet-parser please edit the [configuration](./src/config.json)-file and then run `.parse`. Please find an example below:

```cpp
// Template.cpp

#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!" << endl;
}
```
```json
// icpc.code-snippets

{
  "Template": {
    "prefix": "template",
    "scope": "cpp",
    "body": [
      "#include <iostream>",
      "using namespace std;",
      "",
      "int main() {",
      "  cout << \"Hello World!\" << endl;",
      "}"
   ]
  }
}
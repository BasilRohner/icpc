# ICPC - Competitive Programming Template

This project provides a collection of competitive programming templates for the International Collegiate Programming Contest (ICPC) and a Haskell snippet parser that automatically generates Visual Studio Code (VSCode) snippets from these templates. This tool is designed to streamline the coding process for competitive programmers by offering ready-to-use code snippets.

## Features

- [newton](../templates/newton.cpp)
- [manacher](../templates/manacher.cpp)
- [Template](../templates/Template.cpp)
- [maxflow](../templates/maxflow.cpp)
- [sparse_table](../templates/sparse_table.cpp)
- [lca](../templates/lca.cpp)
- [fenwick_tree_2d](../templates/fenwick_tree_2d.cpp)
- [corasick](../templates/corasick.cpp)
- [segment_tree](../templates/segment_tree.cpp)
- [fft](../templates/fft.cpp)
- [sieve](../templates/sieve.cpp)
- [bellman](../templates/bellman.cpp)
- [bfs](../templates/bfs.cpp)
- [hungarian](../templates/hungarian.cpp)
- [simpson](../templates/simpson.cpp)
- [gomory_hu](../templates/gomory_hu.cpp)
- [dfs](../templates/dfs.cpp)
- [point3d](../templates/point3d.cpp)
- [floyd](../templates/floyd.cpp)
- [gcd](../templates/gcd.cpp)
- [fenwick_tree](../templates/fenwick_tree.cpp)
- [karp](../templates/karp.cpp)
- [point2d](../templates/point2d.cpp)
- [matrix](../templates/matrix.cpp)
- [mincostflow](../templates/mincostflow.cpp)
- [polygon](../templates/polygon.cpp)
- [treap](../templates/treap.cpp)
- [mst](../templates/mst.cpp)
- [lazy_segment_tree](../templates/lazy_segment_tree.cpp)
- [hash](../templates/hash.cpp)
- [dijksta](../templates/dijksta.cpp)
- [phi](../templates/phi.cpp)
- [z_function](../templates/z_function.cpp)
- [convex_hull](../templates/convex_hull.cpp)


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
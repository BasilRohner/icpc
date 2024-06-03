# ICPC - Competitive Programming Template

This project provides a collection of competitive programming templates for the International Collegiate Programming Contest (ICPC) and a Haskell snippet parser that automatically generates Visual Studio Code (VSCode) snippets from these templates. This tool is designed to streamline the coding process for competitive programmers by offering ready-to-use code snippets.

## Features

- [x] [newton](../templates/newton.cpp)
- [x] [manacher](../templates/manacher.cpp)
- [x] [Template](../templates/Template.cpp)
- [x] [maxflow](../templates/maxflow.cpp)
- [x] [sparse_table](../templates/sparse_table.cpp)
- [x] [simplex](../templates/simplex.cpp)
- [x] [lca](../templates/lca.cpp)
- [x] [fenwick_tree_2d](../templates/fenwick_tree_2d.cpp)
- [x] [corasick](../templates/corasick.cpp)
- [x] [segment_tree](../templates/segment_tree.cpp)
- [x] [fft](../templates/fft.cpp)
- [x] [sieve](../templates/sieve.cpp)
- [x] [bellman](../templates/bellman.cpp)
- [x] [bfs](../templates/bfs.cpp)
- [x] [hungarian](../templates/hungarian.cpp)
- [x] [simpson](../templates/simpson.cpp)
- [x] [gomory_hu](../templates/gomory_hu.cpp)
- [x] [dfs](../templates/dfs.cpp)
- [x] [2sat](../templates/2sat.cpp)
- [x] [point3d](../templates/point3d.cpp)
- [x] [floyd](../templates/floyd.cpp)
- [x] [gcd](../templates/gcd.cpp)
- [x] [fenwick_tree](../templates/fenwick_tree.cpp)
- [x] [karp](../templates/karp.cpp)
- [x] [point2d](../templates/point2d.cpp)
- [x] [matrix](../templates/matrix.cpp)
- [x] [mincostflow](../templates/mincostflow.cpp)
- [x] [polygon](../templates/polygon.cpp)
- [x] [treap](../templates/treap.cpp)
- [x] [mst](../templates/mst.cpp)
- [x] [lazy_segment_tree](../templates/lazy_segment_tree.cpp)
- [x] [hash](../templates/hash.cpp)
- [x] [dijksta](../templates/dijksta.cpp)
- [x] [phi](../templates/phi.cpp)
- [x] [z_function](../templates/z_function.cpp)
- [x] [convex_hull](../templates/convex_hull.cpp)


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
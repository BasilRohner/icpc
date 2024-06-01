from pathlib import Path

# TODO escape "-sign
# TODO escape '\n'-sign

intr : str = """
    // Snippet File Generated Using parse.py from www.github.com/BasilRohner/icpc/snippets/parse.py
    // Place your global snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.
	// Example:
	// "Print to console": {
	// 	"scope": "javascript,typescript",
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
"""

buf: list[str] = []

def writeSnippet(lnbuf: list[str], 
                 lnstr: str, 
                 lnpref: str, 
                 lndesc: str) -> None:
    
    r: str = ""
    r += f' "{lnstr}\": {{\n'
    r += f'     "scope": "cpp",\n'
    r += f'     "prefix": "icpc_{lnpref}",\n'
    r += f'     "body": [\n'
    for ln in lnbuf:
        r += f'         "{sanitize(ln)}",\n'
    r += f'     ],\n'
    r += f'     "description": "Icpc - {lndesc}"\n'
    r += f' }}\n'
    buf.append(r)

def sanitize(string: str) -> str:
    escaped_string = string.replace('\\', '\\\\')
    escaped_string = escaped_string.replace('"', '\\"')
    escaped_string = escaped_string.replace("'", '\'')
    escaped_string = escaped_string.replace('\n', '\\n')
    escaped_string = escaped_string.replace('\t', '\\t')
    escaped_string = escaped_string.replace('$', '\\$')
    return escaped_string

def getParams(ln1: str, ln2: str, ln3: str) -> tuple[str, str, str]:
    lnstr: str = ln1[14:].rstrip()    # //templ__str: 
    lnpref: str = ln2[15:].rstrip()   # //templ__pref: 
    lndesc: str = ln3[15:].rstrip()   # //templ__desc: 
    return lnstr, lnpref, lndesc


def parseFile(path: Path) -> None:
    if not path.exists():
        raise Exception('Not a valid path!')
    with path.open() as f:
        lnstr: str = ""
        lnpref: str = ""
        lndesc: str = ""
        lnbuf: list[str] = []
        while l := f.readline():
            if (l[0:10] == '//templ__b'):
                ln1, ln2, ln3 = f.readline(), f.readline(), f.readline()
                lnstr, lnpref, lndesc = getParams(ln1, ln2, ln3)
                lnbuf = []
            elif (l[0:10] == '//templ__e'):
                writeSnippet(lnbuf=lnbuf, lnstr=lnstr, lnpref=lnpref, lndesc=lndesc)
            else:
                r: str = l.rstrip()
                lnbuf.append(r)

def main():
    d_in: str = './in'
    d_out: str = './out/icpc.code-snippets.txt'
    pth: Path = Path(d_in)
    p_out: Path = Path(d_out)

    srcs: list[str] = [x for x in pth.iterdir() if x.is_file()]
    for src in srcs:
        print(f'{src} -> snippet')
        parseFile(src)

    with p_out.open("w", encoding ="utf-8") as f:
        f.write("{")
        f.write(intr)
        f.write("\n")
        for i, itm in enumerate(buf):
            if i != 0:
                f.write(',\n')
            f.write(itm)
            f.write('\n')
        f.write("}")
        
        

if __name__ == '__main__':
    main()
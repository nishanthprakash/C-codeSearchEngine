# cleans all generated data

import os

os.system("rm files 2> /dev/null")
os.system("rm codedata/* 2> /dev/null")
os.system("rm testdata/* 2> /dev/null")
os.system("rm cpindices.obj 2> /dev/null")
os.system("rm *~ 2> /dev/null")
os.system("rm astsearch.txt aststring.txt 2> /dev/null")

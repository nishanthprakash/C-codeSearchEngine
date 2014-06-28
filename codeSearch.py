#------------------------------------START-----------------------------------------
import sys, re, os
from pycparser import c_parser, c_ast

postlist = list()

def postorder(node):
	nodestr = node.__class__.__name__+ ': '
	vlist = [getattr(node, n) for n in node.attr_names]
	attrstr = ', '.join('%s' % v for v in vlist)
	nodestr=nodestr + attrstr
	
	for (child_name, child) in node.children():
		postorder(child)
	postlist.append(nodestr)


Searchfile = str(sys.argv[1])

text1 = open(Searchfile, 'r').read()

text = "checkerfunc(){ " + text1 + " }"

parser = c_parser.CParser()
try :
	ast = parser.parse(text, filename='<none>')
except:
	print("Oh there's a syntax error in this code")
	sys.exit()


postorder(ast.ext[0].body)
del postlist[-1]
ast.ext[0].body.show()

#----------------------SHA1 HASH of nodes-----------------------------------------------

import hashlib
hplist=list() 			# hplist is the hash of postlist
for i in postlist:
	hplist.append(hashlib.sha1(i).hexdigest())

#print(hplist)
#print("-----------------------------------------------------------")

#--------------------H(A) of this code (of all nodes in given)------------------------------

PRIME=3
i=0
codehash=0
num_nodes=len(hplist)
print("Computing hash of code")
while i < num_nodes:
	codehash = codehash + pow(PRIME, num_nodes-i-1)*(int(hplist[i],16))
	print(str(i) + " of " + str(num_nodes) + " done")
	i=i+1

codehash = codehash + pow(PRIME, num_nodes)
print(codehash)

#------------------Find this hash in dictionary of codephrases--------------------

import pickle 
if os.path.exists('cpindices.obj'):
	picklefile = open('cpindices.obj', 'r') 
	cpdic = pickle.load(picklefile) 
else:
	print("Oh you haven't trained the search on any code. Lame!")
	sys.exit()


if cpdic.has_key(hex(codehash)):
	print("This piece of code is found in submissione by the following")
	print(cpdic[hex(codehash)])
else:
	print("No match found")

#---------------------------EOF----------------------------------------------------

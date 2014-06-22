#------------------------------------START-----------------------------------------
from __future__ import print_function
import sys, re, os
from pycparser import c_parser, c_ast

import pickle 
if os.path.exists('cpindices.obj'):
	picklefile = open('cpindices.obj', 'r') 
	cpdic = pickle.load(picklefile) 
else:
	print("Oh you haven't trained the search on any code. Lame!")
	sys.exit()


Searchfile = str(sys.argv[1])

text1 = open(Searchfile, 'r').read()

text = "checkerfunc(){ " + text1 + " }"

parser = c_parser.CParser()
ast = parser.parse(text, filename='<none>')

orig_stdout = sys.stdout
f = file('astsearch.txt', 'w')
sys.stdout = f

#ast.show(buf=sys.stdout) 	# pretty prints AST to the file aststring.txt 

ast.ext[0].body.show(buf=sys.stdout)

sys.stdout = orig_stdout
f.close()

#----------------------------#anonymizing identifiers.....worry about this later--------------
#f1 = open('aststring.txt','r').read()
#f2 = re.sub('ID.*', 'ID', f1)	
#line=f2.split('\n')

#orig_stdout = sys.stdout
#f3 = file('anonast.txt', 'w')
#sys.stdout = f3

#print(f2) 

#sys.stdout = orig_stdout
#f3.close()

#---------------------------------------------------------------------------------------


#---we build our own tree as the the AST object doesnt help to postorder traverse----
#
#---------- Tree representation---------------------

class Node(object):
    def __init__(self, title):
        self.title = title
        self.parent = None
        self.children = []

    def add(self, child):
        self.children.append(child)
        child.parent = self

# -----------------Node insertion-------------------

class Inserter(object):
    def __init__(self, node, depth = 0):
        self.node = node
        self.depth = depth

    def __call__(self, title, depth):
        newNode = Node(title)
        if (depth > self.depth):
            self.node.add(newNode)
            self.depth = depth
        elif (depth == self.depth):
            self.node.parent.add(newNode)
        else:
            parent = self.node.parent
            for i in xrange(0, self.depth - depth):
                parent = parent.parent
            parent.add(newNode)
            self.depth = depth

        self.node = newNode

# ----------- File to tree--------------------------------

with open(r'aststring.txt', 'r') as f1:   
    tree = Node(f1.readline().rstrip('\n'))
    inserter = Inserter(tree)
   	
    for line in f1:
        line = line.rstrip('\n')
        s = re.match('[ ]*', line).group(0).count(' ')/2
        title = line[s:]
	if(title!=''):
	        inserter(title, s)

#-------------------------postorder list of nodes-----------------

postlist=list()
def print_tree(node, depth = 0):
    for child in node.children:
        print_tree(child, depth + 1)
    #print (node.title.strip())   # A Postorder print with levels mentioned
    postlist.append(node.title.strip())
print_tree(tree)

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

print("This piece of code is found in submissione by the following")
print(cpdic[hex(codehash)])

#---------------------------EOF----------------------------------------------------

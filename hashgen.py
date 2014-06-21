
"""hashgen.py: This is the codephrase hash generator for a piece of code"""

__author__ = "Nishanth Prakash"
__copyright__ = "Copyright 2014, HackathonAM"
__credits__ = ["some stanford guys who wrote a paper"]
__license__ = "None"
__version__ = "1.0.1"
__maintainer__ = "Nishanth"
__email__ = "nishanthprakash20@gmail.com"
__status__ = "Production"

#------------------------------------START-----------------------------------------

from __future__ import print_function
import sys, re, os
from pycparser import c_parser, c_ast

import pickle 
if os.path.exists('cpindices.obj'):
	picklefile = open('cpindices.obj', 'rw') 
	cpdic = pickle.load(picklefile) 
else:
	picklefile = open('cpindices.obj', 'w')

StudentID = str(sys.argv[1])
Studentfile = str(sys.argv[2])

text = open(Studentfile, 'r').read()

parser = c_parser.CParser()
ast = parser.parse(text, filename='<none>')

orig_stdout = sys.stdout
f = file('aststring.txt', 'w')
sys.stdout = f

ast.show(buf=sys.stdout)

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
#    print(f4.readline())    	
    for line in f1:
#	print(line.rstrip('\n'))
#	print("haha")
        line = line.rstrip('\n')
#	print(line)
        # note there's a bug with your original tab parsing code:
        # it would count all tabs in the string, not just the ones
        # at the beginning
        s = re.match('[ ]*', line).group(0).count(' ')/2
        title = line[s:]
#	title = title.strip
#	print(title)
#	print(s)
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

#print(postlist)
#print(len(postlist))


# compute sizes of subtree later...its not used in hashing anyway search and then traverse if found to find no. of nodes in a subtree



#----------------------SHA1 HASH of nodes-----------------------------------------------

import hashlib
hplist=list() 			# hplist is the hash of postlist
for i in postlist:
	hplist.append(hashlib.sha1(i).hexdigest())

#print(hplist)
#print("-----------------------------------------------------------")
#--------------------H(A) of prefixes and prefixtree------------------------------
prehplist=list()		# prehplist is the H(A) hash of prefixes of hash of post list
prepostlist=list()		# prepostlist is the prefix tree of postlist
PRIME=3
prehplist.append(PRIME+int(hplist[0], 16))
prepostlist.append(postlist[0])
i=1
while i <= len(hplist)-1:
	prehplist.append(PRIME*prehplist[i-1]+int(hplist[i],16))
	prepostlist.append(prepostlist[i-1]+ " " +postlist[i])
	i=i+1

#print(prehplist)
#print(prepostlist)

#--------------------------hash of all code phrases in the AST--------------------------
import itertools
j=0
alco=list()
hashco=list()
while j < len(hplist):
	k=j
	while k < len(hplist): 
		alco.append(' '.join(list(itertools.islice(prepostlist,j,k+1))))
		if j-1 >= 0 :
			hashco.append(prehplist[k] - pow(PRIME,k-j+1)*(prehplist[j-1]-1))
		else:
			hashco.append(prehplist[k])
		k=k+1
	j=j+1

#print(alco)
#print(hashco)

#------------------collapse hashco into a dictionary of codephrases--------------------

cpdic=dict()
for i in hashco:
	if cpdic.has_key(hex(i)):
		cpdic[hex(i)].add(StudentID)
	else:		
		cpdic[hex(i)] = set([StudentID])
#print(cpdic)

#print(len(prehplist)) # =n
#print(len(hashco)) # =n*(n+1)/2  -----verified!
#print(len(cpdic)) # collapsed no. is less than total

#---------------------pickle out the code phrase dict-------------------------------

pickle.dump(cpdic, picklefile)

#---------------------------EOF----------------------------------------------------
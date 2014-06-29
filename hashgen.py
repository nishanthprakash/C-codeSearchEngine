

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


StudentID = str(sys.argv[1])
Studentfile = str(sys.argv[2])

text = open(Studentfile, 'r').read()

parser = c_parser.CParser()
try :
	ast = parser.parse(text, filename='<none>')
except:
	print("Oh there's a syntax error in this code, hence will not be processed")
	sys.exit()

#ast.show()
postorder(ast)
#print("\n".join(List))
#----------------------SHA1 HASH of nodes-----------------------------------------------

import hashlib
hplist=list() 			# hplist is the hash of postlist
for i in postlist:
	hplist.append(hashlib.sha1(i).hexdigest())

#for i in hplist:
#	print(str(int(i,16)))
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

#print(len(prehplist))
#print(prehplist)
#print("\n".join(prepostlist))

#--------------------------hash of all code phrases in the AST--------------------------
#import itertools
j=0
alco=list()
hashco=list()
while j < len(hplist):
	k=j
	while k < len(hplist): 
		#alco.append(' '.join(itertools.islice(prepostlist,j,k+1)))
		if j-1 >= 0 :
			hashco.append(prehplist[k] - pow(PRIME,k-j+1)*(prehplist[j-1]-1)) #hashes of a{j...k}
		else:
			hashco.append(prehplist[k])
		k=k+1
	j=j+1


#------------------collapse hashco into a dictionary of codephrases--------------------
import pickle 
if os.path.exists('cpindices.obj'):
	picklefile = open('cpindices.obj', 'r') 
	cpdic = pickle.load(picklefile) 
#	cpdic_exists=True
#	print(cpdic_exists)
else:
#	picklefile = open('cpindices.obj', 'w')
#	cpdic_exists=False

#if cpdic_exists != True:
	cpdic=dict()

#picklefile.close()

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

picklefile = open('cpindices.obj', 'w') 
pickle.dump(cpdic, picklefile)
picklefile.close()

#---------------------------EOF----------------------------------------------------

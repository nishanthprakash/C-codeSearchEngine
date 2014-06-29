
#------------------------------------START-----------------------------------------

import sys, re, os
from pycparser import c_parser, c_ast
import xlwt
import itertools

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

print("----done with prefixes--------")

#--------------------------hash of all code phrases in the AST--------------------------
#import itertools
j=0
alco=list()
hashco=list()
while j < len(hplist):
	k=j
	while k < len(hplist): 
		#alco.append(' '.join(list(itertools.islice(prepostlist,j,k+1))))
		if j-1 >= 0 :
			hashco.append(prehplist[k] - pow(PRIME,k-j+1)*(prehplist[j-1]-1)) #hashes of a{j...k}
		else:
			hashco.append(prehplist[k])
		k=k+1
	j=j+1
print("----done with hash of all phrases--------")

#------------------Find this hash in dictionary of codephrases--------------------

import pickle 
if os.path.exists('cpindices.obj'):
	picklefile = open('cpindices.obj', 'r') 
	cpdic = pickle.load(picklefile) 
else:
	print("Oh you haven't trained the search on any code. Lame!")
	sys.exit()

from xlutils.copy import copy
from xlrd import *
if os.path.exists('results.xlsx'):
	workbook = copy(open_workbook('results.xlsx'))
else:
	workbook = xlwt.Workbook()

sheet = workbook.add_sheet('testresults0_' + str(StudentID) )

sheetnum=0
index=0
SHEET_LIMIT = 65536
cumindex=0
for codehash in hashco:
	if index < SHEET_LIMIT:
		if cpdic.has_key(hex(codehash)):
			sheet.write(index,0, str(cumindex+index))
			sheet.write(index,1, hex(codehash))
			sheet.write(index,2,', '.join(cpdic[hex(codehash)])) 

		else:
			sheet.write(index,0, str(cumindex+index))
			sheet.write(index,1, hex(codehash))
			sheet.write(index,2,"----")

		index += 1
		print(str(cumindex+index))
	else:
		sheetnum+=1
		sheet = workbook.add_sheet('testresults' + str(sheetnum) + '_' +str(StudentID) )
		cumindex += SHEET_LIMIT
		index=0
		if cpdic.has_key(hex(codehash)):
			sheet.write(index,0, str(cumindex+index))
			sheet.write(index,1, hex(codehash))
			sheet.write(index,2,', '.join(cpdic[hex(codehash)])) 

		else:
			sheet.write(index,0, str(cumindex+index))
			sheet.write(index,1, hex(codehash))
			sheet.write(index,2,"----")

		index += 1
		print(str(cumindex+index))


print("----writing results--------")
workbook.save('results.xlsx')
#---------------------------EOF----------------------------------------------------


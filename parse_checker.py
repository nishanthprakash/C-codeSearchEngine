
import sys, re, os
from pycparser import c_parser, c_ast


sfList = open(sys.argv[1], 'r').read().split('\n')
print(sfList)

for record in sfList:
	if record == '':
		continue
	sf=record.split(' ')
	StudentID=sf[0]
	Studentfile=sf[1]

	text = open(Studentfile, 'r').read()

	parser = c_parser.CParser()
	try :
		ast = parser.parse(text, filename='<none>')
	except:
		print("Oh there's a syntax error in this code")
		continue
	
	
	ast.show()  


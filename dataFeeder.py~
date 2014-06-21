import sys
import os

sfList = open(sys.argv[1], 'r').read().split('\n')

for record in sfList:
	if record != '':
		sf=record.split(' ')
		StudentID=sf[0]
		File=sf[1]
		run="python hashgen.py" + " " + StudentID + " " + File
		os.system(run)


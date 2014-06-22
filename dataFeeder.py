import sys
import os

sfList = open(sys.argv[1], 'r').read().split('\n')
i=1
for record in sfList:
	if record == '':
		continue
	sf=record.split(' ')
	print(sf)
	StudentID=sf[0]
	File=sf[1]
	run="python hashgen.py" + " " + StudentID + " " + File
	print("--------------- Processing code " + str(i) + " -------------------" )	
	os.system(run)
	i += 1

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
	if "testdata" not in File:
		run="python hashgen.py" + " " + StudentID + " " + File
		print("--------------- Processing code " + str(i) + " -------------------" )	
		os.system(run)
	else:
		print("use " + File + "as test data")		
	
	i += 1

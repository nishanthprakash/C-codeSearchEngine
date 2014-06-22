import xlrd
import os.path
import pycparser
import re

NUMBER_OF_SUBMISSIONS = 4 #33 in the actual spread sheet

wb = xlrd.open_workbook('codes.xlsx')
wb.sheet_names()
sh = wb.sheet_by_index(0)
i = 1

with open("files", "a") as filelist:
    while i< NUMBER_OF_SUBMISSIONS: 	
	
        studentID = int(sh.cell(i,0).value)
        code = str(sh.cell(i,1).value)

	#---------------------Deal with comments as pycparser doesnt------------

	def comment_remover(text):
	    def replacer(match):
	        s = match.group(0)
	        if s.startswith('/'):
	            return ""
	        else:
	            return s
	    pattern = re.compile(
	        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
	        re.DOTALL | re.MULTILINE
	    )
	    return re.sub(pattern, replacer, text)
	
	parser1 = pycparser.CParser()
	
	code2=comment_remover(code)
	
	#---------handle all preproc directives too, pycparser doesnt take care-------
	codes_with_syntax_error=0
	#print(code2)
	toparsecode=''
	for n in code2.split('\n'):
		 if not n.startswith('#'):
			toparsecode=toparsecode + n + "\n"
	#try :
	#	parser1.parse(comment_remover(toparsecode))		#check! 
	#except:
	#	i=i+1
	#	codes_with_syntax_error += 1
	#	continue
	
	#print(toparsecode)

	#toparsecode=toparsecode.rstrip('\r\n')	# remove carriage returns 
	
	#-------------------------------------------------------------------------

	with open( "codedata/"+ str(studentID) +".c", "a") as student_codefile:
	        student_codefile.write(toparsecode + '\n')
	filelist.write( str(studentID) + " " + "codedata/"+ str(studentID) + ".c" + '\n')
        i += 1

#print(codes_with_syntax_error)

	#--------------------------END-------------------------------

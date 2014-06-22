import xlrd
import os.path

wb = xlrd.open_workbook('codes.xlsx')
wb.sheet_names()
sh = wb.sheet_by_index(0)
i = 1
#print(int(sh.cell(i,0).value))
#sfiles=list()
with open("files", "a") as filelist:
    while i<33: #sh.cell(i,0).value != 0:
	#print("row " + str(i) + str(sh.cell(i,0).value))
        studentID = int(sh.cell(i,0).value)
        code = str(sh.cell(i,1).value)
        #DB1 = str(Load) + " " + (" ".join(str(all_d)))
	with open( "codedata/"+ str(studentID) +".c", "a") as student_codefile:
	        student_codefile.write(code + '\n')
	filelist.write( str(studentID) + " " + "codedata/"+ str(studentID) + ".c" + '\n')
        i += 1

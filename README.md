C-codeSearchEngine
==================

A semantic search engine to search for equivalent C codes.

This engine is used to search for equivalent C-codes students might have written in the given data set of student code submissions and their corresponding IDs.

Contains six python scripts:
	
	1. xlreader.py - reads StudentIDs and their respective codes from an xl sheet (col1 StudentID, col2 corresponding code submitted) and extracts all the code into separate files in the folder codedata with file names as <studentID>.c and also makes a list of studentID and studentcodefiles in the file 'files'. Also note that if the codes are not compiler preprocessed codes, this script will remove preprocessor directives and strip all comments from them. 

	2. dataFeeder.py - feeds the student codes in codedata into hashgen.py which is the code phrase indexer

	3. hashgen.py - Reverse indexes all possible codephrases in the given codedata to the studentIDs of student who have submitted them.

	4. codeSearch.py - uses the reverse index generated by hashgen.py to search for the given code phrase in the given data of codes  and returns the StudentIDs of students who have submitted such code phrases (structurally similar codes).
	
	5. cleaner.py - cleans all generated data for fresh processing

	5. parse_checker.py - does a final check if all the codedata generated parses properly.

IMPORTANT: 

	1. The assumption is the codes given parse successfully, i.e. they are syntactically correct  (failing which this doesn't parse it or use it in the search engine).

	2. Use the utility dos2unix to remove carriage returns etc. which will be considered syntax errors in the parser.

	3. This system can be used as a scalable indexer to incrementally add indices of codephrases of codes using hashgen.py
		$ python hashgen.py <studentID> <code_file>

	This adds the indices of the new code_file to the stored indices

USAGE STEPS:

INDEX GENERATION:

	1. Run the xlreader.py which outputs filelist in 'files'
			$ python xlreader.py <code_excel_sheet> <number_of_submissions>

	1a. Run the utility 'dos2unix' for file conversions on all the codes extracted in the folder codedata
			$ dos2unix codedata/*
	1b. Run parse_checker.py to verify that all the codedata now can be parsed properly (OPTIONAL)
			$ python parse_checker.py files
	2. Feed this to dataFeeder.py as arguement and run dataFeeder which feeds data to hashgen.py
			$ python dataFeeder.py files
SEARCH:
	
	Give your code stub file as arg to codeSearch.py and run it. It will look for a match
			$ python codeSearch.py test_codestub.c
CLEANING:

	Run cleaner.py to clean all generated code on finishing
			$ python cleaner.py


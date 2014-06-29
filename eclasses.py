###########-------------Equivalence Probability----------#############-------------

#------------extract ut[A] from a file----------------



def context(A,b):



def queryIndex(b):



def equivalenceprob(b1,b2):
	l1=queryIndex(b1)
	l2=queryIndex(b2)
	count=0
	denominator=0
	w=0
	for A1,c1 in l1:
		for A2,c2 in l2:
			if context(A1,b1) == context (A2,b2):
				w=c1*c2
				if ut[A1]==ut[A2]:
					count=count + w
				denominator=denominator+w
	return (count/denominator)	

###########-------------Equivalence classes---------------#############-----------

#---------------feet that fit the shoe----------------
# for given subtree b find all the ASTs with context c =A\b 
# (first time it will be an exact matching of contexts through indices) 

def findfeet(b,A):
	c=context(A,b)
	if cpdic.has_key(hex(codehash)):
		L = cpdic[c]
	for A1 in L:
		if ut(A1)==ut(A):
			if verify(A1,c,b):
				eclass[b].append(feet(A1,c))		
		else:
			if not verify(A1,c,b)	
				aclass[b].append(feet(A1,c))


#---------------shoe that fit the feet----------------





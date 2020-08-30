import sys
import csv
import re
#import os # p contar quantos ficheiros ha na pasta e definir a range

if len(sys.argv) != 3:
    print("Please provide correct number of args.")

intendedDb = sys.argv[1]
path = "sequences/"
array = []

#https://www.quora.com/How-do-I-get-the-number-of-consecutive-occurrences-of-a-substring-in-a-string-using-Python
def number_of_consecutive_occurrences(substring, full_string):
  pattern = "(?=((" + re.escape(substring) + ")+))"
  matches = re.findall( pattern, full_string)
  #print(max( [len(m[0]) // len(substring) for m in matches], default=0))
  array.append(max( [len(m[0]) // len(substring) for m in matches], default=0))
  return max( [len(m[0]) // len(substring) for m in matches], default=0)

def stripUninterestingValues(string):
    indexToCut = 0
    for char in string:
        if(char == ','):
            indexToCut=indexToCut+1
            continue
        else:
            substr = string[indexToCut: ]
            return substr

d = []
arr = []
outra = []
s = ''
howManyRows = 0

def openFileAndAnalyse():
    for p in range(1):
        ff = open(f"{sys.argv[2]}", "r")
        sstring = ff.read()
        for l in vars:
            number_of_consecutive_occurrences( l, sstring)
        ff.close()
        #d = []
        for p in array:
            d.append(str(p))

def turnIntoInts(elem):
	integer = int(elem, base=10)
	return integer

#large.csv 
if intendedDb == 'databases/large.csv':
    vars = ['AGATC','TTTTTTCT','AATG','TCTAG','GATA','TATC','GAAA','TCTG']
    openFileAndAnalyse()
    for elem in d:
        #integer = int(elem, base=10)
        integer = turnIntoInts(elem)
        outra.append(integer)

    for c in outra:
        c = str(c)
        s = s+c+','
        w = s[:-1]
    
    #ir a bd ver se encontro a str, se sim, devolver o nome
    found = False
    with open('databases/large.csv', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for line in reader:
            retVal = stripUninterestingValues(re.sub("\D", ",", line[0]))
            howManyRows = howManyRows+1

            if retVal == w:
                #print("ta aqui")
                found = True
                name = re.sub(r"[^A-Za-z]+", " ", line[0])
                print(name)
                break

        if found == False:
            print("No match")

#small.csv 

if intendedDb == 'databases/small.csv':
    vars = ['AGATC','AATG','TATC']

    openFileAndAnalyse()

    for elem in d:
        #integer = int(elem, base=10)
        integer = turnIntoInts(elem)
        outra.append(integer)
    
    for c in outra:
        c = str(c)
        s = s+c+','
        w= s[:-1]

    #ir a bd ver se encontro a str; se sim, devolver o nome
    found = False
    with open('databases/small.csv', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for line in reader:
            retVal = stripUninterestingValues(re.sub("\D", ",", line[0]))
            howManyRows = howManyRows+1

            if retVal == w:
                #print("ta aqui")
                found = True
                name = re.sub(r"[^A-Za-z]+", " ", line[0])
                print(name)
                break

        if found == False:
            print("No match")
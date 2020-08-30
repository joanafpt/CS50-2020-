import sys
import csv
import cs50
import sqlite3
from sqlite3 import Error

#print(len(sys.argv))
#print(sys.argv[1])

if len(sys.argv) != 2:
    sys.exit("Please provide correct number of args.")

else:
    #print("let's go")
    #https://stackoverflow.com/questions/16856647/sqlite3-programmingerror-incorrect-number-of-bindings-supplied-the-current-sta
    #https://stackoverflow.com/questions/14949833/searching-sqlite-database-with-python-variables

    house = sys.argv[1]
    #print(type(house))
    #print(house, " house")
    conn = sqlite3.connect('students.db')
    #print(conn)
    c = conn.cursor()
    #c.execute('SELECT * FROM students WHERE house="Gryffindor";')
    c.execute("SELECT * FROM students WHERE house=? ORDER BY lastname, firstname", (house,))

    #c.execute(f'SELECT firstname, lastname, birth FROM students WHERE house={house};')

    #print(c.fetchall())
    results = c.fetchall()

    for i in results:
        #print(i)
        #print(i[0], i[1], i[2])
        # n ha nome do meio

        if i[1] == None:
            print(i[0], i[2] + ", born", i[4])
        elif i[1] != None:
            print(i[0], i[1], i[2] + ", born", i[4])

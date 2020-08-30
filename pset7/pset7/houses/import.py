import sys
import csv
import cs50

#print(len(sys.argv))


if len(sys.argv) != 2:
    sys.exit("Please provide correct number of args.")

else:
    print("let's go")

    #create empty students.db
    open("students.db", "w").close()
    #open that file for sqlite
    db = cs50.SQL("sqlite:///students.db")

    #create table students in database called students.db
    db.execute("CREATE TABLE students(firstname TEXT,middlename TEXT, lastname TEXT, house TEXT, birth NUMERIC)")

    firstname = None
    middlename = None
    lastname = None
    house = None
    birth = None

    with open('characters.csv', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        next(reader)#omitir header
        for line in reader:
            #print(line)
            output = 'NULL'
            #se len é 3, ha nome do meio
            if len(line) == 3:
                output = line[2].split(',')
                firstname = line[0]
                middlename = line[1]
                lastname = output[0]
                #name = line[0] + ' ' + line[1] + ' ' +output[0]
                house = output[1]
                birth = output[2]              


            #if len = 2, no middle name
            if(len(line) == 2):
                #print(line)
                output = line[1].split(',')
                firstname = line[0]
                middlename = None
                lastname = output[0]
                #name = line[0] + ' ' + output[0]
                house = output[1]
                birth = output[2]              

            
          
            #db.execute("INSERT INTO students(name, house, birth) VALUES(?,?,?)", name, house, birth)

            print(firstname, " firstname")
            print(middlename, " middlename")
            print(lastname, " lastname")
            print(house, " house")
            print(birth, " birth")

            db.execute("INSERT INTO students(firstname, middlename, lastname, house, birth) VALUES(?,?,?,?,?)", firstname, middlename, lastname, house, birth)

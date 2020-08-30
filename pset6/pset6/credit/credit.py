from cs50 import get_string

while True:
    number = get_string("Number: ")

    if(len(number) <13 or len(number) > 16):
        print("INVALID")

    if len(number) == 13 or len(number) == 15 or len(number) == 16:
        break

#print(number)
nums = []
mySum = 0
sumTwoDigs = 0
otherNums = []
sumMyOtherNums = 0
dgits = []
mydgs = 0

if len(number) % 2 == 0:

    for i in number[ : : 2]:
        
        if int(i)*2 <9:
            nums.append(int(i)*2)
            mySum = sum(nums)
          
        if int(i)*2 > 9:
            dgits.append((int(i)*2) // 10)
            dgits.append((int(i)*2) % 10)
            mydgs = sum(dgits)
            
    totalFirstSum = mySum + mydgs

    otherNumbers = number[1:]
    for j in otherNumbers[ : : 2]:
        otherNums.append(int(j))
        sumMyOtherNums = sum(otherNums)
    
    if (totalFirstSum + sumMyOtherNums) % 10 == 0:
        if number[0] == '4':
            print("VISA")
        elif number[0] == '5':
            if number[1] == '1' or number[1]== '5' or number[1]== '4' or number[1]== '3' or number[1]== '2':
                print("MASTERCARD")
        else:
            print("INVALID")


else:
    #print(impar)
    modifiedNumber = number[:-1]
    #print(modifiedNumber)
    
    for i in modifiedNumber[ 1: : 2]:
        if int(i)*2 < 9:
            nums.append(int(i)*2) # certo
            mySum = sum(nums) # certo

        if int(i)*2 > 9:
            dgits.append((int(i)*2) // 10)
            dgits.append((int(i)*2) % 10)
            mydgs = sum(dgits)
            
    totalFirstSum = mySum + mydgs

    for j in number[ : : 2]:
        otherNums.append(int(j))
        sumMyOtherNums = sum(otherNums)

    if (totalFirstSum + sumMyOtherNums) % 10 == 0:
        if number[0] == '4':
            print("VISA")
        elif number[0] == '3':
            if number[1] == '4' or number[1] == '7':
                print("AMEX")
        else:
            print("INVALID")




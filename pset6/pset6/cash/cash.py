from cs50 import get_float

while True:
    change = get_float("Change owed: ")

    if change > 0:
        break

#print(f"{change}") # gets inputed change
convertedChange = round(change * 100); #needed to avoid floating point imprecision which causes errors in calculation

'''
converte-se o troco para evitar erros de calculo
e depois a esse troco ve-se quantas vezes se pode
retirar uma moeda , neste caso, de 0.25.
o numero de x q se puder retirar cada moeda é = ao
numero de moedas necessario p cobrir esse valor
'''
coinsCounter = 0

while convertedChange >= 25:
   convertedChange = convertedChange - 25
   coinsCounter = coinsCounter + 1
   #print(coinsCounter) # 40 moedas
#print(coinsCounter)


while convertedChange <= 25 and convertedChange >= 10:
   convertedChange = convertedChange - 10
   coinsCounter = coinsCounter + 1
#print(coinsCounter)

while convertedChange <= 10 and convertedChange >= 5:
   convertedChange = convertedChange - 5
   coinsCounter = coinsCounter + 1

while convertedChange <= 5 and convertedChange >= 1:
   convertedChange = convertedChange - 1
   coinsCounter = coinsCounter + 1
print(coinsCounter)
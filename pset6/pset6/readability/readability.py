from cs50 import get_string
import re

while True:
    text = get_string("Text: ")

    if(text):
       break

#print(text)
letterCounter = 0
wordCounter = 1
sentenceCounter = 0

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

text = text.lower()
for i in text:

    #print(i)
    if i in letters:
        letterCounter = letterCounter +1

    if i == ' ':
        wordCounter = wordCounter +1
        #print(wordCounter, " wordCounter")
        #print(re.search('[a-zA-Z]', text))

    if i == '!' or i == '?' or i == '.':
        sentenceCounter = sentenceCounter+1
        #print(sentenceCounter, "  sentenceCounter")

L = (letterCounter * 100) / wordCounter
S = (sentenceCounter * 100) / wordCounter

L = round(L, 2)
S = round(S, 2)

#print(L)
#print(S)

index = 0.0588 * L - 0.296 * S - 15.8

index = round(index)
#print(index)

if index >= 16:
    print("Grade 16+")
elif index <1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")

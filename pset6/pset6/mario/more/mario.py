while(True):
  print('Height: ', end='')
  height = int(input())
  if height > 0 and height < 9:
        break

space = height - 1
hash = 1

for i in range(height):
    print((space * " ") + (hash * "#")  + ("  ") +  (hash * "#") + (space * " ")    )
    space = space-1
    hash = hash +1
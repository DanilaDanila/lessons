from random import randint

n = randint(1, 30)
m = randint(1, 30)

print(n, m)

for i in range(n):
    for j in range(m):
        print(randint(-1000000, 1000000), end=' ')
    print()

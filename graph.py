import random
l = []
for i in range(100):
    f = []
    for i in range(random.randrange(1, 25)):
        f.append(random.randrange(1, 100))
    l.append(f)
print(l)

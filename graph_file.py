import random
file1 = open("graph.txt", "w")
for i in range(100):
    f = []
    for i in range(random.randrange(1, 25)):
        f.append(random.randrange(1, 100))
    z = str(f)
    file1.write(z)
    file1.write('\n')
file1.close()

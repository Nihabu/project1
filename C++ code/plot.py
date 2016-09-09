import numpy as np

infile = open("oppgave_1b.txt", "r")
n = 0
u = []
for line in infile:
    words = line.split()
    u.append(float(words[0]))
    n += 1
u.reverse()
import matplotlib.pyplot as plt
x = np.linspace(0, 1, n)
print u
plt.plot(x, u)
plt.show()

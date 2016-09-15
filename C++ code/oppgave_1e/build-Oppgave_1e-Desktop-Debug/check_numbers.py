import numpy as np
import matplotlib.pyplot as plt

infile1 = open("/home/erik/FYS3150/project1/C++ code/Oppgave 1a-c/build-oppgave_1a-c-Desktop-Debug/oppgave_1d.txt", "r")
infile2 = open("oppgave_1e.txt", "r")

"""
This loop gives the solution for x from assignment c
"""
x1 = []
for line in infile1:
    words = line.split()
    x1.append(float(words[0]))
x1 = x1[1:len(x1)-1]

"""
This loop gives the solution for x from assignment e
"""
x2 = []
for line in infile2:
    words = line.split()
    x2.append(float(words[0]))

n = len(x2)
h = 1./(len(x1)+1)
x = np.linspace(0, 1, n+2)
f = 1 - (1 - np.exp(-10))*x - np.exp(-10*x) # exact solution
print len(x2)
"""
Slicing x and f to match the length of x2 in the plot. This means removing our initial conditions.
"""
plt.plot(x[1:n+1], f[1:n+1], x[1:n+1], x2, x[1:n+1], x1)
plt.legend(["Exact solution", "LU solution", "Tridiagonal solver"])
plt.show()


"""
printing the maximal deviation from the exact solution for 
"""
print "The max deviation from exact solution in assignment e is %E" % max(abs(x2 - f[1:n+1]))
print "The max deviation from exact solution in assignment c is %E" %  max(abs(x1 - f[1:n+1]))


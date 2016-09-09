import numpy as np
import matplotlib.pyplot as plt
def test_error():
    infile = open("oppgave_1d.txt", "r")
    Error = []
    for line in infile:
        words = line.split()
        Error.append(float(words[0]))
    #print Error[1]
    x = np.linspace(0, 1, len(Error))
    #Error.reverse()
    plt.plot(x, Error, "-")
    plt.legend(["Error"])
    plt.xlabel("x")
    plt.ylabel("Error(x)")
    plt.show()

def test_u():
    import numpy as np
    import matplotlib.pyplot as plt
    infile = open("oppgave_1d.txt", "r")
    u = []
    for line in infile:
        print line
        words = line.split()
        u.append(float(words[0]))
    #u.reverse()
    #print u[0]
    x = np.linspace(0, 1, len(u))
    v = 1 - (1 - np.exp (-10))*x - np.exp (-10*x);
    plt.plot(x, u, x, v)
    plt.legend(["beregnet", "PC"])
    #plt.xlabel("n")
    #plt.ylabel("E(n)")
    plt.show()
test_error()

import numpy as np
import matplotlib.pyplot as plt

def test_error():
    points = 0
    for line in infile:
        words = line.split()
        Error.append(float(words[0]))
        points += 1

    h_max = 1./(1e4 + 1)
    h_min = 1./(1e6 + 1)
    h = np.log10(np.linspace(h_min, h_max, points))
    plt.plot(h, np.log10(Error), "-")
    plt.legend(["Error(h) for optimal h calculation"], loc = ("upperleft"))
    plt.xlabel("log10(h)")
    plt.ylabel("log10(Error(h))")
    plt.show()

def test_u():
    infile = open("oppgave_1d.txt", "r")
    u = []
    for line in infile:
        words = line.split()
        u.append(float(words[0]))
    x = np.linspace(0, 1, len(u))
    v = 1 - (1 - np.exp (-10))*x - np.exp (-10*x);
    plt.plot(x, u, x, v)
    plt.legend(["Numeric", "Exact"])
    plt.xlabel("x")
    plt.ylabel("v(x)")
    plt.title("v(x) for n = 1000")
    plt.show()

test_u()

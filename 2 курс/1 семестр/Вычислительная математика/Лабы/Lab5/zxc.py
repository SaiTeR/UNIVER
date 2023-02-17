import math
import numpy as np
from matplotlib import pyplot as plt


def f(x):
  return x*np.sqrt(x+1)-1
def fprime(x):
  return (3*x+2)/(2*np.sqrt(x+1))
def fprime2(x):
  return (3*x+4)/(np.sqrt(x+1)*(4*x+4))
e_input = float(input()) #ввод точности
a1=10 #начальное значение Х0
y=0
if f(a1)*fprime2(a1): #условие сходимости
  while (f(a1)/fprime(a1))>e_input:
    a2=a1-f(a1)/fprime(a1) #алгоритм ньютона
    print(a2)
    print("")
    f1=f(a1)/fprime(a1)
    print("{:.8f}".format(f1), "текущая точность")
    print("--------------")
    a1=a2
    y=y+1
  else :
    print("_______________")
    print("")
    f=f(a1)/fprime(a1)
    print(a1, "значение корня")
    print("{:.8f}".format(f), "точность")
    print("")
    print(y, "скорость сходимости")
    print("_______________")
    x = np.arange(-10, 10.01, 0.01)
    plt.plot(x, f(x))
    plt.show()
else :
  print ("ABOBA")
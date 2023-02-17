##########
#  CODE  #          Лабораторная работа № 5
#   BY   #      Методы вычислительной математики для 
# SAITER #      нахождения корней нелинейного уравнения
##########

import numpy as np
import matplotlib.pyplot as plt

def F(x):
    #return (5 * x - 8 * np.log(x) - 8)
    #return (x + np.cos(x) - 2)
    return 2 - x - (4 / (x + 2) ** 2)

def F_2pr(x):
    return (8 / (x**2))

def half_interval(a, b): #для дихотомии
    return (a + b) / 2



def method_dich_cnt(a, b, E): #МЕТОД ДИХОТОМИИ
    counter = 0
    while abs(b - a) > E:
        counter += 1

        fa = F(a)
        c = half_interval(a, b)
        fc = F(c)
        if fa * fc >= 0:
            a = c
        else:
            b = c

    return counter


def method_chord(a, b, err):
    if(F(a) * F(b) >= 0):
        print("Неверный интервал")
        exit()
    iter = 0
    c1 = a
    while True:
        c2 = a - ( F(a) * (a-b) ) / ( F(a)- F(b) )

        if abs(c1-c2) < err:
            return [c2, iter]

        if (F(a) * F_2pr(a) > 0): #подбор точки для лучшей сходимости
            b = c2
        else:
            a = c2

        iter += 1
        print(iter, c2)
        if(iter >= 100000):
            print("Невозможно достичь заданной точности")
            exit()
        c1 = c2


def draw_graph(x1, a, b):
    x = np.arange(-10, 10.01, 0.01)
    plt.plot(x, F(x), 0, 0) # отрисовка графа

    plt.title("y(x) = 5x – 8ln(x) - 8") #
    plt.xlabel("x")                     # оформление графа
    plt.ylabel("y")                     #
    
    plt.vlines(a, -10, 10, color = 'r')
    plt.vlines(b, -10, 10, color = 'r')
    plt.vlines(0, -10, 30, color = 'black')
    plt.hlines(0, -2, 10, color = 'black')

    plt.text(x1 + 0.1, F(x1) - 2, '(' + str(round(x1, 3)) + ",0)") # координаты точки
    plt.scatter(x1, F(x1), color = "red", s = 40, marker = 'o') # точка по найденному X

    plt.show()



#########################################
print("Для уравнения    5x – 8ln(x) = 8     найдем корни МЕТОДОМ ХОРД")
print()

A, B = map(float, input("Введиете интервал поиска корня [A,B]: ").split())
e = float(input("Введите точность: "))

x, iter_chord = method_chord(A, B, e)

print()
print("x =", x)
print("Итерации(метод Хорд):\t\t", iter_chord)
print("Итерации(метод Дихотомии):\t", method_dich_cnt(A, B, e))


for i in range(1, 10):
    x, iter_chord = method_chord(A, B, 0.1 ** -i)

print()

draw_graph(x, A, B)
#########################################

##########
#  CODE  #          Лабораторная работа № 5
#   BY   #      Методы вычислительной математики для 
# SAITER #      нахождения корней нелинейного уравнения
##########

import numpy as np
import matplotlib.pyplot as plt

def F(x):
    return (5 * x - 8 * np.log(x) - 8)

def F_2pr(x):
    return (8 / (x**2))



# def method_dich(a, b, E): #МЕТОД ДИХОТОМИИ
#     while abs(b - a) > E:

#         counter += 1
#         if counter >= max_counter:
#             print('Слишком много шагов')
#             break

#         if abs(b - a) <= E:
#             print('Значение math.abs(b-a) стало меньше чем E')
#             break

#         print('\n\nШаг №{counter}'.format(counter=counter))

#         fa = F(a)
#         c = half_interval(a, b)
#         fc = F(c)
#         if fa * fc >= 0:
#             a = c
#         else:
#             b = c
#         print('fa = {f_a} fc = {f_c} fa * fc = {res}'.format(f_a=fa, f_c=fc, res=fa * fc))
#         print('a = {a} b = {b}'.format(a=a, b=b))


def method_chord(a, b, err):
    if(F(a) * F(b) >= 0):
        print("Неверный интервал")
        exit()
    iter = 0
    c1 = a
    while True:
        c2 = a - ( F(a) * (a-b) ) / ( F(a)- F(b) )

        if abs(c1-c2) < err:
            print("Итерации(Метод хорд):", iter)
            return c2

        if (F(a) < 0 and F(c2) > 0) or (F(a) > 0 and F(c2) < 0):
            b = c2
        else:
            a = c2

        c1 = c2



# def method_chord2(x_pr, x_cr, e):
#     iter = 0
#     # x_pr == x**(k - 1)
#     # x_nxt == x**(k + 1)
#     # x_cr == x**k
    
#     if(F(x_pr) * F(x_cr) > 0): #проверка интервала
#         print("Неверный интервал")
#         exit()

#     # if (F(x_pr) * F_2pr(x_pr) < 0): #проверка уловия сходимости                                     !!!!!!!!!!!!!
#     #     print("Функция расходится")
#     #     exit()   
        
#     while (abs(x_cr - x_pr) > e): #АЛГОРИТМ
#         x_nxt = x_cr - F(x_cr) * (x_pr - x_cr) / (F(x_pr) - F(x_cr))
#         x_pr = x_cr
#         x_cr = x_nxt
#         iter += 1
#         print(x_cr)

#     print("Итерации(Метод хорд):", iter)
#     return x_cr

    

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

print()
x = method_chord(A, B, e)
#x = method_chord2(A, B, e)
print("x =", x)

draw_graph(x, A, B)
#########################################

#include <iostream>
using namespace std;



int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Задание 1" << endl << "Start = ";
    double start, iter;
    cin >> start;
    iter = (4 - start) / 9;

    while(start <= 4)
    {
        cout << "x = " << start << " f(x) = " << sin(start) / start << endl;
        start += iter;
    }


    cout << endl << "Задание 2" << endl << "MAX = ";
    int S = 0;
    int MAX;
    int N = 1;
    cin >> MAX;

    while (S <= MAX)
    {
        S += fib(N);
        N++;
    }

    cout << "Сумма = " << S << "  N = " << N;
    

    return 0;
}

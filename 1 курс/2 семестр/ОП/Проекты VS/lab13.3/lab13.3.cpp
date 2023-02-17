#include <iostream>
#include <fstream>
using namespace std;


void KostukMegaCode(double** A, int m, int n)
{
    const double eps = 0.000000000000000000001;
    int* L = new int[n];
    int i, r, v, u, j, k;
    double z, p, c;
    double* X = new double[n];

    for (i = 0; i < n; i++) 
        L[i] = i;
    i = 0;
    if (n < m) r = n; else r = m;
    while (i < r)
    {
        v = i; u = i;
        for (j = i; j < m; j++)
            for (k = i; k < n; k++)
                if (abs(A[j][k]) > abs(A[v][u]))
                {
                    v = j; u = k;
                }

        if (abs(A[v][u]) < eps) r = i;
        else
        {
            if (v != i)  /*перестановка  i-го уравнения с  v-м*/
                for (j = i; j <= n; j++)
                {
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
                }

            if (u != i) /* перестановка  i-го столбца с u-м*/
            {
                for (k = 0; k < m; k++)
                {
                    z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
                }
                p = L[i]; L[i] = L[u]; L[u] = p;
            }

            c = A[i][i];
            for (j = i; j <= n + 1; j++) A[i][j] /= c;

            for (k = 0; k < m; k++)
                if (k != i)
                {
                    c = A[k][i];
                    for (j = i; j <= n; j++) A[k][j] -= c * A[i][j];
                }

            i++;
        }
    }

    i = r;
    while (i < m && abs(A[i][n]) < eps) i++;
    if (i < m) { cout << "решение системы не существует"; }
    else if (r == n) /*решение системы единственное*/
    {
        cout << "Единственное решение:" << endl;
        for (j = 0; j < n; j++) 
        {
            X[L[j]] = A[j][n];
            cout << "x" << (j + 1) << " = " << X[L[j]] << endl;
        } 
    }
    else
    {/*задание значений независимым переменным:
               X[L[r]], ..., X[L[n-1]]*/
               /*вычисление зависимых переменных:*/
        for (int i = r; i <= (n - 1); i++)
        {
            cout << "X" << (L[i] + 1) << " is free" << endl;
            cout << "X" << (L[i] + 1) << " = ";
            cin >> X[L[i]];
        }
           

        cout << "Множество решений:" << endl;
        for (j = 0; j < r; j++)
        {
            X[L[j]] = A[j][n];
            for (k = r; k < n; k++)
                X[L[j]] -= (A[j][k] * X[L[k]]);
        }

        for(j = 0; j < n;j++)
            cout << "X" << (j + 1) << " = " << X[j] << endl;

    }

}

int main()
{
	setlocale(LC_ALL, "RUS");

    fstream file("sod.txt");
    if (!file)
    {
        cout << "Невозможно открыть файл";
        return -1;
    }


    int M, N;
    file >> M; //количество линейных уравнений
    file >> N; //количество неизвестных

    double** A = new double* [M]; //матрица коэф-ов
    for (int i = 0; i < M; i++)
    {
        A[i] = new double[N + 1];
        for (int j = 0; j < (N + 1); j++)
            file >> A[i][j];

    }

    cout << "Считанная матрица:" << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            cout << A[i][j] << " ";
            if (j == N - 1)
                cout << "= ";
        }
        cout << endl;
    }
    KostukMegaCode(A, M, N);
}
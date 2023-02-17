#include <iostream>

using namespace std;


int Det(int n, int** A, double eps)
{
    int i = 0; int r = n; int p = 1;
    double z, c;
    int X;
    while (i < r)
    {
        int v = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[v][i])) v = j;

        if (abs(A[v][i]) < eps) r = i;
        else
        {
            if (v != i)
            {
                p = -p;
                for (int j = i; j < n; j++)
                {
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
                }
            }

            for (int k = i + 1; k < n; k++)
            {
                c = A[k][i] / A[i][i];
                for (int j = i; j < n; j++)
                    A[k][j] -= c * A[i][j];
            }

            i++;
        }
    }

    if (r < n) X = 0;
    else
    {
        X = p * A[0][0];
        for (i = 1; i < n; i++) X *= A[i][i];
    }


    return X;
}


int Rev(int n, int** A, int eps, int** &B)
{
    if (Det(n, A, eps) == 0)
    {
        cout << "Определитель матрицы А равен 0 => матрица А вырожденная и обратной не имеет";
        return 0;
    }

    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j) B[i][j] = 1;
                else B[i][j] = 0;
            }

        int i = 0; int r = n;
        double z;
        int c;
        while (i < r)
        {
            int v = i;
            for (int j = i + 1; j < n; j++)
                if (abs(A[j][i]) > abs(A[v][i])) v = j;


            if (abs(B[v][i]) < eps) r = i;
            else
            {
                if (v != i)
                {
                    for (int j = i; j < n; j++)
                    {
                        z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
                    }
                    for (int j = 1; j < n; j++)
                    {
                        z = B[i][j]; B[i][j] = B[v][j]; B[v][j] = z;
                    }
                }

                double aii = A[i][i];
                for (int j = i; j <= n; j++)
                    A[i][j] /= aii;
                for (int j = 1; j <= n; j++)
                    B[i][j] /= aii;

                for (int k = 0; k < n; k++)
                    if (k != i)
                    {
                        c = A[k][i];
                        for (int j = i; j < n; j++)
                            A[k][j] -= c * A[i][j];
                        for (int j = 0; j < n; j++)
                            B[k][j] -= c * B[i][j];
                    }

                i++;
            }
        }

        cout << "Матрица B(Обратная матрице А)" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        return 1;
    }
        
   
}


void Mult(int** E, int* C, int n, int m, int * &X)
{
    double d;
    
    
    for (int i = 0; i < n; i++)
    {
        d = 0;
        for (int j = 0; j < m; i++)
            d += E[i][j] * C[j];
        X[i] = d;
    }

    cout << "Вектор X(E * C):" << endl;
    for (int i = 0; i < n; i++)
        cout << X[i] << " ";
}


int main()
{
    setlocale(LC_ALL, "Rus");
    
    int n;
    double eps;
    cout << "Введите точность вычислений: ";
    cin >> eps;
    cout << endl << "Введите размерность матрицы: ";
    cin >> n;

    int** A = new int* [n];
    int** D = new int* [n];
    cout << endl << "Введите матрицу A:" << endl;
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        D[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }


    Rev(n, A, eps, D);

    cout << endl << "Введите матрицу Е:" << endl;
    int** E = new int* [n];
    for (int i = 0; i < n; i++)
    {
        E[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> E[i][j];
        }
    }

    cout << "Введите размер вектора m: ";
    int m;
    cin >> m;

    int* C = new int[m];
    cout << "Введите вектор C:" << endl;
    for (int i = 0; i < m; i++)
        cin >> C[i];

    int* X = new int[n];

    Mult(E, C, n, m, X);

    int m1;
    cout << "Введите размер вектора B1: ";
    cin >> m1;
    int* B1 = new int[m1];
    int* X1 = new int[n];
    Mult(D, B1, n, m1, X1);
    cout << endl << "X1:" << endl;
    for (int i = 0; i < m1; i++)
        cout << X1[i];

    int m2;
    cout << "Введите размер вектора B2: ";
    int* B2 = new int[m2];
    int* X2 = new int[n];
    Mult(D, B2, n, m2, X2);
    cout << endl << "X2:" << endl;
    for (int i = 0; i < m2; i++)
        cout << X2[i];
}


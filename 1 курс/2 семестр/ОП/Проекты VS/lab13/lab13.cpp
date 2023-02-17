#include <iostream>
#include <fstream>;

using namespace std;


double* gauss(double** A, double* B, int M, int N);
bool ItsNoUse = false; //для систем где нет решений

int main()
{
    setlocale(LC_ALL, "Rus");

    fstream file("triangle.txt");
    if (!file)
    {
        cout << "Невозможно открыть файл";
        return -1;
    }
    
    
    int M, N;
    file >> M; //количество линейных уравнений
    file >> N; //количество неизвестных

    double** A = new double* [M]; //матрица коэф-ов
    double* B = new double[M]; //матрица того, че короче после знака =
    for (int i = 0; i < M; i++)
    {
        A[i] = new double[N];
        for (int j = 0; j < N; j++)
            file >> A[i][j];

        file >> B[i];
    }

    cout << "Считанная матрица:" << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";

        cout << "= " << B[i] << endl;
    }

    cout << endl << "Найденные решения:" << endl;
    double* x = gauss(A, B, M, N); //массив с ответами
    if (ItsNoUse)
        cout << "Решения для системы нет";
    else
    {
        for (int i = 0; i < N; i++)
            cout << "x" << (i + 1) << " = " << x[i] << endl;
    }
    
    cout << endl;
    return 0;
}



double* gauss(double** a, double* y, int m, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.0000000001;  // точность
    x = new double[n];
    k = 0;

    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < m; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }

        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            ItsNoUse = true;
            return 0;
        }

        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;


        // Нормализация уравнений
        for (int i = k; i < m; i++)
        {
            double temp = a[i][k];

            if (abs(temp) < eps) // для нулевого коэффициента пропустить
                continue; 
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)// уравнение не вычитать само из себя
                continue; 
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }

    for (k = m - 1; k >= 0; k--) // обратная подстановка
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }


    return x;
}

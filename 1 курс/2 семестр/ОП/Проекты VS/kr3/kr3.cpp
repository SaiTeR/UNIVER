#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
	cout << "Введите число вершин n: ";
	cin >> n;

	int** M = new int* [n]; //матрица смежности
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[n];
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	}

    int weight;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "Вввод матрицы расстояний. Введите вес из вершины " << i << " в вершину " << j << endl;
                cin >> weight;
                M[i][j] = weight;
            }
            else
            {
                M[i][j] = 99999999; // ~ такого пути нет
            }
        }
    }

    int a, b, c;
    int* R = new int[n]; //массив кратчайших расстояний

    int* Q = new int[n];
    int* P = new int[n];
    int* S = new int[n];

    cout << "Введите номер начальной вершины а и последних вершин b и c" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    for (int i = 0; i < n; i++)
    {
        Q[i] = 1; R[i] = M[a][i]; P[i] = a;
    }

    Q[a] = 0; P[a] = -1;

    int z, k, rmin;

    for (int j = 1; j < n; j++)
    {
        rmin = 1000000;
        for (int i = 0; i < n; i++)
            if (Q[i] && (R[i] < rmin))
            {
                rmin = R[i]; k = i;
            }

        Q[k] = 0;

        for (int i = 0; i < n; i++)
            if (Q[i] && (z = M[k][i] + R[k]) < R[i])
            {
                R[i] = z; P[i] = k;
            }
    }

    int i;
    i = b; k = 0; S[k] = b;

    while (i != P[a])
    {
        i = P[i]; k++; S[k] = i;
    }


    cout << "Длина кратчайшего пути  до вершины b: " << R[b] << endl;

    cout << "Кратчайший путь до вершины b выглядит так: ";
    k--;
    for (; k >= 0; k--)
        cout << S[k] << " ";
    cout << endl;

    i = c; k = 0; S[k] = c;

    while (i != P[a])
    {
        i = P[i]; k++; S[k] = i;
    }

    cout << "Длина кратчайшего пути  до вершины с: " << R[c] << endl;

    cout << "Кратчайший путь до вершины с выглядит так: ";
    k--;
    for (; k >= 0; k--)
        cout << S[k] << " ";

    return 0;
}
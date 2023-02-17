#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//bool file1_err = false;
//bool file2_err = false;

void Case1()
{
	fstream Input;
	Input.open("1.txt");

	if (!Input)
	{
		cout << "Ошибка в чтении файла для Упражнения 1";
		//file1_err = true;
	}
		

	else
	{
		int** SmezhMatrix; //матрица смежности
		int n, m; //размерность
		int a, b; //пара вершин

		Input >> n; //вершины
		Input >> m; //ребра

		SmezhMatrix = new int* [n];
		for (int i = 0; i < n; i++) //заполнение матрицы нулями
		{
			SmezhMatrix[i] = new int[n];
			for (int j = 0; j < n; j++)
				SmezhMatrix[i][j] = 0;
		}


		for (int k = 0; k < m; k++) //заполнение матрицы смежности данными графа
		{
			Input >> a;
			Input >> b;

			SmezhMatrix[a - 1][b - 1] = 1;
			SmezhMatrix[b - 1][a - 1] = 1;
		}

		for (int x = 0; x < n; x++) //вывод матрицы смежности в консоль
		{
			for (int z = 0; z < n; z++)
				cout << SmezhMatrix[x][z] << " ";

			cout << endl;
		}


		fstream Output;
		Output.open("2.txt");
		if (Output)
		{
			Output << n << " " << m << endl;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					Output << SmezhMatrix[i][j] << " ";

				Output << endl;
			}
		}

		cout << "Zадача Vыполнена, чекайте файлы";
		Input.close();
		Output.close();
	}

}



void Case2()
{
	fstream Input;
	Input.open("2.txt");

	if (!Input)
	{
		cout << endl << "Ошибка в чтении файла для Упражнения 2";
		//file2_err = true;
	}
		

	else
	{
		int n, m; //размерность
		Input >> n >> m;

		int* v1, * v2, * D, * S, * L, * U;
		v1 = new int[m];
		v2 = new int[m];

		int** Matrix = new int* [n];
		for (int i = 0; i < n; i++)
		{
			Matrix[i] = new int[n];
			for (int j = 0; j < n; j++)
				Input >> Matrix[i][j];
		}

		for (int i = 0; i < m; i++)
		{
			v1[i] = 0;
			v2[i] = 0;
		}


		int z = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((Matrix[i][j] != 0) && (Matrix[j][i] != 0))
				{
					v1[z] = i;
					v2[z] = j;
					z += 1;
				}
			}
		}


		int k;
		D = new int[m + m];
		S = new int[n + 1];
		L = new int[n + 1];
		U = new int[n];

		for (int j = 0; j < n + 1; j++) //обнуление длин списков
			L[j] = 0;

		for (int i = 0; i < n; i++) //вычисление длин списков
		{
			for (int j = 0; j < n; j++)
				if (Matrix[i][j] == 1)
					L[i]++;
		}

		S[0] = 0; //вычисление начальных индексов на списки в массиве D
		for (int j = 1; j < n + 1; j++)
			S[j] = S[j - 1] + L[j - 1];

		for (int j = 0; j < n; j++)
			U[j] = S[j];

		//дублирование начальных индексов
		for (int i = 0; i < m; i++) //распределение смежных вершин по спискам массива D
		{
			k = v1[i]; D[U[k]] = v2[i]; U[k]++;
			k = v2[i]; D[U[k]] = v1[i]; U[k]++;
		}
		cout << endl << "L:" << " ";
		for (int j = 0; j < n + 1; j++) cout << L[j] << " ";

		cout << endl << "S:" << " ";
		for (int j = 0; j < n + 1; j++) cout << S[j] + 1 << " ";

		cout << endl << "D:" << " ";
		for (int j = 0; j < m + m; j++) cout << D[j] + 1 << " ";




		fstream Output;
		Output.open("3.txt");
		if (Output)
		{
			Output << n << " " << m << "" << endl;

			for (int j = 0; j < n + 1; j++) Output << L[j] << " "; //L
			Output << endl;

			for (int j = 0; j < n + 1; j++) Output << S[j] + 1 << " ";//S
			Output << endl;

			for (int j = 0; j < m + m; j++) Output << D[j] + 1 << " ";//D
			Output << endl;
		}

		cout << endl << "Zадача Vыполнена, чекайте файлы";
		Input.close();
		Output.close();
	}

}



void Case3()
{
	fstream Input;
	Input.open("3.txt");

	if (!Input)
		cout << "Ошибка в чтении файла для Упражнения 3";

	else
	{
		int n, m;

		Input >> n;
		Input >> m;

		int* L, * S, * D, * v1, * v2;
		D = new int[m + m];
		S = new int[n];
		L = new int[n];

		//L
		for (int i = 0; i < n + 1; i++)
			Input >> L[i];

		//S
		for (int i = 0; i < n + 1; i++)
			Input >> S[i];

		//D
		for (int i = 0; i < (2 * m); i++)
			Input >> D[i];

		v1 = new int[m + m];
		v2 = new int[m + m];

		int z = 0;
		int ot = 0;
		int doo = 0;
		int k = 0;
		for (int i = 0; i < n + 1; i++)
		{
			ot = S[i] - 1;
			doo = ot + L[i];
			while (ot < doo)
			{
				v1[z] = i + 1;
				v2[z] = D[ot];
				z++;
				ot++;
			}

		}

		for (int i = 0; i < m + m; i++)
		{
			cout << v1[i] << " " << v2[i] << endl;

		}

		ofstream Output;
		Output.open("4.txt");
		if (Output)
		{
			for (int i = 0; i < m + m; i++)
				Output << v1[i] << " " << v2[i] << endl;
		}


		cout << "Zадача Vыполнена, чекайте файлы";
		Input.close();
		Output.close();
	}
	
	
}


int main()
{
	setlocale(LC_ALL, "RUS");

	fstream zxc;
	zxc.open("1.txt");
	int n, m, a, b;
	zxc >> n >> m;
	cout << "Входные данные:" << endl << endl;
	for (int k = 0; k < m; k++)
	{
		zxc >> a;
		zxc >> b;
		
		cout << a << "-" << b << endl;
	}

	cout << endl << "#################################################################" << endl;

	cout << endl << "Упражнение 1." << endl << endl;
	Case1();

	cout << endl << endl << "#################################################################" << endl;

	cout << endl << "Упражнение 2." << endl;
	Case2();

	cout << endl <<endl << "#################################################################" << endl;

	cout << endl << "Упражнение 3." << endl << endl;
	Case3();

	cout << endl;
}

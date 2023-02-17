#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Задание 1" << endl;
    int arr1[10];
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = i * i;
        cout << arr1[i] << endl;
    }
    cout << endl;

    cout << "Задание 2" << endl;;
    int arr2[10];
    for (int i = 0; i < 10; i++)
    {
        *(arr2 + i) = i * i;
        cout << *(arr2 + i) << endl;
    }
    cout << endl;

    cout << "Задание 3" << endl;
    int *arr3;
    arr3 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr3[i] = i * i;
        cout << arr3[i] << endl;
    }
    cout << endl;

    cout << "Задание 4" << endl;
    int *arr4;
    arr4 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(arr4 + i) = i * i;
        cout << *(arr4 + i) << endl;
    }

    return 0;
}



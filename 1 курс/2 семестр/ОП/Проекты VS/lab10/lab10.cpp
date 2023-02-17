#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>


using namespace std;

void Pack(int* arr, int* arrNums) //ереванский шпак
{
    for (int i = 0; i < 18; i++)
        arrNums[i] = 0;

    for (int i = 0; i < 2000; i++)
        arrNums[arr[i]]++;

}

void Unpack(int* arrNums, int* outputArr) //ервеанский аншпак
{
    int cnt = 0;
    for(int i = 0; i < 18; i++)
        for (int j = 0; j < arrNums[i]; j++)
        {
            outputArr[cnt] = i;
            cnt++;
        }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    random_device rd; //си плюс плюсовый нищтяк
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 17); //тут писать диапазонш

    int arr[2000], arrNums[18], outputArr[2000];
    


    cout << "Исходный массив:" << endl;
    for (int i = 0; i < 2000; i++)
    {
        arr[i] = dist(gen);
        cout << arr[i] << " ";
    }   
    //sort(arr, arr + 1000);

    cout << endl << endl << "А. Информация о числах из массива:" << endl;
    Pack(arr, arrNums);
    for (int i = 0; i < sizeof(arrNums) / sizeof(arrNums[0]); i++)
        cout << i << " = " << arrNums[i] << endl;

    cout << endl << "Б. Распаковка массива:" << endl;
    Unpack(arrNums, outputArr);
    for (int i = 0; i < sizeof(outputArr) / sizeof(outputArr[0]); i++)
        cout << outputArr[i] << " ";

    cout << endl;

    for (int i = 10; i < 10; i++)
    {
        cout << rand() << endl;
    }
    return 1337;
}



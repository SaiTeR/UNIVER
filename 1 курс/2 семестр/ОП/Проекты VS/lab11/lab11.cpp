#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    cout << "Введите int a: ";
    cin >> a;
    cout << "А вот вам и а: " << a << endl << endl;



    float b;
    printf("Введите float b: ");
    scanf_s("%f", &b);
    printf("Значение переменной b = %f", b);
    printf("\n");



    char c[80];
    cout << endl << "Введите строку c: ";
    gets_s(c);
    gets_s(c);
    cout << "Да ты посмотри, тут вообще пэсня: ";
    puts(c);
    cout << endl;



    ofstream file;
    file.open("test1");
    if (!file)
    {
        cout << "Файл поломался";
        return -1;
    }
    else
        cout << "Файл открылся, можно закрывать" << endl;

    if (file.eof())
        file.close();
    cout << endl;


    
    FILE* input_f;
    input_f = fopen("inp.txt", "r");
    int data;
    fscanf(input_f, "%d", &data);
    cout << "Вот что нашлось в файле: " << data << endl;

    FILE* output_f;
    output_f = fopen("oupt.txt", "w");
    fprintf(output_f, "Теперь тут лежит %d. ", data);
    cout << "Данные были записаны в файл" << endl;
    

    return 1337;
}



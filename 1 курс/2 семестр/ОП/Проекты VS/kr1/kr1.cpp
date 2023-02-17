#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    if (a > b) return true;
    else return false;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "n: ";
    int n, cnt = 0;
    cin >> n;
    char** D = new char* [n];
    int* C = new int[n];

    for (int i = 0; i < n; i++) //вводим словарь
    {
        C[i] = 0;
        D[i] = new char[21];
        cin >> D[i];
    }

    string word = "";

    ifstream file("text.txt");
    while (!file.eof())
    {
        char sym;
        
        
        file.get(sym); //считываем посимвольно

        if (isalpha(sym)) //если символ буква - собираем слово
        {
            word += sym;
        }

        else //если нет то начинем сверку
        {
            string char_word;
            bool check = false; // говорим что совпадений не будет
            for (int i = 0; i < n; i++)
            {
                char_word = D[i];

                if ((char_word == word)) //если слово из текстового файла совпадает со словом из словаря
                {
                    C[i]++;
                    check = true;
                }
            }

            if (check == false && (word.length() > 0)) //если слово не совпало
                cnt++;

           word = ""; //обнулсяем слово
        }


    }


    sort(C, C + n);

    cout << "Количество слов, не совпавших ни с одной строкой из массива D: " << cnt << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << D[C[i]] << endl;
    }

    file.close();
    return 0;
}

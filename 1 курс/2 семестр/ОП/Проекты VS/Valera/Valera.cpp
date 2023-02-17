#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    fstream inp ,out;
    inp.open("test1.txt");
    out.open("out1.txt");
    

    string S;
    bool check = true; //true - текущая открывающая // false - текущая закрывающая
    bool IsOk = true;
    inp >> S;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(' && check)
            check = false;

        else if (S[i] == ')' && !check)
            check = true;

        else
        {
            IsOk = false;
            out << "Круглые скобки расставлены неправильно" << endl;
            if (check)
                out << "Должна быть ( на позиции S[" << i << "]";
            else
                out << "Должна быть ) на позиции S[" << i << "]";
        }
    }

    if (IsOk)
    {
        out << "Круглые скобки расставлены правильно";
    }
}


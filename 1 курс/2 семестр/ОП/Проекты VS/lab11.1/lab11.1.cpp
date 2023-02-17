#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    fstream file("test4.txt");
 
    if (!file)
    {
        cout << "Файл не открылся";
        return -1;
    }



    char** words = new char*[50];

    int i = 0;
    while (!file.eof())
    {
        words[i] = new char[25];
        file >> words[i];
        cout << words[i] << " ";
        i++;
    }
    
    int max_root, big_root = -1, max_cnt = 0;

    cout << endl;
    for (int k = 0; k < i; k++)
    {
        int cnt = 0; //счотчик скока раз было корневым
        for (int j = 0; j < i; j++)
        {
            
            if ((k != j) && (strncmp(words[k], words[j], strlen(words[k])) == 0))
            {
                cnt++;
            }
        }

        if (cnt != 0)
        {
            if (big_root == -1)
                big_root = k;

            if (strlen(words[k]) > strlen(words[big_root]))
                big_root = k;

            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                max_root = k;
            }
        }
        
    }

    fstream file_a("test_answer.txt");
    file_a << "=================" << endl;
    if (max_cnt != 0)
    {
        file_a << words[big_root] << " ";
        for (int k = 0; k < i; k++)
        {
            if ((strncmp(words[big_root], words[k], strlen(words[big_root])) == 0) && (big_root != k))
                file_a << words[k] << " ";

        }
        file_a << endl << words[max_root] << " " << max_cnt;

        cout << "big root: " << words[big_root] << endl;
        cout << "max root: " << words[max_root] << " " << max_cnt << endl;
    }

    else
    {
        file_a << "NO";
        cout << endl << "NO";
    }
        ;
        
    

}



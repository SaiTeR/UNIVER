#include <iostream>
#include <string>

using namespace std;
int main()
{
    //const char* zxc = "zxc";
    //cout << strlen(zxc) << endl;
    //char* copy = new char[strlen(zxc) + 1];

    //strcpy(copy, zxc);
    ///*for (int i = 0; i < strlen(zxc); i++)
    //    copy[i] = zxc[i];*/
    //

    //copy[3] = '\0';
    //cout << copy << endl;

    //strcat(copy, zxc);
    //cout << copy;


    char** lines = new char*[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lines[i] = new char[10];
        cin >> lines[i];
    }

    for (int i = 1; i < n; i += 2)
        cout << (i + 1) << ". " << lines[i] << endl;

    
    
    /*char* str_s = new char[3], * str_d, * pd;
    for (int i = 0; i < 3; i++)
        cin >> str_s[i];

    cout << strlen(zxc) << endl;
    str_d = new char[strlen(zxc) - 10];
    pd = str_d;
    while (*str_d++ = *str_s++);
    cout << pd;*/

}



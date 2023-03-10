////////////
//  CODE  //
//   BY   //      
// SAITER //      
////////////


#include <iostream>
#include <ctime>
using namespace std;


class CStr
{
    
private:
    char* S;
    
    char* Rand_S(int len) //генерация строки заданной длины
    {
        //srand(time(0));
        char* s_rnd = new char[len + 1];
        for (int i = 0; i < len; i++)
            s_rnd[i] = rand() % (('z') - ('a') + 1) + ('a');

        s_rnd[len] = '\0';

        return s_rnd;
    }


public:
    
    int getLenght()
    {
        return strlen(S);
    }
    
    ///////////////////////////////////////////////////////////////////////////////

    CStr() //конструктор по умолчанию, задает рандомную длину строки
    {
        //srand(time(0));
        S = Rand_S(rand() % 20 + 1);
    }

    CStr(char* inputS) //конструктор принимающий строку
    {
        S = new char[strlen(inputS) + 1];
        strcpy(S, inputS);
    }

    CStr(int custLen) //конструктор строки с пользовательской длиной
    {
        S = Rand_S(custLen);
    }

    CStr(CStr& other) //конструктор копирования
    {
        this->S = new char[strlen(other.S) + 1];
        strcpy(S, other.S);
    }

    ///////////////////////////////////////////////////////////////////////////////

    CStr& operator = (CStr& other)
    {
        delete[] S;
        this->S = new char[strlen(other.S) + 1];

        strcpy(this->S, other.S);

        return *this;
    }

    CStr& operator = (char* stroka)
    {
        delete[] S;
        this->S = new char[strlen(stroka) + 1];
        
        strcpy(S, stroka);

        return *this;
    }

    bool operator > (CStr& other)
    {
        if (strcmp(this->S, other.S) == 1)
            return true;
        else
            return false;
    }

    bool operator == (CStr& other)
    {
        if (strcmp(this->S, other.S) == 0)
            return true;
        else
            return false;
    }

    ///////////////////////////////////////////////////////////////////////////////

    friend ostream& operator << (ostream& stream, CStr& other);
    
    ///////////////////////////////////////////////////////////////////////////////

    ~CStr() //деструктор
    {
        //cout << "[Деструктор отработал для CStr: " << this << "]" << endl;
        delete[] S;
    }
};



class CStrArray
{
private:
    
    int lenght;
    CStr* S_Arr;

public:
    
    void sort_by_content()
    {
        for (int i = 0; i < lenght - 1; i++) 
        {
            for (int j = 0; j < lenght - i - 1; j++)
            {
                if (S_Arr[j] > S_Arr[j+1])
                {
                    CStr temp = S_Arr[j];
                    S_Arr[j] = S_Arr[j + 1];
                    S_Arr[j + 1] = temp;
                }
            }
        }
    }

    void sort_by_lenght()
    {
        for (int i = 0; i < lenght - 1; i++) 
        {
            for (int j = 0; j < lenght - i - 1; j++) 
            {
                if (S_Arr[j].getLenght() > S_Arr[j + 1].getLenght())
                {
                    CStr temp = S_Arr[j];
                    S_Arr[j] = S_Arr[j + 1];
                    S_Arr[j + 1] = temp;
                }
            }
        }
    }

    bool check_sort()
    {
        for (int i = 0; i < lenght - 1; i++)
        {
            if (S_Arr[i] > S_Arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    int bin_search(char* toFind)
    {
        CStr key(toFind);

        bool flag = false;
        int l = 0; // левая граница
        int r = lenght; // правая граница
        int mid;

        while ((l <= r) && (flag != true)) 
        {
            mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

            if (S_Arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
            if (S_Arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
            else l = mid + 1;
        }

        if (flag)
            return mid;
        else
            return -1;
    }

    ///////////////////////////////////////////////////////////////////////////////

    CStrArray() {}
    
    CStrArray(int len)
    {
        lenght = len;
        S_Arr = new CStr[len];
    }

    ///////////////////////////////////////////////////////////////////////////////

    CStr& operator [] (int index)
    {
        return S_Arr[index];
    }

    ///////////////////////////////////////////////////////////////////////////////

    friend ostream& operator << (ostream& stream, CStrArray& other);

    ///////////////////////////////////////////////////////////////////////////////

    ~CStrArray()
    {
        cout << "[Деструктор отработал для CStrArray: " << this << "]" << endl;
        delete[] S_Arr;
    }

   
};



ostream& operator << (ostream& stream, CStr& other)
{
    int l = other.getLenght();

    for (int i = 0; i < l; i++)
        stream << other.S[i];

    return stream;
}

ostream& operator << (ostream& stream, CStrArray& other)
{
    int l = other.lenght;

    stream << "[";
    for (int i = 0; i < l; i++)
    {
        if (i == (l - 1))
        {
            stream << other.S_Arr[i];
            break;
        }

        stream << other.S_Arr[i] << ", ";
    }
        
    stream << "]";

    return stream;
}


void test1()
{
    cout << "Демонстрация работы перегрузок конструктора" << endl << endl;

    //Перегрузки конструкторов
    CStr A;
    cout << "A(по умолчанию): \t\t" << A << " " << A.getLenght() << endl;

    CStr B((char*)"zxc_bebra");
    cout << "B(с параметром строка): \t" << B << " " << B.getLenght() << endl;

    CStr C(12);
    cout << "C(с параметром длина строки): \t" << C << " " << C.getLenght() << endl;

    CStr D(A);
    cout << "D(копия А): \t\t\t" << D << " " << D.getLenght() << endl;

    //Работа операторов
    CStr F(5);
    F = B;
    cout << "F(F = B): \t\t\t" << F << " " << F.getLenght() << endl;

    CStr G;
    G = (char*)"amogus";
    cout << "G(присваивание строки): \t" << G << " " << G.getLenght() << endl;

    cout << "Сравнение(>): \t\t\t" << (A > B) << endl;
    cout << "Сравнение(==): \t\t\t" << (A == D) << endl;

    cout << "Friend-функция(для B): \t\t" << B << endl;



    cout << endl;
}


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");

    //test1();
    
    
    int l;
    cout << "Введите длину массива: ";
    cin >> l;
    cout << endl;

    CStrArray a(l);
    cout << "Исходный массив:\t\t " << a << endl;

    a.sort_by_lenght();
    cout <<"Сортировка(по длине):\t\t "<< a << endl;

    a.sort_by_content();
    cout << "Сортировка(по содержанию):\t " << a << endl;
    cout << "Проверка сортировки:\t\t " << a.check_sort() << endl;

    cout << endl << "Введите слово для поиска: ";
    char* toFind = new char[20];
    cin >> toFind;
    cout << "Результат поиска(индекс): " << a.bin_search(toFind) << endl;





    cout << endl;
	return 0;
}


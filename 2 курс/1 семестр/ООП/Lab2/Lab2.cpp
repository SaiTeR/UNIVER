////////////
//  CODE  //
//   BY   //    ООП Лаба 2  ПОСЧИТАТЬ СУММУ ВВЕДЕННЫХ ЧИСЕЛ (С КЛАВИАТУРЫ, С ФАЙЛА, ИЗ МАСССИВА)
// SAITER //      
////////////

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;



class SBase
{
public:
    virtual int Get() = 0;

};


class SKbrd : public SBase
{
public:
    int Get() override
    {
        int num;
        cin >> num;

        if (num == -1)
            return -1;

        else
            return num;
    };
};


class SFile : public SBase
{
private:
    fstream F;

public:
    int Get() override
    {
        if (F.eof()) 
        {
            return -1;
        }

        int num;
        F >> num;

        if (num >= 0) 
        {
            return num;
        }

        return  -1;
    }

    void Reset()
    {
        F.clear();
        F.seekg(0);
    }

    SFile(string file_name) 
    {
        F.open(file_name);
    }

    ~SFile() 
    {
        F.close();
    }
};


class SQueue :public SBase
{
private:
    int* que, lenght, current = 0;

public:
    SQueue(int len)
    {
        srand(time(0));
        lenght = len;
        que = new int[lenght];

        for (int i = 0; i < lenght; i++)
            que[i] = rand() % 100;

    };


    int Get() override
    {
        if (lenght <= 0 || current >= lenght) 
        {
            return -1;
        }

        int number = que[current];
        current++;


        return number;
    }


    void Rewind()
    {
        current = 0;
    }

    ~SQueue()
    {
        delete[] que;
    }
};


class Freq
{
private:
    map<int, int> counts; //ключ - считанное число, значение - количество повторений
    int _sum = 0;

public:
    virtual void Calc(SBase* pobj)
    {
        _sum = 0;
        counts.clear();

        while (true)
        {
            int num = pobj->Get();
            if (num < 0)
                break;

            _sum += num;

            /*if (counts.find(num) == counts.end())
            {
                counts[num] = 1;
            }

            else
            {
                int prVl = counts[num];
                counts[num] = prVl + 1;
            }*/

            counts[num]++;
        }

    }

    friend ostream& operator << (ostream& stream, Freq& obj)
    {
        stream << "Сумма введеных чисел = " << obj._sum << endl;
        stream << "Число-счетчик: " << endl;

        for (pair<int, int> item : obj.counts) 
        {
            stream << "Число: " << item.first << " Счетчик: " << item.second << endl;
        }


        return stream;
    }

    virtual ~Freq()
    {
        counts.clear();
    }
  
};


class Diap : public Freq
{
private:
    int min, max, cnt;

public:

    void Calc(SBase* pobj) override
    {
        min = INT_MAX;
        max = -1;
        cnt = 0;

        while (true)
        {
            int num = pobj->Get();
            if (num < 0)
            {
                break;
            }

            if (num < min)
            {
                min = num;
            }

            if (num > max) 
            {
                max = num;
            }

            cnt++;
        }
    };


    friend ostream& operator << (ostream& stream, Diap& obj)
    {
        stream << "Диапазон:\nMin = " << (obj.min == INT_MAX ? -1 : obj.min) << "\nMax =" << obj.max << "\nCnt = " << obj.cnt << endl;
        return stream;
    }
};








int main()
{
    setlocale(LC_ALL, "RUS");
    
    Freq freq;
    Diap diap;
    
    //SKbrd
    SKbrd KBRD;

    cout << "Введите числа через пробел (-1 для конца ввода):\n";
    freq.Calc(&KBRD);
    cout << freq << endl;

    cout << "Введите числа через пробел (-1 для конца ввода):\n";
    diap.Calc(&KBRD);
    cout << diap << endl;

    
    //FILE
    SFile FILE("test1.txt");

    freq.Calc(&FILE);
    cout << freq << endl;

    FILE.Reset();

    diap.Calc(&FILE);
    cout << diap << endl;

    
    //КУЕУЕ
    SQueue QUEUE(10);
    freq.Calc(&QUEUE);
    cout << freq << endl;

    QUEUE.Rewind();

    diap.Calc(&QUEUE);
    cout << diap << endl;


}


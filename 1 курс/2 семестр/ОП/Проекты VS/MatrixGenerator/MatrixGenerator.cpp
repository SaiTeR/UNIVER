#include <iostream>
#include <random>
#include <fstream>

using namespace std;


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-50, 50);

    setlocale(LC_ALL, "Russian");

    ofstream file("matrix.txt");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            file << dist(gen) << " ";
        }
        file << endl;
    }

}



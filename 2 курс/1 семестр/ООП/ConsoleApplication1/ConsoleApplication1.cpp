#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int i, j, ** mas, norm_m = 0, temp, m;
    printf("razmernost matrici m= ");
    scanf_s("%d", &m);
    mas = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
        mas[i] = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            printf("[%d][%d]=", i, j);
            cin >> mas[i][j];
        }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d\t", mas[i][j]);
        printf("\n\n");
    }
    for (i = 0; i < m; i++)
    {
        temp = 0;
        for (j = 0; j < m; j++)
            temp += (int)fabs(mas[j][i]);
        if (temp > norm_m)
            norm_m = temp;
    }
    printf("\n Norma matrici: %d\n", norm_m);
    return 0;

}
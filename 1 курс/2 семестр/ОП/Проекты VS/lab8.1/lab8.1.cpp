#include <iostream>
#include <ctime>
using namespace std;

struct list
{
    int value;
    list* next;
};

int main()
{
    
    list *head; //голова дай денег
    list *pointer = new list;
    srand(time(0));

    head = pointer;
    pointer->value = rand()%18 + (0);
    pointer->next = NULL;

    for (int i = 0; i < 9; i++)
    {
        pointer->next = new list;
        pointer = pointer->next;
        pointer->value = rand() % 18;
        pointer->next = NULL;
    }

    pointer = head;
    while (pointer != NULL)
    {
        cout << pointer->value << endl;
        pointer = pointer->next;
    }
    

    return 0;

}



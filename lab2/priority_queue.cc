#include <iostream>
#define MAX 5

using namespace std;

class p_queue
{

    int pqueue[MAX];
    static int front, rear;

public:
    void enqueue(int val)
    {
        if (rear == MAX)
        {
            throw "Queue overflow\n";
        }
        pqueue[++rear] = val;
    }

    int dequeue()
    {
        if (rear == front)
        {
            throw "Queue underflow.\n";
        }
        // ascending priority queue
        int small = pqueue[front], ind = 0;
        for (int i = front + 1; i <= rear; i++)
        {
            if (pqueue[i] < small)
            {
                ind = i;
                small = pqueue[i];
            }
        }
        // moving from right to the empty space
        for (int i = ind; i < rear; i++)
        {
            pqueue[i] = pqueue[i + 1];
        }
        rear--;
        return small;
    }

    void display()
    {
        if (rear == front)
        {
            throw "Empty queue.\n";
        }

        for (int i = front + 1; i <= rear; i++)
        {
            cout << pqueue[i] << "\t";
        }
    }
};

int p_queue::rear = -1;
int p_queue::front = -1;

void menu(p_queue &q)
{

    char choice;
    cout << "\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n";
    cin >> choice;

    // cin >> ws; // discard input buffer

    switch (choice)
    {
    case '1':
        int val;
        try
        {
            cout << "Enter a value: ";
            cin >> val;
            q.enqueue(val);
            cout << "Sucessfully pushed.\n";
        }
        catch (const char *msg)
        {
            cout << msg;
        }
        menu(q);
    case '2':

        try
        {
            cout << q.dequeue();
            cout << "\nSucessfully popped.\n";
        }
        catch (const char *msg)
        {
            cout << msg;
        }
        menu(q);

    case '3':

        try
        {
            q.display();
            cout << "\n";
        }
        catch (char const *msg)
        {
            cout << msg;
        }
        menu(q);

    case '4':
        exit(0);

    default:
        menu(q);
    }
}

int main()
{
    p_queue q;
    menu(q);
    return 0;
}
#include <iostream>
#define MAX 5

using namespace std;

class cqueue
{
    int cqueue[MAX];
    static int front, rear;

public:
    void enqueue(int val)
    {
        if (front == (rear + 1) % MAX)
        {
            throw "overflow";
        }
        rear = (rear + 1) % MAX;
        cqueue[rear] = val;
    }

    int dequeue()
    {
        if (front == rear)
        {
            throw "Empty";
        }
        front = (front + 1) % MAX;
        return cqueue[front];
    }

    void display()
    {
        if (front == rear)
        {
            throw "Empty";
        }
        for (int i = (front + 1) % MAX; i != (rear + 1) % MAX; i = (i + 1) % MAX)
        {
            cout << cqueue[i] << "\t";
        }
    }
};

int cqueue::front = MAX - 1;
int cqueue::rear = MAX - 1;

void menu(cqueue &q)
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
    cqueue c;
    menu(c);
    return 0;
}
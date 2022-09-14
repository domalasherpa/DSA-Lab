#include <iostream>
#define MAXSIZE 5

using namespace std;

class queue
{
    int q[MAXSIZE];
    static int front;
    static int rear;

public:
    void enqueue(int val)
    {
        if (rear == MAXSIZE)
        {
            throw "Queue Overflow\n";
        }
        q[++rear] = val;
    }

    int dequeue()
    {
        if (rear == front)
        {
            throw "Queue Underflow\n";
        }
        return q[++front];
    }

    void display()
    {
        if (rear == front)
        {
            throw "Empty queue\n";
        }
        for (int i = front + 1; i <= rear; i++)
        {
            cout << q[i] << "\t";
        }
    }
};

int queue::front = -1;
int queue::rear = -1;

void menu(queue &q)
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
    queue q;
    menu(q);
}
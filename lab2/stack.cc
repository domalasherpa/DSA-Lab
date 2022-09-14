#include <iostream>
#define MAXSIZE 5

using namespace std;

class stack
{
    int st[MAXSIZE];
    static int top;

public:
    void push(int val)
    {
        if (top == MAXSIZE)
        {
            throw "Stack Overflow\n";
        }
        st[++top] = val;
    }

    int pop()
    {
        if (top < 0)
        {
            throw "Stack Underflow\n";
        }
        return st[top--];
    }

    void display()
    {
        if (top < 0)
        {
            throw "Empty stack\n";
        }
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << "\t";
        }
    }
};

int stack::top = -1;

void menu(stack &st)
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
            st.push(val);
            cout << "Sucessfully pushed.\n";
        }
        catch (const char *msg)
        {
            cout << msg;
        }
        menu(st);
    case '2':

        try
        {
            cout << st.pop();
            cout << "\nSucessfully popped.\n";
        }
        catch (const char *msg)
        {
            cout << msg;
        }
        menu(st);

    case '3':

        try
        {
            st.display();
            cout << "\n";
        }
        catch (char const *msg)
        {
            cout << msg;
        }
        menu(st);

    case '4':
        exit(0);

    default:
        menu(st);
    }
}

int main()
{
    stack st;
    menu(st);
}
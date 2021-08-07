#include <iostream>
using namespace std;

int n = 100, top = -1;
int a[100];

bool full()
{

    if (top == n - 1)
        return true;

    else
        return false;
}

bool empty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(int x)
{
    if (!full())
    {
        a[top + 1] = x;
        top++;
    }
    else
        cout << "stack Overflow\n";
}

int pop()
{
    if (!empty())
    {

        int x = a[top];
        free(&top);
        top--;
        return x;
    }
    else
        cout << " stack underflow\n";
    return -1;
}

int peek()
{
    if (!empty())
        return a[top];
    return -1;
}

int main(int argc, char const *argv[])
{

    cout << "Enter size of stack: ";
    cin >> n;
    push(3);
    push(3);
    push(3);
    push(3);
    push(3);
    push(3);
    push(3);
    peek();
    cout << pop() << endl
         << pop();
    // cout<<endl<<size();

    return 0;
}

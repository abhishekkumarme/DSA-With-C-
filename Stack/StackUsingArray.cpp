#include <bits/stdc++.h>
using namespace std;
int top = -1;

void push(int arr[], int n)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow! Cannot push" << endl;
        return;
    }
    else
    {
        int v;
        cout << "Enter a value to push in satck" << endl;
        cin >> v;
        arr[++top] = v;
        return;
    }
}

void pop(int arr[], int n)
{
    if (top == -1)
    {
        cout << "Stack Underflow! Cannot pop" << endl;
        return;
    }
    top--;
}
void topElement(int arr[])
{
    if (top < 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Top element of stack is: " << arr[top] << endl;
}

bool isempty()
{
    return (top == -1);
}

bool isfull(int n)
{
    return (top == n - 1);
}

void display(int arr[])
{
    cout << "Elements of the stacks are: " << endl;
    for (int i = top; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void search(int arr[])
{
    if (top < 0)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Enter a value to search: ";
    int a;
    cin >> a;

    for (int i = top; i >= 0; --i)
    {
        if (arr[i] == a)
        {
            cout << "Value " << a << " is found at index " << i << " (from bottom) or "
                 << (top - i + 1) << " (from top)." << endl;
            return;
        }
    }

    cout << "Value " << a << " is not found in the stack." << endl; // ✅ Prints only once
}

int main()
{
    int n;

    cout << "Enter the size of stack" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " element in Stack" << endl;
        cin >> arr[i];
        top++;
    }
    display(arr);
    int option;

    while (true)
    {
        cout << "Enter choice to perform action" << endl;
        cout << "1 for push operation" << endl;
        cout << "2 for pop operation" << endl;
        cout << "3 for top operation" << endl;
        cout << "4 for search operation" << endl;
        cout << "5 for isFull operation" << endl;
        cout << "6 for isEmpty operation" << endl;
        cout << "0 for exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            push(arr, n);
            display(arr);
            break;
        case 2:
            pop(arr, n);
            display(arr);
            break;
        case 3:
            topElement(arr);
            display(arr);

            break;
        case 4:
            search(arr);
            display(arr);
            break;
        case 5:
            cout << (isfull(n) ? "Stack is full" : " Stack is not empty") << endl;

            break;
        case 6:
            cout << (isempty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 0:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Wrong input! please enter a right choice" << endl;
            break;
        }
    }
}

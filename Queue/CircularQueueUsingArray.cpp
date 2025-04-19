#include <bits/stdc++.h>
using namespace std;

int front = -1, rear = -1;

bool isFull(int size)
{
    return (front == (rear + 1) % size);
}

bool isEmpty()
{
    return (front == -1);
}

void enqueue(int arr[], int size)
{
    if (isFull(size))
    {
        cout << "Queue is full (Overflow)" << endl;
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    int value;
    cout << "Enter data in queue: ";
    cin >> value;
    arr[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue(int arr[], int size)
{
    if (isEmpty())
    {
        cout << "Queue is empty (Underflow)" << endl;
        return;
    }
    cout << "Deleted: " << arr[front] << endl;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void Front(int arr[])
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element is: " << arr[front] << endl;
}

void Rear(int arr[])
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Rear element is: " << arr[rear] << endl;
}

void display(int arr[], int size)
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    cout << endl;
}

void Search(int arr[], int size)
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    bool res = false;
    int i = front;
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    while (true)
    {
        if (arr[i] == value)
        {
            cout << "Data " << value << " at index " << front << " from front" << endl;
            res = true;
            break;
        }
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    if (res == false)
    {
        cout << "Data not found in Queue." << endl;
    }
}

int main()
{
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;
    int arr[size];
    int option;

    while (true)
    {
        cout << "\nEnter choice to perform action" << endl;
        cout << "1 for enqueue operation" << endl;
        cout << "2 for dequeue operation" << endl;
        cout << "3 for Front operation" << endl;
        cout << "4 for Rear operation" << endl;
        cout << "5 for isFull operation" << endl;
        cout << "6 for isEmpty operation" << endl;
        cout << "7 for Search operation" << endl;
        cout << "0 for exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            enqueue(arr, size);
            display(arr, size);
            break;
        case 2:
            dequeue(arr, size);
            display(arr, size);
            break;
        case 3:
            Front(arr);
            break;
        case 4:
            Rear(arr);
            break;
        case 5:
            cout << (isFull(size) ? "Queue is full" : "Queue is not full") << endl;
            break;
        case 6:
            cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 7:
            Search(arr, size);
            break;
        case 0:
            display(arr, size); 
            cout << endl<<"Thank You!" << endl;
            return 0;
        default:
            cout << "Wrong input! Please enter a valid choice." << endl;
            break;
        }
    }
}
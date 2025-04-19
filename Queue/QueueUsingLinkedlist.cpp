#include <bits/stdc++.h>
using namespace std;

int front = -1, rear = -1;

struct node
{
    int data;
    node *next;
} *head = NULL, *last = NULL, *temp;

void enqueue()
{
    if (front == -1)
    {
        front = 0;
    }
    temp = new node();
    cout << "Enter data in queue: ";
    cin >> temp->data;
    if (head == NULL)
    {
        head = last = temp;
        head->next = NULL;
    }
    else
    {
        last->next = temp;
        last = temp;
        last->next = NULL;
    }
    rear++;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow! Cannot remove." << endl;
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
    cout << "Removed front element." << endl;
    front++;
}

void Front()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front: " << head->data << endl;
}

void Rear()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Rear: " << last->data << endl;
}

bool isEmpty()
{
    return (front == -1 || front > rear);
}

void Print()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Elements of the Queue: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Search()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    int n;
    cout << "Enter data to search: ";
    cin >> n;
    temp = head;
    int index = front;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            cout << "Data " << n << " found at index " << index - front << " from front." << endl;
            found = true;
            break;
        }
        temp = temp->next;
        index++;
    }
    if (!found)
    {
        cout << "Data not found in Queue." << endl;
    }
}

int main()
{
    int option;

    while (true)
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Rear Element\n";
        cout << "5. Check if Empty\n";
        cout << "6. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            enqueue();
            Print();
            break;
        case 2:
            dequeue();
            Print();
            break;
        case 3:
            Front();
            break;
        case 4:
            Rear();
            break;
        case 5:
            cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 6:
            Search();
            break;
        case 0:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Wrong input! Please enter a valid choice." << endl;
            break;
        }
    }
}

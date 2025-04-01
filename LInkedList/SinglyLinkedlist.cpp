#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL, *temp, *last;

int count = 0;

// Creating a Linked List with 3 nodes.
void create()
{
    cout << "Creating a linkedlist with  3 nodes" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        temp = new node();
        cout << "Enter data in the node" << endl;
        cin >> temp->data;
        if (head == NULL)
        {
            head = last = temp;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
        count++;
    }
}

// Inserting a new node in the Linked List at the Given position.
void insert()
{
    cout << "Enter position to insert a new node in Linked List" << endl;
    int n;
    cin >> n;
    if (n > count + 1)
    {
        cout << "Given position is out of bound" << endl;
    }
    else
    {
        // Inserting node at 1st position.
        if (n == 1)
        {
            temp = new node();
            cout << "Enter data to insert a new node in the Linked List" << endl;
            cin >> temp->data;
            temp->next = head;
            head = temp;
            count++;

            // Insertin node at last.
        }
        else if (n == count + 1)
        {
            temp = new node();
            cout << "Enter data to insert a new node in the Linked List" << endl;
            cin >> temp->data;
            last->next = temp;
            last = temp;
            count++;
            // Inserting node at any other given position.
        }
        else
        {
            temp = head;
            node *newNode = new node();
            int i = 0;
            while (i < n - 2)
            {
                temp = temp->next;
                i++;
            }
            cout << "Enter data to insert a new node in the Linked List" << endl;
            cin >> newNode->data;
            newNode->next = temp->next;
            temp->next = newNode;

            count++;
        }
    }
}

// Upadating a node in the Linked List.
void update()
{
    cout << "Enter position to update a node in the linkedlist:" << endl;
    int n;
    cin >> n;
    if (n > count)
    {
        cout << "Given position is out of bound" << endl;
    }
    else
    {
        // Update if node is at 1st position.
        if (n == 1)
        {
            cout << "Enter data to update the node" << endl;
            cin >> head->data;
            cout << "Node is updated" << endl;

            // Update if node is at last position.
        }
        else if (n == count)
        {
            cout << "Enter data to update the node" << endl;
            cin >> last->data;
            cout << "Node is updated" << endl;

            // Update node at any other position.
        }
        else
        {
            temp = head;
            int i = 0;
            node *newnode;
            while (i < n - 2)
            {
                temp = temp->next;
                i++;
            }
            newnode = temp->next;
            cout << "Enter data to update the node" << endl;
            cin >> newnode->data;
            cout << "Node is updated" << endl;
        }
    }
}

// Deleting node from the Linked List.
void Delete()
{
    cout << "Enter position to delete a node from Linked List" << endl;
    int n;
    cin >> n;
    if (n > count)
    {
        cout << "Given position is out of bound" << endl;
    }
    else
    {
        // Deleting node from 1st position.
        if (n == 1)
        {
            temp = head->next;
            delete head;
            head = temp;

            // Deleting node at last position.
        }
        else if (n == count)
        {
            temp = head;
            for (int i = 0; i < count - 1; i++)
            {
                temp = temp->next;
            }
            delete last;
            last = temp;
            last->next = NULL;

            // Deleting node from any other position.
        }
        else
        {
            temp = head;
            node *newnode;
            int i = 0;
            while (i < n - 2)
            {
                temp = temp->next;
                i++;
            }
            newnode = temp->next;
            temp->next = newnode->next;
            delete newnode;
        }
        cout << "Node deleted successfuly." << endl;
        count--;
    }
}

// Reversing the Linked List.
void reverse()
{
    // If empty or single node, do nothing
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *prev = NULL, *next2 = NULL;
    temp = head;
    last = head;

    while (temp != NULL)
    {
        next2 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next2;
    }

    head = prev;
}

// Sorting the Linked List.
void sort()
{
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            swap(temp->data, temp->next->data);
        }
        temp = temp->next;
    }
}

// Printing the data of the node
void print()
{
    temp = head;
    cout << endl;
    cout << "Size of the node is: " << count << endl;
    cout << "Printing the element of the Linked List:-" << endl
         << endl;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl
         << endl;
}

// Searching data in Linked List.
void search()
{
    temp = head;
    cout << "Enter data to search" << endl;
    int n;
    cin >> n;
    int i = 0;
    int r;
    while (temp->next != NULL)
    {
        if (temp->data == n)
        {
            cout << "Data " << n << " is at " << i + 1 << " position" << endl;
            r = n;
        }
        temp = temp->next;
        i++;
    }
    if (r != n)
    {
        cout << "Data not found" << endl;
    }
}

int main()
{

    create();
    print();
    int option;
    cout << "Select an option to performs operations on Linked List" << endl;

    while (true)
    {
        cout << "Enter 1 to insert new node in Linked List" << endl;
        cout << "Enter 2 to update a node in Linked List" << endl;
        cout << "Enter 3 to delete a node in Linked List" << endl;
        cout << "Enter 4 to reverse the Linked List" << endl;
        cout << "Enter 5 to sort the Linked List" << endl;
        cout << "Enter 6 to search an element in the Linked List" << endl;
        cout << "Enter 0 exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            insert();
            print();
            break;
        case 2:
            update();
            print();
            break;
        case 3:
            Delete();
            print();
            break;
        case 4:
            reverse();
            print();
            break;
        case 5:
            sort();
            print();
            break;
        case 6:
            search();
            break;
        case 0:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Invalid Option. Please Enter a right option." << endl;
            break;
        }
        cout << endl;
    }
}
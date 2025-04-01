#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *head = NULL, *temp, *last;

int count = 0;

// Creating a Circular Linked List with 3 nodes.
void create()
{
    cout << "Creating a Circular Linked List with 3 nodes" << endl;
    for (int i = 0; i < 3; i++)
    {
        temp = new node();
        cout << "Enter data in the node: ";
        cin >> temp->data;
        temp->next = head; // Default points to head

        if (head == NULL)
        {
            head = last = temp;
            last->next = head; // Circular link
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = head; // Maintain circular link
        }
        count++;
    }
}

// Insert a node at a given position
void insert()
{
    cout << "Enter position to insert a new node: ";
    int n;
    cin >> n;

    if (n < 1 || n > count + 1)
    {
        cout << "Given position is out of bound" << endl;
        return;
    }

    temp = new node();
    cout << "Enter data: ";
    cin >> temp->data;

    if (n == 1) // Insert at beginning
    {
        temp->next = head;
        head = temp;
        last->next = head; // Update circular link
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < n - 1; i++)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;

        if (n == count + 1) // If inserted at last, update last
            last = temp;
    }

    last->next = head; // Ensure circular link
    count++;
}

// Delete a node at a given position
void Delete()
{
    cout << "Enter position to delete a node: ";
    int n;
    cin >> n;

    if (n < 1 || n > count)
    {
        cout << "Given position is out of bound" << endl;
        return;
    }

    node *delNode;

    if (n == 1) // Delete first node
    {
        delNode = head;
        head = head->next;
        last->next = head;
        delete delNode;
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < n - 1; i++)
            curr = curr->next;

        delNode = curr->next;
        curr->next = delNode->next;

        if (n == count) // If last node deleted, update last
            last = curr;

        delete delNode;
    }

    last->next = head; // Maintain circular structure
    count--;
    cout << "Node deleted successfully." << endl;
}

// Reverse the Circular Linked List
void reverse()
{
    if (head == NULL || head->next == head) // Empty or single node
        return;

    node *prev = NULL, *curr = head, *nextNode;
    last = head; // Last becomes the old head

    do
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    head->next = prev; // Fix the last node's link
    head = prev;       // Update head
    last->next = head; // Ensure circular link
}

// Sort the Circular Linked List (Bubble Sort)
void sort()
{
    if (head == NULL || head->next == head) // Empty or single node
        return;

    bool swapped;
    node *ptr1;
    node *lptr = NULL; // Marks sorted end

    do
    {
        swapped = false;
        ptr1 = head;

        do
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != head);

        lptr = ptr1; // Update last sorted node
    } while (swapped);
}

// Print the Circular Linked List
void print()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    temp = head;
    cout << "\nSize of the list: " << count << endl;
    cout << "Circular Linked List Elements: ";

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

// Search for a value in Circular Linked List
void search()
{
    cout << "Enter data to search: ";
    int n;
    cin >> n;

    temp = head;
    int pos = 1;
    bool found = false;

    do
    {
        if (temp->data == n)
        {
            cout << "Data " << n << " found at position " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        cout << "Data not found" << endl;
}

int main()
{
    create();
    print();
    int option;

    while (true)
    {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Reverse the list" << endl;
        cout << "4. Sort the list" << endl;
        cout << "5. Search an element" << endl;
        cout << "6. Print the list" << endl;
        cout << "0. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            insert();
            print();
            break;
        case 2:
            Delete();
            print();
            break;
        case 3:
            reverse();
            print();
            break;
        case 4:
            sort();
            print();
            break;
        case 5:
            search();
            break;
        case 6:
            print();
            break;
        case 0:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Invalid Option! Please enter a valid option." << endl;
        }
    }
}

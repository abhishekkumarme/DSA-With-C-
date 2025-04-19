#include<bits/stdc++.h>
using namespace std;

int front = -1, rear = -1;

bool isFull(int size) {
    return (front == (rear + 1) % size);
}

bool isEmpty() {
    return (front == -1);
}

void enqueueFront(int arr[], int size) {
    if (isFull(size)) {
        cout << "Queue is full (Overflow)" << endl;
        return;
    }
    int value;
    cout << "Enter data to insert at front: ";
    cin >> value;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + size) % size;
    }
    arr[front] = value;
    cout << "Inserted at front: " << value << endl;
}

void enqueueRear(int arr[], int size) {
    if (isFull(size)) {
        cout << "Queue is full (Overflow)" << endl;
        return;
    }
    int value;
    cout << "Enter data to insert at rear: ";
    cin >> value;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    arr[rear] = value;
    cout << "Inserted at rear: " << value << endl;
}

void dequeueFront(int arr[], int size) {
    if (isEmpty()) {
        cout << "Queue is empty (Underflow)" << endl;
        return;
    }
    cout << "Deleted from front: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void dequeueRear(int arr[], int size) {
    if (isEmpty()) {
        cout << "Queue is empty (Underflow)" << endl;
        return;
    }
    cout << "Deleted from rear: " << arr[rear] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + size) % size;
    }
}

void Front(int arr[]) {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element is: " << arr[front] << endl;
}

void Rear(int arr[]) {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Rear element is: " << arr[rear] << endl;
}

void display(int arr[], int size) {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

void Search(int arr[], int size) {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    int i = front;
    bool res = false;
    while (true) {
        if (arr[i] == value) {
            cout << "Data " << value << " found in the queue." << endl;
            res = true;
            break;
        }
        if (i == rear) break;
        i = (i + 1) % size;
    }
    if (!res && arr[rear] == value) {
        cout << "Data " << value << " found in the queue." << endl;
        res = true;
    }
    if (!res) {
        cout << "Data not found in Queue." << endl;
    }
}

int main() {
    int size;
    cout << "Enter size of Dequeue: ";
    cin >> size;
    int arr[size];
    int option;

    while (true) {
        cout << "\nEnter choice to perform action" << endl;
        cout << "1 for enqueue at front" << endl;
        cout << "2 for enqueue at rear" << endl;
        cout << "3 for dequeue from front" << endl;
        cout << "4 for dequeue from rear" << endl;
        cout << "5 for Front operation" << endl;
        cout << "6 for Rear operation" << endl;
        cout << "7 for isFull operation" << endl;
        cout << "8 for isEmpty operation" << endl;
        cout << "9 for Search operation" << endl;
        cout << "0 for exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                enqueueFront(arr, size);
                display(arr, size);
                break;
            case 2:
                enqueueRear(arr, size);
                display(arr, size);
                break;
            case 3:
                dequeueFront(arr, size);
                display(arr, size);
                break;
            case 4:
                dequeueRear(arr, size);
                display(arr, size);
                break;
            case 5:
                Front(arr);
                break;
            case 6:
                Rear(arr);
                break;
            case 7:
                cout << (isFull(size) ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 8:
                cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 9:
                Search(arr, size);
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

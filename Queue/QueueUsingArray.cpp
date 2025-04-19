#include <bits/stdc++.h>
using namespace std;

int front = -1, rear = -1;

void enqueue(int arr[], int n){
    if(rear >= n - 1){
        cout << "Queue Overflow! Cannot insert" << endl;
        return;
    } else {
        if(front == -1){   
            front = 0;
        }
        rear++;
        cout << "Enter data into queue: ";
        int d;
        cin >> d;
        arr[rear] = d;
    }
}

void dequeue(int arr[]){
    if(front == -1 || front > rear){   
        cout << "Queue Underflow! Cannot delete" << endl;
        return;
    }
    cout << "Removed: " << arr[front] << endl;
    front++;
}

void Front(int arr[]){
    if(front == -1 || front > rear){   
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Front Element: " << arr[front] << endl;
}

void Rear(int arr[]){
    if(rear == -1 || front > rear){   
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Rear Element: " << arr[rear] << endl;
}

bool isFull(int n){
    return (rear >= n - 1);
}

bool isEmpty(){
    return (front == -1 || front > rear);
}

void Print(int arr[]){
    if(front == -1 || front > rear){   
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Elements of the Queue: ";
    for(int i = front; i <= rear; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void search(int arr[], int n){
    if(front == -1 || front > rear){   
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Elements of the Queue: ";
    cout<<"Enter data to search: ";
    int d;
    cin>>d;
    bool res = false;
    for(int i = front; i <= rear; i++){
        if(arr[i] == d){
        cout <<"Element "<<d<<" found at "<<i<< " index fron Front"<<endl;
        res = true;
        }
    }
    if(res = false){
        cout<<"Element not found"<<endl;
    }
}

int main(){
    int n;
    cout << "Enter size of Queue: ";
    cin >> n;
    int arr[n];
    int option;
    
    while(true){
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
        
        switch(option){
            case 1:
                enqueue(arr, n);
                Print(arr);
                break;
            case 2:
                dequeue(arr);
                Print(arr);
                break;
            case 3:
                Front(arr);
                break;
            case 4:
                Rear(arr);
                break;
            case 5:
                cout << (isFull(n) ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 6:
                cout << (isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 7:
                search(arr,n);
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

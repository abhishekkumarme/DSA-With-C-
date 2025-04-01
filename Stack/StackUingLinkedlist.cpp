#include<bits/stdc++.h>
using namespace std;



struct node{
    int data;
    node *next;
} *bottom = NULL, *temp,*top=NULL;   

int ind = -1;

void push(int size){
   if(size<=ind+1){
    cout<<"node OverFlow! Cannot Push anymore"<<endl;
    return;
   }
   temp = new node();
   cout<<"Enter data into node"<<endl;
   cin>>temp->data;
    if(top==NULL){
      bottom = top = temp;
    }else{
       temp->next = top;
       top = temp;
    }
    ind++;
}

void pop(){
     if(ind<0){
        cout<<"node UnderFlow! cannot pop anymore"<<endl;
        return;
     }
     temp = top;
     top = temp->next;
     delete temp;
     ind--;
     cout<<"Succesfully poped"<<endl;
}

void peak(){
   if(top==NULL){
    cout<<"Stak is empty"<<endl;
    return;
   }
   cout<<"Element at top is: "<<top->data<<endl;
}

bool isempty(){
    return top == NULL;
}

bool isFull(int size){
    return size<=ind+1;
}

void search(){
    if(top==NULL){
        cout<<"Stak is empty"<<endl;
        return;
       }
   int n;
   cout<<"Enter data to find"<<endl;
   cin>>n;
   int c =0;
   bool r = false;
   temp = top;
   while(true){
     if(temp->data = n){
        cout<<"Data "<<n<<" is found at "<<c<<" index"<<endl;
        r = true;
        return ;
     }else{
        temp = temp->next;
     }
     c++;
   }
   if(!r){
    cout<<"Data is not found"<<endl;
   }
}

void print(){
    if(top==NULL){
        cout<<"Stak is empty"<<endl;
        return;
    }
    temp = top;
    cout<<"Elements of the Stack: ";
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<bottom->data<<endl;
}


int main(){
    int size;
    cout<<"Enter Size of the node:"<<endl;
    cin>>size;

    int option;



  while(true){
    cout<<"Enter choice to perform action"<<endl;
    cout<<"1 for push operation"<<endl;
    cout<<"2 for pop operation"<<endl;
    cout<<"3 for top operation"<<endl;
    cout<<"4 for search operation"<<endl;
    cout<<"5 for isFull operation"<<endl;
    cout<<"6 for isEmpty operation"<<endl;
    cout<<"7 for print operation"<<endl;
    cout<<"0 for exit"<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
        push(size);
        print();
        break;
    case 2:
        pop();
        print();
        break;    
    case 3:
        peak();
        break;
    case 4:
        search();
        break;
    case 5:
        cout<<(isFull(size) ? "Stack is full": " Stack is not Full")<<endl;
        break;
    case 6:
        cout<<(isempty() ? "Stack is empty" : "Stack is not empty")<<endl;
        break;
    case 7:
        print();
        break;
    case 0:
        cout<<"Thank You!"<<endl;
        return 0;
    default:
        cout<<"Wrong input! please enter a right choice"<<endl;
        break;
    }
  }

}
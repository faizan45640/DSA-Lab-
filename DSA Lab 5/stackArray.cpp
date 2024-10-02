
#include<iostream>
#include<stack>
using namespace std;


const int maxSize=10;
class Stack{
    int arr[maxSize];
    int top=-1;
    public:
    Stack(){
        top=-1;
    }
    void push(int v){
        if(!isFull()){
            arr[++top]=v;
            return;
        }

    }
    bool isFull(){
        return top==maxSize;

    }
    bool isEmpty(){
        return top==-1;
    }
    int pop(){
        return arr[top--];
    }
    int size(){
        return top+1;
    }

    

    void display(){
        if(!isEmpty()){
        for(int i=top ; i>-1 ; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }

    }

    
};


class Node{
    public:
    Node* next;
    int val;

    Node(int v){
        val=v;
        next=nullptr;
    }
};

class LinkedListStack{
    Node* head;
    public:
    LinkedListStack(){
        head=nullptr;
    }
    void push(int v){
        Node* newNode=new Node(v);
        newNode->next=head;
        head=newNode;
    }
    int pop(){
        if(!isEmpty()){
        Node* toDelete=head;
        int v=head->val;
        head=head->next;
        return v;}

    }
    bool isEmpty(){
        return head==nullptr;
    }
    int size(){
        Node* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};


bool isBalanced(string s){
    stack<char> st;
    
    for(auto i:s){
        if(i=='(' || i=='{' || i=='['){
            st.push(i);
        }
         else if(!st.empty() && (st.top()=='(' && i==')' ) || (st.top()=='{' && i=='}' ) || (st.top()=='[' && i==']' ) ){
            st.pop();
         }
         else{
            return false;
         }

    }
    return st.empty();


    
}



int main(){
    Stack st;
    st.push(1);
    st.push(4);
    st.display();
    st.pop();
    st.display();
    cout<<st.size();
    cout<<endl;

    LinkedListStack s;
    s.push(5);
    s.push(7);
    s.push(9);
    s.pop();
    s.display();

    string brackets1="{}{}{{})";
    string brackets2="{{{(})}}";
    string brackets3="{{()}}{}(()){}";
    

   bool a= isBalanced(brackets3);
   if(a)
   cout<<"Correct Sequence";
   else
   cout<<"Wrong sequence";
   




}
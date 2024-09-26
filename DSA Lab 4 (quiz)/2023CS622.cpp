#include<iostream>
using namespace std;



class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    Node(int v){
        next=nullptr;
        prev=nullptr;
        data=v;
    }


};

class LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList(){
        head=nullptr;
        tail=nullptr;
    };

    void insertAtStart(int v){
        if(!head && !tail){
            Node* newNode=new Node(v);
            head=newNode;
            tail=head;
            return;
        }

        Node* newNode=new Node(v);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
         
        
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

    void rotateByN(int n){


        if(!head) { cout<<"The list is empty"; return;}
        if(n<0) { cout<<"Enter a valid number"; return;}
        Node* temp=head;
        int count=1;
        while(temp->next){
            temp=temp->next;
            count++;
        }
        if(n==count)
        {
            //original linked list will return as it is back to that position
            return;
        }
        if(n%count==0){
            return;
        }
        if(n>count){
            n=n%count;
        }
        cout<<"value of n is "<<n<<endl;
      
        temp->next=head;
        temp=head;
        for(int i=1;i<count-n;i++){
           temp=temp->next;
        }
       head=temp->next;
        
       temp->next=nullptr;
       
        

    }


   
     
    

    int findNthFromLast(int num){
       if(!head) { cout<<"The list is empty"; return -1;}
       if(num<1) { cout<<"Enter a valid number"; return -1;}
       

        Node* temp=head;
        //reverse to make a new list
        Node* dummy=new Node(-1);
        Node*current=dummy;
        while(temp){
            Node* newNode=new Node(temp->data);
            current->next=newNode;
            current=current->next;
            temp=temp->next;
        }
      Node* head2=dummy->next;
      Node* temp2=head2;
      Node* next=nullptr;
      Node* prev=nullptr;
      while(temp2){
        next=temp2->next;
        temp2->next=prev;
        prev=temp2;
        temp2=next;
      }
        head2=prev;
        int count=1;
        //find nth element
       while(head2){
        if(count==num){
            return head2->data;
        }
        head2=head2->next;
        count++;
       }
       cout<<"out of range";
       return -1;
    }

    


};


int main(){
    LinkedList l;
    l.insertAtStart(11);
    l.insertAtStart(10);
    l.insertAtStart(9);
    l.insertAtStart(8);
    l.insertAtStart(7);
    l.insertAtStart(6);
    l.insertAtStart(5);
    l.insertAtStart(4);
    l.insertAtStart(3);
    l.insertAtStart(2);
    l.insertAtStart(1);
    
    l.display();
    l.rotateByN(6);
    
    
    l.display();
   
}
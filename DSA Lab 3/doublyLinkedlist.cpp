#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int value;
    Node(int v){
        value=v;
        next=nullptr;
        prev=nullptr;
    }


};

class DLinkedList{
    public:
    Node* head;
    Node* tail;
    public:
    DLinkedList(){
        head=nullptr;
        tail=nullptr;
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

    
    void insertAtStart(int v){
        if(!head){
            Node* newNode=new Node(v);
            head=newNode;
            tail=newNode;
            return;
        }
        Node* newNode=new Node(v);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;

    }
    void reverseDisplay(){
        if(!tail){
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            while(temp->prev){
            cout<<temp->value<<" ";
            temp=temp->prev;
        }

        }
        Node* temp=tail;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->prev;
        }
        cout<<endl;

    }


    int totalNodes(){
        int count=0;
        Node* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }

    void Traverse(){
        //front
        Node* temp=head;
        while(temp){
            temp=temp->next;

        }
         temp=tail;
        while(temp){
            temp=temp->prev;
        }
    }

    bool search(int v){
        Node* temp=head;
        while(temp){
            if(temp->value==v){
                return true;
            }
            temp=temp->next;

        }
      return false;
    }
    

    void Delete(int v){
        if(!search(v)){
            return;
        }
        Node* temp=head;
        if(!head->next){
            delete head;
            delete tail;
           head=nullptr;
           tail=nullptr;
           return;
        }
        if(head->value==v){
            head=head->next;
            head->prev=nullptr;
            return;
        }
        while(temp->next){
            if(temp->value==v){
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return;
            }
            temp=temp->next;
            
        }
        temp->prev->next=nullptr;
        delete temp;
    }

    void insertAfterNode(int k , int v){
        if(k<0){
            return;
        }
        if(k==0){
            insertAtStart(v);
            return;
        }
        if(k==totalNodes()-1){
            tail->next=new Node(v);
            tail->next->prev=tail;
            tail=tail->next;
            return;   }
        int cindex=0;
        Node* temp=head;
        while(temp && cindex<k){

            if(cindex==k){
                break;
            }
            temp=temp->next;
            cindex++;
        }
        if(cindex==k && temp){
            Node* newNode=new Node(v);
            newNode->prev=temp;
            newNode->next=temp->next;
            temp->next->prev=newNode;
            temp->next=newNode;
            return;
        }
        
       

    }

    void setTail(){
         if(!tail){
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            tail=temp;


    }

    

}};


Node* merge(DLinkedList L1 , DLinkedList L2){
    Node* temp1=L1.head;
    Node* temp2=L2.head;
    Node* dummy=new Node(-1);
    Node* current=dummy;


    while(temp1 && temp2){
        if(temp1->value<=temp2->value){
            Node* newNode=new Node(temp1->value);
            Node* previous=current;
            current->next=newNode;
            current=current->next;
            current->prev=previous;
            temp1=temp1->next;

        }
        else if(temp1->value>=temp2->value){
            Node* newNode=new Node(temp2->value);
             Node* previous=current;
            current->next=newNode;
            current=current->next;
            current->prev=previous;
            temp2=temp2->next;
        }
       


    }
    while(temp1){
    if(temp1){
        Node* newNode=new Node(temp1->value);
         Node* previous=current;
        current->next=newNode;
        current=current->next;
        current->prev=previous;
        temp1=temp1->next;
        
    }}
    while(temp2){
     if(temp2){
        Node* newNode=new Node(temp2->value);
        Node* previous=current;
        current->next=newNode;
        current=current->next;
        
         current->prev=previous;
         temp2=temp2->next;

    }
    }
    return dummy->next;


}


int main(){
    DLinkedList L;
   
   // L.insertAtStart(16);
  //  L.insertAtStart(4);
  //  L.insertAtStart(2);
     L.insertAtStart(1);

    
    L.display();
    
    
    

    DLinkedList L2;
     L2.insertAtStart(5);
    L2.insertAtStart(3);
    L2.insertAtStart(2);
    L2.insertAtStart(1);
    L2.insertAtStart(0);
 DLinkedList L3;
 L3.head=merge(L,L2);


 L3.display();
 L3.reverseDisplay();

}
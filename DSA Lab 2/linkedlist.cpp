#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node* next;

    Node(int v){
        value=v;
        next=nullptr;


    }
};


class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=nullptr;
    }

    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
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
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    //functions : 
    void insertAtBegin(int v){
        Node* newNode=new Node(v);
        Node* temp=head;
        head=newNode;
        newNode->next=temp;
    }
    void insertAtEnd(int v){
        if(head==NULL){
            insertAtBegin(v);
            return;
        }
        Node* temp=head;

        while(temp->next){
            temp=temp->next;
        }
        Node* newNode=new Node(v);
        temp->next=newNode;

    }

    void update(int index , int v){
        if(isEmpty()){
            return;
        }
        if(index==0){
            
                head->value=v;
                return;
            
            
        }
        int cindex=0;
        Node* temp=head;

        while(temp){
            if(cindex==index){
                temp->value=v;
                return;
            }
            temp=temp->next;
            cindex++;

        }
        cout<<"Out of range error"<<endl;
        return;

    }
    void insertAfter(int index , int v){
        if(index<0){
            cout<<"Index cannot be negative"<<endl;
            return;
        }
        if(index==0){
            if(isEmpty()){
                cout<<"The linked list is empty"<<endl;
            }
            Node* newNode=new Node(v);
            newNode->next=head->next;
            head->next=newNode;
            head=newNode;
            return;
        }
        Node* temp=head;
        Node* prev=head;
        int cindex=0;
        Node* newNode=new Node(v);

        while( cindex<index+1 && temp){
            
          
           prev=temp;
            temp=temp->next;
            cindex++;
            
            
            

        }
        if(cindex==index+1){
            prev->next=newNode;
            newNode->next=temp;
            return;


        }
        if(!temp && cindex==index+1){
            insertAtEnd(v);
            return;
        }
        cout<<"Out of range error"<<endl;

        

    }

    void Delete(int v){
        if(!search(v)){
            return;
        }
        if(head->value==v){
            if(head->next==NULL){
                delete head;
                head=NULL;
                return;
            }
            Node* toDelete=head;
            Node* temp=head->next;
            delete toDelete;
            head=temp;
            return;
        }
        Node* prev=head;
        Node* temp=head;
        while(temp){
            if(temp->value==v){
                Node* toDelete=temp;
                prev->next=temp->next;
                delete temp;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }


    void sortAsc(){
        if(!head || !head->next){
            
            return;
        }
        Node* temp=head;
       bool flag=true;
       while(flag){
        flag=false;
        temp=head;
        while(temp->next){
             if(temp->value > temp->next->value){
                swap(temp->value , temp->next->value);
                flag=true;
             }
            temp=temp->next;
        }
       }

    }

     void sortDesc(){
        if(!head || !head->next){
            return;
        }
        Node* temp=head;
       bool flag=true;
       while(flag){
        flag=false;
        temp=head;
        while(temp->next){
             if(temp->value<temp->next->value){
                swap(temp->value , temp->next->value);
                flag=true;
             }
            temp=temp->next;
        }
       }

    }


    



};





int main(){

    LinkedList l;
    l.insertAtBegin(4);
    l.insertAtBegin(9);
    l.insertAtBegin(8);
    l.insertAtEnd(11);
    
    l.update(4,3);
    l.insertAfter(0,99);
    l.display();
    l.insertAfter(3,71);
    l.Delete(71);

    l.sortDesc();

    

    
    l.display();


}
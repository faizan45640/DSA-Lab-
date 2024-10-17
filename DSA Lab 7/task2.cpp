#include<iostream>
#include<string>
using namespace std;

class Action{
    public:
    int action_id;
    string action_type;
    string text;
    int cursor_position;
    Action* next;
    
   
   
    Action(int id , string type , string text , int pos){
        
        action_id=id;
        action_type=type;
        this->text=text;
        cursor_position=pos;
        next=nullptr;
        

    }

    



};


class Editor{
    public:
    Action* head;
    Action* undoHead;
    string content;
   
    Editor(){
        head=nullptr;
        undoHead=nullptr;
    }
    bool isEmpty(){
        if(!head){
            return true;
            
        }
        return false;
    }
    void PerformAction(int id , string type , int cursor , string content){
        Action* newAction=new Action(id,type,content,cursor);
        
        this->content+=content;
         newAction->next=head;
        
         
         head=newAction;
        
       
    }
    void Undo(){
         Action* newUndo=new Action(head->action_id , head->action_type , head->text , head->cursor_position);
         if(isEmpty()){
            cout<<"No Action performed"<<endl;
            return;
         }
        
        Action* toDelete=head;
            head=head->next;
        newUndo->next=undoHead;
        undoHead=newUndo;
        delete toDelete;
    }
    void Redo(){
        if(!undoHead){
            
            cout<<"Nothing was undone"<<endl;
            return;
        }

        
        Action* revert=new Action(undoHead->action_id , undoHead->action_type , undoHead->text , undoHead->cursor_position);
        //insert back the undo operation

        if(isEmpty()){
            head=revert;
            Action* toDelete=undoHead;
            undoHead=undoHead->next;
            delete undoHead;
            return;
        }
        revert->next=head;
        head=revert;
    }
    


};


int main(){

    Editor e;
    
    //after 3 insertions
    e.PerformAction(1,"insert",1,"Hi ");
    
    e.PerformAction(2,"insert" ,3 , "I ");
    e.PerformAction(3 , "insert" ,4 , "My ");
    e.PerformAction(4,"insert" , 3 , "Name ");
    ;



    //result:
    cout<<"After insertion of 4 words the cursor is at: ";
    cout<<e.head->text<<endl;
    e.Undo();
    e.Undo();
    cout<<"After undo of 2 actions: ";
     cout<<e.head->text<<endl;
     cout<<"After redo of 1 action: ";
     e.Redo();
     
     cout<<e.head->text<<endl;
     string content="";
     Action* temp=e.head;
     while(temp->next){
     content+=temp->text;
     temp=temp->next;
     }
     cout<<"Content: "<<content;


}
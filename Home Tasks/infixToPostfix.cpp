#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node(char v){
        data=v;
        next=nullptr;
    }
    

};



class Stack {
	private:
		Node* head;
		int size;
public:
	Stack()
	{
		head = nullptr;
		size = -1;
	}
	bool empty()
	{
		return head==NULL;
	}
	void push(char v)
	{
		Node* newNode=new Node(v);
        newNode->next=head;
        head=newNode;
	}
	char pop()
	{
		Node* toDelete = head;
		head = head->next;
		char value = toDelete->data;
		delete toDelete;
		return value;
	}
	char top()
	{
		return head->data;
	}
	int getsize()
	{
		return size+1;
	}
};


bool isOperand(char i){
    return ((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9'));
}

int getPrec(char i){
    if(i=='^'){
        return 3;
    }
    else if(i=='*' || i=='/'){
        return 2;
    }
    else if(i=='+' || i=='-'){
        return 1;
    }
    else{
        return -1;
    }
}



void infixToPostfix(string s){
    string result="";
   
    Stack st;
    for(auto i:s){
        
        
        if(isOperand(i)){
            result+=i;
        }
        else if(i=='('){
            st.push(i);
        }
        else if(i==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        
        else{
            while(!st.empty() && st.top() != '(' && (!st.empty() && getPrec(i)>getPrec(st.top())) || (!st.empty() && getPrec(i)==getPrec(st.top()))  ){
                result+=st.top();
                st.pop();
            }
            st.push(i);
        }
       
       
    }
     while(!st.empty()){
            result+=st.top();
            st.pop();
        }
     cout<<result;




}


void infixToPrefix(string s){

}

int main()
{
    string a;
    cout<<"Enter an infix"<<endl;
    cin>>a;
    infixToPostfix(a);
	
	
	
}

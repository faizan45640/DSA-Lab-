#include<iostream>
#include<stack>
#include<algorithm>
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
        return 3;
    }
    else{
        return -1;
    }
}
bool isOperator(char i){
    return (i=='^' || i=='*' || i=='+' || i=='-' || i=='/');
}

void infixToPrefix(string s){
    string result="";
    Stack st;
   
    reverse(s.rbegin() , s.rend());
    for(auto i:s)
    {
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
        else if(isOperator(i)) {
            if(i=='^'){
                while(!st.empty() && getPrec(i)<=getPrec(st.top())){
                    result=result+st.top();
                    st.pop();
                }
            }
            else{
            while(!st.empty() && getPrec(i)<getPrec(st.top())){
                result+=st.top();
                st.pop();
            }
            }
            st.push(i);
        }


    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    
    reverse(result.rbegin() , result.rend());
    cout<<result;
    

}


int main()
{
    string a;
    cout<<"Enter a infix"<<endl;
    cin>>a;
    infixToPrefix(a);
	
	
	
}

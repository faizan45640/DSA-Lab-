#include<iostream>
using namespace std;

class Array{
    
    int totalSize;
    int usedSize;
    int* ptr;

    public:

    Array(int totalSize){
        usedSize=0;
        this->totalSize=totalSize;
        ptr=new int[totalSize];

    }
    bool insertAtStart(int value){
        if(usedSize<totalSize){
            for(int i=usedSize ; i>0 ; i--){
              swap(ptr[i],ptr[i-1]);
            }
            ptr[0]=value;
            usedSize++;
            return true;
        }
        else{
            cout<<"The array is full"<<endl;
            return false;
        }

    }

    bool insertAtEnd(int value){
        if(front()){
            ptr[usedSize++]=value;
            return true;
        }
        else{
            return false;
        }
    }

    bool front(){

        if(usedSize>totalSize){
            return false;
        }
        return true;

    }
    bool back(){
        if(usedSize<=0){
            return false;
        }
        return true;
    }

    bool remove(int value){
        if(usedSize==0){
            cout<<"The array is empty"<<endl;
            return false;
        }
        for(int i=0 ; i<usedSize ; i++){
            if(ptr[i]==value){
                for(int j=i ; j<usedSize ; j++){
                    swap(ptr[j],ptr[j+1]);
                }
                usedSize--;
                return true;
            }
        }
        cout<<"No value was found"<<endl;
        return false;
        

    }
    void print(){
        if(usedSize==0){
            cout<<"Array is empty"<<endl;
        }
        for(int i=0 ; i<usedSize ; i++){
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
    }

    bool update(int old , int newValue){
        if(usedSize==0){
            cout<<"The array is empty"<<endl;
            return false;
        }
        for(int i=0 ; i<usedSize ; i++){
            if(ptr[i]==old){
                ptr[i]=newValue;
                return true;
            }
        }
        cout<<"The value was not found"<<endl;
        return false;
    }
    int indexAt(int v){
         if(usedSize==0){
            cout<<"The array is empty"<<endl;
            return false;
        }

        for(int i=0 ; i<usedSize ; i++){
            if(ptr[i]==v){
                return i;
            }
        }

        cout<<"No value was found"<<endl;
        return -1;


    }
    bool search(int v){

        for(int i=0 ; i<usedSize ; i++){
            if(ptr[i]==v){
                cout<<"The value was found";
                return true;
            }
        }
        return false;
    }

};



int main(){
    Array a(10);

    a.insertAtStart(4);
    a.insertAtStart(6);
    a.insertAtStart(9);
    a.print();
    a.insertAtStart(3);
    
    
    a.print();
    a.insertAtEnd(7);

    a.remove(6);
    a.update(3,91);
    a.print();
    a.remove(91);
    a.remove(9);
    a.print();
    a.remove(4);
    a.print();
    a.remove(3);
}
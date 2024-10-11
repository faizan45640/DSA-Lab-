#include<iostream>
using namespace std;

const int MAX_SIZE=10;
class Queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
    int currSize=0;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isFull(){
        return currSize==MAX_SIZE;
    }
    bool isEmpty(){
        return currSize==0;
    }
    void enqueue(int v){
        if(currSize==MAX_SIZE)
        return;
       
        if(currSize==0){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%MAX_SIZE;
        }
        arr[rear]=v;
        currSize++;    
    }
    int dequeue(){
        int v;
        if(currSize==0){
            return -1;
        }
        else if(currSize==1){
            int v=arr[front];
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX_SIZE;
        }
        currSize--;
        return v;

    }

};
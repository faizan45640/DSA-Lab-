#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }


};



class BST{
    public:
    Node* root;
    
    BST(){
        root = NULL;
    }

    void insert(int data){
        //insert in binary tree
        Node* newNode = new Node(data);
        if(root==NULL){
            root = newNode;
            return;
        }
        Node* temp = root;
        Node* parent = NULL;
        while(temp!=NULL){
            parent = temp;
            if(data<temp->data){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        if(data<parent->data){
            parent->left = newNode;
        }else{
            parent->right = newNode;
        }

    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

};

void sum(Node* root, int level, int& oddSum, int& evenSum){
    if(root==NULL){
        return;
    }
    if(level%2==0){
        evenSum+=root->data;
    }else{
        oddSum+=root->data;
    }
    sum(root->left, level+1, oddSum, evenSum);
    sum(root->right, level+1, oddSum, evenSum);
}

int difference(Node* root){
    int even = 0;
    int odd = 0;
    sum(root, 1, odd, even);
    return odd-even;
}

int main(){

    BST* tree = new BST();
    tree->insert(10);
    tree->insert(5);
    tree->insert(15);
    tree->insert(3);
    tree->insert(7);
    tree->insert(12);
    tree->insert(18);
    tree->inorder(tree->root);
   
    cout<<endl<<difference(tree->root);
    return 0;

}

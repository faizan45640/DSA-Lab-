#include<iostream>
#include<stack>
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

bool findPair(Node* root, int value) {
    if (!root) {
        return false;
    }

    if (root->data == value) 
        return true;
     else if (root->data > value) {
        return findPair(root->left, value);
    } else {
        return findPair(root->right, value);
    }
}


int CountPairs(Node* root1, Node* root2, int x, int& count) {
    if (!root1 || !root2) {
        return 0;
    }

    CountPairs(root1->left, root2, x, count);
    CountPairs(root1->right, root2, x, count);

    if (findPair(root2, x - root1->data)==true) {
        count++;
    }

    return count;
}



int main(){
    BST bst1;
    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(7);
    bst1.insert(2);
    bst1.insert(4);
    bst1.insert(6);
    bst1.insert(8);
 //   bst1.inorder(bst1.root);
   
    BST bst2;
    bst2.insert(10);
    bst2.insert(6);
    bst2.insert(15);
    bst2.insert(3);
    bst2.insert(8);
    bst2.insert(11);
    bst2.insert(18);
   // bst2.inorder(bst2.root);
   

    int count=0;
    cout<<CountPairs(bst1.root, bst2.root, 16 , count );

}
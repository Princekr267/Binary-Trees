#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1) return NULL;
    Node* currNode = new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}

int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=sumTree(root->left);
    int right=sumTree(root->right);
    int curr=root->data;
    root->data=left+right;
    if(root->left!=NULL){
        root->data+=root->left->data; 
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    
    return curr; 
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Transform: "<<sumTree(root)<<endl;
    return 0;
}
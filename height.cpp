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

int height(Node* root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    int curr=max(left, right)+1;
    return curr;
}
int main(){
    vector<int> nodes={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root=buildTree(nodes);
    
    cout<<"Height: "<<height(root)<<endl;
    return 0;
}
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

void preorder(Node* root){
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            Q.push(curr->left);
        }
        if(curr->right!=NULL){
            Q.push(curr->right);
        }
    }
}

void levelOrderVariation(Node* root){
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop(); 
        if(curr==NULL){
            cout<<endl;
            if(Q.empty()) break;
            Q.push(NULL);
        } else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                Q.push(curr->left);
            }
            if(curr->right!=NULL){
                Q.push(curr->right);
            }
        } 
    }
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    // vector<int> nodes={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"First Node value: "<<root->data<<endl<<"Pre order travarsal: ";
    preorder(root);
    cout<<endl<<"In(Middle) order travarsal: ";
    inorder(root);
    cout<<endl<<"Post order travarsal: ";
    postorder(root);
    cout<<endl<<"Level order travarsal: ";
    levelOrder(root);
    cout<<endl<<"Level wise traversal:"<<endl;
    levelOrderVariation(root);

    Node* root2=new Node(2);
    root2->left=new Node(4);
    root2->right=new Node(5);
    root2->left->right=new Node(6);
    preorder(root2);
    levelOrder(root2);
    return 0;
}
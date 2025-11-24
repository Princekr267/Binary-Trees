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

void topView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr=q.front();
        q.pop();
        Node* currNode=curr.first;
        int currHD=curr.second;
        if(m.count(currHD)==0){
            m[currHD]=currNode->data;
        }
        if(currNode->left!=NULL){
            pair<Node*, int> left=make_pair(currNode->left, currHD-1);
            q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*, int> right=make_pair(currNode->right, currHD+1);
            q.push(right);
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
void kthLevel(Node* root, int level){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int nullCount=1;
    while(!q.empty() && nullCount<=level){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
           // cout<<endl;
            nullCount++;
            if(q.empty()) break;
            q.push(NULL);
        } else{
            if(nullCount==level){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
               q.push(curr->right);
            }
        }
    }
    cout<<endl;
}
void kthRec(Node* root, int k, int curr){
    if(root==NULL) return;
    if(curr==k){
        cout<<root->data<<" ";
    }
    kthRec(root->left, k, curr+1);
    kthRec(root->right, k, curr+1);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"Top view of tree: ";
    topView(root);
    cout<<"kth level of tree: ";
    kthLevel(root, 3);
    cout<<"kth level of tree(by recursion): ";
    kthRec(root, 3, 1);
    return 0;
}
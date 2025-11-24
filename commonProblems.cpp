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

int countNodes(Node* root){
    if(root==NULL) return 0;
    int left=countNodes(root->left);
    int right=countNodes(root->right);
    return left+right+1;
}

int nodesSum(Node* root){
    if(root==NULL) return 0;
    int left=nodesSum(root->left);
    int right=nodesSum(root->right);
    return left+right+root->data;
}

int diameter(Node* root){  // Time Complexity -> O(n^2)
    if(root==NULL) return 0;

    int currDia=height(root->left)+height(root->right)+1;
    int leftDia=diameter(root->left);
    int rightDia=diameter(root->right);

    return max(currDia, max(leftDia, rightDia));
}

pair<int, int> optimiseDia(Node* root){  // Time Complexity -> O(n)
    if(root==NULL) return make_pair(0, 0);

    pair<int, int> left=optimiseDia(root->left);
    pair<int, int> right=optimiseDia(root->right);

    int curr=(left.second + right.second)+1;
    int final=max(curr, max(left.first, right.first));
    int finalHt=max(left.second, right.second)+1;

    return make_pair(final,  finalHt);
}

bool isIdentical(Node* root, Node* subroot){
    if(root==NULL && subroot==NULL) return true;
    else if(root==NULL || subroot==NULL) return false;
    if(root->data!=subroot->data) return false;
    return isIdentical(root->left, subroot->left)
           && isIdentical(root->right, subroot->right);
}
bool isSubtree(Node* root, Node* subroot){ //doubt or incorrect
    if(root==NULL && subroot==NULL) return true;
    else if(root==NULL || subroot==NULL) return false;
    if(root->data==subroot->data){
        if(isIdentical(root, subroot)) return true;
    }
    // int isLeft=isSubtree(root->left, subroot);
    // if(!isLeft){
        return isSubtree(root->right, subroot) || isSubtree(root->left, subroot);
    // }
    // return true;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    
    cout<<"Height: "<<height(root)<<endl;
    cout<<"No. of Nodes: "<<countNodes(root)<<endl;

    return 0;
}
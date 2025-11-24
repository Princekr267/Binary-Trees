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

int LowCommAnces(Node* root, int n1, int n2){
    if(root == NULL) return -1;
    if(root->data==n1 || root->data==n2){
        return 1;
    }
    LowCommAnces(root->left, n1, n2);
    LowCommAnces(root->right, n1, n2);
}
bool findPath(Node* root, int n, vector<int> &path){
    if(root==NULL) return false;
    path.push_back(root->data);
    if(root->data==n) return true;
    bool left=findPath(root->left, n, path);
    bool right=findPath(root->right, n, path);
    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(Node* root, int n1, int n2){
    vector<int> path_1;
    vector<int> path_2;
    findPath(root, n1, path_1);
    findPath(root, n2, path_2);
    int lca=-1;
    for(int i=0, j=0; i<path_1.size(), j<path_2.size(); i++, j++){
        if(path_1[i]!=path_2[j]){
            return lca;
        }
        lca=path_1[i];
    }
    return lca;
}
Node* lcaApr2(Node* root, int n1, int n2){
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA=lcaApr2(root->left, n1, n2);
    Node* rightLCA=lcaApr2(root->right, n1, n2);
    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    return (leftLCA==NULL) ? rightLCA : leftLCA ;
}
int distance(Node* root, int n){
    if(root==NULL) return -1;
    if(root->data==n) return 0;
    int leftDis=distance(root->left, n);
    if(leftDis!=-1){
        return leftDis+1;
    }
    int rightDis=distance(root->right, n);
    if(rightDis!=-1){
        return rightDis+1;
    }
    return -1;
}
int minDis(Node* root, int n1, int n2){
    Node* lca=lcaApr2(root, n1, n2);
    int dis1=distance(lca, n1);
    int dis2=distance(lca, n2);
    return dis1+dis2;
}
int kthAnccesstor(Node* root, int n, int k){
    if(root==NULL) return -1;
    if(root->data==n) return 0;
    int leftSub=kthAnccesstor(root->left, n, k);
    int rightSub=kthAnccesstor(root->right, n, k);
    if(leftSub==-1 && rightSub==-1) return -1;
    int validVal=(leftSub==-1) ? rightSub : leftSub ;
    if(validVal+1==k){
        cout<<"kth Anccesstor of "<<n<<" is: "<<root->data<<endl;
    }
    return validVal+1;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<endl<<"Lowest common anccesstor: "<<LCA(root, 4, 5)<<endl;
    cout<<"Lowest common anccesstor app 2: "<<lcaApr2(root, 4, 6)->data<<endl;
    cout<<"Min distance: "<<minDis(root, 4, 5)<<endl;
    kthAnccesstor(root, 6, 1);
    return 0;
}
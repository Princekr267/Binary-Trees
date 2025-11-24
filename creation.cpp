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
    cout<<"Height: "<<height(root)<<endl;
    cout<<"No. of Nodes: "<<countNodes(root)<<endl;

    Node* root2=new Node(2);
    root2->left=new Node(4);
    root2->right=new Node(5);
    root2->left->right=new Node(6);
    cout<<"No. of Nodes of root 2: "<<countNodes(root2)<<endl;
   preorder(root2);
    levelOrder(root2);
    cout<<endl<<"Sum of nodes: "<<nodesSum(root)<<endl;
    cout<<"Max Diameter: "<<diameter(root)<<endl;
    cout<<"Optimised code for max diameter: "<<optimiseDia(root).first<<", "<<optimiseDia(root).second<<endl;
    cout<<"Is Subtree?: "<<isSubtree(root, root2)<<endl;
    topView(root);
    kthLevel(root, 3);
    kthRec(root, 3, 1);
    cout<<endl<<"Lowest common anccesstor: "<<LCA(root, 4, 5)<<endl;
    cout<<"Lowest common anccesstor app 2: "<<lcaApr2(root, 4, 6)->data<<endl;
    cout<<"Min distance: "<<minDis(root, 4, 5)<<endl;
    kthAnccesstor(root, 6, 1);
    cout<<"Transform: "<<sumTree(root)<<endl;
    preorder(root);
    levelOrderVariation(root);
    return 0;
}
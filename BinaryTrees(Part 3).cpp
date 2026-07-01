//Kth level of a tree:

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void kthHelper(Node* root, int k, int currlevel){
    if(root == nullptr){
        return;
    }
    if(currlevel == k){
        cout<<root->data<<" ";
        return;
    }
    kthHelper(root->left, k, currlevel + 1);
    kthHelper(root->right, k, currlevel + 1);
}

void kthLevel(Node* root, int k){
    kthHelper(root, k, 1);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    kthLevel(root, 3);
    return 0;
}

//Lowest Common Ancestor:

//Approach 1: --> O(n), O(n)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

bool rootToNodePath(Node* root, int n, vector<int> &path){
    if(root == nullptr){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isleft = rootToNodePath(root->left, n, path);
    int isright = rootToNodePath(root->right, n, path);

    if(isleft || isright){
        return true;
    }

    path.pop_back();
    return false;
}  

int LCA(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i<path1.size() && j<path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 =3;
    cout<<"LCA = "<<LCA(root, n1, n2)<<endl;
    return 0;
}

//Approach 2: O(n), O(1)
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != nullptr && rightLCA != nullptr){
        return root;
    }

    return leftLCA == nullptr ? rightLCA : leftLCA;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 =6;
    cout<<"LCA2 = "<<LCA2(root, n1, n2)<<endl;
    return 0;
}

//Min Distance Between Nodes:

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != nullptr && rightLCA != nullptr){
        return root;
    }

    return leftLCA == nullptr ? rightLCA : leftLCA;
}

int minDist(Node* root, int n1, int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int dist(Node* root, int n){
    if(root == nullptr){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int leftdist = dist(root->left, n);
    if(leftdist != -1){
        return leftdist + 1;
    }
    int rightdist = dist(root->right, n);
    if(rightdist != -1){
        return rightdist + 1;
    }
    return -1;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    int n1 = 4, n2 =6;
    cout<<"Min distance= "<<minDist(root, n1, n2)<<endl;
    return 0;
}

//Transform to summ tree: each node = sum of left and right subtree

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void levelOrder(Node* root){
    if(root == nullptr){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node*curr = q.front();
        q.pop();

        if(curr == nullptr){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(nullptr);    //to track the next line
        }else{
            cout<<curr->data<<" ";

            if(curr->left != nullptr){
               q.push(curr->left);
            }
            if(curr->right != nullptr){
               q.push(curr->right);
            }
        }
    }
}

int transform(Node* root){
    if(root == nullptr){
        return 0;
    }

    int leftold = transform(root->left);
    int rightold = transform(root->right);
    int currold = root->data;

    root->data = leftold + rightold;
    if(root->left != nullptr){
        root->data += root->left->data;
    }
    if(root->right != nullptr){
        root->data += root->right->data;
    }
    return currold;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    transform(root);
    levelOrder(root);
    return 0;
}

//Kth Ancestor of node:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int kthAncestor(Node* root, int node, int k){
    if(root == nullptr){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDist = kthAncestor(root->left, node, k);
    int rightDist = kthAncestor(root->right, node, k);

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;
    if(validVal + 1 == k){
        cout<<"Kth Ancestor: "<<root->data<<endl;
    }
    return validVal + 1;
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    int node = 5, k = 2;
    kthAncestor(root, node, k);
    return 0;
}


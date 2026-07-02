//Sorted array to balanced BST:

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

Node* buildBSTfromSorted(int arr[], int st, int end){
    if(st > end){
        return nullptr;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);
    return curr;
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[7] = {3,4,5,6,7,8,9};
    Node* root = buildBSTfromSorted(arr,0, 6);

    preorder(root);
    cout<<endl;
    return 0;
}

//Convert BST to Balanced BST:

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

Node* BSTfromSortedVec(vector<int> arr, int st, int end){
    if(st > end){
        return nullptr;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = BSTfromSortedVec(arr, st, mid-1);
    curr->right = BSTfromSortedVec(arr, mid+1, end);
    return curr;
}

void getInorder(Node* root, vector<int> &nodes){
    if(root == nullptr){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* balanceBST(Node* root){
    //getInorder sequence
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, nodes.size()-1);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = balanceBST(root);
    preorder(root);
    cout<<endl;
    return 0;
}

//Merge 2 BSTs:

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

Node* BSTfromSortedVec(vector<int> arr, int st, int end){
    if(st > end){
        return nullptr;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = BSTfromSortedVec(arr, st, mid-1);
    curr->right = BSTfromSortedVec(arr, mid+1, end);
    return curr;
}

void getInorder(Node* root, vector<int> &nodes){
    if(root == nullptr){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

Node* MergeBSTs(Node* root1, Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            merged.push_back(nodes1[i++]);
        }else{
            merged.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }

    return BSTfromSortedVec(merged, 0, merged.size()-1);

}
int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);
    
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);
    
    Node* root = MergeBSTs(root1, root2);
    preorder(root);
    cout<<endl;
    return 0;
}

//size of largest BST in Binary Tree:

#include <iostream>
#include <climits>
#include <algorithm>
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

class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST, int min, int max, int sz){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxsize;

Info* largestBST(Node* root){
    // if(root == nullptr){
    //     return new Info(true, INT_MAX, INT_MIN, 0);
    // }
    //OR
    if(root == nullptr){
        return nullptr;
    }
    if(root->left == nullptr && root->right == nullptr){
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currmin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currmax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currsz = leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min){
        maxsize = max(maxsize, currsz);
        return new Info(true, currmin, currmax, currsz);
    }
    return new Info(false, currmin, currmax, currsz);
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout<<"Max size: "<<maxsize<<endl;
    return 0;
}

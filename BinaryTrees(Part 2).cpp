//Diameter of a tree: No. of nodes in the longest path between 2 leaves

//Approach 1: --> O(n^2)
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
    currNode->left = buildTree(nodes);   //left subtree
    currNode->right = buildTree(nodes);  //right subtree

    return currNode;
}

int height(Node* root){
    if(root == nullptr){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}

int diam1(Node* root){
    if(root == nullptr){
        return 0;
    }
    
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    
    cout<<"Diameter: "<<diam1(root)<<endl;
    return 0;
}

//Approach 2: --> O(n)
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
    currNode->left = buildTree(nodes);   //left subtree
    currNode->right = buildTree(nodes);  //right subtree

    return currNode;
}

pair<int,int> diam2(Node* root){
    if(root == nullptr){
        return make_pair(0,0);
    }

    pair<int, int> leftInfo = diam2(root->left);  //LD,LH
    pair<int, int> rightInfo = diam2(root->right);  //RD,RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    
    cout<<"Diameter: "<<diam2(root).first<<endl;
    return 0;
}

//Subtree of another tree: Return true if there is a subtree of root with the same structure and node values of subroot and false otherwise

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

bool isIdentical(Node* root1, Node* root2){

    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){

    if(root == nullptr && subRoot == nullptr){
        return true;
    }

    if(root == nullptr || subRoot == nullptr){
        return false;
    }

    if(root->data == subRoot->data){
        if(isIdentical(root, subRoot)){
            return true;
        }
    }

    bool isLeftSubtree = isSubtree(root->left, subRoot);

    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }

    return true;
}

int main(){

    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubtree(root, subRoot) << endl;

    return 0;
}

/* Map in C++: Map(key, value)
STL Container:
-map<int, int> m;   //creating a map
-m[key] = val;      //insert in a map
-cout<<m[key];      //access val using key
-m.count(key);      //1 if key present, 0 if key not present
-loop on map: 
for(auto it : m){
cout<<it.first<<it.second;
}                                               */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<int, string> m;
    m[101] = "rahul";
    m[102] = "neha";
    m[131] = "rahul";

    cout<<m[101]<<endl;

    m[101] = "rajat";    //update

    cout<<m.count(101)<<endl;
    cout<<m.count(120)<<endl;

    for(auto it : m){
        cout<<"Key= "<<it.first<<","<<"Value= "<<it.second<<endl;
        cout<<"Double= "<<it.first*2<<endl;
    }
    return 0;
}

//Top view of a tree:

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void topView(Node* root){
    queue<pair<Node*, int>> Q;    //(node, HD)
    map<int, int> m;   //(HD, node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }
        if(currNode->left != nullptr){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }
        if(currNode->right != nullptr){
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    topView(root);
    return 0;
}

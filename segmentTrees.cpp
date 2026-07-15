//Segment Trees: to handle Range queries

#include <iostream>
#include <vector>
using namespace std;

class segmentTree {
    vector<int> tree;
    int n;

    // Build Segment Tree
    void buildTree(vector<int> &arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        buildTree(arr, start, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Range Sum Query
    int rangeSum(int qi, int qj, int si, int sj, int node) {

        // No overlap
        if (qj < si || qi > sj)
            return 0;

        // Complete overlap
        if (qi <= si && sj <= qj)
            return tree[node];

        // Partial overlap
        int mid = si + (sj - si) / 2;

        return rangeSum(qi, qj, si, mid, 2 * node + 1) +
               rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }

    // Point Update
    void updateUtil(int idx, int newVal, int start, int end, int node) {

        if (start == end) {
            tree[node] = newVal;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            updateUtil(idx, newVal, start, mid, 2 * node + 1);
        else
            updateUtil(idx, newVal, mid + 1, end, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    segmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }

    void printTree() {
        for (int x : tree)
            cout << x << " ";
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n - 1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n - 1, 0);
    }
};

int main() {

    vector<int> arr = {1,2,3,4,5,6,7,8};

    segmentTree st(arr);

    cout << "Segment Tree:\n";
    st.printTree();

    cout << "\nRange Sum (2,5): " << st.rangeQuery(2,5) << endl;
    cout << "Range Sum (0,3): " << st.rangeQuery(0,3) << endl;
    cout << "Range Sum (6,7): " << st.rangeQuery(6,7) << endl;

    // Update index 1 from 2 to 3
    st.updateQuery(1,3);

    cout << "\nAfter Update:\n";
    st.printTree();

    cout << "Range Sum (0,3): " << st.rangeQuery(0,3) << endl;

    return 0;
}

//Max segment Tree: 

#include <iostream>
#include <vector>
#include<climits>
using namespace std;

class segmentTree{
    vector<int> tree;
    int n;
    //Creation
    void buildTree(vector<int> &nums, int start, int end, int node){
        if(start == end){
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start)/2;

        buildTree(nums, start, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);
    }
    
    //Query
    int maxQuery(int qi, int qj, int si, int sj, int node){
        if(qi > sj || qj < si){
            return INT_MIN;
        }

        if(si >= qi && sj <= qj){
            return tree[node];
        }

        int mid = si + (sj - si)/2;

        int leftmax = maxQuery(qi, qj, si, mid, 2*node+1);
        int rightmax = maxQuery(qi, qj, mid+1, sj, 2*node+2);

        return max(leftmax, rightmax);
    }

    //update
    void updateUtil(int idx, int newVal, int start, int end, int node){
        int mid = start + (end - start)/2;
        if(idx >= start && idx <= mid){
            updateUtil(idx, newVal, start, mid, 2*node+1);
        }else{
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

public:
    segmentTree(vector<int> &nums){
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }

    void printTree(){
        for(int el : tree){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    int rangeQuery(int qi, int qj){
        return maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal){
        return updateUtil(idx, newVal, 0, n-1, 0);
    }
};

int main(){
    vector<int> nums = {6,8,-1,2,17,1,3,2,4};

    segmentTree st(nums);
    st.printTree();

    cout<<st.rangeQuery(2,5)<<endl;

    st.updateQuery(4,5);
    cout<<st.rangeQuery(0,8)<<endl;
    return 0;
}

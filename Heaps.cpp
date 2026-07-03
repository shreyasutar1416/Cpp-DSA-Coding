//Heaps/Priority Queue: PQ is build on top of heap, for code heap use array, vector
//Heap is a data structure, heap is a complete BT(CBT), CBT is a BT where all levels are filled except maybe the last one, which is filled from left to right , parent >= children -->(maxheap)

//PQ in STL:
#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;       //descending-->max heap(default)
    //priority_queue<int, vector<int>, greater<int>> pq;  //ascending-->min heap(manually)

    pq.push(5);
    pq.push(10);
    pq.push(3);

    while(!pq.empty()){
        cout<<"Top: "<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}

//push/pop/top in heap:

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;   //CBT- max heap
public:
    void push(int val){
        //step 1
        vec.push_back(val);

        //fix heap
        int x = vec.size()-1;  //child Idx
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){   //O(log n)
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i){
        if(i >= vec.size()){
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }
        swap(vec[i], vec[maxIdx]);
        //swapping with child node
        if(maxIdx != i){
            heapify(maxIdx);
        }
    }

    void pop(){
        //step 1
        swap(vec[0], vec[vec.size()-1]);
        //step 2
        vec.pop_back();
        //step 3
        heapify(0);       //O(log n)
    }

    int top(){              //O(1)
        return vec[0];      //highest priority element
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    cout<<"Top: "<<heap.top()<<endl;

    heap.pop();
    cout<<"Top: "<<heap.top()<<endl;

    return 0;

}

//PQ for pair/ objects:

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class student{
public:
    string name;
    int marks;

    student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }
    //operator overloading
    bool operator < (const student &obj) const{
        return this->marks < obj.marks;     
    }
};

int main(){
    priority_queue<student> pq;      

    pq.push(student("aman", 85));
    pq.push(student("Bhumika", 95));
    pq.push(student("Chetan", 65));

    while(!pq.empty()){
        cout<<"Top: "<<pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}

//PQ for Pairs:

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class student{
public:
    string name;
    int marks;

    student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }
    //operator overloading
    bool operator < (const student &obj) const{
        return this->marks < obj.marks;     
    }
};

struct comparePair{
    bool operator()(const pair<string, int> &p1,const pair<string, int> &p2) const{
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparePair> pq;

    pq.push(make_pair("aman", 85));
    pq.push(make_pair("Bhumika", 95));
    pq.push(make_pair("Chetan", 65));

    while(!pq.empty()){
        cout<<"Top: "<<pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}

//Heap Sort:  -->O(n log n)

#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int> &arr, int n){    //O(log n)
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if(left < n && arr[left] > arr[maxIdx]){
        maxIdx = left;
    }
    if(right < n && arr[right] > arr[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != i){
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}

void heapSort(vector<int> arr){     //O(n)
    int n = arr.size();
    //step 1 : build max heap
    for(int i = n/2-1; i>=0; i--){
        heapify(i, arr, n);
    }
    //step 2: taking else to correct pos
    for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main(){
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//Nearby Cars:

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class car{
public:
    int idx;
    int distSq;

    car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }
    //operator overloading
    bool operator < (const car &obj) const{
        return this->distSq > obj.distSq;   //min heap
    }
};

void nearbycar(vector<pair<int, int>> pos, int k){  //-->O(n + k log n)
    vector<car> cars;

    for(int i = 0; i< pos.size(); i++){       //O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(car(i, distSq));
    }

    priority_queue<car> pq(cars.begin(), cars.end());

    for(int i = 0; i<k; i++){
        cout<<"Car: "<<pq.top().idx<<endl;
        pq.pop();                              //O(log n)
    } 
}

int main(){
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k = 2;
    nearbycar(pos, k);
    return 0;
}

//Connect N ropes:

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int ConnectNropes(vector<int> ropes){
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());   //O(n)
    
    int cost = 0;
    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1 + min2); 
    }
    cout<<"Min cost: "<<cost<<endl;
    return cost;
}

int main(){
    vector<int> ropes = {4,3,2,6};
    ConnectNropes(ropes);
    return 0;
}

//Weakest Soldier:

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
public:
    int count;
    int idx;

    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const{
        if(this->count == obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;    //min heap
    }
};

void weakestSoldier(vector<vector<int>> matrix, int k){
    vector<Row> rows;
    for(int i = 0; i<matrix.size(); i++){
        int count = 0;
        for(int j = 0; j<matrix[i].size() && matrix[i][j] == 1; j++){
            count++;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());
    for(int i = 0; i<k; i++){
        cout<<"Row"<<pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<vector<int>> matrix = {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}};
    weakestSoldier(matrix, 2);
    return 0;
}

//Sliding window maximum:

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindowMax(vector<int> arr, int k){
    priority_queue<pair<int, int>> pq;
    
    //1st window
    for(int i = 0; i<k; i++){
        pq.push(make_pair(arr[i], i));
    }
    cout<<"Output: "<<pq.top().first<<" ";
    
    for(int i = k; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout<<pq.top().first<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    slidingWindowMax(arr, k);
    return 0;
}

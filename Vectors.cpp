//Creating a Dynamic Array
#include <iostream>
using namespace std;

int main(){
    int size;
    cin>>size;

    int *arr = new int[size];

    int x = 1;
    for(int i = 0; i<size; i++){
        arr[i] = x;
        cout<<arr[i]<<" ";
        x++;
    }
    cout<<endl;
    return 0;
}

/* Dynamic Memory Allocation:
1) Static Complie- allocation at complie time, uses stack memory, gets freed automatically
2) Dynamic Runtime- allocation at runtime(new operator), uses heap memory, need to be freed explicitly(delete operator)   */

/* Memory Leak: 
A Memory leak occurs when programmers create a memory
in a heap and forget to delete it. leads to reduced performance 
due to depletion of available memory    */
#include <iostream>
using namespace std;

int * func(){
    int *ptr = new int;
    *ptr = 1200;
    cout<<"ptr points to "<<*ptr<<endl;
    return ptr;
}
int main(){
    int *x = func();
    cout<<*x<<endl;
    return 0;
}

//2D Dynamic Arrays:
#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout<<"Enter the rows: ";
    cin>>rows;
    cout<<"Enter the cols: ";
    cin>>cols;

    int* *matrix = new int*[rows];
    for(int i =0; i<rows; i++){
        matrix[i] = new int[cols];
    }
    int x = 1;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            matrix[i][j] = x++;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<matrix[2][2]<<endl;
    cout<<*(*(matrix + 2)+2)<<endl;
    return 0;
}

/* STL: Standard Template Library of C++
It is a library (collection) of container classes, algorithms and iterators.
It contains the implementations of common data structures like vectors, stacks, maps etc   */

/* Vectors:
Like Dynamic Arrays that can resized dynamically at runtime. 
They are stored contiguously in memory.       */

//Vector Implementation in Memory:
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>vec = {1,2,3,4};
    cout<<"Size: "<<vec.size()<<endl;
    cout<<"Capacity: "<<vec.capacity()<<endl;

    vec.push_back(5);  //vec.pop_back() --> to delete
    cout<<"Size: "<<vec.size()<<endl;
    cout<<"Capacity: "<<vec.capacity()<<endl;
    return 0;
}


//Pair sum: Find if any pair in sorted vector has target sum
#include <iostream>
#include <vector>
using namespace std;

vector<int>pairsum(vector<int>arr, int target){
    int st = 0, end = arr.size()-1;
    int currsum = 0;
    vector<int>ans;
    while(st<end){
        currsum = arr[st] + arr[end];
        if(currsum == target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currsum > target){
            end--;
        }else{
            st++;
        }
    }
    return ans;
}
int main(){
    vector<int>vec={2,7,11,15};
    int target = 9;
    vector<int>ans = pairsum(vec, target);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}

//2D Vector:
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//Predict the o/p:
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>v;
    for(int i = 0; i<5; i++){
        v.push_back(i);
        cout<<v.size()<<endl;
        cout<<v.capacity()<<endl;
    }
    return 0;
}

/* Question 1: You have a set of integers, which originally 
contains all the numbers from 1 to n. unfortunately, due to some error, 
one of the numbers in set got duplicated to another number in the set, 
which results in repetition of one number and loss of another number    */
vector<int>findErrorNums(vector<int> & nums){
    vector<int>ans;
    int n = nums.size();
    vector<bool> is present(n+1, false);

    for(int i = 0; i<n; i++){
        if(ispresent[nums[i]]){
            ans.push_back(nums[i]);
        }
        ispresent[nums[i]]=true;
    }
    for(int i=1; i<ispresent.size(); i++){
        if(!ispresent[i]){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

/* Question 2: You are given an integer array height of length n. 
There are n vertical lines drwan such that the two endpoints of the 
ith line are (i,0) and (i,height[i])    */
int maxArea(vector<int> & height){
    int left = 0;
    int right = height.size() -1;
    int maxArea = 0;
    while(left<right){
        int currentArea = min(height[left], height[right] * (right-left));
        maxArea = max(maxArea, currentArea);
        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxArea;
}

/* Question 3: Given an integet array nums, return all the 
triplets [nums[i], nums[j], nums[k]] such that i!=j, i!=k and j!=k, 
and nums[i] + nums[j] + nums[k] == 0      */
vector<vector<int>>threesum(vector<int> & nums){
    vector<vector<int>>ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int>temp = {nums[i], nums[j], nums[k]};
                ans.push_bacl(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]){
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]){
                    k--;
                }
            }
        }
    }
    return ans;
}

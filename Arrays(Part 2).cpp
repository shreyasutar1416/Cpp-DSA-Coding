//Print Subarrays: --> Subarray is continuous part of an array
#include <iostream>
using namespace std;

void printSubarrays(int *arr, int n){
    for(int start = 0; start<n; start++){
        for(int end = start; end<n; end++){
            cout<<"("<<start<<","<<end<<")";
            for(int i = start; i<=end; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
int main(){
    int arr[5] ={1,2,3,4,5};
    int n = 5;

    printSubarrays(arr,n);
    return 0;
}

//Max Subarrays Sum (Brute force approach)
//Maximum--> INT_MIN (-infinity)
//Minimum--> INT_MAX (+infinity)
#include <iostream>
#include <climits>
using namespace std;

void maxSubarraysum1(int *arr, int n){
    int maxsum = INT_MIN;

    for(int start = 0; start<n; start++){
        for(int end = start; end<n; end++){
            int currsum = 0;
            for(int i = start; i<=end; i++){
                currsum = currsum +arr[i];
            }
            cout<<currsum<<" ";
            maxsum = max(maxsum, currsum);
        }
        cout<<endl;
    }
    cout<<"Maximum Subarray sum= "<<maxsum<<endl;
}
int main(){
    int arr[6] ={2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraysum1(arr,n);
    return 0;
}

//slightly optimized (max subarrays sum)
#include <iostream>
#include <climits>
using namespace std;

void maxSubarraysum2(int *arr, int n){
    int maxsum = INT_MIN;

    for(int start = 0; start<n; start++){
        int currsum = 0;
        for(int end = start; end<n; end++){
            currsum = currsum + arr[end];
            maxsum = max(maxsum, currsum);
        }
    }
    cout<<"Maximum Subarray sum= "<<maxsum<<endl;
}
int main(){
    int arr[6] ={2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraysum2(arr,n);
    return 0;
}

//Kadane's Algorithm(DP)
#include <iostream>
#include <climits>
using namespace std;

void maxSubarraysum3(int *arr, int n){
    int maxsum = INT_MIN;
    int currsum = 0;

    for(int i = 0; i<n; i++){
        currsum = currsum + arr[i];
        maxsum = max(maxsum, currsum);
        if(currsum < 0){
            currsum = 0;
        }
    }
    cout<<"Maximum Subarray sum= "<<maxsum<<endl;
}
int main(){
    int arr[6] ={2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraysum3(arr,n);
    return 0;
}

//Buy and Sell Stocks Problem:
#include <iostream>
#include <climits>
using namespace std;

void maxProfit(int *prices, int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    for(int i = 1; i<n; i++){
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }
    int maxProfit = 0;
    for(int i = 0; i<n; i++){
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout<<"Max Profit= "<<maxProfit<<endl;
}
int main(){
    int prices[6] = {7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(int);

    maxProfit(prices,n);
    return 0;
}

//Trapping Rainwater
#include <iostream>
using namespace std;

int trap(int height[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(height[0]);

    cout << "Trapped Water = " << trap(height, n);

    return 0;
}


/* Question 1: Give n an integer array nums, return true 
if any value appears at least twice in the array, 
and return false if every element is distinct */

#include <iostream>
#include <algorithm>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    sort(nums, nums + n);

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}

/* Question 2: Search in Rotated Sorted Array
There is an integer array nums sorted in ascending 
order (with distinct values).
Prior to being passed to your function, nums is possibly 
rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is:
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
(0-indexed)
Example
The array:
[0, 1, 2, 4, 5, 6, 7]
might be rotated at pivot index 3 and become:
[4, 5, 6, 7, 0, 1, 2] 
Given the array nums after the possible rotation and an 
integer target, return the index of target if it is in nums,
or-1 if it is not in nums. You must write an algorithm 
with O(logn) runtime complexity*/
#include <iostream>
using namespace std;

int search(int nums[], int n, int target) {
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[st] <= nums[mid]) {
            if (target >= nums[st] && target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    cout << search(nums, n, target);

    return 0;
}

/* Question 3: Maximum Product Subarray
Given an integer array nums, find a subarray that has the 
largest product, and return that product.
The test cases are generated so that the answer will 
fit in a 32-bit integer.*/
#include <iostream>
#include <algorithm>
using namespace std;

int maxProduct(int nums[], int n) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        ans = max(ans, maxProd);
    }

    return ans;
}

int main() {
    int nums[] = {2, 3, -2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << maxProduct(nums, n);

    return 0;
}

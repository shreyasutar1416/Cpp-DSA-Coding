//Matrix Chain Multiplication (MCM) with Recursion:

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int mcmRec(vector<int> arr, int i, int j){       //min cost
    if(i == j){
        return 0;
    }
    int ans = INT_MAX;

    for(int k = i; k<j; k++){
        //(i,k)
        int cost1 = mcmRec(arr, i, k);
        //(k+1, j)
        int cost2 = mcmRec(arr, k+1, j);
        //curr partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();
    cout<<mcmRec(arr, 1, n-1)<<endl;
    return 0;
}

//Matrix Chain Multiplication (MCM) with memoization:

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int mcmMem(vector<int> arr, int i, int j, vector<vector<int>> &dp){       //min cost
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k = i; k<j; k++){
        //(i,k)
        int cost1 = mcmMem(arr, i, k, dp);
        //(k+1, j)
        int cost2 = mcmMem(arr, k+1, j, dp);
        //curr partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }
    return dp[i][j] = ans;
}

int main(){
    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<mcmMem(arr, 1, n-1, dp)<<endl;
    return 0;
}

//Matrix Chain Multiplication (MCM) with Tabulation: --> O(n^2)

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int mcmTab(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));

    //initialization
    for(int i = 1; i<n; i++){
        dp[i][i] = 0;
    }
    
    //Bottom up fill
    for(int len = 2; len<n; len++){
        for(int i = 1; i<=n-len; i++){
            int j = i + len-1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    vector<int> arr = {1,2,3,4,3};
    cout<<mcmTab(arr)<<endl;
    return 0;
}

//Minimum Partitioning:  (same as 0-1 knapsack)

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int getMinDiff(vector<int> nums){
    int totSum = 0;
    for(int el : nums){
        totSum += el;
    }

    int n = nums.size();
    int w = totSum/2;

    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int grp1sum = dp[n][w];
    int grp2sum = totSum - grp1sum;
    return abs(grp1sum - grp2sum);
}

int main(){
    vector<int> nums = {1,6, 11, 5};
    cout<<getMinDiff(nums)<<endl;
    return 0;
}

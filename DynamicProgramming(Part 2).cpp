//Knapsack Problems:

//0-1 knapsack: with Recursion --> O(2^n)

#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val, vector<int> wt, int w, int n){
    if(n == 0 || w == 0){
        return 0;
    }
    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){     //valid
        //include
        int ans1 = knapSackRec(val, wt, w - itemWt, n-1) + itemVal;
        //exclude
        int ans2 = knapSackRec(val, wt, w, n-1);

        return max(ans1, ans2);
    }else{               //invalid
        //exclude
        return knapSackRec(val, wt, w, n-1);
    }
}
int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7; 
    int n = 5;
    cout<<knapSackRec(val, wt, w, n-1)<<endl;
    return 0;
}

//0-1 knapsack: with Memoization --> O(n*w)

#include<iostream>
#include<vector>
using namespace std;

int knapSackMem(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>> &dp){
    if(n == 0 || w == 0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){     //valid
        //include
        int ans1 = knapSackMem(val, wt, w, n-1, dp);
        //exclude
        int ans2 = knapSackMem(val, wt, w, n-1, dp);

        dp[n][w] = max(ans1, ans2);
    }else{               //invalid
        //exclude
        dp[n][w] = knapSackMem(val, wt, w, n-1, dp);
    }
    return dp[n][w];
}
int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7; 
    int n = 5;
    vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
    cout<<knapSackMem(val, wt, w, n, dp)<<endl;

    cout<<"Mean Matrix\n";
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<w+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//0-1 Knapsack: with Tabulation --> O(n*w)

#include<iostream>
#include<vector>
using namespace std;

int knapSackTab(vector<int>val, vector<int>wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7; 
    int n = 5;
    cout<<knapSackTab(val, wt, w, n)<<endl;
    return 0;
}

//Target sum subset: variation of 0-1 knapsack  --> O(n*target)
//find if there is a subset of numbers which give sum equal to target

#include<iostream>
#include<vector>
using namespace std;

int targetSum(vector<int>nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target] == target;
}
int main(){
    vector<int> nums = {4,2,7,1,3};
    int target = 7;

    cout<<targetSum(nums, target)<<endl;
    return 0;
}

//Unbounded KnapSack: --> O(n*w)

#include<iostream>
#include<vector>
using namespace std;

int unboundedknapSack(vector<int>val, vector<int>wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7; 
    int n = 5;
    cout<<unboundedknapSack(val, wt, w, n)<<endl;
    return 0;
}


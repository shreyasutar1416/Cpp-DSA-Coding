//Coin Change: return number of combinations --> O(n*amount)

#include<iostream>
#include<vector> 
using namespace std;

class solution{
public:
    int change(int amount, vector<int> &coins){
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        for(int i = 0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<amount+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};

//Rod Cutting: cut rod into pieces to get maxprofit from pieces. possible pieces are always of len 1 to n

#include<iostream>
#include<vector> 
using namespace std;

int rodCutting(vector<int> price, vector<int>length, int rodLength){
    int n = length.size();
    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<rodLength+1; j++){
            if(length[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodLength];
}
int main(){
    vector<int> price = {1,5,8,9,10,17,17,20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int rodLength = 8;
    
    cout<<rodCutting(price, length, rodLength)<<endl;
    return 0;
}

//Longest common subsequence: with Recursion --> O(2^n)
//subsequence is created from a string with characters in the same relative order

#include<iostream>
#include<vector> 
using namespace std;

int LcsRec(string str1, string str2){
    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    int n = str1.size();
    int m = str2.size();

    if(str1[n-1] == str2[m-1]){
        return 1 + LcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    }else{
        int ans1 = LcsRec(str1.substr(0, n-1), str2);
        int ans2 = LcsRec(str1, str2.substr(0, m-1));

        return max(ans1, ans2);
    }
}
int main(){
    string str1 = "abcdge";
    string str2 = "abedg";
    int n = str1.size();
    int m = str2.size();

    cout<<LcsRec(str1, str2)<<endl;
    return 0;
}

//Longest common subsequence: with memoization --> O(n*m)

#include<iostream>
#include<vector> 
using namespace std;

int LcsMem(string str1, string str2, vector<vector<int>> dp){
    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    int n = str1.size();
    int m = str2.size();

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]){
        dp[n][m] = 1 + LcsMem(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    }else{
        int ans1 = LcsMem(str1.substr(0, n-1), str2, dp);
        int ans2 = LcsMem(str1, str2.substr(0, m-1), dp);

        dp[n][m] = max(ans1, ans2);
    }
    return dp[n][m];
}
int main(){
    string str1 = "abcdge";
    string str2 = "abedg";
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<LcsMem(str1, str2, dp)<<endl;
    return 0;
}

//Longest common subsequence: with Tabulation --> O(n*m)

#include<iostream>
#include<vector> 
using namespace std;

int LcsTab(string str1, string str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1 ; j++){
            if(str1[i-1] == str2[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1 = "abcdge";
    string str2 = "abedg";
    int n = str1.size();
    int m = str2.size();

    cout<<LcsTab(str1, str2)<<endl;
    return 0;
}


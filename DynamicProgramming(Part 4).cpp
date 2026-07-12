//Longest Common Substring: substring is a contiguous sequence of characters within a string

#include<iostream>
#include<vector> 
using namespace std;

int longestCommonSubstring(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1 ; j++){
            if(str1[i-1] == str2[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int main(){
    string str1 = "abcdge";
    string str2 = "abedg";
    int n = str1.size();
    int m = str2.size();

    cout<<longestCommonSubstring(str1, str2)<<endl;
    return 0;
}

//Longest Increasing Subsequence

#include<iostream>
#include<vector> 
#include <unordered_set>
#include <algorithm>
using namespace std;

int Lis(vector<int> arr){
    unordered_set<int> s(arr.begin(), arr.end());     //unique
    vector<int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end());     //ascending order

    //LCS--> Lis
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1 ; j++){
            if(arr[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    vector<int> arr = {50, 3, 10, 7, 40, 80};
    cout<<Lis(arr)<<endl;
    return 0;
}

//Edit Distance: for 2 strings, return min no. of operations to convert str1 to str2
//--> O(n*m)

#include<iostream>
#include<vector>
using namespace std;

class solution{
public: 
    int minDistance(string word1, string word2){
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        //oth row intialize- insert
        for(int j = 0; j<m+1; j++){
            dp[0][j] = j;
        }

        //oth col- delete
        for(int i = 0; i<n+1; i++){
            dp[i][0] = i;
        }

        //bottom up fill
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

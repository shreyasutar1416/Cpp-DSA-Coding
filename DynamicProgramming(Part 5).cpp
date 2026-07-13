//WildCard Matching:
//Find if wildcard pattern can be matched with a text. The wildcard pattern can include the characters '?' and '*'

class solution{
public:
    bool isMatch(string t, string p){
        int n = t.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;

        for(int j = 1; j<m+1; j++){
            if(p[j-1] == '*'){          //oth row --> text is " "
                dp[0][j] = dp[0][j-1];
            }else{                      //'?' or english char
                dp[0][j] = false;
            }
        }

        //bottom up manner fill DP
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(t[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
}

//Catalan's Number with Recursion:

#include<iostream>
using namespace std;

int catalanRec(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int ans = 0;

    for(int i = 0; i<n; i++){
        ans += catalanRec(i) * catalanRec(n-i-1);
    }
    return ans;
}
int main(){
    for(int i = 0; i<=6; i++){
    cout<<catalanRec(i)<<endl;
    }
    cout<<endl;
    return 0;
}

//Catalan's Number with memoization: O(n)

#include<iostream>
#include <vector>
using namespace std;

int catalanMem(int n, vector<int> &dp){
    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;

    for(int i = 0; i<n; i++){
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp);
    }
    return dp[n] = ans;
}
int main(){
    int n = 6;
    vector<int> dp(n+1, -1);

    for(int i = 0; i<n; i++){
        cout<<catalanMem(i, dp)<<" ";
    }
    cout<<endl;
    return 0;
}

//Catalan's Number with Tabulation: O(n^2)

#include<iostream>
#include <vector>
using namespace std;

int catalanTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n; i++){
        for(int j = 0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 6;
    for(int i = 0; i<=n; i++){
        cout<<catalanTab(i)<<" ";
    }
    cout<<endl;
    return 0;
}

//Count BST's:
//Find count of all possible structurally unique BSTs that can be formed with n nodes

class solution{
public: 
    int numTrees(int n){
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int i = 2; i<=n; i++){
            for(int j = 0; j<i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
}

//Mountain Ranges:
//using up and down strokes create mountains. Find total no. of mountains with n pairs of up and down strokes. (at any moment no. of downstairs can't be mpre than upstairs)

#include<iostream>
#include <vector>
using namespace std;

int mountainRanges(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n; i++){
        for(int j = 0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int pairs = 3;
    cout<<mountainRanges(pairs)<<endl;
    return 0;
}

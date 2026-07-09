//Dynamic Programming

//Fibonacci: with recursion  --> O(2^n)

#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}
int main(){
    int n = 6;
    cout<<fib(n)<<endl;
    return 0;
}

//Fibonacci: with memoization --> O(n)

#include<iostream>
#include<vector>
using namespace std;

int fibDP(int n, vector<int> &f){
    if(n == 0 || n == 1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = fibDP(n-1, f) + fibDP(n-2, f);
    return f[n];
}
int main(){
    int n = 6;
    vector<int> f(n+1, -1);
    cout<<fibDP(n, f)<<endl;
    return 0;
}

//Fibonacci: with Tabulation --> O(n)

#include<iostream>
#include<vector>
using namespace std;

int fibTab(int n){
    vector<int> fib(n+1, 0);
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}
int main(){
    int n = 7;
    cout<<fibTab(n)<<endl;
    return 0;
}

//Climbing stairs: with Recursion --> O(2^n)
//count ways to reach the nth stair. A person can climb 1 or 2 stairs at a time

#include<iostream>
using namespace std;

int countWaysRec(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return countWaysRec(n-1) + countWaysRec(n-2);
}
int main(){
    int n = 5;
    cout<<countWaysRec(n)<<endl;
    return 0;
}

//Climbing stairs: with memoization --> O(n)

#include<iostream>
#include<vector>
using namespace std;

int countWaysMem(int n, vector<int> &dp){
    if(n == 0 || n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = countWaysMem(n-1, dp) + countWaysMem(n-2, dp);
    return dp[n];
}
int main(){
    int n = 6;
    vector<int> dp(n+1, -1);
    cout<<countWaysMem(n, dp)<<endl;
    return 0;
}

//Climbing stairs: with Tabulation --> O(n)

#include<iostream>
#include<vector>
using namespace std;

int countWaysTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n = 5;
    cout<<countWaysTab(n)<<endl;
    return 0;
}

//Variation of Climbing stairs:
//count ways to reach the nth stair. A person can climb 1,2, or 3 stairs at a time

#include<iostream>
#include<vector>
using namespace std;

int countWaysTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main(){
    int n = 4;
    cout<<countWaysTab(n)<<endl;
    return 0;
}


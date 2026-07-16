//Greedy Approach:  --> Make the Greedy choice at all steps. Choose the local optimum and hope for global optimum

//Optimal sub-structure property: --> A problem is said to have an optimal sub-structure if it can be divided into sub-problems whose optimal solution are part of overall optimal solution

//Activity selection: select the max no. of activities that can be performed by a single person. (a person can work on one activity at a time)

#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end){
    //sort on end time
    //A0 select
    int count = 1;
    int currEndTime = end[0];

    for(int i = 1; i <= start.size(); i++){
        if(start[i] >= currEndTime){ //non- overlapping
            count++;
            currEndTime = end[i];
        }
    }
    return count;
}

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9}; 
    cout<<maxActivities(start, end)<<endl;
    return 0;
}

//Pairs in C++:  STL container to store 2 objects

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;      //ascending order
}

int main(){
    vector<int> start = {0,1,3};
    vector<int> end = {9,2,4};

    vector<pair<int,int>> activity(3, make_pair(0,0));

    activity[0] = make_pair(0,9);
    activity[1] = make_pair(1,2);
    activity[2] = make_pair(2,4);
     
    for(int i = 0; i < activity.size(); i++){
        cout<<"A"<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    }

    sort(activity.begin(), activity.end(), compare);

    cout<<"----------sorted-----------\n";
    for(int i = 0; i < activity.size(); i++){
        cout<<"A"<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    }
    return 0;
}

//Fractional Knapsack: put items in knapsack to get the maximum total value in the knapsack

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;       //des based on ratio
}

int fractionKnapsack(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double,int>> ratio(n, make_pair(0.0,0));     //pair(ratio, idx)--> (double,int)

    for(int i = 0; i < n; i++){
        double r = val[i]/(double) wt[i];
        ratio[i] = make_pair(r,i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int idx = ratio[i].second;   //wt , val
        if(wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        }else{
            ans += ratio[i].first * W;
            W = 0;
            break;
        }
    }
    cout<<"max value= "<<ans<<endl;
    return ans;
}

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    fractionKnapsack(val, wt, W);
    return 0;
}

//Min absolute difference pairs: Pair elements of A and B to minimize sum of absolute differences b/w pairs.

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> A = {1,2,3};
    vector<int> B = {3,1,2};
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    for(int i = 0; i < A.size(); i++){
        absDiff += abs(A[i] - B[i]);
    }

    cout<<"Min abs diff= "<<absDiff<<endl;
    return 0;
}

//Max Length chain of pairs: (non-overlapping) find the longest chain which can be formed from a given set of pairs

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>p1, pair<int, int> p2){
    //ascending
    return p1.second < p2.second;
}

int maxChainLength(vector<pair<int, int>> pairs){
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    int ans = 1;
    int currEnd = pairs[0].second;

    for(int i = 1; i < n; i++){
        if(pairs[i].first > currEnd){   //non-overlap
            ans++;
            currEnd = pairs[i].second;
        }
    }
    cout<<"max chain length= "<<ans<<endl;
    return ans;
}

int main(){
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    maxChainLength(pairs);
    return 0;
}

//Indian Coins: we are given an infinite supply of denominations[1,2,5,10,20,50,100,500,2000] find min no. of coins to make change for a value V

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int getMinChange(vector<int> coins, int v){
    int ans = 0;
    int n = coins.size();

    for(int i = n-1; i >= 0 && v > 0; i--){
        if(v >= coins[i]){
            ans += v/coins[i];
            v = v % coins[i];
        }
    }
    cout<<"Min coins for change= "<<ans<<endl;
    return ans;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int v = 590;
    getMinChange(coins, v);
    return 0;
}

//Job sequencing problem: maximize the total profit if only one job can be scheduled at a time

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    sort(jobs.begin(), jobs.end(), compare);
    //first--> deadline; second--> profit
    int profit = jobs[0].second;
    int safeDeadline = 2;

    for(int i = 1; i < jobs.size(); i++){
        if(jobs[i].first >= safeDeadline){
            profit += jobs[i].second;
            safeDeadline++;
        }
    }
    cout<<"Max profit from jobs: "<<profit<<endl;
    return profit;
}

int main(){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);
    
    maxProfit(jobs);
    return 0;

}

//Job sequencing variation:

class Job{
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit){
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs){
    int n = pairs.size();
    vector<job> jobs;

    for(int i = 0; i < n; i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);   //idx,deadline,profit
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.profit > b.profit;
    });   //descending order on basis of profit

    cout<<"selecting Jobs"<<jobs[0].idx<<endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i = 1; i < n; i++){
        if(Jobs[i].deadline >= safeDeadline){
            cout<<"selecting job"<<jobs[i].idx<<endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    cout<<"Max profit= "<<profit<<endl;
    return profit;
}



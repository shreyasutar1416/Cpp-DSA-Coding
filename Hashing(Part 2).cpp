//Majority element--> Find elements that appear more than n/3 times:

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

void majorityElement(vector<int> nums){
    unordered_map<int, int> m;  //<element, freq>

    for(int i = 0; i<nums.size(); i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        }else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int, int> p : m){
        if(p.second > nums.size()/3){
            cout<<p.first<<" ";
        }
    }
    cout<<endl;
}
int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    vector<int> nums2 = {1,2};

    majorityElement(nums2);
    return 0;
}

//Valid anagrams:

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool validAnagrams(string s, string t){
    if(s.size() != t.size()){
        return false;
    }

    unordered_map<char, int> freq;

    for(int i = 0; i<s.size(); i++){
        if(freq.count(s[i])){
            freq[s[i]]++;
        }else{
            freq[s[i]] = 1;
        }
    }

    //2nd to look for t's chars in freq
    for(int i = 0; i<t.size(); i++){
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]] == 0){
                freq.erase(t[i]);
            }else{
                return false;
            }
        }
    }    
    return freq.size() == 0;
}
int main(){
    string s = "race";
    string t = "care";
    cout<<validAnagrams(s,t)<<endl;
    return 0;
}

//Count distinct: 

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int countDistinct(vector<int> arr){
    unordered_set<int> s;

    for(int i = 0; i<arr.size(); i++){
        s.insert(arr[i]);
    }
    for(int el : s){
        cout<<el<<" ";
    }
    cout<<endl;
    return s.size();
}

int main(){
    vector<int> arr = {4,3,2,5,6,7,4,2,1};
    cout<<"Count= "<<countDistinct(arr)<<endl;
    return 0;
}

//Union and intersection:

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int el : arr1){
        s.insert(el);
    }
    for(int el : arr2){
        s.insert(el);
    }
    //print union
    for(int el : s){
        cout<<el<<" ";
    }
    cout<<endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;
    
    for(int el : arr1){
        s.insert(el);
    }
    for(int el : arr2){
        if(s.find(el) != s.end()){
            cout<<el<<" ";
        }
    }
    cout<<endl;
}

int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};

    cout<<"Union: ";
    printUnion(arr1, arr2);

    cout<<"Intersection: ";
    printIntersection(arr1, arr2);
    return 0;
}

//Itinerary from tickets:

#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void printItinerary(unordered_map<string, string> tickets){
    //starting point
    unordered_set<string> to;

    for(pair<string, string>ticket : tickets){
        to.insert(ticket.second);
    }
    string start=" ";
    for(pair<string, string>ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }
    //plan print
    cout<<start<<"-->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"-->";
        start = tickets[start];
    }
    cout<<"destination\n";
}

int main(){
    unordered_map<string, string> tickets;
    tickets["chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
    return 0;
}

//Largest subarray with sum 0:
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubwith0Sum(vector<int> arr){
    unordered_map<int, int> m;
    int sum = 0; 
    int ans = 0;

    for(int j = 0; j<arr.size(); j++){
        sum += arr[j];

        if(m.count(sum)){
            int currlen = j - m[sum];
            ans = max(ans, currlen);
        }else{
            m[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    cout<<"Largest subarray with sum 0: "<<largestSubwith0Sum(arr)<<endl;
    return 0;
}

//Subarray sum equals k:

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraycountwithK(vector<int> arr, int k){
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;

    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
        if(m.count(sum-k)){
            ans += m[sum-k];
        }
        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,2,-2,-20,10};
    int k = -10;

    cout<<"subarray count: "<<subarraycountwithK(arr, k)<<endl;
    return 0;
}

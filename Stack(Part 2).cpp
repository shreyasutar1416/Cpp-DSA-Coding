//Next Greater: first greater element that is to the right   -->O(n)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreater(vector<int>arr, vector<int>ans){
    stack<int> s;
    int idx = arr.size() - 1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx = idx - 1; idx >= 0; idx--){
        int curr = arr[idx];
        while(!s.empty() && curr>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        s.push(curr);
    }
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans = {0,0,0,0,0};

    nextGreater(arr, ans);
    return 0;
}

/* Valid Parenthesis:
(), [], {} --> true
( [ ] ) --> true
( }  --> false
) ( --> false      */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isvalid(string str){
    stack<int> s;

    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }else{
            if(s.empty()){
                return false;
            }
        }
        //match
        int top = s.top();
        if((top == '(' && ch == ')') ||
           (top == '[' && ch == ']') ||
           (top == '{' && ch == '}')){
            s.pop();
        }else{
            return false;
        }
    }
    return s.empty();
}
int main(){
    string str1 = "([}])"; 
    string str2 = "([{}])";

    cout<<isvalid(str1)<<endl;
    cout<<isvalid(str2)<<endl;
    return 0;
}

/* Duplicate Parenthesis:
( x + y ) --> false
( ( x + y ) + z ) --> false
( ( x + y ) ) --> true
( ( x + y ) + ( (z) ) ) --> true       */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isDuplicate(string str){
    stack<char> s;

    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(ch != ')'){
            s.push(ch);
        }else{
            if(s.top() == '('){
                return true;
            }
            while(s.top() != '('){
            s.pop();
            }
        }
        s.pop();
    }
    return false;
}
int main(){
    string str1 = "((a+b))";
    string str2 = "((a+b)+(c+a))";

    cout<<isDuplicate(str1)<<endl;
    cout<<isDuplicate(str2)<<endl;
    return 0;
}

//Max area of histogram (Nextsmaller logic):
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void maxAreaHistogram(vector<int> height){
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    //next smaller left
    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i<height.size(); i++){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }
    //next smaller right
    s.push(n-1);
    nsr[n-1] = n;
    for(int i = n-2; i>=0; i--){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i<n; i++){
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;

        maxArea = max(area, maxArea);
    }

    cout<<"Maximum Area of Histogram: "<<maxArea<<endl;
}
int main(){
    vector<int> height = {2,1,5,6,2,3};
    maxAreaHistogram(height);
    return 0;
}

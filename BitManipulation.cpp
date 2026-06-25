/* Bitwise Operators:
1) Bitwise AND &
2) Bitwise OR |
3) Bitwise XOR ^
4) Binary NOT operator (~), ~0=1, ~1=0     */

/* Binary Shift Operators:
1) Left shift: a<<b --> a*2b 
2) Right shift: a>>b --> a/2b     */

//Check if odd or even:
#include <iostream>
using namespace std;

void oddorEven(int num){
    if(!(num & 1)){
        cout<<"Even"<<endl;
    }else{
        cout<<"Odd"<<endl;
    }
}
int main(){
    oddorEven(5);
    oddorEven(8);
    return 0;
}

//Bitmasks are used to access specific bits in a byte of data (num,i)
//Get ith Bit:
#include <iostream>
using namespace std;

int getIthBit(int num, int i){
    int Bitmask = 1<<i;

    if(!(num & Bitmask)){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    cout<<getIthBit(6,2)<<endl;
    cout<<getIthBit(7,2)<<endl;
    return 0;
}

//Set ith Bit:
#include <iostream>
using namespace std;

int setIthBit(int num, int i){
    int Bitmask = 1<<i;

    return(num | Bitmask);
}
int main(){
    cout<<setIthBit(6,3)<<endl; 
    return 0;
}

//Clear ith Bit:
#include <iostream>
using namespace std;

int clearIthBit(int num, int i){
    int Bitmask = ~(1<<i);

    return(num & Bitmask);
}
int main(){
    cout<<clearIthBit(6,1)<<endl; 
    return 0;
}

//Check for power of 2: --> (num) & (num-1)=0
#include <iostream>
using namespace std;

bool ispowerof2(int num){
    if(!(num & num-1)){
        return true;
    }else{
        return false;
    }
}
int main(){
    cout<<ispowerof2(4)<<endl;
    cout<<ispowerof2(16)<<endl;
    return 0;
}

//WAF to update the ith bit in a no. a/c to given value(0 or 1)
#include <iostream>
using namespace std;

void updateIthBit(int num, int i, int val){
    num = num & ~(1<<i);   //clear
    num = num | (val<<i);  //set
    cout<<num<<endl; 
}
int main(){
    updateIthBit(7,2,0);
    updateIthBit(7,3,1);
    return 0;
}

//WAF to clear last i bits of a number
#include <iostream>
using namespace std;

void clearIthBit(int num, int i){
    int Bitmask = (~0)<<i;
    num = num & Bitmask;
    cout<<num<<endl;
}
int main(){
    clearIthBit(15,2); 
    return 0;
}

//Count Set Bits (sum of all digits):
#include <iostream>
using namespace std;

int countsetBits(int num){
    int count = 0;

    while(num > 0){
        int lastDig = num & 1;
        count = count + lastDig;
        num = num>>1;
    }
    cout<<count<<endl;
    return count;
}
int main(){
    countsetBits(10);
    return 0;
}

//Fast Exponentiation:
#include <iostream>
using namespace std;

void fastExpo(int x, int n){
    int ans = 1;
    while(n>0){
        int lastBit = n & 1;
        if(lastBit){
            ans = ans * x;        
        }
        x = x + x;
        n = n>>1;
    }
    cout<<ans<<endl;
}
int main(){
    fastExpo(3,5);
    return 0;
}

//Question 1: WAF to clear the range of bits from i to j in a given no
void clearBitsInRange(int num, int i, int j){
    int a = (~0) << (j+1);
    int b = (1<<i) -1;

    int mask = a/b;
    num = num & mask;

    cout<<num<<endl;
}

//Question 2: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one
int singlenumber(vector<int> & nums){
    int answer = 0;
    for(int i = 0; i< nums.size(); i++){
        answer ^= nums[i];
    }
    return answer;
}

/* Question 3: you are given a 0-indexed integer array nums. 
The effective value of three indices i,j and k is defined
as ((nums[i] | nums[j]) & nums[k])
The XOR- beauty of the array is the Xoring of the effective values 
of all the possible triplets of indices(i,j,k) where o<=i,j , k<n     */
int XORBeauty(vector<int> & nums){
    int a = 0, b = 0;
    for(int i = 0; i<nums.size(); i++){
        a = a | nums[i];
        b = b ^ nums[i];
    }
    return(a & b);
}

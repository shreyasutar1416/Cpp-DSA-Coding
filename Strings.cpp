//<cstring> function

//1) strcpy(dest,src)--> to copy string from src to dest
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100];
    char str2[100] = "Hello world!!";
    strcpy(str1, str2);
    cout<<str1<<endl;
    return 0;
}

//2) strcat(str1,str2)--> to concatenate/join
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100] = "Hello";
    char str2[100] = "world!!";
    strcat(str1,str2);
    cout<<str1<<endl;
    return 0;
}

//3) strcmp(str1,str2)--> compares 2 strings based on values(-ve, 0, +ve) 
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100] = "abc";
    char str2[100] = "xyz";
    cout<<strcmp(str1,str2)<<endl;
    return 0;
}

/* String in C++:
1) C++ strings are objects of pre-defined string class in STL
2) C++ strings have useful member functions
3) C++ strings are dynamic
4) C++ strings support operators like +, ==, > , < etc
5) C++ strings are stored contiguously in memory     */

//For each loop
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str = "apna college";

    for(int i = 0; i<str.length(); i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //OR
    for(char ch: str){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}

/* Member functions:
1) str.length()
2) str.at(Idx) / str[idx]
3) str.substr(startIdx, size)
4) str.find(word)       */

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str = "apna college";
    
    cout<<str.length()<<endl; //12
    cout<<str[2]<<endl;  //2
    cout<<str.at(3)<<endl;  //a
    cout<<str.find("apna")<<endl; //0
    cout<<str.substr(0,4)<<endl;  //apna

    return 0;
}

//Valid Anagram (words--> rearranged)
#include<iostream>
#include<cstring>
using namespace std;

bool isAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout<<"not valid anagrams"<<" ";
        return false;
    }
    int count[26] = {0};
    for(int i = 0; i<str1.length(); i++){
        int idx = str1[i] - 'a';
        count[idx]++;
    }
    for(int i = 0; i<str2.length(); i++){
        int idx = str2[i] - 'a';
        if(count[idx] == 0){
            cout<<"not valid anagram"<<" ";
            return false;
        }
        count[idx]--;
    }
    cout<<"Valid Anagrams"<<" ";
    return true;
}
int main(){
    string str1 = "anagram";
    string str2 = "nagaram";

    isAnagram(str1, str2);
    return 0;
}

//Question 1: Count how many times lowercase vowels occured in a string entered by the user
#include<iostream>
#include<cstring>
using namespace std;

int getVowelCount(string str){
    int vowelCount = 0;

    for(int i = 0; i<str.length(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vowelCount++;
        }
    }
    return vowelCount;
}
int main(){
    string str = "shreya is a good girl";
    cout << "Number of vowels: " << getVowelCount(str);
    return 0;
}

/* Question 2: you are given two strings s1 and s2 of equal length. 
A string swap is an operation where you choose two indices in a string
and swap the characters at these indices, Return true if it is possible
to make both strings equal by performing at most one string swap on exactly
one of the strings. otherwise, return false         */
#include<iostream>
#include<cstring>
using namespace std;

bool areAlmostequal(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    char diffchar1, diffchar2;
    int diff = 0;
    for(int i = 0; i<str1.length(); i++){
        if(str1[i] != str2[i]){
            if(!diff){
                diffchar1 = str1[i];
                diffchar2 = str2[i];
            }else{
                if(str1[i] != diffchar2 || str2[i] != diffchar1){
                    return false;
                }
            }
            diff++;
        }
        if(diff > 2){
            return false;
        }
    }
    if(diff == 1){
        return false;
    }
    return true;
}
int main(){
    string str1 = "shreya";
    string str2 = "shreya";
    cout<<areAlmostequal(str1, str2)<<endl;
    return 0;
}

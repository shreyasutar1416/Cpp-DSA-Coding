//Building a Trie:

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endofword;
    //prefix problem
    int freq;

    Node(){
        endofword = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        //prefix problem
        root->freq = -1;
    }

    //Insert in Trie:
    void insert(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();   //insert
                //prefix problem
                temp->children[key[i]]->freq = 1;
            }else{ //prefix problem
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endofword = true;
    }

    //Search in Trie:
    bool search(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children(key[i]);    //exists
            }else{
                return false;
            }
        }
        return temp->endofword;
    }
    
    //Count unique substrings:
    int countHelper(Nodes* root){
        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }
        return ans+1;
    }

    //Prefic problem
    string getprefix(string key){
        Node* temp = root;
        string prefix = " ";

        for(int i = 0; i<key.size(); i++){
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1){
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }

    //longest word with all prefix:
    string longestStringwithEOW(){
        string ans = " ";
        longestHelper(root, ans, " ");
        return ans;
    }
    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Nodes*> child : root->children){
            if(child.second->endofword){
                temp += child.first;
                if(temp.size() == ans.size() && temp<ans || (temp>ans)){
                    ans = temp;
                }
                longestHelper(child.second, ans, temp){
                    temp = temp.substr(0, temp.size()-1);
                }
            }
        }
    }
};

//Word break problem:
bool helper(Trie &trie, string key){
    if(key.size() == 0){
        return true;
    }
    for(int i = 0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }
    return false;
}

bool wordBreak(vector<string> dict, string key){
    Trie trie;
    for(int i = 0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    return helper(trie,key);
}

//Prefix problem
void prefixProblem(vector<string> dict){
    Trie trie;
    for(int i = 0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    for(int i = 0; i<dict.size(); i++){
        cout<<trie.getprefix(dict[i])<<endl;
    }
}

//Starts with problem: complete this for a trie--> bool starts with (string prefix)
bool startswith(string prefix){
    Node* temp = root;

    for(int i = 0; i<prefix.size(); i++){
        if(temp->children[prefix[i]]){
            temp = temp->children[prefix[i]];
        }else{
            return false;
        }
    }
    return true;
}

//Count unique substrings: Count total distinct substrings in a string 
int countUniqueSubstr(string str){
    Trie trie;
    //find suffix
    for(int i = 0; i<str.size();i++){
        string suffix = str.substr(1);
        trie.insert(suffix);
    }
    return trie.countNodes();
}

//longest word with all prefix:
string longestString(vector<string> dict){
    Trie trie;
    for(int i = 0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
    return trie.longestStringwithEOW();
}

// int main(){
//     vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
//     cout<<longestSubstring(dict)<<endl;
//     return 0;
// }

// int main(){
//     //prefix problem
//     vector<string> dict = {"zebra", "dog", "duck", "dove"};
//     prefixProblem(dict);
//     return 0;
// }

// int main(){
//     //count unique substring
//     string str = "ababa";
//     cout<<countUniqueSubstr(str)<<endl;          //10
//     return 0;
// }

// int main(){
//     //starts with problem
//     vector<string> words = {"apple", "app", "mango", "man", "woman"};
//     Trie trie;

//     for(int i = 0; i<words.size(); i++){
//         trie.insert(words[i]);
//     }
//     cout<<trie.startswith("wom")<<endl;
//     return 0;
// }

// int main(){
//     //word break problem
//     vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
//     cout<<wordBreak(dict, "ilikesamsung")<<endl;   //1
//     return 0;
// }

// int main(){
//     //Building a Trie
//     vector<string> words = {"the", "a", "there", "their", "any", "thee"};
//     Trie trie;

//     for(int i = 0; i<words.size(); i++){
//         trie.insert(words[i]);
//     }
//     cout<<trie.search("their")<<endl;  //1
//     return 0;
// }

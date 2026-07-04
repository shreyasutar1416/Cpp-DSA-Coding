//Hashing--> Unordered Data structure(Key, value)

//Building hash table: (Insert, search, remove)

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    ~Node() {
        if (next != nullptr) {
            delete next;
        }
    }
};

class Hashtable {
    int totalsize;
    int currsize;
    Node** table;

public:
    Hashtable(int size) {
        totalsize = size;
        currsize = 0;

        table = new Node*[totalsize];
        for (int i = 0; i < totalsize; i++) {
            table[i] = nullptr;
        }
    }

    int Hashfunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = (idx + key[i] * key[i]) % totalsize;
        }
        return idx;
    }

    void insert(string key, int value) {
        int idx = Hashfunction(key);

        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;

        currsize++;

        double lambda = (double)currsize / totalsize;
        if (lambda > 1.0) {
            rehash();
        }
    }

    void rehash() {
        Node** oldtable = table;
        int oldsize = totalsize;

        totalsize *= 2;
        currsize = 0;

        table = new Node*[totalsize];
        for (int i = 0; i < totalsize; i++) {
            table[i] = nullptr;
        }

        for (int i = 0; i < oldsize; i++) {
            Node* temp = oldtable[i];
            while (temp != nullptr) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldtable[i] != nullptr)
                delete oldtable[i];
        }

        delete[] oldtable;
    }

    bool exists(string key) {
        int idx = Hashfunction(key);

        Node* temp = table[idx];
        while (temp != nullptr) {
            if (temp->key == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    int search(string key) {
        int idx = Hashfunction(key);

        Node* temp = table[idx];
        while (temp != nullptr) {
            if (temp->key == key)
                return temp->value;

            temp = temp->next;
        }

        return -1;
    }

    void print() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < totalsize; i++) {
            cout << "Index " << i << " --> ";

            Node* temp = table[i];

            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }

            cout << "NULL\n";
        }
    }

    void remove(string key) {
        int idx = Hashfunction(key);

        Node* temp = table[idx];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }

                temp->next = nullptr;
                delete temp;
                currsize--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    ~Hashtable() {
        for (int i = 0; i < totalsize; i++) {
            if (table[i] != nullptr)
                delete table[i];
        }
        delete[] table;
    }
};

int main() {
    Hashtable ht(7);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 60);
    ht.insert("Nepal", 10);

    if (ht.exists("Nepal")) {
        cout << "Nepal Population: " << ht.search("Nepal") << endl;
    }

    ht.print();

    cout << "\nAfter removing China:\n";
    ht.remove("China");

    ht.print();

    return 0;
}

//STL containers:

//Unordered Map:

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> m;

    m["china"] = 150;         //insert
    m["India"] = 150;
    m["US"] = 60;
    m["Nepal"] = 10;

    cout<<m["India"]<<endl;        //print

    for(pair<string, int> country : m){         //print
        cout<<country.first<<","<<country.second<<endl;
    }

    if(m.count("Nepal")){       //count
        cout<<"Nepal exists\n";
    }else{
        cout<<"Nepal doesn't exists\n";
    }

    m.erase("Nepal");    //delete
    return 0;
}

//Unordered sets:

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);    //insert--> duplicates can't be added
    s.insert(5);
    s.insert(3);
    s.insert(2);

    cout<<s.size()<<endl;        //print size

    if(s.find(3) != s.end()){       //find or search
        cout<<"3 exists\n";
    }else{
        cout<<"3 doesn't exists\n";
    }

    s.erase(3);    //delete
    return 0;
}

//Sets:

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);    //insert--> duplicates can't be added
    s.insert(5);
    s.insert(3);
    s.insert(2);

    cout<<s.size()<<endl;        //print size

    if(s.find(3) != s.end()){       //find or search
        cout<<"3 exists\n";
    }else{
        cout<<"3 doesn't exists\n";
    }

    s.erase(3);    //delete
    return 0;
}

//Pair sum/ two sum problem:

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[7] = {1,2,7,11,15,5,9};
    int n = 7;
    int target = 9;

    unordered_map<int, int> m;
    for(int i = 0; i<n; i++){
        int comp = target - arr[i];
        if(m.count(comp)){
            cout<<"ans= "<<m[comp]<<","<<i<<endl;
            break;
        }
        m[arr[i]] = 1;
    }
    return 0;
}


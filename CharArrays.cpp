/* Char Data type- char--> 1 byte(memory)
'a' - 97   'A' - 65
'b' - 98   'B' - 66
'c' - 99   'C' - 67   */ 

/* Character Arrays: 
c-strings
Explicitly terminated by null character
CREATION AND OUTPUT
char work[] = "code" 
char work[5] = "code"
char work[] = {'c','o','d','e','\0'};
char work[50] = {'c','o','d','e','\0'};     */

/* Input char arrays: 
cin.getline()

char word[10];
cin>>word;

OR

char sentence[50];
cin.getline(sentence,50,'.');   //that dot is delimiter(3rd arg)    */

//example
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char sentence[30];
    cin.getline(sentence, 30, '.');

    cout<<"Your word was: "<<sentence<<endl;
    cout<<"Length: "<<strlen(sentence)<<endl;
    return 0;
}

//Convert to Uppercase- word[] = "apple" --> word[] = "APPLE"
#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n){
    for(int i = 0; i<n; i++){
        char ch = word[i];
        if(ch >= 'A' && ch <= 'Z'){ //uppercase
            continue;
        }else{
            word[i] = ch - 'a' + 'A'; //lowercase
        }
    }
}
int main(){
    char word[] = "Apple";
    toUpper(word, strlen(word));
    cout<<word<<endl;
    return 0;
}

//Reverse a char array
#include <iostream>
#include <cstring>
using namespace std;

void Reverse(char word[], int n){
    int st = 0, end= n-1;
    while(st < end){
        swap(word[st], word[end]);
        st++;
        end--;
    }
}
int main(){
    char word[] = "code";
    Reverse(word, strlen(word));
    cout<<"Reverse: "<<word<<endl;
    return 0;
}

//Valid Palindrome
/* char[] = 'apple';   //false
   char[] = 'racecar';  //true     */
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char word[]) {
    int st = 0;
    int end = strlen(word) - 1;

    while (st < end) {
        if (word[st] != word[end]) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main() {
    char word[] = "racecar";

    if (isPalindrome(word))
        cout << "Valid Palindrome";
    else
        cout << "Not Valid Palindrome";

    return 0;
}


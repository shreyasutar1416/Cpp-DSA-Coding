/* FUNCTIONS- block of code that runs when it is called
syntax: 
returnType fName(type para1, type para2,....){
    //do some work
    return some values; (optional)
}
fName(); //function call- inside int main()   */

//example 1
#include <iostream>
using namespace std;

void sayHello(){ //declartion
    cout<<"Hello all!"<<endl; //definition
}

int main(){
    sayHello(); //function call
    return 0;
}

//example 2
#include <iostream>
using namespace std;

int sum(int a, int b){
    int sum = a + b;
    return sum;
}
int main(){
    int s = sum(4,6);
    cout<<"Sum: "<<s<<endl;
    return 0;
}

//WAF to find the product of 2 numbers
#include <iostream>
using namespace std;

int product(int a, int b){
    int p = a * b;
    return p;
}
int main(){
    cout<<"Product: "<<product(2,3)<<endl;
    return 0;
}

//WAF to print if a no. is odd or even
#include <iostream>
using namespace std;

bool iseven(int n){
    if(n%2==0){
        return true;
    }else{
        return false;
    }
}
int main(){
    iseven(19);
    cout<<iseven<<endl;
    return 0;
}

//WAF to print the factorial of a number n
#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
       fact = fact * i;
    }
    cout<<"Factorial of "<<n<<" = "<<fact<<endl;
    return fact;
}
int main(){
    factorial(4);
    return 0;
}

//WAF to print if a number is prime or not
#include <iostream>
using namespace std;

bool isprime(int n){
    if(n==1){
        return false;
    }

    for(int i = 2; i<=n-1; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<isprime(23)<<endl;
    return 0;
}

/* SCOPE- local(inside function defined) 
vs global(outside function defined) scope of variables */

//WAF to find the binomial coefiicient for given n and r: nCr = n!/r!(n-r)!
#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 1; i<=n; i++){
        fact = fact*i;
    }
    return fact;
}

int bincoeff(int n, int r){
    int val1 = factorial(n);
    int val2 = factorial(r);
    int val3 = factorial(n-r);

    int result = val1/(val2*val3);
    return result;
}
int main(){
    cout<<bincoeff(4,2)<<endl;
    return 0;
}

/* FUNCTION OVERLOADING- multiple functions 
having same names but different parameters */

//example
#include <iostream>
using namespace std;

int sum(int a, int b){
    cout<<(a+b)<<endl;
    return a+b;
}
double sum(double a, double b){
    cout<<(a+b)<<endl;
    return a+b;
}
int main(){
    sum(2,4);
    sum(1.2, 3.2);
    return 0;
}

//Print all primes in a range from 2 to n
#include <iostream>
using namespace std;

bool isprime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 1; i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void allprimes(int n){   //allprimes(2 to 10)
    for(int i = 2; i<=n; i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    allprimes(50);
    return 0;
}

//Question 1: WAF to check if a number is a palindrome in c++
#include <iostream>
using namespace std;

int reverse(int n){
    int res = 0;
    while(n>0){
        int lastdig = n%10;
        res = res*10 + lastdig;
        n = n/10;
    }
    return res;
}
bool ispalindrome(int num){
    int revnum = reverse(num);
    return num == revnum;
}
int main(){
    cout<<ispalindrome(121)<<endl;
    return 0;
}

//Question 2: WAF to calculate sum of digits of a number
#include <iostream>
using namespace std;

int digsum(int n){
    int res = 0;
    while(n>0){
        res += n%10;
        n = n/10;
    }
    return res;
}
int main(){
    cout<<digsum(121)<<endl;
    return 0;
}

/* Question 3: WAF which takes 2 numbers as parameters(a and b)
and outputs: a2+b2+2ab   */
#include <iostream>
using namespace std;

int absquare(int a, int b){
    return a*a + b*b + 2*a*b;
}
int main(){
    cout<<absquare(2,3)<<endl;
    return 0;
}

//Question 4: WAF that prints the largest 3 numbers
#include <iostream>
using namespace std;

int largest(int a, int b, int c){
    if((a>=b) && (a>=c)){
        return a;
    }else if(b>=c){
        return b;
    }else{
        return c;
    }
}
int main(){
    cout<<largest(2,6,1)<<endl;
    return 0;
}

/* Question 5: WAF that accepts a character(ch) as parameters
and returns the character that occurs after ch in the english alphabet  */
#include <iostream>
using namespace std;

char getNextchar(char ch){
    if(ch =='z'){
        return 'a';
    }else{
        return ch + 1;
    }
}
int main(){
    cout<<getNextchar('b')<<endl;
    return 0;
}

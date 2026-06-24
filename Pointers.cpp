/* ADDRESS OF OPERATOR: 
"&" gives the address of a variable  */
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    cout<<&a<<endl;
    return 0;
}

//Pointers- A special variable that stores the address of another variable
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    float pi= 3.14;

    int *ptr = &a;
    float *ptr2 = &pi;

    cout<<&a<<"= "<<ptr<<endl;
    cout<<&pi<<"= "<<ptr2<<endl;
    // cout<<sizeof(ptr)<<endl;
    // cout<<sizeof(ptr2)<<endl;
    
    return 0;

}
//Pointer of pointer address storing using pptr
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;
    int **pptr = &ptr;

    cout<<&ptr<<"= "<<pptr<<endl;
    return 0;

}

/* Dereference operator- gets the value of the variable pointed
 by any pointer * operator lets us directly access and modify the 
 value of variable   */
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;

    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    cout<<&a<<endl;
    cout<<*(&a)<<endl;

    return 0;

}
//we can assign new values to variable of pointer direct
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;
    *ptr = 20;

    cout<<a<<endl;
    return 0;

}

/* NULL Pointers- we assign NULL value to a pointer to show that
 it doesn't point to any location, dereferncing null ptr is not 
 possible as it results in error */
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = NULL;
    
    cout<<ptr<<endl;
    //cout<<*ptr<<endl; //segmentation fault
    return 0;

}

/* Passing Arguments
1)Pass by value- when parameter is a copy of actual argument variable in memory
2)Pass by reference(pass by address)- when we pass the reference of arguments to the function */

//Pass by value(code)
#include <iostream>
using namespace std;

// void changeA(int a){
//     a = 20;
//     cout<<a<<endl;
// }
void changeA(int params){
    params= 20;
    cout<<params<<endl;
}
int main(){
    int a = 10;
    changeA(a);
    cout<<a<<endl;
    return 0;
}

//Pass by reference(code) using pointers
#include <iostream>
using namespace std;

void changeA(int *ptr){
    *ptr= 20;
    cout<<*ptr<<endl;
}
int main(){
    int a = 10;
    changeA(&a);
    cout<<a<<endl;
    return 0;
}

//Reference Variables- is an alternate names(alias) of already existing variable
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int &b = a;
    b = 25;
    //a and b refer to the same location in memory and will have same value
    cout<<b<<endl;
    cout<<a<<endl;

    return 0;
}

//Pass by reference(code) using reference variables
#include <iostream>
using namespace std;

// void changeA(int &a){
//     a = 20;
//     cout<<a<<endl;
// }
void changeA(int &params){
    params = 20;
    cout<<params<<endl;
}
int main(){
    int a = 10;
    changeA(a);
    cout<<a<<endl;

    return 0;
}

//example
#include <iostream>
using namespace std;

int main(){
    int x = 5, y = 10;
    int *ptr1 = &x, *ptr2 = &y;
    ptr2 = ptr1;

    cout<<ptr2<<endl;
    cout<<ptr1<<endl;
    cout<<&x<<endl;

    return 0;
}

//example- can we initialize a pointer with a value 0
#include <iostream>
using namespace std;

int main(){
    int *ptr = 0;
    cout<<ptr<<endl;
    return 0;
}

//Question 1:
#include <iostream>
using namespace std;

int main(){
    int x;
    int *ptr;
    x = 7;
    ptr = &x;
    cout<<*ptr;

    return 0;
}

//Question 2:
#include <iostream>
using namespace std;

void multipleBy2(int &a, int &b, int &c){
        a *= 2;
        b *= 2;
        c *= 2;
}
int main(){
    int x = 1, y = 2, z = 3;
    multipleBy2(x,y,z);
    cout<<x<<y<<z<<endl;
    return 0;
}

//Question 3:
#include <iostream>
using namespace std;
int main(){
    int a = 32;
    int *ptr = &a;

    char ch = 'A';
    char &cho = ch;
    
    cho += a;
    *ptr += ch;

    cout<<a<<","<<ch<<endl;
    return 0;
}

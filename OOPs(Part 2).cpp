/* Polymorphism: is the ability of objects to take on different forms 
or behave in different ways depending on the context in which they are used
-compile time polymorphism
-runtime polymorphism        */

// 1)Complie Time Polymorphism:
//--> Function Overloading
#include <iostream>
#include <string>
using namespace std;

class print{
public:
    void show(int x){
        cout<<"int: "<<x<<endl;
    }
    void show(string str){
        cout<<"string: "<<str<<endl;
    }
};
int main(){
    print obj1;
    obj1.show(25);
    obj1.show("apnacollege");
    return 0;
}

//--> Operator Overloading
//syntax- returntype operator opsymbol(){.....}
#include <iostream>
#include <string>
using namespace std;

class complex{
    int real;
    int img;
public:
    complex(int r, int i){
        real = r;
        img = i;
    }
    void showNum(){
        cout<<real<<"+"<<img<<endl;
    }
    void operator + (complex & c2){
        int resreal = this->real + c2.real;
        int resimg = this->img + c2.img;
        complex c3(resreal, resimg);
        cout<<"res= ";
        c3.showNum();
    }
};
int main(){
    complex c1(1,2);
    complex c2(3,4);

    c1.showNum();
    c2.showNum();
    c1 + c2;
    return 0;
}

/* 2) Runtime Polymorphism:
--> Function overriding - parent and child both contain 
the same function with different implementation. 
The parent class function is said to be overridden    */
#include <iostream>
#include <string>
using namespace std;

class parent{
public:
    void show(){
        cout<<"Parent class show...."<<endl;
    }
};
class child : public parent{
public:
    void show(){
        cout<<"child class show...."<<endl;
    }
};
int main(){
    child child1;
    child1.show();
    return 0;
}

/*--> Virtual Functions - A virtual function is a member function that you expect to be redefined in derived classes.  
-Virtual function are dynamic in nature
-Defined by the keyword "virtual" inside a base class and are always declared with a base class and overridden in a child class
-A virtual function is called during runtime                */
#include <iostream>
#include <string>
using namespace std;

class parent{
public:
    void show(){
        cout<<"Parent class show...."<<endl;
    }
    virtual void hello(){
        cout<<"Parent hello"<<endl;
    }
};
class child : public parent{
public:
    void show(){
        cout<<"child class show...."<<endl;
    }
    void hello(){
        cout<<"child hello"<<endl;
    }
};
int main(){
    child child1;
    parent *ptr;
    ptr = &child1;   //Runtime binding
    ptr->hello();    //virtual function
    child1.show();
    return 0;
}

/* Abstraction: Hiding all unnecessary details and showing only the important parts
class shape{
public:
    void draw();  //pure virtual function
}
-Abstract classes and pure virtual functions
-Abstract classes are used to provide a base class from which other classes can be derived
-They cannot be instantiated and are meant to be inherited
-Abstract classes are typically used to define an interface for derived classes
-Pure virtual functions (or abstract functions) is a virtual function with no definition logic.        */
#include <iostream>
#include <string>
using namespace std;

class shape{
public:
   virtual void draw() = 0; //abstract function, Pure virtual function
};
class circle : public shape{
public:
   void draw(){
      cout<<"draw circle"<<endl;
   }
};
class square : public shape{
public:
    void draw(){
        cout<<"draw square"<<endl;
    }
};
int main(){
    circle cir1;
    cir1.draw();
    square squ1;
    squ1.draw();
    return 0;
}

/* Static Keyword:
 1)static variables- variables declared as static in a function are 
 created and initialized once for the lifetime of the program in function
 Static variables in a class are created and initialized once. 
 They are shared by all the objects of the class in classes            */
#include <iostream>
#include <string>
using namespace std;

class Example{
public:
    //static const int x = 0;
    static int x;
};
int Example::x = 0;
int main(){
    Example eg1;
    Example eg2;
    Example eg3;

    cout<<eg1.x++<<endl;
    cout<<eg2.x++<<endl;
    cout<<eg3.x++<<endl;
    return 0;
}

// 2)Static Objects-
#include <iostream>
#include <string>
using namespace std;

class Example{
public:
    Example(){
        cout<<"Constructor...."<<endl;
    }
    ~Example(){
        cout<<"destructor...."<<endl;
    }
};
int main(){
    int a = 0;
    if(a == 0){
        static Example eg1;
    }
    cout<<"Code ending...."<<endl;
    return 0;
}

/* Friend class/Function: 
A friend class or a friend function can access private and 
protected members of other classes in which it is declared as a friend         */
#include <iostream>
#include <string>
using namespace std;

class A{
    string secret = "secret data";
    friend class B;
};
class B{
public: 
    void showsecret(A &obj){
        cout<<obj.secret<<endl;
    }
};
int main(){
    A a1;
    B b1;

    b1.showsecret(a1);
    return 0;
}

/* Question 1: Create a class to store complex no's using operator overloading, 
create the logic to subtract one complex no from another     */
complex operator - (complex &obj){
    int resreal = this->real - obj.real;
    int resimg = this->img - obj.img;
    complex res(resreal, resimg);
    return res;
}

/* Question 2: Create a class Bankaccount with private attribute accountnumber 
and balance. Implement public methods deposit(), withdraw() and getBalance() to 
manage the account       */
#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:
    int accountnumber;
    double balance;
public:
    BankAccount(int accNum, double bal){
        accountnumber = accNum;
        balance = bal;
    }
    void deposit(double amount){
        balance = balance + amount;
    }
    void withdraw(double amount){
        balance = balance - amount;
    }
    double getBalance(){
        return balance;
    }
};
int main(){
    BankAccount myAccount(12345, 500);
    myAccount.deposit(150);
    myAccount.withdraw(100);
    cout<<"Current Balance: "<<myAccount.getBalance()<<endl;
    return 0;
}

/* Question 3: Create a base class person with attributes name and age. 
Derive a class student from person and add an additional attribute studentID. 
Implement a method displayStudentInfo() in the student class to display all details       */
#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(string n, int a) {
        name = n;
        age = a;
    }
};
class student : public person {
private:
    string studentID;
public:
    student(string n, int a, string id) : person(n, a) {
        studentID = id;
    }
    void displayStudentInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Student ID: " << this->studentID << endl;
    }
};
int main() {
    student student1("Alice", 20, "51234");
    student1.displayStudentInfo();
    return 0;
}

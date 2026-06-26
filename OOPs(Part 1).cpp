//Object Oriented Programming (OOPs): Style of writing code in good way
//Classes- Group of entities, Objects- entities in the real world
#include <iostream>
using namespace std;

class student{
    //properties, data
    string name;
    float cgpa;

    //methods, function, member functions
    void getpercentage(){
        cout<<(cgpa * 10)<<"%"<<endl;
    }
};
int main(){
    student s1; //object
    cout<<sizeof(s1)<<endl;
    return 0;
}

/* Access Modifiers:
1) Private: Data and methods accesible inside class 
2) Public: Data and methods accesible to everyone
3) Protected: Data and methods accesible inside class and to its derived class   */
#include <iostream>
using namespace std;

class student{
    //properties
    private:
        string name;
    public:
        float cgpa;

    //methods
    void getpercentage(){
        cout<<(cgpa * 10)<<"%"<<endl;
    }
};
int main(){
    student s1; //object
    s1.cgpa = 9.0;
    cout<<s1.cgpa<<endl;
    s1.getpercentage();
    return 0;
}

//Getter and setters: special methods
#include <iostream>
#include <string>
using namespace std;

class student{
    string name;
    float cgpa;
    
public:
    void getpercentage(){
        cout<<(cgpa * 10)<<endl;
    }
    //setters
    void setName(string nameval){
        name = nameval;
    }
    void setcgpa(string cgpaval){
        cgpa = cgpaval;
    }
    //Getters
    string getName(){
        return name;
    }
    float getcgpa(){
        return cgpa;
    }
};
int main(){
    student s1;
    s1.setName("shradha");
    s1.setcgpa(9.1);
    cout<<s1.getName()<<endl;
    cout<<s1.getcgpa()<<endl;
    return 0;
}

/* Encapsulation: is wrapping up of data and member function (methods) 
in a single unit. It also implements data hiding(Access modifiers)       */

/* Constructors: Special method invoked automatically 
at time of object creation, used for initalisation.
- Same name as class
- constructor doesn't have a return type
- only called once (automatically), at object creation
- memory allocation happens when constructor is called 

(this) is special pointer in C++ that points to current object
this --> property is same as *(this) property         

1)Non - parameterized constructor (default)
2)Parameterized constructor (parameters)- constructor overloading        */
#include <iostream>
#include <string>
using namespace std;

class car {
       string name;
       string color;
public:
    car() {
    cout << "Default constructor called..." << endl;  //default constructor
    }
    car(string name, string color){   //constructor
        cout<<"Constructor is called, object being created..."<<endl;
        this-> name = name;    //this pointer
        this-> color = color;
    }

    void start(){
        cout<<"car has started...."<<endl;
    }
    void stop(){
        cout<<"car has stopped...."<<endl;
    }

    //Getter
    string getName(){
        return name;
    }
};
int main(){
    car c0;  //Non- parameters
    car c1("Maruti 800", "white");  //parameters
    car c2("Fortuner", "black");
    return 0;
}

/* Create a user class with properties: id(private),username(public) 
and password(private). Its id should be initialized, in a parameterized constructor. 
It should have a getter and setter for password     */
#include <iostream>
#include <string>
using namespace std;

class user{
    private:
       int id;
       string password;
    public:
       string username;

    user(int id){     //constructor
        this->id = id;
    }
    //getter
    string getpassword(){
        return password;
    }
    //setter
    void setpassword(string password){
        this->password = password;
    }
};
int main(){
    user user1(101);
    user1.username = "apnacollege";
    user1.setpassword("abcd");
    cout<<"Username: "<<user1.username<<endl;
    cout<<"Password: "<<user1.getpassword()<<endl;
    return 0;
}

//Copy Constructor: special constructor (default) used to copy properties of one object into another 
#include <iostream>
#include <string>
using namespace std;

class car {
    public:
       string name;
       string color;

    car(string name, string color){   //constructor
        this-> name = name;           //this pointer
        this-> color = color;
    }
    //OR
    car(car & original){
        cout<<"Copying original to new...."<<endl;
        name = original.name;
        color = original.color;
    }
};
int main(){
    car c1("maruti 800", "white");
    car c2(c1);    //copy constructor used to copy from another object 
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}

/* Shallow and Deep copy: Shallow copy copies refernces to original array. 
But array remains same. Deep copy created a brand new copy of the array.

complier generally creates a shallow copy for array.

we need to define own copy constructor when deep copy is needed i.e, 
when class contains pointers to dynamically allocated memory    */

//Destructor: to deallocate memory--> ~className(){.....} -->syntax
~car(){
    cout<<"deleting object...."<<endl;
    if(mileage != NULL){
        delete mileage;
        mileage NULL;
    }
};

//Inheritance: code reusability- When properties and member functions of base class are passed on the derived class
//example
class Animal{
    public:
      string color;

    void eat(){
        cout<<"eats...."<<endl;
    }
    void breathe(){
        cout<<"breathe...."<<endl;
    }
};
class fish : public Animal{
    public:
       int fins;

    void swim(){
        cout<<"Swims...."<<endl;
    }
};

//Types of inheritances:
/*  1)Single Inheritance 
       Base class
           |
           |
      Derived class          */

/* 2)Multi level Inheritance
        Base class
            |
            |
        Derived class
            |
            |
        Derived class         */
#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    void eat(){
        cout<<"eats...."<<endl;
    }
    void breathe(){
        cout<<"breathe...."<<endl;
    }
};
class mammal : public Animal{
public:
    string bloodtype = "warm";
    //OR
    // string bloodtype;
    // mammal(){
    //     bloodtype = "warm";
    // }
};
class dog : public mammal{
public:
    void tailwag(){
        cout<<"a dog wags its tail"<<endl;
    }
};
int main(){
    dog d1;
    d1.eat();
    d1.breathe();
    d1.tailwag();
    cout<<d1.bloodtype<<endl;
    return 0;
}

/* 3) Multiple Inheritance
Base class           Base class
    |                    |
    |____________________|                   
             |
       Derived class                  */
#include <iostream>
#include <string>
using namespace std;

class Teacher{
public:
    int salary;
    string subject;
};
class student{
public:
    int rollno;
    float cgpa;
};
class TA : public Teacher, public student{
public:
    string name;
};
int main(){
    TA ta1;
    ta1.name = "shradha";
    ta1.subject = "C++";
    ta1.cgpa = 9.1;

    cout<<ta1.name<<endl;
    cout<<ta1.subject<<endl;
    cout<<ta1.cgpa<<endl;
    return 0;
}

/* 4) Hierarchical Inheritance
          Base class
     ________|________  
     |                |
Derived class     Derived class      */
#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    void eat(){
        cout<<"eats...."<<endl;
    }
    void breathe(){
        cout<<"breathe...."<<endl;
    }
};
class Bird : public Animal{
public:
    void fly(){
        cout<<"Flys...."<<endl;
    }
};
class Fish : public Animal{
public:
    void swim(){
        cout<<"swims...."<<endl;
    }
};
class mammal : public Animal{
public:
    void walk(){
        cout<<"walks...."<<endl;
    }
};
int main(){
    Fish f1;
    f1.swim();
    return 0;
}

// 5) Hybrid Inheritance- Combination of single and hierarchical inheritance


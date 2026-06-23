/* Question 1: In a program, input the side of a square.
You have to output the area of the square.
Input: n(side) Output: n*n(area) */

# include <iostream>
using namespace std;

int main(){
    int side;

    cout<<"Enter the Side: ";
    cin>>side;

    int Area = (side*side);

    cout<<"Area of Square is: "<<Area<<endl;
    return 0;
}

/* Question 2: Enter cost of 3 items from the user(using float datatype)
-a pencil,a pen and an eraser.
You have to output the total cost of the
items back to the user as their bill. */

# include <iostream>
using namespace std;

int main(){
    float pencil;
    float pen;
    float eraser;

    cout<<"Enter the cost of pencil: ";
    cin>>pencil;

    cout<<"Enter the cost of pen: ";
    cin>>pen;
    
    cout<<"Enter the cost of eraser: ";
    cin>>eraser;
    
    float total_cost = (pencil+pen+eraser);
    cout<<"Total cost of items: "<<total_cost<<endl;

    return 0;
}

/* Question 3: Build a Simple Interest Calculator.
Input: principal(P), rate(R), time(T)
Output: (P*R*T)/100 */

# include <iostream>
using namespace std;

int main(){
    float P;
    float R;
    float T;

    cout<<"Enter the Principal: ";
    cin>>P;

    cout<<"Enter the Rate: ";
    cin>>R;
    
    cout<<"Enter the Time: ";
    cin>>T;

    float simple_interest = (P*R*T)/100;
    cout<<"Simple Interest is: "<<simple_interest<<endl;
    
    return 0;
}

/* Question 4:Write a program to calculate the area of a circle.
Input: r(radius) 
Output: PI*r*r(area) */

# include <iostream>
using namespace std;

int main(){
    float r;
    float PI = 3.14;

    cout<<"Enter the Radius: ";
    cin>>r;

    float Area = (PI*r*r);
    cout<<"Area of circle is: "<<Area<<endl;

    return 0;
}


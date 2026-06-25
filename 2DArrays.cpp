//2D Arrays are 2 Dimensional arrays consists of n * m (rows, cols)
//Input and Output of 2D Arrays
#include <iostream>
using namespace std;

int main(){
    int arr[2][3];
    int n=2, m=3;
    
    for(int i = 0; i<n; i++){ 
        for(int j = 0; j<m; j++){
            cin>>arr[i][j];   //input 2D array
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";    //output 2D array
        }
        cout<<endl;
    }
    return 0;
}

//Spiral Matrix
#include <iostream>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m){
    int srow = 0, scol= 0;
    int erow = n-1, ecol = m-1;

    while(srow <= erow && scol <= ecol){
        //top
        for(int j = scol; j<=ecol; j++){
            cout<<mat[srow][j]<<" ";
        }
        //Right
        for(int i = srow+1; i<=erow; i++){
            cout<<mat[i][ecol]<<" ";
        }
        //Bottom
        for(int j = ecol-1; j>=scol; j--){
            cout<<mat[erow][j]<<" ";
        }
        //Left
        for(int i = erow-1; i>=srow+1; i--){
            cout<<mat[i][scol]<<" ";
        }
        srow++; scol++;
        erow--; ecol--;
    }
    cout<<endl;
}
int main(){
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    spiralMatrix(matrix,4,4);
    return 0;
}

//Diagonal sum Matrix
#include <iostream>
using namespace std;

int diagonalsum(int mat[][4], int n, int m){
    int sum = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                sum = sum + mat[i][j];
            }else if(j == n-i-1){
                sum = sum + mat[i][j];
            }
        }
    }
    cout<<"Sum = "<<sum<<endl;
    return sum;
}
int main(){
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    diagonalsum(matrix, 4, 4);
    return 0;
}

//Search in sorted matrix
#include <iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key){
    int i = 0, j = m-1;

    while(i<n && j>=0){
        if(mat[i][j] == key){
            cout<<"Found at cell ("<<i<<","<<j<<")"<<endl;
            return true;
        }else if(mat[i][j] > key){
            j--;   //left
        }else{
            i++;  //down
        }
    }
    cout<<"Key not found\n";
    return false;
}
int main(){
    int matrix[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    search(matrix, 4 , 4 , 50);
    return 0;
}

//Question 1: Print the number of all 7's that are in the 2D array
#include <iostream>
using namespace std;
int main(){
    int arr[][3] = {{4,7,8}, {8,8,7}};
    int n = 2, m = 3;

    int countof7 = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 7){
                countof7++;
            }
        }
    }
    cout<<"Count of 7 is: "<<countof7<<endl;
    return 0;
}

//Question 2: Print out the sum of the numbers in the second row of the "nums" array
#include <iostream>
using namespace std;

int main(){
    int nums[][4] = {{1,2,3,4}, {5,6,7,8}};
    int n = 2, m = 4;
    int sum = 0;

    for(int j = 0; j<m; j++){
        sum = sum + nums[1][j];
    }
    cout<<"Sum is: "<<sum<<endl;
    return 0;
}

//Question 3: Write a program to find transpose of a matrix
//Transpose is a process of swapping the rows and colums

#include <iostream>
using namespace std;

int main() {
    const int row = 2;
    const int column = 3;

    int matrix[row][column] = {
        {2, 3, 7},
        {5, 6, 7}
    };

    int transpose[column][row];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose Matrix:\n";

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

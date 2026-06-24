//Bubble Sort- large elements come to end by swapping with adjacents
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    print(arr,n);
}
int main(){
    int arr[5] ={5,4,1,3,2};
    bubblesort(arr,5);
    return 0;
}

//Selection Sort- Pick the smallest(from unsorted) and put in the beginning
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionsort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int minIdx = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr,n);
}
int main(){
    int arr[5] ={5,4,1,3,2};
    selectionsort(arr,5);
    return 0;
}

//Insertion Sort- Pick an element from unsorted part and place it correctly in sorted part
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Insertionsort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr){
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr,n);
}
int main(){
    int arr[5] ={5,4,1,3,2};
    Insertionsort(arr,5);
    return 0;
}

//Counting Sort- Use a frequency count of elements from min to max
#include <iostream>
#include <climits>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void countsort(int arr[], int n){
    int freq[100000] = {0};
    int minval = INT_MAX, maxval = INT_MIN;

    for(int i = 0; i<n; i++){
        minval = min(minval, arr[i]);
        maxval = min(maxval, arr[i]);
    }
    for(int i =0; i<n; i++){
        freq[arr[i]]++;
    }
    for(int i = minval; j = 0; i<=maxval; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr,n);
}
int main(){
    int arr[5] ={1,4,5,1,4};
    countsort(arr,5);
    return 0;
}

//Inbuilt Sort:
//Ascending order- sort(start, end)
//Descending order- sort(start, end, greater<int>())
#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[8]={1,4,1,3,2,4,3,7};
    sort(arr,arr + 8); //inbuilt sort syntax direct
    print(arr,8);
    return 0;
}

/* Question: Sort this array of characters using insertion sort in descending order 
char ch[] = {'f','b','a','e','c','d'}    */
#include <iostream>
using namespace std;

void print(char arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Insertionsort(char arr[], int n){
    for(int i = 1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr){
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr,n);
}
int main(){
    char arr[] = {'f','b','a','e','c','d'};
    Insertionsort(arr,6);
    return 0;
}



#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
       cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                flag = true;
            }
        }

        if(!flag)
        {
            break;
        }
        
    }

    for (int i = 0; i < size; i++)
    {
       cout << arr[i]<<" ";
    }
    
    
    return 0;
}
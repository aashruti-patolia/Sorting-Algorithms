#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;

    int arr[size];

    cout << "Enter Elements of Array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        if (small != i)
        {
            swap(&arr[i], &arr[small]);
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
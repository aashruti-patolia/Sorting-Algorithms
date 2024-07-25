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

    // actual logic
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1] > arr[j])
            {
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
    // print
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}
#include <iostream>
#include <limits.h>
using namespace std;

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void sort(int size, int temp_arr[], int arr[])
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        max = Max(max, temp_arr[i]);
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        int ele = temp_arr[i];
        int count_ele = 0;
        for (int j = 0; j < size; j++)
        {
            if (temp_arr[j] == ele)
            {
                count_ele++;
            }
        }
        count[ele] = count_ele;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    int output[size];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[temp_arr[i]] - 1] = arr[i];
        count[temp_arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
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

    // main logic

    int largest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    int count_largest_digits = 0;
    while (largest != 0)
    {
        largest = largest / 10;
        count_largest_digits++;
    };

    int temp_arr[size];
    int div = 1;
    for (int i = 0; i < count_largest_digits; i++)
    {

        for (int j = 0; j < size; j++)
        {
            int ele = arr[j] / div;
            temp_arr[j] = ele % 10;
        }
        sort(size, temp_arr, arr);
        div = div * 10;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
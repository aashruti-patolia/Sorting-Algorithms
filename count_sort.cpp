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

int main()
{
    int size;
    int max = INT_MIN;
    cout << "Enter Size of Array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        max = Max(max, arr[i]);
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        int ele = arr[i];
        int count_ele = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == ele)
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

    for (int i = 0; i < size; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}
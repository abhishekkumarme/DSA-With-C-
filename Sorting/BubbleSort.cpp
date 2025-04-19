#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print(int arr[], int n)
{
    cout << "Elements of the array is: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter " << i + 1 << "th element in the array" << endl;
        cin >> arr[i];
    }

    Bubble_sort(arr, n);
    print(arr, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n)
{
    cout << "Elements of the array are: " << endl;
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
        cout << "Enter " << i + 1 << "th element in array" << endl;
        cin >> arr[i];
    }
    InsertionSort(arr, n);
    print(arr, n);
    return 0;
}
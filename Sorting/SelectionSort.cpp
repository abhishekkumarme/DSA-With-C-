#include <bits/stdc++.h>
using namespace std;

void SelectSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}

void print(int arr[], int n)
{
    cout << "Elements of array" << endl;
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
        cout << "Enter " << i + 1 << "th element in arry" << endl;
        cin >> arr[i];
    }
    SelectSort(arr, n);
    print(arr, n);
    return 0;
}
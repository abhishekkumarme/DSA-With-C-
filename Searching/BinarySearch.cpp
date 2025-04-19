#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;  
    } else if (arr[mid] < target) {
        return BinarySearch(arr, mid + 1, high, target);
    } else {
        return BinarySearch(arr, low, mid - 1, target);
    }
}

void sorting(int arr[], int n){
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

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> arr[i];
    }

    
    int target;
    cout << "Enter the value to find: ";
    cin >> target;
    
    sorting(arr,n);
    int result = BinarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Data " << target << " is found at index " << result << " in array." << endl;
    } else {
        cout << "Data is not found in the array." << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {45, 14, 54, 16, 78};
    int n;
    cout << "Enter data to search" << endl;
    cin >> n;
    bool result = false;
    for (int i = 0; i < 5; ++i)
    {
        if (arr[i] == n)
        {
            cout << "Element found at " << i << " index" << endl;
            result = true;
            break;
        }
    }
    if (!result)
    {
        cout << "Element not found" << endl;
    }
    return 0;
}
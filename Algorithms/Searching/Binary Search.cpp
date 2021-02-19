// program for Binary Search
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int binary_search(int [], int, int);

int main(void)
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int arr[n];

    cout << "\nInput data in array->\n";
    
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int num;

    cout << "\nInput number to search: ";
    cin >> num;

    int check = binary_search(arr, n, num);

    (check == -1) ? cout << "\nNumber " << num << " not found\n" << endl : cout << '\n' << num << " is present at " << check << " index\n";
}

int binary_search(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // means we find the number
        if (arr[mid] == x)
            return mid;
        
        // if the x is greater than mid then the number is in right subarray
        else if (arr[mid] < x)
            left = mid + 1;
        
        else 
            right = mid - 1;
    }

    return -1;
}

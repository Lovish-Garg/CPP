// program for Binary Search
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int binary_search(int [], int, int, int);

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

    int check = binary_search(arr, 0, n, num);

    (check == -1) ? cout << "\nNumber " << num << " not found\n" << endl : cout << '\n' << num << " is present at " << check << " index\n";
}

int binary_search(int arr[], int l, int r, int x)
{   
    // if this comes it means that the number isnot in the array
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    // means we find the number
    if (arr[mid] == x)
        return mid;
    
    // if the x is greater than mid then the number is in right subarray
    else if (arr[mid] < x)
        return binary_search(arr, mid + 1, r, x);
    
    else 
        return binary_search(arr, l, mid - 1, x);

    return -1;
}

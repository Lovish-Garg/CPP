// program for Linear Search
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int linear_search(int [], int, int, int);

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

    int check = linear_search(arr, 0, n, num);

    (check == -1) ? cout << "\nNumber " << num << " not found\n" << endl : cout << '\n' << num << " is present at " << check << " index\n";
}

int linear_search(int arr[],int start, int n, int x)
{   
    // this is case when number isnot in the array
    if (start == n)
        return -1;

    // if arr[start] is number to search then return it
    if (arr[start] == x)
        return start;
    
    // else move forward and search number
    return linear_search(arr, ++start, n, x);
}

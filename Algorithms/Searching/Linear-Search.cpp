// program for Linear Search
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int linear_search(int [], int, int);

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

    int check = linear_search(arr, n, num);

    (check == -1) ? cout << "\nNumber " << num << " not found\n" << endl : cout << '\n' << num << " is present at " << check << " index\n";
}

int linear_search(int arr[], int n, int num)
{
    for (int i = 0; i < n; ++i)
        // if num foudn then return index
        if (arr[i] == num)
            return i;
    // else return -1 
    return -1;
}

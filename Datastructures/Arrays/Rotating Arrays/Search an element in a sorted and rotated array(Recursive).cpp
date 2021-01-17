// program to cycally rotate array by one
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
int search_in_rotated(int [], int, int, int);

int main(void)
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int arr[n];

    cout << "\nInput data in elements->\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nData in array->\n";
    print_arr(arr, n);
    
    int num;
    cout << endl << "Number: ";
    cin >> num;

    cout << endl;

    int index = search_in_rotated(arr, 0, n - 1, num);

    (index == -1) ? cout << num << " not present in array.\n" : cout << num << " present at index " << index << endl;
    return 0;
}

int search_in_rotated(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid; 
    
    if (arr[l] <= arr[mid])
    {
        if (x >= arr[l] && x <= arr[mid])
            return search_in_rotated(arr, l, mid - 1, x);

            return search_in_rotated(arr, mid + 1, r, x);
    }

    if (arr[mid] <= arr[r])// this will always be true if inpput is correct and   first case isnot accepted
    {
        if (x >= arr[mid] && x <= arr[r])
            return search_in_rotated(arr, mid + 1, r, x);
    }
    // this can also be written as else case but it will give a warning 
    return search_in_rotated(arr, l, mid - 1, x);
}
// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// array rotation in C++ with Jusggling Algorithm with O(1) space and O(n) time complexity
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void print_arr(int [], int);
void reversal_algorithm(int [], int, int);

int main(void)
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int arr[n];

    cout << "\nInput data in elements->\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int d;

    cout << "\nElements to rotate: ";
    cin >> d;

    cout << "\nArray before rotating->\n";
    print_arr(arr, n);
    
    reversal_algorithm(arr, n, d);

    cout << "\n\nArray after rotating->\n";
    print_arr(arr, n);
    return 0;
}
// to reverse k array
void reverse(int arr[], int l, int r)
{
    while (l < r)
        swap(arr[l++], arr[r--]);
}

void reversal_algorithm(int arr[], int n, int d)
{
    // in case d >= n;
    d = d % n;

    reverse(arr, 0, d - 1);// rotating 0 to d - 1 elements
    reverse(arr, d, n - 1);// rotating d to n - 1 elements
    reverse(arr, 0, n - 1);// rotating the whole array
}

// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

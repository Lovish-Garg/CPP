// program to cycally rotate array by one
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
void rotate_by_one(int [], int);

int main(void)
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int arr[n];

    cout << "\nInput data in elements->\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nArray before rotating->\n";
    print_arr(arr, n);
    
    rotate_by_one(arr, n);

    cout << "\n\nArray after rotating by one->\n";
    print_arr(arr, n);
    return 0;
}
// to cycally rotate array by one
void rotate_by_one(int arr[], int n)
{
    int temp = arr[n - 1];
    
    for (int i = n - 1; i > 0; --i)// assigning the current element the value of its previous element
        arr[i] = arr[i - 1];
        
    arr[0] = temp;   
}

// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// array rotation in C++
#include <iostream>

using std::cout;
using std::cin;

void print_arr(int [], int);
void rotate(int [], int, int);

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
    
    rotate(arr, n, d);

    cout << "\n\nArray after rotating->\n";
    print_arr(arr, n);
    return 0;
}

void rotate(int arr[], int n, int d)
{
    d = d % n;// in case d is greater than n

    for (int i = 0; i < d; ++i)
    {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = temp;
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// Program to implement Insertion Sort
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
void insertion_sort(int [], int);

int main(void)
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nArrar before sorting->\n";
    print_arr(arr, n);

    insertion_sort(arr, n);

    cout << "\nArray after sorting->\n";
    print_arr(arr, n);
}

void insertion_sort(int arr[], int n)
{
    /*
        here I'm starting from 1 because I will take arr[1] to compare 
        with arr[0] and so on.
    */
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int key = arr[i];

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j]; 
            --j;
        }
        arr[j + 1] = key;
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    
    cout << endl;
}

// Program to implement Insertion Sort
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
void bubble_sort(int [], int);

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

    bubble_sort(arr, n);

    cout << "\nArray after sorting->\n";
    print_arr(arr, n);
}

void swap(int &num, int &num2)
{
    int temp = num;
    num = num2;
    num2 = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)// last element will automatically be sorted
    {
        for (int j = 0; j < n - i - 1; ++j)// here with each complete iteration of I we are getting the largest element on right side and we don't need to compare that
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    
    cout << endl;
}

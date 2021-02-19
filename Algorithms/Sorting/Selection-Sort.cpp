#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
void selection_sort(int [], int);

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

    selection_sort(arr, n);

    cout << "\nArray after sorting->\n";
    print_arr(arr, n);
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
            // if we find a number smaller than ith element then store it 
            if (arr[j] < arr[min_index])
                min_index = j;
        // swapping the smallest element found and the ith element
        swap(arr[i], arr[min_index]);
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    
    cout << endl;
}

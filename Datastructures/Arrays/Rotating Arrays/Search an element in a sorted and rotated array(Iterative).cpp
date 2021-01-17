// program to cycally rotate array by one
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print_arr(int [], int);
int search_in_rotated(int [], int, int);

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

    int index = search_in_rotated(arr, n, num);

    (index == -1) ? cout << num << " not present in array.\n" : cout << num << " present at index " << index << endl;
    return 0;
}

int search_in_rotated(int arr[], int n, int x)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid; 
        
        if (arr[l] <= arr[mid])
        {
            if (x >= arr[l] && x <= arr[mid])
                r = mid - 1;
            else 
                l = mid + 1;
        }

        else if (arr[mid] <= arr[r])
        {
            if (x >= arr[mid] && x <= arr[r])
                l = mid + 1;
  
            else
                r = mid - 1;
        }

    }
    
    return -1;
}
// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

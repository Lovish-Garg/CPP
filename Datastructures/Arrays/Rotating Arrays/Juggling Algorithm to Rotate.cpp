// array rotation in C++ with Jusggling Algorithm with O(1) space and O(n) time complexity
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::__gcd;

void print_arr(int [], int);
void juggling_algorithm(int [], int, int);

int main(void)
{
    cout << __gcd(8, 12) << endl;
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
    
    juggling_algorithm(arr, n, d);

    cout << "\n\nArray after rotating->\n";
    print_arr(arr, n);
    return 0;
}

void juggling_algorithm(int arr[], int n, int d)
{
    // for handling if d >= n
    d = d % n;

    int g_c_d = __gcd(d, n);

    for (int i = 0; i < g_c_d; ++i)
    {
        int temp = arr[i];
        int j = i;
        int k;
        
        while (1)
        {
            k = d + j;

            if (k >= n)
                k -= n;

            if (k == i)
                break;

            arr[j] = arr[k];

            j = k;
        }
        arr[j] = temp;
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

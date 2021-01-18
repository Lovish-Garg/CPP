// program to cycally rotate array by one
#include <iostream>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;

void print_arr(int [], int);
void Print_pairs(int [], int, int);

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
    
    int pair;
    cout << endl << "\nPair: ";
    cin >> pair;
    cout << endl;

    Print_pairs(arr, n, pair);
    return 0;
}

void Print_pairs(int arr[], int n, int x)
{
    unordered_set <int> s;

    for (int i = 0; i < n; ++i)
    {
        int temp = x - arr[i];

        // if temp is present means that we found a pair
        if (s.find(temp) != s.end())
        {
            cout << "Pair with given sum  " << x << 
            " is (" << temp << ", " << arr[i] << ")" << endl;
        }
        // always inserting the arr[i]
        s.insert(arr[i]);
    }
}   

// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

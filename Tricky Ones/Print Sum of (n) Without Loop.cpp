#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;

    cout << "Elements: ";
    cin >> n;

    int sum = (n * (n + 1)) / 2;// this formula can solve it

    cout << "Sum is " << sum << endl;
}

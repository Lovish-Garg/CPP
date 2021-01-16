#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::stack;
using std::endl;

template <class T> class Queue
{
    private:
        stack <T> s1;
        stack <T> s2;

    public:
        void push(T);
        T pop();
        void show_queue();
};

template <class T>
void Queue<T>::push(T val)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(val);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

template <class T>
T Queue<T>::pop()
{
    if (s1.empty())
        return -1;

    int x = s1.top();
    s1.pop();

    return x;
}

template <class T>
void Queue<T>::show_queue()
{
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}

int main()
{
    Queue <double> data;
    
    data.push(21);
    data.push(10);
    data.push(7);
    data.push(7.56);

    cout << data.pop() << endl;

    data.show_queue ();
    return 0;
}

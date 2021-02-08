// Here I willnot do input checking much because I'm just implementing Stack
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Stack
{
    private:
        int size;// size of stack
        int *arr;// I will allocate memory at run-time of (n) integers
        int top;// to take record of topmost element
    
    public:
        Stack(int n)
        {
            arr = new int[n];
            size = n;
            top =-1;

            for (int i = 0; i < n; ++i)
                arr[i] = 0;
        }

        ~Stack()
        {
            delete []arr;
        }
        // inline because this function is very small and inline can make it efficient when this function is called many times 
        inline bool isEmpty()
        {
            // if stack is empty then return true else false
            return (top == -1) ? true : false;
        }

        inline bool isFull()
        {   
            // size - 1 because we are using arrays and Arrays use 0 based indexing
            return (top == size - 1) ? true : false;
        }

        void push(int data)
        {
            // !isfull means when stack isnot empty see isFull function for more understanding
            if (isFull())
                cout << "Stack Overflow!\n";

            else 
            // here I'm also pre-incrementing top
                arr[++top] = data;
        }

        int pop()
        {
            if (isEmpty())
            {   
                cout << "Stack Underflow\n";
                // means return 32bit or 4bytes integer minimum value that it can hold
                return INT32_MIN;
            }
                
            else 
            {
                // store the topmost value
                int pop_value = arr[top];
                --top;// then decrement top

                /*
                 You maybe wondering what will happen to the actual place where top value is stored then answer is you simply don't need to care about it because once you do --top then we will display data only till top and when we push data then the old value will get overridden.
                */
                return pop_value;
            }
        }

        int count()
        {
            // top + 1 because if we have top = -1 then we will show that we have 0 items in stack and when we have top = 0 then output 1
            return top + 1;
        }
        // unsigned so that pos will always be greater than or equal to 0
        int peek(unsigned int pos)
        {   
            if (isEmpty())
            {
                cout << "Stack Underflow\n";
                return INT32_MIN;
            }

            else 
                return arr[pos];
        }

        //changing data at position in Stack
        void change(int pos, int data)
        {
            arr[pos] = data;
            cout << "Item changed at location " << pos << endl;
        }

        // display stack
        void display()
        {
            if (isEmpty())
            {
                cout << "Stack is empty\n";
                return;
            }
            else
            {
                // starting from top and then moving towards 0
                for (int i = top; i >= 0; --i)
                    cout << arr[i] << " ";
            }

            cout << endl;
            return;
        }
};

void menu()
{
    cout << "\nInput 0 for exit\nInput 1 for push\nInput 2 for pop\nInput 3 for peek\nInput 4 for count\nInput 5 for change\nInput 6 for display\nInput 7 for clear\n\nInput your choice: ";
}

int main()
{
    int n;
    int choice;// variable to store choice of user
    cout << "Size of Stack: ";
    cin >> n;

    Stack stack(n);

    do
    {
        int data;// to store data for change and push
        unsigned int position;// to store psotion for change and peek
        menu();
        cin >> choice;

        // switch case to check what user want
        switch(choice)
        {
            // case 0 because if it isnot available then default case will run
            case 0:
                break;
            case 1:
                cout << "Input data to be pushed: ";
                cin >> data;
                stack.push(data);
                break;

            case 2:
                cout << "Returned value after pop: " << stack.pop();
                break;

            case 3:
                
                cout << "Input position to peek: ";
                cin >> position;
                stack.peek(position);
                break;
            
            case 4:
                cout << "Number of elements in stack: " << stack.count();
                break;

            case 5:
                cout << "Input position for change: ";
                cin >> position;
                cout << "Input data for change: ";
                cin >> data;

                stack.change(position, data);
                break;

            case 6:
                stack.display();
                break;

            case 7:
                system("clear");// you can change it to cls for Windows
                break;

            default:
                cout << "Invalid input\n";
        }
        while (getchar() != '\n');
        getchar();
    }
    while (choice != 0);

    cout << "Stack ended\n";
} 

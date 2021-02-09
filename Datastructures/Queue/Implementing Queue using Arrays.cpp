// Implementing queues using arrays
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Queue
{
    private:
        int *arr;// pointer to dynamic array 
        int max;// the upper-bound of queues
        int front;
        int rear;

    public:
        Queue(int max)
        {
            this->max = max;
            arr = new int[max];// dynamically allocating the araay
            front = -1;
            rear = -1;

            // assigning all members of array as 0
            for (int i = 0; i < max; ++i)
                arr[i] = 0;
        }
        
        inline bool isFull()
        {
            if (rear ==  max - 1)
                return true;
            
            return false;
        }

        inline bool isEmpty()
        {
            return (rear == -1 && front == -1) ? true : false;
        }

        void enqueue(int data)
        {
            // when the queue is empty then I would make front and rear = 0 by incrementing both
            if (isEmpty())
            {
                arr[++rear] = data;
                ++front;    
                return;
            }

            // When it is full then Queue overflow
            else if (isFull())
            {
                cout << "\nQueue overflow\n";
                return;
            }
            // else rear += 1 assign data
            arr[++rear] = data;
        }

        // returns value that has been dequeued
        int dequeue()
        {
            if (isEmpty())
            {
                cout << "\nQueue underflow\n";
                return INT32_MIN;
            }
            
            int retur_n; // to store the value to be returned

            // This will true only when there is only one element left in array
            if (rear == front)// in other way if (rear == 0 && front == 0)
            {
                retur_n = arr[front];
                rear = front = -1;// assingning both -1 becuase now Queue is empty

                return retur_n;
            }

            // means there are more than 1 elements in array
            retur_n = arr[front];
            ++front;
            return retur_n;
        }

        int count()
        {
            // because of 0 based indexing
            return rear + 1;
        }

        void display()
        {
            if (rear == -1)
            {
                cout << "\nQueue is empty\n";
                return;
            }
            cout << "\nElements in array->\n";
            for (int i = front; i <= rear && i >= 0; ++i)
                cout << arr[i] << " ";

        }
};

void menu()
{
    cout << "\nInput 0 for exit\nInput 1 for enqueue\nInput 2 for deqeue\nInput 3 for isFull\nInput 4 for isEmpty\nInput 5 for count\nInput 6 for display\nInput 7 for clear screen\n\nInput your choice: ";
}

int main()
{
    int n;
    int choice;// variable to store choice of user
    cout << "Size of Queue: ";
    cin >> n;

    Queue queue(n);

    do
    {
        int data;// to store data for change and push
        menu();
        cin >> choice;

        // switch case to check what user want
        switch(choice)
        {
            // case 0 because if it isnot available then default case will run
            case 0:
                break;
            case 1:
                cout << "Input data to be enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;

            case 2:
                cout << "\nReturned value after dequeue: " << queue.dequeue();
                break;

            case 3:
                (queue.isFull() == true) ? cout << "\nQueue is full\n" : cout << "\nQueue isnot full\n";
                break;

            case 4:
                (queue.isEmpty() == true) ? cout << "\nQueue is empty\n" : cout << "\nQueue isnot empty\n";
                break;

            case 5:
                cout << "\nNumber of elements in queue: " << queue.count();
                break;

            case 6:
                queue.display();
                break;

            case 7:
                system("clear");// you can change it to cls for Windows
                break;

            default:
                cout << "\nInvalid input\n";
        }
        while (getchar() != '\n');
        getchar();
    }
    while (choice != 0);

    cout << "Queue ended\n";
}

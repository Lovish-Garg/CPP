// Implementing queues using linked-lists
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node
{
    public:
        int data;// to store the info
        Node *link; // to point to next location

        Node (int data)// contstructor so that when I dynamically allocate Node then it has got the that should be in it and I wouldnot need to assign the values in it in enqueue function 
        {
            this->data = data;
            link = NULL;
        }
};

class Queue
{
    private:
        Node *front;
        Node *rear;
        int count_times;// to count number of nodes

    public:
        Queue()
        {
            count_times = 0;

            front = NULL;
            rear = NULL;
        }

        inline bool isEmpty()
        {

            return (front == NULL) ? true : false;
        }

        void enqueue(int data)
        {
            // when the queue is empty then I would make front and rear = 0 by incrementing both
            if (isEmpty())
            {
                // here constructor will assign the node the value itself 
                // then rear = front because its first node in linked-list and front should also point to first too.
                rear = front = new Node(data);
                
                ++count_times;// increment

                return;
            }

            // else simply make new node and link with the rear
            Node *temp = new Node(data);
            
            // add new node at end and change rear position
            rear->link = temp;
            rear = temp;

            ++count_times;// increment
        }

        // returns value that has been dequeued
        int dequeue()
        {
            if (isEmpty())
            {
                cout << "\nQueue underflow\n";
                return INT32_MIN;
            }
            
            --count_times;// decrement

            int retur_n = front->data; // to store the value to be returned

            Node* temp_del = front;// because now we need to free the front element

            front = front->link;// then change front position

            
            if (front == NULL)// means there's dead end
            {
                rear = NULL;
            }

            delete temp_del;
            
            return retur_n;
        }

        int count()
        {
            return count_times;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "\nQueue is empty\n";
                return;
            }

            Node *iterate = front;

            cout << "\nElements in array->\n";
            while (iterate)
            {
                cout << iterate->data << " ";
                iterate = iterate->link;
            }

        }
};

void menu()
{
    cout << "\nInput 0 for exit\nInput 1 for enqueue\nInput 2 for deqeue\nInput 3 for isEmpty\nInput 4 for count\nInput 5 for display\nInput 6 for clear screen\n\nInput your choice: ";
}

int main()
{
    int choice;// variable to store choice of user

    Queue queue;

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
                (queue.isEmpty() == true) ? cout << "\nQueue is empty\n" : cout << "\nQueue isnot empty\n";
                break;

            case 4:
                cout << "\nNumber of elements in queue: " << queue.count();
                break;

            case 5:
                queue.display();
                break;            

            case 6:
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

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

class Node
{
    public:
        int key;// to uniquely identify each
        int data;// the actual data to be stored
        Node *link;// to point to next node

        Node(int data)
        {
            key = 0;
            this->data = data;
            link = NULL;
        }

        Node (int key, int data)
        {
            this->key = key;
            this->data = data;
            link = NULL;
        }
};

class Single_list
{
    private:
        Node *head;// the head node
        Node *tail;// to keep record of last Node, it will help in several operations

    public:
        // normal constructor
        Single_list()
        {
            head = NULL;
            tail  = NULL;
        }

        // to check if the node of a key exists 
        Node *nodeExists(int key)
        {
            
            Node *traverse = head;
            Node *temp = NULL;

            while (traverse)
            {
                // if we found the node with that specific key
                if (traverse->key == key)
                {
                    temp = traverse;
                    break;
                }

                traverse = traverse->link;
            }
            return temp;
        }

        void appendNode(int key, int data)
        {
            // if Node exists with same key
            if (nodeExists(key))
            {
                cout << "Same Keys Not Allowed\n";
                return;
            }
            
            // if list is empty 
            if (head == NULL)
            {
                Node *newNode = new Node(key, data);

                // linking newNode with head and then last ptr assign head because we also need to maintain last ptr
                head = newNode;
                tail = head;
                cout << "Node Appended\n";
                
                return;
            }
            
            // else
            Node *newNode = new Node(key, data);

            tail->link = newNode;
            tail = newNode;

            cout << "Node Appended\n";
        }

        // insert a Node at head
        void prependNode(int key, int data)
        {
            // if Node exists with same key
            if (nodeExists(key))
            {
                cout << "Same Keys Not Allowed\n";
                return;
            }
            
            // else
            Node *newNode = new Node(key, data);

            // if list was empty then also change the tail pointer
            if (head == NULL)
                tail = NULL;

            newNode->link = head;
            head = newNode;

            cout << "Node Prepended\n";
        }

        // insert a node after a node of specific value
        void insertNodeAfter(int search, int key, int data)
        {
            // here if the key exists then it will return that Node 
            Node *ptr = nodeExists(search);
            
            // if ptr == NULL
            if (!ptr)
            {
                cout << "Key doesnot exist\n";
                return;
            }
            
            Node *newNode = new Node(key, data);
            //here I'm first making the Node to point at where ptrr points and then making ptr pointing to newNode
            newNode->link = ptr->link;
            ptr->link = newNode;

            // if newNode is the last Node in the list
            if (newNode->link == NULL)
                tail = newNode;

            cout << "Node inserted\n";
        }

        void deleteNodeByKey(int key)
        {
            // if head == NULL
            if (!head)
            {
                cout << "List is already empty\n";
                return;
            }

            // if head itslef contains the Node with the key
            if (head->key == key)
            {
                Node *del = head;
                head = head->link;
                cout << "Node with Key " << key  << " is deleted\n";

                // means the node we are deleting was the last then tail = NULL
                if (tail == del)
                    tail = NULL;

                delete del;
                return;
            }

            // if list has only one Node then We had already delete the Node head if it had the key but if the below is true this means the key is invalid
            if (head->link == NULL)
            {
                cout << "Invalid Key to delete Node\n";
                // then return
                return;
            }

            // else
            Node *del = NULL;// to store address to be deleted
            Node *prevptr = head;// to store the previous Node
            Node *currentptr = head->link;// to store the next of previous

            while (currentptr)
            {   
                if (currentptr->key == key)
                {
                    del = currentptr;
                    break;
                }

                prevptr = currentptr;
                currentptr = currentptr->link;
            }

            // if key not found
            if (!del)
            {
                cout << "Invalid Key to delete Node\n";
                return;
            }
            // means if I'm deleting the last Node
            if (del == tail)
                tail = prevptr;

            prevptr->link = del->link;

            delete del;

            cout << "Node with Key " << key << " is deleted\n";
        }

        // to update Node of a specific key
        void updateNodeByKey(int key, int data)
        {  
            Node *update = nodeExists(key);

            // this will be true when update have NULL means keynot found
            if (!update)
                cout << "Invalid Key to update Node\n";

            else
            {
                update->data = data;

                cout << "Node with Key " << key  << " is updated\n";
            }
                
        }

        void display()
        {
            // if head == NULL
            if (!head)
            {
                cout << "List is Empty\n";
                return;
            }

            Node *traverse = head;

            while (traverse)
            {
                cout << traverse->data << " "; 
                traverse = traverse->link;
            }
        }

        // to free the memory allocated during execution of various operations
        ~Single_list()
        {  
            Node *del = NULL, *traverse = head;

            while (traverse)
            {
                del = traverse;
                traverse = traverse->link;
                
                delete del;
            }
        }
};

void menu()
{
    cout << "Input 0 for Exit\nInput 1 for Appending\nInput 2 for Prepending\nInput 3 for Inserting Node after a Key\nInput 4 to Check if a Node Exists with Specific Key\nInput 5 to Delete a Node by Key\nInput 6 to Update Node by Key\nInput 7 to display\nInput 8 for clear screen\n\nInput your choice: ";
}

int main(void)
{
    int choice;

    Single_list list;// 
    do 
    {
        menu();
        int key;// to store key to pass as argument for operations
        int data;// to store actual data to be passsed
        cin >> choice;

        switch(choice)
        {  
            // just break
            case 0:
                break;
            case 1:
                cout << "\nKey: ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.appendNode(key, data);
                break;

            case 2:
                cout << "\nKey: ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.prependNode(key, data);
                break;

            case 3:
                int key2;// to store key for Node to be search  

                cout << "\nKey(to insert after): ";
                cin >> key2;

                cout << "\nKey(for Node): ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.insertNodeAfter(key2, key, data);
                break;

            case 4:
                cout << "\nKey: ";
                cin >> key;

                if (list.nodeExists(key))
                    cout << "\nNode founded\n";
                
                else 
                    cout << "\nNode not Found\n";
                break;

            case 5:
                cout << "\nKey: ";
                cin >> key;

                list.deleteNodeByKey(key);
                break;

            case 6:
                cout << "Key: ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.updateNodeByKey(key, data);
                break;

            case 7:
                list.display();
                break;
            
            case 8:
                system("clear");// do cls for windows
                break;
                
            default:
                cout << "\nInvalid Choice\n";
        }
        // clearing buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getchar();
    }
    while (choice != 0);

    cout << "Linked-List ended\n";
}

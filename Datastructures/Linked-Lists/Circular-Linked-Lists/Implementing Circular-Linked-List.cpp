// Program to implement CLL (Circular Linked List) and its standard operations
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::numeric_limits;

class Node
{
    public:
        int data;
        Node *link;// to link all Nodes together
        int key;// to uniquely identifuy each Node

        Node (int key, int data)
        {
            this->data = data;
            link = NULL;
            this->key = key;
        }
};

class Circular_List
{
    private:
        Node *head;// starting point of CLL
        Node *tail;// to maintain record of last Node and to perform operations

    public:
        Circular_List ()
        {
            head = NULL;
            tail = NULL;
        }
        Node *nodeExists(int key)
        {
            Node *traverse = head;
            Node *exist = NULL;// this will contain a valid address when a Node exists of a key

            // if list is empty
            if (!traverse)
                return NULL;

            do
            {
                if (traverse->key == key)
                {
                    exist = traverse;
                    break;
                }
                traverse = traverse->link;
            }
            while (traverse != head);

            return exist;
        }

        void appendNode(int key, int data)
        {
            // if there is a same key available then return
            if (nodeExists(key))
            {
                cout << "Same Keys are not allowed\n";
                return;
            }
            // if list is empty 
            if (head == NULL)
            {
                Node *newNode = new Node(key, data);

                // linking newNode with head and then last ptr assign head because we also need to maintain last ptr
                head = newNode;
                newNode->link = head;
                tail = newNode;

                cout << "Node Appended\n";
                
                return;
            }
            
            // else
            Node *newNode = new Node(key, data);

            tail->link = newNode;
            newNode->link = head;
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

            Node *newNode = new Node(key, data);

            // if list is empty
            if (head == NULL)
            {
                head = newNode;
                newNode->link = head;
                tail = newNode;
            }
            else
            {
                newNode->link = head;
                head = newNode;
                tail->link = newNode;
            }
            
            cout << "Node Prepended\n";
        }

        // insert a node after a node of specific value
        void insertNodeAfter(int search, int key, int data)
        {
            // if key is found then return
            if (nodeExists(key))
            {
                cout << "Same Keys Not Allowed\n";
                return;
            }
            // here if the key exists then it will return that Node 
            Node *ptr = nodeExists(search);
            
            // if ptr == NULL
            if (!ptr)
            {
                cout << "Key doesnot exist\n";
                return;
            }
            
            Node *newNode = new Node(key, data);
            
            // if ptr was the Last Node
            if (ptr->link == NULL)
            {
                newNode->link = ptr->link;
                ptr->link = newNode;
                tail = newNode;
            }
            else
            {
                newNode->link = ptr->link;
                ptr->link = newNode;
            }

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
            
            // if we are deleting the last Node of the list
            if (del == tail)
            {
                prevptr->link = head;
                tail = prevptr;
            }
            else 
            {
                prevptr->link = del->link;
            }

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

            do
            {
                cout << traverse->data << " ";
                traverse = traverse->link;
            }
            
            while (traverse != head);
            
            cout << endl;
        }

        // to free the memory allocated during execution of various operations
        ~Circular_List()
        {  
            Node *del = NULL, *traverse = head;
            // traverse == NULL
            if (!traverse)
                return;
            
            do
            {
                del = traverse;
                traverse = traverse->link;
            }
            while (traverse->link != head);

            delete traverse;
        }
};

void menu()
{
    cout << "Input 0 for Exit\nInput 1 for Appending\nInput 2 for Prepending\nInput 3 for Inserting Node after a Key\nInput 4 to Check if a Node Exists with Specific Key\nInput 5 to Delete a Node by Key\nInput 6 to Update Node by Key\nInput 7 to display\nInput 8 for clear screen\n\nInput your choice: ";
}

int main(void)
{
    int choice;

    Circular_List list;// 
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

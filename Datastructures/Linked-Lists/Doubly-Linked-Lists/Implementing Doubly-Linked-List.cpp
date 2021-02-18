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
        Node* next;// also be called as next
        Node* prev;// also be called as prev

        Node(int data)
        {
            key = 0;
            this->data = data;
            next = NULL;
            prev = NULL;
        }

        Node (int key, int data)
        {
            this->key = key;
            this->data = data;
            next = NULL;
            prev = NULL;
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

                traverse = traverse->next;
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

            tail->next = newNode;
            newNode->prev = tail;
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

            // if the list was empty
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;

                return;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            cout << "Node Prepended\n";
        }

        // insert a node after a node of specific value
        void insertNodeAfter(int search, int key, int data)
        {
            // if key exists
            if (nodeExists(key))
            {
                cout << "Same Keys Not Allowed\n";
                return;
            }
            // here if the search key exists then it will return that Node 
            Node *ptr = nodeExists(search);
            
            // if ptr == NULL
            if (!ptr)
            {
                cout << "Key doesnot exist\n";
                return;
            }
            
            Node *newNode = new Node(key, data);
            //here I'm first making the Node to point at where ptrr points and then making ptr pointing to newNode
            newNode->next = ptr->next;
            newNode->prev = ptr;
            ptr->next = newNode;

            // if the next node isnot NULL
            if (ptr->next)
                ptr->next->prev = newNode;

            else// means that it was the last node
                tail = newNode;

            cout << "Node inserted\n";
        }

        void insertNodeBefore(int search, int key, int data)
        {
            // if key exists
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
            
            // if ptr is head or we are going to insert node to head
            if (ptr == head)
            {
                newNode->next = head;
                ptr->prev = newNode;
                head = newNode;
            }
            else
            {
                newNode->next = ptr;
                ptr->prev = newNode;
                ptr->prev->next = newNode;
            }
            cout << "Node inserted\n";
        }

        void deleteNodeByKey(int key)
        {
            Node *del = nodeExists(key);

            if (!del)
            {
                cout << "Invalid Key\n";
                return;
            }

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
            
                // head == NULL
                if (!head->next)
                {
                    tail = NULL;
                    head = NULL;

                    delete del;
                }
                else
                {
                    head = head->next;
                    head->prev = NULL;
                    delete del;
                }

                cout << "Node with Key " << key  << " is deleted\n";
                return;
            }

            // if list has only one Node then We had already delete the Node head if it had the key but if the below is true this means the key is invalid
            if (head->next == NULL)
            {
                cout << "Invalid Key to delete Node\n";
                // then return
                return;
            }
            else
            {
                Node *nextNode = del->next;
                Node *prevNode = del->prev;

                if (nextNode == NULL)
                {
                    tail = prevNode;
                    prevNode->next = NULL;
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                }

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

            while (traverse)
            {
                cout << traverse->data << " "; 
                traverse = traverse->next;
            }
        }

        // to free the memory allocated during execution of various operations
        ~Single_list()
        {  
            Node *del = NULL, *traverse = head;

            while (traverse)
            {
                del = traverse;
                traverse = traverse->next;
                
                delete del;
            }
        }
};

void menu()
{
    cout << "Input 0 for Exit\nInput 1 for Appending\nInput 2 for Prepending\nInput 3 for Inserting Node after a Key\nInput 4 for Inserting Node before a Key\nInput 5 to Check if a Node Exists with Specific Key\nInput 6 to Delete a Node by Key\nInput 7 to Update Node by Key\nInput 8 to display\nInput 9 for clear screen\n\nInput your choice: ";
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
                cout << "\nKey(to insert before): ";
                cin >> key2;

                cout << "\nKey(for Node): ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.insertNodeBefore(key2, key, data);
                break;

            case 5:
                cout << "\nKey: ";
                cin >> key;

                if (list.nodeExists(key))
                    cout << "\nNode founded\n";
                
                else 
                    cout << "\nNode not Found\n";
                break;

            case 6:
                cout << "\nKey: ";
                cin >> key;

                list.deleteNodeByKey(key);
                break;

            case 7:
                cout << "Key: ";
                cin >> key;

                cout << "Data: ";
                cin >> data;

                list.updateNodeByKey(key, data);
                break;

            case 8:
                list.display();
                break;
            
            case 9:
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

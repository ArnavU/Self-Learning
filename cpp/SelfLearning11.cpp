#include <iostream>
using namespace std;

class LinkedList;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void add_first(int data)
    {
        Node *newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    void add_last(int data)
    {
        Node *newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    
    void display()
    {
        Node *temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};


int main()
{
    LinkedList list;

    list.add_first(20);
    list.add_first(10);

    list.add_last(30);
    list.add_last(40);

    list.display();

    return 0;
}
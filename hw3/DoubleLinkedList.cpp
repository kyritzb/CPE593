#include <iostream>

using namespace std;

class DoubleLinkedList2
{

private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node()
        {
            data = 0;
            next = nullptr;
            prev = nullptr;
        }
        Node(int newData)
        {
            data = newData;
            next = nullptr;
            prev = nullptr;
        }
    };

public:
    Node *head;
    Node *tail;

    DoubleLinkedList2()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addEnd(int data)
    {
        Node *node = new Node(data);
        if (tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else if (tail->next == nullptr)
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void addStart(int data)
    {
        Node *node = new Node(data);
        Node *tmp = head;
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
            node->next->prev = node;
        }
    }

    void removeEnd()
    {
        cout << "removing end" << endl;
        Node *newTail = tail->prev;
        newTail->next = nullptr;
        tail = newTail;
        cout << "done" << endl;
    }

    void print()
    {
        Node *curNode = head;
        cout << "--------------------" << endl;
        while (curNode != nullptr)
        {
            cout << curNode->data << "-->";
            curNode = curNode->next;
        }
        cout << endl
             << "--------------------" << endl;
    }

    void printReverse()
    {
        Node *curNode = tail;
        cout << "---------reverse-------" << endl;
        while (curNode != nullptr)
        {
            cout << curNode->data << "-->";
            curNode = curNode->prev;
        }
        cout << endl
             << "--------------------" << endl;
    }

    int size()
    {
        int count = 0;
        Node *curNode = head;
        while (curNode != nullptr)
        {
            count++;
            curNode = curNode->next;
        }
        return count;
    }
};

int main()
{
    DoubleLinkedList2 mylist;

    for (int i = 0; i < 10; i++)
        mylist.addEnd(i);
    for (int i = 0; i < 10; i++)
        mylist.addStart(i);
    for (int i = 0; i < 5; i++)
        mylist.removeEnd();

    cout << "List size:" << mylist.size() << endl;
    mylist.print();
    //added reverse print to show the link is traversable backwards as well as forwards.
    mylist.printReverse();
}
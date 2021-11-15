#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    string data;
    node *next;
};

class LinkedList
{
private:
    node *head, *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add_node(string n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = nullptr;

        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display()
    {
        node *current = head;

        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    bool has(string search)
    {
        node *current = head;

        while (current != nullptr)
        {
            if (current->data == search)
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }
};

class HashMap
{

    //array of linkedLists
    LinkedList **arr;
    int capacity;
    // current size
    int size;

private:
    void buildDictionary(string dictionaryFile)
    {
        ifstream is(dictionaryFile);
        string line;

        while (getline(is, line))
        {
            insertWord(line);
        }
    }

public:
    HashMap(string dictionaryFile)
    {
        cout << "Created new dictionary with " << dictionaryFile << endl;
        // Initial capacity of hash array
        capacity = 30;
        size = 0;
        //array of buckets
        arr = new LinkedList *[capacity];

        for (int i = 0; i < capacity; i++)
            arr[i] = new LinkedList();

        buildDictionary(dictionaryFile);
    }
    // This implements hash function to find index
    // for a key
    int hashCode(string key)
    {
        //return key % capacity;
        int hashed = (int)key.length();

        return hashed;
    }

    void insertWord(string newWord)
    {
        int hashIndex = hashCode(newWord);
        LinkedList *list = arr[hashIndex];
        list->add_node(newWord);
    }

    bool isWord(string word)
    {
        int hashIndex = hashCode(word);
        LinkedList *list = arr[hashIndex];
        return list->has(word);
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "--------Linked List #" << i + 1 << "--------" << endl;
            LinkedList *list = arr[i];
            list->display();
        }
    }
};

int main()
{
    cout << "running" << endl;
    HashMap dict("dict.txt");
    int choice;
    while (choice != 0)
    {
        cout << "-----------------------------" << endl;
        cout << "HashMap with linear chaining" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) Finish" << endl;
        cout << "1) Test Word" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter word: ";
            string word;
            cin >> word;
            bool isWord = dict.isWord(word);
            if (isWord)
            {
                cout << word << " is a word!" << endl;
            }
            else
            {
                cout << word << " is not a word!" << endl;
            }
        }
    }
    choice = 1;
    while (choice != 0)
    {
        cout << "-----------------------------" << endl;
        cout << "             Trie            " << endl;
        cout << "-----------------------------" << endl;
        cout << "0) Finish" << endl;
        cout << "1) Test Word" << endl;
        cout << "2) Starts with" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter word: ";
            string word;
            cin >> word;
            bool isWord = dict.isWord(word);
            if (isWord)
            {
                cout << word << " is a word!" << endl;
            }
            else
            {
                cout << word << " is not a word!" << endl;
            }
        }
    }
    return 0;
}
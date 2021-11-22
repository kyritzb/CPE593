#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class LinkedList
{
private:
    struct node
    {
        string data;
        node *next;
    };

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

//can change the type of data in the array
template <class K>
class DynArray
{
private:
    K *data;           //dynamic array of whatever type is entered when creating the dynamic array
    uint32_t capacity; // how big the array is (everytime you run out of space, double it)
    uint32_t len;      // how many are used

public:
    DynArray()
    {
        data = new K[10]; //initial capacity is set to 10
        capacity = 10;    //initial capacity is set to 10
        len = 0;
    }

    void add(K newNode)
    {
        checkGrow();
        data[len] = newNode;
        len++;
    }

    int size()
    {
        return len;
    }

    K get(int index)
    {
        return data[index];
    }

    void print()
    {
        for (int i = 0; i < len; i++)
        {
            cout << data[i] << ",";
        }
        cout << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Length: " << len << endl;
    }

    //if the array is full, double in size
    void checkGrow()
    {
        if (len == capacity)
        {
            int newCapacity = capacity * 2;
            capacity = newCapacity;
            //copy contents
            K *newData = new K[newCapacity];
            for (int i = 0; i < len; i++)
            {
                newData[i] = data[i];
            }
            //switch new array with old one
            data = newData;
        }
    }
};

class Trie
{

private:
    class TrieNode
    {
    private:
        DynArray<TrieNode *> *children; //an array nodes
    public:
        char data;

        TrieNode(char newData)
        {
            data = newData;
            DynArray<TrieNode *> *newArray = new DynArray<TrieNode *>();
            children = newArray;
        }
        bool hasChild(char searchValue)
        {
            for (int i = 0; i < children->size(); i++)
            {
                TrieNode *curNode = children->get(i);

                char curChar = curNode->data;

                if (curChar == searchValue)
                {
                    return true;
                }
            }

            return false;
        }
        TrieNode *getChild(char searchValue)
        {
            for (int i = 0; i < children->size(); i++)
            {
                TrieNode *curNode = children->get(i);

                //   cout << "curNode:" << curNode->data << endl;

                char curChar = curNode->data;

                if (curChar == searchValue)
                {
                    return curNode;
                }
            }
            return nullptr;
        }

        int childrenSize()
        {
            return children->size();
        }

        TrieNode *getChild(int index)
        {
            if (index >= 0 && index < children->size())
            {
                return children->get(index);
            }
            else
            {
                return nullptr;
            }
        }

        void addChild(char data)
        {
            TrieNode *temp = new TrieNode(data);
            children->add(temp);
        }
        void print()
        {
            cout << "----------------" << endl;
            cout << "data: " << data << endl;
            cout << "Children:" << endl;
            children->print();
            cout << "----------------" << endl;
        }
    };
    void buildDictionary(string dictionaryFile)
    {
        ifstream is(dictionaryFile);
        string line;

        while (getline(is, line))
        {
            insertWord(line);
        }
    }
    TrieNode *getTailNode(string word)
    {
        TrieNode *currentNode = head; //start at head

        int n = word.length();
        char char_array[n + 1];
        strcpy(char_array, word.c_str());

        int depth = 0;
        string result = "";
        char currentLetter = char_array[depth];

        while (currentNode->hasChild(currentLetter))
        {

            // cout
            //    << "current letter =" << currentLetter << endl;
            result.push_back(currentLetter);
            //traverse
            currentNode = currentNode->getChild(currentLetter);
            //  cout << "new head is:" << endl;
            //  currentNode->print();
            depth++;
            currentLetter = char_array[depth];
        }
        return currentNode;
    }

    //backtracking function
    void printCombos(string curString, TrieNode *curNode)
    {

        //base case
        if (curNode->hasChild('*'))
        {
            cout << curString << endl;
        }
        if (curNode->childrenSize() >= 1)
        {
            int childrenCount = curNode->childrenSize();
            // cout << "childrenCount: " << childrenCount << endl;
            for (int i = 0; i < childrenCount; i++)
            {
                TrieNode *newLayer = curNode->getChild(i);
                char curLetter = newLayer->data;
                // cout << "curLetter:" << curLetter << endl;
                string newWord = curString + curLetter;
                printCombos(newWord, newLayer);
            }
        }
    }

public:
    TrieNode *head;
    Trie(string dictionaryFile)
    {
        char emptyChar = (char)0;
        TrieNode *temp = new TrieNode(emptyChar);
        head = temp;
        buildDictionary(dictionaryFile);
    }

    bool isWord(string word)
    {
        TrieNode *currentNode = head; //start at head

        int n = word.length();
        char char_array[n + 1];
        strcpy(char_array, word.c_str());

        int depth = 0;
        string result = "";
        char currentLetter = char_array[depth];

        while (currentNode->hasChild(currentLetter))
        {

            // cout
            //    << "current letter =" << currentLetter << endl;
            result.push_back(currentLetter);
            //traverse
            currentNode = currentNode->getChild(currentLetter);
            //  cout << "new head is:" << endl;
            //  currentNode->print();
            depth++;
            currentLetter = char_array[depth];
        }
        //makes it so if you put the word "hello"
        //hell doesnt get picked up as an added word because it doesnt have child '*'
        if (result == word && currentNode->hasChild('*'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void startsWith(string word)
    {
        TrieNode *currentNode = getTailNode(word); //start at head
        printCombos(word, currentNode);
    }

    void
    insertWord(string newWord)
    {

        TrieNode *currentNode = head; //start at head

        int n = newWord.length();
        // declaring character array
        char char_array[n + 1];
        // copying the contents of the
        // string to char array
        strcpy(char_array, newWord.c_str());

        //place letters in tree
        for (int i = 0; i < n; i++)
        {
            char curLetter = char_array[i];
            //cout << "Placing the letter:" << curLetter << endl;

            bool hasLetter = currentNode->hasChild(curLetter);

            //bool hasLetter = false;

            if (hasLetter)
            {
                currentNode = currentNode->getChild(curLetter);
            }
            else
            {
                currentNode->addChild(curLetter);
                // cout << "added the letter!" << endl;
                currentNode = currentNode->getChild(curLetter);
                //add new node and traverse
            }
            //currentNode->print();
        }
        currentNode->addChild('*');
    }
};

int main()
{
    HashMap dict("dict.txt");
    Trie tree("dict.txt");

    int choice = 1;
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
        else if (choice == 2)
        {
            cout << "Enter word: ";
            string word;
            cin >> word;
            cout << "These are all the words that start with \" " << word << "\"";
            tree.startsWith(word);
        }
    }

    return 0;
}
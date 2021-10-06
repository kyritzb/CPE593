//Bryan Kyritz
//I Pledge my honor that I have abided by the stevens honor system

#include <iostream>
#include <cstdint>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Use the compaction algorithm to efficiently remove all the values (Do not remove a position and shift to the left, too expensive!)
//The inputs can be quite large.  We might assign n=106. or 107.  There might be 20 or 40 or even 100 numbers to remove.  Your program will have to run in less than 30 seconds.

class DynArray
{
private:
    int *data;
    uint32_t capacity; // how big the array is (everytime you run out of space, double it)
    uint32_t len;      // how many are used

public:
    DynArray(uint32_t initialCapacity)
    {
        data = new int[initialCapacity];
        capacity = initialCapacity;
        len = 0;
    }

    void addEnd(int number)
    {
        checkGrow();
        data[len] = number;
        len++;
    }

    void addStart(int number)
    {
        checkGrow();
        for (int i = len + 1; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = number;
        len++;
    }

    void removeEnd()
    {
        data[len] = 0;
        len--;
    }

    int size()
    {
        return len;
    }

    void removeStart()
    {
        for (int i = 0; i < len; i++)
        {
            data[i] = data[i + 1];
        }
        len--;
    }

    void removeIndex(int index)
    {
        for (int i = index; i < len; i++)
        {
            data[i] = data[i + 1];
        }
        len--;
    }

    void removeAllAfter(int index)
    {
        int originalLen = len;
        for (int i = index; i < originalLen; i++)
        {
            data[i] = 0;
            len--;
        }
    }

    int get(int index)
    {
        return data[index];
    }

    void set(int index, int value)
    {
        data[index] = value;
    }

    void print()
    {
        cout << "Data: " << endl;
        for (int i = 0; i < len; i++)
        {
            cout << data[i] << ",";
        }
        cout << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Length: " << len << endl;
    }

    void removeMultiples(int *numsToFollow, int size)
    {
        for (int m = 0; m < size; m++)
        {
            int curMultiple = numsToFollow[m];
            int j = 0;
            for (int i = 0; i < len; i++)
            {
                if (data[i] % curMultiple != 0)
                {
                    data[j++] = data[i];
                }
            }
            removeAllAfter(j);
        }
    }

    int sum()
    {
        int total = 0;
        for (int i = 0; i < len; i++)
        {
            total += data[i];
        }
        return total;
    }

    //if the array is full, double in size
    void checkGrow()
    {
        if (len == capacity)
        {
            int newCapacity = capacity * 2;
            capacity = newCapacity;
            //copy contents
            int *newData = new int[newCapacity];
            for (int i = 0; i < len; i++)
            {
                newData[i] = data[i];
            }
            //switch new array with old one
            data = newData;
        }
    }
};

int main()
{
    uint32_t start = 0;
    uint32_t end = 0;
    int numsToFollow = 0;
    uint32_t range = 0;
    int *multiplesToRemove;

    cout << "Enter Start Number: ";
    cin >> start;

    cout << "Enter End Number: ";
    cin >> end;

    cout << "Enter Amount of Numbers to Follow: ";
    cin >> numsToFollow;

    range = (end - start) * 2;

    DynArray arr(15);

    for (int i = start; i <= end; i++)
    {
        arr.addEnd(i);
    }

    multiplesToRemove = new int[numsToFollow];

    cout << "Enter Numbers To Follow" << endl;

    for (int i = 0; i < numsToFollow; i++)
    {
        int num = 0;
        cout << i + 1 << ") ";
        cin >> num;
        multiplesToRemove[i] = num;
    }

    cout << "----------------" << endl;

    auto startTime = high_resolution_clock::now();
    arr.removeMultiples(multiplesToRemove, numsToFollow);
    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "--------------" << endl;
    cout << "Length: " << arr.size() << endl;
    cout << "Sum: " << arr.sum() << endl;
    cout << "Function duration: " << duration.count() << " microseconds" << endl;
    cout << "--------------" << endl;

    arr.print();

    return 0;
}

#include <iostream>
#include <list>

using namespace std;

class HashMapTable
{
    // size of the hash table
    int table_size;
    // pointer to the array containing keys
    list<int> *table;

public:
    // creating constructor containing all methods
    HashMapTable(int key);
    // hash function to compute the index using table_size and key
    int hashFunction(int key)
    {
        return (key % table_size);
    }
    // inserting the key in the hash table
    void insertElement(int key);
    // deleting the key in the hash table
    void deleteElement(int key);
    // displaying the full hash table
    void displayHashTable();
    // retrieve the index of a given key
    int getPosition(int key);
};

// creating the hash table with given table size ts
HashMapTable::HashMapTable(int ts)
{
    this->table_size = ts;
    table = new list<int>[table_size];
}

// insert function to push the keys in the hash table
void HashMapTable::insertElement(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

// delete function to delete the element from the hash table
void HashMapTable::deleteElement(int key)
{
    int index = hashFunction(key);
    // finding the key at the computed index
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            break;
        }
    }
    // removing the key from hash table if found
    if (i != table[index].end())
    {
        table[index].erase(i);
    }
}

// display function of the hash table
void HashMapTable::displayHashTable()
{
    for (int i = 0; i < table_size; i++)
    {
        cout << i;
        // traversing at recent/current index
        for (auto j : table[i])
        {
            cout << " ==> " << j;
        }
        cout << endl;
    }
}

// retrieve the index of a given key
int HashMapTable::getPosition(int key)
{
    // int idx = -1;
    // for (int i = 0; i < table_size; i++)
    // {
    //     for (auto j : table[i])
    //     {
    //         if (j == key)
    //         {
    //             idx = i;
    //         }
    //     }
    // }
    // if(idx != -1) {
    //     return idx;
    // } else {
    //     cout << "No valid element" << endl;
    //     return -1;
    // }
    int index = hashFunction(key);
    return index;
}

// Main function
int main()
{
    int arr[] = {20, 34, 56, 54, 76, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "debug: " << sizeof(arr) << " " << sizeof(arr[0]) << endl;
    //  hash table of table_size 6
    HashMapTable ht(6);
    // filling hash table table
    for (int i = 0; i < n; i++)
    {
        ht.insertElement(arr[i]);
    }
    // deleting the element 34 from the hash table
    ht.deleteElement(34);
    // displaying the final data of the hash table
    ht.displayHashTable();
    // retrieve the index of a given key 76
    cout << ht.getPosition(20);

    return 0;
}

/*
    Output:
                0 ==> 54
                1
                2 ==> 20 ==> 56
                3 ==> 87
                4 ==> 76
                5

    Explanation:
        In the above code, an array is created for all
        the keys that need to be inserted in the has table.
        Class and constructors are created for hashMapTable
        to calculate the hash function using the formula mentioned above.
        The list is created as the pointer to the array of key values.
        Specific functions are created for the insertion, deletion, and
        display of the hash table and called from the main method.
        While insertion, if 2 or more elements have the same index,
        they are inserted using the list one after the other.
*/
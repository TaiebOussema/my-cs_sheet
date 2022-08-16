#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// insert, search, remove, display

struct Node
{
    int data;
    Node *next;
};

class SinglyLinkedList
{
    // head pointer
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    };
    // insert element at the start of the list
    void insertElement(int data)
    {
        // make a new node
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        // if the list is empty, make the new node the head node
        if (head == nullptr)
        {
            head = new_node;
        }
        // else make the new node the head the its next is the
        // previous head
        else
        {
            Node *temp = head;
            head = new_node;
            new_node->next = temp;
        }
    };
    void removeElement(int data)
    {
        // if the head to be deleted
        if (head->data == data)
        {
            delete head;
            head = nullptr;
            return;
        }
        // if there is only one element in the list
        if (head->next == nullptr)
        {
            // if the head is to be deleted
            if (head->data == data)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                std::cout << "Value not found!" << endl;
            }
        }
        // else loop the list to find element to delete
        Node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next->data == data)
            {
                Node *temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            }
            temp = temp->next;
        }
    }
    bool searchElement(int data)
    {
        Node *temp = head;
        bool output = false;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                output = true;
            }
            temp = temp->next;
        }
        return output;
    }
    void display() {
        Node* temp;
        while(temp != nullptr) {
            std::cout<< temp->data << " " << endl;
            temp = temp->next;
        }
        cout << endl;
    }

};


int main()
{
    SinglyLinkedList list;
    list.insertElement(6);
    list.insertElement(9);
    list.insertElement(1);
    list.insertElement(7);
    list.display();
    return 0;
}

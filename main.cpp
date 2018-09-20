#include <iostream>
#include <sstream>
#include <regex>
#include <iterator>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node
{
    string value;
    Node *next;
};

class LinkedList
{

  public:
    Node *head;
    int listLength;
    Node *prevNode;

    Node *insert(int index, string text)
    {

        if (index < 0 || index > listLength)
        { // for invalid index
            // TODO: remove
            throw "index out of range";
        }

        Node *newNode = new Node();
        newNode->value = text;
        if (index == 0)
        {
            //insert at beginning of list
            if (head != NULL) { newNode->next = head; }
            head = newNode;
            listLength++;
        }

        // insert past index 0
        if (index > 0) { //TODO: change to else?
            newNode = prevNode->next;
            newNode->next = prevNode->next->next;
            prevNode->next = newNode;
            head = newNode;
        }
        return head;
    }

    void remove(int index)
    {
    }

    Node *search(string text)
    {
        return nullptr;
    }

    LinkedList(vector<string> vecStrs)
    {
        if (vecStrs.size() == 0) { return; } //if empty list

        Node *localHead = new Node();
        localHead->value = vecStrs[0];

        Node *prevNode = localHead;

        for (int i = 1; i < vecStrs.size(); i++)
        {
            Node *currentNode = new Node();
            prevNode->next = currentNode;
            currentNode->value = vecStrs[i];
            prevNode = currentNode;
        }

        head = localHead;
        listLength = vecStrs.size(); //remember to update when you delete nodes
    }

    friend ostream &operator<<(ostream &os, const LinkedList &list)
    {
        auto currentNode = list.head;
        //os << "list length: " << list.listLength << endl;
        for (int i = 0; i < list.listLength; i++)
        {
            os << currentNode->value << endl;
            currentNode = currentNode->next;
        }

        return os;
    }
};

class Editor 
{
    public:
        LinkedList *ll;

        void insertEnd(string text) {
            ll->insert(ll->listLength, text);
        }

        void insertAt(int index, string text) {
            ll->insert(index, text);
        }
};

void tests()
{
    vector<string> strs = {};
    LinkedList *l = new LinkedList(strs);
    l->insert(0, string("Aa"));
    l->insert(0,string("Bb"));
    l->insert(0,string("Cc"));
    cout << (*l);

    l->insert(1,string("Dd"));
    cout << (*l);

    /*strs = {"max is great"};
    l = new LinkedList(strs);
    l->insert(0, string("madeline is great"));
    cout << (*l);*/ 

    // strs = {"max is great"};
    // l = new LinkedList(strs);
    // l->insert(-1, string("madeline is great"));
    // cout << (*l);

    // strs = {"max is great"};
    // l = new LinkedList(strs);
    // l->insert(10, string("madeline is great"));
    // cout << (*l);
}

int main()
{
    tests();
    return 0;
}
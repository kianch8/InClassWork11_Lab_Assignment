#include <iostream>
#include <memory>
#include <string>
using namespace std;

// =========================================
// PART A: Manual Memory Management
// =========================================

struct ListNode 
{
    int id;
    string name;
    ListNode* next;
};

class NodeList 
{
private:
    ListNode* head;
    int count;

    // Private helper function
    void clear()
    {
        ListNode* curr = head;
        while (curr)
        {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;
        count = 0;
    }

public:
    NodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) 
    {
        ListNode* n = new ListNode{id, name, head};
        head = n;
        count++;
    }

    void removeNode(int id) 
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->id != id) 
        {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return;
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        cout << "Deleted node id: " << curr->id << endl;
        count--;
    }

    void display() const 
    {
        ListNode* curr = head;
        while (curr) 
        {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next;
        }

        cout << "null" << endl;
    }

    // Copy Constructor
    NodeList(const NodeList& other) : head(nullptr), count(0)
    {
        if (!other.head) return;

        // First node
        head = new ListNode{other.head->id, other.head->name, nullptr};
        ListNode* currNew = head;
        ListNode* currOther = other.head->next;

        // Other nodes
        while (currOther)
        {
            currNew->next = new ListNode{currOther->id, currOther->name, nullptr};
            currNew = currNew->next;
            currOther = currOther->next;
        }

        count = other.count;
    }

    // Assignment Operator
    NodeList& operator=(const NodeList& other)
    {
        // Self-assignment check
        if (this == &other) return *this;

        clear(); 

        if (!other.head) return *this;

        // First node
        head = new ListNode{other.head->id, other.head->name, nullptr};
        ListNode* currNew = head;
        ListNode* currOther = other.head->next;

        // Other nodes
        while (currOther)
        {
            currNew->next = new ListNode{currOther->id, currOther->name, nullptr};
            currNew = currNew->next;
            currOther = currOther->next;
        }

        count = other.count;
        return *this;
    }


    ~NodeList() 
    {
        // Commented out destructor body to demonstrate memory leak (for testing)
        // clear();
    }
};

// Main function to test the NodeList class
int main() 
{
    NodeList list;

    list.addNode(1, "Router");
    list.addNode(2, "Switch");
    list.addNode(3, "Firewall");

    cout << "Original list:\n";
    list.display();

    // TEST copy constructor
    NodeList copyList = list;
    cout << "\nCopied list:\n";
    copyList.display();

    // TEST assignment operator
    NodeList assignedList;
    assignedList = list;
    cout << "\nAssigned list:\n";
    assignedList.display();

    // TEST removal
    list.removeNode(2);
    cout << "\nAfter removing node 2:\n";
    list.display();

    return 0;
}
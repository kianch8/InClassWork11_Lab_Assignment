#include <iostream>
#include <memory>
#include <string>
using namespace std;

// =========================================
// PART B: Smart Pointer Rewrite
// =========================================

struct SmartListNode 
{
    int id;
    string name;
    unique_ptr<SmartListNode> next;

    SmartListNode(int i, string n, unique_ptr<SmartListNode> nx)
        : id(i), name(n), next(move(nx)) {}
};

class SmartNodeList 
{
private:
    unique_ptr<SmartListNode> head;
    int count;

public:
    SmartNodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) 
    {
        head = make_unique<SmartListNode>(id, name, move(head));
        count++;
    }

    void removeNode(int id) 
    {
        SmartListNode* curr = head.get();
        SmartListNode* prev = nullptr;

        while (curr && curr->id != id) 
        {
            prev = curr;
            curr = curr->next.get();
        }

        if (!curr) return;

        if (!prev) 
        {
            // Remove head
            head = move(head->next);
        } 

        else 
        {
            // Skip current node
            prev->next = move(curr->next);
        }

        count--;
    }

    void display() const 
    {
        SmartListNode* curr = head.get();
        while (curr) 
        {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next.get();
        }
        cout << "null" << endl;
    }

    int size() const 
    {
        return count;
    }

    // No destructor needed! No copy constructor needed!
    // unique_ptr handles all cleanup automatically.
};


int main() {
    SmartNodeList list;

    list.addNode(1, "Router");
    list.addNode(2, "Switch");
    list.addNode(3, "Firewall");

    cout << "Smart list:\n";
    list.display();

    list.removeNode(2);
    cout << "\nAfter removing node 2:\n";
    list.display();

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Page
{
    string url;
    string title;
    int accessTime[3];
    Page *next;
    Page *prev;
};

void visit(Page *&head, Page *&current, string url, string title, int h, int m, int s)
{
    Page *newNode = new Page;
    newNode->url = url;
    newNode->title = title;
    newNode->accessTime[0] = h;
    newNode->accessTime[1] = m;
    newNode->accessTime[2] = s;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
}

void goBack(Page *&current)
{
    if (current && current->prev)
    {
        current = current->prev;
    }
}

void goForward(Page *&current)
{
    if (current && current->next)
    {
        current = current->next;
    }
}

void deleteEntry(Page *&head, Page *&current)
{
    if (!current)
        return;
    Page *temp = current;
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp == head)
        head = temp->next;
    if (temp->prev)
        current = temp->prev;
    else
        current = temp->next;
    delete temp;
}

void displayHistory(Page *head, Page *current)
{
    Page *p = head;
    while (p)
    {
        if (p == current)
            cout << ">> ";
        cout << p->title << " [" << p->url << "] Time: ";
        for (int i = 0; i < 3; i++)
        {
            cout << p->accessTime[i] << (i < 2 ? ":" : "");
        }
        cout << endl;
        p = p->next;
    }
}

int main()
{
    Page *head = nullptr;
    Page *current = nullptr;
    string cmd, u, t;

    while (true)
    {
        cin >> cmd;
        if (cmd == "visit")
        {
            cin >> u;
            cin.ignore();
            getline(cin, t);
            visit(head, current, u, t, 10, 15, 30);
        }
        else if (cmd == "back")
        {
            goBack(current);
        }
        else if (cmd == "forward")
        {
            goForward(current);
        }
        else if (cmd == "delete")
        {
            deleteEntry(head, current);
        }
        else if (cmd == "display")
        {
            displayHistory(head, current);
        }
        else if (cmd == "EXIT")
        {
            while (head)
            {
                Page *temp = head;
                head = head->next;
                delete temp;
            }
            break;
        }
    }
    return 0;
}
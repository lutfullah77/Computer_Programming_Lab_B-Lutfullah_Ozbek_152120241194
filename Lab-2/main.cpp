#include <iostream>
#include <string>

using namespace std;
struct node
{
    string songTitle;
    node *next;
};
void addSong(node *&head, const string &title);
void searchSong(node *head, const string &title);
void listSongs(node *head);

int main()
{
    node *head = nullptr;
    int choice;
    string title;

    while (true)
    {
        cout << "1. Add Song\n2. Search Song\n3. List Songs\n4. Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            addSong(head, title);
        }
        else if (choice == 2)
        {
            cout << "Enter song title to search: ";
            cin.ignore();
            getline(cin, title);
            searchSong(head, title);
        }
        else if (choice == 3)
        {
            listSongs(head);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    void addSong(node * &head, const string &title)
    {
        node *newNode = new node;
        newNode->songTitle = title;
        newNode->next = head;
        head = newNode;
    }
    void searchSong(node * head, string & title)
    {
        node *current = head;
        while (current != nullptr)
        {
            if (current->songTitle == title)
            {
                cout << "song found: " << current->songTitle << endl;
                return;
            }
            current = current->next;
        }
        cout << "song not found: " << title << endl;
    }
    void listSongs(node * head)
    {
        node *current = head;
        while (current != nullptr)
        {
            cout << current->songTitle << endl;
            current = current->next;
        }
    }
}
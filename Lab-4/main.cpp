#include <iostream>
#include <string>

using namespace std;

struct MoneyBundle
{
    string serialNumber;
    string currencyType;
    int billCounts[3];
    MoneyBundle *next;
};

struct customer
{
    string customerName;
    string transaction_type;
};

struct MoneyStack
{
    MoneyBundle *top = nullptr;
    void push(string sn, string ct, int bc1, int bc2, int bc3)
    {
        MoneyBundle *newBundle = new MoneyBundle;
        newBundle->serialNumber = sn;
        newBundle->currencyType = ct;
        newBundle->billCounts[0] = bc1;
        newBundle->billCounts[1] = bc2;
        newBundle->billCounts[2] = bc3;
        newBundle->next = top;
        top = newBundle;
    }
    void pop()
    {
        if (top != nullptr)
        {
            MoneyBundle *temp = top;
            top = top->next;
            delete temp;
        }
    }
};
struct BankQueue
{
    customer *front = nullptr;
    customer *rear = nullptr;
    void enqueue(string name, string type)
    {
        if (count < 5)
        {
            rear(rear + 1) % 5;
            items[rear].customerName = name;
            items[rear].transaction_type = type;
            count++;
        }
        else
        {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }
    void dequeue()
    {
        if (count > 0)
        {
            front = (front + 1) % 5;
            count--;
        }
    }
};
int main()
{
    BankQueue bankline;
    MoneyStack safe;
    safe.push("SN123", "USD", 10, 20, 30);
    safe.push("SN124", "EUR", 5, 15, 25);

    bankline.enqueue("ahmet", "withdraw");
    bankline.enqueue("mehmet", "deposit");

    cout << "--Current Safe-- " << endl;
    MoneyBlonde *temp = safe.top;
    while (temp != nullptr)
    {
        cout << "Bundle: " << temp->serialNumber << " [" << temp->currencyType << "]" << endl;
        temp = temp->next;
    }
    cout << "--Current Bank Queue-- " << endl;
    for (int i = 0; i < bankline.count; i++)
    {
        int index = (bankline.front + i) % 5;
        cout << "Customer: " << bankline.items[index].customerName << " [" << bankline.items[index].transaction_type << "]" << endl;
    }

    cout << "\nProcessing Transaction..." << endl;
    if (bankLine.count > 0 && safe.top != nullptr)
    {
        cout << "Customer " << bankLine.items[bankLine.front].customerName
             << " served with bundle " << safe.top->serialNumber << endl;
        bankLine.dequeue();
        safe.pop();
    }

    return 0;
}
}

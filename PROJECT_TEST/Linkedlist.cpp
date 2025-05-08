#include <iostream>
#include <vector>
using namespace std;

class linkedlist
{
public:
    vector<int> data;

    void add(int value)
    {
        data.push_back(value);
    }

    void remove(int value)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == value)
            {
                data.erase(data.begin() + i);
                cout << "Element " << value << " removed." << endl;
                return;
            }
        }
        cout << "Element " << value << " not found." << endl;
    }

    void display()
    {
        if (data.empty())
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List elements: ";
        for (int val : data)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    void update(int num, int num1)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == num)
            {
                data[i] = num1;
                cout << "Element " << num << " updated to " << num1 << "." << endl;
                return;
            }
        }

        cout << "Element " << num << " Not found!!" << endl;
    }
};

int main()
{
    linkedlist l1;
    int choice, val, num, num1;

    do
    {
        cout << endl
             << "--- Linked list menu ---" << endl;
        cout << endl
             << "Press 1 for Add Element";
        cout << endl
             << "Press 2 for Remove Element";
        cout << endl
             << "Press 3 for Update Element";
        cout << endl
             << "Press 4 for Display List";
        cout << endl
             << "Press 5 for Exit" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> val;
            l1.add(val);
            break;
        case 2:
            cout << "Enter value to remove: ";
            cin >> val;
            l1.remove(val);
            break;
        case 3:
            cout << "Enter value to update: ";
            cin >> num;
            cout << "Enter new value: ";
            cin >> num1;
            l1.update(num, num1);
            break;
        case 4:
            l1.display();
            break;
        case 5:
            cout << "Exiting program!!" << endl;
            break;
        default:
            cout << "Invalid choice!!" << endl;
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

class BookStack
{
private:
    string library[SIZE];
    int last;

public:
    BookStack()
    {
        last = -1;
    }

    void addBook(string name)
    {
        if (last == SIZE - 1)
        {
            cout << "\nShelf is Full!\n";
            return;
        }

        library[++last] = name;
        cout << "Book Added Successfully.\n";
    }

    void removeBook()
    {
        if (last == -1)
        {
            cout << "\nShelf is Empty!\n";
            return;
        }

        cout << "Removed Book : " << library[last] << endl;
        last--;
    }

    void showTop()
    {
        if (last == -1)
        {
            cout << "\nNo Books Available.\n";
            return;
        }

        cout << "Latest Book : " << library[last] << endl;
    }

    void showBooks()
    {
        if (last == -1)
        {
            cout << "\nNo Books in Shelf.\n";
            return;
        }

        cout << "\nBooks Available:\n";

        for (int i = last; i >= 0; i--)
        {
            cout << i + 1 << ". " << library[i] << endl;
        }
    }
};

int main()
{
    BookStack shelf;
    int option;
    string title;

    do
    {
        cout << "\n=========================\n";
        cout << "     BOOK STACK MENU\n";
        cout << "=========================\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. View Top Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter Choice : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cin.ignore();
            cout << "Enter Book Title : ";
            getline(cin, title);
            shelf.addBook(title);
            break;

        case 2:
            shelf.removeBook();
            break;

        case 3:
            shelf.showTop();
            break;

        case 4:
            shelf.showBooks();
            break;

        case 5:
            cout << "\nProgram Closed.\n";
            break;

        default:
            cout << "\nPlease Enter a Valid Choice.\n";
        }

    } while (option != 5);

    return 0;
}
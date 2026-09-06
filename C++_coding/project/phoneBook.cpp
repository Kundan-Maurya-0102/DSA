#include <iostream>
#include <string>
#include <vector>

using namespace std;

class contact
{
private:
    string phoneNum;
    string name;

public:
    contact(string p, string n)
    {
        phoneNum = p;
        name = n;
    }
    void display() const
    {
        cout << "Phone Num : " << phoneNum << endl;
        cout << "Name      : " << name << endl;
    }
    string getName() const
    {
        return name;
    }
    string getNum() const
    {
        return phoneNum;
    }
    void updateNum(string phoneNum)
    {
        this->phoneNum = phoneNum;
    }
    void updateName(string name)
    {
        this->name = name;
    }
};

class phoneBook
{
private:
    vector<contact> contacts;

public:
    void addContact(string p, string n)
    {
        contact c(p, n);
        contacts.push_back(c);
        cout << "Contact Added Successfully." << endl
             << endl;
    }

    void showContact()
    {
        for (const contact &c : contacts)
        {
            c.display();
            cout << endl;
        }
    }
    void searchContact(string name)
    {
        for (const contact &c : contacts)
        {
            if (name == c.getName())
            {
                cout << "Found " << endl;
                c.display();
            }
            else
            {
                cout << "Not Found : " << endl;
            }
        }
    }
    void deleteContact(string name)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            if (name == contacts.at(i).getName())
            {
                contacts.erase(contacts.begin() + i);
                cout << "successfully deleted." << endl;
                return;
            }
        }
        cout << "contact not found." << endl;
    }
    void updateContact(string identifier, string newPhone)
{
    for (contact& c : contacts)
    {
        if (c.getName() == identifier || c.getNum() == identifier)
        {
            c.updateNum(newPhone);

            cout << "Contact updated successfully." << endl;
            return;
        }
    }

    cout << "Contact not found." << endl;
}
};

int main()
{
    phoneBook pb1;

    pb1.addContact("7562995360", "KundanMaurya");
    pb1.addContact("125468962", "Akhilesh");
    pb1.showContact();
    // pb1.deleteContact("KundanMaurya");
    pb1.showContact();
    pb1.updateContact("KundanMaurya","6205727933");
    pb1.showContact();

    return 0;
}
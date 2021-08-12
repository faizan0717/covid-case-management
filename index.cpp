#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <vector>
using namespace std;
void topBar()
{
    system("CLS");
    cout << "*************  Covid tracker  *************" << endl;
    cout << endl
         << endl;
}
int urChoice()
{
    int temp;
    cout << endl
         << endl
         << endl
         << "Enter yout choice : ";
    cin >> temp;
    return temp;
}
int validatePassword(string uName, string uPass)
{
    vector<string> temp;
    string t = "";
    int id = 1;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("user.txt");
    while (!indata.eof())
    {
        if (flag == 1)
        {
            temp.push_back(to_string(id));
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
        }
        else
        {
            t = t + value;
        }
        indata >> value;
    }
    for (int i = 0; i < temp.size(); i += 4)
    {
        if (uName == temp[i + 1])
        {
            cout << temp[i + 1] << endl;
            if (uPass == temp[i + 2])
            {
                if (temp[i + 3] == "a")
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void exitMsg()
{
    cout << endl
         << endl;
    cout << "\tThanks for wisiting";
}
void addUsers()
{
    topBar();
    string name, pass, type;
    cout << "\tNew user name :";
    cin >> name;
    cout << "\tNew user Password :";
    cin >> pass;
    cout << "\tNew user type (a/o) :";
    cin >> type;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        ofstream file;
        file.open("user.txt", ios::app);
        if (!file.is_open())
        {
            cout << "File not found,press enter to continue\n";
            getch();
            return;
        }
        file << name << "/" << pass << "/" << type << "*" << endl;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void deleteUser()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("user.txt");
    cout << "ID\tName\t\tPassword\ttype" << endl;
    indata >> value;
    while (!indata.eof())
    {
        if (flag == 1)
        {
            cout << id << "\t";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\t\t";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl;
        }
        else
        {
            t = t + value;
            cout << value;
        }
        indata >> value;
    }

    indata.close();
    cout << endl
         << endl
         << "Enter the id you want to delete:";
    cin >> id;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 3)
        {

            if (tc == id)
            {
                // cout << temp[i] << endl;
                //  cout << temp[i + 1] << endl;
                // cout << temp[i + 2] << endl;
                temp.erase(temp.begin() + i, temp.begin() + (i + 3));
                //    temp.erase(temp.begin() + (i));
                //    temp.erase(temp.begin() + (i + 1));
                flag = 1;
                break;
                //
            }
            tc++;
        }
        if (flag)
        {
            file.open("user.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 3)
            {
                file << temp[i] << "/" << temp[i + 1] << "/" << temp[i + 2] << "*" << endl;
            }
        }
        else
        {
            cout << endl
                 << "element not fount,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void deleteCase()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("case.txt");
    cout << "id=";
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            cout << id << "\n";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\n";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl
                 << endl
                 << "id=";
        }
        else
        {
            t = t + value;
            cout << value;
        }
    }
    cout << "end of data";
    indata.close();
    cout << endl
         << endl
         << "Enter the case id you want to delete:";
    cin >> id;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    cout << endl
         << endl;
    for (int i = 0; i < temp.size(); i += 2)
    {
        cout << temp[i] << temp[i + 1];
    }
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 2)
        {

            if (tc == id)
            {
                // cout << temp[i] << endl;
                //  cout << temp[i + 1] << endl;
                // cout << temp[i + 2] << endl;
                temp.erase(temp.begin() + i, temp.begin() + (i + 2));
                //    temp.erase(temp.begin() + (i));
                //    temp.erase(temp.begin() + (i + 1));
                flag = 1;
                break;
                //
            }
            tc++;
        }
        if (flag)
        {
            file.open("case.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 2)
            {
                file << temp[i] << "/" << temp[i + 1] << "*" << endl;
            }
        }
        else
        {
            cout << endl
                 << "element not fount,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void addCase()
{
    topBar();
    string date, no_of_case;
    cout << "\tEnter date (DD-MM-YYYY) :";
    cin >> date;
    cout << "\tNumber of case :";
    cin >> no_of_case;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        ofstream file;
        file.open("case.txt", ios::app);
        if (!file.is_open())
        {
            cout << "File not found,press enter to continue\n";
            getch();
            return;
        }
        file << date << "/" << no_of_case << "*" << endl;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void editCase()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("case.txt");
    cout << "id=";
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            cout << id << "\n";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\n";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl
                 << endl
                 << "id=";
        }
        else
        {
            t = t + value;
            cout << value;
        }
    }
    cout << "end of data";
    indata.close();
    cout << endl
         << endl
         << "Enter the case id you want to edit:";
    cin >> id;
    string date, case_no;
    cout << endl
         << "\t Do you want to continue (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 2)
        {

            if (tc == id)
            {
                cout << endl;
                cout << endl;
                cout << "\told date (DD-MM-YYYY) :" << temp[i] << endl;
                cout << "\tnew date (DD-MM-YYYY) :";
                cin >> temp[i];
                cout << endl;
                cout << "\told Number of case :" << temp[i + 1] << endl;
                cout << "\tnew Number of case :";
                cin >> temp[i + 1];
                cout << endl;
                flag = 1;
                break;
            }
            tc++;
        }
        if (flag)
        {
            file.open("case.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 2)
            {
                file << temp[i] << "/" << temp[i + 1] << "*" << endl;
            }
            cout << "record sucessfully updated,press enter to continue";
            getch();
        }
        else
        {
            cout << endl
                 << "element not found,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}

void editCase()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("case.txt");
    cout << "id=";
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            cout << id << "\n";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\n";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl
                 << endl
                 << "id=";
        }
        else
        {
            t = t + value;
            cout << value;
        }
    }
    cout << "end of data";
    indata.close();
    cout << endl
         << "\t Press 1 to continue";
    return;
}
void adminHome(string uName)
{
    int invalidChoice = 0, choice;
    while (true)
    {
        cout << "admmin";
        topBar();
        if (invalidChoice)
        {
            cout << "\tInvalid choice\n"
                 << endl;
            invalidChoice = 0;
        }
        cout << "         1.Add Case" << endl
             << "         2.Delete Case" << endl
             << "         3.Edit Number of Case" << endl
             << "         4.Add Users" << endl
             << "         5.Delete Users" << endl
             << "         6.logout" << endl;
        choice = urChoice();
        if (choice == 11)
        {
            exitMsg();
            exit(0);
        }
        if (choice == 22)
        {
            return;
        }
        switch (choice)
        {
        case 1:
            addCase();
            break;
        case 2:
            deleteCase();
            break;
        case 3:
            editCase();
            break;
        case 4:
            addUsers();
            break;
        case 5:
            deleteUser();
            break;
        case 6:
            return;
            break;
        default:
            invalidChoice = 1;
            break;
        }
    }
}
void homePage(string uName)
{
    int invalidChoice = 0, choice;
    while (true)
    {
        topBar();
        if (invalidChoice)
        {
            cout << "\tInvalid choice\n"
                 << endl;
            invalidChoice = 0;
        }
        cout << "       ==================================       " << endl
             << "         1.View all Case" << endl
             << "         4.logout" << endl
             << "       ==================================       " << endl;
        choice = urChoice();
        if (choice == 11)
        {
            exitMsg();
            exit(0);
        }
        if (choice == 22)
        {
            return;
        }
        switch (choice)
        {
        case 1:
            vievall();
            break;
        case 4:
            return;
            break;
        default:
            invalidChoice = 1;
            break;
        }
    }
}
void loginPage()
{
    int invalidIndicator = 0;
    string uName, uPass;
    while (true)
    {
        topBar();
        if (invalidIndicator)
        {
            cout << "   Username or password is incorrect Try again" << endl;
            invalidIndicator = 0;
        }
        cout << "\tUser Name : ";
        cin >> uName;
        if (uName == "11")
        {
            exitMsg();
            exit(0);
        }
        cout << "\tUser Password : ";
        cin >> uPass;
        invalidIndicator = validatePassword(uName, uPass);
        if (invalidIndicator == 0)
        {
            invalidIndicator = 1;
            continue;
        }
        else if (invalidIndicator == 2)
        {
            invalidIndicator = 0;
            adminHome(uName);
        }
        else
        {
            invalidIndicator = 0;
            homePage(uName);
        }
    }
}
int main()
{
    loginPage();
}
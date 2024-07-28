#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<conio.h>
#include <algorithm>
#include <sstream> 
#include <cstdlib>
#include <limits> 
using namespace std;

class login_system
{
    void waiting()
    {
        for(int i = 0; i < 10; i++)
        {
            Sleep(200);
            cout<<"..";
        }
    }
private:
    string fname, sname, name, Lname, pass, number, password, email, mobile;
    int date, month, year;
public:
    void homepage();
    void menu();
    void details();
    void modify();
    void change_password();
    void delete_account();
    void exit();

    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            } else
                return true;
        } else {
            return false;
        }
    }

   bool isValidDate(int d, int m, int y) {
    if (y > 1900 && y < 2024) {     
        if (m >= 1 && m <= 12) {

            if ((d >= 1 && d <= 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                return true;
            else if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                return true;
            else if ((d >= 1 && d <= 28) && (m == 2))
                return true;
            else if (d == 29 && m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
                return true;
        }
    }
    return false;
}

int getIntInput(const string& prompt) {
    string input;
    int value;
    bool validInput = false;

    do {
        cout << prompt;
        cin >> input;

        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            validInput = true;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);

    return value;
}

    bool isValidPhoneNumber(const string& num) {
        return num.length() == 10 && all_of(num.begin(), num.end(), ::isdigit);
    }

    bool isValidEmail(const string& email) {
        size_t at_index = email.find('@');
        size_t dot_index = email.rfind('.');
        return at_index != string::npos && dot_index != string::npos && at_index < dot_index;
    }

    bool isAlphaString(string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    };
};

void login_system::homepage()
{
        system("cls");
        cout<<"\n\t     ____________________________________________________________________________________________"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |\t\t\t              CREATE, LOGIN & AUTHENTICATION                            |"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                HOMEPAGE              |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. Create Account                     |";
        cout<<"\n\t\t\t\t\t|2. Login                              |";
        cout<<"\n\t\t\t\t\t|3. List of All Accounts               |";
        cout<<"\n\t\t\t\t\t|4. Search Account By Name             |";
        cout<<"\n\t\t\t\t\t|5. Exit                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;
        char x;
        cout<<"\t\t\t\t\t-> ";
        cin>>x;
        if(x == '1')
        {
            system("cls");
            cout<<"\n\t\t\t\t ________________________________________\n";
            cout<<"\t\t\t\t|                                        |";
            cout<<"\n\t\t\t\t|               Create Account           |"<<endl;
            cout<<"\t\t\t\t|________________________________________|"<<endl<<endl;
            while (true) {

            cout << "\t\t\t\t\tEnter User_First_Name: " << endl << "\t\t\t\t\t";
            cin >> fname;
            if (!isAlphaString(fname)) {
                cout << "\t\t\t\t\tInvalid input. Name cannot contain numbers. Please re-enter: \n";
            } else {
                break; 
            }
        }

            while (true) {
            cout << "\t\t\t\t\tEnter User_Second_Name: " << endl << "\t\t\t\t\t";
            cin >> sname;
            if (!isAlphaString(sname)) {
            cout << "\t\t\t\t\tInvalid input. Name cannot contain numbers. Please re-enter: \n ";
            } else {
                break; 
            }
        }
            cout << " \n" << "\t\t\t\t\tEnter your Date of Birth-" << " \n";
            date = getIntInput("\t\t\t\t\tDay :  ");
            month = getIntInput("\t\t\t\t\tMonth : ");
            year = getIntInput("\t\t\t\t\tYear :  ");
            while (!isValidDate(date, month, year)) {
                cout << "Invalid date. Please re-enter." << " \n";
                date = getIntInput("\t\t\t\t\tDay :  ");
                month = getIntInput("\t\t\t\t\tMonth : ");
                year = getIntInput("\t\t\t\t\tYear :  ");
            }

        cout << " \n" << "\t\t\t\t\tEnter your Contact Details: " << " \n" << "\t\t\t\t\tPhone Number : ";
        cin >> number;
        while (!isValidPhoneNumber(number)) {
            cout << "Invalid phone number. It must be 10 digits. Please re-enter: ";
            cin >> number;
        }
        cout << " \n" << "\t\t\t\t\tEnter Email Address: " << " \n" << "\t\t\t\t\t";
        cin >> email;
        while (!isValidEmail(email)) {
            cout << "Invalid email format. Please re-enter: ";
            cin >> email;
        }
        
        cout << " \n" << "\t\t\t\t\tEnter password: " << " \n" << "\t\t\t\t\t";
        char ch;
        password = "";
        ch = _getch();
        while (ch != 13 || password.empty()) {
            if(ch != 8 && ch != 13) {
                password.push_back(ch);
                cout << '*';
            } else if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
            ch = _getch();
        }

        fstream file;
        file.open("files", ios::app | ios::out);
        if (!file) {
            cout << "\t\t\t\t\tRegistration failed" << " \n" << "Try again later" << " \n";
        } else {
            file << fname << " " << sname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
            cout << "\n\n\t\t\t\t\tAccount Created Successfully." << " \n" << "\n\t\t\t\t\t";
            file.close();
        }
        system("pause");
        homepage();

        }
         else if(x == '2')
        {
            system("cls");
            cout<<"\n\t\t\t\t\t ______________________________________\n";
            cout<<"\t\t\t\t\t|                                      |";
            cout<<"\n\t\t\t\t\t|               LOGIN PAGE             |";
            cout<<"\n\t\t\t\t\t|______________________________________|"<<endl<<endl;
            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t\tError! File not found"<<endl;
                file.close();
                cout<<"\n\t\t\t\t\t\t";
                system("pause");
                file.close();
                homepage();
            }
            else
            {
                char ch;
                name = "";
                pass = "";
                int flag = 0;
                cout<<"\t\t\t\t\tEnter User_First_Name : ";
                cin>>name;
                cout<<"\t\t\t\t\tEnter User_Second_Name : ";
                cin>>Lname;
                cout<<"\t\t\t\t\tEnter Password : ";
                pass = "";
                ch = _getch();
                while (ch != 13 || pass.empty()) {
                    if(ch != 8 && ch != 13) {
                    pass.push_back(ch);
                    cout << '*';
                } else if (!pass.empty()) {
                pass.pop_back();
                cout << "\b \b";
            }
            ch = _getch();
        }
                file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    if(name == fname && Lname == sname && pass == password)
                    {
                        flag = 1;
                        break;
                    }
                    file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                }
                cout<<"\n\t\t\t\t\tVerifying User Data"<<endl<<"\t\t\t\t\t";
                waiting();
                if(flag == 1)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tLogin Successful";
                    file.close();
                    Sleep(789);
                    menu();
                }
                else if(flag == 0)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tNo account exists with given credentials."<<endl;
                    cout<<"\n\t\t\t\t\t";
                    system("pause");
                    file.close();
                    homepage();
                }
            }
        }
        else if(x == '3')
        {
            int x = 1;
            system("cls");
            cout<<"\n\t\t\t\t ______________________________________________"<<endl;
            cout<<"\t\t\t\t|                                              |";
            cout<<"\n\t\t\t\t|             LIST OF ALL ACCOUNTS             |"<<endl;
            cout<<"\t\t\t\t|______________________________________________|"<<endl<<endl;
            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t Error! File not found"<<endl;
            }
            else
            {
                file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    Sleep(66);
                    cout<<"\t\t\t\t\t\t ______________"<<endl;
                    cout<<"\t\t\t\t\t\t|              |"<<endl;
                    cout<<"\t\t\t\t\t\t|   ACCOUNT "<<x++<<"  |"<<endl;
                    cout<<"\t\t\t\t\t\t|______________|"<<endl;
                    cout<<endl<<"\t\t\t\t\t 1. User_name = "<<fname<<" "<<sname<<endl;
                    cout<<"\t\t\t\t\t 2. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t 3. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t 4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl;
                    cout<<"\t\t\t\t\t ------------------------------------"<<endl<<endl;
                    file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                }
                cout<<"\t\t\t\t\t Reached at end of the File"<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t ";
            system("pause");
            homepage();
        }
        else if(x == '4')
        {
            system("cls");
            cout<<"\n\t\t\t\t ___________________________________________\n";
            cout<<"\t\t\t\t|                                           |";
            cout<<"\n\t\t\t\t|                SEARCH ACCOUNT             |"<<endl;
            cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
            cout<<"\t\t\t\t\tEnter User_First_Name: ";
            cin>>name;
            cout<<"\t\t\t\t\tEnter User_Second_Name: ";
            cin>>Lname;
            cout<<"\t\t\t\t\tEnter Mobile Number: ";
            cin>>mobile;

            int found = 0;
            fstream file;
            file.open("files", ios::in);
            file>>fname>>sname>>password>>number>>email>>date>>month>>year;
            while(!file.eof())
            {
                if(name == fname && Lname == sname && mobile == number)
                {
                    Sleep(66);
                    cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<" "<<sname<<endl;
                    cout<<"\t\t\t\t\t2. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t3. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
                    cout<<"\t\t\t\t\t------------------------------------"<<endl<<endl;
                    found++;
                }
                file>>fname>>sname>>password>>number>>email>>date>>month>>year;
            }
            if(found == 0)
            {
                cout<<endl<<"\t\t\t\t\tNo account exist with ["<<name<<Lname<<"] username ."<<endl<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t";
            system("pause");
            homepage();
        }
        else if(x == '5')
        {
            _exit(0);
        }
        else
        {
            cout<<"\t\t\t\t\tInvalid Parameter, Try Again.";
            Sleep(636);
            homepage();
        }
}
void login_system::menu()
    {
        system("cls");
        cout<<"\n\t\t\t\t __________________________________________________\n";
        cout<<"\t\t\t\t|                                                  |";
        cout<<"\n\t\t\t\t|                 ACCOUNT MANAGMENT                |"<<endl;
        cout<<"\t\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tKindly select an option below:"<<endl<<endl;
        cout<<"\t\t\t\t\t1. Account Details"<<endl<<endl;
        cout<<"\t\t\t\t\t2. Modify Account"<<endl<<endl;
        cout<<"\t\t\t\t\t3. Change Password"<<endl<<endl;
        cout<<"\t\t\t\t\t4. Delete Account"<<endl<<endl;
        cout<<"\t\t\t\t\t5. Logout"<<endl;
        char option;
        cout<<endl<<"\t\t\t\t\t-> ";
        cin>>option;
        switch(option)
        {
        case '1':
            details();
            break;
        case '2':
            modify();
            break;
        case '3':
            change_password();
        case '4':
            delete_account();
        case '5':
            {
                cout<<"\n\t\t\t\t\tLogging Out . . ."<<endl<<"\t\t\t\t\t";
                waiting();
                homepage();
            }
        default:
            cout<<"\t\t\t\t\tInvalid Option\n\t\t\t\t\tTry Again."<<endl;
            Sleep(636);
            menu();
        }
    }
void login_system::details()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              ACCOUNT DETAILS              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file;
    file.open("files", ios::in);
    file>>fname>>sname>>password>>number>>email>>date>>month>>year;
    while(!file.eof())
    {
        if(name == fname && Lname == sname && password == pass)
        {
            Sleep(66);
            cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t2. Email = "<<email<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t3. Contact = "<<number<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t5. Account Password = "<<password<<endl<<endl;
            break;
        }
        file>>fname>>sname>>password>>number>>email>>date>>month>>year;
    }
    file.close();
    cout<<"\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::modify()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              MODIFY ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("modify", ios::app | ios::out);
    file>>fname>>sname>>password>>number>>email>>date>>month>>year;
    while(!file.eof())
    {
        if(name == fname && Lname == sname && pass == password)
        {
            cout<<"\t\t\t\t\tEnter User_First_Name: "<<endl<<"\t\t\t\t\t";
            cin>>fname;
            cout<<"\t\t\t\t\tEnter User_Second_Name: "<<endl<<"\t\t\t\t\t";
            cin>>sname;
            cout<<endl<<"\t\t\t\t\tEnter your Date of Birth- "<<endl<<"\t\t\t\t\tDay :  ";
            cin>>date;
            cout<<"\t\t\t\t\tMonth : ";
            cin>>month;
            cout<<"\t\t\t\t\tYear :  ";
            cin>>year;
            cout<<endl<<"\t\t\t\t\tEnter your Contact Details: "<<endl<<"\t\t\t\t\tPhone Number : ";
            cin>>number;
            cout<<endl<<"\t\t\t\t\tEnter Email Address: "<<endl<<"\t\t\t\t\t";
            cin>>email;
            file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        else
        {
            file1<<fname<<" "<<sname<< " "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        file>>fname>>sname>>password>>number>>email>>date>>month>>year;
    }
    cout<<endl<<"\t\t\t\t\tSaving new details, Please wait . . ."<<endl<<"\t\t\t\t\t";
    waiting();
    file.close();
    file1.close();
    remove("files");
    rename("modify", "files");
    cout<<endl<<"\n\t\t\t\t\tAccount Details Saved Successfully."<<endl;
    cout<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl<<"\n\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::change_password()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              CHANGE PASSWORD              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    string oldpass, newpass, confirmpass;
    cout<<"\t\t\t\t\tEnter your Old Password: ";
    cin>>oldpass;
    if(oldpass == pass)
    {
        cout<<endl<<"\t\t\t\t\tEnter New Password: ";
        cin>>newpass;
        if(newpass == oldpass)
        {
            cout<<endl<<"\t\t\t\t\tOld and New Password can't be same.";
        }
        else
        {
            cout<<endl<<"\t\t\t\t\tConfirm New Password: ";
            cin>>confirmpass;
            if(confirmpass != newpass)
            {
                cout<<endl<<"\t\t\t\t\tError! Password mismatch."<<endl<<"\t\t\t\t\tPlease try again.";
                Sleep(636);
                change_password();
            }
            else
            {
                fstream file, file1;
                file.open("files", ios::in);
                file1.open("modify", ios::app | ios::out);
                file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    if(name == fname && Lname == sname && pass == oldpass)
                    {
                        file1<<fname<<" "<<sname<<" "<<newpass<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                    }
                    else
                    {
                        file1<<fname<<" "<<sname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                    }
                    file>>fname>>sname>>password>>number>>email>>date>>month>>year;
                }
                cout<<endl<<"\t\t\t\t\tChanging Password, Please wait . . ."<<endl<<"\t\t\t\t\t";
                waiting();
                cout<<endl<<"\n\t\t\t\t\tPassword changed successfully."<<endl;
                cout<<endl<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl;
                file.close();
                file1.close();
                remove("files");
                rename("modify", "files");
            }
        }
    }
    else
    {
        cout<<endl<<"\t\t\t\t\tError! Wrong Password"<<endl;
    }
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::delete_account()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              DELETE ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    cout<<"\t\t\t\t\tAre you sure want to delete account ?"<<endl;
    cout<<"\t\t\t\t\tThis action can't be undone!"<<endl;
    cout<<"\t\t\t\t\tY/N: ";
    char x;
    cin>>x;
    if(x == 'y' || x == 'Y')
    {
        fstream file, file1;
        file.open("files", ios::in);
        file1.open("modify", ios::app | ios::out);
        file>>fname>>sname>>password>>number>>email>>date>>month>>year;
        while(!file.eof())
        {
            if(name == fname && Lname == sname && pass == password)
            {
//                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            else
            {
                file1<<fname<<" "<<sname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
            }
            file>>fname>>sname>>password>>number>>email>>date>>month>>year;
        }
        cout<<endl<<"\t\t\t\t\tDeleting Account . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        cout<<endl<<"\n\t\t\t\t\tAccount Deleted Successfully."<<endl;
        cout<<endl<<"\t\t\t\t\tLogging you out . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        file.close();
        file1.close();
        remove("files");
        rename("modify", "files");
        homepage();
    }
    else if(x == 'N' || x == 'n')
    {
        cout<<endl<<"\t\t\t\t\tTaking you back to Main Menu"<<endl<<"\t\t\t\t\t";
        waiting();
        Sleep(636);
        menu();
    }
    else
    {
        cout<<"\t\t\t\t\tPlease select a valid option."<<endl;
        system("pause");
        delete_account();
    }
}
int main()
{
    login_system x;
    x.homepage();
    return 0;
}
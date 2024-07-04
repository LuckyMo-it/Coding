#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class bankuser
{
public:
    unsigned int id = 99;
    string pass;
    string name;
    unsigned int mobileno;
};
class transaction
{
public:
    unsigned id;
    string s;
    int a;
    int total = 0;
};
class management
{
public:
    bankuser a;
    transaction t;
    fstream f, f1, f2, f3;
    void adduser()
    {
        char co;
        while (1)
        {
            system("cls");
            cout << "\t\t\t\tUSER ADD MODULE" << endl;
            f.open("bankuser.txt", ios::in);
            while (f.read((char *)&a, sizeof(a)))
            {
            }

            f.close();
            a.id = a.id + 1;
            cout << "\t\t\t\tADD USER" << endl;
            cout << "ID=" << a.id << endl;
            fflush(stdin);
            cout << "NAME=";
            getline(cin, a.name);
            cout << endl;
            cout << "ENTER PIN=";
            fflush(stdin);
            getline(cin, a.pass);
            cout << endl;
            cout << "MobileNO=";
            cin >> a.mobileno;
            cout << endl;
            f.open("bankuser.txt", ios::out | ios::app);
            f.write((char *)&a, sizeof(a));
            f.close();
            cout << "USER ADDED TO SERVER\n";
            cout << "DO YOU WANT TO CONTINUE(1)\n";
            co = getch();
            if (co != '1')
                break;
            getch();
        }
    }
    void showuser()
    {
        char co;
        string pin;
        while (1)
        {
            system("cls");
            cout << "USER DISPLAY MODULE\n";
            unsigned id;
            int c = 0;

            cout << "Enter ID=";
            cin >> id;
            cout << endl;
            f.open("bankuser.txt", ios::in);
            while (f.read((char *)&a, sizeof(a)))
            {
                if (id == a.id)
                {

                    cout << "Name=" << a.name << endl;
                    cout << "MobileNO=" << a.mobileno << endl;
                    f1.open("transdet.txt", ios::in);

                    while (f1.read((char *)&t, sizeof(t)))
                    {
                        if (t.id == id)
                        {
                            cout << "\n\t\tTOTAL BALANCE=" << t.total << "\n";
                        }
                        else
                        {
                            cout << "\n\t\tTOTAL BALANCE=0(never done any transaction)\n";
                        }
                    }
                    f1.close();
                    cout << "\n\n\t\t\t---H.History---" << endl;
                    f1.open("userhistory.txt", ios::in);
                    cout << "============||Transaction||==" << endl;
                    while (f1.read((char *)&t, sizeof(t)))
                        ;
                    {
                        if (t.id == id)
                        {
                            cout << "            " << t.a << endl;
                        }
                    }
                    f1.close();
                    c = 1;
                }
            }
            f.close();
            if (c == 0)
                cout << "USER NOT EXISTS IN SERVER" << endl;
            cout << "\n\nDO YOU WANT TO CONTINUE(1)\n";
            co = getch();
            if (co != '1')
                break;
            getch();
        }
    }
    void transaction(int id)
    {
        char co;
        
        int c = 0, p;
        char ch;
        string pin;
        while (1)
        {
            system("cls");
            cout << "TRANSACTION MODULE\n";
            
            f.open("bankuser.txt", ios::in);
            while (f.read((char *)&a, sizeof(a)))
            {
                if (a.id == id)
                {

                    c = 1;
                    cout << "NAME=" << a.name << "\n";
                    cout << "\t\t1.WITHDRAW\t2.CREDIT" << endl;
                    ch = getch();
                    if (ch == '1')
                    {
                        cout << "ENTER AMOUNT =";
                        cin >> p;
                        cout << endl;
                        t.id = id;
                        t.a = -p;
                        t.total = t.total + t.a;
                        f1.open("transdet.txt", ios::out);
                        f1.write((char *)&t, sizeof(t));
                        historyuser();
                        f1.close();
                    }
                    else if (ch == '2')
                    {
                        cout << "ENTER AMOUNT =";
                        cin >> p;
                        cout << endl;
                        t.id = id;
                        t.a = p;
                        t.total = t.total + t.a;
                        f1.open("transdet.txt", ios::out);
                        f1.write((char *)&t, sizeof(t));
                        historyuser();
                        f1.close();
                    }
                }
            }
            f.close();
            if (c == 0)
            {
                cout << "USER DONT EXISTS IN SERVER" << endl;
            }
            cout << "\n\nDO YOU WANT TO CONTINUE(1)" << endl;

            co = getch();
            if (co != '1')
                break;
            getch();
        }
    }
    void historyuser()
    {
        f.open("userhistory.txt", ios::app);
        f.write((char *)&t, sizeof(t));
        f.close();
    }
    void deluser()
    {
        char co;
        while (1)
        {
            system("cls");
            cout << "DELETION MODULE\n";
            int id;
            int c = 0;
            cout << "ENTER ID=\n";
            cin >> id;
            cout << "\n";
            f.open("bankuser.txt", ios::in);
            f1.open("bankusertemp.txt", ios::out);
            f2.open("transdet.txt", ios::out);
            f3.open("transdettemp.txt", ios::out);
            while (f.read((char *)&a, sizeof(a)))
                ;
            {
                if (id == a.id)
                    c = 1;
                if (id != a.id)
                {
                    f1.write((char *)&a, sizeof(a));
                }
                else if (t.id != id)
                {
                    f3.write((char *)&t, sizeof(t));
                }
            }
            f.close();
            f1.close();
            f2.close();
            f3.close();
            remove("bankuser.txt");
            rename("bankusertemp.txt", "bankuser.txt");
            remove("transdet.txt");
            rename("transdettemp.txt", "transdet.txt");
            if (c == 0)
                cout << "USER NOT FOUND\n";
            else
                cout << "USER DELETED FROM SERVER\n";
            cout << "\n\nDO YOU WANT TO CONTINUE(1)" << endl;

            co = getch();
            if (co != '1')
                break;
            getch();
        }
    }
};
void user()
{
    char c;
    management a1;
    bankuser a;
    int id;
    string pin;
    fstream fin;
    cout << "\t\t==USER PANEL==" << endl;
    cout << "ENTER ID=";
    cin >> id;
    cout << endl;
    cout << "ENTER PIN=";
    fflush(stdin);
    getline(cin,pin);
    cout << endl;
    fin.open("bankuser.txt", ios::in);
    while (fin.read((char *)&a, sizeof(a)))
    {fin.close();
        if (id == a.id )
        { if(a.pass.compare(pin)==0)
        {
            while (1)
            {
                
                cout << "1.TRANSACTIONS" << endl;

                c = getch();
                if (c == '1')
                    a1.transaction(id);

                else
                    break;
            }}
            else
        {
            cout << "YOU ENTERED WRONG INFO" << endl;
         getch();
        }
         
        }
        
            
    }
   
}
void admin()
{
    char c;
    management a1;
    while (1)
    {
        system("cls");
        cout << "\t\t==ADMIN PANEL==" << endl;

        cout << "1.ADD USER\t2.SHOW USER" << endl;
        cout << "3.DELETE USER" << endl;
        c = getch();
        if (c == '1')
            a1.adduser();
        else if (c == '2')
            a1.showuser();
        else if (c == '3')
            a1.deluser();

        else
            break;
    }
}
int main()
{
    char c;
    while (1)
    {
        system("cls");
        cout << "\t\t\t\t=====" << char(36) << " BANk MANAGEMENT SYSTEM " << char(36) << "=====" << endl;
        cout << "1.LOGIN AS USER\t\t2.LOGIN AS ADMIN" << endl;
        c = getch();
        if (c == '1')
            user();
        else if (c == '2')
            admin();
        else
            break;
    }
    return 0;
}

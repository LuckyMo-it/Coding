#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int n=10;
class original
{
    public:
    int a1[10];
};
class changable
{
    public:
    int a[10];


};

class arraysys
{
    public:
    original x;
    changable y;
    fstream f,f2,f3;
    int pos ,i;char ch;
    arraysys()
    {

        /*f.open("2.txt",ios::out);
        while(f)
        {

        f.write((char *)&x.a1,sizeof(x.a1));
        }
        f.close();*/


    }
    void show(){
        cout<<"1.Original Array\t2.Performed Array"<<endl;
        ch=getch();
        if(ch=='1')
        {   cout<<"Original Elements "<<endl;
            f.open("1.txt",ios::in);
            while(f.read((char *)&x,sizeof(x)))
            {

                for(i=0;i<n;i++)
                    cout<<x.a1[i]<<" ";

            }


            f.close();
        }
        else if(ch=='2')
        {
            cout<<"Performed Array Elements "<<endl;
            f.open("2",ios::in);
            while(f)
            {
                f.read((char *)&y,sizeof(y));
                cout<<y.a;
            }f.close();
        }
        ch=getch();

    }
    void insertioninor()
    {
        for(i=0;i<n;i++)
        {
            cin>>x.a1[i];
        }
        f.open("1.txt",ios::out);

        f.write((char *)&x,sizeof(x));

        f.close();
        cout<<"Insertion completed"<<endl;
        }
    void deletion()
    {
        system("cls");
        cout<<"Enter position-"<<endl;
        cin>>pos;
        y.a[pos]=0;
        f.open("2",ios::out);
        f.write((char *)&y,sizeof(y));
        f.close();
        cout<<"Element Deleted"<<endl;



    }




};
int main()
{   arraysys a;
    char c;
    while(1){
    system("cls");
    cout<<"\t\tArray Operations"<<endl;





    cout<<"1.Deletion\t2.Original Array Element"<<endl;
    c=getch();
    if(c=='1')
        a.deletion();
    else if(c=='2')
    {
    a.insertioninor();

    }
    else if(c=='3')
    {
        a.show();
    }
    else
        exit(0);}




}

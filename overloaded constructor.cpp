//  overloaded constructor

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

enum acc_type{CURRENT=1,SAVINGS=2,FIXDED=3};
// .....class definition for account type object in commercialn  bank
class acc
{
private:
    int acc_id;
    char name[25];
    acc_type type;
public:
    acc();         //constructor with no parametter
    acc(int id,char *name,acc_type t);      //constructor with three parametter
    acc(ifstream &fin);      //constructor with one parametter
    int disply();
    ~acc(){};
};
acc::acc()
{
    int type;
    cout<<endl<<"Enter account Id: #";
    cin>>acc_id;
    cout<<endl<<"Enter name of account holder: ";
    cin>>name;
    cout<<endl<<"Enter account type(CURRENT=1,SAVINGS=2,FIXDED=3)#";
    cin>>type;
    acc::type=(acc_type)type;
}
acc::acc(int id,char *name,acc_type t)
{
    acc_id=id;
    strcpy(acc::name,name);
    type=t;
}
acc::acc(ifstream& fin)
{
    fin.open("C:\\Temp\\Overload.dat",ios::in);    //open file
    if(!fin)
    {
        cout<<endl<<"File Error:File not found...."<<endl;
        cout<<endl<<"So,No record is created,object is empty or Garbage.";
           return;
    }
    fin>>acc_id;
    fin>>name;
    int type;
    fin>>type;
    acc::type=(acc_type)type;
}
int acc::disply()
{
    static int out_no=1;
    cout<<endl<<"Output#"<<out_no++;
    char *type_name[3]={"CURRENT","SAVINGS","FIXED"};
    cout<<endl<<"Account id#"<<acc_id<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"Account type: "<<type_name[type]<<endl;
}
int main()
{
    ifstream fin;
    acc a1,a2(2,"NITON",SAVINGS),a3(fin);
    a1.disply();
    a2.disply();
    a3.disply();
}

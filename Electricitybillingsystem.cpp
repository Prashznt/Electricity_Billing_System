#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>
#include<iomanip>
using namespace std;
class consumer
{
private:
int customer_id;
char name[30];
char address[25],month[15],remark[10];
long double unitamt,billamt,year;
public:
    consumer(){
    string Null;
    customer_id=00;
    name[0]='\0';
    address[0]='\0';
    month[0]='\0';
    unitamt=00.00;
    billamt=00.00;
    year=0000;
    remark[0]='\0';
    }
     void readconsumerdata()
    {
        cout<<"\033[1;35mcreate your PIN:\033[0m"<<endl;
        cin>>customer_id;
        cout<<"\033[1;35mEnter consumer Name:\033[0m"<<endl;
        cin.ignore();
        cin.getline(name,30);
        cout<<"\033[1;35mEnter consumer Address:\033[0m"<<endl;
        cin.getline(address,25);
    }
    void readbilldata()
    {
         cout<<"\033[1;35mEnter units of electricity consumed\033[0m"<<endl;
            cin>>unitamt;
           billamt= calculate(unitamt);
            cout<<"\033[1;35mEnter Month:\033[0m"<<endl;
            cin.ignore();
            cin.getline(month,15);
        cout<<"\033[1;35mEnter year:\033[0m"<<endl;
        cin>>year;
         strcpy(remark, "paid");/*can cause buffer overflow*/
    }
     void displayconsumerdata()
{
     cout<<endl<<"\033[1;37mconsumer id:"<<customer_id<<endl;
     cout<<endl<<"Name:"<<name<<endl;
     cout<<endl<<"Address:\033[0m"<<address<<endl;
}
     void displaybilldata()
{
    cout<< setprecision(20);
     cout<<"\033[1;37munit consumed:"<<unitamt<<endl;
    cout<<"Bill amount:"<<billamt<<endl;
    cout<<"status: pending"<<endl;
    cout<<"For"<<" "<<month<<"  \033[0m"<<year<<endl;
}
 void displayBilldata()
{
    cout<< setprecision(20);
     cout<<"\033[1;37munit consumed:"<<unitamt<<endl;
    cout<<"Bill amount:"<<billamt<<endl;
    cout<<"status:"<<remark<<endl;
    cout<<"For"<<" "<<month<<"  \033[0m"<<year<<endl;
}
double calculate(long double x)
{
    long double B;
     float aa,ab,ac,ad,ae,aA,aB,aC,aD,aE;
    ifstream F;
    F.open("BILLRATE-DATA.txt",ios::in|ios::app);
     if(!F){
				cout<<"Error!!!!!\n";
				}
				else
				{ 
                   F >> aA;
                   F >> aa;
                   F >> aB;
                   F >> ab;
                   F >> aC;
                   F >> ac;
                   F >> aD;
                   F >> ad;
                   F >> aE;
                   F >> ae;
                           
                }
if(x<=aA)
{
    B=aa*x;
    return B;
}
else if (x<=aA+aB)
{
B=((aa*x)+(ab*(x-aA)));
 return B;
}
else if(x<=aD)
{
    B=(aa*aA)+(ab*aB)+(ac*(x-aA+aB));
     return B;
}
else if(x<=aE)
{
B=((aa*aA)+(ab*aB)+(ac*aC)+(ad*(x-aD)));
 return B;
}
else
{
    B=((aa*aA)+(ab*aB)+(ac*aC)+(ad*aD)+(ae*(x-aE)));
     return B;
}
}
   int searchrecord(const string& z,string v){
    int count=0;
     ifstream R;
     R.open(v+".txt",ios::in|ios::binary);
     if(!R){
     cout<<"\033[1;31m\n file not found!!!\033[0m"<<endl;
     }
     else{
        R.read((char*)this,sizeof(*this));
        while (!R.eof()) {
            if (z==month)
               {
                displayconsumerdata();
                displayBilldata();
                count++;
                }
                R.read((char*)this,sizeof(*this));
                }
            R.close();
            if(count==0){
            cout<<"\033[1;31mdata not found\033[0m"<<endl;
              }
        }
        return 0;
     }
     int deleterecord(const string& z,string v){
     ifstream R;
     ofstream p;
     R.open(v+".txt",ios::in|ios::binary);
     if(!R){
     cout<<"\033[1;31m\n file not found!!!\033[0m"<<endl;
     }
     else{
        p.open("tempfile.dat",ios::out|ios::binary);
        int recordfound=0;
        R.read((char*)this,sizeof(*this));
        while (!R.eof()) {
            if (z!=month)
               {
                p.write((char*)this,sizeof(*this));
                }
                else{
                    recordfound=1;
                }
                R.read((char*)this,sizeof(*this));
                }
            R.close();
            p.close();
            remove((v + ".txt").c_str());
            rename("tempfile.dat", (v + ".txt").c_str());
            if(recordfound==1){
                cout<<"\033[1;32mrecord deleted successfully !!!\033[0m"<<endl;
            }
            else{
                cout<<"\033[1;31mRecord not found\033[0m"<<endl;
            }
        }
        return 0;
     }
     friend long double getbillamt(consumer);
};
int Billpayment(long double Btt)
{
    int i;
 long double bamt;
 BiLL: system("cls");
    cout<<"\033[1;33m_____________________________________________________BILL PAYMENT_____________________________________________________________\033[0m"<<endl;
    cout<<"\033[1;32m Total amount to be paid: "<<Btt<<endl;
    cout<<"Enter amount\033[0m"<<endl;
    cin>>bamt;
    if(Btt!=bamt){ 
         system("cls");
    cout<<"\033[1;31mplease enter exact amount to be paid!!!!\033[0m"<<endl;
    cout<<endl;
    cout<<"\033[1;34m enter 1 to exit and any other key to continue\033[0m"<<endl;
    cin>>i;
    if(i==1){
        return 1;
    }
    else{
    goto BiLL;
    }
    }
        system("cls");
        cout<<"\033[1;32m         payment successful !!\033[0m"<<endl;
        cout<<endl;
        cout<<"\033[1;34m__________________________________________________________THANK-YOU____________________________________________________\033[0m"<<endl;
        return 0;  
         }

         
int adminlogin()
{
    string admin_username,admin_pass;
    string AU="admin";
    string P="password";
      cout<<"\033[1;33m_____________________________________________________________ADMIN LOGIN___________________________________________________________\033[0m"<<endl;
   cout<<"\033[1;35mEnter Admin username:\033[0m"<<endl;
   cin>>admin_username;
   cout<<"\033[1;35mEnter admin password:\033[0m"<<endl;
   cin>>admin_pass;
   if(AU!=admin_username){
    cout<<"\033[1;31minvalid username\033[0m"<<endl;
    return 0;
   }
   else if(P!=admin_pass){
    cout<<endl;
    cout<<"\033[1;31minvalid password!!!\033[0m"<<endl;
    return 0;
   }
   else{
    return 1;
   }
}
int homepage()
{
    int ch1;
    cout<<"\033[1;33m***********************************************************HOME-PAGE***************************************************************\033[0m"<<endl;  
    cout<<endl;
    cout<<"\033[1;34m1.SIGN UP"<<endl;
    cout<<"2.LOG IN"<<endl;
    cout<<"3.ADMIN LOG-IN"<<endl;
    cout<<"4.Contact us"<<endl;
    cout<<"5.EXIT\033[0m"<<endl;
    cout<<"\033[1;32mEnter your choice(1 to 5)\033[0m"<<endl;
    cin>>ch1;
    return ch1;
}
int menucaseend()
{
    int X;
     cout<<"\033[1;34mPress 1  to view menupage"<<endl;
           cout<<"press 2 to view homepage\033[0m"<<endl;
           cin>>X;
           return X;

}
int viewBillrate(){
    float aa,ab,ac,ad,ae,aA,aB,aC,aD,aE;
    system("cls");
    cout<<"\033[1;33m*****************************************************CURRENT BILL RATE*******************************************************\033[0m"<<endl;
    ifstream F;
    F.open("BILLRATE-DATA.txt",ios::in|ios::app);
     if(!F){
				cout<<"\033[1;31mError!!!!!\n\033[0m";
				}
				else
				{ 
                   F >> aA;
                   F >> aa;
                   F >> aB;
                   F >> ab;
                   F >> aC;
                   F >> ac;
                   F >> aD;
                   F >> ad;
                   F >> aE;
                   F >> ae;
                           
                }
                cout<<"\033[1;34mfor first  \033[0m"<<"\033[1;31m"<<aA<<  "\033[1;32munits at rate of Rs.\033[0m"                                             <<"\033[1;31m"<<aa<<"\033[0m"<<        "\033[1;35mper unit\033[0m"<<endl;
                cout<<"\033[1;34mfor  next \033[0m" <<"\033[1;31m"<<aB<<"("<<aA<<"-"<<aA+aB<<")\033[0m"<<"\033[1;32m units at rate of Rs.\033[0m"             <<"\033[1;31m"<<ab<<"\033[0m"<<     "\033[1;35mper unit\033[0m"<<endl;
                cout<<"\033[1;34mfor  next\033[0m " <<"\033[1;31m"<<aC<<"("<<aA+aB<<"-"<<aA+aB+aC<<")\033[0m"<<"\033[1;32m units at rate of Rs.\033[0m"       <<"\033[1;31m"<<ac<<"\033[0m"<<     "\033[1;35mper unit\033[0m"<<endl;
                cout<<"\033[1;34mfor next \033[0m"  <<"\033[1;31m"<<aD<<"("<<aA+aB+aC<<"-"<<aA+aB+aC+aD<<")\033[0m"<<"\033[1;32m units at rate of Rs.\033[0m" <<"\033[1;31m"<<ad<<"\033[0m"<<    "\033[1;35mper unit\033[0m"<<endl;
                cout<<"\033[1;34mfor above \033[0m" <<"\033[1;31m"<<    "("<<aA+aB+aC+aD<<")\033[0m"   <<"\033[1;32m units at rate of Rs.\033[0m"             <<"\033[1;31m"<<ae<<"\033[0m"<<     "\033[1;35mper unit\033[0m"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\033[1;34mpress Enter to goto homepage\033[0m"<<endl;
                getch();
                return 0;
    
}
int readbillvar(){
    system("cls");/*prices are in both small letter variables*/
   float aa,ab,ac,ad,ae,aA,aB,aC,aD,aE;
   cout<<"\033[1;33m*****************************************************UPDATE BILL RATE**************************************************************\033[0m"<<endl;
    cout<<"\033[1;34mEnter the first unit limit:\033[0m";cin>>aA;cout<<"\033[1;32m at rate of RS.\033[0m";cin>>aa;
    cout<<"\033[1;34mEnter the next unit limit :\033[0m";cin>>aB;cout<<"\033[1;32m at rate of RS.\033[0m";cin>>ab;
    cout<<"\033[1;34mEnter the next unit limit :\033[0m";cin>>aC;cout<<"\033[1;32m at rate of RS.\033[0m";cin>>ac;
    cout<<"\033[1;34mEnter the next unit limit :\033[0m";cin>>aD;cout<<" \033[1;32mat rate of RS.\033[0m";cin>>ad;
    cout<<"\033[1;34mEnter the next unit limit :\033[0m";cin>>aE;cout<<" \033[1;32mat rate of RS.\033[0m";cin>>ae;
    ofstream F;
     F.open("BILLRATE-DATA.txt",ios::out|ios::trunc);/*trunc to overwrite existing data in file*/
     if(!F){
				cout<<"\033[1;31mError!!!!!\n\033[0m";
				}
				else
				{
     F<<aA<<endl;
     F<<aa<<endl;
     F<<aB<<endl;
     F<<ab<<endl;
     F<<aC<<endl;
     F<<ac<<endl;
     F<<aD<<endl;
     F<<ad<<endl;
     F<<aE<<endl;
     F<<ae<<endl;
     } 
     cout<<"\033[1;32mBill rate updated sucessfully.....\033[0m"<<endl;
     cout<<"\033[1;34mpress enter for homepage\033[0m"<<endl;
     getch();
     return 0;     
}
long double getbillamt(consumer B){
long double p;
p=B.billamt;
return p;
}
int main()
{
    consumer B,W;
    char s;
    string username,m;
    int id,idf,ch1,ch2,ch3,Y,E;
    long double btt;

    ifstream D("ASCII.txt");
    if (!D) {
        cout << "\033[1;31mError opening file.\033[0m" << endl;
        return 1;
    }
    string line;
    while (getline(D,line)) {
         cout << "\033[33m" << line << "\033[0m" << endl;
    }
    D.close();
    ifstream SY("ASCII1.txt");
    if (!SY) {
        cout << "\033[1;31mError opening file.\033[0m" << endl;
        return 1;
    }
    while (getline(SY, line)) {
    cout << "\033[34m" << line << "\033[0m" << endl;
}
    SY.close();
  cout<<"\033[1;35mpress enter to continue\033[0m";
  getch();
   home:
   system("cls");
    switch(homepage()) {
      case 1:{
        system("cls");
      cout<<"\033[1;33m*****************************************************SIGN UP*******************************************************************\033[0m"<<endl;
     cout<<"\033[1;35mCreate Username\033[0m"<<endl;
     cin.ignore();
      getline(cin,username);
      B.readconsumerdata();
     ofstream F;
     F.open(username+".txt",ios::out|ios::app|ios::binary);
     F.write((char*)&B,sizeof(B));
      cout<<"\033[1;32m\n Yours details have been saved successfully...\033[0m"<<endl;
       F.close();
       cout<<"\033[1;34mpress enter to view homepage\033[0m"<<endl;
       getch();
       goto home;
       break;
      }
     case 2:
     {
        system("cls");
       cout<<"\033[1;33m************************************************************LOG IN*****************************************************************\033[0m"<<endl;
       cout<<"\033[1;35mEnter your username to open file:\033[0m"<<endl;
       cin.ignore();
       getline(cin,username);
       fstream A;
       A.open(username+".txt",ios::app|ios::in|ios::out|ios::binary);
       if(!A)
       {
        cout<<"\033[31mError opening file\033[0m"<<endl;
        return 1;
       }
       std::vector<unsigned char> buffer(4);/*creating buffer*/
       A.read(reinterpret_cast<char*>(buffer.data()),4);/*reads first 4 byte data in buffer*/
       A.close();
       idf = *reinterpret_cast<int*>(buffer.data());/*convert buffer into integer*/
       cout<<"\033[1;35mEnter your PIN:\033[0m"<<endl;
       cin>>id;
       if(id!=idf)
        {
           cout<<"\033[31mverification failed!!!\033[0m"<<endl<<"\033[1;36minvalid username or id !!!\033[0m"<<endl;
           exit(0);
          }/*inside log-in switch case*/
        menu:
        system("cls");
        cout<<"\033[1;33m*************************************************************NEPAL ELECTRICITY AUTHORITY****************************************\033[0m"<<endl;
        cout<<endl;
        cout<<"\033[1;31m----------------------------------------------------------------MENU-PAGE----------------------------------------------------------\033[0m"<<endl;
        cout<<"\033[34m1.Generate Bill"<<endl<<"2.view consumer record"<<endl<<"3.search previous month record"<<endl<<"4.Delete record"<<endl<<"5.view current Bill rate"<<endl<<"6.Home-page\033[0m"<<endl;
         cout<<"\033[1;32mEnter your choice\033[0m"<<endl;
         cin>>ch2;
         switch (ch2)
        {
          case 1:/*generate bill*/
          {
            system("cls");
            cout<<"\033[33m________________________________________________________________Generate Bill________________________________________________________________\033[0m"<<endl;
            fstream C;
           C.open(username+".txt",ios::in|ios::out|ios::app|ios::binary);
           C.read((char*)&B,sizeof(B));
           B.readbilldata();
           system("cls");
           cout<<"\033[1;37m----------------------------------------------------GOVERNMENT OF NEPAL-----------------------------------------------------------"<<endl;
           cout<<endl;
           cout<<"****************************************************NEPAL ELECTRICITY AUTHORITY****************************************************"<<endl;
           cout<<__TIMESTAMP__<<endl;
           B.displayconsumerdata();
           B.displaybilldata();
           cout<<endl;
           cout<<"___________________________________________________________________________________________________________________________________\033[0m"<<endl;
           cout<<"\033[1;32mDo you want to pay the bill ? "<<endl<<" Enter 1 to pay..."<<endl<<"Enter 2 to exit to homepage\033[0m"<<endl;
           cin>>Y;
           if(Y==1) {
            btt=getbillamt(B);/*B.billamt;*/
          E=Billpayment(btt);
          if(E==0){
            C.write((char*)&B,sizeof(B));
             C.close();
             }
            Y=menucaseend();
           if(Y==1)
           {
            goto menu;
           }
           else if(Y==2)
           {
           goto home;
           }
           else
           {
            cout<<"\033[1;31minvalid input\033[0m"<<endl;
           }
           cout<<"\033[34mpress enter to view homepage page\033[0m"<<endl;
           getch();
            goto home;
           }
           else if(Y=2){
            goto home;
           }
           else{
            cout<<"\033[31minvalid input\033[0m"<<endl<<"\033[34mpress enter to view homepage\033[0m"<<endl; 
            getch();
            goto home;
           }
           break;
           }
           case 2:{
            system("cls"); 
            cout<<"\033[1;33m***********************************************consumer details***********************************************************\033[0m"<<endl;
           ifstream D;
          D.open(username+".txt",ios::in|ios::app|ios::binary);
           if(!D){
           cout<<"\033[1;31m\nfile not found\033[0m"<<endl;
           }
           D.read((char*)&W,sizeof(W));
           while(!D.eof()){
           W.displayconsumerdata();
           W.displayBilldata();
           cout<<"______________________________________________________________________________________________________________________________"<<endl;
            D.read((char*)&W,sizeof(W));
            }
           cout<<endl;
           cout<<__TIMESTAMP__<<endl;
           D.close();
           Y=menucaseend();
           if(Y==1)
           {
            goto menu;
           }
           else if(Y==2)
           {
           goto home;
           }
           else
           {
            cout<<"\033[1;31minvalid input\033[0m"<<endl;
           }
           cout<<"\033[1;34mpress enter to view homepage page\033[0m"<<endl;
           getch();
            goto home;
            break;
            }
            case 3:{
                system("cls");
                cout<<"\033[1;33m*********************************************************search record*************************************************************\033[0m"<<endl;
                 cout<<"\033[1;35mEnter desired month:\033[0m"<<endl;
                 cin.ignore();
                  getline(cin,m);
                  B.searchrecord(m,username);
                  Y=menucaseend();
           if(Y==1)
           {
            goto menu;
           }
           else if(Y==2)
           {
           goto home;
           }
           else
           {
            cout<<"\033[1;31minvalid input\033[0m"<<endl;
           }
           cout<<"\033[1;34mpress enter to view homepage page\033[0m"<<endl;
           getch();
            goto home;
                  break;
            }
            case 4:{
                cout<<"\033[1;33m**********************************************************************delete record*********************************************************\033[0m"<<endl;
                system("cls");
                cout<<"\033[1;35mEnter desired month:\033[0m"<<endl;
                 cin.ignore();
                  getline(cin,m);
                  B.deleterecord(m,username);
                  Y=menucaseend();
           if(Y==1)
           {
            goto menu;
           }
           else if(Y==2)
           {
           goto home;
           }
           else
           {
            cout<<"\033[1;31minvalid input\033[0m"<<endl;
           }
           cout<<"\033[1;34mpress enter to view homepage page\033[0m"<<endl;
           getch();
            goto home;
                  break;
            }
            case 5:{/*view bill rate*/
                      viewBillrate();
                goto menu;
                break;
                   }
                   case 6:{/*return to home page*/
                    goto home;
                    break;
                   }
            default:
                cout<<"\033[1;31mInvalid input!!!\033[0m"<<endl;
             cout<<"\033[1;34mpress enter to view homepage page\033[0m"<<endl;
           getch();
            goto home;
            break;
          }
          break;
        }
        /*home ko case*/
            case 3:{ 
                system("cls");
           Y= adminlogin();
                if(Y==0){
                    cout<<endl;
                    cout<<"\033[1;34m press enter to goto home page\033[0m";
                    getch();
                    goto home;
                    }
                    system("cls");
            cout<<"\033[1;33m***************************************************ADMIN PAGE***************************************************************\033[0m"<<endl;
            cout<<endl; 
            cout<<"\033[1;34m1.view current Bill Rate"<<endl;
            cout<<"2.Update Bill Rate\033[0m"<<endl;
            cout<<"\033[1;32mEnter your choice\033[0m"<<endl;
            cin>>ch3;
            switch (ch3)
            {
               case 1:/*view bill rate*/
                viewBillrate();
                goto home;
                break;
                case 2:/* update bill rate*/
                readbillvar();
                goto home;
                break;
                default:cout<<"\033[1;31mInvalid input!!!\033[0m"<<endl;
                cout<<"\033[1;34mpress enter to view homepage page\033[0m"<<endl;
             getch();
             goto home;
                break;
            }
            break;
            }
            case 4:{
                system("cls");
                cout<<"\033[1;33m********************************************************Contact Us*******************************************************************\033[0m"<<endl;
                 cout<<endl;
                 cout<<"\033[1;34mcontact us in case of any query or feedback:"<<endl;
                 cout<<"Ph:-0123456789"<<endl;
                 cout<<"mail:electricitybillingsystem@email.com\033[0m"<<endl;
                 cout<<endl;
                 cout<<"\033[1;32mpress enter to goto homepage\033[0m"<<endl;
                 getch();
                 goto home;
                  break;
            }
             case 5:{
                system("cls");
              cout<<"\033[1;36mDO YOU WANT TO EXIT(Y/N)\033[0m"<<endl;
              cin>>m;
              if(m=="y"||m=="Y")
	           {
                 exit(0);
               }
                 else{
                      goto home;
                   }
              break;
             }
              default:cout<<"\033[1;31minvalid input!!!\033[0m"<<endl;
              cout<<"\033[1;34mplease enter your choice between 1 to 4\033[0m"<<endl;
    }
   getch();
  return 0;
    }

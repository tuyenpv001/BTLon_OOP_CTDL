#include<iostream>
#include<fstream>
#include<windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctime>
using namespace std;
char load = 219;

struct Node { 
   string NAME,PIN_N,MOBILE,STK_c,DATE; 
   int AMOUNT;
   Node *prev; 
   Node *next; 
}; 

class Double_Pointer_Linked{
	private:	
		Node *head,*tail;
	public:
		
		Double_Pointer_Linked();
		void insert(string N,string P,string M,string C,int A,string D);
		void Create_New_Account(string N,string P,string M,string C,int A,string D);
		void display_ALL();
		void Update(Node* obj);
		void Deposit(string ID1,int New_amount);
		void Withdraw_Amount(string ID1,int New_amount);
		void Search_Account(string ID1,string no);
	
};

class Bank{
	public:
		
			//Ham ve duong dong tren cung
		virtual void starting_line( string a){	
		};
		//Ham gioi thieu thanh vien nhom
		virtual void group_introduction(){	
		};
		//function Ham dang nhap 
		virtual bool User_login(){	
		};
		virtual int main_manu(){
		}
		// Ham cai dat
		virtual int setting(){
		}
		virtual void change_user_id()
		{
		}
		virtual void change_user_PIN() 
		{
		}
		virtual void logout(){
		}
		virtual void Create_Account(){
		}
		virtual bool login_user_account(){
		}
	
		virtual void Search_accounts(){
		}
		virtual int User_Login_Manu(){
		}
		virtual void Withdraw(){
		}
		virtual void Detail(){
		}
		virtual string IntToString(int a){
		}
		virtual void Deposit(){
		}
		virtual void Display_Accounts(){
		}
		
};
class Customer: public Bank{
	private:
		char password;
		string id ,Phone,STK,pin,retype_pin,date;
		int length,Total_amount;
	public:
		void Create_Account();
		void Display_Accounts();	
};

class Login:public Bank {
	public:
		void starting_line( string a);
		void group_introduction();
		bool User_login();
};

class Man_u:public Bank{
	private:
		string ID,PIN, confirm_pin;
		char password,password2;
		int confirm;
	public:
		int main_manu();
		int setting();
		void logout();
		void change_user_id();
		void change_user_PIN();
};

class User_Account:public Bank{
	private:
		string id,check_id,pin,check_pin,data,data1,data2,data3,data4;
		int password,length,no,g;
		int index,index1,index2,position;
		int W,D;
	public:
		bool login_user_account();	
		void Search_accounts();
		int User_Login_Manu();
		void Detail();
		void Withdraw();
		void Deposit();
};


Double_Pointer_Linked::Double_Pointer_Linked()
	{
		head=NULL;
	}
void Double_Pointer_Linked::insert(string N,string P,string M,string C,int A,string D){
	   Node* newnode = new Node; 
	   newnode->NAME  = N; 
	   newnode->PIN_N  = P;
	   newnode->MOBILE  = M;
	   newnode->STK_c  = C;
	   newnode->AMOUNT  = A;
	   newnode->DATE  = D;
	   newnode->next = NULL;
	   	newnode->prev = NULL;     
	   if(head ==  NULL) 
	   {
	   	head = newnode;
	   	tail=newnode;
	   }
	   else
	   {
	   	tail->next = newnode ;
		newnode->prev=tail;     
	    tail=newnode;
	   }   
}

void Double_Pointer_Linked::Create_New_Account(string N,string P,string M,string C,int A,string D){
		int n         ;                
		ifstream r("count.txt");
        if(r)
        {
            r>>n;
        }
        r.close();
        ifstream w("User.txt");
        string VL1,VL2,VL3,VL4,VL6;
        int VL5;
        Double_Pointer_Linked ob;
		for(int i=0;i<n;i++)
		{
			w>>VL1;
			w>>VL2;
			w>>VL3;
			w>>VL4;
			w>>VL5;
			w>>VL6;
			insert(VL1,VL2,VL3,VL4,VL5,VL6);
			i=i+5;	
		}
		insert(N,P,M,C,A,D);
		Node* ptr;
		Update(ptr);
	
}

void Double_Pointer_Linked::display_ALL(){
	int n;                
	ifstream r("count.txt");
    if(r)
    {
        r>>n;
    }   
    r.close();
    ifstream w("User.txt");
    string VL1,VL2,VL3,VL4,VL6;
    int VL5;
    Double_Pointer_Linked ob;
	for(int i=0;i<n;i++)
	{
		w>>VL1;
		w>>VL2;
		w>>VL3;
		w>>VL4;
		w>>VL5;
		w>>VL6;
		insert(VL1,VL2,VL3,VL4,VL5,VL6);
		i=i+5;	
	}
   Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
   cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<"   Ten : "<< ptr->NAME <<endl;
    cout<<"\t\t\t\t\t"<<"   SDT : "<< ptr->MOBILE <<endl;
    cout<<"\t\t\t\t\t"<<"   STK : "<< ptr->STK_c <<endl;
    cout<<"\t\t\t\t\t"<<"   So tien : "<< ptr->AMOUNT <<endl;
    cout<<"\t\t\t\t\t"<<"   Ngay : "<< ptr->DATE <<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    ptr = ptr->next; 
  } 
}

void Double_Pointer_Linked::Update(Node* obj){
	Node* ptr;
	ptr=obj;
   ptr = head;  
   ofstream w("User.txt");
   while(ptr != NULL) { 
      w<< ptr->NAME <<endl;
      w<< ptr->PIN_N <<endl;
      w<< ptr->MOBILE <<endl;
      w<< ptr->STK_c <<endl;
      w<< ptr->AMOUNT <<endl;
      w<< ptr->DATE <<endl;
      ptr = ptr->next; 
  } 
}

void Double_Pointer_Linked::Deposit(string ID1,int New_amount){
		int n         ;                
		ifstream r("count.txt");
        if(r)
        {
            r>>n;
        }
        
        r.close();
        ifstream w("User.txt");
        string VL1,VL2,VL3,VL4,VL6;
        int VL5;
        Double_Pointer_Linked ob;
	for(int i=0;i<n;i++)
	{	
		w>>VL1;
		w>>VL2;
		w>>VL3;
		w>>VL4;
		w>>VL5;
		w>>VL6;
		insert(VL1,VL2,VL3,VL4,VL5,VL6);
		i=i+5;
		
	}

   Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
   if(ptr->NAME==ID1 )
   {
   	 
      ptr->AMOUNT=ptr->AMOUNT+New_amount;
      
	Update(ptr);
   }
      ptr = ptr->next; 
  } 
}

void Double_Pointer_Linked::Withdraw_Amount(string ID1,int New_amount){
	int n;                
		ifstream r("count.txt");
        if(r)
        {
            r>>n;
        }
        
        r.close();
        ifstream w("User.txt");
        string VL1,VL2,VL3,VL4,VL6;
        int VL5;
        Double_Pointer_Linked ob;
	for(int i=0;i<n;i++)
	{
		w>>VL1;
		w>>VL2;
		w>>VL3;
		w>>VL4;
		w>>VL5;
		w>>VL6;
		insert(VL1,VL2,VL3,VL4,VL5,VL6);
		i=i+5;
		
	}

   Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
   if(ptr->NAME==ID1 )
   {
   	 if(ptr->AMOUNT<New_amount)
   	 {
   		system("cls");
		system("color E1"); //Ham cai dat mau chu xanh
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
		cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" Xin loi!So du ngan hang thap "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
		cout<<load;
		cout<<"\n";
		getch();
		system("cls");
   	 	
		}
   	 else
      ptr->AMOUNT=ptr->AMOUNT-New_amount;
      
	Update(ptr);
   }
   
      ptr = ptr->next; 
  } 
}

void Double_Pointer_Linked::Search_Account(string ID1,string no){
	 int n;                
		ifstream r("count.txt");
        if(r)
        {
            r>>n;
        }
        
        r.close();
        ifstream w("User.txt");
        string VL1,VL2,VL3,VL4,VL6;
        int VL5;
        Double_Pointer_Linked ob;
	for(int i=0;i<n;i++)
	{	
		w>>VL1;
		w>>VL2;
		w>>VL3;
		w>>VL4;
		w>>VL5;
		w>>VL6;
		insert(VL1,VL2,VL3,VL4,VL5,VL6);
		i=i+5;
		
	}

	int c=0;
   Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
   if(ptr->NAME==ID1 || ptr->STK_c==no)
   {
   	 system("cls");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |     Chi Tiet    |     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    cout<<"\t\t\t\t\t"<<"   Ten : "<< ptr->NAME <<endl;
    cout<<"\t\t\t\t\t"<<"   SDT : "<< ptr->MOBILE <<endl;
    cout<<"\t\t\t\t\t"<<"   STK : "<< ptr->STK_c <<endl;
    cout<<"\t\t\t\t\t"<<"   So tien : "<< ptr->AMOUNT<<endl;
    cout<<"\t\t\t\t\t"<<"   Ngay : "<< ptr->DATE <<endl;
    cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
    c++;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
   }
   
      ptr = ptr->next; 
  } 
  if(c==0)
  {
  	system("cls");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"  Xin loi! Khong tim thay id  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
  }
}

void Login::starting_line(string a){
	system("cls");
	system("color 7d");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t"<<a<<endl<<endl<<endl;
	for(int i=0;i<118;i++)
	{
		Sleep(15);
		cout<<load;
	}
	system("CLS");
}

void Login::group_introduction(){
	system("color E1");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     |  Thanh Vien Nhom  |    "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"        Nguyen Lam Truc       "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"        Nguyen Tien Trinh     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"        Nguyen Anh Tuan       "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"        Phan Van Tuyen        "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"   Dang Quang Truong Nguyen   "<<load<<endl;	
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	getch();	
	system("cls");
	system("color E1");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n\n\n";
	cout<<"\t\t\t      Loading ";
	
	for(int i=0; i<35; i++)
	{
		cout<<load;
		if(i<10)
		Sleep(300);
		if(i>=10 && i<20)
		Sleep(150);
		if(i>=10)
		Sleep(25);
	}
	system("cls");
}

bool Login::User_login(){
	string user_id, pin,compare_id,compare_pin;
	char password;
	system("color E1");
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=32;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"  QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=32;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |    Dang nhap    |      "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"       Vui long dang nhap      "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     Su dung id va Password    "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     dang nhap vao phan mem    "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                               "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=32;i++)
		cout<<load;
	cout<<"\n";
	ifstream rd("user login.txt");
	if(!rd.is_open())
	{
		ofstream wrt("user login.txt");
		wrt<<"root\n";
		wrt<<"1234";
	}
	else
	{
		rd>>compare_id;
		rd>>compare_pin;
		cout<<"\n\t\t\t\t\t  User ID:   ";
	    cin>>user_id;
	    cout<<"\t\t\t\t\t      PIN:   ";
			
	    while(password!=13) 
	    {
			   if(password>=48 && password<=57) 
			{
				pin.push_back(password);
	            cout << '*';
			}
	     	password = _getch(); 

		}
	}
	
	if(user_id==compare_id && pin==compare_pin) 
	return true;
	else
	return false;
	
}


void Customer::Create_Account(){
	system("color E1");
	id="\0";
	Phone="\0";
	STK="\0";
	pin="\0";
			
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |  Tai khoan moi  |     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t  Ten nguoi dung : ";  
	          
	cin>>id;
	length=0;
	password=0;
	
	cout<<"\t\t\t\t\t  PIN       : ";
	 while( length!=6)
	    {
		   if (password>=48 && password<=57)
		{
			pin.push_back(password);
            cout <<"*";
            length++;
		}
      password = _getch(); 

	}
	
	length=0;
	password=0;
	cout<<"\n\t\t\t\t\t  SDT    : ";
	 while( length!=10) 
	    {
		   if(password>=48 && password<=57) 
		{
			Phone.push_back(password);
            cout << password;
            length++;
            if(length==4)
            cout<<"-";
		}
      password = _getch(); 

	}
	length=0;
	password=0;
	cout<<"\n\t\t\t\t\t  STK      : ";
	while(length!=12) 
	    {
		   if(password>=48 && password<=57) 
		{
			STK.push_back(password);
            cout << password;
            length++;
            if(length==4 || length == 8)
            cout<<"-";
		}
      password = _getch(); 

	}
	cout<<"\n\t\t\t\t\t  Ngay     : ";
	time_t now = time(0);
    tm *ltm = localtime(&now);

   cout << ltm->tm_mday;
   cout << "/"<< 1 + ltm->tm_mon;
   cout << "/" << 1900 + ltm->tm_year << endl;
   
   cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
	cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";

	string a;
	ofstream te("t.txt");
	te<<ltm->tm_mday<<":"<<1 + ltm->tm_mon<<":"<<1900 + ltm->tm_year<<endl;
	te.close();
	ifstream to("t.txt");
	to>>a;
	Double_Pointer_Linked Ob;
	Ob.Create_New_Account(id,pin,Phone,STK,50000,a);
	ifstream r("count.txt");
		int i=0;
        if(r)
        {
            r>>i;
            ofstream s( "count.txt");
            i=i+6;
            s<<i;
        }
        else
        {
            ofstream s( "count.txt");
            i=0;
            i=i+6;
            s<<i;
        }
       
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n\n";
	cout<<"\t\t\t\t\t"<<load<<"   Tao tai khoan thanh cong   "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n\n";
        r.close();

}

void Customer::Display_Accounts(){
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     | Tat ca tai khoan  |    "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	
    Double_Pointer_Linked ob;
	ob.display_ALL();	
}

int Man_u::main_manu(){
	int Select;
	do{
		system("cls");
		system("color E1"); 
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=33;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"  QUAN LY TAI KHOAN NGAN HANG   "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=33;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"       |     Lua chon    |      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"       ~~~~~~~~~~~~~~~~~~~      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                                "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"    [1]  :  Tao tai khoan       "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"    [2]  :  Dang nhap TK        "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"    [3]  :  Hien thi TK         "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"    [4]  :  Tim TK              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"    [5]  :  Cai dat             "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      Dang xuat (Nhan: esc)     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"________________________________"<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=33;i++)
			cout<<load;
		cout<<"\n";
		
		Select=_getch();
	}while(Select!='1'&&Select!='2'&&Select!='3'&&Select!='4'&&Select!='5'&&Select!='6'&&Select!=27);
	return Select; 
			
}

int Man_u::setting(){
	int Select;
	do{
		system("cls");
		system("color E1"); 
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |     Cai dat     |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [1]   :  Doi ID         "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [2]   :  Doi ma PIN     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      Quay lai (<-Backspace)  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		
		Select=_getch();
	}while(Select!='1'&&Select!='2'&&Select!=8);
	return Select;  
}

void Man_u::logout(){
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t";
	cout<<"Dang xuat.";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);	
}

void Man_u::change_user_id(){
	system("cls");
	string ID,PIN;
	int confirm;
	ifstream read("user login.txt");
	read>>ID;
	read>>PIN;
	read.close();
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |     Cai dat     |     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ID moi :";
	cin>>ID;
	
	cout<<"\t\t\t\t\t"<<load<<"      Xac nhan ID moi  (Y/N)  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	confirm=_getch();
			
			if(confirm=='y' || confirm=='Y')
			{
				ofstream wrt("user login.txt");
			    wrt<<ID<<endl;
			    wrt<<PIN;
			    wrt.close();
			}
			else if(confirm=='n' || confirm=='N')
			{
			}
		
			else
			change_user_id();
			system("cls");	
}

void Man_u::change_user_PIN(){
				
	ifstream read("user login.txt");
	read>>ID;
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |     Cai dat     |     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      -------------------     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t       Ma PIN moi :     ";
	 
	while(password!=13)
	    {
		   if(password>=48 && password<=57)  
		{
			PIN.push_back(password);  
            cout << '*';
		}
      password = _getch();

	}
	cout<<endl;
	cout<<"\t\t\t\t\t       Xac nhan ma PIN : ";
	
	while(password2!=13)  
	    {
		   if(password2>=48 && password2<=57)  
		{
			confirm_pin.push_back(password2); 
            cout << '*';
		}
      password2 = _getch();

	}
	cout<<endl;
	cout<<"\t\t\t\t\t"<<load<<"            Gui (Y/N)         "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
	confirm=_getch();
	
			if(confirm=='y'|| confirm=='Y')
			{
				if(PIN==confirm_pin)
			{
				ofstream wrt("user login.txt");
			    wrt<<ID<<endl;
			    wrt<<PIN;
			    
			    wrt.close();
			}
			}
			else  if(confirm=='n'|| confirm=='N')
	     	{	}
	
		else
		{
			cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n\n";
	        cout<<"\t\t\t\t\tVui long dang nhap dung ID va PIN\n\n";
         	cout<<"\t\t\t\t\t";
	for(int i=0;i<=31;i++)
		cout<<load;
	cout<<"\n";
			change_user_PIN();
		}
			
			read.close();	
}  
bool User_Account::login_user_account(){
	bool log=false;
	system("color E1");
	length=0;
	password=0;
	pin="\0";
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
		cout<<load;
	cout<<"\n";
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      |    Dang nhap    |     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t  Ten nguoi dung : ";
	cin>>id;
	cout<<"\t\t\t\t\t  PIN : ";
	while(password!=13 ) 
	    {
		   if (password>=48 && password<=57) //chi lay gia tri dang so
		{
			pin.push_back(password);
            cout <<"*";
            length++;
		}
      password = _getch(); //lay ki tu de so sanh

	}
	ifstream r("count.txt");
        if(r)
        {
            r>>no;
        }
        
        r.close();
        ifstream w("User.txt");
	for(int i=0;i<no;i++)
	{
		cout<<endl;
		w>>check_id;
		w>>check_pin;
		w>>data1;
		w>>data2;
		w>>data3;
		w>>data4;
		if(check_id==id && check_pin==pin)
		{
			
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)
			cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t       XIN CHAO  ["<<check_id<<"]"<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			position=i;
			cout<<"\t\t\t\t\t";
			for(int j=0;j<=31;j++)
				cout<<load;
			cout<<"\n\n";
			getch();
			log=true;
		}
		i=i+5;
		
	}
	w.close();
	if(log==false)
	{
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
		cout<<load;	 
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"     Mat khau khong dung      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
		cout<<load;
		cout<<"\n\n";
		getch();
	}
	return log;	
	
}

void User_Account::Search_accounts(){
	system("color E1");
	length=0;
	password=0;
	pin="\0";
	int option;
	do{
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
		cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |     Tim kiem    |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [1]  : Ten nguoi dung   "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [2]  : STK              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      Quay lai (<-Backspace)  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		option=getch();
	}while(option!='1' && option!='2' && option!= 8);
	string id1,cn;
	if(option=='1')
	{
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |     Tim kiem    |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |  Ten nguoi dung |     "<<load<<endl;		
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t   Ten nguoi dung  : ";
		cin>>id1;
	}

	if(option=='2'){
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |  Tim kiem STK  |      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t      STK : ";
		char p=0;
		while(p!=13 /*&& length!=13*/) 
		    {
				   if(p>=48 && p<=57)
				{
					pin.push_back(p);
		            cout << p;
		            length++;
		            if(length==4 || length == 8)
		            cout<<"-";
				}
		      	p = _getch(); 
	
			}
	}
	cn=pin;
	Double_Pointer_Linked ob;
	if(option!=8)
	ob.Search_Account(id1,cn);	
}

int User_Account::User_Login_Manu(){
	int S;
	do{
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |  TK nguoi dung  |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [1]   :   Gui tien      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [2]   :   Rut tien      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      [3]   :   Chi tiet      "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"______________________________"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      Quay lai (<-Backspace)  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		S=_getch();
	}while(S!='1'&&S!='2'&&S!='3'&&S!=8);
	return S;	
}

void User_Account::Detail(){
	Double_Pointer_Linked obj;
	obj.Search_Account(id,"0");
	getch();
}
void User_Account::Withdraw(){
	do{
		system("cls");
		int take1;
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"  QUAN LY TAI KHOAN NGAN HANG "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |   So tien gui   |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t      So tien  : ";
		cin>>W;
		if(W<=0)
		{
			cout<<"\n\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"     Nhap gia tri hop le      "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
			getch();
		}
	
	}	while(W<=0);
			
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     Dong y : ('Y' hoac 'y')  "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"     Khong : ('N' hoac 'n')   "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
		cout<<load;
	cout<<"\n";
	
	do{
		g=getch();
	}while(g!='Y'&&g!='y'&&g!='N'&&g!='n');
	system("cls");
	if(g=='Y'||g=='y')
    {
    	Double_Pointer_Linked Ob;
        Ob.Deposit(id,W);
          cout<<"\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	        cout<<"\t\t\t\t\t           Dang xu ly.";
	        Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
				cout<<".";
				Sleep(500);
	        cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
	    Detail();       
    }	
}
void User_Account::Deposit(){
	do{
		system("cls");
		int take1;
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
			cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      |     Rut tien    |     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"      ~~~~~~~~~~~~~~~~~~~     "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t       So tien  : ";
		cin>>W;
		if(W<=0)
		{
			cout<<"\n\t\t\t\t\t";
			for(int i=0;i<=31;i++)
				cout<<load;
			cout<<"\n";
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"     Nhap gia tri hop le      "<<load<<endl;
			cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
			cout<<"\t\t\t\t\t";
			for(int i=0;i<=31;i++)
				cout<<load;
			cout<<"\n";
			getch();
		}
		
	} while(W<=0);
	
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"    Dong y : ('Y' hoac 'y')   "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"    Khong : ('N' hoac 'n')    "<<load<<endl;
	cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
	cout<<"\t\t\t\t\t";
	for(int j=0;j<=31;j++)
		cout<<load;
	cout<<"\n";
	do{
		g=getch();
	} while(g!='Y'&&g!='y'&&g!='N'&&g!='n');
	system("cls");
	if(g=='Y'||g=='y')
    {
       Double_Pointer_Linked Ob;
       Ob.Withdraw_Amount(id,W);
        cout<<"\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t\t           Dang xu ly.";
        Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(500);
        cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        Detail();
      
    }
}

int main(){
	Bank* a[4];
	Login obj1;  
	Man_u obj2;
	Customer obj3;
	User_Account obj4;
	a[0]=&obj1;//Tao 1 doi tuong cua lop bank
	a[1]=&obj2;
	a[2]=&obj3;
	a[3]=&obj4;
	int select2;
	a[0]->group_introduction();
	system("cls");
	string wlm="CHAO MUNG DEN VOI QUAN LY TAI KHOAN NGAN HANG";
    a[0]->starting_line(wlm);
    while(true){
    	system("cls");
    	bool check;  
	check=a[0]->User_login(); 
	if(check==true)  //neu dung se dang nhap vao phan mem
	{
		int Select;
		wlm="     CHAN THANH CAM ON!!";
		a[0]->starting_line(wlm);
		do{
			system("cls");
		Select=a[1]->main_manu();
		system("cls");
		if(Select=='1')
		{
			a[2]->Create_Account();
			_getch();
		}
		else if(Select=='2')
		{
			bool c;
			do{
			system("cls");
		    c=	a[3]->login_user_account();
	}
		    while(c==false);
		    if(c==true)
			do{
			select2=a[3]->User_Login_Manu();
			if(select2=='1'){
				a[3]->Withdraw();
				_getch();
			}
			if(select2=='2'){
				a[3]->Deposit();
				_getch();
			}
			if(select2=='3')
			{
				a[3]->Detail();
		     	_getch();
			}
			
			}while(select2!=8);
			select2=0;
		}
		
		else if(Select=='3')
		{
			a[2]->Display_Accounts();
			_getch();
		}
	
		else if(Select=='4')
		{
			a[3]->Search_accounts();
			_getch();
		}
		else if(Select=='5')   
		{
			do{
			select2=a[1]->setting();
			if(select2=='1')  
			{
				a[1]->change_user_id();
				_getch();
			}
			else if(select2=='2')  
			{
				system("cls");
				a[1]->change_user_PIN();
				_getch();
			}
		}while(select2!=8);
		}
		else if (Select==27)
		{
			a[1]->logout();
			string wlm="              Dang xuat ";
            a[0]->starting_line(wlm);
		}
		}
		while(Select!=27 );
	}
	else 
	{    
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t";
		for(int i=0;i<=31;i++)
		cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<" QUAN LY TAI KHOAN NGAN HANG  "<<load<<endl;
		cout<<"\t\t\t\t\t"<<load<<"                              "<<load<<endl;
		cout<<"\t\t\t\t\t";
		for(int j=0;j<=31;j++)
		cout<<load;
		cout<<"\n";
		cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	    cout<<"\t\t\t\t\t  Vui long nhap dung ID va PIN  \n";
     	cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     	_getch();
	}
} 
	
}		

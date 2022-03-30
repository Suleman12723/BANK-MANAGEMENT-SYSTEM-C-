#include <windows.h>
#include <iostream>
#include "fstream"
#include <string>
using namespace std;
int amount;
string username;
string user_password;
int age;
char gender;
int counter;
string admin_name;
string admin_password;
int admin_counter;

 
struct users
{
	string name;
	string password;
	int cash;
	char gender;
	int age;
	int donation;	
	
}obj[100];

struct admins
{
	string admin_name;
	string admin_pass;
	
}admin[100];

/////////////////////////////////////////////// ALL FUNCTIONS PROTOTYPE/////////////////////////////////////////////////////////////////////////////////
int modules();
void User_module();
void checker();
bool checked_true();
void Login();
void menu_print();
bool check_login();
void withdraw_money();
void deposit_money();
void request_balance();
void online();
void donation();
void QUIT();
void edit_file();
void Admin_module();
void admin_Login();
bool check_admin_login();
bool admin_checked_true();
void Total_customers();
void amount_all();
void sort_on_cash();
void highest_balance();
void by_name();
void greater_than_10();
void user_age();
void age_greater_than_30();
void highest_donor();
void lowest_balance();
void youngest_ones();
void total_donated();
void find();
///////////////////////////////////////////////////// FUNCTIONS BEFORE USER MODULE //////////////////////////////////////////////////////////////////////

void read_user_file()
{
	ifstream in("users.txt");
	int i=0;
	while(!in.eof())
	{   
		in >> obj[i].name;
		in >> obj[i].password;
		in >> obj[i].cash; 
		in >> obj[i].gender;
		in >> obj[i].age;
		in >> obj[i].donation;
		i++;
		
	}
	counter = i;
}

void edit_file()
{
	for(int i=0; i<counter; i++)
		{
			if(username==obj[i].name && user_password==obj[i].password)
			{
					obj[i].cash=amount;
					
			}
		}	
	ofstream in("temp.txt");
		for(int i=0; i< counter-1; i++)
		{
			in << obj[i].name << endl;
			in << obj[i].password << endl;
			in << obj[i].cash <<endl;
			in << obj[i].gender <<endl;
			in << obj[i].age<<endl;
			in << obj[i].donation<<endl<<endl;
		}
		in.close();
		remove("users.txt");
		rename("temp.txt","users.txt");
}



//////////////////////////////// MENU AFTER LOGIN//////////////////////////
void menu_print()
{
	cout<<endl;
	cout<<"CHOOSE FROM THE MENU: "<<endl;
	cout<<"1. WITHDRAW MONEY"<<endl;
	cout<<"2. DEPOSIT MONEY"<<endl;
	cout<<"3. REQUEST BALANCE"<<endl;
	cout<<"4. Online Transaction such as Paying Elcetricity bill"<<endl;
	cout<<"5. DONATION FOR Diamer Bhasha and Mohmind Dam"<<endl;
	cout<<"6. QUIT THE PROGRAM"<<endl;
}




//////////////////////////////////// WITHDRAW MONEY/////////////////////////////////

void withdraw_money()
{
	int amount_user;
	cout<<"Your Balance is: "<<amount<<endl; 
	cout<<"how much money you want to with draw"<<endl;
	cout<<"ENTER THE AMOUNT: ";
	cin>>amount_user;
	
	if(amount_user<=amount)
	{	
		string n;
		string p;
		int c;
		
		
		amount = amount - amount_user; 
		edit_file();
		cout<<"your remaining amount is: "<<amount<<endl<<endl;
	}
	else
	{
		cout<<"Your current balance is insufficent for this transaction"<<endl;
		cout <<"Your current balance is: "<<amount<<endl<<endl;
	}
	
}


///////////////////Deposit money/////////////////////////////////////////////

void deposit_money()
{
	cout<<endl<<"your current balance is: "<<amount;
	int cash;
	cout<<endl<<"How much money you want to deposit: ";
	cin>>cash;
	amount=amount+cash;
	edit_file();
	cout<<endl<<"your balance now is: "<<amount<<endl;
	Sleep(1000);
}



/////////////////////////////////// RQUEST BALANCE////////////////////////////

void request_balance()
{
	cout<<"your current balance is: ";
	cout<<amount;
	cout<<endl;
	Sleep(1000);
}


////////////////////////////Online bill //////////////////////////

void online()
{
	int choose;
	int payment;
	cout<<endl<<"choose which bill you want to pay: "<<endl;
	cout<<"1. Electricity\n2. Gas\n3. Telephone"<<endl;
	cout<<"Enter: ";
	cin>>choose;
	cout<<"Enter the amount of your bill: ";
	cin>>payment;
	if(amount > payment)
	{
		amount = amount -payment;
		edit_file();
		cout<<endl<<"Your bill have been paid\nYour raminning balance is: "<<amount<<endl;
		Sleep(1000);
	}
	else
	{
		cout<<endl<<"Your balance is insufficent for this transiction"<<endl;
	}
	
	
	
}



////////////////////////// Donation ///////////////////////////////////

void donation()
{
	int payment;
	int dona;
	cout<<"How much you want to donate: ";
	cin>>payment;
	amount=amount-payment;
	cout<<endl<<"Your remainning balance is: "<<amount;	
	dona=payment;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(username==obj[i].name && user_password == obj[i].password)
		{
			obj[i].donation=dona;
		}
	}
	
	edit_file();
	
}




///////////////////////////////// LOGIN //////////////////////////////////////
void Login()
{
	int ch;
	while(ch !=0)
	{

		
		menu_print();
		cout<<endl;
		cout<<"ENTER: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				withdraw_money();
				break;
			}
			case 2:
			{
				deposit_money();
				break;
			}
			case 3:
			{
				request_balance();
				break;
			}
			case 4:
			{
				online();
				break;
			}
			case 5:
			{
				donation();
				break;
			}
			case 6:
			{
				QUIT();
				break;
			}
		}	
	}		 
}

////////////////////////////// CHECKED TRUE////////////////////////////////////////
bool checked_true()
{
	read_user_file();
	for(int i=0; i<counter; i++)
	{
		if(username==obj[i].name && user_password==obj[i].password)
		{
				amount = obj[i].cash;
				return true;
		}
	}
	return false;
}



///////////////////////////////// LOGIN CHECK FUNCTION/////////////////////////
bool check_login()
{	
	cin.ignore();
	cout<<endl;
	cout<<"ENTER YOUR NAME: ";
	getline(cin,username);
	
	cout<<"ENTER THE PASSWORD: ";
	getline(cin,user_password);
	
	if(checked_true())
	{
		return true;
	}
	else
	{
		cout<<"ENTERD PASSWORD OR USERNAME IS INCORRECT"<<endl<<endl;
		return false;
	}
	
}


///////////////////////////LOGIN CHECKER FUNCTION//////////////////////
void checker()
{
	if(check_login())
	{
		Login();
	}
		else
	{
		User_module();
	}
		
}



//////////////////////// CREATE AN ACCOUNT////////////////////////////
void Create_Acc()
{
	read_user_file();
	string name;
	string password;
	int cash;
	int new_age;
	char new_gender;
	int ch;
	int don=0;
	cout<<endl;
	cout<<"CHOOSE THE TYPE OF THE ACCOUNT: "<<endl;
	cout<<"1. Current\n2. Default\n";
	cin>>ch;
	if(ch==1 || ch==2 )
	{
		cin.ignore();
		cout<<"Enter a username: ";
		getline(cin,name);
		for(int i=0; i<counter-1; i++)
		{
			if(name==obj[i].name)
			{
				cout<<endl<<"The username you entered already exixts: "<<endl;
				User_module();
				
			}
		}
		
		
		cout<<"enter the password: ";
		getline(cin,password);
		
		cout<<"Enetr your Gender M or F:";
		cin>>new_gender;
		
		cout<<"Enter your age: ";
		cin>>new_age;
		
		cout<<"enetr the amount of cash you want to deposit for opening account: ";
		cin>>cash;
		
		
		
		
			ofstream in("users.txt",ios::app);
			in << endl << name << endl;
			in << password << endl;
			in << cash <<endl;
			in << new_gender << endl;
			in << new_age << endl;
			in << don <<endl;
			
		
		
	}
	cout<<endl;
	counter++;
	User_module();

}






//////////////////////////// QUIT ////////////////////////////////
void QUIT()
{
	exit(3);
}






/////////////////////////////////////////////////////////// USER MODULE ///////////////////////////////////////////////////////////////////////////
void User_module()
{
	
	
	int ch;
	cout<<endl<<"Enter a choice from the MENU: "<<endl;
	cout<<"1. LOGIN"<<endl;
	cout<<"2. CREATE A NEW ACCOUNT"<<endl;
	cout<<"3. QUIT"<<endl;
	cout<<"ENTER: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			checker();
			break;
		}
		case 2:
		{
			Create_Acc();
			break;
		}
		case 3:
		{
			QUIT();
			break;
		}
	
	}		
}


///////////////////////////////////////////////////////////// FUNCTIONS BEFORE ADMIN MODULE /////////////////////////////////////////////////////////////
void admin_menu()
{
	cout<<endl<<"CHOOSE FROM THE MENU: "<<endl;
	cout<<"1. Check Total number of Customers\n";
	cout<<"2. Total amount of all the customers\n";
	cout<<"3. Sort Customers w.r.t their balance (in increasing order and decreasing order)\n";
	cout<<"4. Find the customer with highest balance\n";
	cout<<"5. Search Customer by name and print its information\n";
	cout<<"6. Find total customers having balance greater than $10\n";
	cout<<"7. Find all the female customers with age greater than 20 and less than 30\n";
	cout<<"8. Find all the customers with age greater than 30 and less 45\n";
	cout<<"9. Find the customer who have donated highest amount for “ Diamer Bhasha and Mohmind Dam ”\n";
	cout<<"10. Find the Customer with lowest balance\n";
	cout<<"11. Find the youngest male and female customer.\n";
	cout<<"12. Find total customers whose name starts with  a  or  A \n";
	cout<<"13. Find total amount, your customers have donated for Diamer Bhasha and Mohmind Dam\n";
	cout<<"14. Quit\n";
}

/////////////////////////////// TOTAL CUSTOMERS////////////////////////////////

void Total_customers()
{
	read_user_file();
	cout<<endl<<"Number of Customers: "<<counter-1<<endl;
	for(int i=0; i<counter-1; i++)
	{
		cout<<endl<<"Name: "<<obj[i].name<<endl;
	}
	Sleep(1000);
	
}

////////////////////////////AMOUNT OF ALL CUSTOMERS/////////////////////////////

void amount_all()
{
	int sum=0;
	cout<<"The total amount of each user is: "<<endl;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		cout<<obj[i].name<<" : "<<obj[i].cash<<endl;
		sum =sum+obj[i].cash;
	}
	cout<<endl<<"THE SUM OF AMOUNT OF ALL THE CUSTOMERS: "<<sum<<endl;
	Sleep(1000);
}

////////////////////////////SORT USERS ON BASIS OF CASH/////////////////////////

void sort_on_cash()
{
	read_user_file();
	int ch, count,index,min,temp_age, temp_don;
	string temp_name,temp_pass;
	char temp_gender;
	users obj2[100];
	int temp;
	int cmp=obj[0].cash;
	cout<<"Choose on wich order you want to sort users on basis of cash"<<endl;
	cout<<"1. Ascending\n2. Descending"<<endl;
	cin>>ch;
	if(ch==1)
	{
		for(int i=0;i<counter-1;i++)
		{		
			for(int j=i+1;j<counter-1;j++)
			{
				if(obj[i].cash>obj[j].cash)
				{
					temp  =obj[i].cash;
					obj[i].cash=obj[j].cash;
					obj[j].cash=temp;
					
					temp_name  =obj[i].name;
					obj[i].name=obj[j].name;
					obj[j].name=temp_name;
					
					temp_pass  =obj[i].password;
					obj[i].password=obj[j].password;
					obj[j].password=temp_pass;
					
					temp_gender  =obj[i].gender;
					obj[i].gender=obj[j].gender;
					obj[j].gender=temp_gender;
					
					temp_age  =obj[i].age;
					obj[i].age=obj[j].age;
					obj[j].age=temp_age;
					
					temp_don  =obj[i].donation;
					obj[i].donation=obj[j].donation;
					obj[j].donation=temp_don;
					
					
				}
			}
			
		
		}
	}
	else if(ch==2)
	{
		for(int i=0;i<counter-1;i++)
		{		
			for(int j=i+1;j<counter-1;j++)
			{
				if(obj[i].cash<obj[j].cash)
				{
					temp  =obj[i].cash;
					obj[i].cash=obj[j].cash;
					obj[j].cash=temp;
					
					temp_name  =obj[i].name;
					obj[i].name=obj[j].name;
					obj[j].name=temp_name;
					
					temp_pass  =obj[i].password;
					obj[i].password=obj[j].password;
					obj[j].password=temp_pass;
					
					temp_gender  =obj[i].gender;
					obj[i].gender=obj[j].gender;
					obj[j].gender=temp_gender;
					
					temp_age  =obj[i].age;
					obj[i].age=obj[j].age;
					obj[j].age=temp_age;
					
					temp_don  =obj[i].donation;
					obj[i].donation=obj[j].donation;
					obj[j].donation=temp_don;
				}
			}
			
		}
	}
			
	edit_file();
	
}

////////////////////////////// HIGHEST BALANCE//////////////////////////////////

void highest_balance()
{
	int co;
	int compare=0;
	read_user_file();

	
	for(int j=0; j<counter-1; j++)
	{
		if(compare <= obj[j].cash)
		{
			compare = obj[j].cash;
			co=j;	
		}
	}	

	cout<<"THE CUSTOMER WITH THE MOST BALANCE: "<<endl;
	cout<<"NAME: "<<obj[co].name<<endl;
	cout<<"CASH: "<<obj[co].cash<<endl;
	Sleep(1000);
}

//////////////////////////// SEARCH BY NAME/////////////////////////////////////

void by_name()
{
	string name;
	cout<<"Enetr the name of the customer you want to search: ";
	cin>>name;
	cout<<endl;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(obj[i].name == name)
		{
			cout<<"NAME: "<<obj[i].name<<endl;
			cout<<"AGE: "<<obj[i].age<<endl;
			cout<<"GENDER: "<<obj[i].gender<<endl;
			cout<<"PASSWORD: "<<obj[i].password<<endl;
			cout<<"CASH: "<<obj[i].cash<<endl;
		}
	}
	Sleep(1500);
	
}

//////////////////////////// GREATER THAN 10$ //////////////////////////////////

void greater_than_10()
{
	int c=1682;
	cout<<"According to current exchange rate 10$ = Rs. 1,682 "<<endl<<endl;
	cout<<"The customers having baance greater than 10$: "<<endl;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(obj[i].cash > c)
		{
			cout<<"NAME: "<<obj[i].name<<endl;
			cout<<"CASH: "<<obj[i].cash<<endl<<endl;
		}
	}
	Sleep(1000);
}
/////////////////// FEMALES GREATAER THAN 20 and less than 30 age///////////////

void user_age()
{
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(obj[i].gender='F' && (obj[i].age >20 && obj[i].age < 30 ))
		{
			cout<<"NAME: "<<obj[i].name<<endl;
			cout<<"AGE: "<<obj[i].age<<endl;
			cout<<"GENDER: "<<" "<<obj[i].gender<<endl;
			cout<<"PASSWORD: "<<obj[i].password<<endl;
			cout<<"CASH: "<<obj[i].cash<<endl;
		}
	}
	
}

///////////////////////////////// AGE GREATER THAN 30 AND LESS THAN 45/////////////////

void age_greater_than_30()
{
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(obj[i].age >30 && obj[i].age<45)
		{
			cout<<"NAME: "<<obj[i].name<<endl;
			cout<<"AGE: "<<obj[i].age<<endl;
			cout<<"GENDER: "<<" "<<obj[i].gender<<endl;
			cout<<"PASSWORD: "<<obj[i].password<<endl;
			cout<<"CASH: "<<obj[i].cash<<endl;
			
		}
	}
	
}

//////////////////////////// HIGHEST DONOR/////////////////////////////////////

void highest_donor()
{
	int donor=0;
	int ch;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(donor < obj[i].donation)
		{
			donor =obj[i].donation;
			ch=i;
		}
	}
	cout<<"NAME: "<<obj[ch].name<<endl;
	cout<<"DONATION: "<<obj[ch].donation<<endl<<endl;
	Sleep(1000);
	
}
//////////////////////////////// LOWEST BALANCE///////////////////////////////
void lowest_balance()
{
	read_user_file();
	int cl=0;
	int compare=obj[1].cash;
	

	for(int j=0; j<counter-1; j++)
	{
		if(compare >= obj[j].cash)
		{
			compare = obj[j].cash;
			cl=j;		
		}	
	}
	
		

	cout<<"THE CUSTOMER WITH THE LOWEST BALANCE: "<<endl;
	cout<<"NAME: "<<obj[cl].name<<endl;
	cout<<"CASH: "<<obj[cl].cash<<endl;
	Sleep(1000);
}

/////////////////////////////// YOUNGEST CUSTOMERS//////////////////////////////
void youngest_ones()
{
	read_user_file();
	int comparing_m=100;
	int comparing_f=100;
	int m,f;
	for(int i=0; i <counter-1; i++)
	{
		if(obj[i].gender=='M' && obj[i].age <comparing_m)
		{
			comparing_m=obj[i].age;
			m=i;
		}
		if(obj[i].gender=='F' && obj[i].age <comparing_f)
		{
			comparing_f = obj[i].age;
			f=i;
		}
	}
	

	cout<<"THE YOUNGEST MALE CUSTOMER IS: "<<endl;
	cout<<"NAME: "<<obj[m].name<<endl;
	cout<<"AGE: "<<obj[m].age<<endl;
	cout<<"CASH: "<<obj[m].cash<<endl<<endl;
	cout<<"THE YOUNGEST FEMALE CUSTOMER IS: "<<endl;
	cout<<"NAME: "<<obj[f].name<<endl;
	cout<<"AGE: "<<obj[f].age<<endl;
	cout<<"CASH: "<<obj[f].cash<<endl;

	
	Sleep(1000);
}



///////////////////////////// TOTAL AMOUNT DONATED//////////////////////////////

void total_donated()
{
	int sum=0;
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		
		sum=sum+obj[i].donation;
		
	}
	cout<<"THE TOTAL SUM OF AMOUNT DONATED BY ALL CUSTOMERS: "<<sum<<endl<<endl;
	
	Sleep(1000);
}

//////////////////////////// starts with a or A/////////////////////////////////

void find()
{
	
	read_user_file();
	for(int i=0; i<counter-1; i++)
	{
		if(obj[i].name[0] == 'a' || obj[i].name[0] =='A')
		{
			cout<<"NAME: "<<obj[i].name<<endl;
			cout<<"AGE: "<<obj[i].age<<endl;
			cout<<"GENDER: "<<obj[i].gender<<endl;
			cout<<"PASSWORD: "<<obj[i].password<<endl;
			cout<<"CASH: "<<obj[i].cash<<endl<<endl;
		}
	}
	Sleep(1500);	
}

////////////////////////////ADMIN LOGIN/////////////////////////////////////////

void admin_Login()
{
	
	int ch;
	while(ch !=0)
	{

		cout<<endl;
		admin_menu();
		cout<<endl;
		cout<<"ENTER: ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
			{
				Total_customers();
				break;
			}
			case 2:
			{
				amount_all();
				break;
			}
			case 3:
			{
				sort_on_cash();
				break;
			}
			case 4:
			{
				highest_balance();
				break;
			}
			case 5:
			{
				by_name();
				break;
			}
			case 6:
			{
				greater_than_10();
				break;
			}
			case 7:
			{
				user_age();
				break;
			}
			case 8:
			{
				void age_greater_than_30();
				break;
			}
			case 9:
			{
				highest_donor();
				break;
			}
			case 10:
			{
				lowest_balance();
				break;
			}
			case 11:
			{
				youngest_ones();
				break;
			}
			
			case 12:
			{
				find();
				break;
			}
			case 13:
			{
				total_donated();
				break;
			}
			case 14:
			{
				QUIT();
				break;
			}
		}	
	}
}



//////////////////////////////// ADMIN CHECKED TRUE///////////////////////////////

bool admin_checked_true()
{
	ifstream in("admins.txt");
	int i=0;
	while(!in.eof())
	{   
		in >> admin[i].admin_name;
		in >> admin[i].admin_pass;
		i++;
		
	}
	admin_counter = i;
	for(int i=0; i<admin_counter; i++)
	{
		if(admin_name==admin[i].admin_name && admin_password==admin[i].admin_pass)
		{
				return true;
		}
	}
	return false;
}


/////////////////////////////// LOGIN CHECKER//////////////////////////////
bool check_admin_login()
{	
	
	
	cout<<endl;
	cout<<"TO give space use '_' instead of space: "<<endl<<endl;
	
	cout<<"ENTER YOUR ADMIN NAME: ";
	cin>>admin_name;
	
	cout<<"ENTER THE PASSWORD: ";
	cin>>admin_password;
	
	
	if(admin_checked_true())
	{
		return true;
	}
	else
	{
		cout<<"ENTERD PASSWORD OR ADMIN NAME IS INCORRECT"<<endl<<endl;
		return false;
	}
	
}

	
//////////////////////////// ADMIN LOGIN CHECKER////////////////////	
void admin_checker()
{
	if(check_admin_login())
	{
		admin_Login();
	}
		else
	{
		Admin_module();
	}
		
}	






	
//////////////////////////////////////////////////////////// ADMIN MODULE ///////////////////////////////////////////////////////////////////////////////
void Admin_module()
{
	admin_checker();
	
	
}







////////////////////////////////////////////////////////////// FUNCTIONS BEFORE MAIN ////////////////////////////////////////////////////////////////////
int modules()
{
	int ch;
	cout<<"CHOOSE: "<<endl;
	cout<<"1. USER MODULE"<<endl;
	cout<<"2. ADMIN MODULE"<<endl;
	cout<<"ENTER: ";
	cin>>ch;
	return ch;
	
}




/////////////////////////////////////////////////////////////MAIN FUNCTION///////////////////////////////////////////////////////////////////////////////
int main()
{	
	
	int module=modules();
	switch(module)
	{
		case 1:
		{
			User_module();
			break;
		}
		case 2:
		{
			Admin_module();
			break;
		}
	}
	
	
	return 0;
}

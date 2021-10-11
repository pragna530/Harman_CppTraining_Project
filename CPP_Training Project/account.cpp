//preprocessor segment to include all the necessary header files.
#include<iostream>
#include<iomanip>

//declaring all the namespaces used
using namespace std;


//defining the class account with all user details
class account
{
    //all the variables declared as private
	int AccountNo;
	char CustomerName[50];
	int deposit;
	char AccountType;

public:
	
    //declaring all the functions
    void create_account();	
    void authenticate();	
	void show_account();	
	void modify();   
	void dep(int);
	void draw(int);	
	void report();	
	int retacno();	
	int retdeposit();	
	char rettype();	

};       

//to check if coustomers name is correct or not
void account::authenticate()
{
	int cname=0;

	for(int i=0;i<50;i++)
	{
		if(CustomerName[i]!='\0')
		{
			if(((CustomerName[i]>='a'&&CustomerName[i]<='z')||(CustomerName[i]>='A'&&CustomerName[i]<='Z'))||(CustomerName[i]==' '))
			continue;
			else
			cname++;
		}
		else
		break;
	}
	if(cname!=0)
	{
		
		cout<<"\nWarning: Invalid CustomerName! Terminating The program. Please try again later\n\n\n"<<endl;
        create_account();
	}
}


//function to create a new account and getting new user details
void account::create_account()
{  
    int number_of_digits = 0;

	cout<<"\nEnter The account No: ";
	cin>>AccountNo;
    
    int n=AccountNo;
    //calculating the number of digits in the account number and checking if it is 4.
    do
    {
       ++number_of_digits; 
       n /= 10;

    } while (n);
   
    if(number_of_digits!=4)
    cout<<"The Account number should be of 4 digits! Please try again!";
     
    
    else
    {
        cout<<"\n\nEnter The Name of The account Holder : ";
        cin.ignore();
        gets(CustomerName);
        authenticate();//checking if entered name is valid

        cout<<"\nEnter Type of The account (C/S) : ";
        cin>>AccountType;
        AccountType=toupper(AccountType);

        cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin>>deposit;

        cout<<"\nAccount Created Successfully!";
    }
}

//Display Account Details
void account::show_account()
{
	cout<<"\nAccount No. : "<<AccountNo;

	cout<<"\nAccount Holder Name : "<<CustomerName;
	
    cout<<"\nType of Account : "<<AccountType;
	
    cout<<"\nBalance amount : "<<deposit;
}


//to update or change user input
void account::modify()
{
	cout<<"\nThe account No: "<<AccountNo;

	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(CustomerName);
    authenticate();

	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>AccountType;
	AccountType=toupper(AccountType);

	cout<<"\nEnter The amount : ";
	cin>>deposit;
}

//update account when amt is deposited
void account::dep(int x)
{
	deposit+=x;
}

//update account when amt is withdrawn
void account::draw(int x)
{
	deposit-=x;
}

//Display all the user records
void account::report()
{
	cout<<AccountNo<<setw(20)<<setfill(' ')<<CustomerName<<setw(10)<<setfill(' ')<<" "<<AccountType<<setw(20)<<setfill(' ')<<deposit<<endl;
}

//return the account number
int account::retacno()
{
	return AccountNo;
}

//return the amt depisited
int account::retdeposit()
{
	return deposit;
}

//return the account type
char account::rettype()
{
	return AccountType;
}





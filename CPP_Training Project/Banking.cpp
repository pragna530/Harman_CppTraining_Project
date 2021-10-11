/*
    Objective: To Create a bank Management System for Customers.
	Author: Siri Pragna T
	Created On: October 10, 2021
	Modified On:
	Dependencies:

*/


//preprocessor segment to include all the header files necessary.
#include<iostream>
#include<fstream>
#include<ctype.h>
#include<stdio.h>
#include"Transactions.cpp" //including the transactions file which contains the functions.


//declaring all the namespaces required
using namespace std;

//Main Driver Code
int main()
{
	//declaring the variables.
	char mainChoice;
	int num;
	
	cout<<"\n\t\t\t*****WELCOME TO SIRI'S BANK*****";
	
	do
	{
	    //displaying the menu for customer input
		cout<<"\n\n\t\t\tOPTIONS FOR NET BANKING:";
		cout<<"\n1. CREATE NEW ACCOUNT";
		cout<<"\n2. DEPOSIT AMOUNT";
		cout<<"\n3. WITHDRAW AMOUNT";
		cout<<"\n4. BALANCE ENQUIRY";
		cout<<"\n5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n6. CLOSE AN ACCOUNT";
		cout<<"\n7. MODIFY AN ACCOUNT";
		cout<<"\n8. CALCULATE ACCOUNT INTEREST";
		cout<<"\n9. EXIT";
		cout<<"\nEnter The transaction which you want to perform: (1-8) ";
		cin>>mainChoice;
		
		switch(mainChoice)
		{
			case '1':write_account(); //writes the object data into the file and create account
			    	break;

			case '2':cout<<"\n\n\tEnter The account No. : "; 
					 cin>>num;
					 deposit_withdraw(num, 1);//to deposite the ammount
					 break;

			case '3':cout<<"\n\n\tEnter The account No. : ";
					 cin>>num;
				     deposit_withdraw(num, 2);//to withdraw the amount
					 break;

			case '4':cout<<"\n\n\tEnter The account No. : ";
					 cin>>num;
				 	 display_sp(num);//Display the Balance amount
					 break;

			case '5':display_all(); //display all the user records from the file
					 break;

			case '6':cout<<"\n\n\tEnter The account No. : ";
					 cin>>num;
					 delete_account(num);//to close an account
					 break;

			case '7':cout<<"\n\n\tEnter The account No. : ";
					 cin>>num;
					 modify_account(num);//to update any account details
					 break;

			case '8':cout<<"\n\n\tEnter The account No. : ";
					 cin>>num;
					 calculate_interest(num);//to calculate the interest.
					 break;

			case '9':cout<<"\n\n\n\n\t\t*** Thank you for Banking with us ***";
                     exit(0);
					 //exit

			default :cout<<"\nWrong Choice Entered!";
		}
		
	}while(mainChoice!='9');

	return 0;
}




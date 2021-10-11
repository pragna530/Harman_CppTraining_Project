
//Preprocessing segment to include all the header files
#include<iostream>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

#include"account.cpp" //including account class

//declaring all the namespaces used
using namespace std;




//function to write into the file and create account
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}


//Function to display the account details form the file account.txt
void display_sp(int n)
{
	account ac;
	int flag=0;

	ifstream inFile;
	inFile.open("account.txt",ios::in);
	
    if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
    cout<<"\nBALANCE DETAILS\n";
	
    while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	
    inFile.close();
	
    if(flag==0)
		cout<<"\n\nAccount number does not exist";
}



//Function to modity the account details in the file
void modify_account(int n)
{
	int found=0;

	account ac;
	fstream File;
	File.open("account.txt",ios::binary|ios::in|ios::out);
	
    if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	
    File.close();
	
    if(found==0)
		cout<<"\n\n Record Not Found ";
}




//delete any user form the file
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary|ios::in);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\n\tRecord Deleted ..";
}

//Display all the records present in the file
void display_all()
{
	account ac;

	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=========================================================\n";
	cout<<"A/c No.\t\tNAME\t\tType\t\tBalance\n";
	cout<<"=========================================================\n";
	
    while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


//to diposite and withdraw 
void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;

	account ac;
	fstream File;
	File.open("account.txt", ios::binary|ios::in|ios::out);
	
    if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
            //to deposite the amount
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
	
            //if user wants to withdraw the amount
    		if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}

			int pos=(-1)* sizeof(ac);
			
            File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));//updating in the file
			
            cout<<"\n\n\t Record Updated";
			found=1;

	       }
	}
	File.close();

	if(found==0)
		cout<<"\n\n Record Not Found ";
}

void calculate_interest(int n)
{
  int rate=2,months;
  cout<<"Enter the number of months: ";
  cin>>months;

  int interest= (2*n*months)/100;

  cout<<"\nTotal interest for "<<months<<" months = "<<interest;

}
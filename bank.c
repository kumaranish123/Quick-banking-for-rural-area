//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//char acc_num[20];               
//char acc_holder_name[50];
//float net_blnc=0.0;
//char acc_no[20];                
//
//char choice;					
//float amt;						
//float cred,deb,trans_bal;
//int accnt_exists=0;					
//int proceed=0;					
//FILE * file ;
//
//void create_account();
//int get_accnt_indx();
//void account_info();
//void deposit();
//void withdraw();
//void passbook();
//
//void main(){
//
//	while(1)
//		{
//			system ("CLS");
//			printf("****************************************************\n");
//			printf("\n\n				||Bank of Cs||	\n\n");
//			printf("****************************************************\n");
//			printf("Please choose the desired service number:\n");
//			printf("1.Account creation\n");
//			printf("2.Account information\n");
//			printf("3.Deposit amount\n");
//			printf("4.Withdraw amount\n");
//			printf("5.Access Passbook\n\n");
//			printf("Enter any number to return to the main menu from elsewhere\n");
//			scanf(" %c",&choice);
//
//			switch(choice){
//				case '1':	system ("CLS");
//							create_account();
//							break;
//
//				case '2': 	system ("CLS");
//							accnt_exists=get_accnt_indx();
//							if(accnt_exists)
//								account_info();
//							break;
//
//				case '3':	system ("CLS");
//							accnt_exists=get_accnt_indx();
//							if(accnt_exists)
//								deposit();
//							break;
//				case '4':	system ("CLS");
//							accnt_exists=get_accnt_indx();
//							if(accnt_exists)
//								withdraw();
//							break;
//
//
//				case '5':	system ("CLS");
//							accnt_exists=get_accnt_indx();
//							if(accnt_exists)
//								{
//									system ("CLS");
//									passbook();
//								}
//							break;
//
//				default:	printf("Invalid choice\n");
//							printf("Enter any number to continue\n");
//							scanf("%d",&proceed);
//							break;
//
//			} 
//		}
//
//}
//
//void create_account()
//{
//
//    printf("Please enter the following details:\n");
//    printf("Account number:\n");
//    scanf("%s", acc_num);
//    strcat(acc_num, ".dat");
//    printf("Account holder's name:\n");
//    scanf("%s",acc_holder_name);
//    file = fopen(acc_num, "a");
//    if (file)
//    {
//
//		fprintf(file,"%s\n",acc_holder_name);
//	   	fprintf(file,"0.0 \t \t 0.0 \t \t 0.0\n",amt,net_blnc);
//		printf("Account created successfuly!\n");
//		fclose(file);
//    }
//    else
//    {
//           printf("Sorry, could not create account.");
//    }
//    printf("Enter any number to continue\n");
//    scanf("%d",&proceed);
//}
//
//int get_accnt_indx()
//{
//	printf("Enter your account number.\n");
//	scanf("%s",&acc_no);
//	strncpy(acc_num, acc_no,sizeof(acc_num));
//	strcat(acc_num, ".dat");
//	file = fopen(acc_num, "r");
//	if(file)
//	{
//		fclose(file);
//		return 1;
//	}
//	else
//	{
//		printf("Sorry, this account doesn't exist.\n");
//		printf("Enter any number to continue\n");
//		scanf("%d",&proceed);
//		return 0;
//	}
//
//}
//
//void account_info()
//{
//	file = fopen(acc_num, "r");
//	if (file)
//	{
//    	printf("Account number: %s\n",acc_no);
//		fscanf(file, "%s", acc_holder_name);
//	    printf("Account holder's name: %s\n",acc_holder_name);
//		while(fscanf(file, "%f", &net_blnc)==1)
//			{
//
//			}
//		printf("Account balance: %.2f\n",net_blnc);
//		fclose(file);
//
//    }
//    else
//    {
//    	printf("error accessing account");
//	}
//
//    printf("Enter any number to continue\n");
//	scanf("%d",&proceed);
//
//}
//
//void deposit()
//{
//
//	printf("Enter the amount to be deposited\n");
//	scanf("%f",&amt);
//	if(amt<0)
//	{
//		printf("INCORRECT ENTRY : Entered deposit amount is negative\n");
//		printf("Balance not updated\n");
//		printf("********************\n");
//	}
//	else
//	{
//		file = fopen(acc_num,"r");
//		if(file)
//		{
//			fscanf(file, "%s", acc_holder_name);
//			while(fscanf(file, "%f", &net_blnc)==1)			
//			{
//
//
//			}
//			fclose(file);
//
//			file = fopen(acc_num,"a");
//			if(file)
//			{
//				net_blnc+=amt;																
//				fprintf(file,"0.0 \t \t %0.2f \t \t %0.2f\n",amt,net_blnc);
//			   	fclose(file);
//				printf("Amount deposited %.2f\nUpdated balance: %.2f\n",amt,net_blnc);
//				printf("********************\n");
//			}
//			else
//				printf("Could not update the record!!");
//		}
//		else
//			printf("Could not retrieve the data!!");
//
//
//	}
//	printf("Enter any number to continue\n");
//	scanf("%d",&proceed);
//
//}
//
//void withdraw()
//{
//	file = fopen(acc_num,"r");
//	if(file)
//	{
//		fscanf(file, "%s", acc_holder_name);
//		while(fscanf(file, "%f", &net_blnc)==1)			
//		{
//
//
//		}
//		fclose(file);
//
//		if(net_blnc<=0)
//		{
//			printf("Low balance. Can not withdraw\n");
//
//		}
//		else
//		{
//			printf("Enter the amount to be withdrawn\n");
//			scanf("%f",&amt);
//			if(amt<0)
//			{
//				printf("The amount can't be withdrawn in negative\n");
//				printf("********************\n");
//			}
//			else if(amt>net_blnc)
//			{
//				printf("Insufficient balance\n");
//				printf("********************\n");
//
//			}
//			else
//			{
//				net_blnc-=amt;
//				file = fopen(acc_num,"a");
//				if(file)
//				{
//					fprintf(file,"%0.2f \t \t 0.0 \t \t %0.2f\n",amt,net_blnc);
//				   	fclose(file);
//					printf("Amount withdrawn: %0.2f\nUpdated balance: %0.2f\n",amt,net_blnc);
//					printf("********************\n");
//				}
//				else
//					printf("Could not update the record!!");
//			}
//		}
//	}
//	else
//	{
//		printf("Could not retrieve the data!!");
//	}
//
//	printf("Enter any number to continue\n");
//	scanf("%d",&proceed);
//
//}
//
//void passbook()
//{
//	file = fopen(acc_num, "r");
//	fscanf(file, "%s", acc_holder_name);
//	printf("================================================\n");
//	printf("\n\n \t\t||Bank of Cs||	\n");
//	printf("A/c:%s \t\t\t Name:%s\n\n",acc_no,acc_holder_name);
//	printf("________________________________________________\n");
//	printf("DEBIT \t\t CREDIT \t BALANCE	\n");
//	printf("________________________________________________\n");
//	while(fscanf(file, "%f %f %f", &deb, &cred, &trans_bal)==3)			
//			{
//				printf("%0.2f \t\t %0.2f \t %0.2f\n", deb, cred, trans_bal);
//				printf("------------------------------------------------\n");
//
//
//			}
//	printf("\n\n");
//	printf("Enter any number to continue\n");
//	scanf("%d",&proceed);
//}






//c++
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

char acc_num[20];               
char acc_holder_name[50];
float net_blnc = 0.0;
char acc_no[20];                

char choice;					
float amt;						
float cred, deb, trans_bal;
int accnt_exists = 0;					
int proceed = 0;					
fstream file;

void create_account();
int get_accnt_indx();
void account_info();
void deposit();
void withdraw();
void passbook();

int main() {

	while (1)
	{
		system("CLS");
		cout << "****************************************************\n";
		cout << "\n\n				||Bank of Cs||	\n\n";
		cout << "****************************************************\n";
		cout << "Please choose the desired service number:\n";
		cout << "1. Account creation\n";
		cout << "2. Account information\n";
		cout << "3. Deposit amount\n";
		cout << "4. Withdraw amount\n";
		cout << "5. Access Passbook\n\n";
		cout << "Enter any number to return to the main menu from elsewhere\n";
		cin >> choice;

		switch (choice) {
		case '1':	system("CLS");
					create_account();
					break;

		case '2': 	system("CLS");
					accnt_exists = get_accnt_indx();
					if (accnt_exists)
						account_info();
					break;

		case '3':	system("CLS");
					accnt_exists = get_accnt_indx();
					if (accnt_exists)
						deposit();
					break;
		case '4':	system("CLS");
					accnt_exists = get_accnt_indx();
					if (accnt_exists)
						withdraw();
					break;

		case '5':	system("CLS");
					accnt_exists = get_accnt_indx();
					if (accnt_exists)
					{
						system("CLS");
						passbook();
					}
					break;

		default:	cout << "Invalid choice\n";
					cout << "Enter any number to continue\n";
					cin >> proceed;
					break;
		}
	}
}

void create_account() {

    cout << "Please enter the following details:\n";
    cout << "Account number:\n";
    cin >> acc_num;
    strcat(acc_num, ".dat");
    cout << "Account holder's name:\n";
    cin >> acc_holder_name;
    file.open(acc_num, ios::out | ios::app);
    if (file)
    {
		file << acc_holder_name << "\n";
	   	file << "0.0 \t \t 0.0 \t \t 0.0\n";
		cout << "Account created successfully!\n";
		file.close();
    }
    else
    {
        cout << "Sorry, could not create account.";
    }
    cout << "Enter any number to continue\n";
    cin >> proceed;
}

int get_accnt_indx() {
	cout << "Enter your account number.\n";
	cin >> acc_no;
	strncpy(acc_num, acc_no, sizeof(acc_num));
	strcat(acc_num, ".dat");
	file.open(acc_num, ios::in);
	if (file)
	{
		file.close();
		return 1;
	}
	else
	{
		cout << "Sorry, this account doesn't exist.\n";
		cout << "Enter any number to continue\n";
		cin >> proceed;
		return 0;
	}
}

void account_info() {
	file.open(acc_num, ios::in);
	if (file)
	{
    	cout << "Account number: " << acc_no << "\n";
		file >> acc_holder_name;
	    cout << "Account holder's name: " << acc_holder_name << "\n";
		while (file >> net_blnc)
		{
		}
		cout << "Account balance: " << net_blnc << "\n";
		file.close();
    }
    else
    {
    	cout << "Error accessing account";
	}

    cout << "Enter any number to continue\n";
	cin >> proceed;
}

void deposit() {
	cout << "Enter the amount to be deposited\n";
	cin >> amt;
	if (amt < 0)
	{
		cout << "INCORRECT ENTRY: Entered deposit amount is negative\n";
		cout << "Balance not updated\n";
		cout << "********************\n";
	}
	else
	{
		file.open(acc_num, ios::in);
		if (file)
		{
			file >> acc_holder_name;
			while (file >> net_blnc)
			{
			}
			file.close();

			file.open(acc_num, ios::out | ios::app);
			if (file)
			{
				net_blnc += amt;
				file << "0.0 \t \t " << amt << " \t \t " << net_blnc << "\n";
			   	file.close();
				cout << "Amount deposited: " << amt << "\nUpdated balance: " << net_blnc << "\n";
				cout << "********************\n";
			}
			else
				cout << "Could not update the record!!";
		}
		else
			cout << "Could not retrieve the data!!";
	}
	cout << "Enter any number to continue\n";
	cin >> proceed;
}

void withdraw() {
	file.open(acc_num, ios::in);
	if (file)
	{
		file >> acc_holder_name;
		while (file >> net_blnc)
		{
		}
		file.close();

		if (net_blnc <= 0)
		{
			cout << "Low balance. Cannot withdraw\n";
		}
		else
		{
			cout << "Enter the amount to be withdrawn\n";
			cin >> amt;
			if (amt < 0)
			{
				cout << "The amount can't be withdrawn in negative\n";
				cout << "********************\n";
			}
			else if (amt > net_blnc)
			{
				cout << "Insufficient balance\n";
				cout << "********************\n";
			}
			else
			{
				net_blnc -= amt;
				file.open(acc_num, ios::out | ios::app);
				if (file)
				{
					file << amt << " \t \t 0.0 \t \t " << net_blnc << "\n";
				   	file.close();
					cout << "Amount withdrawn: " << amt << "\nUpdated balance: " << net_blnc << "\n";
					cout << "********************\n";
				}
				else
					cout << "Could not update the record!!";
			}
		}
	}
	else
	{
		cout << "Could not retrieve the data!!";
	}

	cout << "Enter any number to continue\n";
	cin >> proceed;
}

void passbook() {
	file.open(acc_num, ios::in);
	file >> acc_holder_name;
	cout << "================================================\n";
	cout << "\n\n \t\t||Bank of Cs||	\n";
	cout << "A/c: " << acc_no << " \t\t\t Name: " << acc_holder_name << "\n\n";
	cout << "________________________________________________\n";
	cout << "DEBIT \t\t CREDIT \t BALANCE	\n";
	cout << "________________________________________________\n";
	while (file >> deb >> cred >> trans_bal)
	{
		cout << deb << " \t\t " << cred << " \t " << trans_bal << "\n";
		cout << "------------------------------------------------\n";
	}
	cout << "\n\n";
	cout << "Enter any number to continue\n";
	cin >> proceed;
}


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Account_Details{
    int accNo;
	char name[25];
	char Fname[25];
	char aadhar_no[15];
	char P_no[25];
	char email[25];
	float amount;
	int newAmount;
    fstream file,file1;

    public:
	int search;

    void createAccount(void);   
    void depositAmount(void);   
    void withdrawAmount(void);  
    void checkInfo(void);       
};


void Account_Details :: createAccount(){

    srand(time(0));
	accNo=rand()*rand()+rand()*rand()+rand()*rand();
	
	cout<<"Enter Your name :: ";
	cin>>name;
	
	cout<<"Enter Your Father name :: ";
	cin>>Fname;

	cout<<"Enter Your Aadhar number :: ";
	cin>>aadhar_no;
	
	cout<<"Enter Your phone no. :: ";
	cin>>P_no;
	
	cout<<"Enter Your email :: ";
	cin>>email;
	
	cout<<"Enter Your amount :: ";
	cin>>amount;
	
	cout<<endl<<accNo<<" This is your account number... \n";
	cout<<"Please save it \n\n";
	
	file.open("data.txt",ios::out|ios::app);
	file<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar_no<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
	file.close();
}

void Account_Details :: depositAmount(){
   
	cout<<"Enter amount to deposit :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	
	while(!file.eof()) {
		if(accNo==search){
			cout<<"\nCurrent amount :: "<<amount;
			amount=amount + newAmount;
			cout<<"\nUpdated amount :: "<<amount<<endl;
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar_no<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar_no<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	}
	
	file.close();
	file1.close();
	remove("data.txt");
	rename("data1.txt","data.txt");
}

void Account_Details :: withdrawAmount(){
    
	cout<<"Enter amount to withdraw :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	
	while(!file.eof()) {
		if(accNo==search){
			cout<<"\nCurrent amount :: "<<amount;
			amount=amount - newAmount;
			cout<<"\nUpdated amount :: "<<amount<<endl;
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar_no<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar_no<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	}
	
	file.close();
	file1.close();
	remove("data.txt");
	rename("data1.txt","data.txt");
}

void Account_Details :: checkInfo(){
	fstream file;
	file.open("data.txt",ios::in);
	if(!file){
		cout<<"File opening error !";
	}
	file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	while(!file.eof()){
		if(accNo==search){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: Account Number ::: ";
            cout<<"\t   "<<accNo<<endl;
            cout<<"\t::: User Name      ::: ";
            cout<<"\t   "<<name<<"\n";
            cout<<"\t::: Father Name    ::: ";
            cout<<"\t   "<<Fname<<"\n";
            cout<<"\t::: Aadhar number  ::: ";
            cout<<"\t   "<<aadhar_no<<"\n";
            cout<<"\t::: Phone Number   ::: ";
            cout<<"\t   "<<P_no<<"\n";
            cout<<"\t::: Email          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";
		
	    }
		file>>accNo>>name>>Fname>>aadhar_no>>P_no>>email>>amount;
	}
	
	file.close();
}

int main(){

    Account_Details A1;
    char choice;

    cout<<"\n\n\n\t\t......:::State Bank of India:::......";
	cout<<"\n\t\t:: press 1 to Login  Account :: ";
	cout<<"\n\t\t:: press 2 to Create Account ::";
	cout<<"\n\t\t:: press 0 to Exit           ::";
	cout<<"\n\t\t:: ......................... ::\n\t\t\t\t";
	cin>>choice;
    
    switch(choice){
        case '1':
            cout<<"Enter your account no :: ";
	        cin>>A1.search;
        while(1){

            cout<<"\n\n\n\t\t.......:::State Bank of India:::.......";
            cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: press 3 to Check    Info    ::";
            cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n\t\t\t\t";
            cin>>choice;

            switch (choice)
            {
            case '1':
                A1.depositAmount();
            break;
            case '2':
                A1.withdrawAmount();
            break;
            case '3':
                A1.checkInfo();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice...!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            A1.createAccount();
        break;
        case '0':
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice...! ";
        break;
    }
    return 0;
}
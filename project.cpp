/*  
    Program: Store Managment System.
    ©This Program is Copyrighted and Owned by Zohaib Ahmed
    Terms & Conditions:
        This program is designed to manage store data. The main features of this program is to Sign Up customers,
        employees, and Only One Owner. After the successfull Sign Up a customer can view account info, modify that
        info and can place any order by providing there credit card details or Address for Cash on Delivery.
        Employees are 10 allowed only and can modify there data, can view there Salary and withdraw, can check for
        any holiday or so. employees are only allowed by the owner to sign up to there account. owner will provide
        a special pin to register to store.
        Similarly owner is allowed to signup only once, he may manage his data after successfull sign up. owner
        can view total profit, total salaries of all employees, total expenses, and other calculations etc.
    Privacy Policy:
        This program will store your data in the form of Data Base files and is encrypted
        Your Privacy is our number one Priority.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;
struct Access_data{
    string user_name,user_pass,user_address,user_credit_num,user_credit_exp, user_credit_code;
};
//------------------------Main Data function to just Print out Main Menu
void Main_Menu_data();
//----------------------Sign up data function to print signup menu details
void Sign_up_data();
//-----------------------sign up function to start signning up any account
void Sign_up(Access_data[],Access_data[],Access_data[],int,int,int);
void Customer_Sign_up(Access_data[],int); //----Customer will be able to sign up through this function
void Employee_Sign_up(Access_data[],int); //----Employee will be able to sign up through this function
void Owner_Sign_up(Access_data[],int); //----Owner will be able to sign up through this function
//----------------------login function to start login for corresponding 
void Login();
void Customer_login(); //-----------Customer will be able to login through this function
void Employee_login();//----------Employees wil be able to login through this function
void Owner_login();//-------------Owner will be able to login through this function
//--------------------Login data to be printed
void Login_data();
//----------------------Help function containing timings etc
void Help();
//-----------------------Help Data to be printed
void Help_data();
void timing_data();//----timing data function to just print time
void contact_data();//----my contact details
//----------------------About us funtion to print Data 
void About_data();
//-----------------functions to load data into memory and checks 
void customer_data_to_memory(Access_data[]);
int customer_data_loading_check=0;
void employee_data_to_memory(Access_data[]);
int employee_data_loading_check=0;
void owner_data_to_memory(Access_data[]);
int owner_data_loading_check=0;
int owner_code=12112; //------------owner code given to the Employee to create account
string owner_entry_check="0"; //------------for owner entry point if it is 1 Owner will not able to create account
int main(){
    //-------customer data
    int size_customer_data=5000;
    Access_data *customer_memory=new Access_data[size_customer_data];
    customer_data_to_memory(customer_memory); //-------this functiion is to load account data into the program
    //-------Employee data
    int size_employee_data=10;
    Access_data* employee_memory=new Access_data[size_employee_data];
    employee_data_to_memory(employee_memory); //-------this function is to load account data into the program for employees
    //-------Owner Data
    int size_owner_data=10;
    Access_data* owner_memory=new Access_data[size_owner_data];
    owner_data_to_memory(owner_memory);//-------this functiion is to load account data into the program
    bool running=true;
    do{
        int check=0;
        do{
            check=0;
            Main_Menu_data();
            cout<<"\nPlease Choose Your Option: ";
            char choice_menu;
            cin>>choice_menu;
            choice_menu = tolower(choice_menu);
            switch(choice_menu){
                case 's':Sign_up(customer_memory,employee_memory,owner_memory,size_customer_data,size_employee_data,size_owner_data);break;
                case 'l':Login();break;
                case 'h':Help();break;
                case 'a':About_data();break;
                case 'e':running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        check=1;
            }
        }while(check==1);
    }while(running);
}
/*
    ------------------------------------------------------
   ---------------------- Just Printable data------------------
    ------------------------------------------------------
*/
void Main_Menu_data(){
    system("cls");
    cout<<"\033[1m\033[31mWelcome To the Store\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[S]\033[0m Sign Up\n";
    cout<<"\033[01m\033[32m[L]\033[0m Login\n";
    cout<<"\033[01m\033[32m[H]\033[0m Help\n";
    cout<<"\033[01m\033[32m[A]\033[0m About\n";
    cout<<"\033[01m\033[32m[E]\033[0m Exit\n";
}
void Sign_up_data(){
    system("cls");
    cout<<"\033[1m\033[31mSign Up\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[C]\033[0m Customer Sign Up\n";
    cout<<"\033[01m\033[32m[E]\033[0m Employee Sign Up\n";
    cout<<"\033[01m\033[32m[O]\033[0m Owner Sign Up\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void About_data(){
    system("cls");
    cout<<"\033[1m\033[31mAbout\033[0m\n";
    cout<<"-------------------\n";
    cout<<"Version \033[36m1.00\033[0m\n";
    cout<<"Dated: \033[36m04/02/2021\033[0m\n";
    cout<<"This Program is Copyrighted by \033[36mZohaib Ahmed\033[0m\n";
    cout<<"Press Enter to Go Back: ";
    getch();
}
void Help_data(){
    system("cls");
    cout<<"\033[1m\033[31mHelp\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[T]\033[0m Timing of the Store\n";
    cout<<"\033[01m\033[32m[A]\033[0m About\n";
    cout<<"\033[01m\033[32m[C]\033[0m Contact\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void timing_data(){
    system("cls");
    cout<<"\033[1m\033[31mTimings\033[0m\n";
    cout<<"-------------------\n";time_t now =time(0);
	char* day_find = ctime(&now);
	cout<<"\033[01m\033[32mCurrent-Time\033[0m = "<<day_find<<"\n";
	if(day_find[0]=='M'){
		if(day_find[1]=='o'){
			if(day_find[2]=='n'){
				cout<<"\033[1m\033[31mMonday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mMonday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='T'){
		if(day_find[1]=='u'){
			if(day_find[2]=='e'){
				cout<<"\033[1m\033[31mTuesday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mTuesday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='W'){
		if(day_find[1]=='e'){
			if(day_find[2]=='d'){
				cout<<"\033[1m\033[31mWednesday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mWednesday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='T'){
		if(day_find[1]=='h'){
			if(day_find[2]=='u'){
				cout<<"\033[1m\033[31mThusday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mThusday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='F'){
		if(day_find[1]=='r'){
			if(day_find[2]=='i'){
				cout<<"\033[1m\033[31mFriday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mFriday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='S'){
		if(day_find[1]=='a'){
			if(day_find[2]=='t'){
				cout<<"\033[1m\033[31mSaturday\033[0m 9AM - 9PM\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mSaturday\033[0m 9AM - 9PM\n";
	}
    if(day_find[0]=='S'){
		if(day_find[1]=='u'){
			if(day_find[2]=='n'){
				cout<<"\033[1m\033[31mSunday\033[0m Close\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mSunday\033[0m Close\n";
	}
    cout<<"Press Enter to Go Back: ";
    getch();
}
void contact_data(){
    system("cls");
    cout<<"\033[1m\033[31mContact\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\033[01m\033[32mEmail: \033[0m zohaib.ahmed1397@gmail.com\n";
    cout<<"\033[01m\033[32mPhone: \033[0m +92-308-8877196\n";
    cout<<"\033[01m\033[32mAny Quries ask here: \033[0m https://github.com/Zohaib1397\n";
    cout<<"Press Enter to Go Back: ";
    getch();
}
void Login_data(){
    system("cls");
    cout<<"\033[1m\033[31mLogin\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[C]\033[0m Customer Login\n";
    cout<<"\033[01m\033[32m[E]\033[0m Employee Login\n";
    cout<<"\033[01m\033[32m[O]\033[0m Owner Login\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
/*
    -----------------------------------------------------------------
   --------------------------- Sign-Up Function------------------------
    -----------------------------------------------------------------
*/
void Sign_up(Access_data customer_data[],Access_data employee_data[],Access_data owner_data[],int customer_size,int employee_size,int owner_size){
    bool signup_running=true;
    do{
        int customer_data_loading_check=0;
        int employee_data_loading_check=0;
        int owner_data_loading_check=0;
        int sign_up_check=0;
            do{
            Sign_up_data();
            cout<<"\nChoose Your Option: ";
            char choice_signup;
            cin>>choice_signup;
            choice_signup = tolower(choice_signup);
            switch(choice_signup){
                case 'c':Customer_Sign_up(customer_data,customer_size);break;
                case 'e':Employee_Sign_up(employee_data,employee_size);break;
                case 'o':Owner_Sign_up(owner_data,owner_size);break;
                case 'b':signup_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to Go back: ";
                        getch();
                        sign_up_check=1;
            }
        }while(sign_up_check==1);
    }while(signup_running);
}
/*
    ---------------------------------------------------
   ---------------------- Sub function --------------
---------------------for Customer SignUp ------------------
    -----------------------------------------------------
*/
void Customer_Sign_up(Access_data memory[],int size){ //--------------Save Customer ID Details
    system("cls");
    customer_data_to_memory(memory);
    if(customer_data_loading_check==0){
        bool start_signup = true;
        do{
            fstream data_file; //-------Customer_ID file created
            char choice_address,choice_cd;
            string username,password,address=" ",CD_num=" ",CD_exp=" ";
            int CD_code=0,check=0;
            string test;
            data_file.open("Customer_ID.db",ios::out|ios::in|ios::app);
            cin.ignore();
            if(data_file.is_open()){
                do{ 
                    check=0;
                    cout<<"Create Username\033[31m*\033[0m: ";
                    getline(cin,username);
                    int i=0;
                    while(i<=size){ //----------run until end of line to check for same Username
                        if(username==memory[i].user_name){ //---this checks for if there is already an Username Present
                            cout<<"\033[31mError!!\033[0m User Name is Already Present: \033[31mTry again\033[0m\n";
                            check=1;
                            username.clear();
                            break;
                        }
                        i++;
                    }
                }while(check==1);
                int pass_check=0;
                do{
                    cout<<"Create Password\033[31m*\033[0m: ";
                    getline(cin,password);
                    if(password.length()<8){
                        cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
                        cout<<"Press Enter to \033[31mTry again\033[0m";
                        getch();
                    }
                }while(password.length()<8);
                int address_check=0;
                //-----------there is a choice for user. he may enter address now or later on any purchase
                do{
                    cout<<"Do you want to Add Address(y/n): ";
                    cin>>choice_address;
                    choice_address = tolower(choice_address);
                    switch(choice_address){
                        case 'y':cout<<"Enter Your Address: ";
                                cin.ignore();
                                getline(cin,address);
                                break;
                        case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
                        default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                                cout<<"Press Enter to \033[31mTry again\033[0m";
                                getch();
                                address_check=1;
                    }
                }while(address_check==1);
                int cd_check=0;
                //-----------there is a choice for user. he may enter Credit-Card now or later on any purchase
                do{
                    cout<<"Do you want to Add Credit-Card Details(y/n): ";
                    cin>>choice_cd;
                    choice_cd = tolower(choice_cd);
                    switch(choice_cd){
                        case 'y':cout<<"Enter Your Credit Card Number: ";
                                cin.ignore();
                                getline(cin,CD_num);
                                cout<<"Enter Code: ";
                                cin>>CD_code;
                                cout<<"Enter Expire Details(MM/YY): ";
                                cin.ignore();
                                getline(cin,CD_exp);
                                break;
                        case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
                        default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                                cout<<"Press Enter to \033[31mTry again\033[0m";
                                getch();
                                cd_check=1;
                    }
                }while(cd_check==1);
                //-----------Conditions for user entered data
                if(choice_address=='n'&&choice_cd=='n'){
                    address="---";
                    CD_num="---";
                    CD_exp="---";
                    CD_code=000;
                    data_file<<username<<"\n"<<password<<"\n"<<address<<"\n"<<CD_num<<"\n"<<CD_code<<"\n"<<CD_exp<<"\n";
                }
                else if(choice_address=='n'&&choice_cd=='y'){
                    address="---";
                    data_file<<username<<"\n"<<password<<"\n"<<address<<"\n"<<CD_num<<"\n"<<CD_code<<"\n"<<CD_exp<<"\n";
                }
                else if(choice_address=='y'&&choice_cd=='n'){
                    CD_num="---";
                    CD_exp="---";
                    CD_code=000;
                    data_file<<username<<"\n"<<password<<"\n"<<address<<"\n"<<CD_num<<"\n"<<CD_code<<"\n"<<CD_exp<<"\n";
                }
                else{
                    cout<<"\033[31mUnkown Error!!!: Try Again\033[0m\n";
                }
                cout<<"\033[1m\033[32mSuccessfully Created Account\033[0m\n";
                cout<<"Press Enter to Go back: ";
                getch();
                start_signup=false;
            }
            else{
                cout<<"\033[31mError!!\033[0m Unable to Open the desired file \033[36mTry again\033[0m\n";
                cout<<"Press Enter to Go back: ";
                getch();
                start_signup=false;
                //-----signup function here
            }
        }while(start_signup);
    }
}
/*
    ---------------------------------------------------
   ---------------------- Sub function -----------------
---------------------for Employee SignUp ------------------
    -----------------------------------------------------
*/
void Employee_Sign_up(Access_data memory[],int size){
    system("cls");
    employee_data_to_memory(memory);
    if(employee_data_loading_check==0){
        bool start_signup = true;
        do{
            fstream employee_data; //-------Employee_ID file created
            char choice_address,choice_cd;
            string username,password,address=" ",CD_num=" ",CD_exp=" ";
            int CD_code=0,check=0;
            employee_data.open("Employee_ID.db",ios::out|ios::in|ios::app);
            cout<<"Enter \033[36mSpecial Code\033[0m Given by the Owner: ";
            int code_by_owner;
            cin>>code_by_owner;
            if(code_by_owner!=owner_code){
                cout<<"\033[31mError!!\033[0m You can't create Account\n";
                cout<<"Press Enter to Go back: ";
                getch();
                start_signup=false;
            }
            else{
                cin.ignore();
                if(employee_data.is_open()){
                    do{ 
                        check=0;
                        cout<<"Create Username\033[31m*\033[0m: ";
                        getline(cin,username);
                        int i=0;
                        while(i<=size){ //----------run until end of line to check for same Username
                            if(username==memory[i].user_name){ //---this checks for if there is already an Username Present
                                cout<<"\033[31mError!!\033[0m User Name is Already Present: \033[31mTry again\033[0m\n";
                                check=1;
                                username.clear();
                                break;
                            }
                            i++;
                        }
                    }while(check==1);
                    do{
                    cout<<"Create Password\033[31m*\033[0m: ";
                    getline(cin,password);
                    if(password.length()<8){
                        cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
                        cout<<"Press Enter to \033[31mTry again\033[0m";
                        getch();
                    }
                }while(password.length()<8);
                    cout<<"Enter Your Address\033[31m*\033[0m: ";
                    getline(cin,address);
                    cout<<"Enter Your Credit Card Number\033[31m*\033[0m: ";
                    getline(cin,CD_num);
                    cout<<"Enter Code\033[31m*\033[0m: ";
                    cin>>CD_code;
                    cout<<"Enter Expire Details(MM/YY)\033[31m*\033[0m: ";
                    cin.ignore();
                    getline(cin,CD_exp);
                    //-----------Conditions for user entered data
                    employee_data<<username<<"\n"<<password<<"\n"<<address<<"\n"<<CD_num<<"\n"<<CD_code<<"\n"<<CD_exp<<"\n";
                    cout<<"\033[1m\033[32mSuccessfully Created Account\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                    start_signup=false;
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to Open the desired file \033[36mTry again\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                    start_signup=false;
                    //-----signup function here
                }
            }
        }while(start_signup);
    }
}
/*
    ---------------------------------------------------
   ---------------------- Sub function -----------------
---------------------for Owner SignUp ------------------
    -----------------------------------------------------
*/
void Owner_Sign_up(Access_data memory[],int size){
    system("cls");
    owner_data_to_memory(memory);
    if(owner_data_loading_check==0){
        if(owner_entry_check!="1"){
            bool start_signup = true; //------------creat account for owner
            do{
                fstream owner_data; //-------owner_ID file created
                char choice_address,choice_cd;
                string username,password,address=" ",CD_num=" ",CD_exp=" ";
                int CD_code=0,check=0;
                owner_data.open("Owner_ID.db",ios::out|ios::in|ios::app);
                cin.ignore();
                if(owner_data.is_open()){
                    do{ 
                        check=0;
                        cout<<"Create Username\033[31m*\033[0m: ";
                        getline(cin,username);
                        int i=0;
                        while(i<=size){ //----------run until end of line to check for same Username
                            if(username==memory[i].user_name){ //---this checks for if there is already an Username Present
                                cout<<"\033[31mError!!\033[0m User Name is Already Present: \033[31mTry again\033[0m\n";
                                check=1;
                                username.clear();
                                break;
                            }
                            i++;
                        }
                    }while(check==1);
                    do{
                        cout<<"Create Password\033[31m*\033[0m: ";
                        getline(cin,password);
                        if(password.length()<8){
                            cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
                            cout<<"Press Enter to \033[31mTry again\033[0m";
                            getch();
                            cout<<"\n";
                        }
                    }while(password.length()<8);
                    cout<<"Enter Your Address\033[31m*\033[0m: ";
                    getline(cin,address);
                    cout<<"Enter Your Credit Card Number\033[31m*\033[0m: ";
                    getline(cin,CD_num);
                    cout<<"Enter Code\033[31m*\033[0m: ";
                    cin>>CD_code;
                    cout<<"Enter Expire Details(MM/YY)\033[31m*\033[0m: ";
                    cin.ignore();
                    getline(cin,CD_exp);
                    //-----------Conditions for user entered data
                    owner_data<<username<<"\n"<<password<<"\n"<<address<<"\n"<<CD_num<<"\n"<<CD_code<<"\n"<<CD_exp<<"\n"<<"1";
                    cout<<"\033[1m\033[32mSuccessfully Created Account\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                    start_signup=false;
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to Open the \033[31mOwner_ID.db\033[0m \033[36mTry again\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                    start_signup=false;
                    //-----signup function here
                }
            }while(start_signup);
        }
        else{
            cout<<"\033[31mError!!\033[0m Owner Account can only be created \033[36mOnce\033[0m\n";
            cout<<"Press Enter to Go back: ";
            getch();
        }
    }
}
/*
    -----------------------------------------------------------------
   --------------------------- Login Function------------------------
    -----------------------------------------------------------------
*/
void Login(){
    bool login_running=true;
    do{
        int login_check=0;
        do{
            login_check=0;
            Login_data();
            cout<<"\nChoose your option: ";
            char login_choice;
            cin>>login_choice;
            login_choice = tolower(login_choice);
            switch(login_choice){
                case 'c':Customer_login();break;
                case 'e':Employee_login();break;
                case 'o':Owner_login();break;
                case 'b':login_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        login_check=1;
            }
        }while(login_check==1);
    }while(login_running);
}
/*
    -----------------------------------------------------------------
   --------------------------- Help Function------------------------
    -----------------------------------------------------------------
*/
void Help(){
    bool help_running=true;
   do{
       Help_data();
       int help_check=0;
       do{  
           help_check=0;
           cout<<"\nChoose your option: ";
           char help_choice;
           cin>>help_choice;
           help_choice = tolower(help_choice);
           switch(help_choice){
               case 't':timing_data();break;
               case 'a':About_data();break;
               case 'c':contact_data();break;
               case 'b':help_running=false;break;
               default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        help_check=1;
           }
       }while(help_check==1);
   }while(help_running);
}
/*
    ---------------------------------------------------------------
---------------------Functions to Load Account Data into Memory-------------
    ---------------------------------------------------------------
*/
void customer_data_to_memory(Access_data memory[]){
    ifstream data_customer;
    data_customer.open("Customer_ID.db");
    if(data_customer.is_open()){
        int i=0;
        while(!data_customer.eof()){
            getline(data_customer,memory[i].user_name);
            getline(data_customer,memory[i].user_pass);
            getline(data_customer,memory[i].user_address);
            getline(data_customer,memory[i].user_credit_num);
            getline(data_customer,memory[i].user_credit_code);
            getline(data_customer,memory[i].user_credit_exp);
            i++;
        }
        data_customer.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mCustomer_ID\033[0m\n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
        int customer_data_loading_check=1;
    }
}
void employee_data_to_memory(Access_data memory[]){
    ifstream data_employee;
    data_employee.open("Employee_ID.db");
    if(data_employee.is_open()){
        int i=0;
        while(!data_employee.eof()){
            getline(data_employee,memory[i].user_name);
            getline(data_employee,memory[i].user_pass);
            getline(data_employee,memory[i].user_address);
            getline(data_employee,memory[i].user_credit_num);
            getline(data_employee,memory[i].user_credit_code);
            getline(data_employee,memory[i].user_credit_exp);
            i++;
        }
        data_employee.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mEmployee_ID\033[0m\n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
        int employee_data_loading_check=1;
    }
}
void owner_data_to_memory(Access_data memory[]){
    ifstream data_owner;
    data_owner.open("Owner_ID.db");
    if(data_owner.is_open()){
        int i=0;
        while(!data_owner.eof()){
            getline(data_owner,memory[i].user_name);
            getline(data_owner,memory[i].user_pass);
            getline(data_owner,memory[i].user_address);
            getline(data_owner,memory[i].user_credit_num);
            getline(data_owner,memory[i].user_credit_code);
            getline(data_owner,memory[i].user_credit_exp);
            getline(data_owner,owner_entry_check);
            i++;
        }
        data_owner.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mOwner_ID.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
        int owner_data_loading_check=1;
    }
}
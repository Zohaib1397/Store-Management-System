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
#include<sstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct Access_data{
    string user_name,user_pass,user_address,user_credit_num,user_credit_exp, user_credit_code;
};
struct Login_store{
    string user_name,user_pass,user_address,user_credit_num,user_credit_exp, user_credit_code;
};
struct Products{
    string name;
    int purchase_price;
    int sale_price;
};
struct Products_data_access{
    string name;
    string purchase_price;
    string sale_price;
};
struct store_cart_data{
    string name;
    int sale_price;
    int quantity;
};
struct attendance_data{
    string attendance;
    string current_time;
    string target_time;
    string check;
};
struct order_profit{
    string name;
    string cd_num;
    string profit;
    string source;
};
struct salary{
    string name;
    string cd_num;
    string address;
    string salary;
    string timeing;
};
int index_login;
int size_storage[8];
int sign_up_storage[4];
store_cart_data store_data[100];//-------maximum cart products are 100
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
void Login(Access_data[],Access_data[],Access_data[],int,int,int);
//----sub login customer
void Customer_login(Access_data[],int); //-----------Customer will be able to login through this function
int total_bill=0; //------for billing
int bill_purchase_price=0;
int profit=0;
Login_store store={" "}; //-------for logins
void customer_login_start(); //----------after successfull login display this
void Buy_Products(); //---------customer only
void Buy_Products_data(); //----------data will be used and can be Modified by customer and owner respectively
void simple_Products_data(); //--------for employee and owner
//------------display products
void Display_sports();
void Display_tools();
void Display_electronics();
void Display_customer_sports();
void Display_customer_tools();
void Display_customer_electronics();
void sports_products();
void tools();
void cart_products();
void payment_method();
void payment_mehtod_data();
void print_receipt();
void electronics_products();
void Account_Details(); //-----------Account Details for Customer, Employee, Owner
void Account_Details_data(); //--------just to display sub menus
void edit_customer();
//----sub login employee
void Employee_login(Access_data[],int);//----------Employees wil be able to login through this function
void attendance_employee();
void salary_employee();
void Account_Details_employee();
void withdraw_of_employee(int,attendance_data[],int[]); //----first int for salary second for attendance data to memory and third is for size of employee
void edit_employee();
int employee_salary; //------------employee salary
//----sub login Owner
void Owner_login(Access_data[],int);//-------------Owner will be able to login through this function
void owner_login_start_data();//------just to print owner login data
void employee_details_by_owner();
void products_main();
void products_data();
void credit_card_payment();
void cash_on_delivery();
void edit_products();
void edit_products_data(); //------to display edit products menu
void add_products();
void add_products_data(); //--------sports tools electronics 
void add_sports();
void add_tools();
void add_electronics();
void log_data();
void modify_products();
void modify_sports();
void modify_tools();
void modify_electronics();
void display_products(); //----------to display products
void total_profit();
void Account_Details_Owner();
void edit_owner(); //------------to edit owner details
void list_employee(Access_data[],int);
void edit_employee_by_owner();
void change_employee_code();
void change_employee_salary();
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
int cart_counter=0;
void employee_data_to_memory(Access_data[]);
int employee_data_loading_check=0;
void owner_data_to_memory(Access_data[]);
int owner_data_loading_check=0;
void products_data_to_memory(int[]);
void accounts_data_to_memory(int[]);
void order_data_to_memory(order_profit[]);
void salary_data_to_memory(salary[]);
//-----------functions to load storage data for modification and purchasing
void load_sports_data(Products_data_access[]);
void load_tools_data(Products_data_access[]);
void load_electronics_data(Products_data_access[]);
void attendance_data_to_memory(attendance_data[]);
int owner_code; //------------owner code given to the Employee to create account
string owner_entry_check="0"; //------------for owner entry point if it is 1 Owner will not able to create account
int main(){
    //-------customer data
    ofstream just_to_load_accounts_data("Accounts_log.db",ios::app);
    just_to_load_accounts_data.close();
    ofstream just_to_load_products_data("Products_log.db",ios::app);
    just_to_load_products_data.close();
    ofstream load_attendance("attendance.dll",ios::app);
    load_attendance.close();
    accounts_data_to_memory(sign_up_storage);
    if(sign_up_storage[0]!=1){
        fstream attendance;
        attendance.open("attendance.dll",ios::out|ios::in);
        if(attendance.is_open()){
            attendance<<"0\n"; //-------for attendance counter
            attendance<<"0\n"; //------for current time
            attendance<<"0\n"; //-----for target time
            attendance<<"0\n"; //-------for check
            attendance<<"0\n";
            attendance<<"0\n";
            attendance<<"0\n";
            attendance<<"0\n";
            attendance.close();
        }
        else{
            cout<<"\033[31mError!!\033[0m Unable to Load the \033[attendance.dll\033[0m \n";
            cout<<"Press Enter to \033[36mTry again\033[0m";
            getch();
            cout<<"\n";
        }
        fstream log_product;
        log_product.open("Products_log.db",ios::out|ios::in);
        if(log_product.is_open()){
            log_product<<"1\n";
            log_product<<"0\n";
            log_product<<"0\n";
            log_product<<"0\n";
            log_product<<"500\n";
            log_product<<"1121\n";
            log_product<<"1\n";
            log_product<<"1";
            log_product.close();
        }
        else{
            cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mProducts_log.db\033[0m \n";
            cout<<"Press Enter to \033[36mTry again\033[0m";
            getch();
            cout<<"\n";
        }
        fstream log;
        log.open("Accounts_log.db",ios::out|ios::in);
        if(log.is_open()){
            log<<"1\n";
            log<<"10\n";
            log<<"5\n";
            log<<"2";
            log.close();
        }
        else{
            cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mAccounts_log.db\033[0m \n";
            cout<<"Press Enter to \033[36mTry again\033[0m";
            getch();
            cout<<"\n";
        }

    }
    accounts_data_to_memory(sign_up_storage);
    int size_customer_data=sign_up_storage[1];
    Access_data *customer_memory=new Access_data[size_customer_data];
    ofstream just_to_load_customer_data("Customer_ID.db",ios::app);
    just_to_load_customer_data.close();
    customer_data_to_memory(customer_memory); //-------this functiion is to load account data into the program
    //-------Employee data
    int size_employee_data=sign_up_storage[2];
    Access_data* employee_memory=new Access_data[size_employee_data];
    ofstream just_to_load_employee_data("Employee_ID.db",ios::app);
    just_to_load_employee_data.close();
    employee_data_to_memory(employee_memory); //-------this function is to load account data into the program for employees
    //-------Owner Data
    int size_owner_data=sign_up_storage[3];
    Access_data* owner_memory=new Access_data[size_owner_data];
    ofstream just_to_load_owner_data("Owner_ID.db",ios::app);
    just_to_load_owner_data.close();
    owner_data_to_memory(owner_memory);//-------this functiion is to load account data into the program
    ofstream just_to_load_product_data("Products_log.db",ios::app);
    just_to_load_product_data.close();
    ifstream just_to_load_sports_data("Sports_data.db",ios::app);
    just_to_load_sports_data.close();
    ofstream just_to_load_Tools_data("Tools_data.db",ios::app);
    just_to_load_Tools_data.close();
    ofstream just_to_load_Electronics_data("Electronics_data.db",ios::app);
    just_to_load_Electronics_data.close();
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
                case 'l':Login(customer_memory,employee_memory,owner_memory,size_customer_data,size_employee_data,size_owner_data);break;
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
    return 0;
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
    cout<<"-------------------\n";
    time_t now =time(0);
	string day_find = ctime(&now);
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
				cout<<"\033[1m\033[31mSunday\033[0m Closed\n";
			}
		}
	}
	else{
		cout<<"\033[1m\033[34mSunday\033[0m Close\n";
	}
    cout<<"\nPress Enter to Go Back: ";
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
void customer_login_start(){
    system("cls");
    cout<<"\033[1m\033[31mWelcome @"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[B]\033[0m Buy Products\n";
    cout<<"\033[01m\033[32m[D]\033[0m Account Details\n";
    cout<<"\033[01m\033[32m[A]\033[0m About Us\n";
    cout<<"\033[01m\033[32m[L]\033[0m Logout\n";
    cout<<"\033[01m\033[32m[E]\033[0m Exit\n";
}
void owner_login_start_data(){
    system("cls");
    cout<<"\033[1m\033[31mWelcome @"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[D]\033[0m Employees Details\n";
    cout<<"\033[01m\033[32m[P]\033[0m Products\n";
    cout<<"\033[01m\033[32m[T]\033[0m Total Profit\n";
    cout<<"\033[01m\033[32m[A]\033[0m Account Details\n";
    cout<<"\033[01m\033[32m[U]\033[0m About Us\n";
    cout<<"\033[01m\033[32m[L]\033[0m Logout\n";
    cout<<"\033[01m\033[32m[E]\033[0m Exit\n";
}
void owner_employee_details(){
    cout<<"\n\033[01m\033[32m[L]\033[0m List of Employees\n";
    cout<<"\033[01m\033[32m[C]\033[0m Change Employee Sign Up code\n";
    cout<<"\033[01m\033[32m[S]\033[0m Change Employee Salary\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void Buy_Products_data(){
    system("cls");
    cout<<"\033[1m\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[S]\033[0m Sports Products\n";
    cout<<"\033[01m\033[32m[T]\033[0m Tools\n";
    cout<<"\033[01m\033[32m[E]\033[0m Electronics Products\n";
    cout<<"\033[01m\033[32m[C]\033[0m Cart\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void simple_Products_data(){
    system("cls");
    cout<<"\033[1m\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[S]\033[0m Sports Products\n";
    cout<<"\033[01m\033[32m[T]\033[0m Tools\n";
    cout<<"\033[01m\033[32m[E]\033[0m Electronics Products\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void products_data(){
    system("cls");
    cout<<"\033[1m\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[E]\033[0m Edit Products\n";
    cout<<"\033[01m\033[32m[D]\033[0m Display Products\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void edit_products_data(){
    system("cls");
    cout<<"\033[1m\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[A]\033[0m Add Products\n";
    cout<<"\033[01m\033[32m[M]\033[0m Modify Products\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go Back\n";
}
void log_data(){
    system("cls");
    cout<<"\033[1m\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n\n";
}
void employee_login_start_data(){
    system("cls");
    cout<<"\033[1m\033[31mWelcome @"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[A]\033[0m Mark Attendance\n";
    cout<<"\033[01m\033[32m[S]\033[0m Salary\n";
    cout<<"\033[01m\033[32m[D]\033[0m Account Details\n";
    cout<<"\033[01m\033[32m[U]\033[0m About Us\n";
    cout<<"\033[01m\033[32m[L]\033[0m Logout\n";
    cout<<"\033[01m\033[32m[E]\033[0m Exit\n";
}
void payment_method_data(){
    system("cls");
    cout<<"\033[1m\033[31m @"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------\n";
    cout<<"\n\033[01m\033[32m[C]\033[0m Credit Card\n";
    cout<<"\033[01m\033[32m[D]\033[0m Cash on Delivery\n";
    cout<<"\033[01m\033[32m[B]\033[0m Go back\n";
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
            sign_up_check=0;
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
                sign_up_storage[1]=sign_up_storage[1]+1;
                fstream store("Accounts_log.db",ios::out|ios::in);
                if(store.is_open()){
                    store<<"1\n";
                    store<<sign_up_storage[1]<<"\n";
                    store<<sign_up_storage[2]<<"\n";
                    store<<sign_up_storage[3]<<"\n";
                    store.close();
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mAccounts_log.db\033[0m \n";
                    cout<<"Press Enter to \033[36mTry again\033[0m";
                    getch();
                    cout<<"\n";
                }
                data_file.close();
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
            products_data_to_memory(size_storage);
            int code_by_owner;
            cin>>code_by_owner;
            if(code_by_owner!=size_storage[5]){
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
                    ofstream attendance;
                    attendance.open("attendance.dll",ios::app);
                    if(attendance.is_open()){
                        attendance<<"0\n";
                        attendance<<"0\n";
                        attendance<<"0\n";
                        attendance<<"0\n";
                        attendance.close();
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mattendance.dll\033[0m \n";
                        cout<<"Press Enter to \033[36mTry again\033[0m";
                        getch();
                        cout<<"\n";
                    }
                    sign_up_storage[2]=sign_up_storage[2]+1;
                    fstream store("Accounts_log.db",ios::out|ios::in);
                    if(store.is_open()){
                        store<<"1\n";
                        store<<sign_up_storage[1]<<"\n";
                        store<<sign_up_storage[2]<<"\n";
                        store<<sign_up_storage[3]<<"\n";
                        store.close();
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mAccounts_log.db\033[0m \n";
                        cout<<"Press Enter to \033[36mTry again\033[0m";
                        getch();
                        cout<<"\n";
                    }
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
                    //---------owner data will not increase
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
void Login(Access_data customer_memory[],Access_data employee_memory[],Access_data owner_memory[],int size_customer_data,int size_employee,int size_owner_data){
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
                case 'c':Customer_login(customer_memory,size_customer_data);break;
                case 'e':Employee_login(employee_memory,size_employee);break;
                case 'o':Owner_login(owner_memory,size_owner_data);break;
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
    ---------------------------------------------------
   ---------------------- Sub function -----------------
---------------------for Customer login ------------------
    -----------------------------------------------------
*/
void Customer_login(Access_data memory[],int size){
    system("cls");
    customer_data_to_memory(memory);
    bool login_check;
    bool login_start=false;
    bool login_running=true;
    if(customer_data_loading_check==0){
        do{
            do{
                cin.ignore();
                login_check=true;
                string username,password;
                cout<<"Enter Username\033[31m*\033[0m: ";
                getline(cin,username);
                cout<<"Enter Password\033[31m*\033[0m: ";
                getline(cin,password);
                int i=0;
                while(i<=size){
                    if(username==memory[i].user_name&&password==memory[i].user_pass){
                        login_check=false;
                        store.user_name=memory[i].user_name;
                        store.user_pass=memory[i].user_pass;
                        store.user_address=memory[i].user_address;
                        store.user_credit_num=memory[i].user_credit_num;
                        store.user_credit_code=memory[i].user_credit_code;
                        store.user_credit_exp=memory[i].user_credit_exp;
                        login_start=true;
                        login_running=false;
                        index_login=i;
                    }
                    i++;
                }
                if(login_check==true){
                    cout<<"\033[31mError!!\033[0m Your Username or Password is incorrect\n";
                    cout<<"Press \033[31m[B]\033[0m to go back or [Any other key] to try again: ";
                    char choice;
                    cin>>choice;
                    choice=tolower(choice);
                    if(choice=='b'){
                        login_running=false;
                        login_check=false;
                    }
                    else{
                        login_check=true;
                    }
                }
            }while(login_check!=false);
        }while(login_running);
    }
    if(login_start==true){
        bool login_start_running=true;
        do{
            customer_login_start();
            bool login_start_check=true;
            do{
                cout<<"\nChoose your option: ";
                char login_start_choice;
                cin>>login_start_choice;
                login_start_choice = tolower(login_start_choice);
                switch(login_start_choice){
                    case 'b':Buy_Products();break;
                    case 'd':Account_Details();break;
                    case 'a':About_data();break;
                    case 'l':login_start_running=false;cart_counter=0;total_bill=0;bill_purchase_price=0;profit=0;break;
                    case 'e':exit(0);break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again ";
                            getch();
                            login_start_check=false;
                }
            }while(login_start_check==false);
        }while(login_start_running);
    }
}
//----- customer_login\login\buyproducts
void Buy_Products(){
    bool buy_products_running=true;
    do{
        Buy_Products_data();
        bool buy_products_check=true;
        do{
            cout<<"\nChoose your option: ";
            char buy_products_choice;
            cin>>buy_products_choice;
            buy_products_choice = tolower(buy_products_choice);
            switch(buy_products_choice){
                case 's':sports_products();break;
                case 't':tools();break;
                case 'e':electronics_products();break;
                case 'c':cart_products();break;
                case 'b':buy_products_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        buy_products_check=false;
            }
        }while(buy_products_check==false);
    }while(buy_products_running);
}
void sports_products(){
    bool purchase_sports_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Sports data found. Please contact administrator\n";
            cout<<"Press Enter to go back: ";
            getch();
            purchase_sports_running=false;
        }
        else{
            if(size_storage[1]!=0){
                bool purchase_sports_check;
                do{
                    purchase_sports_check=true;
                    system("cls");
                    Display_customer_sports();
                    Products_data_access *data=new Products_data_access[size_storage[1]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    int quant;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        purchase_sports_check=true;
                        purchase_sports_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[1]){
                        load_sports_data(data);
                        int i;
                        i=ia-1;
                        stringstream convert(data[i].sale_price); //------convert string to integer
                        stringstream convert_pp(data[i].purchase_price);
                        int pp;
                        convert_pp>>pp;
                        int sale_price;
                        convert>>sale_price;
                        cout<<"How many \033[01m\033[35m"<<data[i].name<<"\033[0m you want: ";
                        cin>>quant;
                        int price;
                        price = (quant*sale_price);
                        total_bill= total_bill+price;
                        int pro;
                        pro=(quant*pp);
                        bill_purchase_price = bill_purchase_price+pro;
                        profit = profit + (total_bill-bill_purchase_price);
                        int check;
                        for(int index=0;index<100;index++){
                            if(data[i].name==store_data[index].name){
                                store_data[index].sale_price+=price;
                                store_data[index].quantity+=quant;
                                check=1;
                            }
                        }
                        store_data[cart_counter].name = data[i].name;
                        store_data[cart_counter].sale_price = price;
                        store_data[cart_counter].quantity = quant;
                        if(check!=1){
                            cart_counter++;
                        }
                        bool buy_more;
                        do{
                            buy_more=true;
                            cout<<"Do you want to buy more Sports products\033[01m\033[35m(y/n)\033[0m:";
                            char again_choice;
                            cin>>again_choice;
                            again_choice=tolower(again_choice);
                            switch(again_choice){
                                case 'y':purchase_sports_running=true;break;
                                case 'n':cout<<"\033[1m\033[32mSuccessfully added to cart\033[0m\n";
                                        cout<<"Press Enter to Go back: ";
                                        getch();
                                        purchase_sports_running=false;
                                        break;
                                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                                        cout<<"Press Enter to try again ";
                                        getch();
                                        buy_more=false;
                            }
                        }while(buy_more==false);
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        purchase_sports_check=false;
                    }
                }while(purchase_sports_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Sports data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                purchase_sports_running=false;
            }
        }
    }while(purchase_sports_running);
}
void tools(){
    bool purchase_Tools_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Tools data found. Please contact administrator\n";
            cout<<"Press Enter to go back: ";
            getch();
            purchase_Tools_running=false;
        }
        else{
            if(size_storage[2]!=0){
                bool purchase_Tools_check;
                do{
                    purchase_Tools_check=true;
                    system("cls");
                    Display_customer_tools();
                    Products_data_access *data=new Products_data_access[size_storage[2]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    int quant;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        purchase_Tools_check=true;
                        purchase_Tools_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[2]){
                        load_tools_data(data);
                        int i;
                        i=ia-1;
                        stringstream convert(data[i].sale_price); //------convert string to integer
                        stringstream convert_pp(data[i].purchase_price);
                        int pp;
                        convert_pp>>pp;
                        int sale_price;
                        convert>>sale_price;
                        cout<<"How many \033[01m\033[35m"<<data[i].name<<"\033[0m you want: ";
                        cin>>quant;
                        int price;
                        price = (quant*sale_price);
                        total_bill= total_bill+price;
                        int pro;
                        pro=(quant*pp);
                        bill_purchase_price = bill_purchase_price+pro;
                        profit = profit + (total_bill-bill_purchase_price);
                        int check;
                        for(int index=0;index<100;index++){
                            if(data[i].name==store_data[index].name){
                                store_data[index].sale_price+=price;
                                store_data[index].quantity+=quant;
                                check=1;
                            }
                        }
                        store_data[cart_counter].name = data[i].name;
                        store_data[cart_counter].sale_price = price;
                        store_data[cart_counter].quantity = quant;
                        if(check!=1){
                            cart_counter++;
                        }
                        bool buy_more;
                        do{
                            buy_more=true;
                            cout<<"Do you want to buy more Tools products\033[01m\033[35m(y/n)\033[0m:";
                            char again_choice;
                            cin>>again_choice;
                            again_choice=tolower(again_choice);
                            switch(again_choice){
                                case 'y':purchase_Tools_running=true;break;
                                case 'n':cout<<"\033[1m\033[32mSuccessfully added to cart\033[0m\n";
                                        cout<<"Press Enter to Go back: ";
                                        getch();
                                        purchase_Tools_running=false;
                                        break;
                                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                                        cout<<"Press Enter to try again ";
                                        getch();
                                        buy_more=false;
                            }
                        }while(buy_more==false);
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        purchase_Tools_check=false;
                    }
                }while(purchase_Tools_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Tools data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                purchase_Tools_running=false;
            }
        }
    }while(purchase_Tools_running);
}
void electronics_products(){
    bool purchase_Electronics_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Electronics data found. Please contact administrator\n";
            cout<<"Press Enter to go back: ";
            getch();
            purchase_Electronics_running=false;
        }
        else{
            if(size_storage[3]!=0){
                bool purchase_Electronics_check;
                do{
                    purchase_Electronics_check=true;
                    system("cls");
                    Display_customer_electronics();
                    Products_data_access *data=new Products_data_access[size_storage[3]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    int quant;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        purchase_Electronics_check=true;
                        purchase_Electronics_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[3]){
                        load_electronics_data(data);
                        int i;
                        i=ia-1;
                        stringstream convert(data[i].sale_price); //------convert string to integer
                        stringstream convert_pp(data[i].purchase_price);
                        int pp;
                        convert_pp>>pp;
                        int sale_price;
                        convert>>sale_price;
                        cout<<"How many \033[01m\033[35m"<<data[i].name<<"\033[0m you want: ";
                        cin>>quant;
                        int price;
                        price = (quant*sale_price);
                        total_bill= total_bill+price;
                        int pro;
                        pro=(quant*pp);
                        bill_purchase_price = bill_purchase_price+pro;
                        profit = profit + (total_bill-bill_purchase_price);
                        int check;
                        for(int index=0;index<100;index++){
                            if(data[i].name==store_data[index].name){
                                store_data[index].sale_price+=price;
                                store_data[index].quantity+=quant;
                                check=1;
                            }
                        }
                        store_data[cart_counter].name = data[i].name;
                        store_data[cart_counter].sale_price = price;
                        store_data[cart_counter].quantity = quant;
                        if(check!=1){
                            cart_counter++;
                        }
                        bool buy_more;
                        do{
                            buy_more=true;
                            cout<<"Do you want to buy more Electronics products\033[01m\033[35m(y/n)\033[0m:";
                            char again_choice;
                            cin>>again_choice;
                            again_choice=tolower(again_choice);
                            switch(again_choice){
                                case 'y':purchase_Electronics_running=true;break;
                                case 'n':cout<<"\033[1m\033[32mSuccessfully added to cart\033[0m\n";
                                        cout<<"Press Enter to Go back: ";
                                        getch();
                                        purchase_Electronics_running=false;
                                        break;
                                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                                        cout<<"Press Enter to try again ";
                                        getch();
                                        buy_more=false;
                            }
                        }while(buy_more==false);
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        purchase_Electronics_check=false;
                    }
                }while(purchase_Electronics_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Electronics data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                purchase_Electronics_running=false;
            }
        }
    }while(purchase_Electronics_running);
}
void cart_products(){
    bool cart_products_running=true;
    do{
        bool cart_check=true;
        do{
            system("cls");
            if(cart_counter==0){
                cout<<"\033[31mError!!\033[0m There is no product in the Cart\n";
                cout<<"Press Enter to Go back: ";
                getch();
                cart_products_running=false;
            }
            else{
                cout<<"\033[01m\033[36mProducts\t\t\t"<<left<<setw(25)<<"Quantity"<<setw(25)<<"Price\n\033[0m"<<right<<"\n";
                for(int i=0;i<cart_counter;i++){
                    cout<<left<<setw(25)<<store_data[i].name<<"\t\t\t"<<left<<setw(25)<<store_data[i].quantity<<setw(25)<<store_data[i].sale_price<<right<<"\n";
                }
                cout<<"---------------------------------------------------------------\n";
                cout<<"\033[32mTotal bill\033[0m:"<<setw(50)<<total_bill<<"\n";
                cout<<"\nPress \033[36m[P]\033[0m to Purchase or \033[31m[B]\033[0m to go back: ";
                char cart_products_choice;
                cin>>cart_products_choice;
                cart_products_choice = tolower(cart_products_choice);
                switch(cart_products_choice){
                    case 'p':payment_method();cart_products_running=false;break;
                    case 'b':cart_products_running=false;break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again ";
                            getch();
                            cart_check=false;
                }
            }
        }while(cart_check==false);
    }while(cart_products_running);
}
void payment_method(){
    bool payment_method_running=true;
    do{
        bool payment_method_check=true;
        do{
            payment_method_data();
            cout<<"\nChoose Your Option: ";
            char payment_method_choice;
            cin>>payment_method_choice;
            payment_method_choice = tolower(payment_method_choice);
            switch(payment_method_choice){
                case 'c':credit_card_payment();payment_method_running=false;break;
                case 'd':cash_on_delivery();payment_method_running=false;break;
                case 'b':payment_method_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        payment_method_check=false;
            }
        }while(payment_method_check==false);

    }while(payment_method_running);
}
void credit_card_payment(){
    bool credit_card_payment_running=true;
    int cc_check;
    int order_placed;
    do{
        bool credit_card_check=true;
        do{
            if(store.user_credit_num=="---"){
                cout<<"Credit Card details are not added. \n\033[36mDo you want add Credit Card info\033[0m\033[01m\033[35m(y/n)\033[0m: ";
                char c_c_payment_choice;
                cin>>c_c_payment_choice;
                c_c_payment_choice=tolower(c_c_payment_choice);
                switch(c_c_payment_choice){
                    case 'y':cc_check=1;credit_card_payment_running=false;break;
                    case 'n':credit_card_payment_running=false;break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        credit_card_check=false;
                }
            }
            else{
                order_placed=1;
                credit_card_payment_running=false;
            }
        }while(credit_card_check==false);
    }while(credit_card_payment_running);
    if(cc_check==1){
        cout<<"Enter Your Credit Card Number: ";
        cin.ignore();
        getline(cin,store.user_credit_num);
        cout<<"Enter Code: ";
        cin>>store.user_credit_code;
        cout<<"Enter Expire Details(MM/YY): ";
        cin.ignore();
        getline(cin,store.user_credit_exp);
        Access_data *data=new Access_data[sign_up_storage[1]];
        customer_data_to_memory(data);
        data[index_login].user_credit_num=store.user_credit_num;
        data[index_login].user_credit_code=store.user_credit_code;
        data[index_login].user_credit_exp=store.user_credit_exp;
        ofstream customer("Customer_ID.db");
        if(customer.is_open()){
            int index=0;
            do{
                customer<<data[index].user_name<<"\n"<<data[index].user_pass<<"\n"<<data[index].user_address<<"\n"<<data[index].user_credit_num<<"\n"<<data[index].user_credit_code<<"\n"<<data[index].user_credit_exp<<"\n";
                index++;
            }while(data[index].user_name!="") ;
            customer.close();
        }
        else{
            cout<<"\033[31mError!!\033[0m Unable to access the \033[31mCustomer_ID.db\033[0m \033[36mTry again\033[0m\n";
            cout<<"Press Enter to Go back: ";
            getch();
        }
    }
    order_placed=1;
    if(order_placed==1){
        cout<<"Confirm Order(y/n): ";
        char order_choice;
        cin>>order_choice;
        order_choice = tolower(order_choice);
        if(order_choice=='y'){
            bool check=true;
            do{
                ofstream order("Order_placed.log",ios::app);
                if(order.is_open()){
                    order<<store.user_name<<"\n"<<store.user_credit_num<<"\n"<<profit<<"\nCredit_Card_payment\n";
                    order.close();
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to access the \033[31mOrder_placed.log\033[0m \033[36mTry again\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                }
                products_data_to_memory(size_storage);
                size_storage[6]+=1;
                ofstream increment("Products_log.db");
                if(increment.is_open()){
                    increment<<size_storage[0]<<"\n"<<size_storage[1]<<"\n"<<size_storage[2]<<"\n"<<size_storage[3]<<"\n"<<size_storage[4]<<"\n"<<size_storage[5]<<"\n"<<size_storage[6]<<"\n"<<size_storage[7]<<"\n";
                }
                cout<<"\033[32mSuccefully placed your order.\033[0m\n";
                cout<<"Press \033[36m[P]\033[0m to print receipt or \033[31m[B]\033[0m to go back: ";
                char choice;
                cin>>choice;
                choice=tolower(choice);
                switch(choice){
                    case 'p':print_receipt();break;
                    case 'b':break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again: ";
                            getch();
                            check=false;
                }
            }while(check==false);
        }
        else if(order_choice=='n'){
            cout<<"\033[32mOk!!!\033[0m\n";
            cout<<"Press Enter to continue: ";
            getch();
        }
        else{
            cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
            cout<<"Press Enter to try again: ";
            getch();
        }
    }
}
void print_receipt(){
    system("cls");
    cout<<setw(50)<<"\033[31m@"<<store.user_name<<"\033[0m\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    cout<<"\033[01m\033[36mProducts\t\t\t\t   "<<left<<setw(60)<<"Quantity"<<setw(2)<<"Price\n\033[0m"<<right<<setw(20)<<"\n";
    for(int i=0;i<cart_counter;i++){
        cout<<left<<setw(25)<<store_data[i].name<<"\t\t\t"<<left<<setw(25)<<store_data[i].quantity<<setw(30)<<store_data[i].sale_price<<right<<"\n";
    }
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    cout<<"\033[32mTotal bill\033[0m:"<<setw(75)<<total_bill<<"\n";
    time_t now =time(0);
	char* day_find = ctime(&now);
	cout<<"\033[01m\033[31mTime\033[0m = "<<day_find<<"\n";
    cout<<"Press Enter to continue: ";
    getch();
}
void cash_on_delivery(){
    bool address_payment_running=true;
    int cc_check;
    int order_placed;
    do{
        bool address_check=true;
        do{
            if(store.user_address=="---"){
                cout<<"Address details are not added. \n\033[36mDo you want add Address info\033[0m\033[01m\033[35m(y/n)\033[0m: ";
                char address_choice;
                cin>>address_choice;
                address_choice=tolower(address_choice);
                switch(address_choice){
                    case 'y':cc_check=1;address_payment_running=false;break;
                    case 'n':address_payment_running=false;break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        address_check=false;
                }
            }
            else{
                order_placed=1;
                address_payment_running=false;
            }
        }while(address_check==false);
    }while(address_payment_running);
    if(cc_check==1){
        cout<<"Enter Your Address: ";
        cin.ignore();
        getline(cin,store.user_address);
        Access_data *data=new Access_data[sign_up_storage[1]];
        customer_data_to_memory(data);
        data[index_login].user_address=store.user_address;
        ofstream customer("Customer_ID.db");
        if(customer.is_open()){
            int index=0;
            do{
                customer<<data[index].user_name<<"\n"<<data[index].user_pass<<"\n"<<data[index].user_address<<"\n"<<data[index].user_credit_num<<"\n"<<data[index].user_credit_code<<"\n"<<data[index].user_credit_exp<<"\n";
                index++;
            }while(data[index].user_name!="") ;
            customer.close();
        }
        else{
            cout<<"\033[31mError!!\033[0m Unable to access the \033[31mCustomer_ID.db\033[0m \033[36mTry again\033[0m\n";
            cout<<"Press Enter to Go back: ";
            getch();
        }
    }
    order_placed=1;
    if(order_placed==1){
        cout<<"Confirm Order(y/n): ";
        char order_choice;
        cin>>order_choice;
        order_choice = tolower(order_choice);
        if(order_choice=='y'){
            bool check=true;
            do{
                check=true;
                ofstream order("Order_placed.log",ios::app);
                if(order.is_open()){
                    order<<store.user_name<<"\n"<<store.user_credit_num<<"\n"<<profit<<"\nCash_on_delivery\n";
                    order.close();
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to access the \033[31mOrder_placed.log\033[0m \033[36mTry again\033[0m\n";
                    cout<<"Press Enter to Go back: ";
                    getch();
                }
                products_data_to_memory(size_storage);
                size_storage[6]+=1;
                ofstream increment("Products_log.db");
                if(increment.is_open()){
                    increment<<size_storage[0]<<"\n"<<size_storage[1]<<"\n"<<size_storage[2]<<"\n"<<size_storage[3]<<"\n"<<size_storage[4]<<"\n"<<size_storage[5]<<"\n"<<size_storage[6]<<"\n"<<size_storage[7]<<"\n";
                }
                cout<<"\033[32mSuccefully placed you order.\033[0m\n";
                cout<<"Press \033[36m[P]\033[0m to print receipt or \033[31m[B]\033[0m to go back: ";
                char choice;
                cin>>choice;
                choice=tolower(choice);
                switch(choice){
                    case 'p':print_receipt();break;
                    case 'b':break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again ";
                            getch();
                            check=false;
                }
            }while(check==false);
        }
        else if(order_choice=='n'){
            cout<<"\033[32mOk!!!\033[0m\n";
            cout<<"Press Enter to continue: ";
            getch();
        }
        else{
            cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
            cout<<"Press Enter to try again: ";
            getch();
        }
    }
}
void Account_Details(){
    bool account_detail_running=true;
    do{
        bool account_detail_check;
        do{
            log_data();
            account_detail_check=true;
            cout<<"\033[1m\033[32mUsername\033[0m: "<<store.user_name<<"\n";
            cout<<"\033[1m\033[32mAddress\033[0m: "<<store.user_address<<"\n";
            cout<<"\033[1m\033[32mCredit Card No.:\033[0m "<<store.user_credit_num<<"\n";
            cout<<"\033[1m\033[32mCredit Card Expiry\033[0m: "<<store.user_credit_exp<<"\n";
            cout<<"\nPress \033[36m[E]\033[0m to edit or \033[31m[B]\033[0m to go back: ";
            char account_choice;
            cin>>account_choice;
            account_choice = tolower(account_choice);
            switch(account_choice){
                case 'e':edit_customer();break;
                case 'b':account_detail_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        account_detail_check=false;
            }
        }while(account_detail_check==false);
    }while(account_detail_running);
}
void edit_customer(){
    system("cls");
    Access_data *customer=new Access_data[sign_up_storage[1]];
    customer_data_to_memory(customer);
    customer[index_login].user_name="";
    int check;
    cin.ignore();
    do{ 
        check=0;
        cout<<"Enter New Username\033[31m*\033[0m: ";
        getline(cin,store.user_name);
        int i=0;
        while(i<=sign_up_storage[1]){ //----------run until end of line to check for same Username
            if(store.user_name==customer[i].user_name){ //---this checks for if there is already an Username Present
                cout<<"\033[31mError!!\033[0m User Name is Already Present: \033[31mTry again\033[0m\n";
                cin.ignore();
                check=1;
                store.user_name.clear();
                break;
            }
            i++;
        }
    }while(check==1);
    do{
        cout<<"Enter New Password\033[31m*\033[0m: ";
        getline(cin,store.user_pass);
        if(store.user_pass.length()<8){
            cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
            cout<<"Press Enter to \033[31mTry again\033[0m";
            getch();
        }
    }while(store.user_pass.length()<8);
    int address_check=0;
    char choice_address;
    char choice_cd;
    //-----------there is a choice for user. he may enter address now or later on any purchase
    do{
        address_check=0;
        cout<<"Do you want to Add Address(y/n): ";
        cin>>choice_address;
        choice_address = tolower(choice_address);
        switch(choice_address){
            case 'y':cout<<"Enter Your Address: ";
                    cin.ignore();
                    getline(cin,store.user_address);
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
                    getline(cin,store.user_credit_num);
                    cout<<"Enter Code: ";
                    cin>>store.user_credit_code;
                    cout<<"Enter Expire Details(MM/YY): ";
                    cin.ignore();
                    getline(cin,store.user_credit_exp);
                    break;
            case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
            default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                    cout<<"Press Enter to \033[31mTry again\033[0m";
                    getch();
                    cd_check=1;
        }
    }while(cd_check==1);
    customer[index_login].user_name=store.user_name;
    customer[index_login].user_pass=store.user_pass;
    customer[index_login].user_address=store.user_address;
    customer[index_login].user_credit_num=store.user_credit_num;
    customer[index_login].user_credit_code=store.user_credit_code;
    customer[index_login].user_credit_exp=store.user_credit_exp;
    fstream customer_data("Customer_ID.db",ios::out);
    int index=0;
    do{
        customer_data<<customer[index].user_name<<"\n"<<customer[index].user_pass<<"\n"<<customer[index].user_address<<"\n"<<customer[index].user_credit_num<<"\n"<<customer[index].user_credit_code<<"\n"<<customer[index].user_credit_exp<<"\n";
        index++;
    }while(customer[index].user_name!="");
    customer_data.close();
    cout<<"\033[1m\033[32mSuccessfully Saved new details\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
}
void Employee_login(Access_data memory[],int size){
    system("cls");
    employee_data_to_memory(memory);
    bool employee_login_running=true;
    bool employee_login_check;
    bool employee_login_start=false;
    do{
        do{
            employee_login_check=true;
            string username,password;
            cout<<"Enter Username\033[31m*\033[0m: ";
            cin.ignore();
            getline(cin,username);
            cout<<"Enter Password\033[31m*\033[0m: ";
            getline(cin,password);
            int i=0;
            while(i<=size){
                if(username==memory[i].user_name&&password==memory[i].user_pass){
                    employee_login_check=false;
                    store.user_name=memory[i].user_name;
                    store.user_pass=memory[i].user_pass;
                    store.user_address=memory[i].user_address;
                    store.user_credit_num=memory[i].user_credit_num;
                    store.user_credit_code=memory[i].user_credit_code;
                    store.user_credit_exp=memory[i].user_credit_exp;
                    employee_login_start=true;
                    employee_login_running=false;
                    index_login=i;
                }
                i++;
            }
            if(employee_login_check==true){
                cout<<"\033[31mError!!\033[0m Your Username or Password is incorrect\n";
                cout<<"Press \033[31m[B]\033[0m to go back or [Any other key] to try again: ";
                char choice;
                cin>>choice;
                choice=tolower(choice);
                if(choice=='b'){
                    employee_login_running=false;
                    employee_login_check=false;
                }
                else{
                    employee_login_check=true;
                }
            }
        }while(employee_login_check!=false);
    }while(employee_login_running);
    if(employee_login_start){ 
        bool employee_login_start_running=true;
        do{
            employee_login_start_data();
            bool employee_login_start_check=true;
            do{
                cout<<"\nChoose your option: ";
                char employee_login_choice;
                cin>>employee_login_choice;
                employee_login_choice = tolower(employee_login_choice);
                switch(employee_login_choice){
                    case 'a':attendance_employee();break;
                    case 's':salary_employee();break;
                    case 'd':Account_Details_employee();break;
                    case 'u':About_data();break;
                    case 'l':employee_login_start_running=false;break;
                    case 'e':exit(0);break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again ";
                            getch();
                            employee_login_start_check=false;
                }
            }while(employee_login_start_check==false);
        }while(employee_login_start_running);
    }
}
void attendance_employee(){
    time_t now=time(0);
    string full_date = ctime(&now);
    string d = full_date.substr(8,2);
    string h = full_date.substr(11,2);
    string m = full_date.substr(14,2);
    string s = full_date.substr(17,2);
    stringstream convert_day(d);
    int day;
    convert_day>>day;
    stringstream convert_hour(h);
    int hour;
    convert_hour>>hour;
    stringstream convert_minute(m);
    int minute;
    convert_minute>>minute;
    stringstream convert_second(s);
    int second;
    convert_second>>second;
    int total_seconds = (day*86400)+(hour*3600)+(minute*60)+second;
    int next_day = day+1;
    int next_hour = 8;
    int next_minute=0;
    int next_second=0;
    int total_seconds_next_day = (next_day*86400)+(next_hour*3600)+(next_minute*60)+next_second;
    //------attendance can only be marked from 8AM to 9PM
    if(hour>=8&&hour<=21){
        attendance_data *data=new attendance_data[sign_up_storage[2]];
        attendance_data_to_memory(data);
        attendence_checker:
        if(data[index_login].check!="1"){
            //--------first convert string to integer then increment 1 and convert integer to string
            stringstream convert_to_integer(data[index_login].attendance);
            int increament;
            convert_to_integer>>increament;
            increament+=1;
            stringstream convert_to_string;
            convert_to_string<<increament;
            convert_to_string>>data[index_login].attendance;
            //---------for current time
            //--converting time to seconds
            stringstream current_time_to_string;
            current_time_to_string<<total_seconds;
            current_time_to_string>>data[index_login].current_time;
            //--------store time of next day starting from 8 AM
            stringstream target_time_to_string;
            target_time_to_string<<total_seconds_next_day;
            target_time_to_string>>data[index_login].target_time;
            data[index_login].check="1";
            ofstream attendance("attendance.dll");
            if(attendance.is_open()){
                int index=0;
                do{
                    attendance<<data[index].attendance<<"\n"<<data[index].current_time<<"\n"<<data[index].target_time<<"\n"<<data[index].check<<"\n";
                    index++;
                }while(data[index].attendance!="");
            }
            cout<<"\033[32mSuccessfully Marked Your Attendance\033[0m\n";
            cout<<"Press Enter to go back: ";
            getch();
        }
        else{
            stringstream convert_target_time(data[index_login].target_time);
            int target_time;
            convert_target_time>>target_time;
            int time_aloft=target_time-total_seconds;
            if(time_aloft>0){
                cout<<"\033[32mYour Attendance has already been Marked\033[0m\n";
                int left_second = time_aloft;
                int final_day = left_second/86400;
                left_second%=86400;
                int final_hour=left_second/3600;
                left_second%=3600;
                int final_minute=left_second/60;
                left_second%=60;
                int final_second=left_second;
                cout<<"You can Mark your next Attendance after: \033[36m"<<final_day<<"\033[0m Days \033[36m"<<final_hour<<"\033[0m Hours \033[36m"<<final_minute<<"\033[0m Minutes \033[36m"<<final_second<<"\033[0m Seconds\n";
                cout<<"Press Enter to go back: ";
                getch();
            }
            else{
                data[index_login].check="0";
                goto attendence_checker;
            }
        }
    }
    else{
        cout<<"\033[31mError!!\033[0m Attendance Can only be marked and checked from 8AM - 9PM\n";
        cout<<"Press Enter to go back ";
        getch();
    }
}
void salary_employee(){
    products_data_to_memory(size_storage);
    attendance_data *data=new attendance_data[sign_up_storage[2]];
    attendance_data_to_memory(data);
    stringstream convert_to_integer(data[index_login].attendance);
    int attendance;
    convert_to_integer>>attendance;
    int total_salary=attendance*size_storage[4];
    bool salary_employee_running=true;
    if(total_salary!=0){
        do{
            bool salary_check;
            do{
                salary_check=true;
                log_data();
                cout<<"Your Total salary = \033[32m"<<total_salary<<"\033[0mrs\n";
                cout<<"\nPress \033[36m[W]\033[0m to withdraw or \033[31m[B]\033[0m to go back: ";
                char salary_choice;
                cin>>salary_choice;
                salary_choice=tolower(salary_choice);
                switch(salary_choice){
                    case 'w':withdraw_of_employee(total_salary,data,size_storage);salary_employee_running=false;break;
                    case 'b':salary_employee_running=false;break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again: ";
                            getch();
                            salary_check=false;
                }
            }while(salary_check==false);
        }while(salary_employee_running);
    }
    else{
        cout<<"\033[31mError!!\033[0m You Haven't Marked your Attendance or you had already withdrawn your Salary.\n";
        cout<<"Press Enter to go back: ";
        getch();
    }
}
void withdraw_of_employee(int total_salary,attendance_data data[],int size_storage[]){
    time_t temp=time(0);
    string current_time = ctime(&temp);
    fstream salary("salary.log",ios::app|ios::in|ios::out);
    if(salary.is_open()){
        salary<<store.user_name<<"\n";
        salary<<store.user_credit_num<<"\n";
        salary<<store.user_address<<"\n";
        salary<<total_salary<<"\n";
        salary<<current_time;
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31msalary.log\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
    products_data_to_memory(size_storage);
    size_storage[7]+=1;
    ofstream increment("Products_log.db");
    if(increment.is_open()){
        increment<<size_storage[0]<<"\n"<<size_storage[1]<<"\n"<<size_storage[2]<<"\n"<<size_storage[3]<<"\n"<<size_storage[4]<<"\n"<<size_storage[5]<<"\n"<<size_storage[6]<<"\n"<<size_storage[7]<<"\n";
    }
    data[index_login].attendance="0";
    ofstream attendance("attendance.dll");
    if(attendance.is_open()){
        int index=0;
        do{
            attendance<<data[index].attendance<<"\n"<<data[index].current_time<<"\n"<<data[index].target_time<<"\n"<<data[index].check<<"\n";
            index++;
        }while(data[index].attendance!="");
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mattendance.dll\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
    cout<<"\033[32mSuccessfully Transfered money to your Account.\033[0m\n";
    cout<<"Press Enter to go back: ";
    getch();
}
void Account_Details_employee(){
    bool account_detail_running=true;
    do{
        bool account_detail_check;
        do{
            log_data();
            account_detail_check=true;
            cout<<"\033[1m\033[32mUsername\033[0m: "<<store.user_name<<"\n";
            cout<<"\033[1m\033[32mAddress\033[0m: "<<store.user_address<<"\n";
            cout<<"\033[1m\033[32mCredit Card No.:\033[0m "<<store.user_credit_num<<"\n";
            cout<<"\033[1m\033[32mCredit Card Expiry\033[0m: "<<store.user_credit_exp<<"\n";
            cout<<"\nPress \033[36m[E]\033[0m to edit or \033[31m[B]\033[0m to go back: ";
            char account_choice;
            cin>>account_choice;
            account_choice = tolower(account_choice);
            switch(account_choice){
                case 'e':edit_employee();break;
                case 'b':account_detail_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        account_detail_check=false;
            }
        }while(account_detail_check==false);
    }while(account_detail_running);
}
void edit_employee(){
    system("cls");
    Access_data *employee=new Access_data[sign_up_storage[2]];
    employee_data_to_memory(employee);
    employee[index_login].user_name="";
    int check;
    cin.ignore();
    do{ 
        check=0;
        cout<<"Enter New Username\033[31m*\033[0m: ";
        getline(cin,store.user_name);
        int i=0;
        while(i<=sign_up_storage[2]){ //----------run until end of line to check for same Username
            if(store.user_name==employee[i].user_name){ //---this checks for if there is already an Username Present
                cout<<"\033[31mError!!\033[0m User Name is Already Present: \033[31mTry again\033[0m\n";
                cin.ignore();
                check=1;
                store.user_name.clear();
                break;
            }
            i++;
        }
    }while(check==1);
    do{
        cout<<"Enter New Password\033[31m*\033[0m: ";
        getline(cin,store.user_pass);
        if(store.user_pass.length()<8){
            cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
            cout<<"Press Enter to \033[31mTry again\033[0m";
            getch();
        }
    }while(store.user_pass.length()<8);
    int address_check=0;
    char choice_address;
    char choice_cd;
    //-----------there is a choice for user. he may enter address 
    do{
        address_check=0;
        cout<<"Do you want to Add Address(y/n): ";
        cin>>choice_address;
        choice_address = tolower(choice_address);
        switch(choice_address){
            case 'y':cout<<"Enter Your Address: ";
                    cin.ignore();
                    getline(cin,store.user_address);
                    break;
            case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
            default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                    cout<<"Press Enter to \033[31mTry again\033[0m";
                    getch();
                    address_check=1;
        }
    }while(address_check==1);
    int cd_check=0;
    //-----------there is a choice for user. he may enter Credit-Card 
    do{
        cout<<"Do you want to Add Credit-Card Details(y/n): ";
        cin>>choice_cd;
        choice_cd = tolower(choice_cd);
        switch(choice_cd){
            case 'y':cout<<"Enter Your Credit Card Number: ";
                    cin.ignore();
                    getline(cin,store.user_credit_num);
                    cout<<"Enter Code: ";
                    cin>>store.user_credit_code;
                    cout<<"Enter Expire Details(MM/YY): ";
                    cin.ignore();
                    getline(cin,store.user_credit_exp);
                    break;
            case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
            default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                    cout<<"Press Enter to \033[31mTry again\033[0m";
                    getch();
                    cd_check=1;
        }
    }while(cd_check==1);
    employee[index_login].user_name=store.user_name;
    employee[index_login].user_pass=store.user_pass;
    employee[index_login].user_address=store.user_address;
    employee[index_login].user_credit_num=store.user_credit_num;
    employee[index_login].user_credit_code=store.user_credit_code;
    employee[index_login].user_credit_exp=store.user_credit_exp;
    fstream employee_data("Employee_ID.db",ios::out);
    int index=0;
    do{
        employee_data<<employee[index].user_name<<"\n"<<employee[index].user_pass<<"\n"<<employee[index].user_address<<"\n"<<employee[index].user_credit_num<<"\n"<<employee[index].user_credit_code<<"\n"<<employee[index].user_credit_exp<<"\n";
        index++;
    }while(employee[index].user_name!="");
    employee_data.close();
    cout<<"\033[1m\033[32mSuccessfully Saved new details\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
}
/*
    ---------------------------------------------------
   ---------------------- Sub function -----------------
---------------------for owner login ------------------
    -----------------------------------------------------
*/
void Owner_login(Access_data memory[],int size){
    system("cls");
    owner_data_to_memory(memory);
    bool owner_login_running=true;
    bool owner_login_check;
    bool owner_login_start=false;
    do{
        do{
            owner_login_check=true;
            string username,password;
            cout<<"Enter Username\033[31m*\033[0m: ";
            cin.ignore();
            getline(cin,username);
            cout<<"Enter Password\033[31m*\033[0m: ";
            getline(cin,password);
            int i=0;
            while(i<=size){
                if(username==memory[i].user_name&&password==memory[i].user_pass){
                    owner_login_check=false;
                    store.user_name=memory[i].user_name;
                    store.user_pass=memory[i].user_pass;
                    store.user_address=memory[i].user_address;
                    store.user_credit_num=memory[i].user_credit_num;
                    store.user_credit_code=memory[i].user_credit_code;
                    store.user_credit_exp=memory[i].user_credit_exp;
                    owner_login_start=true;
                    owner_login_running=false;
                    index_login=i;
                }
                i++;
            }
            if(owner_login_check==true){
                cout<<"\033[31mError!!\033[0m Your Username or Password is incorrect\n";
                cout<<"Press \033[31m[B]\033[0m to go back or [Any other key] to try again: ";
                char choice;
                cin>>choice;
                choice=tolower(choice);
                if(choice=='b'){
                    owner_login_running=false;
                    owner_login_check=false;
                }
                else{
                    owner_login_check=true;
                }
            }
        }while(owner_login_check!=false);
    }while(owner_login_running);
    if(owner_login_start){ 
        bool owner_login_start_running=true;
        do{
            owner_login_start_data();
            bool owner_login_start_check=true;
            do{
                cout<<"\nChoose your option: ";
                char owner_login_choice;
                cin>>owner_login_choice;
                owner_login_choice = tolower(owner_login_choice);
                switch(owner_login_choice){
                    case 'd':employee_details_by_owner();break;
                    case 'p':products_main();break;
                    case 't':total_profit();break;
                    case 'a':Account_Details_Owner();break;
                    case 'u':About_data();break;
                    case 'l':owner_login_start_running=false;break;
                    case 'e':exit(0);break;
                    default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                            cout<<"Press Enter to try again ";
                            getch();
                            owner_login_start_check=false;
                }
            }while(owner_login_start_check==false);
        }while(owner_login_start_running);
    }
}
void employee_details_by_owner(){
    int employee_counter=0;
    Access_data *memory=new Access_data[sign_up_storage[2]];
    employee_data_to_memory(memory);
    for(int index=0;index<sign_up_storage[2];index++){
        if(memory[index].user_name!=""){
            employee_counter++;
        }
    }
    bool employee_detail_running=true;
    do{
        bool employee_detail_check;
        do{
            log_data();
            employee_detail_check=true;
            cout<<"There are currently \033[32m"<<employee_counter<<"\033[0m Employees\n";
            products_data_to_memory(size_storage); //-------for salary and code
            cout<<"Employee Sign Up Code: \033[32m"<<size_storage[5]<<"\033[0m\n";
            cout<<"Employee Salary(Per Hour): \033[32m"<<size_storage[4]<<"\033[0m\n";
            owner_employee_details();
            cout<<"\nChoose your option: ";
            char employee_detail_choice;
            cin>>employee_detail_choice;
            employee_detail_choice=tolower(employee_detail_choice);
            switch(employee_detail_choice){
                case 'l':list_employee(memory,sign_up_storage[2]);break;
                case 'c':change_employee_code();break;
                case 's':change_employee_salary();break;
                case 'b':employee_detail_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        employee_detail_check=false;
            }
        }while(employee_detail_check==false);
    }while(employee_detail_running);
}
void change_employee_code(){
    products_data_to_memory(size_storage);
    cout<<"Enter New Code: ";
    cin>>size_storage[5];
    ofstream increment("Products_log.db");
    if(increment.is_open()){
        increment<<size_storage[0]<<"\n"<<size_storage[1]<<"\n"<<size_storage[2]<<"\n"<<size_storage[3]<<"\n"<<size_storage[4]<<"\n"<<size_storage[5]<<"\n"<<size_storage[6]<<"\n"<<size_storage[7]<<"\n";
    }
    cout<<"\033[32mSuccessfully Modified code\033[0m\n";
    cout<<"Press Enter to continue: ";
    getch();
}
void change_employee_salary(){
    products_data_to_memory(size_storage);
    cout<<"Enter New Salary: ";
    cin>>size_storage[4];
    ofstream increment("Products_log.db");
    if(increment.is_open()){
        increment<<size_storage[0]<<"\n"<<size_storage[1]<<"\n"<<size_storage[2]<<"\n"<<size_storage[3]<<"\n"<<size_storage[4]<<"\n"<<size_storage[5]<<"\n"<<size_storage[6]<<"\n"<<size_storage[7]<<"\n";
    }
    cout<<"\033[32mSuccessfully Modified Salary\033[0m\n";
    cout<<"Press Enter to continue: ";
    getch();
}
void list_employee(Access_data memory[],int size){
    bool list_employee_running=true;
    int employee_counter=0;
    employee_data_to_memory(memory);
    for(int index=0;index<sign_up_storage[2];index++){
        if(memory[index].user_name!=""){
            employee_counter++;
        }
    }
    do{
        system("cls");
        log_data();
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t Address"<<setw(40)<<"Credit Card Number\n\033[0m";
        cout<<"\033[01m\033[33m-------------------------------------------------------------------------------------\033[0m\n";
        for(int index=0;index<size;index++){
            if(memory[index].user_name!=""){
                cout<<index+1<<"\t\t"<<setw(25)<<left<<memory[index].user_name<<setw(25)<<memory[index].user_address<<setw(25)<<memory[index].user_credit_num<<right<<"\n";
            }
        }
        bool list_employee_check;
        do{
            list_employee_check=true;
            accounts_data_to_memory(sign_up_storage);
            Access_data*employee_data=new Access_data[sign_up_storage[2]];
            employee_data_to_memory(employee_data);
            cout<<"\nChoose the Desired Number to Remove any Employee or \033[31m[B]\033[0m to go back: ";
            char a_value;
            cin>>a_value;
            a_value=tolower(a_value);
            int ia = a_value-'0';
            if(a_value=='b'){
                list_employee_check=true;
                list_employee_running=false;
            }
            else if(ia>0&&ia<=employee_counter){
                int i;
                i=ia-1;
                attendance_data* at_data=new attendance_data[sign_up_storage[2]];
                attendance_data_to_memory(at_data);
                ofstream attendance("attendance.dll");
                attendance.close();
                ofstream check("Employee_ID.db");
                check.close();
                at_data[i].attendance="";
                at_data[i].check="";
                at_data[i].current_time="";
                at_data[i].target_time="";
                employee_data[i].user_name="";
                employee_data[i].user_pass="";
                employee_data[i].user_address="";
                employee_data[i].user_credit_num="";
                employee_data[i].user_credit_code="";
                employee_data[i].user_credit_exp="";
                fstream change_employee("Employee_ID.db",ios::app|ios::out);
                if(change_employee.is_open()){
                    int index=0;
                    for(index;index<sign_up_storage[2];index++){
                        if(employee_data[index].user_name!=""){
                            change_employee<<employee_data[index].user_name<<"\n"<<employee_data[index].user_pass<<"\n"<<employee_data[index].user_address<<"\n"<<employee_data[index].user_credit_num<<"\n"<<employee_data[index].user_credit_code<<"\n"<<employee_data[index].user_credit_exp<<"\n";
                        }
                    }
                    change_employee.close();
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mEmployee_ID.db\033[0m \n";
                    cout<<"Press Enter to \033[36mTry again\033[0m";
                    getch();
                    cout<<"\n";
                }
                fstream change_at_data("attendance.dll",ios::app|ios::out);
                if(change_at_data.is_open()){
                    int index=0;
                    for(index;index<sign_up_storage[2];index++){
                        if(at_data[index].attendance!=""){
                            change_at_data<<at_data[index].attendance<<"\n"<<at_data[index].current_time<<"\n"<<at_data[index].target_time<<"\n"<<at_data[index].check<<"\n";
                        }
                    }
                    change_at_data.close();
                }
                else{
                    cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mEmployee_ID.db\033[0m \n";
                    cout<<"Press Enter to \033[36mTry again\033[0m";
                    getch();
                    cout<<"\n";
                }
                list_employee_running=false;
            }
            else{
                cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                cout<<"Press Enter to try again ";
                getch();
                list_employee_check=false;
            }
        }while(list_employee_check==false);
    }while(list_employee_running);
}
void products_main(){
    bool products_main_running=true;
    do{
        bool products_check=true;
        do{
            products_data();
            cout<<"\nChoose your option: ";
            char products_choice;
            cin>>products_choice;
            products_choice=tolower(products_choice);
            switch(products_choice){
                case 'e':edit_products();break;
                case 'd':display_products();break;
                case 'b':products_main_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        products_check=false;
            }
        }while(products_check==false);
    }while(products_main_running);
}
void edit_products(){
    bool edit_products_running=true;
    do{
        bool edit_products_check=true;
        do{
            edit_products_data();
            cout<<"\nChoose your option: ";
            char edit_products_choice;
            cin>>edit_products_choice;
            edit_products_choice=tolower(edit_products_choice);
            switch(edit_products_choice){
                case 'a':add_products();break;
                case 'm':modify_products();break;
                case 'b':edit_products_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        edit_products_check=false;
            }
        }while(edit_products_check==false);
    }while(edit_products_running);
}
//--------functions to add products to memory
void add_products(){
    bool add_products_running=true;
    do{
        bool add_products_check=true;
        do{
            simple_Products_data(); //--------due to same function of a function instead add it is buy
            cout<<"\nChoose your option: ";
            char add_products_choice;
            cin>>add_products_choice;
            add_products_choice=tolower(add_products_choice);
            switch(add_products_choice){
                case 's':add_sports();break;
                case 't':add_tools();break;
                case 'e':add_electronics();break;
                case 'b':add_products_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        add_products_check=false;
            }
        }while(add_products_check==false);
    }while(add_products_running);
}
void add_sports(){
    system("cls");
    cout<<"\nHow many \033[01m\033[34mProducts\033[0m you want to add: ";
    int to_add;
    cin>>to_add;
    products_data_to_memory(size_storage);
    size_storage[1]+=to_add;
    fstream store("Products_log.db",ios::out|ios::in);
    if(store.is_open()){
        store<<"1\n";
        store<<size_storage[1]<<"\n";
        store<<size_storage[2]<<"\n";
        store<<size_storage[3]<<"\n";
        store<<size_storage[4]<<"\n";
        store<<size_storage[5]<<"\n";
        store.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mProducts_log.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
    Products*data=new Products[to_add];
    ofstream store_data("Sports_data.db",ios::app);
    for(int i=0;i<to_add;i++){
        cout<<"\nEnter \033[01m\033[35mproduct "<<i+1<<"\033[0m name: ";
        cin.ignore();
        getline(cin,data[i].name);
        cout<<"Enter \033[01m\033[35mpurchase price\033[0m of product: ";
        cin>>data[i].purchase_price;
        cout<<"Enter \033[01m\033[35mSale price\033[0m: ";
        cin>>data[i].sale_price;
        if(store_data.is_open()){
            store_data<<data[i].name<<"\n";
            store_data<<data[i].purchase_price<<"\n";
            store_data<<data[i].sale_price<<"\n";
        }
    }
    store_data.close();
    cout<<"\033[1m\033[32mSuccessfully Saved Data\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
}
void add_tools(){
    system("cls");
    cout<<"\nHow many \033[01m\033[34mProducts\033[0m you want to add: ";
    int to_add;
    cin>>to_add;
    products_data_to_memory(size_storage);
    size_storage[2]+=to_add;
    fstream store("Products_log.db",ios::out|ios::in);
    if(store.is_open()){
        store<<"1\n";
        store<<size_storage[1]<<"\n";
        store<<size_storage[2]<<"\n";
        store<<size_storage[3]<<"\n";
        store<<employee_salary<<"\n";
        store<<owner_code<<"\n";
        store.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mProducts_log.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
    Products*data=new Products[to_add];
    ofstream store_data("Tools_data.db",ios::app);
    for(int i=0;i<to_add;i++){
        cout<<"\nEnter \033[01m\033[35mproduct "<<i+1<<"\033[0m name: ";
        cin.ignore();
        getline(cin,data[i].name);
        cout<<"Enter \033[01m\033[35mpurchase price\033[0m of product: ";
        cin>>data[i].purchase_price;
        cout<<"Enter \033[01m\033[35mSale price\033[0m: ";
        cin>>data[i].sale_price;
        if(store_data.is_open()){
            store_data<<data[i].name<<"\n";
            store_data<<data[i].purchase_price<<"\n";
            store_data<<data[i].sale_price<<"\n";
        }
    }
    store_data.close();
    cout<<"\033[1m\033[32mSuccessfully Saved Data\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
}
void add_electronics(){
    system("cls");
    cout<<"\nHow many \033[01m\033[34mProducts\033[0m you want to add: ";
    int to_add;
    cin>>to_add;
    products_data_to_memory(size_storage);
    size_storage[3]+=to_add;
    fstream store("Products_log.db",ios::out|ios::in);
    if(store.is_open()){
        store<<"1\n";
        store<<size_storage[1]<<"\n";
        store<<size_storage[2]<<"\n";
        store<<size_storage[3]<<"\n";
        store<<employee_salary<<"\n";
        store<<owner_code<<"\n";
        store.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mProducts_log.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
    Products*data=new Products[to_add];
    ofstream store_data("Electronics_data.db",ios::app);
    for(int i=0;i<to_add;i++){
        cout<<"\nEnter \033[01m\033[35mproduct "<<i+1<<"\033[0m name: ";
        cin.ignore();
        getline(cin,data[i].name);
        cout<<"Enter \033[01m\033[35mpurchase price\033[0m of product: ";
        cin>>data[i].purchase_price;
        cout<<"Enter \033[01m\033[35mSale price\033[0m: ";
        cin>>data[i].sale_price;
        if(store_data.is_open()){
            store_data<<data[i].name<<"\n";
            store_data<<data[i].purchase_price<<"\n";
            store_data<<data[i].sale_price<<"\n";
        }
    }
    store_data.close();
    cout<<"\033[1m\033[32mSuccessfully Saved Data\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
}
//-----------functions to modify the products from memory
void modify_products(){
    bool modify_products_running=true;
    do{
        bool modify_products_check=true;
        do{
            simple_Products_data(); //--------due to same function of a function instead modify it is buy
            cout<<"\nChoose your option: ";
            char modify_products_choice;
            cin>>modify_products_choice;
            modify_products_choice=tolower(modify_products_choice);
            switch(modify_products_choice){
                case 's':modify_sports();break;
                case 't':modify_tools();break;
                case 'e':modify_electronics();break;
                case 'b':modify_products_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        modify_products_check=false;
            }
        }while(modify_products_check==false);
    }while(modify_products_running);
}
void modify_sports(){
    bool modify_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Products data found. You must Add Products first\n";
            cout<<"Press Enter to go back: ";
            getch();
            modify_running=false;
        }
        else{
            if(size_storage[1]!=0){
                bool modify_check;
                do{
                    modify_check=true;
                    system("cls");
                    Display_sports();
                    Products_data_access *data=new Products_data_access[size_storage[1]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        modify_check=true;
                        modify_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[1]){
                        load_sports_data(data);
                        int i;
                        i=ia-1;
                        cout<<"\nEnter \033[01m\033[35mNew Product name\033[0m: ";
                        cin.ignore();
                        getline(cin,data[i].name);
                        cout<<"Enter \033[01m\033[35mProduct purchase price \033[0m: ";
                        cin>>data[i].purchase_price;
                        cout<<"Enter \033[01m\033[35mProduct sale price \033[0m: ";
                        cin>>data[i].sale_price;
                        ofstream store_data("Sports_data.db");
                        for(int i=0;i<size_storage[1];i++){
                            if(store_data.is_open()){
                                store_data<<data[i].name<<"\n";
                                store_data<<data[i].purchase_price<<"\n";
                                store_data<<data[i].sale_price<<"\n";
                            }
                        }
                        cout<<"\033[1m\033[32mSuccessfully Modified Data\033[0m\n";
                        cout<<"Press Enter to Go back: ";
                        getch();
                        modify_running=false;
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        modify_check=false;
                    }
                }while(modify_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Sports data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                modify_running=false;
            }
        }
    }while(modify_running);
}
void modify_tools(){
    bool modify_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Products data found. You must Add Products first\n";
            cout<<"Press Enter to go back: ";
            getch();
            modify_running=false;
        }
        else{
            if(size_storage[2]!=0){
                bool modify_check;
                do{
                    modify_check=true;
                    system("cls");
                    Display_tools();
                    Products_data_access *data=new Products_data_access[size_storage[2]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        modify_check=true;
                        modify_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[2]){
                        load_tools_data(data);
                        int i;
                        i=ia-1;
                        cout<<"\nEnter \033[01m\033[35mNew Product name\033[0m: ";
                        cin.ignore();
                        getline(cin,data[i].name);
                        cout<<"Enter \033[01m\033[35mProduct purchase price \033[0m: ";
                        cin>>data[i].purchase_price;
                        cout<<"Enter \033[01m\033[35mProduct sale price \033[0m: ";
                        cin>>data[i].sale_price;
                        ofstream store_data("Tools_data.db");
                        for(int i=0;i<size_storage[2];i++){
                            if(store_data.is_open()){
                                store_data<<data[i].name<<"\n";
                                store_data<<data[i].purchase_price<<"\n";
                                store_data<<data[i].sale_price<<"\n";
                            }
                        }
                        cout<<"\033[1m\033[32mSuccessfully Modified Data\033[0m\n";
                        cout<<"Press Enter to Go back: ";
                        getch();
                        modify_running=false;
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        modify_check=false;
                    }
                }while(modify_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Tools data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                modify_running=false;
            }
        }
    }while(modify_running);
}
void modify_electronics(){
    bool modify_running=true;
    do{
        products_data_to_memory(size_storage);
        if(size_storage[0]!=1){
            cout<<"\033[31mError!!\033[0m No Products data found. You must Add Products first\n";
            cout<<"Press Enter to go back: ";
            getch();
            modify_running=false;
        }
        else{
            if(size_storage[3]!=0){
                bool modify_check;
                do{
                    modify_check=true;
                    system("cls");
                    Display_electronics();
                    Products_data_access *data=new Products_data_access[size_storage[3]+5];
                    cout<<"\nChoose the Desired Number or Press \033[31m[B]\033[0m to go back: ";
                    char a_value;
                    cin>>a_value;
                    a_value=tolower(a_value);
                    int ia = a_value-'0';
                    if(a_value=='b'){
                        modify_check=true;
                        modify_running=false;
                    }
                    else if(ia>0&&ia<=size_storage[3]){
                        load_electronics_data(data);
                        int i;
                        i=ia-1;
                        cout<<"\nEnter \033[01m\033[35mNew Product name\033[0m: ";
                        cin.ignore();
                        getline(cin,data[i].name);
                        cout<<"Enter \033[01m\033[35mProduct purchase price \033[0m: ";
                        cin>>data[i].purchase_price;
                        cout<<"Enter \033[01m\033[35mProduct sale price \033[0m: ";
                        cin>>data[i].sale_price;
                        ofstream store_data("Electronics_data.db");
                        for(int i=0;i<size_storage[3];i++){
                            if(store_data.is_open()){
                                store_data<<data[i].name<<"\n";
                                store_data<<data[i].purchase_price<<"\n";
                                store_data<<data[i].sale_price<<"\n";
                            }
                        }
                        cout<<"\033[1m\033[32mSuccessfully Modified Data\033[0m\n";
                        cout<<"Press Enter to Go back: ";
                        getch();
                        modify_running=false;
                    }
                    else{
                        cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        modify_check=false;
                    }
                }while(modify_check==false);
            }
            else{
                cout<<"\033[31mError!!\033[0m No Electronics data found. You must Add Products first\n";
                cout<<"Press Enter to go back: ";
                getch();
                modify_running=false;
            }
        }
    }while(modify_running);
}
void display_products(){
    bool display_products_running=true;
    do{
        bool display_products_check=true;
        do{
            simple_Products_data(); //--------due to same function of a function instead display it is buy
            cout<<"\nChoose your option: ";
            char display_products_choice;
            cin>>display_products_choice;
            display_products_choice=tolower(display_products_choice);
            switch(display_products_choice){
                case 's':log_data();
                        Display_sports();
                        cout<<"\nPress Enter to go back: ";
                        getch();
                        break;
                case 't':log_data();
                        Display_tools();
                        cout<<"\nPress Enter to go back: ";
                        getch();
                        break;
                case 'e':log_data();
                        Display_electronics();
                        cout<<"\nPress Enter to go back: ";
                        getch();
                        break;
                case 'b':display_products_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        display_products_check=false;
            }
        }while(display_products_check==false);
    }while(display_products_running);
}
void total_profit(){
    products_data_to_memory(size_storage);
    order_profit*customer_order=new order_profit[size_storage[6]];
    salary*employee_salary=new salary[size_storage[7]];
    order_data_to_memory(customer_order);
    salary_data_to_memory(employee_salary);
    int sum_order=0;
    int *order_data=new int[size_storage[6]];
    for(int index=0;index<size_storage[6];index++){
        if(customer_order[index].profit!=""){
            stringstream convert_profit(customer_order[index].profit);
            convert_profit>>order_data[index];
        }
    }
    for(int index=0;index<size_storage[6]-1;index++){
        sum_order+=order_data[index];
    }
    int sum_salary=0;
    int *salary_data=new int[size_storage[7]];
    for(int index=0;index<size_storage[7];index++){
        stringstream convert_salary(employee_salary[index].salary);
        convert_salary>>salary_data[index];
    }
    for(int index=0;index<size_storage[7]-1;index++){
        sum_salary+=salary_data[index];
    }
    cout<<"Total Sales Profit: \033[31m"<<sum_order<<"\033[0m RS.\n";
    cout<<"Total Salary of Employees(Withdrawn): \033[31m"<<sum_salary<<"\033[0m RS.\n";
    cout<<"Grand Total: \033[31m"<<sum_order-sum_salary<<"\033[0m RS.\n";
    cout<<"\nPress Enter to go back: ";
    getch();
}
/*
    -----------------------------------------------------------------
   --------------------------- Account Details and it's modification Function------------------------
    -----------------------------------------------------------------
*/
void Account_Details_Owner(){
    bool account_detail_running=true;
    do{
        bool account_detail_check;
        do{
            log_data();
            account_detail_check=true;
            cout<<"\033[1m\033[32mUsername\033[0m: "<<store.user_name<<"\n";
            cout<<"\033[1m\033[32mAddress\033[0m: "<<store.user_address<<"\n";
            cout<<"\033[1m\033[32mCredit Card No.:\033[0m "<<store.user_credit_num<<"\n";
            cout<<"\033[1m\033[32mCredit Card Expiry\033[0m: "<<store.user_credit_exp<<"\n";
            cout<<"\nPress \033[36m[E]\033[0m to edit or \033[31m[B]\033[0m to go back: ";
            char account_choice;
            cin>>account_choice;
            account_choice = tolower(account_choice);
            switch(account_choice){
                case 'e':edit_owner();break;
                case 'b':account_detail_running=false;break;
                default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                        cout<<"Press Enter to try again ";
                        getch();
                        account_detail_check=false;
            }
        }while(account_detail_check==false);
    }while(account_detail_running);
}
void edit_owner(){
    system("cls");
    cout<<"Enter Username\033[31m*\033[0m: ";
    cin.ignore();
    getline(cin,store.user_name);
    do{
        cout<<"Enter Password\033[31m*\033[0m: ";
        getline(cin,store.user_pass);
        if(store.user_pass.length()<8){
            cout<<"\033[31mError!!\033[0m Password must be 8 characters long\n";
            cout<<"Press Enter to \033[31mTry again\033[0m";
            getch();
        }
    }while(store.user_pass.length()<8);
    int address_check=0;
    char choice_address;
    char choice_cd;
    //-----------there is a choice for user. he may enter address 
    do{
        address_check=0;
        cout<<"Do you want to Add Address(y/n): ";
        cin>>choice_address;
        choice_address = tolower(choice_address);
        switch(choice_address){
            case 'y':cout<<"Enter Your Address: ";
                    cin.ignore();
                    getline(cin,store.user_address);
                    break;
            case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
            default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                    cout<<"Press Enter to \033[31mTry again\033[0m";
                    getch();
                    address_check=1;
        }
    }while(address_check==1);
    int cd_check=0;
    //-----------there is a choice for user. he may enter Credit-Card 
    do{
        cout<<"Do you want to Add Credit-Card Details(y/n): ";
        cin>>choice_cd;
        choice_cd = tolower(choice_cd);
        switch(choice_cd){
            case 'y':cout<<"Enter Your Credit Card Number: ";
                    cin.ignore();
                    getline(cin,store.user_credit_num);
                    cout<<"Enter Code: ";
                    cin>>store.user_credit_code;
                    cout<<"Enter Expire Details(MM/YY): ";
                    cin.ignore();
                    getline(cin,store.user_credit_exp);
                    break;
            case 'n':cout<<"\033[1m\033[31mOk!!\033[0m\n";break;
            default:cout<<"\033[31mError!!\033[0m You entered invalid choice\n";
                    cout<<"Press Enter to \033[31mTry again\033[0m";
                    getch();
                    cd_check=1;
        }
    }while(cd_check==1);
    fstream owner_data("Owner_ID.db",ios::out);
    owner_data<<store.user_name<<"\n"<<store.user_pass<<"\n"<<store.user_address<<"\n"<<store.user_credit_num<<"\n"<<store.user_credit_code<<"\n"<<store.user_credit_exp<<"\n"<<"1";
    owner_data.close();
    cout<<"\033[1m\033[32mSuccessfully Created Account\033[0m\n";
    cout<<"Press Enter to Go back: ";
    getch();
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
void order_data_to_memory(order_profit memory[]){
    products_data_to_memory(size_storage);
    ifstream order_data;
    order_data.open("Order_placed.log");
    if(order_data.is_open()){
        int index=0;
        while(!order_data.eof()){
            getline(order_data,memory[index].name);
            getline(order_data,memory[index].cd_num);
            getline(order_data,memory[index].profit);
            getline(order_data,memory[index].source);
            index++;
        }
        order_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mOrder_placed.log\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";\
    }
}
void salary_data_to_memory(salary memory[]){
    products_data_to_memory(size_storage);
    ifstream salary_data("salary.log");
    if(salary_data.is_open()){
        int index=0;
        while(!salary_data.eof()){
            getline(salary_data,memory[index].name);
            getline(salary_data,memory[index].cd_num);
            getline(salary_data,memory[index].address);
            getline(salary_data,memory[index].salary);
            getline(salary_data,memory[index].timeing);
            index++;
        }
        salary_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31msalary.log\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";\
    }
}
//-----------log file loading
void products_data_to_memory(int memory[]){
    ifstream products_quantity;
    products_quantity.open("Products_log.db");
    if(products_quantity.is_open()){
        while(!products_quantity.eof()){
            products_quantity>>memory[0];
            products_quantity>>memory[1];
            products_quantity>>memory[2];
            products_quantity>>memory[3];
            products_quantity>>memory[4];
            products_quantity>>memory[5];
            products_quantity>>memory[6];
            products_quantity>>memory[7];
        }
        products_quantity.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mProducts_log.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void accounts_data_to_memory(int memory[]){
    ifstream products_quantity;
    products_quantity.open("Accounts_log.db");
    if(products_quantity.is_open()){
        while(!products_quantity.eof()){
            products_quantity>>memory[0];
            products_quantity>>memory[1];
            products_quantity>>memory[2];
            products_quantity>>memory[3];
        }
        products_quantity.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mAccounts_log.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void load_sports_data(Products_data_access memory[]){
    ifstream data_load;
    data_load.open("Sports_data.db",ios::app);
    if(data_load.is_open()){
        int i=0;
        while(!data_load.eof()){
            getline(data_load,memory[i].name);
            getline(data_load,memory[i].purchase_price);
            getline(data_load,memory[i].sale_price);
            i++;
        }
        data_load.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mSports_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void load_tools_data(Products_data_access memory[]){
    ifstream data_load;
    data_load.open("Tools_data.db");
    if(data_load.is_open()){
        int i=0;
        while(!data_load.eof()){
            getline(data_load,memory[i].name);
            getline(data_load,memory[i].purchase_price);
            getline(data_load,memory[i].sale_price);
            i++;
        }
        data_load.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mTools_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void load_electronics_data(Products_data_access memory[]){
    ifstream data_load;
    data_load.open("Electronics_data.db");
    if(data_load.is_open()){
        int i=0;
        while(!data_load.eof()){
            getline(data_load,memory[i].name);
            getline(data_load,memory[i].purchase_price);
            getline(data_load,memory[i].sale_price);
            i++;
        }
        data_load.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mElectronics_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void attendance_data_to_memory(attendance_data memory[]){
    ifstream attendance("attendance.dll");
    if(attendance.is_open()){
        int index=0;
        while(!attendance.eof()){
            getline(attendance,memory[index].attendance);
            getline(attendance,memory[index].current_time);
            getline(attendance,memory[index].target_time);
            getline(attendance,memory[index].check);
            index++;
        }
        attendance.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mattendance.dll\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
/*
    ---------------------------------------
-----------------Display Functions ----------
    ---------------------------------------
*/
void Display_sports(){
    ifstream display_data("Sports_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(55)<<"\033[01m\033[32mSports Products\033[0m\n";
        cout<<"\033[01m\033[33m---------------------------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Purchase Price"<<setw(25)<<"Sale Price\n\033[0m";
        for(int i=0;i<size_storage[1];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<setw(25)<<temp_pp<<setw(25)<<temp_sp<<right<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mSports_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void Display_tools(){
    ifstream display_data("Tools_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(55)<<"\033[01m\033[32mTools Products\033[0m\n";
        cout<<"\033[01m\033[33m---------------------------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Purchase Price"<<setw(25)<<"Sale Price\n\033[0m";
        for(int i=0;i<size_storage[2];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<setw(25)<<temp_pp<<setw(25)<<temp_sp<<right<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mTools_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void Display_electronics(){
    ifstream display_data("Electronics_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(55)<<"\033[01m\033[32mElectronics Products\033[0m\n";
        cout<<"\033[01m\033[33m---------------------------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Purchase Price"<<setw(25)<<"Sale Price\n\033[0m";
        for(int i=0;i<size_storage[3];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<setw(25)<<temp_pp<<setw(25)<<temp_sp<<right<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mElectronics_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void Display_customer_sports(){
    ifstream display_data("Sports_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(50)<<"\033[01m\033[32mSports Products\033[0m\n";
        cout<<"\033[01m\033[33m-------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Price"<<setw(25)<<"\033[0m\n";
        for(int i=0;i<size_storage[1];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<"\t "<<setw(25)<<temp_sp<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mSports_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void Display_customer_tools(){
    ifstream display_data("Tools_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(50)<<"\033[01m\033[32mTools Products\033[0m\n";
        cout<<"\033[01m\033[33m-------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Price"<<setw(25)<<"\033[0m\n";
        for(int i=0;i<size_storage[2];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<"\t "<<setw(25)<<temp_sp<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mTools_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
void Display_customer_electronics(){
    ifstream display_data("Electronics_data.db");
    if(display_data.is_open()){
        string temp_name;
        string temp_pp;
        string temp_sp;
        products_data_to_memory(size_storage);
        cout<<setw(50)<<"\033[01m\033[32mElectronics Products\033[0m\n";
        cout<<"\033[01m\033[33m-------------------------------------------------------\033[0m\n";
        cout<<"\033[01m\033[36mNo.\t\tName"<<setw(25)<<"\t\t Price"<<setw(25)<<"\033[0m\n";
        for(int i=0;i<size_storage[3];i++){
            getline(display_data,temp_name);
            getline(display_data,temp_pp);
            getline(display_data,temp_sp);
            cout<<i+1<<"\t\t"<<setw(25)<<left<<temp_name<<"\t "<<setw(25)<<temp_sp<<"\n";
        }
        display_data.close();
    }
    else{
        cout<<"\033[31mError!!\033[0m Unable to Load the \033[31mElectronics_data.db\033[0m \n";
        cout<<"Press Enter to \033[36mTry again\033[0m";
        getch();
        cout<<"\n";
    }
}
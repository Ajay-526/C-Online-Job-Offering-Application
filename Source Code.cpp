#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>
char name[10]="manager";
char pass[10]="123";
using namespace std;
class admin{
	public:
		int job_id;
		char job_name[30];
		char designation[45];
		char place[30];
		int salary;
		char date_of_exam[35];
		char date_of_interview[35];
	
	public:
		void add_jobs();
		void display_jobs();
		void total_jobs();
		void edit_jobs();
		int check_job(int);
		int modify_job(int);
		int delete_job(int);
		int valid_user_job(int);
};

class users:public admin{
	char user_name[30];
	char address[35];
	char phone[10];
	int job_id_choosen;
	char job_name_choosen[35];
	char designation_choosen[35];
	char place_choosen[35];
	int salary_choosen;
	char date_picked_for_exam[35];
	char date_picked_for_interview[35];
	public:
		void choose_job();
		void validate_job(int);
		void display_users();
		void m();
};

class manage: public admin{
	public:
		void menu();
};
class regis: public admin{	
public:
	int id;
	int pass;
public:	
	void menu();
	void reg();
	void login();
	int check_reg(int,int);
	void all_registrations();
};
void regis::menu()
{
	int ch;
	do
	{
		cout<<"\nHello!!";
		cout<<"\n1.User Registration";
		cout<<"\n2.User Login";
		cout<<"\n4.Exit";
		cout<<"\nEnter choice";
		cin>>ch;
		switch(ch)
		{
			case 1: reg();
					break;
			case 2: login();
					break;
			case 3: exit(0);
					break;
			default: cout<<"Sorry! Choose a right one";
						break;
		}
	}while(1);
}
void regis::reg()
{
	int i,ps,flag=0;
	ofstream reg("registrations.dat",ios::app);
	cout<<"Enter id: in numbers:";
	cin>>i;
	cout<<"Choose Password in numbers:";
	cin>>ps;
	flag=check_reg(i,ps);
	if(flag)
	{
		cout<<"Sorry!! Registration details are already taken";
	}
	else
	{
		id=i;
		pass=ps;
		reg.write((char*)this,sizeof(*this));
		cout<<"-------------------Registration Successfull--------------------------";
	}
	reg.close();
}
int regis::check_reg(int i,int ps)
{
	int flag=0;
	ifstream check("registrations.dat",ios::in);
	check.seekg(0);
	while(!check.eof() && check.read((char*)this,sizeof(*this)))
	{
		//check.read((char*)this,sizeof(*this));
		if(i==id || ps==pass)
		{
			flag=1;
			break;
		}
	}
	check.close();
	return flag;
}
void regis::login()
{
	users u;
	int i,ps,flag=0;
	cout<<"Enter id: in numbers:";
	cin>>i;
	cout<<"Choose Password in numbers:";
	cin>>ps;
	flag=check_reg(i,ps);
	ifstream check("registrations.dat",ios::in);
	check.seekg(0);
	while(!check.eof() && check.read((char*)this,sizeof(*this)))
	{
		//check.read((char*)this,sizeof(*this));
		if(i==id && ps==pass)
		{
			cout<<"\n--------------Login Successfull-----------------";
	        u.m();
			break;
		}
		else
		{
			cout<<"Invalid Entries:";
		}
	}
	check.close();
}
void users::m()
{
	int ch;
	do
	{
		cout<<"\n1.Choose a Job:";
		cout<<"\n2.Display all the users:";
		cout<<"\n3.Go-back to the menu";
		cout<<"\n4.Exit out";
		cout<<"\nEnter the choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: choose_job();
					break;
			case 2: display_users();
					break;
			case 3: return;
					break;
			case 4: exit(0);
					break;
			default:cout<<"\nChoose the right one"; 
		}
	}while(1);
}
void users::choose_job()
{
	int ct=0,ch,p;
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		total_jobs();
		cout<<"\nEnter the job-id you like:";
		cin>>ch;
		cout<<"****"<<ch;
		validate_job(ch);
	}
	else
	{
		total_jobs();
		cout<<"\nEnter the job-id you like:";
		cin>>ch;
		cout<<"****"<<ch;
		validate_job(ch);
	}
}
int admin::valid_user_job(int ch)
{
	int flag=0;
	ifstream fin("site.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(*this));
		if(ch==job_id)
		{
			flag=1;
			break;
		}
	}
	fin.close();
	return flag;
}
void users::validate_job(int ch)
{
	char c;
	int p;
	ofstream enter("users.dat",ios::app);
	ofstream enter1("users1.dat",ios::app);
	
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		int flag=valid_user_job(ch);
		if(flag)
		{
			cout<<"\nyou have choosen :";
			display_jobs();
			cout<<"\nDo you want to contiue:(y/n)";
			cin>>c;
			if(c=='y')
			{
				cout<<"Enter Name:";
				cin>>user_name;
				cin.sync();
				cout<<"Address:";
				cin>>address;
				cout<<"Phone Number:";
				cin>>phone;
				job_id_choosen=ch;
				strcpy(job_name_choosen,job_name);
				strcpy(designation_choosen,designation);
				strcpy(place_choosen,place);
				salary_choosen=salary;
				strcpy(date_picked_for_exam,date_of_exam);
				strcpy(date_picked_for_interview,date_of_interview);
				enter.write((char*)this,sizeof(*this));
			}
		}
		else
		{
			cout<<"\nSoryy!! Job-id not found or not created.";
			cout<<"\nPress any key...";
			getch();
		}
	}
	else
	{
		int flag=valid_user_job(ch);
		if(flag)
		{
			cout<<"\nyou have choosen :";
			display_jobs();
			cout<<"\nDo you want to contiue:(y/n)";
			cin>>c;
			if(c=='y')
			{
				cout<<"Enter Name:";
				cin>>user_name;
				cin.sync();
				cout<<"Address:";
				cin>>address;
				cout<<"Phone Number:";
				cin>>phone;
				job_id_choosen=ch;
				strcpy(job_name_choosen,job_name);
				strcpy(designation_choosen,designation);
				strcpy(place_choosen,place);
				salary_choosen=salary;
				strcpy(date_picked_for_exam,date_of_exam);
				strcpy(date_picked_for_interview,date_of_interview);
				enter1.write((char*)this,sizeof(*this));
			}
		}
		else
		{
			cout<<"\nSoryy!! Job-id not found or not created.";
			cout<<"\nPress any key...";
			getch();
		}
	}
	enter.close();
	enter1.close();
}
void users::display_users()
{
	int ct=0,p;
	ifstream in("users.dat",ios::in);
	ifstream in1("users1.dat",ios::in);
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		while(!in.eof())
		{
			in.read((char*)this,sizeof(*this));
			cout<<"\n----------------------------------------------------------";
			cout<<"\nName: "<<user_name;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone: "<<phone;
			cout<<"\nJob id choosen: "<<job_id_choosen;
			cout<<"\nJob Name Choose: "<<job_name_choosen;
			cout<<"\nDesignation choosen: "<<designation_choosen;
			cout<<"\nPlace choosen: "<<place_choosen;
			cout<<"\nDate choosen for exam : "<<date_picked_for_exam;
			cout<<"\nDate choosen for interview : "<<date_picked_for_interview;
			ct++;
		}
		cout<<"\n----------------------------------------------------------";
		cout<<"\nThe total no.of users are: "<<ct;
	}
	else
	{
		while(!in1.eof())
		{
			in1.read((char*)this,sizeof(*this));
			cout<<"\n----------------------------------------------------------";
			cout<<"\nName: "<<user_name;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone: "<<phone;
			cout<<"\nJob id choosen: "<<job_id_choosen;
			cout<<"\nJob Name Choose: "<<job_name_choosen;
			cout<<"\nDesignation choosen: "<<designation_choosen;
			cout<<"\nPlace choosen: "<<place_choosen;
			cout<<"\nDate choosen for exam : "<<date_picked_for_exam;
			cout<<"\nDate choosen for interview : "<<date_picked_for_interview;
			ct++;
		}
		cout<<"\n----------------------------------------------------------";
		cout<<"\nThe total no.of users are: "<<ct;
	}
	in.close();
	in1.close();
}
void manage::menu()
{
	int choice;
	while(1)
	{
		cout<<"\n1. Add Jobs:";
		cout<<"\n2. Display Jobs";
		cout<<"\n3. Total View of Jobs";
		cout<<"\n4. Edit the Jobs";
		cout<<"\n5. Go back to the menu";
		cout<<"\n6. Exit from the site";
		cout<<"\nEnter the Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: add_jobs();
					break;
			case 2: display_jobs();
					break;
			case 3: total_jobs();
					break;
			case 4: edit_jobs();
					break;
			case 5: return;
					break;
			case 6: exit(0);
					break;
			default: cout<<"\nInavalid Choice";
					cout<<"Presss any key--";
					break;
		}
	}
}
void admin::edit_jobs()
{
	int choice,r,p;
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		cout<<"\n EDIT MENU";
		cout<<"\n ---------";
		cout<<"\n\n 1.Modify Job Records";
		cout<<"\n 2.Delete Job Records";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		cout<<"\n Enter Job Id: " ;
		cin>>r;
		switch(choice)
		{
			case 1:	modify_job(r);
					break;
			case 2:	delete_job(r);
					break;
			default: cout<<"\n Wrong Choice.....!!";
		}
		cout<<"\n Press any key to continue....!!!";
		getch();		
	}
	else
	{
		cout<<"\n EDIT MENU";
		cout<<"\n ---------";
		cout<<"\n\n 1.Modify Job Records";
		cout<<"\n 2.Delete Job Records";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		cout<<"\n Enter Job Id: " ;
		cin>>r;
		switch(choice)
		{
			case 1:	modify_job(r);
					break;
			case 2:	delete_job(r);
					break;
			default: cout<<"\n Wrong Choice.....!!";
		}
		cout<<"\n Press any key to continue....!!!";
		getch();		
	}
}

int admin::modify_job(int r)
{
	long pos,flag=0,p;
	//fstream file("site.dat",ios::in|ios::out);
	fstream file("premium.dat",ios::in|ios::out);
	fstream file1("non_premium.dat",ios::in|ios::out);
	
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		while(!file.eof())
		{
			pos=file.tellg();
			file.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				cout<<"\n Enter New Details";
				cout<<"\n -----------------";
				cout<<"\n : ";
				cout<<"Job-Name:";
			    cin>>job_name;
			    cin.sync();
			    cout<<"Designation:";
			    gets(designation);
			    cin.sync();
			    cout<<"place:";
			    cin>>place;
			    cout<<"Salary:";
			    cin>>salary;
			    cout<<"Date of Examination:";
			    cin>>date_of_exam;
			    cout<<"Date of Interview:";
			    cin>>date_of_interview;
			    
			    file.seekg(pos);
				file.write((char*)this,sizeof(*this));
				cout<<"\n Record is modified....!!";
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<"\n Sorry Job-Id not found or created...!!";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			pos=file.tellg();
			file1.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				cout<<"\n Enter New Details";
				cout<<"\n -----------------";
				cout<<"\n : ";
				cout<<"Job-Name:";
			    cin>>job_name;
			    cin.sync();
			    cout<<"Designation:";
			    gets(designation);
			    cin.sync();
			    cout<<"place:";
			    cin>>place;
			    cout<<"Salary:";
			    cin>>salary;
			    cout<<"Date of Examination:";
			    cin>>date_of_exam;
			    cout<<"Date of Interview:";
			    cin>>date_of_interview;
			    
			    file1.seekg(pos);
				file1.write((char*)this,sizeof(*this));
				cout<<"\n Record is modified....!!";
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<"\n Sorry Job-Id not found or created...!!";
		file1.close();
	}
}

int admin::delete_job(int r)
{
	int flag=0,p;
	char ch;
	int ct=0;
	ifstream fin("premium.dat",ios::in);
	ifstream fin1("non_premium.dat",ios::in);
	
	ofstream fout("temp.dat",ios::out| ios::binary);
	ofstream fout1("temp1.dat",ios::out| ios::binary);
	
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				cout<<"\nJob-Id: "<<job_id;
				cout<<"\nJob-Name: "<<job_name;
				cout<<"\nDesignation: "<<designation;
				cout<<"\nPlace: "<<place;
				cout<<"\nSalary: "<<salary;
				cout<<"\nDate of Examination: "<<date_of_exam;
				cout<<"\nDate of Interview: "<<date_of_interview;
				
				cout<<"\n\n Do you want to delete this record(y/n): ";
			    cin>>ch;
			    if(ch=='n')
			  		fout.write((char*)this,sizeof(*this));
				flag=1;
			}
			else
				fout.write((char*)this,sizeof(*this));
		}
		
		fin.close();
		fout.close();
		if(flag==0)
			cout<<"\n Sorry Job-Id not found or Created...!!";
		else
		{
			remove("premium.dat");
			rename("temp.dat","premium.dat");
		}
	}
	else
	{
		while(!fin1.eof())
		{
			fin1.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				cout<<"\nJob-Id: "<<job_id;
				cout<<"\nJob-Name: "<<job_name;
				cout<<"\nDesignation: "<<designation;
				cout<<"\nPlace: "<<place;
				cout<<"\nSalary: "<<salary;
				cout<<"\nDate of Examination: "<<date_of_exam;
				cout<<"\nDate of Interview: "<<date_of_interview;
				
				cout<<"\n\n Do you want to delete this record(y/n): ";
			    cin>>ch;
			    if(ch=='n')
			  		fout1.write((char*)this,sizeof(*this));
				flag=1;
			}
			else
				fout1.write((char*)this,sizeof(*this));
		}
		
		fin1.close();
		fout1.close();
		if(flag==0)
			cout<<"\n Sorry Job-Id not found or Created...!!";
		else
		{
			remove("non_premium.dat");
			rename("temp1.dat","non_premium.dat");
		}
	}
}

void admin::add_jobs()
{
	int r,flag,p;
    char ch;
    int c;
    ofstream fout("premium.dat",ios::app);
    ofstream fout1("non_premium.dat",ios::app);
    cout<<"\nEnter the Job Details:";
    cout<<"Enter Job Id:";
    cin>>r;
    flag=check_job(r);
    if(flag)
    {
    	cout<<"\nSorry! This Id has been taken:";
	}
    else
    {
    	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
    	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
    	cin>>p;
    	if(p==1)
    	{
    		job_id=r;
	    	cout<<"Job-Name:";
		    cin>>job_name;
		    cin.sync();
		    cout<<"Designation:";
		    gets(designation);
		    cin.sync();
		    cout<<"place:";
		    cin>>place;
		    cout<<"Salary:";
		    cin>>salary;
		    cout<<"Date of Examination:";
		    cin>>date_of_exam;
		    cout<<"Date of Interview:";
		    cin>>date_of_interview;
		    fout.write((char*)this,sizeof(*this));
			fout.close();
		}
		else
		{
			job_id=r;
	    	cout<<"Job-Name:";
		    cin>>job_name;
		    cin.sync();
		    cout<<"Designation:";
		    gets(designation);
		    cin.sync();
		    cout<<"place:";
		    cin>>place;
		    cout<<"Salary:";
		    cin>>salary;
		    cout<<"Date of Examination:";
		    cin>>date_of_exam;
		    cout<<"Date of Interview:";
		    cin>>date_of_interview;
		    fout1.write((char*)this,sizeof(*this));
			fout1.close();
		}
	}
}

int admin::check_job(int r)
{
	int flag=0,p;
	
	ifstream fin("premium.dat",ios::in);
	ifstream fin1("non_premium.dat",ios::in);
	cout<<"\nFor Comfirmantion Please:";
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				flag=1;
				break;
			}
		}
		fin.close();
		return(flag);
	}
	else
	{
		while(!fin1.eof())
		{
			fin1.read((char*)this,sizeof(*this));
			if(job_id==r)
			{
				flag=1;
				break;
			}
		}
		fin1.close();
		return(flag);
	}
}

void admin::display_jobs()
{
	int j,ct=0,p;
	int flag=0;
	ifstream fin("premium.dat",ios::in);
	ifstream fin1("non_premium.dat",ios::in);
	
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		cout<<"\nEnter the job id:";
		cin>>j;
		while(!fin.eof() && fin.read((char*)this,sizeof(*this)))
		{
			//fin.read((char*)this,sizeof(*this));
			if(job_id==j)
			{
				ct=1;
				break;
			}
		}
		if(ct==1)
		{
			cout<<"\nJob-Name: "<<job_name;
			cout<<"\nDesignation: "<<designation;
			cout<<"\nPlace: "<<place;
			cout<<"\nSalary: "<<salary;
			cout<<"\nDate of Examination: "<<date_of_exam;
			cout<<"\nDate of Interview: "<<date_of_interview;
			flag=1;
		}
		if(flag=0)
			cout<<"\nSorry!! Job Id not found;";
		cout<<"\n\n Press any key to continue....!!";
		getch();
		fin.close();
	}
	else
	{
		cout<<"\nEnter the job id:";
		cin>>j;
		while(!fin1.eof() && fin1.read((char*)this,sizeof(*this)))
		{
			//fin1.read((char*)this,sizeof(*this));
			if(job_id==j)
			{
				ct=1;
				break;
			}
		}
		if(ct==1)
		{
			cout<<"\nJob-Name: "<<job_name;
			cout<<"\nDesignation: "<<designation;
			cout<<"\nPlace: "<<place;
			cout<<"\nSalary: "<<salary;
			cout<<"\nDate of Examination: "<<date_of_exam;
			cout<<"\nDate of Interview: "<<date_of_interview;
			flag=1;
		}
		if(flag=0)
			cout<<"\nSorry!! Job Id not found;";
		cout<<"\n\n Press any key to continue....!!";
		getch();
		fin1.close();
	}
}

void admin::total_jobs()
{
	int ct=0,p;
	ifstream fin("premium.dat",ios::in);
	ifstream fin1("non_premium.dat",ios::in);
	
	cout<<"\nSay whether it is Premium jobs or non-premium jobs";
	cout<<"\nsay 1 for-premium\nsay 2 for-non premium";
	cin>>p;
	if(p==1)
	{
		cout<<"\n";
		cout<<"\nJob-ID \t Jobe-Name: \t Designation \t Salary \t Place\n";
		while(!fin.eof() && fin.read((char*)this,sizeof(*this)))
		{
			//fin.read((char*)this,sizeof(*this));
			cout<<job_id<<" \t "<<job_name<<" \t "<<designation<<" \t "<<salary<<" \t "<<place<<"\n";
			ct++;
		}
		cout<<"\nThe Total no. of jobs availaible are : "<<ct;
		fin.close();
	}
	else
	{
		cout<<"\n";
		cout<<"\nJob-ID \t Jobe-Name: \t Designation \t Salary \t Place\n";
		while(!fin1.eof() && fin1.read((char*)this,sizeof(*this)))
		{
			//fin1.read((char*)this,sizeof(*this));
			cout<<job_id<<" \t "<<job_name<<" \t "<<designation<<" \t "<<salary<<" \t "<<place<<"\n";
			ct++;
		}
		cout<<"\nThe Total no. of jobs availaible are : "<<ct;
		fin1.close();
	}
}


main()
{
	cout<<"*************************WELCOME This is Ajay Kumar*************************";
	manage m;
	regis r;
	char n[10];
	char ps[10];
	int i;
	while(1)
	{
		cout<<"Are you a USER or ADMIN? (1/0) enter 10 to exit()";
		cin>>i;
		if(i==1)
		{
			r.menu();
		}
		else
		{
			cout<<"enter user name:";
			cin>>n;
			cout<<"Password:";
			cin>>ps;
			if(strcmp(name,n)==0 && strcmp(pass,ps)==0)
			{
				cout<<"---------------------WELCOME ADMIN----------------------";
				m.menu();
			}
			else
			cout<<"Sorry!!";
		}
		if(i==10)
		break;
	}
	exit(0);
}

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<dos.h>
#define go(r,c) gotoxy(c,r)

char ans;
FILE *ft;
FILE *ft1;
FILE *ek;//file pointer
FILE *fp;//file pointer
FILE *ek1;//file pointer
struct patient//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};
struct doctor//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Speciality[20];
	char Experience[20];
};
struct bed//list of global variable
{
	char addbed[20];
	char bedavail[20];
	char bedinfo[15];
};
struct bed B;
struct doctor d;
struct patient p,temp_c;
char ans=0;
int ok;
int b, valid=0;

void message(char *message);
void colorbox(int size);

void splashScreen();
/* login screen */
void screen1();
/* main menu */
void screen11();
/* sub menu patient management*/
void screen111();
/* sub menu -doctor management */
void screen112();
/* sub menu -bed management */
void screen113();
/* sub menu - change password */
void screen114();
/* data entry screen of patient */
void screen1111();
/* data display screen of patient*/
void screen1112();
/* data search screen of patient*/
void screen1113();
/* data Edit screen of patient*/
void screen1114();
/* data Delete screen of patient*/
void screen1115();
/* data Entry screen of Doctor*/
void screen1121();
/* data View screen of Doctor*/
void screen1122();
/* data Edit screen of Doctor*/
void screen1123();
/* data Delete screen of patient*/
void screen1124();
/* data entry screen of bed*/
void screen1131();
/* data view screen of bed*/
void screen1132();
/* data edit screen of bed*/
void screen1133();

void Title()//function for title screen
{
	printf("\n-------------------------------------------------------------------------");
	printf("\n                             AIIMS HOSPITAL         ");
	printf("\n-------------------------------------------------------------------------");
}

void main(){
	splashScreen();
}
void splashScreen(){
	clrscr();
	go(8,24);textcolor(YELLOW);cprintf("Hospital Management System");textcolor(WHITE);
	go(12,30);
	textcolor(WHITE);
	cprintf("Version 1.0");
	go(15,30);
	textcolor(YELLOW);
	cprintf("Developed by");
	go(17,27);
	textcolor(WHITE);
	cprintf("Rahul Tiwari,Ritesh");
	delay(5000);
	screen1();
}
void message(char *message){
	int col=40-strlen(message)/2;
	gotoxy(col,24);
	printf(message);clreol();
}
void colorbox(int size){
	int i;
	textbackground(BLUE);
	for(i=1;i<=size;i++)
	   cprintf(" ");
	textbackground(BLACK);
}

void screen1(){
	char userid[51],password[51],ch;
	int i=0;
	clrscr();
	go(5,24);textcolor(YELLOW);cprintf("Hospital Management System");textcolor(WHITE);
	go(7,30);printf("Admin Login");
	go(10,20);printf("User ID");
	go(12,20);printf("Password");
	go(10,35);colorbox(15);
	go(12,35);colorbox(15);
	go(24,30);colorbox(40);
	message("Enter valid username");
	go(10,35);gets(userid);
	go(24,30);colorbox(40);
	message("Enter password");clreol();
	go(12,35);
	fflush(stdin);
	while(i<50){
	     ch=getch();
	     if(ch==13){ //Enter key
		break;
	     }
	     if(ch==8){ //Backspace
		int n;
		if(i>0)
		{	i--;
			go(12,35);clreol(); //clear till end of line
			go(12,35); for(n=0;n<i;n++) putchar('*');
		}
	     }
	     else{
		password[i]=ch;
		putchar('*');
		i++;
	     }
	}
	password[i]='\0';
	if(strcmp(userid,"admin")==0  && strcmp(password,"123456")==0)
	{
		go(20,20);printf("Success... Press any key to continue");
		getch();
		screen11();
	}
	else{
		go(14,20);printf("Invalid user id or password");
		getch();
	}
}
void screen11(){
	char choice;
	clrscr();
	for(;;){
		clrscr();
		textcolor(YELLOW);textbackground(GREEN);
		go(5,20); cprintf(" Main Menu : Hospital Management System");
		textcolor(RED);textbackground(BLACK);
		go(8,30); cprintf("P");printf("atient Management");
		go(10,30); cprintf("D");printf("octor Management");
		go(12,30); cprintf("B");printf("ed Management");
		go(14,30); cprintf("C");printf("hange Password");
		go(16,30); cprintf("Q");printf("uit Application");
		go(22,30); printf("Your choice can be from p,d,b,c,q");
		go(20,45);clreol();
		go(20,30); printf("Enter choice : ");
		fflush(stdin);
		textcolor(WHITE);
		choice=tolower(getchar());
		switch(choice){
			case 'p': screen111(); break;
			case 'd': screen112();break;
			case 'b': screen113();break;
			case 'c': screen114();break;
			case 'q': exit(0);
			default:
			go(22,30);
			printf("Sorry! Invalid Choice");
			system("pause");
		}
	}

}
void screen111(){
	char choice;
	clrscr();
	for(;;){
		clrscr();
		textcolor(YELLOW);textbackground(RED);
		go(5,24); cprintf(" Sub Menu : Patient Management");
		textcolor(RED);textbackground(BLACK);
		go(8,30); cprintf("A");printf("dd Patient Record");
		go(10,30); cprintf("V");printf("iew Patient Record");
		go(12,30); cprintf("S");printf("earch Patient Record");
		go(14,30); cprintf("E");printf("dit Patient Record");
		go(16,30); cprintf("D");printf("elete Patient Record");
		go(18,30); cprintf("M");printf("ain Menu");
		go(20,30); printf("Your choice can be from a,v,s,e,d,m");
		go(20,45);clreol();
		go(20,30); printf("Enter choice : ");
		fflush(stdin);
		textcolor(WHITE);
		choice=tolower(getchar());
		switch(choice){
			case 'a': screen1111(); break;
			case 'v': screen1112(); break;
			case 's': screen1113();break;
			case 'e': screen1114();break;
			case 'd': screen1115();break;
			case 'm': return;
			default:
			go(22,30);
			printf("Sorry! Invalid Choice");
			system("pause");
		}
	}


}
/* Doctor Menu*/
void screen112(){
char choice;
	clrscr();
	for(;;){
		clrscr();
		textcolor(YELLOW);textbackground(RED);
		go(5,24); cprintf(" Sub Menu : Doctor Management");
		textcolor(RED);textbackground(BLACK);
		go(8,30); cprintf("A");printf("dd Doctor Record");
		go(10,30); cprintf("V");printf("iew Doctor Record");
		go(12,30); cprintf("E");printf("dit Doctor Record");
		go(14,30); cprintf("D");printf("elete Doctor Record");
		go(16,30); cprintf("M");printf("ain Menu");
		go(22,30); printf("Your choice can be from a,v,e,d,m");
		go(20,45);clreol();
		go(20,30); printf("Enter choice : ");
		fflush(stdin);
		textcolor(WHITE);
		choice=tolower(getchar());
		switch(choice){
			case 'a': screen1121(); break;
			case 'v': screen1122();	break;
			case 'e': screen1123();break;
			case 'd': screen1124();break;
			case 'm': return;
			default:
			go(22,30);
			printf("Sorry! Invalid Choice");
			system("pause");
		}
	}


}
/* Bed submenu*/
void screen113(){
char choice;
	clrscr();
	for(;;){
		clrscr();
		textcolor(YELLOW);textbackground(RED);
		go(5,24); cprintf(" Sub Menu : Bed Management");
		textcolor(RED);textbackground(BLACK);
		go(8,30); cprintf("A");printf("dd New Bed");
		go(10,30); cprintf("S");printf("ee Available Bed");
		go(12,30); cprintf("E");printf("dit Bed information");
		go(16,30); cprintf("M");printf("ain Menu");
		go(22,30); printf("Your choice can be from s,a,e,m");
		go(20,45);clreol();
		go(20,30); printf("Enter choice : ");
		fflush(stdin);
		textcolor(WHITE);
		choice=tolower(getchar());
		switch(choice){
			case 'a': screen1131();break;
			case 's': screen1132();break;
			case 'e': screen1133();break;
			case 'm': return;
			default:
			go(22,30);
			printf("Sorry! Invalid Choice");
			system("pause");
		}
	}


}
/* change password menu*/
void screen114(){

}

/*Patient SubMenu*/
void screen1111(){

	system("cls");
	Title();// call Title function
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}

	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
	if(!ok)
	    {
		printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);
/* **************************************** Address ******************************************************************* */
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
		goto C;
	}

}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Contact_no);b++)
		{
			if (!isalpha(p.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
	}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
/* ********************************************************* Problem *********************************************** */
    E:
    printf("\n\t\t\tProblem: ");
    scanf("%s",p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>15||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
/* ********************************************** Prescribed Doctor **************************************** */
	F:
    printf("\n\t\t\tPrescribed Doctor:");
    fflush(stdin);gets(p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Doctor);b++)
		{
			if (isalpha(p.Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
			goto F;
		}
	}

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
	screen1111();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
	getch();
	return;
	}
    else
    {
	printf("\n\t\tInvalid Input\n");
	goto sd;
    }
}
/* view patient menu*/
void screen1112(){
{
	int row;
	system("cls");
	Title();
	ek=fopen("Record2.dat","r");
	printf("\n\n");
	printf("\n\n\t\t!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(11,15);
		printf("Gender");
		gotoxy(18,15);
		printf("Age");
		gotoxy(22,15);
		printf("Address");
		gotoxy(30,15);
		printf("Contact No");
		gotoxy(41,15);
		printf("Email");
		gotoxy(54,15);
		printf("Problem");
		gotoxy(64,15);
		printf("Prescribed Doctor");
		printf("================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name,
					&p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(11,row);
			printf("%c",p.Gender);
			gotoxy(18,row);
			printf("%i",p.age);
			gotoxy(22,row);
			printf("%s",p.Address);
			gotoxy(30,row);
			printf("%s",p.Contact_no);
			gotoxy(41,row);
			printf("%s",p.Email);
			gotoxy(54,row);
			printf("%s",p.Problem);
			gotoxy(64,row);
			printf("%s",p.Doctor);
			row++;
		}
		fclose(ek);
		getch();
		return;
}
}
void screen1113(){
char name[20];
	system("cls");
	Title();// call Title function
	ek=fopen("Record2.dat","r");
	printf("\n\n");
	printf("\n\n\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,10);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(11,15);
			printf("Gender");
			gotoxy(18,15);
			printf("Age");
			gotoxy(22,15);
			printf("Address");
			gotoxy(30,15);
			printf("Contact No.");
			gotoxy(41,15);
			printf("Email");
			gotoxy(54,15);
			printf("Problem");
			gotoxy(64,15);
			printf("Prescribed Doctor");
			printf("================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(11,18);
			printf("%c",p.Gender);
			gotoxy(18,18);
			printf("%i",p.age);
			gotoxy(22,18);
			printf("%s",p.Address);
			gotoxy(30,18);
			printf("%s",p.Contact_no);
			gotoxy(41,18);
			printf("%s",p.Email);
			gotoxy(54,18);
			printf("%s",p.Problem);
			gotoxy(64,18);
			printf("%s",p.Doctor);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.First_Name,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
	screen1113();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
	getch();
		return;
    }
	else
    {
	printf("\n\tInvalid Input.\n");
	goto L;
    }
}
void screen1114(){
	FILE *ek, *ft;
	int i,b, valid=0;
	char ch;
	char name[20];

	system("cls");
	Title();// call Title window
		ft=fopen("temp2.dat","w+");
		ek=fopen("Record2.dat","r");
		if(ek==NULL)
			{
				printf("\n\t Can not open file!! ");
				getch();
				return;
			}
	printf("\n\n\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("Enter the First Name of the Patient : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);

	if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			return;
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,10);
				printf("*** Existing Record ***");
				gotoxy(10,12);
				printf("%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				gotoxy(12,14);
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);
				gotoxy(12,15);
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				gotoxy(12,16);
				printf("Enter Gender: ");
				scanf("%s",p.Gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,17);
				printf("Enter age: ");
				scanf("%i",&p.age);
				gotoxy(12,18);
				printf("Enter Address: ");
				scanf("%s",p.Address);
				p.Address[0]=toupper(p.Address[0]);
				gotoxy(12,19);
				printf("Enter Contact no: ");
				scanf("%s",p.Contact_no);
				gotoxy(12,20);
				printf("Enter New email: ");
				scanf("%s",p.Email);
				gotoxy(12,21);
				printf("Enter Problem: ");
				scanf("%s",p.Problem);
				p.Problem[0]=toupper(p.Problem[0]);
				gotoxy(12,22);
				printf("Enter Doctor: ");
				fflush(stdin);gets(p.Doctor);
				p.Doctor[0]=toupper(p.Doctor[0]);
				printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.dat");
	   rename("temp2.dat","Record2.dat");
		getch();
		return;
}
void screen1115(){
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);

	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		return;
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		return;
	}
}

/*Doctor SubMenu*/
void screen1121(){
system("cls");
	Title();// call Title function
	//list of variables
	fp=fopen("Record3.dat","a");//open file in write mode
	printf("\n\n\t\t!!!!!!!!!!!!!! Add Doctor Record !!!!!!!!!!!!!\n");

	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",d.First_Name);
	d.First_Name[0]=toupper(d.First_Name[0]);
	if(strlen(d.First_Name)>20||strlen(d.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(d.First_Name);b++)
		{
			if (isalpha(d.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}

	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",d.Last_Name);
    d.Last_Name[0]=toupper(d.Last_Name[0]);
    if(strlen(d.Last_Name)>20||strlen(d.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(d.Last_Name);b++)
		{
			if (isalpha(d.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&d.Gender);
		if(toupper(d.Gender)=='M'|| toupper(d.Gender)=='F')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
	if(!ok)
	    {
		printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge:");
    scanf(" %i",&d.age);
/* **************************************** Address ******************************************************************* */
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",d.Address);
    d.Address[0]=toupper(d.Address[0]);
    if(strlen(d.Address)>20||strlen(d.Address)<4)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
		goto C;
	}

}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",d.Contact_no);
    if(strlen(d.Contact_no)>10||strlen(d.Contact_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(d.Contact_no);b++)
		{
			if (!isalpha(d.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",d.Email);
    if (strlen(d.Email)>30||strlen(d.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
	}
}while(strlen(d.Email)>30||strlen(d.Email)<8);
/* ********************************************************* Speciality *********************************************** */
    E:
    printf("\n\t\t\tSpeciality : ");
    scanf("%s",d.Speciality);
    d.Speciality[0]=toupper(d.Speciality[0]);
    if(strlen(d.Speciality)>15||strlen(d.Speciality)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(d.Speciality);b++)
		{
			if (isalpha(d.Speciality[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Speciality contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
/* ********************************************** Experience **************************************** */
	F:
    printf("\n\t\t\tExperience:");
    fflush(stdin);gets(d.Experience);
    d.Experience[0]=toupper(d.Experience[0]);
    if(strlen(d.Experience)>30||strlen(d.Experience)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(d.Experience);b++)
		{
			if (isalpha(d.Experience[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Experience contain Invalid character :(  Enter again :)");
			goto F;
		}
	}

    fprintf(fp," %s %s %c %i %s %s %s %s %s\n", d.First_Name, d.Last_Name, d.Gender, d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(fp);//fp file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
	screen1121();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
	getch();
	return;
	}
    else
    {
	printf("\n\t\tInvalid Input\n");
	goto sd;
    }
}

void screen1122(){
	int row;
	system("cls");
	Title();
	fp=fopen("Record3.dat","r");
	printf("\n\n");
	printf("\n\n\t\t!!!!!!!!!!!!! List Doctors Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(11,15);
		printf("Gender");
		gotoxy(18,15);
		printf("Age");
		gotoxy(22,15);
		printf("Address");
		gotoxy(30,15);
		printf("Contact No");
		gotoxy(41,15);
		printf("Email");
		gotoxy(54,15);
		printf("Speciality");
		gotoxy(66,15);
		printf("Experience\n");
		printf("=============================================================================");
		row=17;
		while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", d.First_Name, d.Last_Name,
					&d.Gender, &d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",d.First_Name, d.Last_Name);
			gotoxy(11,row);
			printf("%c",d.Gender);
			gotoxy(18,row);
			printf("%i",d.age);
			gotoxy(22,row);
			printf("%s",d.Address);
			gotoxy(30,row);
			printf("%s",d.Contact_no);
			gotoxy(41,row);
			printf("%s",d.Email);
			gotoxy(54,row);
			printf("%s",d.Speciality);
			gotoxy(64,row);
			printf("%s",d.Experience);
			row++;
		}
		fclose(fp);
		getch();
		return;
}



void screen1123(){
	FILE *fp, *ft1;
	int i,b, valid=0;
	char ch;
	char name[20];

	system("cls");
	Title();// call Title window
		ft1=fopen("temp3.dat","w+");
		fp=fopen("Record3.dat","r");
		if(fp==NULL)
			{
				printf("\n\t Can not open file!! ");
				getch();
				return;
			}
	printf("\n\n\t\t!!!!!!!!!!!!!! Edit Doctors Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("Enter the First Name of the Doctor : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);

	if(ft1==NULL)
		{
			printf("\n Can not open file");
			getch();
			return;
		}
		while(fscanf(fp,"%s %s %c %i %s %s %s %s %s\n", d.First_Name, d.Last_Name, &d.Gender, &d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience)!=EOF)
		{
			if(strcmp(d.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,10);
				printf("*** Existing Record ***");
				gotoxy(10,12);
				printf("%s %s %c %i %s %s %s %s %s\n",d.First_Name, d.Last_Name, d.Gender, d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience);
				gotoxy(12,14);
				printf("Enter New First Name: ");
				scanf("%s",d.First_Name);
				gotoxy(12,15);
				printf("Enter Last Name: ");
				scanf("%s",d.Last_Name);
				gotoxy(12,16);
				printf("Enter Gender: ");
				scanf("%s",d.Gender);
				p.Gender=toupper(d.Gender);
				gotoxy(12,17);
				printf("Enter age: ");
				scanf("%i",&d.age);
				gotoxy(12,18);
				printf("Enter Address: ");
				scanf("%s",d.Address);
				d.Address[0]=toupper(d.Address[0]);
				gotoxy(12,19);
				printf("Enter Contact no: ");
				scanf("%s",d.Contact_no);
				gotoxy(12,20);
				printf("Enter New email: ");
				scanf("%s",d.Email);
				gotoxy(12,21);
				printf("Enter Speciality: ");
				scanf("%s",d.Speciality);
				d.Speciality[0]=toupper(d.Speciality[0]);
				gotoxy(12,22);
				printf("Enter Experience: ");
				fflush(stdin);gets(d.Experience);
				d.Experience[0]=toupper(d.Experience[0]);
				printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft1,"%s %s %c %i %s %s %s %s %s\n",d.First_Name,d.Last_Name,d.Gender, d.age,d.Address,d.Contact_no,d.Email, d.Speciality,d.Experience);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}
			}
			else
			{
			fprintf(ft1,"%s %s %c %i %s %s %s %s %s\n",d.First_Name,d.Last_Name,d.Gender, d.age,d.Address,d.Contact_no, d.Email,d.Speciality,d.Experience);
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft1);
	   fclose(fp);
	   remove("Record3.dat");
	   rename("temp3.dat","Record3.dat");
		getch();
		return;
}
void screen1124(){
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	ft1=fopen("temp_file3.dat","w+");
	fp=fopen("Record3.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Doctors Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Doctor Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);

	while (fscanf(fp,"%s %s %c %i %s %s %s %s %s", d.First_Name, d.Last_Name, &d.Gender,
			 &d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience)!=EOF)
	{
		if (strcmp(d.First_Name,name)!=0)
		fprintf(ft1,"%s %s %c %i %s %s %s %s %s\n", d.First_Name, d.Last_Name, d.Gender, d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", d.First_Name, d.Last_Name, d.Gender, d.age, d.Address, d.Contact_no, d.Email, d.Speciality, d.Experience);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		return;
	}
	else
	{
		fclose(fp);
		fclose(ft1);
		remove("Record3.dat");
		rename("temp_file3.dat","Record3.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		return;
	}

}

void screen1131(){
system("cls");
	Title();// call Title function
	//list of variables
	ek1=fopen("Record4.dat","a");//open file in write mode
	printf("\n\n\t\t!!!!!!!!!!!!!! Add Bed Information !!!!!!!!!!!!!\n");
	printf("\n\n\t\t\t Total No of Bed:");
	scanf(" %s",B.bedinfo);
	printf("\n\n\t\t\t Total No of Bed Available:");
	scanf(" %s",B.bedavail);
	printf("\n\n\t\t\t Total No of Bed occupied:");
	scanf(" %s",B.addbed);
	fprintf(ek1," %s %s %s\n",B.bedinfo,B.bedavail,B.addbed );
	printf("\n\n\t\t\t.... Information Record Successful ...\n");
	system("pause");
	fclose(ek1);//ek file is closed
}

void screen1132(){
int row;
	system("cls");
	Title();
	ek1=fopen("Record4.dat","r");
	printf("\n\n");
	printf("\n\n\t\t!!!!!!!!!!!!! List Bed Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Total No of Bed :");
		gotoxy(1,17);
		printf("Total Number of Bed available :");
		gotoxy(1,19);
		printf("Total No of Bed Occupied :");
		while(fscanf(ek1,"%s %s %s ",B.bedinfo,B.bedavail,B.addbed )!=EOF)
		{
			gotoxy(35,15);
			printf("%s",B.bedinfo);
			gotoxy(35,17);
			printf("%s",B.bedavail);
			gotoxy(35,19);
			printf("%s",B.addbed);

		}
		fclose(ek1);
		getch();
		return;
}

void screen1133(){
      FILE *ek1, *ft2;
	int i,b, valid=0;
	char ch;
	char name[20];
	char name1[20]="Bed\0";

	system("cls");
	Title();// call Title window
		ft2=fopen("temp4.dat","w+");
		ek1=fopen("Record4.dat","r");
		if(ek1==NULL)
			{
				printf("\n\t Can not open file!! ");
				getch();
				return;
			}
	printf("\n\n\t\t!!!!!!!!!!!!!! Edit Bed Info !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("Enter Secret code for editing Bed info : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);

	if(ft2==NULL)
		{
			printf("\n Can not open file");
			getch();
			return;
		}
		while(fscanf(ek1,"%s %s %s\n",B.bedinfo,B.bedavail,B.addbed )!=EOF)
		{
			if(strcmp(name1, name)==0)
			{
				valid=1;
				gotoxy(25,10);
				printf("*** Existing Record ***");
				gotoxy(10,12);
				printf("Total Bed");
				gotoxy(20,12);
				printf("Total Bed Availavle");
				gotoxy(36,12);
				printf("Total Bed Occupied");
				gotoxy(10,14);
				printf("%10s %12s %15s\n",B.bedinfo,B.bedavail,B.addbed);
				gotoxy(12,16);
				printf("Enter New Total no of Bed: ");
				scanf("%s",B.bedinfo);
				gotoxy(12,18);
				printf("Enter Total No of Bed available: ");
				scanf("%s",B.bedavail);
				gotoxy(12,20);
				printf("Enter total No of Bed occupied: ");
				scanf("%s",B.addbed);

				printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft2,"%s %s %s\n", B.bedinfo,B.bedavail,B.addbed);
				printf("\n\n\t\t\tPatient record updated successfully...");

				}
			}
			else
			{
			fprintf(ft2,"%s %s %s\n",B.bedinfo,B.bedavail,B.addbed );
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft2);
	   fclose(ek1);
	   remove("Record4.dat");
	   rename("temp4.dat","Record4.dat");
		getch();
		return;
}
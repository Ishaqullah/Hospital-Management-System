#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


#define ENTER 13 //ASCII value of enter key
#define TAB 9 //ASCII value of tab key
#define BKSP 8 //ASCII value of backspace key
#define SPACE 32 //ASCII value of space key

//---------------------------------------------LIST OF GLOBAL VARIABLE-------------------------------------------------------------
struct patient
{
	char First_Name[100];
	char Last_Name[100]; 
	int age;
	char Gender;
	char Contact_no[100];
	char Address[100];
	char Email[100];
	char Doctor[100];
	char Problem[100];
};

struct acc
{
	char username[20];
	char password[20];
}account;
//----------------------------------------------FOR PLACING CURSOR-----------------------------------------------------------------

void gotoxy(int x, int y) {
COORD c ; 
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


//---------------------------------------------LIST OF FUNCTIONS--------------------------------------------------------------
void title();
void welcomescreen();
void signup();
void loginscreen(int);
void choice(struct patient pat[],int,int);
void add(int,struct patient pat[],int);
void edit(struct patient pat[],int);
void del(struct patient pat[],int);
void view(struct patient pat[],int,int);
void search(struct patient pat[],int,int);
void exitme();

//------------------------------------------MAIN-------------------------------------------------

main()
{
system("color F0");
welcomescreen();
}


//-------------------------------------------TITLE-----------------------------------------------

void title()
{
	printf("\t\t\t\t\t\t***********************\n");
	printf("\t\t\t\t\t\t  NU GENERAL HOSPITAL\n");
	printf("\t\t\t\t\t\t***********************\n");
		
}

//-------------------------------------------WELCOME SCREEN-----------------------------------------------

void welcomescreen()
{
	printf("\nNOTE: Default Username is (Fast) and Password is (NUCES) if you want to change it go for sign up");
	printf("\n\n\t\t\t\t\t *****************************************\n");
	printf("\t\t\t\t\t\t      Developed By\n");
	printf("\t\t\t\t\t  Ishaqullah Siddiqui_20K-0148(Group Leader)\n");
	printf("\t\t\t\t\t  Sarim Latif Khan_20K-1644   (Group Member)\n");
	printf("\t\t\t\t\t  Atizaz Ahmed_20K-1734       (Group Member)\n");
	printf("\t\t\t\t\t *****************************************\n");
	int choice;
	printf("\n\n\n\n\n\n\t\t\t\t\t  *******************************************");
	printf("\n\t\t\t\t\t  #\t\t WELCOME TO\t\t    #");
	printf("\n\t\t\t\t\t  #\t     NU GENERAL HOSPITAL\t    #");
	printf("\n\t\t\t\t\t  *******************************************");
	printf("\n\n\n\n\t\t\t\t\t   For Sign up press 1\n\t\t\t\t\t   For Login press 2\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		system("cls");
		signup();
		break;
		case 2:
		system("cls");
		loginscreen(0);
		break;
		default:
		printf("Sorry Invalid Entry!!");
	}
		
}



void signup()
{
	int i=0;
	char password[20];
	FILE *fptr;
	fptr=fopen("Account.txt","a");
	title();
	printf("\n\n\t\t\t\tEnter username you want for your account ");
	fflush(stdin);
	gets(account.username);
	printf("\n\n\t\t\t\tEnter password you want for your account ");
	fflush(stdin);
	gets(password);
	while(1)
	{
		if(password[i]=='\0')
		break;
		
		account.password[i]=password[i]+100;
		i++;
	}
	fprintf(fptr,"%s %s\n",account.username,account.password);
	fclose(fptr);
    printf("\n\n\t\t\t\tYou have been regestired.Press any key to continue ");
    getch();
    system("cls");
    loginscreen(0);
}
//-------------------------------------------LOGIN SCREEN-----------------------------------------------

void loginscreen(int i)
{
	FILE *fptr;
	fptr=fopen("Account.txt","r");
	while(!feof(fptr))
	{
	fscanf(fptr,"%s %s\n",account.username,account.password);
	}
	struct patient pat[100];
	char entusername[20];
	char entpassword[20];
	char ans,ch;
	int j=0,k=0;
	title();
	printf("\n\n\t\t\t\t\tEnter user name ");
	fflush(stdin);
	gets(entusername);
	printf("\n\t\t\t\t\tEnter password ");
	
	while(1)
    {
	   ch = getch(); // Here we are reading charachter from a user by getch() and that charachter is stored in var ch
	   if(ch==ENTER)
	{
	   entpassword[j]='\0';
	   break;   
    }
    else if(ch==BKSP)
	{
		if(j>0)
		{
			j--;
			printf("\b \b");
		}
	}
	else if(ch == TAB||ch == SPACE)
	{
		continue;
	}
	else
	{
		entpassword[j]=ch;
		j++;
		printf("*");
	}
}
	while(1)
	{
		if(entpassword[k]=='\0')
		break;
		
		entpassword[k]=entpassword[k]+100;
		k++;
	}
	
	if(strcmp(entusername,account.username)==0 && strcmp(entpassword,account.password)==0)
	{
		system("cls");
		choice(pat,0,0);
	}
	
	else
	{
		if(i<=1){
		printf("\n\n\t\t\t\tYou have entered wrong username or password (Press any key to continue)");
		getch();
			system("cls");
			return loginscreen(i+1);
	}
	else
	printf("\n\n\t\t\t\tSorry you can not enter the management syetem");
	}
fclose(fptr);
}

//------------------------------------------CHOICE------------------------------------------------
void choice(struct patient pat[],int ctr,int i){
int c;
 title();
 fflush(stdin);
 printf("\n\n\t\t\t\t\t1.Add Patient Record\n\n\t\t\t\t\t2.Edit Patient Record\n\n\t\t\t\t\t3.List of Patient record\n\n\t\t\t\t\t4.Delete Patient Record\n\n\t\t\t\t\t5.Search Patient Record\n\n\t\t\t\t\t6.Exit\n\n(Note: Press the respective option number to select)\n");
 scanf("%d",&c);
if(c==1)
 {
 	system("cls");
 	add(i,pat,ctr);
 }
else if(c==2)
 {
 	system("cls");
 	edit(pat,ctr);
 }
else if(c==3)
 {
 	system("cls");
 	view(pat,ctr,i);
 }
else if(c==4)
 {
 	system("cls");
 	del(pat,ctr);
 }
else if(c==5)
 {
 	system("cls");
 	search(pat,ctr,i);
 }
else if(c==6)
 {
    system("cls");
 	exitme();
 }	
else
{
printf("Invalid choice (Press any key to continue)");
getch();
system("cls");
choice(pat,ctr,i);
}
}

//-------------------------------------------ADD RECORD-----------------------------------------------

void add(int i,struct patient pat[],int ctr)
{
	title();
	FILE *fptr;
	fptr=fopen("Record1.txt","a");
	printf("\n\n\t\t\t  !!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");
	char ans;
	fflush(stdin);
printf("\n\n\t\t\t\t\tEnter the first name: ");
gets(pat[i].First_Name);	
fflush(stdin);

printf("\n\n\t\t\t\t\tEnter the last name: ");
gets(pat[i].Last_Name);	
fflush(stdin);	

A:	
printf("\n\n\t\t\t\t\tEnter the gender (M for male) & (F for female): ");
scanf(" %c",&pat[i].Gender);	
fflush(stdin);
if(pat[i].Gender=='M' || pat[i].Gender=='m' || pat[i].Gender=='F' || pat[i].Gender=='f'){
printf("\n\n\t\t\t\t\tEnter the age: ");
scanf("%d",&pat[i].age);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter the address: ");	
gets(pat[i].Address);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter the contact number: ");	
gets(pat[i].Contact_no);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter email: ");	
gets(pat[i].Email);	
fflush(stdin);
printf("\n\n\t\t\t\t\tEnter problem: ");	
gets(pat[i].Problem);
fflush(stdin);
printf("\n\n\t\t\t\t\tEnter the doctor: ");
gets(pat[i].Doctor);
fflush(stdin);

fprintf(fptr,"%s %s %c %d %s %s %s %s %s\n",pat[i].First_Name,pat[i].Last_Name,pat[i].Gender,pat[i].age,pat[i].Address,pat[i].Contact_no,pat[i].Email,pat[i].Problem,pat[i].Doctor);
printf("\n\n\t\t\t.... Information Record Successful ...");
fclose(fptr);

printf("\n\n\t\tDo you want to enter more record (Y/N)");
scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
return add(i+1,pat,ctr+1);	
}
else if(ans=='N' || ans=='n'){ 
system("cls");
choice(pat,ctr+1,i+1);
}
else
printf("INVALID ENTRY!!");

}

else
{
	printf("Invalid gender");
goto A;	
}



}




//-------------------------------------------VIEW RECORD----------------------------------------------

void view(struct patient pat[],int ctr,int i)
{
	FILE *fptr;
	fptr=fopen("Record1.txt","r");
	if(fptr==NULL){
		printf("File not found!!To proceed enter any key ");
		getch();
		system("cls");	
        choice(pat,ctr,i);
	}
	title();
	printf("\n\n\t\t\t  !!!!!!!!!!!!!! List of Patients Record !!!!!!!!!!!!!\n");
	int j,row=12;
	char ans;
gotoxy(1,10);
printf("Full name");
gotoxy(20,10);
printf("Gender");
gotoxy(27,10);
printf("Age");
gotoxy(31,10);
printf("Address");
gotoxy(49,10);
printf("Contact-no");
gotoxy(64,10);
printf("Email");
gotoxy(88,10);
printf("Problem");
gotoxy(105,10);
printf("Doctor");
printf("\n=======================================================================================================================");
char buffer[100];
fgets(buffer,100,fptr);
int x=0;
while(!feof(fptr))
{
	struct patient *p=pat+x;
	sscanf(buffer,"%s %s %c %d %s %s %s %s %s",&p->First_Name,&p->Last_Name,&p->Gender,&p->age,&p->Address
	,&p->Contact_no,&p->Email,&p->Problem,&p->Doctor);
	fgets(buffer,100,fptr);
	x++;
}
int n=x;
for(j=0;j<n;j++){
	

	
gotoxy(1,row);	
printf("%s %s",pat[j].First_Name,pat[j].Last_Name);
gotoxy(20,row);
printf("%c",pat[j].Gender);
gotoxy(27,row);
printf("%d",pat[j].age);
gotoxy(31,row);
printf("%s",pat[j].Address);
gotoxy(49,row);
printf("%s",pat[j].Contact_no);
gotoxy(64,row);
printf("%s",pat[j].Email);
gotoxy(88,row);
printf("%s",pat[j].Problem);
gotoxy(105,row);
printf("%s",pat[j].Doctor);
row++;	


}

fclose(fptr);
printf("\nDo you want to proceed (Y/N)");

scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
choice(pat,ctr,i);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
exitme();
}
else
printf("INVALID ENTRY!!");

}

//-------------------------------------------DELETE RECORD----------------------------------------------

void del(struct patient pat[],int ctr)
{
    
    FILE *fptr,*fptr1;
    fptr=fopen("Record1.txt","r+");
    fptr1=fopen("temp1.txt","a+");
	title();
	char ans;
	int i,l=0;
	char name[20];
	printf("\n\n\t\t\t  !!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	fflush(stdin);
	printf("\n\n\t\t\tEnter the name of patient whose record you want to delete ");
	gets(name);
	fflush(stdin);
    struct patient p;
   	while (fscanf(fptr,"%s %s %c %d %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(fptr1,"%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{
			l=1;
		}
	}
	
	if(l==0)
	{
		printf("\n\n\t\tRecord not found!!");
		printf("\n\n\t\tDo you want to proceed (Y/N)");	
		scanf("%c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
choice(pat,ctr,i);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
exitme();
}
else
printf("IVALID ENTRY!!");
}

	
else
{		
fclose(fptr);
fclose(fptr1);
remove("Record1.txt");
rename("temp1.txt","Record1.txt");
printf("\n\n\t\tYour data has been deleted.Do you want to delete more record (Y/N)");
scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
return 	del(pat,ctr);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
choice(pat,ctr,i);
}
else
printf("IVALID ENTRY!!");
	
	
}

}

//-------------------------------------------EDIT RECORD----------------------------------------------

void edit(struct patient pat[],int ctr)
{
	 FILE *fptr,*fptr1;
    fptr=fopen("Record1.txt","r+");
    fptr1=fopen("temp2.txt","a+");
	title();
	char ans;
	int i,l=0;
	char name[20];
	printf("\n\n\t\t\t  !!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	fflush(stdin);
	printf("\n\n\t\t\tEnter the name of patient whose record you want to edit ");
	gets(name);
	fflush(stdin);
    struct patient p;
   	while (fscanf(fptr,"%s %s %c %d %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(fptr1,"%s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{
			l=1;
		}
	}
	

if(l==1)
{
printf("\n\n\t\t\t\t\tEnter the first name: ");
gets(pat[i].First_Name);	
fflush(stdin);

printf("\n\n\t\t\t\t\tEnter the last name: ");
gets(pat[i].Last_Name);	
fflush(stdin);	

C:	
printf("\n\n\t\t\t\t\tEnter the gender (M for male) & (F for female): ");
scanf(" %c",&pat[i].Gender);	
fflush(stdin);
if(pat[i].Gender=='M' || pat[i].Gender=='m' || pat[i].Gender=='F' || pat[i].Gender=='f'){
printf("\n\n\t\t\t\t\tEnter the age: ");
scanf("%d",&pat[i].age);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter the address: ");	
gets(pat[i].Address);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter the contact number: ");	
gets(pat[i].Contact_no);
fflush(stdin);	
printf("\n\n\t\t\t\t\tEnter email: ");	
gets(pat[i].Email);	
fflush(stdin);
printf("\n\n\t\t\t\t\tEnter problem: ");	
gets(pat[i].Problem);
fflush(stdin);
printf("\n\n\t\t\t\t\tEnter the doctor: ");
gets(pat[i].Doctor);
fflush(stdin);

fprintf(fptr1,"%s %s %c %d %s %s %s %s %s\n",pat[i].First_Name,pat[i].Last_Name,pat[i].Gender,pat[i].age,pat[i].Address,pat[i].Contact_no,pat[i].Email,pat[i].Problem,pat[i].Doctor);
printf("\n\n\t\t\t.... Information Record Successful ...");	

fclose(fptr);
fclose(fptr1);
remove("Record1.txt");
rename("temp2.txt","Record1.txt");
printf("\n\n\t\tYour data has been edited.Do you want to edit more record (Y/N)");
scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
return 	edit(pat,ctr);
}


else if(ans=='N' || ans=='n')
{ 
system("cls");
choice(pat,ctr,i);
}


else
printf("IVALID ENTRY!!");

}

else
{
printf("Invalid gender");
goto C;	
}

} 


else
{
	    printf("\n\n\t\tRecord not found!!");
		printf("\n\n\t\tDo you want to proceed (Y/N)");	
		scanf("%c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
choice(pat,ctr,i);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
exitme();
}
else
printf("IVALID ENTRY!!");
}

 	
}



//-------------------------------------------SEARCH RECORD----------------------------------------------

void search(struct patient pat[],int ctr,int i)
{
	char name[20];
	int l=0;
FILE *fptr;
	fptr=fopen("Record1.txt","r");
	if(fptr==NULL){
		printf("File not found!!To proceed enter any key ");
		getch();
		system("cls");	
        choice(pat,ctr,i);
	}
	title();
	printf("\n\n\t\t\t  !!!!!!!!!!!!!! Search for Patient Record !!!!!!!!!!!!!\n");
	int j,row=12;
	char ans;
	printf("\n\n\t\t\tEnter the name of patient whose record you want to search ");
	fflush(stdin);
gets(name);


gotoxy(1,10);
printf("Full name");
gotoxy(20,10);
printf("Gender");
gotoxy(27,10);
printf("Age");
gotoxy(31,10);
printf("Address");
gotoxy(49,10);
printf("Contact-no");
gotoxy(64,10);
printf("Email");
gotoxy(88,10);
printf("Problem");
gotoxy(105,10);
printf("Doctor");
printf("\n=======================================================================================================================");
char buffer[100];
fgets(buffer,100,fptr);
int x=0;

fflush(stdin);
 
while(!feof(fptr))
{
	struct patient *p=pat+x;
	sscanf(buffer,"%s %s %c %d %s %s %s %s %s",&p->First_Name,&p->Last_Name,&p->Gender,&p->age,&p->Address
	,&p->Contact_no,&p->Email,&p->Problem,&p->Doctor);
	fgets(buffer,100,fptr);
	x++;
}
int n=x;
for(j=0;j<n;j++){
l=0;	
if(strcmp(pat[j].First_Name,name)==0)
{
	
gotoxy(1,row);	
printf("%s %s",pat[j].First_Name,pat[j].Last_Name);
gotoxy(20,row);
printf("%c",pat[j].Gender);
gotoxy(27,row);
printf("%d",pat[j].age);
gotoxy(31,row);
printf("%s",pat[j].Address);
gotoxy(49,row);
printf("%s",pat[j].Contact_no);
gotoxy(64,row);
printf("%s",pat[j].Email);
gotoxy(88,row);
printf("%s",pat[j].Problem);
gotoxy(105,row);
printf("%s",pat[j].Doctor);
row++;
break;	
}
else 
l++;

}
if(l!=0)
{
	printf("\n\t\t\t\tSorry Record not found");
}

fclose(fptr);
printf("\nDo you want to proceed (Y/N)");

scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
choice(pat,ctr,i);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
exitme();
}
else
printf("INVALID ENTRY!!");	
}

//-------------------------------------------EXIT----------------------------------------------

void exitme()
{
	title();
	printf("\n\n\t\tThanks For visiting :)");
}








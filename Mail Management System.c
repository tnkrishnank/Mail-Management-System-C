#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

//Structure that hold that user data
typedef struct
{
    char name[50];
    char rollno[7];
    char dob[11];
    char dep[4];
    char passwd[20];
    char rpasswd[20];
}user;

//Definition of all function prototypes used in this program
void homepage();
void signup();
void addnewuser(user A);
int isExistingUser(user A);
void login();
void options(char rollno[]);
void compose(char rollno[]);
void display(char code[],char roll[]);
void readm(char roll[]);
void newm(char roll[]);
void oldm(char roll[]);
void sent(char roll[]);
void further(char to[],char rs[],char rd2[],char roll[],int n);
void reply(char user[],char sub[],char body[],char rd[],char roll[]);
void changepwd(char rollno[]);
int count(char roll[],int i);
void deletem(char roll[],int n);

int main()
{
    int i;

    char a = 219;

    //Command to change the background and text color
    system("COLOR 02");

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *       WELCOME TO AMCS MAIL       *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    DESIGNED BY :                 |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    20PC13 - GURU PRASANNA V      |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    20PC22 - NAVIN KRISHNA T      |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    20PC37 - VETRIVEL M D         |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n");
    printf("\n\t\t\t\t\t  ");
    printf("             LOADING...\n");
    printf("\n\t\t\t\t\t  ");

    //Loop to display the Loading Part
    for (i = 1; i <= 36; i++)
    {
        printf("%c",a);
        Sleep(50);
    }
    system("cls");
    homepage();
    return 0;
}

void homepage()
{
    system("cls");
    system("COLOR 70");

    int choice;

home:

    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *       WELCOME TO AMCS MAIL       *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    1. LOGIN                      |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    2. SIGNUP                     |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n\n");

    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    switch(choice)
    {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            default:
                printf("\n");
                printf("\t\t\t\t\t  ************************************\n");
                printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
                printf("\t\t\t\t\t  ************************************\n");
                printf("\n\t\t\t\t\t  ");
                system("pause");
                system("cls");
                goto home;
    }
}

void signup()
{
    system("cls");

    int i;
    int t = 0;
    int b = 0;

    char a = 'a';

    user newuser;

    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t  ***********************************************\n");
    printf("\t\t\t\t  *              AMCS MAIL SIGNUP               *\n");
    printf("\t\t\t\t  ***********************************************\n");
    printf("\n");

    //Getting the Name from user
    printf("\t\t\t\t  NAME                      : ");
    gets(newuser.name);

    //Checking whether the first character entered by user in NULL
    if(newuser.name[0] == '\0')
        t = 1;

    //Loop to check if the entered Name is Valid or Not
    i = 0;
    while(1)
    {
        b = 0;
        //Base Condition to Terminate from the Loop if a NULL or ENTER character is encountered
        if(newuser.name[i] == '\0' || newuser.name[i] == '\r')
        {
            break;
        }
        //Checking if the user has entered only alphabets in
        if(newuser.name[i] >= 'A' && newuser.name[i] <= 'Z')
        {
            b = 1;
        }
        if(newuser.name[i] >= 'a' && newuser.name[i] <= 'z')
        {
            b = 1;
        }
        //Checking whether any other character other than alphabet, entered by the user for name is a blank-space (or) dot
        if(newuser.name[i] == ' ')
        {
            b = 1;
        }
        if(newuser.name[i] == '.')
        {
            b = 1;
        }
        //If statement to set the Flag variable 1 if the entered name is invalid
        if(b == 0)
        {
            t = 1;
            break;
        }
        i++;
    }

    //if statement to print INVALID NAME if the Flag variable is 1
    if(t == 1)
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *               INVALID NAME !!!              *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }

    //Getting the Roll Number from user
    printf("\t\t\t\t  ROLL NUMBER               : ");
    gets(newuser.rollno);

    /*
        -> Checking whether the roll number contains only 6 characters
        -> Checking whether the first two characters of roll number is a digit
        -> Checking whether the second and third character of roll number is a alphabet
        -> Checking whether the number obtained from last two characters is greater than zero and less than or equal to 40
    */

    if(newuser.rollno[6] != '\0')
        t = 1;
    if(newuser.rollno[0] < '0' || newuser.rollno[0] > '9')
        t = 1;
    if(newuser.rollno[1] < '0' || newuser.rollno[1] > '9')
        t = 1;
    if(!((newuser.rollno[2] > 65 && newuser.rollno[2] < 90) || (newuser.rollno[2] > 97 && newuser.rollno[2] < 122)))
        t = 1;
    if(!((newuser.rollno[3] > 65 && newuser.rollno[3] < 90) || (newuser.rollno[3] > 97 && newuser.rollno[3] < 122)))
        t = 1;
    if(newuser.rollno[4] == '4' && newuser.rollno[5] != '0')
        t = 1;
    if(newuser.rollno[4] < '0' || newuser.rollno[4] > '9')
        t = 1;
    if(newuser.rollno[4] == '0' && newuser.rollno[5] == '0')
        t = 1;

    //if statement to print INVALID ROLL NUMBER if the Flag variable is 1
    if(t == 1)
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *           INVALID ROLL NUMBER !!!           *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }

    //Converting the Roll number to uppercase
    i = 0;
    do
    {
        newuser.rollno[i] = toupper(newuser.rollno[i]);
        i++;
    }
    while(newuser.rollno[i] != '\0');

    /*
        Checking whether the user has already created a account,
        The isExistingUser() function returns 1 if the user has already Created a account
        Or else it return 0
    */

    if(isExistingUser(newuser))
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *          ACCOUNT ALREADY EXISTS !!!         *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }

    //Getting the Date of Birth from user
    printf("\t\t\t\t  DATE OF BIRTH (DD/MM/YYYY): ");
    gets(newuser.dob);

    /*
        -> Checking whether the date of birth contains only 10 characters
        -> Checking whether the number obtained from first two characters are greater than zero and less than or equal to 31
        -> Checking whether the number obtained from fourth and fifth characters are greater than zero and less than or equal to 12
        -> Checking whether the number obtained from last four digits are greater than or equal to 1000
        -> Checking whether the user has entered a invalid day(00) and month(00)
        -> Checking whether the last four characters entered by the user is a digit
    */

    if(newuser.dob[10] != '\0')
        t = 1;
    if(newuser.dob[0] < '0' || newuser.dob[0] > '3')
        t = 1;
    if(newuser.dob[1] < '0' || newuser.dob[1] > '9')
        t = 1;
    if(newuser.dob[0] == '3' && newuser.dob[1] > '1')
        t = 1;
    if(newuser.dob[3] < '0' || newuser.dob[3] > '1')
        t = 1;
    if(newuser.dob[4] < '0' || newuser.dob[4] > '9')
        t = 1;
    if(newuser.dob[3] == '1' && newuser.dob[4] > '2')
        t = 1;
    if(strstr(newuser.dob,"00/"))
        t = 1;
    if(newuser.dob[6] < '1' || newuser.dob[6] > '2' )
        t = 1;

    i = 7;
    do
    {
        if(!(isdigit(newuser.dob[i])))
        {
            t = 1;
            break;
        }
        i++;
    }
    while(i != 10);

    //if statement to print INVALID Date of Birth if the Flag variable is 1
    if(t == 1)
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *          INVALID DATE OF BIRTH !!!          *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }

    printf("\t\t\t\t  DEPARTMENT (SS/TCS/DS/CS) : ");
    gets(newuser.dep);

    //Checking whether the user has entered valid a department within the given opions
    if(strcmpi(newuser.dep,"tcs") && strcmpi(newuser.dep,"ss") && strcmpi(newuser.dep,"ds") && strcmpi(newuser.dep,"cs"))
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *            INVALID DEPARTMENT !!!           *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }

    printf("\t\t\t\t  PASSWORD                  : ");

    //Loop to get the password from the user character by character and displaying * at the same time
    i = 0;
    while(a != '\r')
    {
        a = getch();
        if(a == '\r' && i == 0)
        {
            printf("\n\n");
            printf("\t\t\t\t  ***********************************************\n");
            printf("\t\t\t\t  *             INVALID PASSWORD !!!            *\n");
            printf("\t\t\t\t  ***********************************************\n");
            printf("\n\t\t\t\t  ");
            system("pause");
            homepage();
        }
        if(a == '\b' && i > 0)
        {
            i--;
            putch(a);
            putch(' ');
            putch(a);
        }
        else if(a != '\r' && a != '\b')
        {
            putch('*');
            newuser.passwd[i] = a;
            i++;
        }
    }
    newuser.passwd[i] = '\0';

    printf("\n");

    printf("\t\t\t\t  RE-TYPE PASSWORD          : ");

    //Loop to get the password from the user character by character and displaying * at the same time
    a = 'a';
    i = 0;
    while(a != '\r')
    {
        a = getch();
        if(a == '\b' && i > 0)
        {
            i--;
            putch(a);
            putch(' ');
            putch(a);
        }
        else if(a != '\r' && a != '\b')
        {
            putch('*');
            newuser.rpasswd[i] = a;
            i++;
        }
    }
    newuser.rpasswd[i] = '\0';

    //Checking whether both the passwords entered by the user is same or not.
    if((strcmp(newuser.passwd,newuser.rpasswd)) == 0)
    {
        //Calling a the addnewuser() function to create a new account
        addnewuser(newuser);
    }
    else
    {
        printf("\n\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\t\t\t\t  *            PASSWORD MISMATCH !!!            *\n");
        printf("\t\t\t\t  ***********************************************\n");
        printf("\n\t\t\t\t  ");
        system("pause");
        homepage();
    }
}

void addnewuser(user A)
{
    int i;
    int l;

    char path[45];

    FILE *f;
    f = fopen("USERS.txt","a");

    //Loop to write the roll number to the users file in uppercase
    i = 0;
    do
    {
        fputc(toupper(A.rollno[i]),f);
        i++;
    }
    while(A.rollno[i] != '\0');

    fputs(" - ",f);

    //Loop to write the name to the users file in uppercase
    i = 0;
    do
    {
        fputc(toupper(A.name[i]),f);
        i++;
    }
    while(A.name[i] != '\0');

    fputs(" (",f);

    //Loop to write the department to the users file in uppercase
    i = 0;
    do
    {
        fputc(toupper(A.dep[i]),f);
        i++;
    }
    while(A.dep[i] != '\0');

    fputs(")",f);
    fprintf(f,"\n");

    fclose(f);

    sprintf(path,"%s.txt",A.rollno);
    f = fopen(path,"a");

    /*
        -> A new file is created for the User by with their roll number as the name
        -> Writing the password to the first line of the file(storing the password as 20 characters)
        -> Writing the name, roll-number, DOB and department to the file in uppercase
    */

    l = strlen(A.passwd);

    for(i = 0; i < 20 - l; i++)
    {
        A.passwd[l+i] = '!';
    }
    A.passwd[20] = '\0';

    fputs(A.passwd,f);
    fprintf(f,"\n");
    fputs("NAME        : ",f);

    i = 0;
    do
    {
        fputc(toupper(A.name[i]),f);
        i++;
    }
    while(A.name[i] != '\0');

    fprintf(f,"\n");
    fputs("ROLL NUMBER : ",f);

    i = 0;
    do
    {
        fputc(toupper(A.rollno[i]),f);
        i++;
    }
    while(A.rollno[i] != '\0');

    fprintf(f,"\n");
    fputs("DOB         : ",f);
    fputs(A.dob,f);
    fprintf(f,"\n");
    fputs("DEPARTMENT  : ",f);

    i = 0;
    do
    {
        fputc(toupper(A.dep[i]),f);
        i++;
    }
    while(A.dep[i] != '\0');

    fprintf(f,"\n");

    fclose(f);

    //Displaying the Message on Successful Account Creation to the user
    printf("\n\n");
    printf("\t\t\t\t  ***********************************************\n");
    printf("\t\t\t\t  *               ACCOUNT CREATED               *\n");
    printf("\t\t\t\t  ***********************************************\n");
    printf("\n\t\t\t\t  ");
    system("pause");
    homepage();
}

int isExistingUser(user A)
{
    /*
        -> Function to check if the user has already created a account or not
        -> The function return 0 if user is a new user
        -> The function returns 1 if the user has already created a account
    */

    FILE *f;
    f = fopen("USERS.txt","r");

    while(fgets(A.name,sizeof(A.name),f))
    {
        //Checks whether the given user A's name is written in the users file(Contains the list of users)
        if(strstr(A.name,A.rollno))
        {
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    return 0;
}

void login()
{
    //Command to clear the screen
    system("cls");

    int i;
    int l;

    char choice;
    char rollno[7];
    char pass[20];
    char chk[20];
    char path[45];
    char a;

home:

    //Command to clear the input buffer
    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  *************************************\n");
    printf("\t\t\t\t\t  *          AMCS MAIL LOGIN          *\n");
    printf("\t\t\t\t\t  *************************************\n\n");
    printf("\t\t\t\t\t   NOTE : ROLL NUMBER IS YOUR USERNAME\n\n");

    printf("\t\t\t\t\t   USERNAME : ");
    gets(rollno);

    //Converting the user-name entered by user to uppercase
    i = 0;
    do
    {
        rollno[i] = toupper(rollno[i]);
        i++;
    }
    while(rollno[i] != '\0');

    FILE *f;

    sprintf(path,"%s.txt",rollno);

    fflush(stdin);

    /*
        -> If statement to check if the account exists or not
        -> This is done by checking if the complier if able to open the file in the given path
    */

    if((f = fopen(path,"rw")) == NULL)
    {
        printf("\n\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *     ACCOUNT DOES NOT EXIST !!!    *\n");
        printf("\t\t\t\t\t  *************************************\n\n");

        printf("\t\t\t\t\t  DO YOU HAVE AN EXISTING ACCOUNT ? ( Y / N ) : ");
        scanf(" %c",&choice);

        if(choice == 'Y' || choice == 'y')
        {
            system("cls");
            goto home;
        }
        else
        {
            printf("\n\t\t\t\t\t  ");
            printf("DO YOU WANT TO SIGNUP ? ( Y / N ) : ");
            scanf(" %c",&choice);
            if(choice == 'Y' || choice == 'y')
            {
                signup();
            }
            else
            {
                homepage();
            }
        }
        fclose(f);
    }

    printf("\n\n");
    printf("\t\t\t\t\t   PASSWORD : ");

    a = 'a';

    //Loop to get the password from the user if the account exists
    i = 0;
    while(a != '\r')
    {
        a = getch();
        if(a == '\b' && i > 0)
        {
            i--;
            putch(a);
            putch(' ');
            putch(a);
        }
        else if(a != '\r' && a != '\b')
        {
            putch('*');
            pass[i] = a;
            i++;
        }
    }
    pass[i] = '\0';

    fgets(chk,sizeof(chk),f);

    l = strlen(pass);

    for(i = 0; i < 19 - l; i++)
    {
        pass[l+i] = '!';
    }
    pass[19] = '\0';

    //Comparing the password entered by the user and the password stored int the first line of the file
    if((strcmp(chk,pass)) == 0)
    {
        //If the password matches then options() function is called
        options(rollno);
    }
    else
    {
        printf("\n\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *      INCORRECT PASSWORD !!!       *\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        goto home;
    }
}

void options(char rollno[])
{
    /*
        This function gets the users choice and
        directs them to that particular page the
        available options are compose, read, change
        password and go back.
    */

    //Command to clear the screen
    system("cls");

    int choice;

home:

    //Command to clear the input buffer
    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *       WELCOME TO AMCS MAIL       *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    1. COMPOSE                    |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    2. READ                       |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    3. CHANGE PASSWORD            |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    4. LOGOUT                     |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n\n");

    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            compose(rollno);
            break;
        case 2:
            readm(rollno);
            break;
        case 3:
            changepwd(rollno);
            break;
        case 4:
            homepage();
            break;
        default:
            printf("\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\n\t\t\t\t\t  ");
            system("pause");
            system("cls");
            goto home;
    }
}

void compose(char rollno[])
{
    /*
        This function is to show the to the user
        available departments and direct the
        user to the page that lists out all the
        available users in that particular department
    */

    system("cls");

    int choice;

home:

    //Command to clear the input buffer
    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *       RECEPIENT DEPARTMENT       *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  1. SOFTWARE SYSTEMS             |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  2. THEORETICAL COMPUTER SCIENCE |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  3. DATA SCIENCE                 |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  4. CYBER SECURITY               |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n\n");

    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            display("(SS)",rollno);
            break;
        case 2:
            display("(TCS)",rollno);
            break;
        case 3:
            display("(DS)",rollno);
            break;
        case 4:
            display("(CS)",rollno);
            break;
        default:
            printf("\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\n\t\t\t\t\t  ");
            system("pause");
            system("cls");
            goto home;
    }
}

void display(char code[],char roll[])
{
    /*
        This function displays all the available
        users in a particular department that the
        user has chosen and send the mail to all
        the users that the user has entered
    */

    //Command to clear the screen
    system("cls");

    int i;
    int j;
    int t;
    int n;

    char from_add[65];
    char sub[1000];
    char body[100000];
    char line[65];
    char path[45];
    char choice[3];

    FILE *f;
    FILE *f1;

home:

    //Command to clear the input buffer
    fflush(stdin);

    f = fopen("USERS.txt","r");

    printf("\n\n");
    printf("\t AVAILABLE USERS :\n\n");

    //Loop to display all the available users in the department chosen by the user
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,code))
        {
            printf("\t\t %d. %s",i,line);
            i++;
        }
        if(strstr(line,roll))
        {
            strcpy(from_add,line);
        }
    }

    fclose(f);

    printf("\n");

    printf("\t ENTER NUMBER OF RECEPIENTS TO SEND MAIL : ");

    t = 0;

    //If condition to check whether the input given by the user is a number and lies within the given range
    if(scanf("%d",&n))
    {
        if(n > 0 && n < i)
        {
            goto down;
        }
        else
        {
            t = 1;
        }
    }
    else
    {
        t = 1;
    }

    //Displays INVALID NUMBER OF USERS if the Flag variable is 1
    if(t == 1)
    {
        printf("\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\t\t\t\t\t  *   INVALID NUMBER OF USRES !!!    *\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        goto home;
    }

down: ;

    char user[n][7];

    printf("\n");

    //Getting the user-name of all the accounts that the user to which the wants to send mail
    for(i = 0; i < n; i++)
    {
        fflush(stdin);

        printf("\t ROLL NUMBER OF RECEPIENT %2d : ",i+1);
        gets(user[i]);

        for(j = 0; j < 7; j++)
        {
            user[i][j] = toupper(user[i][j]);
        }
    }

    system("cls");

    fflush(stdin);

    /*
        This part displays the from address
        and prompts the user to enter the subject
        and description of the mail
    */

    printf("\n\n\n\n");
    printf("\t\t FROM        : %s\n",from_add);
    printf("\t\t SUBJECT     : ");
    gets(sub);
    printf("\n");
    printf("\t\t DESCRIPTION : ");
    gets(body);
    printf("\n\n");

    /*
        This part of the function opens the file of the
        user to whom the logged in user wants to send mail
        and writes the mail, and displays the message whether
        the mail was delivered or not.
        It also writes the mail in the logged in users file to
        have a copy of the sent mail.
    */

    sprintf(path,"%s.txt",roll);
    f1 = fopen(path,"a");

    for(i = 0; i < n; i++)
    {
        t = 0;

        f = fopen("USERS.txt","r");

        while(fgets(line,sizeof(line),f))
        {
            if(strstr(line,user[i]))
            {
                t = 1;
            }
        }
        fclose(f);

        sprintf(path,"%s.txt",user[i]);

        if(t == 1)
        {
            if(i == 0)
            {
                fprintf(f1,"\n");
                fputs("TO          : ",f1);
            }

            f = fopen(path,"a");

            fprintf(f,"\n");
            fputs("FROM        : ",f);
            fputs(from_add,f);
            fputs("SUBJECT     : ",f);
            fputs(sub,f);
            fprintf(f,"\n");
            fputs("DESCRIPTION : ",f);
            fputs(body,f);
            fprintf(f,"\n");

            fclose(f);

            printf("\t\t\t\t\t  *************************************\n");
            printf("\t\t\t\t\t  *    SENT SUCCESSFULLY TO %s    *\n", user[i]);
            printf("\t\t\t\t\t  *************************************\n");
            printf("\n");

            fputs(user[i],f1);
            fprintf(f1," ");
        }
        else
        {
            printf("\t\t\t\t\t  *************************************\n");
            printf("\t\t\t\t\t  *     %s DOES NOT EXIST !!!     *\n", user[i]);
            printf("\t\t\t\t\t  *************************************\n");
            printf("\n");
        }
    }

    fprintf(f1,"\n");
    fputs("TUBJECT     : ",f1);
    fputs(sub,f1);
    fprintf(f1,"\n");
    fputs("TESCRIPTION : ",f1);
    fputs(body,f1);
    fprintf(f1,"\n");

    fclose(f1);

    printf("\t\t\t\t\t  ");
    system("pause");
    system("cls");
    options(roll);
}

void readm(char roll[])
{
    /*
        This function displays all the available
        options inside read - new mail, old mail and
        sent mail then directs the user to the corresponding
        function
    */

    //Command to clear the screen
    system("cls");

    int choice;

home:

    //Command to clear the input buffer
    fflush(stdin);

    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *            AMCS MAIL             *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    1. NEW MAIL                   |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    2. READ MAIL                  |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    3. SENT MAIL                  |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |    4. GO BACK                    |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n\n");

    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            newm(roll);
            break;
        case 2:
            oldm(roll);
            break;
        case 3:
            sent(roll);
            break;
        case 4:
            options(roll);
            break;
        default:
            printf("\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\n\t\t\t\t\t  ");
            system("pause");
            system("cls");
            goto home;
    }
}

void newm(char roll[])
{
    /*
        This function displays all the
        new messages that the user has
        received
    */

    //Command to clear the screen
    system("cls");

    int i;
    int n;
    int ind;
    int t;

    char line[100000];
    char path[45];
    char to[7];
    char rs[10000];
    char rd2[10000];

    FILE *f;
    sprintf(path,"%s.txt",roll);

home:

    //Command to clear the input buffer
    fflush(stdin);

    f = fopen(path,"r");

    printf("\n\n\n");

    //Loop to display the abstract of all the new messages(From and Subject)
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FROM        : "))
        {
            printf("\t\t  %4d. %s",i,line);
            i++;
        }
        if(strstr(line,"SUBJECT     : "))
        {
            printf("\t\t        %s\n",line);
        }
    }
    fclose(f);

    //This if statement is executed if the user does not have any new mail
    if(i == 1)
    {
        fflush(stdin);

        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *       YOU HAVE NO NEW MAILS       *\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        readm(roll);
    }

    printf("\n\t\t\t\t  ENTER MAIL NUMBER TO OPEN : ");
    scanf("%d",&n);

    f = fopen(path,"r+");

    t = 0;

    //Loop to open the complete mail that the user has chosen
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FROM        : "))
        {
            if(i == n)
            {
                system("cls");
                printf("\n\n\n");
                strcpy(to,line);
                ind = (strlen(line)) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"X");
                fseek(f,(ind * -1) - 1,SEEK_CUR);
                printf("\t\t  %s\n",line);
                t = 1;
            }
        }
        if(strstr(line,"SUBJECT     : "))
        {
             if(i == n)
             {
                strcpy(rs,line);
                ind = (strlen(line) + 1) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"R");
                fseek(f,(ind * -1) - 1,SEEK_CUR);
                printf("\t\t  %s\n",line);
             }
        }
        if(strstr(line,"DESCRIPTION : "))
        {
            if(i == n)
             {
                strcpy(rd2,line);
                ind = (strlen(line) + 1) * -1;
                fseek(f,ind,SEEK_CUR);
                fprintf(f,"R");
                fseek(f,(ind * -1) - 1,SEEK_CUR);
                printf("\t\t  %s\n",line);
             }
            i++;
        }
    }
    to[strlen(to) + 1] = '\0';

    fclose(f);

    //if condition that executed when the user enters a invalid mail number
    if(t == 0)
    {
        printf("\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        goto home;
    }

    //Calls the further() function that provides the user with options to reply to a mail or delete a mail
    further(to,rs,rd2,roll,count(roll,n));
}

void oldm(char roll[])
{
    /*
        This function displays all the
        messages that the user has
        already read
    */

    //Command to clear the screen
    system("cls");

    int i;
    int n;
    int t;

    char line[100000];
    char path[45];
    char to[7];
    char rs[10000];
    char rd2[10000];

    FILE *f;
    sprintf(path,"%s.txt",roll);

home:

    //Command to clear the input buffer
    fflush(stdin);

    f = fopen(path,"r");

    printf("\n\n\n");

    //Loop to display the abstract of all the read messages(From and Subject)
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FXOM        : "))
        {
            line[1] = 'R';
            printf("\t\t  %4d. %s",i,line);
            i++;
        }
        if(strstr(line,"RUBJECT     : "))
        {
            line[0] = 'S';
            printf("\t\t        %s\n",line);
        }
    }

    fclose(f);

    //This if statement is executed if the user does not have any read mail
    if(i == 1)
    {
        fflush(stdin);

        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *      YOU HAVE NO READ MAILS       *\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        readm(roll);
    }

    printf("\n\t\t\t\t  ENTER MAIL NUMBER TO OPEN : ");
    scanf("%d",&n);

    f = fopen(path,"r");

    t = 0;

    //Loop to open the complete mail that the user has chosen
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FXOM        : "))
        {
            if(i == n)
            {
                system("cls");
                printf("\n\n\n");
                line[1] = 'R';
                strcpy(to,line);
                printf("\t\t  %s\n",line);
                t = 1;
            }
        }
        if(strstr(line,"RUBJECT     : "))
        {
            if(i == n)
            {
                line[0] = 'S';
                strcpy(rs,line);
                printf("\t\t  %s\n",line);
            }
        }
        if(strstr(line,"RESCRIPTION : "))
        {
            if(i == n)
            {
                line[0] = 'D';
                strcpy(rd2,line);
                printf("\t\t  %s",line);
            }
            i++;
        }
    }
    to[strlen(to) + 1] = '\0';

    fclose(f);

    //if condition that executed when the user enters a invalid mail number
    if(t == 0)
    {
        printf("\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        goto home;
    }

    //Calls the further() function that provides the user with options to reply to a mail or delete a mail
    further(to,rs,rd2,roll,count(roll,n));
}

void sent(char roll[])
{
    /*
        This function displays all the
        messages that the user has
        sent to others
    */

    system("cls");

    int i;
    int n;
    int t;

    char line[100000];
    char path[45];
    char to[7];
    char rs[10000];
    char rd2[10000];

    FILE *f;
    sprintf(path,"%s.txt",roll);

home:

    fflush(stdin);

    f = fopen(path,"r");

    printf("\n\n\n");

    //Loop to display the abstract of all the sent messages(From and Subject)
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"TO          : "))
        {
            printf("\t\t  %4d. %s",i,line);
            i++;
        }
        if(strstr(line,"TUBJECT     : "))
        {
            line[0] = 'S';
            printf("\t\t        %s\n",line);
        }
    }

    fclose(f);

    //This if statement is executed if the user does not have any sent mail
    if(i == 1)
    {
        fflush(stdin);

        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *      YOU HAVE NO SENT MAILS       *\n");
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        readm(roll);
    }

    printf("\n\t\t\t\t  ENTER MAIL NUMBER TO OPEN : ");
    scanf("%d",&n);

    f = fopen(path,"r");

    t = 0;

    //Loop to open the complete mail that the user has chosen
    i = 1;
    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"TO          : "))
        {
            if(i == n)
            {
                system("cls");
                printf("\n\n\n");
                strcpy(to,line);
                printf("\t\t  %s\n",line);
                t = 1;
            }
        }
        if(strstr(line,"TUBJECT     : "))
        {
            if(i == n)
            {
                line[0] = 'S';
                strcpy(rs,line);
                printf("\t\t  %s\n",line);
            }
        }
        if(strstr(line,"TESCRIPTION : "))
        {
            if(i == n)
            {
                line[0] = 'D';
                strcpy(rd2,line);
                printf("\t\t  %s",line);
            }
            i++;
        }
    }
    to[strlen(to) + 1] = '\0';

    fclose(f);

    //if condition that executed when the user enters a invalid mail number
    if(t == 0)
    {
        printf("\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
        printf("\t\t\t\t\t  ************************************\n");
        printf("\n\t\t\t\t\t  ");
        system("pause");
        system("cls");
        goto home;
    }
    printf("\n\t\t\t\t\t  ");
    system("pause");
    system("cls");
    readm(roll);
}

void further(char to[],char rs[],char rd2[],char roll[],int n)
{
    /*
        This function that provides the user
        with options to reply to a mail or
        delete a mail
    */

    int t;
    int c;
    int i;
    int choice;

    char rpl[1000];
    char rd1[1000];
    char body[100000];

    t = 0;
    c = 0;

    //Extracting the to address
    for(i = 0; t < 6; i++)
    {
        if(to[i] == ':' || c == 1)
        {
            if(c == 0)
            {
                i++;
                c = 1;
            }
            else
            {
                to[t] = to[i];
                t++;
            }
        }
    }
    to[t] = '\0';

    t = 0;
    c = 0;

    //Extracting the content of the subject
    for(i = 0; i < strlen(rs) - 1; i++)
    {
        if(rs[i] == ':' || c == 1)
        {
            if(c == 0)
            {
                i++;
                c = 1;
            }
            else
            {
                rs[t] = rs[i];
                t++;
            }
        }
    }
    rs[t] = '\0';

    t = 0;
    c = 0;

    //Extracting the content of the description
    for(i = 0; i < strlen(rd2) - 1; i++)
    {
        if(rd2[i] == ':'|| c == 1)
        {
            if(c == 0)
            {
                i++;
                c = 1;
            }
            else
            {
                rd2[t] = rd2[i];
                t++;
            }
        }
    }
    rd2[t] = '\0';

    fflush(stdin);

    printf("\n\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *            AMCS MAIL             *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  1. REPLY                        |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  2. DELETE                       |\n");
    printf("\t\t\t\t\t  |                                  |\n");
    printf("\t\t\t\t\t  |  3. GO BACK                      |\n");
    printf("\t\t\t\t\t  |__________________________________|\n\n\n");

    printf("\t\t\t\t\t  ENTER YOUR CHOICE : ");
    scanf("%d",&choice);

    /*
        -> Case 1 - Gets the Subject and Description for reply and hands over the control to reply() function
        -> Case 2 - Calls deletem() function that deletes the mail
        -> Case 3 - Redirects to readm() function
    */

    switch(choice)
    {
        case 1:
            system("cls");
            fflush(stdin);
            sprintf(rpl,"REPLY TO (%s)",rs);
            printf("\n\n\n");
            printf("\n\t\t SUBJECT     : %s\n",rpl);
            printf("\n\t\t DESCRIPTION : ");
            gets(rd1);
            sprintf(body,"REPLY TO (%s), %s",rd2,rd1);
            reply(to,rpl,body,rd2,roll);
            break;
        case 2:
            deletem(roll,n);
            break;
        case 3:
            readm(roll);
            break;
        default:
            printf("\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\t\t\t\t\t  *        INVALID CHOICE !!!        *\n");
            printf("\t\t\t\t\t  ************************************\n");
            printf("\n\t\t\t\t\t  ");
            system("pause");
            system("cls");
            readm(roll);
    }
}

void reply(char user[],char sub[],char body[],char rd[],char roll[])
{
    /*
        This function is used to send
        the reply to a particular mail
        that the user has selected.
    */

    int t;

    char path[45];
    char from_add[65];
    char line[65];

    FILE *f;
    FILE *f1;

    f = fopen("USERS.txt","r");

    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,roll))
            strcpy(from_add,line);
    }

    fclose(f);

    t = 0;

    f = fopen("USERS.txt","r");

    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,user))
        {
            t = 1;
        }
    }
    fclose(f);

    sprintf(path,"%s.txt",user);
    f = fopen(path,"a");

    sprintf(path,"%s.txt",roll);
    f1 = fopen(path,"a");

    printf("\n\n");

    if(t == 1)
    {
        //Writes the content to the users own file(a copy of sent mail)
        fprintf(f1,"\n");
        fputs("TO          : ",f1);
        fputs(user,f1);
        fprintf(f1,"\n");
        fputs("TUBJECT     : ",f1);
        fputs(sub,f1);
        fprintf(f1,"\n");
        fputs("TESCRIPTION : ",f1);
        fputs(body,f1);
        fprintf(f1,"\n");

        fclose(f1);

        //Writes the content in the file of the user who has sent the message to the logged-in user
        fprintf(f,"\n");
        fputs("FROM        : ",f);
        fputs(from_add,f);
        fputs("SUBJECT     : ",f);
        fputs(sub,f);
        fprintf(f,"\n");
        fputs("DESCRIPTION : ",f);
        fputs(body,f);
        fprintf(f,"\n");

        fclose(f);

        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *    SENT SUCCESSFULLY TO %s    *\n",user);
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n");
    }
    else
    {
        printf("\t\t\t\t\t  *************************************\n");
        printf("\t\t\t\t\t  *     %s DOES NOT EXIST !!!     *\n",user);
        printf("\t\t\t\t\t  *************************************\n");
        printf("\n");
    }
    printf("\t\t\t\t\t  ");
    system("pause");
    system("cls");
    readm(roll);
}

void changepwd(char rollno[])
{
    /*
        This function changes the
        password of the user
    */

    //Command to clear the screen
    system("cls");

    int i;

    char line[999];
    char pwd[20];
    char path[45];
    char t;

    FILE *f;
    sprintf(path,"%s.txt",rollno);
    f = fopen(path,"r+");

    fflush(stdin);

    printf("\n\n\n");
    printf("\n\t\t\t\t\t  ENTER NEW PASSWORD : ");

    //Loop to get the new password from the user
    i = 0;
    while(t != '\r')
    {
        t = getch();
        if(t == '\b' && i > 0)
        {
            i--;
            putch(t);
            putch(' ');
            putch(t);
        }
        else if(t != '\r' && t != '\b')
        {
            putch('*');
            pwd[i] = t;
            i++;
        }
    }
    pwd[i]='\0';

    //Resets the password
    fputs("!!!!!!!!!!!!!!!!!!!!",f);

    fclose(f);

    //Opens the file in read and write mode
    f = fopen(path,"r+");

    //Updates the new password in the file
    fputs(pwd,f);

    fclose(f);

    printf("\n\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\t\t\t\t\t  *  PASSWORD CHANGED SUCCESSFULLY   *\n");
    printf("\t\t\t\t\t  ************************************\n");
    printf("\n\t\t\t\t\t  ");
    system("pause");
    system("cls");
    options(rollno);
}

int count(char roll[],int i)
{
    /*
        This function will be invoked by
        deletem() function to return the position
        of the mail to be deleted
    */

    int c;
    int t;

    char path[45];
    char line[10000];

    FILE *f;

    sprintf(path,"%s.txt",roll);
    f = fopen(path,"r+");

    c = 1;
    t = 0;

    while(fgets(line,sizeof(line),f))
    {
        if(strstr(line,"FXOM        :"))
        {
            c++;
        }
        if(strstr(line,"FROM        :"))
        {
            t++;
        }
        if(t == (i-1))
        {
            break;
        }
    }

    fclose(f);

    return c;
}

void deletem(char roll[],int n)
{
    /*
        This function is to delete
        the message that the user has
        selected
    */

    int i=1;
    int ind=0;
    int k;

    char body[10000];
    char path[45];

    FILE *f;

    sprintf(path,"%s.txt",roll);
    f = fopen(path,"r+");

    //Loop to replace the mail with blank-space(Delete the mail)
    while(fgets(body,sizeof(body),f))
    {
        if(strstr(body,"FXOM        :"))
        {
            if(i == n)
            {
                ind = (strlen(body)+1) * -1;
                fseek(f,ind,SEEK_CUR);
                for(k = 0; k < (-1 * ind) - 2; k++)
                {
                    fputs(" ",f);
                }
                fseek(f,0,SEEK_CUR);
            }
        }
        if(strstr(body,"RUBJECT     :"))
        {
            if(i == n)
            {
                ind = (strlen(body)+1) * -1;
                fseek(f,ind,SEEK_CUR);
                for(k = 0; k < (-1 * ind) - 2; k++)
                {
                    fputs(" ",f);
                }
                fseek(f,0,SEEK_CUR);
            }
        }
        if(strstr(body,"RESCRIPTION :"))
        {
            if(i == n)
            {
                ind = (strlen(body)+1) * -1;
                fseek(f,ind,SEEK_CUR);
                for(k = 0; k < (-1 * ind) - 2; k++)
                {
                    fputs(" ",f);
                }
                fseek(f,0,SEEK_CUR);
            }
            i++;
        }
    }

    fclose(f);

    printf("\n\n");
    printf("\t\t\t\t\t  *************************************\n");
    printf("\t\t\t\t\t  *          MESSAGE DELETED          *\n");
    printf("\t\t\t\t\t  *************************************\n");
    printf("\n\t\t\t\t\t  ");
    system("pause");
    system("cls");
    readm(roll);
}

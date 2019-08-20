/***************************************************************************************************
====================================================================================================
PROGRAM NAME : STUDENT MARKSHEET
DESIGNER     : ARABIND MEHER
DESCRIPTION  : IT TAKES THE STUDENT DETAILS AND GENERATE THE MARKSHEET
====================================================================================================
****************************************************************************************************/

/**HEADER FILES**/
#include<iostream>      //FOR INPUT/OTPUT STREAM
#include<stdio.h>       //FOR STANDRD INPUT/OUTPUT
#include<conio.h>       //FOR CONSOLE INPUT/OUTPUT
#include<stdlib.h>      //FOR STANDARD LIBRARY
#include<string.h>      //FOR STRIGR FUNCTIONS
#include<time.h>        //FOR DATE AND TIME FUNCTION

void displayDate_Time();
/**TO DISPLAY DATE AND TIME**/

class studentDetails
/**TO STORE ALL THE DETAILS OF STUDENT & FUNCTIONS FOR PROGRAM**/
{
    char name[50];              //NAME
    int roll;                   //ROLL NUMBER
    float mark[5];              //MARK IN 5 DIFFRENT SUBJECT
    float totalMark;            //TOTAL MARK
    float percent;              //PERCENTAGE
    char subject[5][20];        //SUBJECT
    char subjectCode[5][5];     //SUBJECT CODE
    char subjectGrade[5][3];    //GRADE IN DIFFRENT SUBJECT
    char overalGrade[3];        //OVERAL GRADE
    char result[5];             //RESULT

public:
    void enterStudentDetail()
    /**TO ENTER THE DETAILS OF STUDENT**/
    {
        std::cout<<"Student Name     : ";
        gets(name);
        //TO ENTER THE NAME OF THE STUDENT
        std::cout<<"\nStudent Roll No. : ";
        scanf("%d",&roll);
        //TO ENTER THE ROLL NUMBER OF THE STUDENT
        std::cout<<"\n\n";
    }

    void enterSubjectDetail()
    /**TO ENTER THE SUBJECT DETAILS OF THE STUDENT**/
    {
        int index;
        //TO MANAGE THE ARRAY

        //COMPULSARY SUBJECTS
        strcpy(subject[0],"English");
        strcpy(subject[1],"Physics");
        strcpy(subject[2],"Chemistry");

        //COMPULSARY SUBJECT CODE
        strcpy(subjectCode[0],"E007");
        strcpy(subjectCode[1],"P007");
        strcpy(subjectCode[2],"C009");

        //DISPLAYING COMPULSARY SUBJECT LIST
        std::cout<<"Subject List :-\n";
        std::cout<<"English - E007\n";
        std::cout<<"Physics - P007\n";
        std::cout<<"Chemistry - C009\n\n";

        //DISPLAYING FIRST OPTIONAL SUBJECT LIST
        std::cout<<"First Optional :-\n";
        std::cout<<"Mathematics - M011\n";
        std::cout<<"Biology - B007\n\n";
        std::cout<<"Enter your first optional subject code :\n";

        //TO ENTER THE FIRST OPTIONAL CODE
        re1:
        std::cout<<"----->> ";
        std::cin>>subjectCode[3];

        //CHECK IF ENTERED SUBJECT CODE IS CORRECT OR NOT
        //IF CORRECT THEN ASSIGN THE SUBJECT
        if(strcmp(subjectCode[3],"M011")==0)
            strcpy(subject[3],"Mathematics");
        else if(strcmp(subjectCode[3],"B007")==0)
            strcpy(subject[3],"Biology");
        else
        {
            //IF THE ENTERED SUBJECT CODE IS IN CORRECT
            std::cout<<"error\n";
            goto re1;
        }

        //IF THE FIRST OPTIONAL IS MATHEMATICS
        if(strcmp(subjectCode[3],"M011")==0)
        {
            //TO DISPLAY THE SECOND OPTIONAL
            std::cout<<"\nSecond Optional :-\n";
            std::cout<<"Biology - B007\n";
            std::cout<<"Computer Science - C015\n";
            std::cout<<"Physical Education - P017\n\n";
            std::cout<<"Enter your second optional subject code :\n";

            //TO ENTER THE FIRST OPTIONAL CODE
            re2:
            std::cout<<"----->> ";
            std::cin>>subjectCode[4];

            //CHECK IF ENTERED SUBJECT CODE IS CORRECT OR NOT
            //IF CORRECT THEN ASSIGN THE SUBJECT
            if(strcmp(subjectCode[4],"B007")==0)
                strcpy(subject[4],"Biology");
            else if(strcmp(subjectCode[4],"C015")==0)
                strcpy(subject[4],"Computer Science");
            else if(strcmp(subjectCode[4],"P017")==0)
                strcpy(subject[4],"Physical Education");
            else
            {
                //IF THE ENTERED SUBJECT CODE IS IN CORRECT
                std::cout<<"error\n";
                goto re2;
            }
        }

        //IF THE FIRST OPTIONAL IS BIOLOGY
        else if(strcmp(subjectCode[3],"B007")==0)
        {
            //TO DISPLAY THE OPTIONAL
            std::cout<<"\nSecond Optional :-\n";
            std::cout<<"Mathematics - M011\n";
            std::cout<<"Computer Science - C015\n";
            std::cout<<"Physical Education - P017\n\n";
            std::cout<<"Enter your second optional subject code :\n";

            //TO ENTER THE SECOND OPTIONAL CODE
            re3:
            std::cout<<"----->> ";
            std::cin>>subjectCode[4];

            //CHECK IF ENTERED SUBJECT CODE IS CORRECT OR NOT
            //IF CORRECT THEN ASSIGN THE SUBJECT
            if(strcmp(subjectCode[4],"M011")==0)
                strcpy(subject[4],"Mathematics");
            else if(strcmp(subjectCode[4],"C015")==0)
                strcpy(subject[4],"Computer Science");
            else if(strcmp(subjectCode[4],"P017")==0)
                strcpy(subject[4],"Physical Education");
            else
            {
                //IF THE ENTERED SUBJECT CODE IS IN CORRECT
                std::cout<<"error\n";
                goto re3;
            }
        }
    }

    void enterMarksDetail()
    /**TO ENTER THE MARK DETAIL OF THE STUDENT**/
    {
        re1:
        //TO CLEAR THE SCREEN
        system("CLS");

        int index, check, check2;

        std::cout<<"Enter your Marks :-\n\n";
        for(index=0; index<5; index++)
        {
            std::cout<<subject[index]<<" : ";
            std::cin>>mark[index];
            std::cout<<"\n";
        }
        std::cout<<"\n";
        std::cout<<"Check whether the detail is correct or not.\n";
        std::cout<<"0 - To re enter the data.\n";
        std::cout<<"1 - To continue with the same data.\n";

        re2:
        std::cout<<"----->> ";
        std::cin>>check;

        if(check==1)
        {
            std::cout<<"\nPlease pres any key to get the mark-sheet.";
            getch();
        }
        else if(check==0)
            goto re1;
        else
            goto re2;

        check2=checkDetails();

        if(check2)
        {
            system("CLS");

            std::cout<<"\tERROR 406 - NOT ACCEPTABLE\n";
            std::cout<<"\tPLEASE ENTER AN VALID INPUT\n";
            std::cout<<"\n\tPRESS ANY KEY TO CONTINUE\n";

            getch();

            goto re1;
        }
    }

    int checkDetails()
    {
        int index, flag=0;

        for(index=0; index<5; index++)
            if(mark[index]<0 || mark[index]>100)
            {
                flag=1;
                break;
            }
        return flag;
    }

    void manipulateDetails()
    {
        int index;

        for(index=0; index<5; index++)
        {
            if(mark[index]>90)
                strcpy(subjectGrade[index],"A+");
            else if(mark[index]>80 && mark[index]<=90)
                strcpy(subjectGrade[index],"A");
            else if(mark[index]>70 && mark[index]<=80)
                strcpy(subjectGrade[index],"B+");
            else if(mark[index]>60 && mark[index]<=70)
                strcpy(subjectGrade[index],"B");
            else if(mark[index]>50 && mark[index]<=60)
                strcpy(subjectGrade[index],"C");
            else if(mark[index]>40 && mark[index]<=50)
                strcpy(subjectGrade[index],"D");
            else if(mark[index]>33 && mark[index]<=40)
                strcpy(subjectGrade[index],"E");
            else if(mark[index]>=0 && mark[index]<=33)
                strcpy(subjectGrade[index],"F");
        }

        totalMark=0;
        for(index=0; index<5; index++)
            totalMark+=mark[index];


        percent=totalMark/5;

        if(percent>90)
            strcpy(overalGrade,"A+");
        else if(percent>80 && percent<=90)
            strcpy(overalGrade,"A");
        else if(percent>70 && percent<=80)
            strcpy(overalGrade,"B+");
        else if(percent>60 && percent<=70)
            strcpy(overalGrade,"B");
        else if(percent>50 && percent<=60)
            strcpy(overalGrade,"C");
        else if(percent>40 && percent<=50)
            strcpy(overalGrade,"D");
        else if(percent>33 && percent<=40)
            strcpy(overalGrade,"E");
        else if(percent>=0 && percent<=33)
            strcpy(overalGrade,"F");

        if(strcmp(overalGrade,"F")==0)
            strcpy(result,"FAIL");
        else
            strcpy(result,"PASS");
    }

    void displayMarksheet()
    {
        system("CLS");

        int index, length;

        printf("       CENTRAL BOARD OF SECONDARY EDUCATION\n\n");
        printf("\t\tSTUDENT MARKSHEET\n\n\n");

        displayDate_Time();

        printf("  Name     : %s\n",name);
        printf("  Roll No. : %d\n\n",roll);

        printf("|-----------------------------------------------------|\n");
        printf("| CODE | SUBJECT            | MARK   | OUT OF | GRADE |\n");
        printf("|-----------------------------------------------------|\n");

        for(index=0; index<5; index++)
        {
            printf("| %s | %s", subjectCode[index], subject[index]);
            length=strlen(subject[index]);
            space(length);

            printf("| %6.2f |    100 | %s    ", mark[index], subjectGrade[index]);
            length=strlen(subjectGrade[index]);
            gradeSpace(length);
            printf("|\n");
        }

        printf("|-----------------------------------------------------|\n");
        printf("|      | TOTAL MARK         | %6.2f |    500 |       |\n", totalMark);
        printf("|      | PERCENTAGE         | %6.2f |    100 |       |\n", percent);

        printf("|-----------------------------------------------------|\n");
        printf("|      | OVERAL GRADE       | %s                      ", overalGrade);
        length=strlen(overalGrade);
        gradeSpace(length);
        printf("|\n");

        printf("|-----------------------------------------------------|\n");
        printf("|      | RESULT             | %s                    |\n", result);

        printf("|-----------------------------------------------------|\n");
    }

    void space(int length)
    {
        int index, freeSpace=20-length-1;
        for(index=0; index<freeSpace; index++)
            printf(" ");
    }

    void gradeSpace(int length)
    {
        if(length==1)
            printf(" ");
    }

}student;

int main()
{
    std::cout<<"CBSE Student Portal\n\n";

    student.enterStudentDetail();

    student.enterSubjectDetail();

    student.enterMarksDetail();

    student.manipulateDetails();

    student.displayMarksheet();

    getch();

    return EXIT_SUCCESS;
}

void displayDate_Time()
{
    time_t rawDate;
    time_t rawTime;

    struct tm *dateInfo;
    struct tm *timeInfo=localtime(&rawTime);

    char buffer[80];

    time(&rawDate);
    dateInfo=localtime(&rawDate);

    strftime(buffer,80,"  DATE : %d-%m-%y\t", dateInfo);
    printf("%s",buffer);

    printf("      TIME : %02d:%02d:%02d\n\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}

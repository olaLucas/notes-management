#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct student
{
    char name[150];

    int attendanceNumber;

    float grade1;
    float grade2;
    float grade3;
    float grade4;
    float participationGrade;

    float average;

    char situation[30];

    int absents;
};

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

void toList(struct student students[40])
{
    system("clear");

    int total = 0; 

    printf("\n |=====================| LIST REGISTERS |=====================| \n");

    for (int i = 0; i <= 39; i++)
    {
        if (students[i].attendanceNumber > 0)
        {
            total++;

            printf("\n ---------------------| STUDENT: %d |-------------------- \n", students[i].attendanceNumber);

            printf("Name: %s \n\n", students[i].name);

            printf("Grade 1: %f \n", students[i].grade1);
            printf("Grade 2: %f \n", students[i].grade2);
            printf("Grade 3: %f \n", students[i].grade3);
            printf("Grade 4: %f \n", students[i].grade4);
            printf("Participation grade: %f \n\n", students[i].participationGrade);

            printf("Average: %f \n", students[i].average);

            printf("Situation: %s \n\n", students[i].situation);

            printf("Absents: %d \n", students[i].absents);

            printf("\n ---------------------| REGISTER END |-------------------- \n");
        }
    }
    printf("\nTotal of students registered: %d\n\n", total);
    cleanBuffer();
    getchar();
}

float average(struct student students[40], int i)
{
    char* pointer[30] = {students[i].situation};
    float average = 0;

    average = (students[i].grade1 + students[i].grade2 + students[i].grade3 + students[i].grade4 + students[i].participationGrade) / 5;

    if (average >= 5 && students[i].absents < 50)
    {   
        strcpy(*pointer, "APPROVED");
    }
    else if (average < 5 || students[i].absents >= 50)
    {
        strcpy(*pointer, "REPROVED");
    }

    return average;
}

struct student toRegister(struct student students[40], int i, int j, int n, bool mode, bool* repetition)
{   
    // i = studentsNum
    // j = studentsAmount
    // n = newStudents 
    //mode  true = alphabetical and false = numerical

    j--;

    if (mode == true)
    {
        i = 0;

        if (repetition == true)
        {
            i = j;
            j = j + n;
        }
    }
    else if(mode == false)
    {
        i--;
        j = i;
    }

    for (i ; i <= j; i++)
    {

        if (students[i].attendanceNumber <= 0 || students[i].attendanceNumber != students[i].attendanceNumber)
        {
            students[i].attendanceNumber = i + 1;
            printf("\t------------------------ \n\n");

            printf("\nInsert the informations about the student number %d \n\n", students[i].attendanceNumber);

            printf("Name: ");
            scanf("%s", &students[i].name);

            printf("\nGrade 1: ");
            scanf("%f", &students[i].grade1);

            printf("\nGrade 2: ");
            scanf("%f", &students[i].grade2);

            printf("\nGrade 3: ");
            scanf("%f", &students[i].grade3);

            printf("\nGrade 4: ");
            scanf("%f", &students[i].grade4);

            printf("\nParticipation grade: ");
            scanf("%f", &students[i].participationGrade);

            printf("\nAbsents: ");
            scanf("%d", &students[i].absents);

            students[i].average = average(students, i);

            *repetition = true;

            printf("\n \t |=====================| REGISTER CONCLUED |=====================| \n\n");
        }
        else
        {
            if (mode == true)
            {
                j++;
            }
            else
            {
                printf("This number is already in use! Make sure that you're registering the right student. \n\n");
                cleanBuffer();
                getchar();
            }
        }
    }

    return students[40];
}

bool verification(int value)
{
    bool validation = true;

    if (value <= 0)
    {
        printf("\n \t******************\n\n");

        printf("Register cancelled. 0 students wanted to register or invalid number typed. \n\n");
        printf("Number typed: %d \n\n", value);

        printf("Returning to menu... \n\n");

        printf("\n\t******************\n\n");

        cleanBuffer();
        getchar();
        
        system("clear");

        validation = false;
    }
    else if (value > 39)
    {
        printf("\n\t|*********************| ERROR |*********************| \n\n");
        printf("Too many students, maximum amount is 40. \n\n");
        printf("Number typed: %d\n\n", value);

        printf("Returning to menu... \n\n");
        printf("\n\t|*********************| ERROR |*********************| \n\n");

        cleanBuffer();
        getchar();

        system("clear");

        validation = false;
    }

    return validation;
}

void registerQuantity(int* studentsAmount, struct student students[40])
{
    system("clear");

    int newStudents = {0};
    int selector = 0;
    int caseSelector = 0;
    int studentsNum = 0;
    bool mode = {0}; // true = alphabetical and false = numerical
    bool verify = false; 
    bool repetition = {0};

    printf("\n \t |=====================| REGISTER STUDENT |=====================| \n\n");

    do
    {   
        printf("Select the method to register your students:\n\n");
        printf("1. Alphabetical. \n");
        printf("2. Attendance Number. \n");
        printf("3. Exit.\n\n");

        printf(">>> ");
        scanf("%d", &caseSelector);

        printf("\t------------------------ \n\n");

        if (caseSelector != 3)
        {
            if (repetition == true)
            {
                

                printf("How many students you want to register?\n\n");
                printf(">>> ");
                scanf("%d", &newStudents);
                verify = verification(newStudents);
            }
            else
            {
                printf("How many students you want to register?\n\n");
                printf(">>> ");
                scanf("%d", &studentsAmount);
                verify = verification(studentsAmount);
            }
        }
        if (verify == true)
        {
            switch (caseSelector)
            {
            case 1:
                mode = true;
                toRegister(students, studentsNum, studentsAmount, newStudents, mode, &repetition);
                break;

            case 2:
                int cont = studentsAmount;
                cont--;

                mode = false;

                for (int i = 0; i <= cont; i++)
                {
                    printf("\t------------------------ \n\n");

                    printf("Insert the student's attendance number: \n\n");
                    printf(">>> ");
                    scanf("%d", &studentsNum);

                    verify = verification(studentsNum);

                    if(verify == true)
                    {
                        toRegister(students, studentsNum, studentsAmount, newStudents, mode, &repetition);
                    }
                }
                
                break;

            case 3:

                printf("Closing... \n\n");
                cleanBuffer();
                getchar();
                break;

            default:
                system("clear");
                printf("\t|*********************| ERROR |*********************| \n\n");
                printf("Invalid option typed. Please, try again. \n\n");
                cleanBuffer();
                getchar();
                break;
            } 
        }
           
    } while (caseSelector != 3);
}
    
int main()
{   
    int selector = 0;
    int studentsAmount = {0};
    struct student students[40] = {0};

    do
    {   
        system("clear");

        printf(" |=====================| MENU |=====================| \n\n");

        printf(" \t Welcome to the grade manager! \n\n");

        printf(" Please select an function: \n");
        printf(" 1. Register student. \n");
        printf(" 2. List students. \n");
        printf(" 3. Exit. \n\n");

        printf(">>> ");
        scanf("%d", &selector);

        switch (selector)
        {
        case 1:
            registerQuantity(&studentsAmount, students);
            break;

        case 2:
            if (studentsAmount >= 0)
            {
                toList(students);    
            }
            else
            {
                printf("|*********************| ERROR |*********************| \n\n");
                printf("None students registered\n\n");
                cleanBuffer();
                getchar();
            }
        
            break;

        case 3:
            printf("Closing... \n\n");
            system("pause");
            break;
    
        default:
            system("cls");
            printf("|*********************| ERROR |*********************| \n\n");
            printf("Invalid option typed. Please, try again. \n\n");
            system("pause");
            break;
        }

    } while (selector != 3);
}
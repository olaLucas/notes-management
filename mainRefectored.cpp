#include <string.h>
#include <iostream>
#include <stdbool.h>
#include <string.h>
using namespace std;

class Student
{
private:
    
    char name[150];

    int attendanceNumber;

    float grade1;
    float grade2;
    float grade3;
    float grade4;

    float average;

    char situation[30];

    int absents;

public:
    Student()
    {
        name;

        grade1 = 0;
        grade2 = 0;
        grade3 = 0;
        grade4 = 0;

        average;

        situation;

        absents = 0;
    }
    
    int letterNumber;
        
    void registerStudent();
    void defineLetterNumber();
    void defineAttendanceNumber(Student array[], int arraySize);
    void averageCalc();
    void showStudent();
    int findStudent(Student array[], int arraySize, int option);
    void deleteStudent(Student array[], int arraySize, int index);
    void changeData(Student array[], int arraySize, int index);
};

void cleanBuffer();
void sort(Student array[], int arraySize);

void Student::changeData(Student array[], int arraySize, int index)
{
    int selector, option = 0;

    do
    {
        cout << endl << " Select which information you want to change: " << endl;
        cout << " 1. Name" << " (Actual " << array[index].name << ")" << endl;
        cout << " 2. Grade 1" << " (Actual " << array[index].grade1 << ")" << endl;
        cout << " 3. Grade 2" << " (Actual " << array[index].grade2 << ")" << endl;
        cout << " 4. Grade 3" << " (Actual " << array[index].grade3 << ")" << endl;
        cout << " 5. Grade 4" << " (Actual " << array[index].grade4 << ")" << endl;

        cout << " 6. Absents" << "(Actual " << array[index].absents << ")" << endl;
        cout << " 7. Exit" << endl << endl << ">>> ";

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Digit the new name: ";
            cin >> array[index].name;
            selector = 7;
            break;
        
        case 2:
            cout << "Digit the new grade 1: ";
            cin >> array[index].grade1;
            selector = 7;
            break;

        case 3:
            cout << "Digit the new grade 2: ";
            cin >> array[index].grade2;
            selector = 7;
            break;

        case 4:
            cout << "Digit the new grade 3: ";
            cin >> array[index].grade3;
            selector = 7;
            break;

        case 5:
            cout << "Digit the new grade 4: ";
            cin >> array[index].grade4;
            selector = 7;
            break;

        case 6:
            cout << "Digit the new absents: ";
            cin >> array[index].absents;
            selector = 7;
            break;

        case 7:
            selector = 7;
            break;

        default:
            cout << "Invalid option selected. Please try again." << endl;
            getchar();
            break;
        }

    } while (selector != 7);

    if (option == 1)
    {
        array[index].defineLetterNumber();
        sort(array, arraySize);
    }
    else if (option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
    {
        array[index].averageCalc();
    }
}

void Student::deleteStudent(Student array[], int arraySize, int index)
{   
    array[index].name[0] = '\0';

    array[index].letterNumber = 999;
    array[index].attendanceNumber = 0;
    
    array[index].grade1 = 0;
    array[index].grade2 = 0;
    array[index].grade3 = 0;
    array[index].grade4 = 0;

    array[index].average = 0;

    array[index].situation[0] = '\0';

    array[index].absents = 0;
}

void Student::registerStudent()
{
    cout << endl << endl <<"Insert name: ";
    cin >> name;

    cout << endl << endl << "Insert grade 1: ";
    cin >> grade1;

    cout << endl << endl << "Insert grade 2: ";
    cin >> grade2;

    cout << endl << endl << "Insert grade 3: ";
    cin >> grade3;

    cout << endl << endl << "Insert grade 4: ";
    cin >> grade4;

    cout << endl << endl << "Student's absents: ";
    cin >> absents;

    averageCalc();
    defineLetterNumber();
}

void Student::averageCalc()
{
    int gradeAmounts = 4;

    if (grade1 > 10)
    {
        grade1 = 10;
    }
    if (grade2 > 10)
    {
        grade2 = 10;
    }
    if (grade3 > 10)
    {
        grade3 = 10;
    }
    if (grade4 > 10)
    {
        grade4 = 10;
    }

    average = (grade1 + grade2 + grade3 + grade4) / gradeAmounts;

    if (average > 4 && absents < 50)
    {
        strcpy(situation, "APPROVED");
    }
    else
    {
        strcpy(situation, "REPROVED");
    }
}

void Student::showStudent()
{
    cout << endl << " ---------------------| STUDENT:" << attendanceNumber << " |-------------------- " << endl;
    cout << "Name: " << name << endl;
    cout << "Number: " << attendanceNumber << endl;
    cout << "Grade 1: " << grade1 << endl;
    cout << "Grade 2: " << grade2 << endl;
    cout << "Grade 3: " << grade3 << endl;
    cout << "Grade 4: " << grade4 << endl;
    cout << "Average: " << average << endl;
    cout << "Situation: " << situation << endl;
    cout << "Absents: " << absents;
    cout << endl << " ---------------------| REGISTER END |-------------------- " << endl;
}

void Student::defineLetterNumber()
{
    int cont = 0;
    int index[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    int indexSize = sizeof(index)/sizeof(index[0]);

    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < indexSize; i++)
    {
        if (name[0] == alphabet[i])
        {
            letterNumber = index[i];
        }
    }
}

void Student::defineAttendanceNumber(Student array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        array[i].attendanceNumber = i + 1;
    }
}

int Student::findStudent(Student array[], int arraySize, int option)
{   
    bool status = false;
    char studentName[30];
    int selector = 0;
    int index = 0;

    if (arraySize < 1)
    {
        cout << "None students was registered." << endl;
        getchar();
    }
    else
    {
        cout << endl << "Insert the student's name: ";
        cin >> studentName;

        for (int i = 0; i < arraySize; i++)
        {
            if (strcmp(studentName, array[i].name) == 0)
            {
                index = i;
                status = true;
            }
        }

        if (status == true)
        {
            switch (option)
            {
            case 3:
                changeData(array, arraySize, index);
                break;
            
            case 4:
                deleteStudent(array, arraySize, index);
                sort(array, arraySize);
                break;
            
            default:
                cout << "Option error";
                getchar();
                break;
            }

            if (status == true && option == 4)
            {
                arraySize = arraySize - 1;
            }    
        }
        else
        {
            cout << endl << "Student didn't found. Please try again." << endl;
            cleanBuffer();
            getchar();
        }
    }
        
    return arraySize;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

void swap(Student array[], int i, int j)
{
    Student temp;

    temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void sort(Student array[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[i].letterNumber > array[j].letterNumber)
            {   
                swap(array, i, j);
            }
        }
    }

    Student function;
    function.defineAttendanceNumber(array, arraySize);
}

void showStudents(Student array[], int arraySize)
{
    if (arraySize < 1)
    {
        cout << "None students was registered." << endl;
        cleanBuffer();
        getchar();
    }
    else
    {
        for (int i = 0; i < arraySize; i++)
        {   
            array[i].showStudent();
        }

        cleanBuffer();
        getchar();
    }
}

int registerStudents(Student array[], int arraySize)
{
    int newArraySize = 0;
    cout << endl << "Amount of students to register: ";
    cin >> newArraySize;

    for (int i = arraySize; i < arraySize + newArraySize; i++)
    {
        array[i].registerStudent();
    }

    arraySize = arraySize + newArraySize;

    sort(array, arraySize);

    return arraySize;
}

int main(void)
{
    int selector = 0;
    int arraySize = 0;
    int option = 0;
    Student array[40];
    Student function;

    do
    {
        cout << " |=====================| MENU |=====================|" << endl << endl;
        cout << " \t Welcome to the grade manager! \n\n";
        cout << " Please select an function: \n";
        cout << " 1. Register student. \n";
        cout << " 2. List students. \n";
        cout << " 3. Change student's data \n";
        cout << " 4. Delete student \n";
        cout << " 5. Exit. \n\n";

        cout << "Select an option: " << endl << ">>> ";
        cin >> option;

        switch (option)
        {
        case 1:
            arraySize = registerStudents(array, arraySize);
            system("clear");
            break;
        
        case 2:
            showStudents(array, arraySize);
            system("clear");
            break;
        
        case 3: 
            function.findStudent(array, arraySize, option);
            system("clear");
            break;

        case 4:
            arraySize = function.findStudent(array, arraySize, option);
            system("clear");
            break;
        
        case 5:
            cout << "Exiting..." << endl << endl;
            selector = 3; 
            break;

        default:
            cout << "Option unavailable" << endl << endl;
            cout << "Press enter to continue..." << endl;
            getchar();
            break;
        }

    } while (selector != 3);
}
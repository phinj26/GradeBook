#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* The 20 elements represent the 20 students. The 100 subelements represent up to 100 grades the
teacher can put in for a quarter. This 2D matrix is where the information will be stored */

int Gradebook[20][100] = {};
int numGrades = 0;
string nameList[20];

void check(int stuID, int gradeID)
{
    cout << nameList[stuID - 1] << " got a "
         << Gradebook[stuID - 1][gradeID - 1]
         << " on grade " << gradeID << "." << endl;
}

double average(int stuID)
{
    if (numGrades == 0)
    {
        cout << "This student has no grades entered.";
        return 0;
    }

    double x = 0;
    int i = 0;

    while (i < numGrades)
    {
        x += Gradebook[stuID - 1][i];
        i++;
    }

    return x / numGrades;
}

int main()
{

    cout << "Welcome to your grade book! First, we will need to initialize your gradebook." << endl;
    cout << "The first step is to enter student names. The order you put them in will "
         << "correspond to their student ID." << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "Student " << i + 1 << "'s name is: ";
        getline(cin, nameList[i]);
    }

    int obj = 0;
    char scale;

    while (obj != 5)
    {
        cout << "\n========================" << endl;
        cout << "        GRADEBOOK" << endl;
        cout << "========================" << endl;
        cout << "1. Enter grades" << endl;
        cout << "2. Check a grade" << endl;
        cout << "3. Check a student average" << endl;
        cout << "4. Check all student averages" << endl;
        cout << "5. Exit" << endl;
        cout << "========================" << endl;
        cout << "Choose an option, 1-5. " << endl;
        cin >> obj;

        if (obj == 1)
        {
            if (numGrades == 100)
            {
                cout << "You have entered the limit of grades.";
            }
            else
            {
                string input;
                cout << "Enter the 20 grades separated by commas: ";
                getline(cin >> ws, input);

                stringstream ss(input);

                int i = 0;
                int score;
                char comma;

                while ((i < 20) && (ss >> score))
                {
                    if (i < 19)
                    {
                        ss >> comma;
                    }
                    if (score < 0 || score > 100)
                    {
                        cout << "WARNING: The grade you entered for student " << i+1 << " is not between 0 and 100." << endl;
                    }
                    Gradebook[i][numGrades] = score;
                    i++;
                }

                if (i == 20)
                {
                    numGrades++;
                }
                else
                {
                    int j = 0;
                    while (j < i)
                    {
                        Gradebook[j][numGrades] = 0;
                        j++;
                    }
                    cout << "You did not enter 20 grades. Make sure to enter a grade for every student." << endl;
                }
            }
        }
        else if (obj == 2)
        {

            cout << "Would you like to check grades for an individual student, or all students? (I or A)";
            cin >> scale;

            // Individual student, single grade
            if (scale == 'i' || scale == 'I')
            {
                int stuID;
                int gradeID;

                cout << "Which student's grade would you like to check?\n";
                cin >> stuID;

                if (stuID > 20 || stuID < 1)
                {
                    cout << "There is no student with this ID.";
                }
                else
                {
                    cout << "Which grade are you looking for?\n";
                    cin >> gradeID;

                    if (gradeID < 1 || gradeID > numGrades)
                    {
                        cout << nameList[stuID - 1]
                             << " does not have that grade.";
                    }
                    else
                    {
                        check(stuID, gradeID);
                    }
                }
            }
            // All students, single grade
            else if (scale == 'a' || scale == 'A')
            {
                int grade;

                cout << "Which grade would you like to check?" << endl;
                cin >> grade;

                if (grade < 1 || grade > numGrades)
                {
                    cout << "You have not entered this grade yet.";
                }
                else
                {
                    cout << "These were the scores for grade "
                         << grade << ":" << endl;

                    int i = 0;

                    while (i < 20)
                    {
                        cout << nameList[i] << ": "
                             << Gradebook[i][grade - 1] << endl;
                        i++;
                    }
                }
            }
        }
        // Individual student, average
        else if (obj == 3)
        {
            int stuID;

            cout << "Which student's average would you like to check?";
            cin >> stuID;
            if (stuID > 20 || stuID < 1)
            {
                cout << "There is no student with this ID.";
            }
            else
            {
                cout << nameList[stuID - 1] << "'s average is " << average(stuID);
            }
        }

        // All students, average
        else if (obj == 4)
        {
            cout << "These are the student averages, in order of student IDs:" << endl;
            int i = 0;
            while (i < 20)
            {
                cout << nameList[i] << ": " << average(i + 1) << endl;
                i++;
            }
        }
        else if (obj == 5)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "The operative you entered is invalid. ";
        }
    }
    return 0;
}

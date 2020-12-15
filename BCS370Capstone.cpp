/*
 BCS 370 Capstone

 Diana Guerrero
 Professor Zhao
 BCS 370
 12/14/20

 Partner: Ryan W.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Assignments Class: stores information of each assignment including Course, Due Date, Number of Assignments
class Assignments 
{
public:
    string Course;
    int Due_Date;
    int Number_of_Assignments;

    Assignments(string Course, int Due_Date, int Number_of_Assignments)
    {
        this->Course = Course;
        this->Due_Date = Due_Date;
        this->Number_of_Assignments = Number_of_Assignments;
    }
};

// HomeworkManagementSystem Class: stores records of all assignments
class HomeworkManagementSystem
{
    /* For Failed Menu Below
    // Variables For Push & Pop
    stack<char>X;
    stack<char>F;
    */
public:
    vector<Assignments>a;

    // Adding New Assignment Record
    void insert(string Course, int Due_Date, int Number_of_Assignments)
    {
        a.push_back(Assignments(Course, Due_Date, Number_of_Assignments));
    }

    // Display Assignments Using Tail Recursion
    void display(int x, int size)
    {
        if (x == size)
        {
            return;
        }

        cout << a[x].Course << " " << a[x].Number_of_Assignments << " " << a[x].Due_Date << " " << endl;
        display(x + 1, size);
    }

    // Update an Assignment By Number of Assignments
    void update(string Course, int Number_of_Updated_Assignments, int Due_Date)
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i].Number_of_Assignments == Number_of_Updated_Assignments)
            {
                a[i].Course = Course;
                a[i].Due_Date = Due_Date;
                break;
            }
    }

    // Search Assignments by Due Date
    void search_by_due_date(int days)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].Due_Date == days)
            {
                cout << a[i].Number_of_Assignments << " " << a[i].Course << " " << endl;
            }
        }
    }

    // Search Assignments by Course Name
    void search_by_course(string Course)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].Course == Course)
            {
                cout << a[i].Number_of_Assignments << " " << a[i].Course << " " << a[i].Due_Date << " " << endl;
            }
        }
    }

    // Remove an Assignment
    void remove_homework(int Number_of_Assignments)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].Number_of_Assignments == Number_of_Assignments)
            {
                a.erase(a.begin() + i);
            }
        }
    }
};
    int main()
    {
        HomeworkManagementSystem hms;

        cout << "Course    Number of Assignments    Due Date" << endl;

        // All Assignments Inserted
        hms.insert("Calculus",     2,     1);
        hms.insert("SQL",     3,      5);
        hms.insert("Data Structures",     1,      2);
        hms.insert("Java",      3,       1);

        // All Assignments Displayed
        hms.display(0, hms.a.size());

        cout << "----------------------" << endl;

        // An example of an assignment updated
        hms.update("SQL",      1,      1);

        cout << "----------------------" << endl;

        // Display Updated Assignments 
        hms.display(0, hms.a.size());

        cout << "----------------------" << endl;

        // An example of searching by days
        hms.search_by_due_date(1);

        cout << "----------------------" << endl;

        // An example of searching by course
        hms.search_by_course("Data Structures");

        cout << "----------------------" << endl;

        // An example of removing an assignment
        hms.remove_homework(2);

        cout << "----------------------" << endl;

        // Display Updated Assignments
        hms.display(0, hms.a.size());

        return 0;
    }
    
    /* Attempt at trying to create a menu and have user input but it failed to run :(
    // Homework Management System Menu Functions

    void printScreen()
    {
        stack<char>I;
        while (!X.empty())
        {
            I.push(X.top());
            X.pop();
        }

        while (!I.empty())
        {
            cout << I.top() << endl;
            X.push(I.top());
            I.pop();
        }
    }

    void add()
    {
        bool choice;
        int num;
        int days;

        cout << "Fall 2020 Semester" << endl;
        cout << "------------------" << endl;
        cout << "1. Calculus" << endl;
        cout << "2. SQL" << endl;
        cout << "3. Data Structures" << endl;
        cout << "4. Java" << endl;

        // cout << "Please choose a Course to add an assigment to: ";
        char o;
        cin >> o;

        //X.push(o);

        cout << "Please choose an assigment to add: ";
        cin >> choice;
        cout << "Enter the amount of assigments for this course: " << endl;
        cin >> num;
        cout << "How many days is the assignment due: " << endl;
        cin >> days;
        if (choice = "Calculus") 
        {
            insert("Calculus", days, num);
            cout << num << " has been added to calculus." << endl;
        }
        
    }
    

    void search()
    {
        cout << "Please choose an assigment to search: ";
        printScreen();
    }

    void display()
    {
        cout << "Display Assignment: ";
        printScreen();
    }

    void update()
    {
        cout << "Please choose an assigment to update: ";
        printScreen();
    }

    void remove()
    {
        cout << "Please choose an assigment to remove: ";
        X.pop();
        printScreen();
    }

    // Homework Management System Menu Display
    
    void play()
    {
        int play = 1;

        while (play)
        {
            int choice;
            std::cout << "          *******Homework Managent System*******" << endl;
            std::cout << "1. Insert Assigment" << endl;
            std::cout << "2. Search Assigment" << endl;
            std::cout << "3. Display Assigment" << endl;
            std::cout << "4. Delete Assigment" << endl;
            std::cout << "5. Update Assigment" << endl;
            std::cout << "6. Exit" << endl;
            std::cout << "Please enter a choice from the menu above: " << endl;
            std::cin >> choice;

            // Switch Case
            switch (choice)
            {
            case 1 : this->add();
                break;
            case 2 : this->search();
                break;
            case 3 : this->display();
                break;
            case 4: this->remove();
                break;
            case 5: this->update();
                break;
            case 6 : cout << "END" << endl;
            default:cout << "Invalid Choice!";
                break;
            }
        }
    }
    */


 
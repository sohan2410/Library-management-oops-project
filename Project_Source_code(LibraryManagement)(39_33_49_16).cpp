#include <bits/stdc++.h>
using namespace std;

/* *******************LIBRARIAN****************** */

class students
{
public:
    students *next;
    string student_name;
    string dob, date;
    string name_issued_book;
    int day_issued = 0, month_issued = 0, year_issued = 0;
    int day_returned = 0, month_returned = 0, year_returned = 0;
    int unique_id;
    int prime_id;
    int book_ID = 0;
    int fine_charged = 0;
    int months;
    int number_days = 0;
    int exceed_days;
    students()
    {
        next = NULL;
    }
};

void add_prime_member(students *&new_student)
{
    int choice;
    cout << "Choose how long you wish to be a prime member for." << endl;
    cin >> new_student->months;
    cout << "Fill in the registration date in the given format (DD/MM/YYYY): ";
    cin >> new_student->date;
    cout << "The amount you have to pay is" << new_student->months * 150 << endl;
    cout << "Your new ID number is " << endl;
    new_student->prime_id = new_student->unique_id + 80;
    cout << "'" << new_student->prime_id << "'" << endl;
    cout << "Press '1' to continue" << endl;
    cin >> choice;
    if (choice == 1)
    {
        return;
    }
    else
    {
        cout << "INPUT IS INVALID";
        exit(0);
    }
}

void issue_book(students *&new_student, int choice)
{
    int choice1;
    switch (choice)
    {
    case 1:
        cout << "Put the title of the book here : ";
        cin >> new_student->name_issued_book;
        cout << "Enter the book ID : ";
        cin >> new_student->book_ID;
        {
            int date_check = 1;
            while (date_check)
            {
                cout << "Date of Issuing the book in the given format (DD MM YYYY)(WITH SPACES) : ";
                cin >> new_student->day_issued >> new_student->month_issued >> new_student->year_issued;
                if (new_student->month_issued == 1 || new_student->month_issued == 3 || new_student->month_issued == 5 || new_student->month_issued == 7 || new_student->month_issued == 8 || new_student->month_issued == 10 || new_student->month_issued == 12)
                {
                    if (new_student->day_issued > 31)
                        cout << "INVALID DATE" << endl;
                    else
                        date_check = 0;
                }
                else if (new_student->month_issued == 11 || new_student->month_issued == 6 || new_student->month_issued == 9 || new_student->month_issued == 11)
                {
                    if (new_student->day_issued > 30)
                        cout << "INVALID DATE" << endl;
                    else
                        date_check = 0;
                }
                else if (new_student->month_issued == 2)
                {
                    if (((new_student->year_issued % 4 == 0) && (new_student->year_issued % 100 != 0)) || (new_student->year_issued % 400 == 0))
                        date_check = 0;
                    else
                        cout << "INVALID DATE";
                }
            }
        }
        cout << "The number of days you want to issue the book (not more than 10 days if you are not a prime member) : ";
        cin >> new_student->number_days;
        if (new_student->number_days <= 10 && new_student->number_days > 0)
        {
            cout << "Book " << new_student->name_issued_book << "(ID = " << new_student->book_ID << ")"
                 << "has been issued" << endl;
        }
        else if (new_student->number_days > 10)
        {

            if (new_student->prime_id == new_student->unique_id + 80)
            {
                return;
            }
            else
            {

                cout << "You are not a member of our library's prime group." << endl
                     << "If you want to be a part of it press 1" << endl
                     << "1.Yes" << endl
                     << "2.No" << endl;
                cin >> choice1;
                if (choice1 == 1)
                {
                    add_prime_member(new_student);
                }
                else if (choice1 == 2)
                {
                    return;
                }
                else
                {
                    cout << "INVALID INPUT";
                    exit(0);
                }
            }
        }

        {
        }

        break;
    case 2:

        break;
    default:
        cout << "INPUT IS INVALID";
        exit(0);
        break;
    }
}

void issue_a_book_for_member(students *head)
{
    int unique_idno;
    cout << "	ENTER UNIQUE ID: ";
    cin >> unique_idno;
    students *temp = head;

    while (1)
    {
        if (temp->unique_id == unique_idno || temp->prime_id == unique_idno)
            break;
        else
            temp = temp->next;
    }
    if (temp->book_ID > 0 && temp->prime_id != temp->unique_id + 80)
    {
        int choice1;
        cout << "You are not prime member of our library" << endl
             << "If you want to be a part of our prime family press 1" << endl
             << "1.Yes" << endl
             << "2.No" << endl;
        cin >> choice1;
        if (choice1 == 1)
        {
            add_prime_member(temp);
            issue_book(temp, 1);
        }
        else if (choice1 == 2)
        {
            cout << "Sorry then You have to have Only One Book at a Time";
            return;
        }
        else
        {
            cout << "INVALID INPUT";
            exit(0);
        }
    }
    else
        issue_book(temp, 1);
}

void add_new_student(students *&head, int i)
{
    int choice;
    students *new_student = new students();
    cout << "ENTER"
         << " " << i << " STUDENT'S NAME: ";
    cin >> new_student->student_name;
    cout << "ENTER YOUR DOB in the format (DD-MM-YYYY): ";
    cin >> new_student->dob;
    new_student->unique_id = new_student->student_name[0] + new_student->student_name[1] + new_student->student_name[2] + new_student->dob[0] + new_student->dob[1] + new_student->dob[3] + new_student->dob[4];
    cout << new_student->student_name << " your unique ID is "
         << "'" << new_student->unique_id << "'" << endl;
    cout << endl;
    new_student->prime_id = new_student->unique_id;
    cout << endl;
    cout << "Want to issue a book?" << endl
         << "1.Yes" << endl
         << "2.No" << endl;
    cin >> choice;
    if (choice == 1)
    {
        issue_book(new_student, choice);
    }
    else if (choice == 2)
    {
        if (head == NULL)
        {
            head = new_student;
            return;
        }
        students *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_student;
        return;
    }
    else
    {
        cout << "INPUT IS INVALID";
        exit(0);
    }

    if (head == NULL)
    {
        head = new_student;
        return;
    }
    students *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_student;
}

void check_info(students *tmp)
{

    int ID, choice;
    cout << "To check the status of your issued book, enter your valid issued ID." << endl;
    cin >> ID;
    while (1)
    {
        if (tmp->prime_id == ID)
        {
            cout << "NAME = " << tmp->student_name << endl;
            cout << "ID = " << tmp->prime_id;
            cout << endl;
            if (tmp->book_ID == 0)
            {
                cout << "You don't have any books issued." << endl;
                cout << "To issue a book press 1" << endl
                     << "To return to home page press 0" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    issue_book(tmp, choice);
                }
                else if (choice == 0)
                {
                    return;
                }
                else
                {
                    cout << "INPUT IS INVALID";
                    exit(0);
                }
            }
            else
            {

                cout << "You already have a book issued" << endl;
                cout << "BOOK NAME = " << tmp->name_issued_book << endl;
                cout << "BOOK ID = " << tmp->book_ID << endl;
                cout << "Issued date = " << tmp->day_issued << " " << tmp->month_issued << " " << tmp->year_issued << endl;
                cout << "The number of days for which the user has issued the book = " << tmp->number_days << endl;
            }
        }
        else
        {
            tmp = tmp->next;
        }
    }
}
void remove_a_student(students *head)
{
    string name;
    int unique_idno, choice;
    cout << "Search a member by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Unique ID" << endl;
    cout << "ENTER CHOICE: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "	ENTER YOUR NAME: ";
        cin >> name;
        students *temp = head;
        if (temp->student_name == name)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->student_name == name)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }

    else if (choice == 2)
    {
        cout << "	ENTER THE UNIQUE ID: ";
        cin >> unique_idno;
        students *temp = head;
        if (temp->unique_id == unique_idno)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->unique_id == unique_idno)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }
}

void return_book(students *head)
{
    int unique_idno;
    cout << "	ENTER THE UNIQUE ID: ";
    cin >> unique_idno;
    students *temp = head;
    if (temp->unique_id == unique_idno)
    {
        cout << "Date of RETURNING the book issued (format- DD MM YYYY)(WITH SPACES): ";
        cin >> temp->day_returned >> temp->month_returned >> temp->year_returned;
        cout << " YOUR BOOK HAS BEEN RETURNED";
        return;
    }
    else
        while (1)
        {
            if (temp->unique_id == unique_idno)
                break;
            else
                temp = temp->next;
        }
    cout << "Date of RETURNING the book (format- DD MM YYYY)(WITH SPACES): ";
    cin >> temp->day_returned >> temp->month_returned >> temp->year_returned;
    cout << " YOUR BOOK HAS BEEN RETURNED";
    return;
}

int return_days(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int days = 0, i;
    if (d1 == 0 && m1 == 0 && y1 == 0)
        days = 0;
    else
    {

        int montharray[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (m1 == m2)
        {
            days = d2 - d1 + 1;
            days = days + (y2 - y1) * 365;
        }

        else if (m1 < m2)
        {
            for (i = m1; i < m2; i++)
                days = days + montharray[i];

            days = days + d2 - d1 + 1 + (y2 - y1) * 365;
        }

        else if (m1 > m2)
        {
            for (i = m2; i < m1; i++)
                days = days + montharray[i];

            days = days + d1 - d2 + 1;
            days = 365 - days + (y2 - y1 - 1) * 365;
        }
    }
    return days;
}

void fine_charging(students *&stud)
{
    if (stud->unique_id == stud->prime_id)
    {
        int number_of_days = return_days(stud->day_issued, stud->month_issued, stud->year_issued, stud->day_returned, stud->month_returned, stud->year_returned);
        if (number_of_days > stud->number_days)
        {
            stud->fine_charged = (number_of_days - stud->number_days) * 2;
            if (stud->fine_charged < 0 || number_of_days == 0)
                stud->fine_charged = 0;
            return;
        }

        else
            return;
    }
}

/* ***********************************Books***************************** */

class books
{
public:
    string book_name;
    int book_id;
    books *next;
    books()
    {
        next = NULL;
    }
};

void add_new_book(books *&head)
{
    books *new_book = new books();
    cout << "ENTER THE BOOK NAME: ";
    cin >> new_book->book_name;
    cout << "ENTER THE BOOK ID: ";
    cin >> new_book->book_id;
    if (head == NULL)
    {
        head = new_book;
        return;
    }
    books *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_book;
}

void display(books *head)
{
    if (head == NULL)
    {
        cout << "NO LIST AVAILABLE";
        return;
    }
    books *tmp = head;
    cout << "NAME"
         << "             "
         << "Book ID" << endl;
    while (1)
    {
        cout << tmp->book_name << "                 " << tmp->book_id << endl;
        if (tmp->next == NULL)
            return;
        else
            tmp = tmp->next;
    }
}

void remove_a_book(books *&head)
{
    string name;
    int book_idno, choice;
    cout << "Search by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Book ID" << endl;
    cout << "ENTER CHOICE: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "	ENTER Book Name : ";
        cin >> name;
        books *temp = head;
        if (temp->book_name == name)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->book_name == name)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }

    else if (choice == 2)
    {
        cout << "	ENTER Book ID : ";
        cin >> book_idno;
        books *temp = head;
        if (temp->book_id == book_idno)
        {
            head = temp->next;
        }
        else
            while (1)
            {
                if (temp->next->book_id == book_idno)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
    }
}

void display(students *head)
{
    int i;
    if (head == NULL)
    {
        cout << "NO LIST AVAILABLE";
        return;
    }
    students *tmp = head;
    cout << "NAME"
         << "              "
         << "UNIQUE ID"
         << "          "
         << "BOOK ISSUED"
         << "          "
         << "ISSUE DATE"
         << "          "
         << "RETURN DATE"
         << "          "
         << "FINE CHARGED" << endl;
    while (1)
    {
        cout << tmp->student_name;
        for (i = 0; i < 18 - (tmp->student_name.length()); i++)
            cout << " ";
        cout << tmp->unique_id;
        cout << "                ";
        cout << tmp->name_issued_book;
        for (i = 0; i < 21 - (tmp->name_issued_book.length()); i++)
            cout << " ";
        printf("%.2d  %.2d  %.4d", tmp->day_issued, tmp->month_issued, tmp->month_issued);
        cout << "        ";
        printf("%.2d  %.2d  %.4d", tmp->day_returned, tmp->month_returned, tmp->month_returned);
        cout << "         ";
        fine_charging(tmp);
        cout << tmp->fine_charged << endl;
        if (tmp->next == NULL)
            return;
        else
            tmp = tmp->next;
    }
}

int main()
{
    students *head = NULL;
    books *headb = NULL;
    int choice1, choice2, choice3, i, n;
    cout << endl;

    cout << "************* WELCOME TO LIBRARY MANAGEMENT SYSTEM *************\n\n";

    cout << "\t\t YOU are LOGGED IN AS A LIBRARIAN \n\n";
    cout
        << "\t\t    ENTER '1' TO CONTINUE : ";
    cin >> choice1;
    system("CLS");
    while (1)
    {
        if (choice1 == 1)
        {
            cout << endl
                 << endl
                 << endl
                 << endl;
            cout << "----------------------------------------\n";
            cout << "Choose a category to operate : " << endl
                 << "1. STUDENT" << endl
                 << "2. BOOK" << endl;
            cout << "----------------------------------------\n\n";
            cout << "Enter a choice : ";
            cin >> choice3;
            if (choice3 == 1)
            {
                cout << "\n------------------------------------\n";
                cout << "CHOOSE FROM THE FOLLOWING : " << endl;
                cout << "\t1. Add  new account\n"
                     << "\t2. Remove a account\n"
                     << "\t3. Display member list\n"
                     << "\t4. Info about student\n"
                     << "\t5. Return a book\n"
                     << "\t6. Issue a book\n"
                     << "\t7. Exit\n";
                cout << "------------------------------------\n\n";
                cout << "Enter your choice : ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    cout << "ENTER NUMBER OF STUDENTS TO ADD: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                        add_new_student(head, i + 1);
                }

                else if (choice2 == 2)
                {
                    remove_a_student(head);
                }

                else if (choice2 == 3)
                {
                    display(head);
                }
                else if (choice2 == 4)
                {
                    check_info(head);
                }

                else if (choice2 == 5)
                {
                    return_book(head);
                }
                else if (choice2 == 6)
                {
                    issue_a_book_for_member(head);
                }
                else if (choice2 == 7)
                {
                    exit(0);
                }
                else
                {
                    cout << "INPUT IS INVALID";
                    exit(0);
                }
            }

            else if (choice3 == 2)
            {
                cout << "---------------------------------\n";
                cout << "CHOOSE FROM THE FOLLOWING: " << endl;
                cout << "\t1. Add a new book\n"
                     << "\t2. Remove a book\n"
                     << "\t3. Display book list\n"
                     << "\t4. Exit\n";
                cout << "----------------------------------\n\n";
                cout << "Enter your choice : ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    cout << "ENTER NUMBER OF BOOKS TO BE ADDED: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                        add_new_book(headb);
                }

                else if (choice2 == 2)
                {
                    remove_a_book(headb);
                }

                else if (choice2 == 3)
                {
                    display(headb);
                }

                else if (choice2 == 4)
                {
                    exit(0);
                }
                else
                {
                    cout << "INPUT IS INVALID";
                    exit(0);
                }
            }
            else
            {
                cout << "INPUT IS INVALID";
                exit(0);
            }
        }
    }
    return 0;
}

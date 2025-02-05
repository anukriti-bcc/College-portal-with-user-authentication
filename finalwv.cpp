#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <cmath>
using namespace std;

int publishResult = 0;
void home();
void intro();
void exit();
void login_admin();
void login_faculty();
void login_student();

// admin features
void menu();
void add_student();
void add_faculty();
void view_existing_student(int);
void view_existing_faculty(int);
void modify_existing_student(int);
void modify_existing_faculty(int);
void update_semester();
void delete_faculty(int);
void delete_student(int);

// faculty Specific Feature
void upload_marks(int);
void view_specific_marks(int);

// student specific feature
void view_result();

class school_member
{
public:
    char name[80];
    char address[200];
    char phone[11];
    char dob[40];
    char pass[20];
};

class student : public school_member
{
public:
    int semester;
    int id;
    float math,english,sdf;
    float percentage;

    void calc_percentage() {
    float total = math+english+sdf;
    percentage = total / 3;
}

};

class faculty : public school_member
{
public:
    int id;
    char department[40];
};

int main()
{
    system("color a");
    system("cls");

    intro();
    home();

    return 0;
}

void intro()
{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *****  *     *****  ***    * * *    *****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *        " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *****  *     *     *   *  *  *  *   *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  * * *   *****  ****  *****  ***   *  *  *   *****     " << endl;
    Sleep(300);
    cout << endl;
    cout << "\t\t\t\t   -----------------------TO----------------------" << endl;
    Sleep(500);
    cout << "\t\t\t\t                  ABC COLLEGE PORTAL" << endl;
    Sleep(500);
    cout << "\t\t\t\t   -----------------------------------------------" << endl;
    Sleep(500);
    cout << "\nPress enter to continue...";
    cin.get();
}

void home()
{
    char c;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t  ---------- STUDENT RECORD MANAGEMENT SYSTEM ----------" << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t\t       ----------HOME PAGE----------\n\n"
         << endl;
    cout << "\n\n";
    cout << "\t\t\t\t\t      Select User type from following:" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t    1.Login as Admin\n\n";
    cout << "\t\t\t\t\t\t    2.Login as Faculty\n\n";
    cout << "\t\t\t\t\t\t    3.Login as Student\n\n";
    cout << "\t\t\t\t\t\t    4.Shut the system\n\n";
    cout << "ENTER YOUR CHOICE : ";
    cin >> c;
    system("cls");
    switch (c)
    {
    case '1':
    {
        login_admin();
        break;
    }
    case '2':
    {
        login_faculty();
        break;
    }
    case '3':
    {
        login_student();
        break;
    }
    case '4':
    {
        exit();
        break;
    }
    }
}

void exit()
{
    char c;
    system("cls");
    system("color a");
    cout << "THANK YOU FOR USING THIS SOFTWARE! :) " << endl;
    cout << "\n\n";
    return;
}

void login_admin()
{
    char ch;
    string pass, id;
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t   Login As Admin \n\n";
    cout << "\t\t\t\t    ---------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t  Enter your Id and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t\t  ID: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t\t  Password: ";
    cin.ignore();
    ch = _getch();
    while (true)
{
    ch = _getch();
    if (ch == 13)
    {
        break;
    }
    else if (ch == 8)
    {
        if (!pass.empty())
        {
            cout << "\b \b";
            pass.pop_back();
        }
    }
    else
    {
        pass.push_back(ch);
        cout << '*';
    }
}

    if (id == "admin" && pass == "admin") //
        menu();
    else
    {
        cout << "\n\n\t\t\t\t\t\tInvalid ID or Password\n\n";
        cout << endl;
        cout << "\t\t\t\t        Enter 'H' to go back to login options...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            home();
    }
}

void menu()
{
begin:
    system("cls");
    system("color c");
    int choice;
    cout << "\n\n\n\t\t\t\t\t\t Welcome Admin\n\n\n";
    cout << "\t\t\t\t-------------------MAIN MENU------------------\n\n"<< endl;
    cout << "\t\t\t\t 1. View and Publish Result\n\n";
    Sleep(300);
    cout << "\t\t\t\t\t\t    STUDENT \n\n";
    Sleep(300);
    cout << "\t\t\t\t 2. Add a new Student\n\n";
    Sleep(300);
    cout << "\t\t\t\t 3. View existing Student record\n\n";
    Sleep(300);
    cout << "\t\t\t\t 4. Modify existing Student record.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 5. Upload Student Marks.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 6. View Specific Student Marks.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 7. Update semester.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 8. Delete Student record.\n\n";
    Sleep(300);
    cout << "\t\t\t\t\t\t    FACULTY \n\n";
    Sleep(300);
    cout << "\t\t\t\t 9. Add a new Faculty\n\n";
    Sleep(300);
    cout << "\t\t\t\t 10. View existing Faculty\n\n";
    Sleep(300);
    cout << "\t\t\t\t 11. Modify existing faculty record\n\n";
    Sleep(300);
    cout << "\t\t\t\t 12. Delete existing faculty record\n\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t 13. Log Out\n\n";
    cout << "\t\t\t\t--------------------------------------------------" << endl;
    Sleep(300);
    int check=1;
    while(check){
    cout << "\t\t\t\tENTER YOUR CHOICE... <1-13> : ";
    Sleep(300);
    cin >> choice;
    if (choice > 0 && choice < 14 && !cin.fail() && (choice==floor(choice))) {
        check=0;
    }
    else{
        cout<<"\t\t\t\tInvalid input. Try again.\n";
        cin.clear();
        cin.ignore();
    }
    }
    cout << endl;
    system("cls");
    switch (choice)
    {
    case 1:
    {
        view_result();
        goto begin;
        break;
    }
    case 2:
    {
        add_student();
        goto begin;
        break;
    }
    case 3:
    {
        int n;
        cout << "\n\nENTER STUDENT ID TO VIEW PROFILE : ";
        cin >> n;
        view_existing_student(n);
        goto begin;
        break;
    }
    case 4:
    {
        int n;
        cout << "\n\nENTER STUDENT ID TO MODIFY PROFILE : ";
        cin >> n;
        modify_existing_student(n);
        goto begin;
        break;
    }
    case 5:
    {
        int n;
        cout << "\n\nENTER STUDENT ID TO UPLOAD MARKS : ";
        cin >> n;
        upload_marks(n);
        goto begin;
        break;
    }
    case 6:
    {
        int n;
        cout << "ENTER STUDENT ID TO VIEW MARKS: ";
        cin >> n;
        view_specific_marks(n);
        goto begin;
        break;
    }
    case 7:
    {
        update_semester();
        goto begin;
        break;
    }
    case 8:
    {
        int n;
        cout << "\n\nENTER STUDENT ID TO DELETE RECORD : ";
        cin >> n;
        delete_student(n);
        goto begin;
        break;
    }
    case 9:
    {
        add_faculty();
        goto begin;
        break;
    }
    case 10:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO VIEW PROFILE : ";
        cin >> n;
        view_existing_faculty(n);
        goto begin;
        break;
    }
    case 11:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO MODIFY PROFILE DATA : ";
        cin >> n;
        modify_existing_faculty(n);
        goto begin;
        break;
    }
    case 12:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO DELETE RECORD : ";
        cin >> n;
        delete_faculty(n);
        goto begin;
        break;
    }
    case 13:
    {
        home();
        break;
    }
    }
}

void view_result() {
    system("cls");
    student s;
    ifstream infile;
    bool check = false;
    infile.open("Student.txt", ios::app | ios::binary);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tALL STUDENTS REPORT CARDS FOR REVIEW " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        cout << "\t\t\t\tSTUDENT NAME : " << s.name << endl
             << endl;
        cout << "\t\t\t\tSTUDENT ADMISSION ID : " << s.id << endl
             << endl;
        cout << "\t\t\t\t MATH      : " << s.math << endl;
        cout << "\t\t\t\t ENGLISH   : " << s.english << endl;
        cout << "\t\t\t\t SDF       : " << s.sdf << endl;
        cout << "\t\t\t\t PERCENTAGE: " << s.percentage <<"%" <<endl<< endl;
        cout << "------------------------------------------------------------\n"<< endl;
        check = true;
    }
    infile.close();
    if (check == false)
        cout << "\t\t\t\t  NO RECORD FOUND. " << endl
             << endl;
    if (check == true)
    {
        cout << "\n\nPublish Result? Enter 1 for yes, any other digit for no : ";
        cin >> publishResult;
        if (publishResult == 1)
        {
            cout << "\n\nResult Published to STUDENT PORTAL\n\n";
        }
    }
    cout << "\tPress enter to continue....";
    cin.ignore();
    cin.get();
}

void add_student() {
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Student.txt", ios::app | ios::binary);
    try{
    if (outfile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    cout << "\n\n\n";
    cout << "\t\t\t\t---------- Add A Student ----------\n\n";
    s.semester=1;
    int check=1;
    while(check){
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(s.name, 100);
    if(strlen(s.name)>0&&strlen(s.name)<40){
        check=0;
    }
    else{
        cout<<"Name entered has invalid length. Must be 1-39 characters. Try again.\n";
    }
    }
    check=1;
    while(check){
    cout << "ENTER ADMISSION ID (INT value): ";
    cin>>s.id;
    fflush(stdin);
    if(s.id>0&&s.id<=999999 && !cin.fail()){
        check=0;
    }
    else{
        cout<<"Invalid input. ID must be a positive integer of max. length 6. Try again.\n";
        cin.clear();
        cin.ignore();
    }
    }
    check=1;
    while(check){
    cout << "ENTER D.O.B (DDMMYYYY): ";
    cin.getline(s.dob, 40);
    if(strlen(s.dob)==8){
        check=0;
    }
    else{
        cout<<"Invalid input. DOB must be entered in DDMMYYYY format. Try again.\n";
    }
    }
    check=1;
    while(check){
    cout << "ENTER PHONE NO. : ";
    cin.getline(s.phone, 20);
    if(strlen(s.phone)==10){
        check=0;
    }
    else{
        cout<<"Invalid input. Phone no. must be of length 10. Try again.\n";
    }
    }
    check=1;
    cout << "ENTER ADDRESS : ";
    cin.getline(s.address, 200);
    cout << "Set A Password For the User : ";
    cin.getline(s.pass, 20);
    outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void view_existing_student(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool equality = false;
    cout << "\n\n\n\t\t\t\t--------------- STUDENT PROFILE -------------------\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.id == n)
        {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ADMISSION ID : " << s.id << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\t\t\t\t SEMESTER : " << s.semester << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << s.phone << endl;
            cout << "\t\t\t\t ADDRESS : " << s.address << endl;
            cout << "\t\t\t\t PASSWORD : " << s.pass << endl;
            cout << "\t\t\t\t------------------------------------------------ "<< endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}

void view_existing_student_faculty(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool equality = false;
    cout << "\n\n\n\t\t\t\t--------------- STUDENT PROFILE -------------------\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.id == n)
        {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ADMISSION ID : " << s.id << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\t\t\t\t SEMESTER : " << s.semester << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << s.phone << endl;
            cout << "\t\t\t\t ADDRESS : " << s.address << endl;
            cout << "\t\t\t\t------------------------------------------------ "<< endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}

void modify_existing_student(int n)
{
    system("cls");
    student s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool checker = false;
    cout << "\n\n\n\t\t\t\t--------------MODIFY STUDENT PROFILE--------------\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&s), sizeof(student));
        {
            if (s.id == n)
            {
                cout << "\t\t\t\t 1. NAME : " << s.name << endl;
                cout << "\t\t\t\t 2. ADMISSION ID : " << s.id << endl;
                cout << "\t\t\t\t 3. D.O.B : " << s.dob << endl;
                cout << "\t\t\t\t 4. PHONE NUMBER :" << s.phone << endl;
                cout << "\t\t\t\t 5. ADDRESS :" << s.address << endl;
                cout << "\t\t\t\t 6. PASSWORD : " << s.pass << endl;
                cout << "\n\t\t\t\t-------------------------------------------" << endl;
                int check=1;
                while(check){
                int ch;
                cout << "\t\t\t      Enter 1,3-6 to update faculty information, enter 7 to go back to menu: ";
                cin >> ch;
                cout<<endl;

                switch (ch)
                {
                case 1:
                    cout << "\t\t\t\tEnter Full Name: ";
                    cin.ignore();
                    cin.getline(s.name, 40);
                    break;
                case 2:
                    cout<<"\n\t\t\t\tID cannot be changed. Try again.\n ";
                    break;
                case 3:
                    cout << "\t\t\t\tEnter Date of Birth: ";
                    cin.ignore();
                    cin.getline(s.dob, 40);
                    break;
                case 4:
                    cout << "\t\t\t\tEnter Phone Number: ";
                    cin.ignore();
                    cin.getline(s.phone,11);
                    break;
                case 5:
                    cout << "\t\t\t\tEnter Address: ";
                    cin.ignore();
                    cin.getline(s.address, 200);
                    break;
                case 6:
                    cout << "\t\t\t\tEnter Password: ";
                    cin.ignore();
                    cin.getline(s.pass, 20);
                    break;
                case 7:
                    cout << "\t\t\t\t Back to menu.\n" << endl;
                    check=0;
                    break;
                default:
                    cout << "\t\t\t\tInvalid choice. Please enter a number between 1 and 7." << endl;
                    break;
                }

                if (ch >= 1 && ch <= 6 && ch!=2)
                {
                    int pos = (-1) * static_cast<int>(sizeof(student));
                    infile.seekp(pos, ios::cur);
                    infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                    cout << endl;
                    cout << "\t\t\t\tTHE FILE HAS BEEN SUCCESSFULLY UPDATED" << endl;
                }
                }
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void delete_student(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::binary);
    try{
    if (!infile)
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    ofstream outfile;
    outfile.open("Record3.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t------------------DELETE A STUDENT RECORD------------------------\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.id != n)
        {
            outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
        }
    }
    infile.close();
    outfile.close();
    remove("Student.txt");
    rename("Record3.txt", "Student.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void upload_marks(int n) {
    system("cls");
    student s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    try{
    if (infile.fail()) {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool checker = false;
    cout << "\n\n\t\t\t\t-------------------UPLOAD STUDENT MARKS----------------------\n\n";

    ofstream file;
    file.open("Student.csv", ios::app);

    file.seekp(0, ios::end);
    if (file.tellp() == 0) {
        file << "Name, ID, Maths, English, SDF, %" << endl;
    }

    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
        if (s.id == n) {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ADMISSION ID : " << s.id << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\n\t\t\t\t--------------------------------------------" << endl;
            cout << "\t\t\t\t\t  UPLOAD MARKS BELOW" << endl;
            cout << "\t\t\t\t---------------------------------------------" << endl;

            cout << "\t\t\t\tMATH    : ";
            cin >> s.math;
            cout << "\t\t\t\tENGLISH : ";
            cin >> s.english;
            cout << "\t\t\t\tSDF     : ";
            cin >> s.sdf;

            s.calc_percentage();

            infile.seekp(infile.tellg() - sizeof(student));

            infile.write(reinterpret_cast<char *>(&s), sizeof(student));

            cout << endl;
            cout << "\n\t\t\t\tMARKS UPLOADED SUCCESSFULLY" << endl;
            checker = true;

            file << s.name << ", "<< s.id<<", "<<s.math << ", " << s.english<<", " <<s.sdf<<", " <<s.percentage<<endl;
            break;
        }
    }

    infile.close();
    file.close();

    if (!checker)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;

    cout << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void update_semester() {
    system("cls");
    ifstream infile("Student.txt", ios::binary);
    ofstream outfile("TempStudent.txt", ios::binary | ios::app);
try{
    if (!infile || !outfile) {

        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }
}
catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    student s;
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
        s.semester++;
        outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
    }

    infile.close();
    outfile.close();

    if (remove("Student.txt") != 0) {
        cout << "Error deleting Student.txt";
        return;
    }
    if (rename("TempStudent.txt", "Student.txt") != 0) {
        cout << "Error renaming TempStudent.txt";
        return;
    }

    cout << "Semester updated successfully!";
    cin.ignore();
    cin.get();
}


void view_specific_marks(int n) {
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    try{
    if (infile.fail()) {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool found = false;
    ofstream outfile("Result.csv");
    outfile << "ID,Name,Math,English,SDF,Percentage" << endl;

    cout << "\n\n\t\t\t\t-------------- STUDENT REPORT CARD -----------------\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
        if (s.id== n) {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ADMISSION ID : " << s.id << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\t\t\t\t-------------------------------" << endl;
            cout << "\t\t\t\t MATH      : " << s.math<< endl;
            cout << "\t\t\t\t ENGLISH   : " << s.english << endl;
            cout << "\t\t\t\t SDF       : " << s.sdf << endl;
            cout << endl;
            cout << "\t\t\t\t PERCENTAGE: " << s.percentage << "%" << endl;
            cout << "\t\t\t\t-------------------------------" << endl;

            outfile << s.id << "," << s.name << ","
                    << fixed << setprecision(2) << s.math << ","
                    << fixed << setprecision(2) << s.english << ","
                    << fixed << setprecision(2) << s.sdf << ","
                    << fixed << setprecision(2) << s.percentage << "%" << endl;

            found = true;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;

    cout << endl;
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}

void add_faculty()
{
    system("cls");
    faculty f;
    ofstream outfile;
    outfile.open("Faculty.txt", ios::app | ios::binary);
    try{
    if (outfile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    cout << "\n\n";
    cout << "\t\t\t\t----------------Add A Faculty ----------------\n\n";

    int check=1;
    while(check){
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(f.name, 100);
    if(strlen(f.name)>0&&strlen(f.name)<40){
        check=0;
    }
    else{
        cout<<"Name entered has invalid length. Must be 1-39 characters. Try again.\n";
    }
    }
    check=1;
    while(check){
    cout << "ENTER D.O.B (DDMMYYYY): ";
    cin.getline(f.dob, 40);
    if(strlen(f.dob)==8){
        check=0;
    }
    else{
        cout<<"Invalid input. DOB must be entered in DDMMYYYY format. Try again.\n";
    }
    }
    check=1;
    while(check){
    cout << "ENTER PHONE NO. : ";
    cin.getline(f.phone, 20);
    if(strlen(f.phone)==10){
        check=0;
    }
    else{
        cout<<"Invalid input. Phone no. must be of length 10. Try again.\n";
    }
    }
    cout << "ENTER ADDRESS : ";
    cin.getline(f.address, 200);
    cout << "ENTER Department: ";
    cin.getline(f.department, 40);
    cout << "Set a Password: ";
    cin.getline(f.pass, 40);
    cout << "ENTER Faculty ID (INT type): ";
    cin >> f.id;
    outfile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void view_existing_faculty(int n)
{
    system("cls");
    faculty f;
    ifstream infile;
    infile.open("Faculty.txt", ios::binary | ios::in);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool equality = false;
    cout << "\n\n\t\t\t\t---------------- FACULTY PROFILE ---------------------\n\n";
    while (!infile.eof() && infile.read(reinterpret_cast<char *>(&f), sizeof(faculty)))
    {
        if (f.id == n)
        {
            cout << "\t\t\t\t NAME : " << f.name << endl;
            cout << "\t\t\t\t FACULTY ID : " << f.id << endl;
            cout << "\t\t\t\t D.O.B : " << f.dob << endl;
            cout << "\t\t\t\t DEPARTMENT : " << f.department << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << f.phone << endl;
            cout << "\t\t\t\t ADDRESS : " << f.address << endl;
            cout << "\t\t\t\t PASSWORD : " << f.pass << endl;
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            equality = true;
        }
    }
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl<<endl;
    infile.close();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Press any key to continue...";
    cin.get();
}

void modify_existing_faculty(int n)
{
    system("cls");
    faculty f;
    fstream infile;
    infile.open("Faculty.txt", ios::binary | ios::in | ios::out);
    try{
    if (infile.fail())
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
        }
    }
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool checker = false;
    cout << "\n\n\t\t\t\t-------------------MODIFY FACULTY PROFILE------------------------\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&f), sizeof(faculty));
        {
            if (f.id == n)
            {
                cout << "\t\t\t\t 1. NAME : " << f.name << endl;
                cout << "\t\t\t\t 2. FACULTY ID : " << f.id << endl;
                cout << "\t\t\t\t 3. D.O.B : " << f.dob << endl;
                cout << "\t\t\t\t 4. DEPARTMENT : " << f.department << endl;
                cout << "\t\t\t\t 5. PHONE NUMBER : " << f.phone << endl;
                cout << "\t\t\t\t 6. ADDRESS : " << f.address << endl;
                cout << "\t\t\t\t 7. PASSWORD : " << f.pass << endl;
                cout << "\n\t\t\t\t-------------------------------------------------------------------" << endl;
                int check=1;
                while(check){
                int ch;
                cout << "\t\t\t      Enter 1,3-7 to update faculty information, enter 8 to go back to menu: ";
                cin >> ch;
                cout<<endl;
                switch (ch){
                case 1:
                    cout << "\t\t\t\t Enter Full Name: ";
                    cin.ignore();
                    cin.getline(f.name, 40);
                    break;
                case 2:
                    cout<<"\nID cannot be changed. Try again.\n ";
                    break;
                case 3:
                    cout << "\t\t\t\t Enter Date of Birth: ";
                    cin.ignore();
                    cin.getline(f.dob, 40);
                    break;
                case 4:
                    cout << "\t\t\t\t Enter Department: ";
                    cin.ignore();
                    cin.getline(f.department, 40);
                    break;

                case 5:
                    cout << "\t\t\t\t Enter Phone Number: ";
                    cin.ignore();
                    cin.getline(f.phone,11);
                    break;

                case 6:
                    cout << "\t\t\t\t Enter Address: ";
                    cin.ignore();
                    cin.getline(f.address, 200);
                    break;

                case 7:
                    cout << "\t\t\t\t Enter Password: ";
                    cin.ignore();
                    cin.getline(f.pass, 20);
                    break;

                case 8:
                    cout << "\t\t\t\t Back to menu.\n" << endl;
                    check=0;
                    break;
                default:
                    cout << "\t\t\t\tInvalid choice. Please enter a number between 1 and 8." << endl;
                    break;
                }

                if (ch >0 && ch <8 && ch!=2)
                {
                    int pos = (-1) * static_cast<int>(sizeof(faculty));
                    infile.seekp(pos, ios::cur);
                    infile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
                    cout << endl;
                    cout << "\t\t\t\tTHE FILE HAS BEEN SUCCESSFULLY UPDATED" << endl;
                }
            }
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void delete_faculty(int n)
{
    system("cls");
    faculty f;
    ifstream infile;
    try{
    infile.open("Faculty.txt", ios::binary);
    if (!infile)
    {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    ofstream outfile;
    outfile.open("Record2.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t---------------------DELETE A FACULTY RECORD----------------------n\n";
    while (infile.read(reinterpret_cast<char *>(&f), sizeof(faculty)))
    {
        if (f.id != n)
        {
            outfile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
        }
    }
    infile.close();
    outfile.close();
    remove("Faculty.txt");
    rename("Record2.txt", "Faculty.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void login_faculty() {
    char cc;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t Login As Faculty \n\n";
    cout << "\t\t\t\t------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t Enter your Faculty ID and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t Faculty ID: ";
    cin >> id;
    cout << "\t\t\t\t Password: ";
    char ch = _getch();
    while (ch != 13) {
        if (ch == 8) {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    system("cls");
    faculty f;
    ifstream infile;
    infile.open("Faculty.txt", ios::app | ios::binary);
    try{
    if (infile.fail()) {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool equality = false;
    while (infile.read(reinterpret_cast<char *>(&f), sizeof(faculty))) {
        if (f.id == id && f.pass == password) {

             start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t\t       Welcome " << f.name << "\n\n\n";
            cout << "\t\t\t\t--------------------------FACULTY MENU----------------------------\n\n"
                 << endl;
            cout << "\t\t\t\t 1. View profile\n\n";
            Sleep(300);
            cout << "\t\t\t STUDENT:\n";
            Sleep(300);
            cout << "\t\t\t\t 2. View existing Student record\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Upload Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 4. View Specific Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 5. Log Out\n\n";
            cout << "\t\t\t\t-------------------------------------------------" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-5> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                view_existing_faculty(f.id);
                goto start;
                break;
            }
            case '2':
            {
                int k;
                cout << "\n\nENTER STUDENT ID TO VIEW PROFILE : ";
                cin >> k;
                view_existing_student_faculty(k);
                goto start;
                break;
            }
            case '3':
            {
                int k;
                cout << "\n\nENTER STUDENT ID TO UPLOAD MARKS : ";
                cin >> k;
                upload_marks(k);
                goto start;
                break;
            }
            case '4':
            {
                int k;
                cout << "\n\nENTER STUDENT ID TO VIEW RESULT : ";
                cin >> k;
                view_specific_marks(k);
                goto start;
                break;
            }
            case '5':
            {
                home();
                break;
            }
            }
            equality = true;
        }
    }
    infile.close();
    if (!equality) {
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press 'H' key to continue...";
        char a;
        cin >> a;
        if (a=='h'||a=='H')
            home();
    }
}

void login_student() {
    char cc;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t           Login As Student \n\n";
    cout << "\t\t\t\t-----------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t\t\t Enter your ID and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t\t ID: ";
    cin >> id;
    cout << "\t\t\t\t\t Password: ";
    char ch = _getch();
    while (ch != 13) {
        if (ch == 8) {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    try{
    if (infile.fail()) {
        cin.ignore();
        throw invalid_argument("File opening failed.\n");
    }}
    catch(const invalid_argument &e){
    cout<<"Error! "<<e.what()<<endl;
    cin.get();
    return;
}
    bool equality = false;
    system("cls");
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
        if (s.id == id && s.pass == password) {
             start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t\t   Welcome " << s.name << "\n\n\n";
            cout << "\t\t\t\t---------------------- STUDENT MENU ---------------------------\n\n"
                 << endl;
            cout << "\t\t\t\t 1. View profile\n\n";
            Sleep(300);
            cout << "\t\t\t\t 2. View Result.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Log Out\n\n";
            cout << "\t\t\t\t-------------------------------------------" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-3> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                view_existing_student(s.id);
                goto start;
                break;
            }
            case '2':
            {
                if (publishResult == 1)
                    view_specific_marks(s.id);
                else
                {
                    cout << "\n\n\n\t\tResult Not Uploaded Yet. Contact Admin \n\n";
                    cout << "\t\tPress enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                goto start;
                break;
            }
            case '3':
            {
                home();
                break;
            }
            }

            equality = true;
        }
    }
    infile.close();
    if (!equality){
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "Press 'H' key to continue...";
        char a;
        cin >> a;
        if (tolower(a) == 'h')
            home();
    }
}


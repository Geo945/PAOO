#include<iostream>

using namespace std;

enum Sex { M = 'M', F = 'F' };

class Uncopyable {
protected: // allow construction
    Uncopyable() {} // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable&); // ...but prevent copying
    Uncopyable& operator=(const Uncopyable&);
};

class UPTUniversity: private Uncopyable{
private:
    std::string name;
    std::string email;
public:
    UPTUniversity(const std::string& name, const std::string& email);
    std::string getEmail();
};

UPTUniversity::UPTUniversity(const std::string& name, const std::string& email)
    :name(name),
     email(email)
{}

std::string UPTUniversity::getEmail(){
    return email;
}

UPTUniversity& UPT() {
    static UPTUniversity upt("Politehnica", "email@upt.ro");
    return upt;
}

class StudentUPT {
private:
    std::string firstName;
    std::string lastName;
    Sex sex;
    int age;
    int birthYear;
    int birthMonth;
    int birthDay;

public:
    // Constructor
    StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth,const int birthDay);
    // Copy Constructor
    StudentUPT(const StudentUPT &stud);
    // Destructor
    ~StudentUPT();
    // copy assignment operator
    StudentUPT& operator=(const StudentUPT &stud);
    // c++ compiler creates constructor, copy constructor, destructor and assign operator functions if you dont have them
    void toString();
};

// Destructor implementation
StudentUPT::~StudentUPT() {};

// copy assignment operator implementation
StudentUPT &StudentUPT::operator=(const StudentUPT &stud) {
    firstName =  stud.firstName;
    lastName =  stud.lastName;
    sex = stud.sex;
    age =  stud.age;
    birthYear = stud.birthYear;
    birthMonth = stud.birthMonth;
    birthDay = stud.birthDay;

    return *this;
};

// Constructor implementation
StudentUPT::StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth,const int birthDay)
        :firstName(firstName),
         lastName(lastName),
         sex(sex),
         age(age),
         birthYear(birthYear),
         birthMonth(birthMonth),
         birthDay(birthDay)
{}

// Copy constructor implementation
StudentUPT::StudentUPT(const StudentUPT &stud) {
    firstName =  stud.firstName;
    lastName =  stud.lastName;
    sex = stud.sex;
    age =  stud.age;
    birthYear = stud.birthYear;
    birthMonth = stud.birthMonth;
    birthDay = stud.birthDay;
}

void StudentUPT::toString(){
    cout<<endl<<"firstName: "<<firstName;
    cout<<endl<<"lastName: "<<lastName;
    cout<<endl<<"sex: "<<(char)sex;
    cout<<endl<<"age: "<<age;
    cout<<endl<<"birthYear: "<<birthYear;
    cout<<endl<<"birthMonth: "<<birthMonth;
    cout<<endl<<"birthDay: "<<birthDay;
    cout<<endl<<"University email: "<<UPT().getEmail();
    cout<<endl;
}

int main() {
    StudentUPT studentUpt("Johnutule", "Ciocanim", M, 34, 2000, 10, 23);
    StudentUPT studentUpt2(studentUpt);
    StudentUPT studentUpt3 = studentUpt2;

    studentUpt.toString();
    cout<<endl;
    studentUpt2.toString();
    cout<<endl;
    studentUpt3.toString();

    UPTUniversity university("UPT", "email@yahoo.com");
    // Compile error pentru ca am exclus crearea de copy constructor;
    // Putem face asta si la execution time daca declaram direct metoda private in clasa respectiva fara sa extidenm clasa Uncopyable
    // UPTUniversity university1 = university

    return 0;
}
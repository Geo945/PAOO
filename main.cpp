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

class Phone {
private:
    std::string phone;
    std::string number;
public:
    Phone(){};
    Phone(const std::string phone, const std::string number);
    std::string getNumber();
    std::string getPhone();
};

Phone::Phone(const std::string phone, const std::string number)
    :phone(phone),
    number(number)
{}

std::string Phone::getNumber(){
    return number;
}

std::string Phone::getPhone(){
    return phone;
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
//    Phone *phone = new Phone("Samsung", "0727337520");
    Phone *phone;

public:
    // Constructor
    StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth, const int birthDay, const std::string phone, const std::string number);
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

    if(this == &stud) return *this;

    firstName =  stud.firstName;
    lastName =  stud.lastName;
    sex = stud.sex;
    age =  stud.age;
    birthYear = stud.birthYear;
    birthMonth = stud.birthMonth;
    birthDay = stud.birthDay;

    Phone *phn = phone;
    phone = new Phone(*stud.phone);
    delete phn;

    return *this;
};

// Constructor implementation
StudentUPT::StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth, const int birthDay,  const std::string phone, const std::string number)
        :firstName(firstName),
         lastName(lastName),
         sex(sex),
         age(age),
         birthYear(birthYear),
         birthMonth(birthMonth),
         birthDay(birthDay),
         phone(new Phone(phone, number))
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
    phone = stud.phone;
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
    cout<<endl<<phone->getPhone()<<" "<<"phone: "<<phone->getNumber();
}

class ScholarshipStudentUpt: public StudentUPT {
private:
    int scholarshipAmount;

public:
    ScholarshipStudentUpt(const StudentUPT &stud, const int scholarshipAmount);
    ScholarshipStudentUpt& operator=(const ScholarshipStudentUpt &stud);
    void toString();
};

ScholarshipStudentUpt::ScholarshipStudentUpt(const StudentUPT &stud, const int scholarshipAmount)
    :StudentUPT(stud),
    scholarshipAmount(scholarshipAmount)
{}

ScholarshipStudentUpt& ScholarshipStudentUpt::operator=(const ScholarshipStudentUpt &stud) {
    if(this == &stud) return *this;

    StudentUPT::operator=(stud);
    scholarshipAmount = stud.scholarshipAmount;

    return *this;
}

void ScholarshipStudentUpt::toString() {
    StudentUPT::toString();
    cout<<endl;
    cout<<"Scholar ship amount: "<<scholarshipAmount;
    cout<<endl;
}


int main() {
    StudentUPT studentUpt("firstName", "lastName", M, 34, 2000, 10, 23, "Samsung", "0733447529");
    StudentUPT studentUpt2(studentUpt);
    StudentUPT studentUpt3 = studentUpt2;

    studentUpt.toString();
    cout<<endl;
    studentUpt2.toString();
    cout<<endl;
    studentUpt3.toString();
    cout<<endl;

    UPTUniversity university("UPT", "email@yahoo.com");
    // Compile error pentru ca am exclus crearea de copy constructor;
    // Putem face asta si la execution time daca declaram direct metoda private in clasa respectiva fara sa extidenm clasa Uncopyable
    // UPTUniversity university1 = university

    ScholarshipStudentUpt scholarshipStudentUpt(studentUpt, 999);
    scholarshipStudentUpt.toString();
    cout<<endl;

    ScholarshipStudentUpt scholarshipStudentUpt1 = scholarshipStudentUpt;
    scholarshipStudentUpt1.toString();

    return 0;
}
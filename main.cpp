#include<iostream>

using namespace std;

enum Sex { M = 'M', F = 'F' };

class UPTUniversity {
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
    StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth,const int birthDay);
    void toString();
};

StudentUPT::StudentUPT(const std::string &firstName, const std::string &lastName, const Sex sex, const int age, const int birthYear, const int birthMonth,const int birthDay)
        :firstName(firstName),
         lastName(lastName),
         sex(sex),
         age(age),
         birthYear(birthYear),
         birthMonth(birthMonth),
         birthDay(birthDay)
{}

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
    StudentUPT studentUpt("Johnule", "Ciocanim", M, 34, 2000, 10, 23);

    studentUpt.toString();

    return 0;
}
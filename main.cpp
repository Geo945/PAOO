#include<iostream>

using namespace std;

enum Sex {
    'M', 'F'
};

class Customer {
private:
    std::string firstName;
    std::string lastName;
    Sex sex;
    int age;
    int birthYear;
    int birthMonth;
    int birthDay;

public:
    Customer(
            const std::string &firstName,
            const std::string &lastName,
            const Sex sex,
            const int age,
            const int birthYear,
            const int birthMonth,
            const int birthDay
    ){
        firstName(firstName);
        lastName(lastName);
        sex(sex);
        age(age);
        birthYear(birthYear);
        birthMonth(birthMonth);
        birthDay(birthDay);
    }

    toString(){
        cout<<endl<<"firstName: "<<firstName;
        cout<<endl<<"lastName: "<<lastName;
        cout<<endl<<"sex: "<<sex;
        cout<<endl<<"age: "<<age;
        cout<<endl<<"birthYear: "<<birthYear;
        cout<<endl<<"birthMonth: "<<birthMonth;
        cout<<endl<<"birthDay: "<<birthDay;
        cout<<endl;
    }
};

int main() {
    Customer customer("Alkio", "DeyuV", 'M', 34, 2000, 10, 23);
    return 0;
}
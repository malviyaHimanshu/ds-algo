// Object Oriented Programming in C++

#include<iostream>
#include<string>
#pragma GCC optimise("Ofast")
using namespace std;

class Student {
    // data members
    // Private - by default
    string name;
    int age;
    bool gender;

    public:
        // default contructor
        Student() {
            cout<<"Default Constructor"<<endl;
            this->name = "";
            this->age = 0;
            this->gender = 0;
        }

        // parameterized constructor
        Student(string name, int age, bool gender) {
            cout<<"Parameterised Constructor"<<endl;
            this->name = name;
            this->age = age;
            this->gender = gender;
        }

        // Default Copy constructor do shallow copy (copies the pointer to object)
        // Copy constructor (this does deep copy i.e. copies address as well as values)
        Student(Student &a) {
            cout<<"Copy Constructor"<<endl;
            this->name = a.name;
            this->age = a.age;
            this->gender = a.gender;
        }

        // Destructor
        ~Student() {
            cout<<"Destructor"<<endl;
        }

        void set(string s) {
            this->name = s;
        }
        void getName() {
            cout<<this->name<<endl;
        }

        void display() {
            cout<<"Name : "<<this->name<<endl;
            cout<<"Age : "<<this->age<<endl;
            cout<<"Gender : "<<this->gender<<endl;
        }

        // Operator Overloading
        bool operator == (Student &a) {
            if(name==a.name && age==a.age && gender==a.gender) {
                return true;
            }
            return false;
        }
};

int main() {
    // single object
    Student a;

    // array of objects
    Student arr[3];
    // for(int i=0; i<3; i++) {
    //     cin>>arr[i].name;
    //     cin>>arr[i].age;
    //     cin>>arr[i].gender;
    // }

    Student s1("Andrew", 19, 0);
    s1.display();

    Student copyOfS1 = s1;
    copyOfS1.display();

    Student s2("Tristian", 18, 0);

    // Operator Overloading
    if(s2 == s1) {
        cout<<"Same"<<endl;
    } else {
        cout<<"Not Same"<<endl;
    }

    return 0;
}
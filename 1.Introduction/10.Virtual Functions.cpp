#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int professor_id = 0, student_id = 0;
class Person {
    public :
        Person() {}
        virtual void getdata() {};
        virtual void putdata() {};
    
    protected :
    string name;
        int age;
};

class Professor : public Person {
    public :
        Professor() {
            ++professor_id;
        }
        void getdata() {
            cin >> name >> age >> publications;
            cur_id = professor_id;
        }
        void putdata() {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
    private :
        int publications;
        int cur_id;
};

class Student : public Person {
    public :
        Student() {
            ++student_id;
        }
        void getdata() {
            cin >> name >> age;
            for(int i = 0; i < 6; i++) cin >> marks[i];
            cur_id = student_id;
        }
        void putdata() {
            int sum = 0;
            for(int i = 0; i < 6; i++) sum += marks[i];
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
    private :
        int marks[6];
        int cur_id;
};

int main(){

    int n, val;
    cin>>n;
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            per[i] = new Professor;
        }
        else per[i] = new Student;

        per[i]->getdata();
    }

    for(int i=0;i<n;i++)
        per[i]->putdata();

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
using namespace std;

class Person
{
    private: 
        string name;
        int age;
        static int students;
        static int professors;
        
    public:
        Person(){}
        static int increment_student(){
            int id = Person::students;
            Person::students = id + 1;
            return id;
        }
        static int increment_professor(){
            int id = Person::professors;
            Person::professors = id + 1;
            return id;
        }
        virtual void getdata(){}
        virtual void putdata(){}
        void setparams(string&& n , int a){
            //setting name and age...
            this->name = std::move(n);
            this->age = a;
        }
        void getParams(){
            cout << this->name << " " << this->age << " ";
        }

};

class Professor : public Person
{
    private:
        int publications;
        int cur_id;

    public: 
        Professor(){
            // setting the professors id!
            this->cur_id = Person::increment_professor();
        }
        
        void getdata(){
            string n;
            int a;
            
            std::cin >> n;
            std::cin >> a;

            // setting person params!
            Person::setparams(std::move(n) , a);
            // setting professors publications!
            std::cin >> this->publications;
        }   

        void putdata(){
            Person::getParams();
            cout << this->publications << " "  << this->cur_id << endl;
        }
};

class Student : public Person
{
    private :
        int marks[6];
        int cur_id;
    
    public:
        Student()
        {
            this->cur_id = Person::increment_student();
        }

        void getdata(){
            string n;
            int a;

            std::cin >> n;
            std::cin >> a;

            for (int i = 0 ; i < 6 ; i++)
                std::cin >> marks[i];

            Person::setparams(std::move(n) , a);
        }   

        void putdata(){
            int total = 0;
            for(int i = 0 ; i < 6 ; i++)
                total += this->marks[i];
            
            Person::getParams();
            cout << total << " " << this->cur_id << endl;
        }
};

// STATIC SPACE
int Person::students = 1;
int Person::professors = 1;


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

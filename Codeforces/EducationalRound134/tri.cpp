#include<iostream>
#include<string.h>
using namespace std;
class Employee{
    int empID;
    string name;
    string address;
    string designation;
    int salary;
public:
    Employee(){
        empID = 0;
        salary = 0;
    }
    Employee(int emp_id, string Name, string add, string desg, int sal){
        empID = emp_id;
        name = Name;
        address = add;
        designation = desg;
        salary = sal;
    }
    void display(){
        cout << "Employee Id : " << empID << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Designation : " << designation << endl;
        cout << "Salary : " << salary << endl;
    }
    void get_id(){
        cout << "Enter EMP ID : ";
        cin >> empID;
        cout << endl;
    }
    void get_name(){
        cout << "Enter name of employee : " ;
        cin >> name ;
        cout << endl;
    }
    void get_add(){
        cout << "Enter address of employee : " ;
        cin >> address;
        cout << endl;
    }
    void get_desg(){
        cout << "Enter designation of employee : " ;
        cin >> designation;
        cout << endl;
    }
    void get_sal(){
        cout << "Enter salary of employee : " ;
        cin >> salary;
        cout << endl;
    }
    void input_data(){
        get_id();
        get_name();
        get_add();
        get_desg();
        get_sal():
    }
    void output_data(){
        cout << "Employee ID : " << empId << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Designation : " << designation << endl;
        cout << "Salary : " << salary << endl;
    }
};
int main(){
    cout << "Welcome administrator !!!" << endl ;
    int NUMBER_EMPLOYEES;
    cout << "Enter the number of employees : " << endl;
    cin >> NUMBER_EMPLOYEES;
    Employee* employe[NUMBER_EMPLOYEES];
    for(int i = 0; i < NUMBER_EMPLOYEES; ++i){
        cout << "Enter data for employee : " << i + 1 << endl;
        employee[i] = new Employee();
        employeee[i] -> input_data();
    }
    for(int i = 0; i < NUMBER_EMPLOYEES; ++i){
        employee[i] -> output_data();
    }
}
    
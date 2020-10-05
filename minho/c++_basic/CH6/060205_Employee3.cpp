#include <iostream>
#include <string>

class Employee {
    protected:
        std::string name;
        int age;

        std::string position;
        int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}
        Employee(const Employee& employee){
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        virtual void print_info() {
            std::cout << name << " ( " << position << " , " << age << " ) == > "
                << calculate_pay() << " 만원\n";
        }

        virtual int calculate_pay() { return 200 + rank * 50;}
};


class Manager : public Employee {
    int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : Employee(name, age, position, rank)
                ,year_of_service(year_of_service) {}

        Manager(const Manager& manager)
            : Employee(manager.name, manager.age, manager.position, manager.rank)
                ,year_of_service(year_of_service) {}
        
        Manager() : Employee() {}

        int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }

        void print_info() override {
            std::cout << name << " ( " << position << " , " << age << " , " << year_of_service 
                <<" ) == > " << calculate_pay() << " 만원\n";
        }
};


class Employee_list {
    int alloc_employee;         //total employee num
    int current_employee;       //current employee num

    Employee **employee_list;   //employee data

    public:
        Employee_list(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee* [alloc_employee];
            current_employee = 0;
        }

        void add_employee(Employee* employee){
            employee_list[current_employee] = employee;
            current_employee++;
        }

        int current_employee_num() { return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for(int i = 0; i < current_employee; i++){
                employee_list[i] -> print_info();
                total_pay += employee_list[i] -> calculate_pay();
            }   //This is Polymorphism. It calls one func but operate two works.

            std::cout << "total pay  : " << total_pay << " 만원  \n";
        }

        ~Employee_list() {
            for(int i = 0; i< current_employee; i++){
                delete employee_list[i];
            }

            delete[] employee_list;
        }
};



int main()
{
    Employee_list emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원" ,1));
    emp_list.add_employee(new Employee("하하", 34, "평사원" ,1));
    emp_list.add_employee(new Manager("유재석", 41, "부장" ,7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장" ,4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장" ,5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리" ,2));
    emp_list.add_employee(new Employee("길", 36, "인턴" ,-2));
    emp_list.print_employee_info();

    return 0;
}
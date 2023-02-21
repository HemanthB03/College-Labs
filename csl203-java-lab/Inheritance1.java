class Employee {
    String name, address;
    int age, phone;
    double salary;

    public Employee(String name, int age, int phone, double salary, String address) {
        this.name=name;
        this.age=age;
        this.phone=phone;
        this.salary=salary;
        this.address=address;
    }

    void printSalary() {
        System.out.println("Salary: "+salary);
    }

    void printDetails() {
        System.out.println("Name: "+name+"\nAge: "+age+"\nPhone No: "+phone+"\nAddress: "+address);
    }
}

class Officer extends Employee {
    String specialization;

    public Officer(String name, int age, int phone, double salary, String address, String specialization) {
        super(name, age, phone, salary, address);
        this.specialization=specialization;
    }
}

class Manager extends Employee {
    String department;

    public Manager(String name, int age, int phone, double salary, String address, String department) {
        super(name, age, phone, salary, address);
        this.department=department;
    }
}

public class Inheritance1 {
    public static void main(String[] args) {
        Officer officer=new Officer("Bob", 54, 1234212, 20000.0, "Bobvile, Street 3", "Officer of Cleaning");
        Manager manager=new Manager("Jeff", 32, 9242823, 5000000.0, "Jeffrey Town", "Department of Human Resources");

        officer.printDetails();
        officer.printSalary();

        System.out.println();

        manager.printDetails();
        manager.printSalary();
    }
}

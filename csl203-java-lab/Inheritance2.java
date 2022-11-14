class Employee {
    void printName(String name) {
        System.out.println("Name of class is " + name);
    }
    void printSalary(String name, float salary) {
        System.out.println("Salary of " + name + " is " + salary);
    }
}

class Engineer extends Employee {

}

//name of netbeans project should be Inheritance2
public class Inheritance2 {
    public static void main(String[] args) {
        Engineer e = new Engineer();
        e.printName("Employee");
        e.printSalary("Employee", 20000);
        e.printName("Engineer");
        e.printSalary("Engineer", 250000);
    }
}

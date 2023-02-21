class Employee {
    void display(String name) {
        System.out.println("Name of class is "+name);
    }
    void calcSalary(String name, int salary) {
        System.out.println("Salary of "+name+" is "+salary);
    }
}

class Engineer extends Employee {

}

public class Inheritance2 {
    public static void main(String[] args) {
        Engineer eng=new Engineer();
        eng.display("Employee");
        eng.calcSalary("Employee", 10000);
        eng.display("Engineer");
        eng.calcSalary("Engineer", 20000);
    }
}

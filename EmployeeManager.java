import java.util.*;
class Employee
{
	String name;
	String department;
	int id;
	int salary;
	
	Employee(String name, String department, int id, int salary)
	{
		this.name=name;
		this.department=department;
		this.id=id;
		this.salary=salary;
	}
	public String toString()
	{
		return("Name:"+name+"\nDepartment:"+department+"\nID:"+id+"\nSalary:"+salary);
	}
}

class DuplicateEntryException extends RuntimeException
{
	DuplicateEntryException(String message)
	{
		super(message);
	}
}

class EmployeeManager
{
	public static void main(String args[]) throws DuplicateEntryException
	{
		ArrayList<Employee> employees=new ArrayList<>();
		int choice;
		String name;
		String department;
		int id;
		int salary;
		Scanner sc=new Scanner(System.in);
		do
		{
			System.out.println("1.Add an employee\n2.Remove an employee\n3.Display all employees\n4.Exit");
			choice=sc.nextInt();
			switch(choice)
			{
				case 1:
				System.out.println("Enter employee details:");
				System.out.print("Enter name:");
				sc.nextLine();
				name=sc.nextLine();
				System.out.print("Enter department:");
				department=sc.nextLine();
				System.out.print("Enter ID:");
				id=sc.nextInt();
				for(Employee e:employees)
				{
					if(e.id==id)
						throw new DuplicateEntryException("Duplicate entry not allowed!");
				}
				System.out.print("Enter salary:");
				salary=sc.nextInt();
				employees.add(new Employee(name,department,id,salary));
				break;
				case 2:
				System.out.print("Enter id of employee to be removed:");
				int idToRemove=sc.nextInt();
				employees.removeIf(e->e.id==idToRemove);
				break;
				case 3:
				for(Employee e:employees)
				System.out.println(e);
				break;
				case 4:
				break;
			}
		}while(choice!=4);
	}
}
```java
import java.util.Scanner;

public class FirstJavaClass {

	public static void main(String[] kuchbhi) {
		
		 int, float, char, String, long, double, boolean
		
		int marks = 18;
		float averageMarks = 19.345f;
		char grade = 'A';
		String name = "Anuj";
		boolean isValid = false;

		long bigNumber = 98749823749823l;
		
		System.out.println(averageMarks);
		
		
		 +, -, /, *, %, ++, --
		
		int firstNumber = 1234;
		int secondNumber = 234;
		
		double sum = (double)firstNumber % (double)secondNumber;
		System.out.println(sum);
		
		int a = 12;
		 this statement increments by 1
		a = a + 1;
		System.out.println(++a);
		System.out.println(a);
		a--;
		System.out.println(a);
		// assignment =
		
		//Taking user input
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your name: ");
		String name = sc.nextLine();

		System.out.println(name);
		
		int age = 12;
		
		 >, <, >=, <=, ==, !=
		
		if ( age > 18 ) {
			System.out.println("you can vote");
		} else {
			System.out.println("you can not vote");
		}
		
		// && , ||, !
		
		int age = 12;
		if ( !(age > 18) ) {
	System.out.println("you can vote");
		} else {
			System.out.println("you can not vote");
		}
		
		
		boolean isEqual = 18 == 18;
		System.out.println(19 != 18);
		
		char grade = 'D';
		
		if(grade == 'A') {
			System.out.println("your grade is very good");
		} else if (grade == 'B') {
			System.out.println("very good, keep learning");
		} else if(grade == 'D') {
			System.out.println("keep improving");
		} else {
			System.out.println("invalid grade");
		}
		
		switch case
		
		char grade = 'R';
		
		switch(grade) {
		case 'A':
			System.out.println("your grade is very good");
			break;
		case 'B':
			System.out.println("very good, keep learning");
			break;
		case 'C':
			System.out.println("Nice keep going");
			break;
		default:
			System.out.println("wrong argument");
	}
		
		 for, while, do-while
		
		 for(;;)
		
		for(int i = 0; i < 10; i++) {
			System.out.println("Anuj" + i);
		}
		int a = 23;
		while(a <= 100) {
			a++;
			if ( a == 65 ) continue;
			System.out.println(a);
		}
		int a = 23;
		do {
			System.out.println(a);
			a++;
		} while(a > 100);
		
		 array
		 23, 12, 56, 34, 99
		
		int marks[] = new int[5];
		marks[0] = 23;
		marks[1] = 12;
		marks[2] = 56;
		marks[3] = 34;
		marks[4] = 99;
		
		int marks[] = {23, 12, 56, 34, 99, 12, 34};
		
		for(int i = 0; i<=marks.length; i++) {
			System.out.println(marks[i]);
		}
		
		int a[][] = new int[2][3];
int a[][] = {
				{
					1, 2
				}, {
					3, 4
				}
			};
		System.out.println(a[1][0]);
		
		System.out.println(average(3, 6));
		System.out.println(average(4, 6));
		
		int a[] = new int[3];
		
		try {
			System.out.println(2/0);
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Error aaya tha");
			System.out.println(e.getLocalizedMessage());
		} catch(ArithmeticException e) {
			
		}
		
		System.out.println("niche ki line");
		
		String a = "hi";
		String b = "hi";
		
		String state = "  New Delhi  ";
		System.out.println(a == b);
		System.out.println(a.equals(b));
		
		System.out.println(1 + (int)(6*Math.random()));
		
	}
	
	
	 method
	
	 returnType functionName (arguments) {}
	
	static int average(int firstNumber, int secondNumber) {
		int sum = firstNumber + secondNumber;
		return sum / 3;
	}

}

```

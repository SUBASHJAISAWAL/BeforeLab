import java.util.Scanner;
import cie.*;
import see.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine(); 

        Internals cie[] = new Internals[n];
        External see[] = new External[n];

        for (int i = 0; i < n; i++) {
            cie[i] = new Internals();
            see[i] = new External();

            System.out.println("\nEnter details for Student " + (i + 1));

            System.out.print("USN: ");
            String usn = sc.nextLine();

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Semester: ");
            int sem = sc.nextInt();

            cie[i].getDetails(usn, name, sem);
            see[i].getDetails(usn, name, sem);

            int internalMarks[] = new int[5];
            int seeMarks[] = new int[5];

            System.out.println("Enter 5 Internal marks: ");
            for (int j = 0; j < 5; j++)
                internalMarks[j] = sc.nextInt();
            cie[i].setInternalMarks(internalMarks);

            System.out.println("Enter 5 SEE marks: ");
            for (int j = 0; j < 5; j++)
                seeMarks[j] = sc.nextInt();
            see[i].setSEEMarks(seeMarks);

            sc.nextLine(); 
        }

        System.out.println("\n=== Final Marks of Students ===");
        for (int i = 0; i < n; i++) {
            cie[i].displayDetails();
            System.out.println("Final Marks (out of 100): ");
            for (int j = 0; j < 5; j++) {
                int finalMark = cie[i].internalMarks[j] + (see[i].seeMarks[j] / 2);
                System.out.println("Course " + (j + 1) + ": " + finalMark);
            }
            System.out.println("-----------------------------");
        }

        sc.close();
    }
}

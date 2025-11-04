import java.util.Scanner;

class Account {
    String name;
    String accNo;
    String accType;
    double balance;

    void inputDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter customer name: ");
        name = sc.nextLine();
        System.out.print("Enter account number: ");
        accNo = sc.nextLine();
        System.out.print("Enter account type (Savings/Current): ");
        accType = sc.nextLine();
        System.out.print("Enter initial balance: ");
        balance = sc.nextDouble();
        sc.nextLine(); 
    }

    void deposit() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter deposit amount: ");
        double amt = sc.nextDouble();
        balance += amt;
        sc.nextLine(); 
    }

    void withdraw() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter withdrawal amount: ");
        double amt = sc.nextDouble();
        sc.nextLine(); 
        if (balance >= amt) {
            balance -= amt;
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    void displayBalance() {
        System.out.println("Final balance: " + balance);
    }
}

class SavAcct extends Account {
    void computeInterest() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of years: ");
        int years = sc.nextInt();
        sc.nextLine(); 
        double interest = balance * 0.05 * years;
        balance += interest;
        System.out.println("Interest added: " + interest);
    }
}

class CurAcct extends Account {
    void checkMinimum() {
        if (balance < 1000) {
            balance -= 100;
            System.out.println("Penalty of 100 imposed due to low balance.");
        } else {
            System.out.println("Minimum balance maintained.");
        }
    }
}

public class Bank {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 1; i <= 2; i++) {
            System.out.println("\n--- Enter details for User " + i + " ---");
            System.out.print("Enter account type (Savings/Current): ");
            String type = sc.nextLine();

            if (type.equalsIgnoreCase("Savings")) {
                SavAcct s = new SavAcct();
                s.inputDetails();
                s.deposit();
                s.computeInterest();
                s.withdraw();
                s.displayBalance();
            } else if (type.equalsIgnoreCase("Current")) {
                CurAcct c = new CurAcct();
                c.inputDetails();
                c.deposit();
                c.withdraw();
                c.checkMinimum();
                c.displayBalance();
            } else {
                System.out.println("Invalid account type.");
            }
        }

        sc.close();
    }
}

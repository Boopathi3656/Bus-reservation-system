import java.util.Scanner;
public class Bankmanagment {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Account account = new Account(1000.00, "1234");
        System.out.print("Enter your PIN: ");
        String inputPin = scanner.nextLine();
        if (!account.authenticate(inputPin)) {
            System.out.println("Incorrect PIN");
            scanner.close();
            return;
        }
        int choice;
        do {
            System.out.println("\nATM Menu:");
            System.out.println("1. Check Balance");
            System.out.println("2. Deposit Money");
            System.out.println("3. Withdraw Money");
            System.out.println("4. Exit");
            System.out.print("Enter choice (1-4): ");
            while (!scanner.hasNextInt()) {
                System.out.println("Please enter a number from 1 to 4.");
                scanner.next();
                System.out.print("Enter choice (1-4): ");
            }
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Current Balance: " + account.getBalance());
                    break;
                case 2:
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 3:
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 4:
                    System.out.println("Thank you");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 4);
        scanner.close();
    }
}
class Account {
    private double balance;
    private final String pin;
    public Account(double initialBalance, String pin) {
        this.balance = initialBalance;
        this.pin = pin;
    }
    public boolean authenticate(String inputPin) {
        return this.pin.equals(inputPin);
    }
    public double getBalance() {
        return balance;
    }
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Successfully deposited: " + amount);
        } else {
            System.out.println("Invalid deposit amount");
        }
    }
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Successfully withdrew: " + amount);
        } else {
            System.out.println("Insufficient balance or invalid amount");
        }
    }
}
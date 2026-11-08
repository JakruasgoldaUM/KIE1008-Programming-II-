#include <iostream>
using namespace std;

// ==========================================
// a) Base Class: bankAccount
// ==========================================
class bankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor with validation
    bankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Error: Initial balance was invalid. Balance set to 0.0." << endl;
        }
    }

    // i. Add amount to current balance
    virtual void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // ii. Withdraw money with validation
    virtual void debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
        } else if (amount > 0) {
            balance -= amount;
        }
    }

    // iii. Return current balance
    double getBalance() const {
        return balance;
    }

    // iv. Print account information
    virtual void printInfo() const {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << endl;
    }
};

// ==========================================
// b) Derived Class: savingsAccount
// ==========================================
class savingsAccount : public bankAccount {
private:
    double interestRate; // Percentage
    double fee;          // Added to satisfy the fee deduction requirement

public:
    // Constructor initializes base class, interest rate, and transaction fee
    savingsAccount(int accNum, double initialBalance, double rate, double transactionFee) 
        : bankAccount(accNum, initialBalance) {
        interestRate = rate;
        fee = transactionFee;
    }

    // Calculate interest earned
    double calculateInterest() const {
        // Assuming interestRate is passed as a percentage (e.g., 5.0 for 5%)
        return getBalance() * (interestRate / 100.0);
    }

    // Redefined credit: adds amount, then subtracts fee
    void credit(double amount) override {
        bankAccount::credit(amount);
        bankAccount::debit(fee); // Subtract fee after successful credit
    }

    // Redefined debit: withdraws amount, subtracts fee only if withdrawal succeeded
    void debit(double amount) override {
        double currentBalance = getBalance();
        bankAccount::debit(amount);
        
        // If balance decreased, the debit was successful, so apply the fee
        if (getBalance() < currentBalance) {
            bankAccount::debit(fee); 
        }
    }

    // Overridden printInfo to include savings-specific details
    void printInfo() const override {
        bankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "%" 
             << "\nTransaction Fee: $" << fee << endl;
    }
};

// ==========================================
// c) Main Test Program
// ==========================================
int main() {
    cout << "--- Testing Invalid Base Account ---" << endl;
    bankAccount badAccount(1001, -50.0); 
    badAccount.printInfo();
    
    cout << "\n--- Testing Savings Account ---" << endl;
    // Account 2001, $1000 balance, 5% interest rate, $2.00 fee per transaction
    savingsAccount mySavings(2001, 1000.0, 5.0, 2.0);
    mySavings.printInfo();

    cout << "\n> Crediting $200.00 to Savings..." << endl;
    mySavings.credit(200.0); // Should add 200, subtract 2 fee = 1198
    cout << "New Balance: $" << mySavings.getBalance() << endl;

    cout << "\n> Debiting $50.00 from Savings..." << endl;
    mySavings.debit(50.0); // Should subtract 50, subtract 2 fee = 1146
    cout << "New Balance: $" << mySavings.getBalance() << endl;

    cout << "\n> Attempting to debit $5000.00..." << endl;
    mySavings.debit(5000.0); // Should fail and NOT charge a fee
    cout << "Balance after failed debit: $" << mySavings.getBalance() << endl;

    cout << "\n> Calculating Interest..." << endl;
    double interestEarned = mySavings.calculateInterest();
    cout << "Interest Earned: $" << interestEarned << endl;
    
    cout << "\n> Adding Interest to Balance (No fee applied for this internal action)..." << endl;
    // Using base class credit explicitly to avoid the transaction fee for interest
    mySavings.bankAccount::credit(interestEarned); 
    mySavings.printInfo();

    return 0;
}
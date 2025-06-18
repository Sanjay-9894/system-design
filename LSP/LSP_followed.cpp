#include <iostream>
using namespace std;
#include <vector>

class NonWithdrwableAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAcc : public NonWithdrwableAccount {
    public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAcc{
private :
    double balance;

    public:
    SavingAccount(){
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAcc {
private:
    double balance;

public:
    CurrentAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount : public NonWithdrwableAccount{
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

};

class BankClient {
   private:
    vector<WithdrawableAcc*> withaccounts;
    vector<NonWithdrwableAccount*> depaccounts;

public:
    BankClient(vector<WithdrawableAcc*> withaccounts,
     vector<NonWithdrwableAccount*> depaccounts) { 
        this->withaccounts = withaccounts;
        this->depaccounts = depaccounts;
    }

        void processTransactions() {
        for (WithdrawableAcc* acc : withaccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (NonWithdrwableAccount* acc : depaccounts) {
            acc->deposit(5000);
        }
    }
};



int main(){
    vector<WithdrawableAcc*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<NonWithdrwableAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

      BankClient* client = new BankClient (withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;

};
//Harris Dizdarevic
//Bank Accounts

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "bank.h"
using namespace std;

//New Prototypes
int read_accts(Bank&);
void print_accts(Bank&, ofstream&);
void menu();
int findacct(Bank&);
void balance(Bank&, ofstream&);
void deposit(Bank&, ofstream&);
void withdraw(Bank&, ofstream&);
int new_acct(Bank&, ofstream&);
int close_acct(Bank&, ofstream&);
int delete_acct(Bank&, ofstream&);
void reopen_acct(Bank&, ofstream&);
void account_info(Bank&, ofstream&);
void transaction_info(Bank&, ofstream&);
void accounthistory(Bank&, ofstream&);
void mypause(void);

int main()
{
    Bank bank;
    char selection;
    bool not_finished = true;

    ofstream output("con");
    //ofstream output("bankoutput.txt");

    output.setf(ios::fixed,ios::floatfield);
    output.precision(2);

    output << setw(55) << "Harris Dizdarevic's Bank Program" << endl << endl;

    read_accts(bank);
    print_accts(bank,output);

    do {
      menu();
      cin >> selection;
      switch(toupper(selection))
      {
        case 'Q':
          not_finished = false;
          print_accts(bank, output);
          accounthistory(bank, output);
          break;

        case 'B':
          balance(bank, output);
          break;

        case 'D':
          deposit(bank, output);
          break;

        case 'W':
          withdraw(bank, output);
          break;

        case 'I':
          account_info(bank, output);
          break;

        case 'H':
          transaction_info(bank, output);
          break;

        case 'N':
          new_acct(bank, output);
          break;

        case 'C':
          close_acct(bank, output);
          break;

        case 'R':
          reopen_acct(bank, output);
          break;

        case 'X':
         delete_acct(bank, output);
         break;

       default:
         output << endl << "Error: '" << selection
         << "' is an invalid selection - try again"
         << endl << endl;
         break;
      }

      mypause();

    } while (not_finished);

    output.close();

    return 0;
 }


 int read_accts(Bank &bank)
 {
    string first, last, ssn, type, status;
    int acctnum;
    double balance;

    ifstream input("database.txt");

    while (!input.eof())
    {
      input >> last;
      input >> first;
      input >> ssn;
      input >> acctnum;
      input >> type;
      input >> balance;
      bank.addAccount(acctnum, type, balance, Depositor(Name(first, last), ssn));
    }

    input.close();

    return bank.getActiveAccounts();
 }


 void print_accts(Bank &bank, ofstream &output)
 {
   const Account *account;
   Name name;

   output << endl;
   output << setw(52) << "Database of Bank Accounts" << endl << endl;
   output << "  Name "
          << setw(10) << "SSN "
          << setw(14) << "Account # "
          << setw(8) << "Type "
          << setw(14) << "Balance "
          << setw(10) << "Status " << endl;

   for (int i = 0; i < bank.getActiveAccounts(); ++i)
   {
     account = bank.getAccount(i);
     name = account->getDepositor().getName();

     output << bank.getAccount(i)->getDepositor().getName().getLastName()
            << " "
            << bank.getAccount(i)->getDepositor().getName().getFirstName()
            << " "
            << bank.getAccount(i)->getDepositor().getSSN() << " "
            << setw(7) << account->getAccountNumber() << " "
            << setw(11)<<account->getAccountType() << " "
            << setw(12) << account->getBalance() << " "
            << setw(8) << account->getAccountStatus() << endl;
   }
 }



 void menu()
 {
   cout << endl << endl;
   cout << "Select one of the following transactions:" << endl;
   cout << "\t****************************" << endl;
   cout << "\t* List of Choices *" << endl;
   cout << "\t****************************" << endl;
   cout << "\t I -- Account Information" << endl;
   cout << "\t W -- Withdrawal" << endl;
   cout << "\t D -- Deposit" << endl;
   cout << "\t N -- New Account" << endl;
   cout << "\t B -- Balance Inquiry" << endl;
   cout << "\t C -- Close Account (Not Deleting)" << endl;
   cout << "\t X -- Delete Account" << endl;
   cout << "\t H -- Account Information with Transaction History" << endl;
   cout << "\t R -- Reopen a Closed Account" << endl;
   cout << "\t Q -- Quit" << endl;
   cout << endl << "\tEnter your selection: ";
 }


 void balance(Bank &bank, ofstream &output)
 {
     Account *account;
     int requested_account, i;
     string type = "Balance Inquiry";

     cout << endl << "Enter the account number: ";
     cin >> requested_account;

     i = bank.findAccount(requested_account);
     if (i == -1)
     {
       output << endl << "Transaction Requested: Balance Inquiry" << endl;
       output << "Error: Account number " << requested_account
               << " does not exist" << endl;
     }
     else
     {
       account = bank.getAccount(i);
       output << endl << "Transaction Requested: Balance Inquiry" << endl;
       output << "Account Number: " << requested_account << endl;
       output << "Current Balance: $" << account->getBalance() << endl;
       account->addTransaction(type,account->getBalance());
     }
 }


void deposit(Bank &bank, ofstream &output)
{
     Account *account;
     int requested_account, i;
     string type = "Deposit";
     double deposit_amount;

     cout << endl << "Enter the account number: ";
     cin >> requested_account;


     i = bank.findAccount(requested_account);

     if (i == -1)
     {
       output << endl << "Transaction Requested: Deposit" << endl;
       output << "Error: Account number " << requested_account
               << " does not exist" << endl;
     }
     else
     {
        account = bank.getAccount(i);
        cout << "Enter amount to deposit: ";
        cin >> deposit_amount;

        if (deposit_amount <= 0.00)
        {
          output << endl << "Transaction Requested: Deposit" << endl;
          output << "Account Number: " << requested_account << endl;
          output << "Error: " << deposit_amount << " is an invalid amount"
                  << endl;
        }
        else
        {
          output << endl << "Transaction Requested: Deposit" << endl;
          output << "Account Number: " << requested_account << endl;
          output << "Old Balance: $" << account->getBalance() << endl;
          output << "Amount to Deposit: $" << deposit_amount << endl;
          account->makeDeposit(deposit_amount);
          output << "New Balance: $" << account->getBalance() << endl;
          bank.setAccount(*account, i);
          account->addTransaction(type,account->getBalance());
        }
      }
}

 void withdraw(Bank &bank, ofstream &output)
 {
    Account *account;
    int accounti, i;
    double withdraw_amt;
    string type = "Withdrawl";

    cout << endl << "Enter Account number: ";
    cin >> accounti;

    i = bank.findAccount(accounti);

    if(i == -1)
    {
      output << endl << "Transaction Requested: Withdrawl" << endl;
      output << "Account: " << accounti << " does not exist." << endl;
    }
    else
    {
      account = bank.getAccount(i);
      cout << endl << "Please enter amount to Withdraw: ";
      cin >> withdraw_amt;

      if(withdraw_amt <= 0.00)
      {
        output << endl << "Transaction Requested: Withdrawl" << endl;
        output << "Account: " << accounti << endl;
        output << "Error: " << withdraw_amt << " is an invalid amount."
                << endl;
      }

      if(account->makeWithdraw(withdraw_amt))
      {
         output << endl << "Transaction Requested: Withdrawl" << endl;
         output << "Account number: " << account->getAccountNumber() << endl;
         output << "Available Balance: " << account->getBalance() << endl;
         output << "Withdraw Amount: " << withdraw_amt << endl;
         output << "Error: Insufficient funds or Invalid Amount." << endl
                 << endl;
      }
      else
      {
         output << endl << "Transaction Requested: Withdrawl" << endl;
         output << "Account: " << account->getAccountNumber() << endl;
         output << "Previous Balance: " << account->getBalance() << endl;
         output << "Amount to Withdraw: " << withdraw_amt << endl;
         account->makeWithdraw(withdraw_amt);
         output << "Present Balance: " << account->getBalance() << endl;
         account->addTransaction(type,account->getBalance());
         bank.setAccount(*account, i);

      }
    }

}


 int new_acct(Bank &bank, ofstream &output)
 {
     string transtype = "Created Account";
     string lastn, firstn, socialsnum, acctype;

     int newaccount, i;

     cout << endl << "To create an Account enter a new account number." << endl;
     cin >> newaccount;
     i = bank.findAccount(newaccount);

     if(i != -1)
     {
       output << endl << "Creating new Account... Failed!" << endl;
       output << "Account number: " << newaccount << " already exists" << endl;
     }
     else
     {
       cout << "To finish completing your new account enter:" << endl;
       cout << "Last Name: " << endl;
       cin >> lastn;

       cout << "First Name: " << endl;
       cin >> firstn;

       cout << "Social Security Number: " << endl;
       cin >> socialsnum;

       cout << "Account Type: " << endl;
       cin >> acctype;

       cout << endl;

       bank.addAccount(newaccount, acctype, 0, Depositor(Name(firstn, lastn), socialsnum));
     }

     return bank.getActiveAccounts();
 }


int close_acct(Bank &bank, ofstream &output)
{
     Account *account;
     int close_acc, i;

     string transtype = "Closed Account";
     cout << "Enter an account number that you wish to delete: ";
     cin >> close_acc;

     i = bank.findAccount(close_acc);

     for(int accnumi = 0; accnumi < bank.getActiveAccounts(); accnumi++)
     {
       if(i == -1)
       {
         //Error Message
         output << endl << "Closing Account... incomplete" << endl;
         output << "Error: Account number: " << close_acc
                 << " does not exist." << endl;
         break;
       }
       else
        account = bank.getAccount(i);

       if(account->getBalance() > 0)
       {
         output << endl << "Error: Account " << account->getAccountNumber()
                 << " has a balance of: $" << account->getBalance()
                 << ". Please withdraw your balance "
                 << "before you can close your account!" << endl;
         break;
       }
       else
       {
         if(close_acc == account->getAccountNumber())
         {
           bank.closeAccount(account->getBalance(), i);
           output << endl << "Deleting Account... complete" << endl;
           output << "Account number: " << close_acc << " has been closed!"
                   << endl;
           account->addTransaction(transtype,account->getBalance());
           break;
         }
       }
     }
     return bank.getActiveAccounts();
}

int delete_acct(Bank &bank, ofstream &output)
{
     Account *account;
     int delete_acc, i;

     string transtype = "Deleted Account";
     cout << "Enter an account number that you wish to delete: ";
     cin >> delete_acc;

     i = bank.findAccount(delete_acc);

     for(int accnumi = 0; accnumi < bank.getActiveAccounts(); accnumi++)
     {
       account = bank.getAccount(i);

       if(i == -1)
       {
         //Error Message
         output << endl << "Deleting Account... incomplete" << endl;
         output << "Error: Account number: " << delete_acc << " does not exist."
                 << endl;
         break;
       }
       else
        if(account->getBalance() > 0)
        {
          output << endl << "Error: Account " << account->getAccountNumber()
                  << " has a balance of: $" << account->getBalance()
                  << ". Please withdraw your balance before "
                  << "you can delete your account!"
                  << endl;
          break;
        }
        else
          if(delete_acc == account->getAccountNumber())
          {
             bank.deleteAccount(account->getBalance(), i);
             output << endl << "Deleting Account... complete" << endl;
             output << "Account number: " << delete_acc << " has been deleted!"
                     << endl;

             break;
          }
      }
      return bank.getActiveAccounts();
}



void account_info(Bank &bank, ofstream &output)
{
   Account *account;
   int index, i; //two different indices
   string user_ssn;

   cout << "To view your account information, enter your Social Security "
        << "number: " << endl << endl;
   cin >> user_ssn;
   output << endl;

   i = bank.findAccountSSN(user_ssn);

   for (index = 0; index <= bank.getActiveAccounts(); index++)
   {
      if (i == -1)
      {
        output << "Error: SSN " << user_ssn << " does not exist!" << endl
                << endl;
        break;
      }
      else
      {
        account = bank.getAccount(i);
        output << "Full Account Information" << endl
                << "--------------------------------------------" << endl
                << endl;
        output << "Name: " << account->getDepositor().getName().getFirstName()
                << ", " << account->getDepositor().getName().getLastName()
                << endl;
        output << "SSN: " << account->getDepositor().getSSN()
                << endl;
        output << "Account #: " << account->getAccountNumber()
                << endl;
        output << "Type: " << account->getAccountType()
                << endl;
        output << "Balance: $" << account->getBalance()
                << endl;
        output << "Status: " << account->getAccountStatus()
                << endl;
        break;
      }

    }
}

void transaction_info(Bank &bank, ofstream &output)
{
   Account *account;
   int index , i; //two different indices
   string user_ssn;


   cout << "To view your account information, enter your Social Security "
        << "number: ";
   cin >> user_ssn;
   output << endl;

   i = bank.findAccountSSN(user_ssn);

   for (index = 0; index <= bank.getActiveAccounts(); index++)
   {
     if (i == -1)
     {
       output << "Error: SSN " << user_ssn << " does not exist!" << endl
              << endl;
       break;
     }
     else
     {
       account = bank.getAccount(i);
       output << "Full Account Information" << endl
               << "--------------------------------------------" << endl
               << endl;
       output << "Name: " << account->getDepositor().getName().getFirstName()
               << ", " << account->getDepositor().getName().getLastName()
               << endl;
       output << "SSN: " << account->getDepositor().getSSN()
               << endl;
       output << "Account #: " << account->getAccountNumber()
               << endl;
       output << "Type: " << account->getAccountType()
               << endl;
       output << "Balance: $" << account->getBalance()
               << endl;
       output << "Status: " << account->getAccountStatus()
               << endl << endl;
       output << "Transaction History" << endl
               << "--------------------------------------------"
               << endl;

      //for(int index = 0; index < bank.getActiveaccts(); index++)
      for(int _i = 0; _i < account->getNumTrans(); _i++)
      {
        output << "Action done: ";
        output << account->getTransaction(_i)->getTranType() << endl;
        output << "Transaction Amount: ";
        output << account->getTransaction(_i)->getTranAmount() << endl;
      }
      break;
    }
  }
}

void accounthistory(Bank &bank, ofstream &output)
{
   Account *account;
   int index;

   output << endl << setw(45) << "Transaction History" << endl << endl;

   for(index = 0; index < bank.getActiveAccounts(); index++)
   {
     account = bank.getAccount(index);
     output << "Account Number: " << account->getAccountNumber() << endl;
     for(int i_ = 0; i_ < account->getNumTrans(); i_++)
     {
       output << "Action done: ";
       output << account->getTransaction(i_)->getTranType() << endl;
       output << "Transaction Amount: ";
       output << account->getTransaction(i_)->getTranAmount() << endl;
     }
   }
}

void reopen_acct(Bank &bank, ofstream &output)
{
   Account *account;
   Name name;
   Depositor depositor;
   int reopacct;

   cout << "Enter the account number you wish to reopen: " << endl;
   cin >> reopacct;

   int index = bank.findAccount(reopacct);
   if(index == -1)
     cout << "Account: " << reopacct << " is not a valid account." << endl;
   else
   {
     account = bank.getAccount(index);
     if(account->getAccountStatus() == "Open")
      output << "Account: " << reopacct << " is already open." << endl;
     else
      if(account->getAccountStatus() == "Closed")
        account->setAccountStatus("Open");
   }

}

void mypause(void)
{
   system("pause");
   return;
}

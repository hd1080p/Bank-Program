#include "bank.h"
#include "account.h"

bool Bank::openAccount(int id){
	if (getAccount(id) == this->account.end())
		return true;
	return false;
}

bool Bank::deleteAccount(double balance, std::list<Account>::iterator it){
	if (balance != 0 || it != account.end()) {
		account.erase(it);
		return true;
	}
	return false;
}

void Bank::addAccount(int id, std::string type, double balance, Depositor depositor)
{ account.push_back(Account(id, type, balance, depositor)); }

bool Bank::closeAccount(double balance, int id){
	std::list<Account>::iterator it = getAccount(id);

	if (balance == 0 || it != account.end()) {
		it->setAccountStatus("Closed");
		return true;
	}

	return false;
}

bool Bank::reopenAccount(int id){
	std::list<Account>::iterator it = getAccount(id);

	if (it != account.end()) {
		it->setAccountStatus("Open");
		return true;
	}

	return false;
}

int Bank::getActiveAccounts() const
{ return account.size(); }

void Bank::setAccount(Account account, int id){
	std::list<Account>::iterator it = getAccount(id);
	*it = Account(account);
}


std::list<Account>::iterator Bank::getAccount(int id){
	std::list<Account>::iterator it = account.begin();

	while (it != account.end()){
		if (it->getAccountNumber() == id)
			return it;
		it++;
	}

	return account.end();
}

std::list<Account>::iterator Bank::getAccount(std::string ssn) {
	std::list<Account>::iterator it = account.begin();

	while (it != account.end()){
		if (it->getDepositor().getSSN() == ssn)
			return it;
		it++;
	}

	return account.end();
}

void Bank::print(std::ofstream &output){
   Account account;
   std::list<Account>::iterator it = this->account.begin();
   this->account.sort();

   output << std::endl;
   output << std::setw(52) << "Database of Bank Accounts" << std::endl << std::endl;
   output << "  Name "
          << std::setw(10) << "SSN "
          << std::setw(14) << "Account # "
          << std::setw(8) << "Type "
          << std::setw(14) << "Balance "
          << std::setw(10) << "Status " << std::endl;

   for(std::list<Account>::iterator it = this->account.begin(); it != this->account.end(); ++it)
   {
       account = *(getAccount(it->getAccountNumber()));

       output << account.getDepositor().getName().getLastName()  << " "
              << account.getDepositor().getName().getFirstName() << " "
              << account.getDepositor().getSSN()                 << " "
              << std::setw(7) << account.getAccountNumber()           << " "
              << std::setw(11)<< account.getAccountType()             << " "
              << std::setw(12) << account.getBalance()                << " "
              << std::setw(8) << account.getAccountStatus()           << std::endl;
   }
}

void Bank::getDatabaseTransaction(std::ofstream &output){
  Account account;

  output << std::endl << std::setw(45) << "Transaction History for All Accounts" << std::endl << std::endl;

  for(std::list<Account>::iterator it = this->account.begin(); it != this->account.end(); ++it){
    account = *(this->getAccount(it->getAccountNumber()));
    output << "Account Number: " << account.getAccountNumber() << std::endl;

    for(int i = 0; i < account.getNumTrans(); i++){
      output << "Action done: ";
      output << account.getTransaction(i)->getTranType() << std::endl;
      output << "Transaction Amount: ";
      output << account.getTransaction(i)->getTranAmount() << std::endl;
    }
  }
}

void Bank::getAccountTransaction(std::list<Account>::iterator it, std::ofstream &output){
	for(int i = 0; i < it->getNumTrans(); i++){
		output << "Action Done: ";
		output << it->getTransaction(i)->getTranType() << std::endl;
		output << "Transaction Amount: ";
		output << it->getTransaction(i)->getTranAmount() << std::endl;
		output << "-------------------------------------" << std::endl;
	}
}

void Bank::balance(std::ofstream &output) {
  Account account;
  int id;                                                      //Account #
  std::string type = "Balance Inquiry";                        //Transaction type

  std::cout << std::endl << "Enter the account number: ";      //Prompting the user
  std::cin >> id;                                              //for an Account #


  std::list<Account>::iterator i = this->getAccount(id);       //Index

  if (i == this->account.end()){                               //Error Handling
    output << "\nTransaction Requested: Balance Inquiry" << std::endl;
    output << "Error: Account number " << id
           << " does not exist" << std::endl;
  }
  else{                                                        //Continues with balance
    account = *i;                                              //inquiry.
    output << "\nTransaction Requested: Balance Inquiry" << std::endl;
    output << "Account Number: " << id << std::endl;
    output << "Current Balance: $" << account.getBalance() << std::endl;
    account.addTransaction(type,account.getBalance());
  }
}

void Bank::deposit(std::ofstream &output){
  Account account;
  int id;
  std::list<Account>::iterator i;
  std::string type = "Deposit";
  double amount;

  std::cout << std::endl << "Enter the account number: ";      //Prompts the user for an
  std::cin >> id;                                              //Account #

  i = this->getAccount(id);

  if (i == this->account.end()){                               //Error checking
    output << std::endl << "Transaction Requested: Deposit" << std::endl;
    output << "Error: Account number " << id
          << " does not exist" << std::endl;
  }
  else{
    account = *i;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    if (amount <= 0.00){
      output << std::endl << "Transaction Requested: Deposit" << std::endl;
      output << "Account Number: " << id << std::endl;
      output << "Error: " << amount << " is an invalid amount"
             << std::endl;
    }
    else{
      output << std::endl << "Transaction Requested: Deposit" << std::endl;
      output << "Account Number: " << id << std::endl;
      output << "Old Balance: $" << account.getBalance() << std::endl;
      output << "Amount to Deposit: $" << amount << std::endl;
      account.makeDeposit(amount);
      output << "New Balance: $" << account.getBalance() << std::endl;
      account.addTransaction(type,account.getBalance());
      this->setAccount(account, i->getAccountNumber());
    }
  }
}

void Bank::withdrawl(std::ofstream &output){
  Account account;
  int id;
  std::list<Account>::iterator i;
  double amount;
  std::string type = "Withdrawl";

  std::cout << std::endl << "Enter Account number: ";        //Prompts the user for an
  std::cin >> id;                                            //Account #

  i = this->getAccount(id);

  if(i == this->account.end()){                              //Error Checking
    output << std::endl << "Transaction Requested: Withdrawl" << std::endl;
    output << "Account: " << id << " does not exist." << std::endl;
  }
  else{
    account = *i;
    std::cout << std::endl << "Please enter amount to Withdraw: ";
    std::cin >> amount;                                      //Prompts user for amount

    if(amount <= 0.00){                                      //Error Checking
      output << std::endl << "Transaction Requested: Withdrawl" << std::endl;
      output << "Account: " << id << std::endl;
      output << "Error: " << amount << " is an invalid amount."
            << std::endl;
    }
    if(account.checkWithdrawl(amount)){                      //Checks if sufficient balance
      output << std::endl << "Transaction Requested: Withdrawl" << std::endl;
      output << "Account number: " << account.getAccountNumber() << std::endl;
      output << "Available Balance: " << account.getBalance() << std::endl;
      output << "Withdraw Amount: " << amount << std::endl;
      output << "Error: Insufficient funds or Invalid Amount." << std::endl
            << std::endl;
    }
    else{
      output << std::endl << "Transaction Requested: Withdrawl" << std::endl;
      output << "Account: " << account.getAccountNumber() << std::endl;
      output << "Previous Balance: " << account.getBalance() << std::endl;
      output << "Amount to Withdraw: " << amount << std::endl;
      account.makeWithdrawl(amount);
      output << "Present Balance: " << account.getBalance() << std::endl;
      account.addTransaction(type,account.getBalance());
      this->setAccount(account, i->getAccountNumber());
    }
  }
}

int Bank::new_account(std::ofstream &output){
  std::string type = "Created Account";
  std::string last, first, ssn, acctype;
  int id;

  std::cout << std::endl << "To create an Account enter a new account number." << std::endl;
  std::cin >> id;                                          //Prompts user for new Account #


  if(!(this->openAccount(id))){                           //Error Checking
    output << std::endl << "Creating new Account... Failed!" << std::endl;
    output << "Account number: " << id << " already exists" << std::endl;
  }
  else{
    std::cout << "To finish completing your new account enter:" << std::endl;
    std::cout << "Last Name: " << std::endl;
    std::cin >> last;

    std::cout << "First Name: " << std::endl;
    std::cin >> first;

    std::cout << "Social Security Number: " << std::endl;
    std::cin >> ssn;

    std::cout << "Account Type: " << std::endl;
    std::cin >> acctype;

    std::cout << std::endl;

    this->addAccount(id, acctype, 0, Depositor(Name(first, last), ssn));
  }

  return this->getActiveAccounts();
}

int Bank::close_account(std::ofstream &output){
  Account account;
  int id;
  std::string type = "Closed Account";
  std::list<Account>::iterator i;

  std::cout << "Enter an account number that you wish to close: ";
  std::cin >> id;                                   //Prompts User for an Account #

  i = this->getAccount(id);

  if(i == this->account.end()){                     //Error Checking
    output << std::endl << "Closing Account... incomplete" << std::endl;
    output << "Error: Account number: " << id
           << " does not exist." << std::endl;
  }
  else
    account = *i;

  if(account.getBalance() > 0){                      //Checks if account has a Balance
    output << std::endl << "Error: Account " << account.getAccountNumber()
           << " has a balance of: $" << account.getBalance()
           << ". Please withdraw your balance "
           << "before you can close your account!" << std::endl;

  }
  else{
    if(id == account.getAccountNumber()){
      this->closeAccount(account.getBalance(), i->getAccountNumber());
      output << std::endl << "Deleting Account... complete" << std::endl;
      output << "Account number: " << id << " has been closed!"
             << std::endl;
      account.addTransaction(type,account.getBalance());

    }
  }

  return this->getActiveAccounts();
}

int Bank::delete_account(std::ofstream &output){
  Account account;
  int id;
  std::list<Account>::iterator i;
  std::string type = "Deleted Account";

  std::cout << "Enter an account number that you wish to delete: ";
  std::cin >> id;                                  //Prompts the user for a Account #

  i = this->getAccount(id);

  if(i == this->account.end()){
    output << std::endl << "Deleting Account... incomplete" << std::endl;
    output << "Error: Account number: " << id << " does not exist."
           << std::endl;
  }
  else{
    account = *i;
    if(account.getBalance() > 0){
      output << std::endl << "Error: Account " << account.getAccountNumber()
             << " has a balance of: $" << account.getBalance()
             << ". Please withdraw your balance before "
             << "you can delete your account!"
             << std::endl;
    }
    else
      if(id == account.getAccountNumber()){
        this->deleteAccount(account.getBalance(), i);
        output << std::endl << "Deleting Account... complete" << std::endl;
        output << "Account number: " << id << " has been deleted!"
               << std::endl;
      }
  }
  return this->getActiveAccounts();
}

void Bank::account_info(std::ofstream &output){
  Account account;
  std::list<Account>::iterator i;
  std::string ssn;

  std::cout << "To view your account information, enter your Social Security "
       << "number: ";
  std::cin >> ssn;
  output << std::endl;

  i = this->getAccount(ssn);

  if (i == this->account.end()){
    output << "Error: SSN " << ssn << " does not exist!" << std::endl
           << std::endl;
  }
  else{
    account = *i;
    output << "Full Account Information" << std::endl
           << "--------------------------------------------\n"
           << std::endl;
    output << "Name: " << account.getDepositor().getName().getLastName()
           << ", " << account.getDepositor().getName().getFirstName()
           << std::endl;
    output << "SSN: " << account.getDepositor().getSSN()
           << std::endl;
    output << "Account #: " << account.getAccountNumber()
           << std::endl;
    output << "Type: " << account.getAccountType()
           << std::endl;
    output << "Balance: $" << account.getBalance()
           << std::endl;
    output << "Status: " << account.getAccountStatus()
           << std::endl;
  }
}

void Bank::transaction_info(std::ofstream &output){
  Account account;
  std::list<Account>::iterator i;
  std::string ssn;

  std::cout << "To view your account information, enter your Social Security "
       << "number: ";
  std::cin >> ssn;

  output << std::endl;

  i = this->getAccount(ssn);


  if (i == this->account.end()){
    output << "Error: SSN " << ssn << " does not exist!\n"
           << std::endl;
  }
  else{
    account = *i;
    output << "Full Account Information" << std::endl
           << "--------------------------------------------" << std::endl
           << std::endl;
    output << "Name: " << account.getDepositor().getName().getFirstName()
           << ", " << account.getDepositor().getName().getLastName()
           << std::endl;
    output << "SSN: " << account.getDepositor().getSSN()
           << std::endl;
    output << "Account #: " << account.getAccountNumber()
           << std::endl;
    output << "Type: " << account.getAccountType()
           << std::endl;
    output << "Balance: $" << account.getBalance()
           << std::endl;
    output << "Status: " << account.getAccountStatus()
           << std::endl << std::endl;

    this->getAccountTransaction(i,output);
  }
}

void Bank::reopen_account(std::ofstream &output){
  Account account;
  Name name;
  Depositor depositor;
  int id;

  std::cout << "Enter the account number you wish to reopen: " << std::endl;
  std::cin >> id;

  std::list<Account>::iterator i = this->getAccount(id);

  if(i == this->account.end())
    std::cout << "Account: " << id << " is not a valid account." << std::endl;
  else{
    account = *i;
    if(account.getAccountStatus() == "Open")
      output << "Account: " << id << " is already open." << std::endl;
    else {
      this->reopenAccount(id);
      output << "\nAccount: " << id << " has been reopened!" << std::endl;
    }
  }
}

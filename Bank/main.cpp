//Harris Dizdarevic
//Bank Accounts
#include "bank.h"

using namespace std;

//Function Prototypes
void parse_accounts(Bank&);
void menu();

int main(){
  Bank bank;
  char selection;
  bool not_finished = true;


  ofstream output("con");                          //You can either output to terminal
  //ofstream output("bankoutput.txt");             //or to a file.

  output.setf(ios::fixed,ios::floatfield);         //Sets the precision of
  output.precision(2);                             //decimals to two places.

  output << setw(55) << "Harris Dizdarevic's Bank Program" << endl << endl;

  parse_accounts(bank);
  bank.print(output);

  do {
    menu();                                        //Print the menu
    cin >> selection;                              //Choose an option

    switch(toupper(selection)){                    //Not case-sensitive
      case 'Q':                                    //Terminates the program and
        not_finished = false;                      //Prints the database of
        bank.print(output);                        //accounts; and their history
        bank.getDatabaseTransaction(output);       //of transactions made
          break;

      case 'B':                                    //Checks the balance of an
        bank.balance(output);                      //account.
          break;

      case 'D':                                    //Performs a deposit for an
        bank.deposit(output);                      //account.
          break;

      case 'W':                                    //Performs a withdrawl for an
        bank.withdrawl(output);                    //account.
          break;

      case 'I':                                    //Gives information about an
        bank.account_info(output);                 //account given the SSN.
          break;

      case 'H':                                    //Gives transaction history of
        bank.transaction_info(output);             //an account given the SSN.
          break;

      case 'N':                                    //Allows the user to create a
        bank.new_account(output);                  //new account.
          break;

      case 'C':                                    //Allows the user to close an
        bank.close_account(output);                //account. The account still
          break;                                   //appears in the database.

      case 'R':                                    //Allows the user to reopen a
        bank.reopen_account(output);               //closed account. Does not work
          break;                                   //on a deleted account.

      case 'X':                                    //Deletes an account entirely
        bank.delete_account(output);               //from the database.
          break;

      default:
        output << "\nError: '" << selection
               << "' is an invalid selection - try again\n"
               << endl;
         break;
      }
  } while (not_finished);

  output.close();

  return 0;
}

void parse_accounts(Bank &bank){
  string first, last, ssn, type, status;           //Details for an Account user
  int id;                                          //Account number
  double balance;                                  //Account balance
                                                   //Reads in the file
  ifstream input("database.txt");

  while (!input.eof()){                            //Formats the order in which
      input >> last;                               //the file is read.
      input >> first;                              //Format:
      input >> ssn;                                //Last Name, First Name, SSN,
      input >> id;                                 //Account # (ID), Type
      input >> type;                               //(Checking/Savings/CD), and
      input >> balance;                            //Balance.
      bank.addAccount(id, type, balance, Depositor(Name(first, last), ssn));
  }

  input.close();
}

void menu(){
	cout << endl << endl;
	cout << "Select one of the following options:" << endl;
	cout << "\t****************************" << endl;
	cout << "\t*     List of Options      *" << endl;
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

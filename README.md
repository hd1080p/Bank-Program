# Bank-Simulation Program: <br/>_a major project in an Advanced C++ course Ver. Original (1)_

## DISCLAIMER
The data provided in the sample input (i.e. an example database) absolutely has no connection
with real people.

##Overview
The purpose of this bank program is designing and implementing a bank's behavior by demonstrating many concepts such as:<br/>
&nbsp;&nbsp;&nbsp;* Object-oriented and functional designs; nested objects <br/>
&nbsp;&nbsp;&nbsp;* Multiple file compilation: separate header and source files <br/>
&nbsp;&nbsp;&nbsp;* Database manipulation <br/>
&nbsp;&nbsp;&nbsp;* Input-Process-Output (IPO) Documentation <br/>
&nbsp;&nbsp;&nbsp;* Dynamic Memory management: pointers <br/>

####What will you see?
Sample input file: database.txt<br/>
Format:<br/>

Last Name | First Name | SSN | Account Number | Balance | Type | Status
--------- | ---------- | --- | -------------- | ------- | ---- | ------
Doe | John | 00-00-0000 | 1234 | 1000.00 | Checking | Open

<br/>

####API
**class Bank**<br/>

_Members_

Type | Identifier | Description
---- | ---------- | -----------
int | active_accounts | Keeps track of how many active users there are.
Account* | account (object) | Dynamically allocated accounts; Banks contain a database of accounts.


_Methods_

Type | Function Name | Parameters | Description
---- | ------------- | ---------- | -----------
bool | openAccount | int index, Account object, Depositor object, Name object | Opens an Account; checks for an existing account-number/ssn: if it exists, try again otherwise, create a new account
bool | closeAccount | double balance, int index | Closes an account; does not delete the account from the database, flagging it as "Closed". It checks if the account has a balance: if so, it will inform the user to empty out the balance before closing an account.
bool | deleteAccount | double balance, int index | Deletes an account; completely deletes the account from the database. It checks if the account has a balance, if so then it will inform the user to empty out the balance before deleting the account.
void | countActiveAccts | Account object, Depositor object, Name object | Counts the number of active accounts, open or closed. Excludes deleted accounts.
void | setAccount | Account object, int index | Assigns a current object to a specific index within the database.
void | addAccount | int number, string type, double balance, Depositor object | Adds an account to the database.
int | findAccount | int requested_account | Given an account number, it will search through the database. Returns -1 if not found, 1 if found.
int | findAccountSSN | string requested_ssn | Instead of the account number, if given the ssn, it will search the database. Returns -1 if not found, 1 if found.
int | getActiveAccounts | none | Gets the current number of active accounts.
Account* | getAccount | int index | Returns a pointer to an account in the database.

**class Account** <br/>

_Members_

Type | Identifier | Description
---- | ---------- | -----------
string | status | Account status: Open or Closed
string | type | Account type: Checking, Savings, or CD
int | accnum | Account number
Depositor | depositor (object) | Account contains a Depositors' information


_Methods_

Type | Function Name | Parameters | Description
---- | ------------- | ---------- | -----------
void | makeDeposit | double amount | Adds funds to an account; checks are done in the function Deposit.
void | setBalance | double balance | Assigns a new balance to the current object.
void | setAccountType | string type | Stores and assigns the account type to the current object.
void | setAccountStatus | string status | Stores and assigns the account status to the current object.
void | setTransaction | Transaction object, int index | Stores and assigns an existing Transaction to the current object.
void | addTransaction | string type, double amount | Instantiates a new Transaction object and assigns it to the current object.
bool | makeWithdraw | double amount | This method only withdraws when the amount does not exceed the balance and the amount being withdrawed is not less than zero.
bool | findAccount | int account_number | Given an account number, checks if the current object matches with the account number, returns true; otherwise false.
bool | findAccountSSN | string ssn | Given a SSN, checks if the current object matches with the SSN, returns true; otherwise false.
int | setAccountNumber | int account_number | Stores and assigns a account number to the current object.
int | getAccountNumber | none | Returns the current object's account number.
int | getNumTrans | none | Returns the number of transactions made in the account.
double | getBalance | none | Returns the current balance in the account.
string | getAccountType | none | Returns the type of account
string | getAccountStatus | none | Returns the current status of the account.
Depositor | getDepositor | none | Returns the Depositor associated with the account.
Transaction* | getTransaction | int index | Returns a specific transaction made in the account.

<br/>

**class Depositor** <br/>

_Members_

Type | Identifier | Description
---- | ---------- | -----------
string | ssn | Social-security-number
Name | name (object) | A depositor contains the name of the account, and the ssn


_Methods_

Type | Function Name | Parameters | Description
---- | ------------- | ---------- | -----------
void | setName | string type | Assigns and stores the Name in the current object.
void | setSSN | double amount | Assigns and stores the ssn in the current object.
string | getSSN | None | Returns the ssn of the depositor.
Name | getName | None | Returns a Name object associated with the depositor.


<br/>

**class Name** <br/>

_Members_

Type | Identifier | Description
---- | ---------- | -----------
string | last | Last name
string | first | First name


_Methods_

Type | Function Name | Parameters | Description
---- | ------------- | ---------- | -----------
string | setFirstName | string first | Sets the first name to the current object associated with the account.  
string | setLastName | string last | Sets the last name to the current object associated with the account.
void | getFirstName | None | Returns the first name in the current object.
void | getLastName | None | Returns the last name in the current object.

<br/>

**class Transaction** <br/>

_Members_

Type | Identifier | Description
---- | ---------- | -----------
string | type | Transaction type
double | amount | The amount that changed in the transaction

_Methods_

Type | Function Name | Parameters | Description
---- | ------------- | ---------- | -----------
void | setTranType | string type | Sets the Transaction type for the current object
void | setTranAmount | double amount | Sets/stores the amount in the Transaction for the current object
string | getTranType | None | Returns the type of Transaction made
double | getTranAmount | None | Returns the amount changed in a Transaction

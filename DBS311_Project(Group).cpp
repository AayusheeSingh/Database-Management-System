/***************************************************************************************************************
* 
*                                          DBS-311 PROJECT
*                                 Member-1 Aayushee Singh (173927211)
*                                 Member-2 lakshay Arora (1737204214)
*                                 Member-3 Pruthvi Patel(170733216)
* 
****************************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <occi.h>
using oracle::occi::Environment;
using oracle::occi::Connection;
using oracle::occi::Statement;
using oracle::occi::ResultSet;
using namespace oracle::occi;
using namespace std;

struct Employee
{
    int employeeID = 0;
    string firstName;
    string lastName;
    string phone;
    string positiontitle;
    int branchID = 0;
};

struct Customer
{
    int customerID;
    string firstName;
    string lastName;
    string phone;
    string address;
    string postalCode;
    string country;
};
struct Transactions
{
    int transactionID = 0;
    int customerID = 0;
    double transactionAmount = 0.0;
    string transactionDate;
    string transactionType;
};

struct Branch
{
    int branchID = 0;
    int branchManager = 0;
    string branchName;
    string branchLocation;
    string phoneNumber;

};
struct Accounts {
    int accountID = 0;
    int customerID = 0;
    int accountBalance = 0;
    string accountNumber;
    string accountType;
    string status;
    string openingDate;
    int branchID = 0;
};

struct creditCardAccount {
    int cardID = 0;
    int customerID = 0;
    string cardNumber;
    string expirationDate;
    int creditLimit = 0;
    int creditBalance = 0;
};

int mainMenu(void);
int employeeMenu(void);
int customerMenu(void);
int transactionMenu(void);
int branchMenu(void);
int accountsMenu(void);
int creditCardAccountMenu(void);

int findEmployee(Connection* conn, int employeeID);
void displayEmployee(Connection* conn, struct Employee emp);
void displayAllEmployees(Connection* conn);

int findCustomer(Connection* conn, int customerID);
void displayCustomer(Connection* conn, struct Customer cust);
void displayAllCustomers(Connection* conn);

int findTransaction(Connection* conn, int transactionID);
void displayTransaction(Connection* conn, struct Transactions trans);
void displayAllTransaction(Connection* conn);

int findBranch(Connection* conn, int branchID);
void displayBranch(Connection* conn, struct Branch brn);
void displayAllBranch(Connection* conn);

int findAccount(Connection* conn, int accountID);
void displayAccount(Connection* conn, struct Accounts acc);
void displayAllAccounts(Connection* conn);

int findCreditCard(Connection* conn, int cardID);
void displayCreditCard(Connection* conn, struct creditCardAccount card);
void displayAllCreditCards(Connection* conn);



int main() {

    Environment* env = nullptr;
    Connection* conn = nullptr;
    Employee emp;
    // User Variables
    string str;
    string usr = "dbs311_233nbb26";    // this is my login assigned to me	
    string pass = "32105190";          // this is my password assigned to me	
    string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(usr, pass, srv);
        cout << "Connection is Successful!" << endl;

        int input = 0;
        do {

            input = mainMenu();

            if (input == 1) {
                // Employee Menu
                int empChoice = employeeMenu();

                if (empChoice == 1) {
                    cout << "\n Entering choice to find the employee";
                    int eno;
                    cout << "\nEnter Employee ID:";
                    cin >> eno;
                    if (findEmployee(conn, eno) == 1) {
                        cout << "\nValid Employee ID\n";
                    }
                    else {
                        cout << "\nInvalid Employee ID\n";
                    }
                }
                else if (empChoice == 2) {
                    cout << "\nEntering choice to display the employee";
                    displayEmployee(conn, emp);
                }
                else if (empChoice == 3) {
                    cout << "\nEntering choice to display all employees";
                    displayAllEmployees(conn);
                }

            }

            else if (input == 2)
            {
                // Customer Menu
                int custChoice = customerMenu();

                if (custChoice == 1) {
                    cout << "\n Entering choice to find the customer";
                    int custNo;
                    cout << "\nEnter Customer ID:";
                    cin >> custNo;
                    if (findCustomer(conn, custNo) == 1) {
                        cout << "\nValid Customer ID\n";
                    }
                    else {
                        cout << "\nInvalid Customer ID\n";
                    }
                }
                else if (custChoice == 2)
                {
                    cout << "\nEntering choice to display the customer";
                    Customer cust;
                    displayCustomer(conn, cust);
                }
                else if (custChoice == 3)
                {
                    cout << "\nEntering choice to display all customers";
                    displayAllCustomers(conn);
                }

            }

            else if (input == 3) 
            {
                int transChoice = transactionMenu();

                if (transChoice == 1) {
                    cout << "\n Entering choice to find the transaction";
                    int eno;
                    cout << "\nEnter Transaction ID:";

                    cin >> eno;
                    if (findTransaction(conn, eno) == 1) {
                        cout << "\nValid Transaction ID\n";
                    }
                    else {
                        cout << "\nInvalid Transaction ID\n";
                    }

                }

                else if (transChoice == 2) {
                    struct Transactions trans;
                    cout << "\nEntering choice to display the Transaction";
                    displayTransaction(conn, trans);
                }
                else if (transChoice == 3) {
                    cout << "\nEntering choice to display all Transactions";
                    displayAllTransaction(conn);
                }
                else{
                    cout << "Invalid Input!!" << endl;
                  }
            }


            else if (input == 4) 
            {
                int brnChoice = branchMenu();

                if (brnChoice == 1) {
                    cout << "\n Entering choice to find the branch";
                    int brnNo;
                    cout << "\nEnter branch ID:";
                    cin >> brnNo;
                    if (findBranch(conn, brnNo) == 1) {
                        cout << "\nValid branch ID\n";
                    }
                    else {
                        cout << "\nInvalid branch ID\n";
                    }
                }
                else if (brnChoice == 2)
                {
                    cout << "\nEntering choice to display the branch";
                    struct Branch brn;
                    displayBranch(conn, brn);
                }
                else if (brnChoice == 3)
                {
                    cout << "\nEntering choice to display all branchs";
                    displayAllBranch(conn);
                }

                else
                {
                    cout << "Invalid Input!!" << endl;

                }

            }
            else if (input == 5)
            {
            // accloyee Menu
            int accChoice = accountsMenu();

            if (accChoice == 1) {
                cout << "\n Entering choice to find the account";
                int eno;
                cout << "\nEnter account ID:";
                cin >> eno;
                if (findAccount(conn, eno) == 1) {
                    cout << "\nValid Account ID\n";
                }
                else {
                    cout << "\nInvalid Account ID\n";
                }
            }
            else if (accChoice == 2) {
                struct Accounts acc;
                cout << "\nEntering choice to display the account";
                displayAccount(conn, acc);
            }
            else if (accChoice == 3) {
                cout << "\nEntering choice to display all accounts";
                displayAllAccounts(conn);
            }
            }
            else if(input == 6)
            {
                  // Credit Card Menu
                int cardChoice = creditCardAccountMenu();

                if (cardChoice == 1) {
                    cout << "\n Entering choice to find the credit card";
                    int cardNo;
                    cout << "\nEnter Card ID:";
                    cin >> cardNo;
                    if (findCreditCard(conn, cardNo) == 1) {
                        cout << "\nValid Card ID\n";
                    }
                    else {
                        cout << "\nInvalid Card ID\n";
                    }
                }
                else if (cardChoice == 2)
                {
                    cout << "\nEntering choice to display the card";
                    creditCardAccount card;
                    displayCreditCard(conn, card);
                }
                else if (cardChoice == 3)
                {
                    cout << "\nEntering choice to display all credit cards";
                    displayAllCreditCards(conn);
                }

            }
           
        } while (input != 7);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);

    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
    return 0;
}


int mainMenu(void)
{
    int choice;
    cout << "\nMain Menu" << endl;
    cout << "1. Employees" << endl;
    cout << "2. Customers" << endl;
    cout << "3. Transactions" << endl;
    cout << "4. Branch" << endl;
    cout << "5. Accounts" << endl;
    cout << "6. Credit Card Accounts" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return choice;
}

int employeeMenu(void)
{
    int choice;
    cout << "\nEmployee Menu" << endl;
    cout << "1. Find Employee" << endl;
    cout << "2. Display Employee" << endl;
    cout << "3. Display All Employees" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int customerMenu(void)
{

    int choice2;
    cout << "\nCustomer Menu" << endl;
    cout << "1. Find Customer" << endl;
    cout << "2. Display Customer" << endl;
    cout << "3. Display All Customers" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice2;

    return choice2;
}


int transactionMenu(void)
{
    int choice;
    cout << "\nTransactions Menu" << endl;
    cout << "1. Find Transaction" << endl;
    cout << "2. Display Transaction" << endl;
    cout << "3. Display All Transactions" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int branchMenu(void)
{

    int choice2;
    cout << "\nBranch Menu" << endl;
    cout << "1. Find Branch" << endl;
    cout << "2. Display Branch" << endl;
    cout << "3. Display All Branchs" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice2;

    return choice2;
}
int accountsMenu(void)
{
    int choice;
    cout << "\nAccount Menu" << endl;
    cout << "1. Find Account" << endl;
    cout << "2. Display account" << endl;
    cout << "3. Display All Accounts" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int creditCardAccountMenu(void)
{

    int choice2;
    cout << "\nCredit Card Menu" << endl;
    cout << "1. Find Credit Card" << endl;
    cout << "2. Display Credit Card" << endl;
    cout << "3. Display All Credit Cards" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice2;

    return choice2;
}


int findEmployee(Connection* conn, int employeeID)
{

    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT employeeID, firstName, lastName, phone, positiontitle, branchID FROM EMPLOYEES WHERE employeeID= " + to_string(employeeID));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }
}

void displayEmployee(Connection* conn, struct Employee emp)
{
    int employeeid;
    bool correctCode = false;
    do {
        cout << "\nEnter employeeid: ";
        cin >> employeeid;
        if (!cin || findEmployee(conn, employeeid) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid employeeid\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table..." << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT employeeId, firstName, lastName, phone, positiontitle, branchID FROM EMPLOYEES WHERE employeeid= " + to_string(employeeid));
                while (rs2->next())
                {
                    cout << "\n--------------- Employee Information -------------- - " << endl;
                    emp.employeeID = rs2->getInt(1);
                    emp.firstName = rs2->getString(2);
                    emp.lastName = rs2->getString(3);
                    emp.phone = rs2->getString(4);
                    emp.positiontitle = rs2->getString(5);
                    emp.branchID = rs2->getInt(6);

                    cout << "\nEmployee ID Number: ";
                    cout << emp.employeeID;
                    cout << "\nEmployee First Name: ";
                    cout << emp.firstName;
                    cout << "\nEmployee Last Name: ";
                    cout << emp.lastName;
                    cout << "\nEmployee phone: ";
                    cout << emp.phone;
                    cout << "\nEmployee position title ";
                    cout << emp.positiontitle;
                    cout << "\nEmployee connected to which branch ";
                    cout << emp.branchID;
                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}


void displayAllEmployees(Connection* conn) {
    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT employeeID,branchID, firstName, lastName, phone, positiontitle FROM EMPLOYEES");

        cout << setw(25) << "\n\nEmployee ID" << setw(20) << "Branch ID" << setw(20) << "firstName" << setw(17) << "lastName" << setw(15) << "Phone" << setw(15) << "Position Title" << endl;
        Employee emp2;
        while (rs3->next()) {
            emp2.employeeID = rs3->getInt(1);
            emp2.branchID = rs3->getInt(2);
            emp2.firstName = rs3->getString(3);
            emp2.lastName = rs3->getString(4);
            emp2.phone = rs3->getString(5);
            emp2.positiontitle = rs3->getString(6);

            cout << left << setw(25);
            cout << emp2.employeeID;
            cout << left << setw(20);
            cout << emp2.branchID;
            cout << left << setw(20);
            cout << emp2.firstName;
            cout << left << setw(17);
            cout << emp2.lastName;
            cout << left << setw(15);
            cout << emp2.phone;
            cout << left << setw(15);
            cout << emp2.positiontitle;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
}


int findCustomer(Connection* conn, int customerID)
{

    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT customerId, firstName, lastName, phone, address,postalCode,country FROM CUSTOMERS WHERE customerid= " + to_string(customerID));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }
}

void displayCustomer(Connection* conn, struct Customer cust)
{
    int customerid;
    bool correctCode = false;
    do {
        cout << "\nEnter customerid: ";
        cin >> customerid;
        if (!cin || findCustomer(conn, customerid) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid customerid\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table...+" << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT customerId, firstName, lastName, phone, address,postalCode,country FROM CUSTOMERS WHERE customerid= " + to_string(customerid));
                while (rs2->next())
                {
                    cout << "\n--------------- Customer Information -------------- - " << endl;
                    cust.customerID = rs2->getInt(1);
                    cust.firstName = rs2->getString(2);
                    cust.lastName = rs2->getString(3);
                    cust.phone = rs2->getString(4);
                    cust.address = rs2->getString(5);
                    cust.postalCode = rs2->getString(6);
                    cust.country = rs2->getString(7);


                    cout << "\nCustomer ID Number: ";
                    cout << cust.customerID;
                    cout << "\nCustomer First Name: ";
                    cout << cust.firstName;
                    cout << "\nCustomer Last Name: ";
                    cout << cust.lastName;
                    cout << "\nCustomer phone: ";
                    cout << cust.phone;
                    cout << "\nCustomer's address ";
                    cout << cust.address;
                    cout << "\nCustomer's postal code  ";
                    cout << cust.postalCode;
                    cout << "\nCustomer's country  ";
                    cout << cust.country;
                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}


void displayAllCustomers(Connection* conn) {
    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT customerId, firstName, lastName, phone, address,postalCode,country FROM CUSTOMERS ");

        cout << setw(25) << "\n\nCustomer Employee ID" << setw(15) << "First Name" << setw(19) << "Last Name" << setw(16) << "Phone" << setw(19) << "Address" << setw(18) << "Postal Code" << setw(15) << "Country" << endl;
        Customer cust2;
        while (rs3->next()) {
            cust2.customerID = rs3->getInt(1);
            cust2.firstName = rs3->getString(2);
            cust2.lastName = rs3->getString(3);
            cust2.phone = rs3->getString(4);
            cust2.address = rs3->getString(5);
            cust2.postalCode = rs3->getString(6);
            cust2.country = rs3->getString(7);

            cout << left << setw(25);
            cout << cust2.customerID;
            cout << left << setw(20);
            cout << cust2.firstName;
            cout << left << setw(20);
            cout << cust2.lastName;
            cout << left << setw(17);
            cout << cust2.phone;
            cout << left << setw(19);
            cout << cust2.address;
            cout << left << setw(15);
            cout << cust2.postalCode;
            cout << left << setw(15);
            cout << cust2.country;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
}


int findTransaction(Connection* conn, int transactionID)
{

    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT tansactionID, customerID, transactionamount, transactiondate, transactiontype FROM Transactions WHERE tansactionID= " + to_string(transactionID));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }
}

void displayTransaction(Connection* conn, struct Transactions trans)
{
    int transactionid;
    bool correctCode = false;
    do {
        cout << "\nEnter transactionid: ";
        cin >> transactionid;
        if (!cin || findTransaction(conn, transactionid) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid transactionid\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table..." << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT tansactionID, customerID, transactionAmount, transactionDate, transactionType FROM Transactions WHERE tansactionID= " + to_string(transactionid));
                while (rs2->next())
                {
                    cout << "\n--------------- Transaction Information -------------- - " << endl;
                    trans.transactionID = rs2->getInt(1);
                    trans.customerID = rs2->getInt(2);
                    trans.transactionAmount = rs2->getDouble(3);
                    trans.transactionDate = rs2->getString(4);
                    trans.transactionType = rs2->getString(5);


                    cout << "\nTransaction ID Number: ";
                    cout << trans.transactionID;
                    cout << "\nTransaction Customer ID: ";
                    cout << trans.customerID;
                    cout << "\nTransaction Amount: ";
                    cout << trans.transactionAmount;
                    cout << "\nTransaction Date: ";
                    cout << trans.transactionDate;
                    cout << "\nTransaction type: ";
                    cout << trans.transactionType;

                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}

void displayAllTransaction(Connection* conn) {
    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT tansactionID, customerID, transactionAmount, transactionDate, transactionType FROM Transactions");

        cout << setw(25) << "\n\nTransaction ID" << setw(20) << "Customer ID" << setw(25) << " TransactionAmount" << setw(20) << "TransactionDate" << setw(18) << "TransactionType" << endl;
        Transactions trans2;
        while (rs3->next()) {
            trans2.transactionID = rs3->getInt(1);
            trans2.customerID = rs3->getInt(2);
            trans2.transactionAmount = rs3->getDouble(3);
            trans2.transactionDate = rs3->getString(4);
            trans2.transactionType = rs3->getString(5);

            cout << left << setw(25);
            cout << trans2.transactionID;
            cout << left << setw(20);
            cout << trans2.customerID;
            cout << left << setw(20);
            cout << trans2.transactionAmount;
            cout << left << setw(17);
            cout << trans2.transactionDate;
            cout << left << setw(16);
            cout << trans2.transactionType;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
}

int findBranch(Connection* conn, int branchID) {
    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT branchId, branchmanager, branchname, branchlocation, phonenumber FROM Branch WHERE branchid= " + to_string(branchID));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }

}


void displayBranch(Connection* conn, struct Branch brn) {
    int branchid;
    bool correctCode = false;
    do {
        cout << "\nEnter branchid: ";
        cin >> branchid;
        if (!cin || findBranch(conn, branchid) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid branchid\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table...+" << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT branchId, branchmanager, branchname, branchlocation, phonenumber FROM Branch WHERE branchid= " + to_string(branchid));
                while (rs2->next())
                {
                    cout << "\n--------------- Branch Information -------------- - " << endl;
                    brn.branchID = rs2->getInt(1);
                    brn.branchManager = rs2->getInt(2);
                    brn.branchName = rs2->getString(3);
                    brn.branchLocation = rs2->getString(4);
                    brn.phoneNumber = rs2->getString(5);


                    cout << "\nBranch ID Number: ";
                    cout << brn.branchID;
                    cout << "\nBranch Manager ID: ";
                    cout << brn.branchManager;
                    cout << "\nBranch  Name: ";
                    cout << brn.branchName;
                    cout << "\nBranch Location: ";
                    cout << brn.branchLocation;
                    cout << "\nBranch's phone: ";
                    cout << brn.phoneNumber;
                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}

void displayAllBranch(Connection* conn) {

    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT branchId, branchmanager, branchname, branchlocation, phonenumber FROM Branch ");

        cout << setw(20) << "\n\nBranch ID" << setw(20) << "Branch Manager ID" << setw(22) << "Branch Name" << setw(29) << "Branch Location" << setw(35) << "Phone Number" << endl;
        Branch brn2;
        while (rs3->next()) {
            brn2.branchID = rs3->getInt(1);
            brn2.branchManager = rs3->getInt(2);
            brn2.branchName = rs3->getString(3);
            brn2.branchLocation = rs3->getString(4);
            brn2.phoneNumber = rs3->getString(5);

            cout << left << setw(25);
            cout << brn2.branchID;
            cout << left << setw(15);
            cout << brn2.branchManager;
            cout << left << setw(25);
            cout << brn2.branchName;
            cout << left << setw(40);
            cout << brn2.branchLocation;
            cout << left << setw(15);
            cout <<  brn2.phoneNumber;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }

}


int findAccount(Connection* conn, int accountID)
{

    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT accountID, customerID, accountBalance, accountNumber, accountType, status, openingDate, branchID FROM Accounts WHERE accountID= " + to_string(accountID));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }
}

void displayAccount(Connection* conn, struct Accounts acc)
{
    int accountID;
    bool correctCode = false;
    do {
        cout << "\nEnter accountID: ";
        cin >> accountID;
        if (!cin || findAccount(conn, accountID) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid accountID\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table..." << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT accountID, customerID, accountBalance, accountNumber, accountType, status, openingDate, branchID FROM Accounts WHERE accountID= " + to_string(accountID));
                while (rs2->next())
                {
                    cout << "\n--------------- Account Information -------------- - " << endl;
                    acc.accountID = rs2->getInt(1);
                    acc.customerID = rs2->getInt(2);
                    acc.accountBalance = rs2->getInt(3);
                    acc.accountNumber = rs2->getString(4);
                    acc.accountType = rs2->getString(5);
                    acc.status = rs2->getString(6);
                    acc.openingDate = rs2->getString(7);
                    acc.branchID = rs2->getInt(8);


                    cout << "\nAccount ID Number: ";
                    cout << acc.accountID;
                    cout << "\nAccount Customer Number: ";
                    cout << acc.customerID;
                    cout << "\nAccount Balance: ";
                    cout << acc.accountBalance;
                    cout << "\nAccount Number: ";
                    cout << acc.accountNumber;
                    cout << "\nAccount Status: ";
                    cout << acc.status;
                    cout << "\nAccount Opening Date: ";
                    cout << acc.openingDate;
                    cout << "\nAccount Branch ID: ";
                    cout << acc.branchID;
                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}


void displayAllAccounts(Connection* conn) {
    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT accountID, customerID, accountBalance, accountNumber, accountType, status, openingDate, branchID FROM Accounts");

        cout << setw(25) << "\n\nAccount ID" << setw(20) << "Customer ID" << setw(20) << "AccountBalance" << setw(17) << "AccountNumber" << setw(15) << "AccountType" << setw(15) << "Status" << setw(15) << "OpeningDate" << setw(15) << "Branch ID" << endl;
        Accounts acc2;
        while (rs3->next()) {
            acc2.accountID = rs3->getInt(1);
            acc2.customerID = rs3->getInt(2);
            acc2.accountBalance = rs3->getInt(3);
            acc2.accountNumber = rs3->getString(4);
            acc2.accountType = rs3->getString(5);
            acc2.status = rs3->getString(6);
            acc2.openingDate = rs3->getString(7);
            acc2.branchID = rs3->getInt(8);

            cout << left << setw(25);
            cout << acc2.accountID;
            cout << left << setw(20);
            cout << acc2.customerID;
            cout << left << setw(20);
            cout << acc2.accountBalance;
            cout << left << setw(17);
            cout << acc2.accountNumber;
            cout << left << setw(15);
            cout << acc2.accountType;
            cout << left << setw(15);
            cout << acc2.status;
            cout << left << setw(15);
            cout << acc2.openingDate;
            cout << left << setw(15);
            cout << acc2.branchID;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
}



int findCreditCard(Connection* conn, int card)
{

    Statement* stmt = conn->createStatement();
    ResultSet* rs = stmt->executeQuery("SELECT cardID, customerID, cardNumber, expirationDate, creditLimit, creditBalamce FROM creditCardAccount WHERE cardID= " + to_string(card));
    if (rs->next()) {
        return 1;
    }
    else {
        return 0;
    }
}

void displayCreditCard(Connection* conn, struct creditCardAccount card)
{
    int cardID;
    bool correctCode = false;
    do {
        cout << "\nEnter cardID: ";
        cin >> cardID;
        if (!cin || findCreditCard(conn, cardID) != 1)
        {
            correctCode = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid cardID\n";
        }
        else {
            correctCode = true;
            cout << "\nValid Input" << endl;
            cout << "\nSearch in table...+" << endl;
            try {
                Statement* stmt2 = conn->createStatement();
                ResultSet* rs2 = stmt2->executeQuery("SELECT cardID, customerID, cardNumber, expirationDate, creditLimit, creditBalamce FROM creditCardAccount WHERE cardID= " + to_string(cardID));
                while (rs2->next())
                {
                    cout << "\n--------------- Credit Card Information -------------- - " << endl;
                    card.cardID = rs2->getInt(1);
                    card.customerID = rs2->getInt(2);
                    card.cardNumber = rs2->getString(3);
                    card.expirationDate = rs2->getString(4);
                    card.creditLimit = rs2->getInt(5);
                    card.creditBalance = rs2->getInt(6);



                    cout << "\nCredit Card ID Number: ";
                    cout << card.cardID;
                    cout << "\nCredit Card Customer ID: ";
                    cout << card.customerID;
                    cout << "\nCredit Card Number: ";
                    cout << card.cardNumber;
                    cout << "\nCredit Card Expiration date: ";
                    cout << card.expirationDate;
                    cout << "\nCredit Card's limit: ";
                    cout << card.creditLimit;
                    cout << "\nCredit Card's Balance: ";
                    cout << card.creditBalance;
                    cout << "\n";
                }
                cout << endl;
                conn->terminateStatement(stmt2);
            }
            catch (SQLException& sqlExcp)
            {
                cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
            }
        }
    } while (!correctCode);
}


void displayAllCreditCards(Connection* conn) {
    try {
        Statement* stmt3 = conn->createStatement();
        ResultSet* rs3 = stmt3->executeQuery("SELECT cardID, customerID, cardNumber, expirationDate, creditLimit, creditBalamce FROM creditCardAccount");

        cout << setw(25) << "\n\nCredit Card ID" << setw(20) << "CustomerID" << setw(20) << "CardNumber" << setw(17) << "ExpirationDate" << setw(15) << "creditLimit" << setw(15) << "creditBalance" << endl;
        creditCardAccount card2;
        while (rs3->next()) {
            card2.cardID = rs3->getInt(1);
            card2.customerID = rs3->getInt(2);
            card2.cardNumber = rs3->getString(3);
            card2.expirationDate = rs3->getString(4);
            card2.creditLimit = rs3->getInt(5);
            card2.creditBalance = rs3->getInt(6);



            cout << left << setw(25);
            cout << card2.cardID;
            cout << left << setw(20);
            cout << card2.customerID;
            cout << left << setw(20);
            cout << card2.cardNumber;
            cout << left << setw(17);
            cout << card2.expirationDate;
            cout << left << setw(15);
            cout << card2.creditLimit;
            cout << left << setw(15);
            cout << card2.creditBalance;
            cout << endl;
        }
        cout << endl;

        conn->terminateStatement(stmt3);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }
}


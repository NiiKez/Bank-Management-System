#include <stdio.h>
#include <stdlib.h>



void createAccount();
void deposit();
void withdraw();
void showstatus();
void deleteAcc();
// void selectcurrency();
// void showhistory();



struct account{
    char firstname[10];
    char lastname[10];
    float balance;

};

struct account accounts[100];
int accountCount = 0;
double balance = 0;
int accNumber = 0;

int getUserChoice() {
    int choice;
    int result;

    while (1) {
        result = scanf("%d", &choice);

        // If scanf fails to read an integer
        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");

            // Clear the input buffer
            while (getchar() != '\n');  // Read and discard invalid characters
        } else {
            return choice;
        }
    }
}


int main(void) {

    while (1){

        printf("------Main Menu-------- \n");
        printf("[1] Create Account\n");
        printf("[2] Deposit money \n");
        printf("[3] Withdraw money \n");
        printf("[4] Overview of Accounts\n");
        printf("[5] Delete Account \n");
        printf("[6] Transaction History\n");
        printf("----------------------- \n");
        printf("Enter choice: ");


        int choice = getUserChoice();

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                if (accountCount > 0) {
                    deposit();
                } else {
                    printf("Create an Account first!\n");
                }
                break;

            case 3:
                if (accountCount > 0){
                    withdraw();
                }else {
                    printf("Create an Account first");
                }
            case 4:
                if(accountCount > 0){
                    showstatus();
                } else {
                    printf("Create an Account first!\n");
                }
                break;

            case 5:
                if(accountCount > 0){
                    deleteAcc();
                }else{
                    printf("Currently no accounts!\n");
                }
                break;
                //case 6:
                //    if(accountCount > 0){
                //        showhistory();
                //    }else{
                //        printf("Create an Account first!\n");
                //    }
                //    break;

            default:
                printf("Wrong input! Please Try again");
                return 0;

        }
    }
}


void createAccount(){

    struct account *accptr = &accounts[accountCount];

    printf("-------Welcome to our registration System--------\n");
    printf("Enter your first name: ");
    scanf("%s", accptr->firstname);
    printf("Enter your last name: ");
    scanf("%s", accptr->lastname);
    printf("Account successfully created for %s %s\n", accptr->firstname, accptr->lastname);
    accptr->balance = 0;
    printf("Current balance %.2f\n", accptr->balance);
    accountCount++;
}


void deposit(){

    int i;
    printf("Here is a list of your accounts: \n");
    for(i= 0; i < accountCount; i++){

        printf("ID_no %d: %s %s / Balance: %.2f \n",i, accounts[i].firstname, accounts[i].lastname, accounts[i].balance);

    }
    printf("Input your ID number: ");
    scanf("%d", &accNumber);
    if(accNumber >= i || accNumber < 0){

        printf("Wrong input!\n");

    }else{

        double amount;
        printf("Enter amount: ");
        scanf("%lf", &amount);
        accounts[accNumber].balance  += amount;

        printf("New balance of %s %s: %.2lf\n", accounts[accNumber].firstname, accounts[accNumber].lastname, accounts[accNumber].balance);
    }

}



void showstatus(){

    for(int i= 0; i < accountCount; i++){

        printf("ID_no %d: %s %s / Balance: %.2lf\n",i, accounts[i].firstname, accounts[i].lastname, accounts[i].balance);

    }

}

void withdraw(){

    int i;
    printf("Here is a list of your accounts: \n");
    for(i= 0; i < accountCount; i++){

        printf("ID_NO %d: %s %s / Balance: %.2f\n",i, accounts[i].firstname, accounts[i].lastname, accounts[i].balance);

    }
    printf("Input your ID number: ");
    scanf("%d", &accNumber);

    if(accNumber >= i || accNumber < 0){
        printf("Wrong input/ID number: \n");
    }
    else{
        double amount;
        printf("Enter amount to withdraw: ");
        scanf("%lf", &amount);

        if(accounts[accNumber].balance < amount)
            printf("You cant withdraw more many than you have!\n");
        else{
            accounts[accNumber].balance -= amount;
            printf("New balance of %s %s: %.2f\n", accounts[accNumber].firstname, accounts[accNumber].lastname, accounts[accNumber].balance);
        }

    }

}


void deleteAcc(){

    printf("-------Welcome to our Account Management System-------\n");
    int i;
    printf("Here is a list of your accounts: \n");
    for(i= 0; i < accountCount; i++){

        printf("ID_NO %d: %s %s / Balance: %.2f\n",i, accounts[i].firstname, accounts[i].lastname, accounts[i].balance);

    }

    printf("Enter the ID number of the Account you want to delete: ");
    scanf("%d",&accNumber);


    if(accNumber >= i || accNumber < 0){
        printf("Wrong input/ID number \n");
        return;
    }

    for (i = accNumber; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1]; // Shift the next account to the current index
    }

    accountCount--;
    printf("Account deleted successfully\n");

}


/*void showhistory(){

    int i;
    printf("Here is a list of your accounts: \n");
    for(i= 0; i < accountCount; i++){

        printf("ID_NO %d: %s %s / Balance: %.2f\n",i, accounts[i].firstname, accounts[i].lastname, accounts[i].balance);

    }

    printf("Enter ID number: ");
    scanf("%d",&accNumber);

    for( i = 0; i < accountCount; i++){

        printf("History: \n", accounts[i].balance);
    }



}*/

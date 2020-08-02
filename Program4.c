#include <stdio.h>
int PromptUser(int index);
int userIncomeCalculations(char *pPerson, double *pHourlyRate, double *pHoursWorked, double *pAmountPaid, double *pOverHoursRate);
double userTaxCalculations(double *pay);
int userOutputOne(int index);

struct Employee{
    char person[25];
    double hourlyRate;
    double hoursWorked;
    double overHoursRate;
    double amountPaid;
    double taxesPaid;
    double takeHome;
};

struct Employee workers[25];
double totalGrossPay[5];
int breakPerson[5];
int userEntries;
int j=0;
int i=1;

int main(void) {
    int userInput;
    int userEditInput;
    int userPrintOneInput;
    int userCalcOneInput;

    do{
        printf("Main Menu \n");
        printf("1. Add Employee \n");
        printf("2. Edit Employee \n");
        printf("3. Print Employee \n");
        printf("4. Print All Employees \n");
        printf("5. Perform Calculations on one Employee \n");
        printf("6. Perform Calculations on all Employees \n");
        printf("7. Quit \n ");
        scanf(" %d", &userInput);

        if(userInput == 1){
          PromptUser(i);
          i++;
        }

        if(userInput == 2){
          printf("Choose an employee. \n");
          for(j=1; j<i; j++){
            printf("%d: %s\n",j, workers[j].person);
          }
          scanf(" %d", &userEditInput);
          PromptUser(userEditInput);
        }

        if(userInput == 3){
            printf("Choose an employee. \n");
            for(j=1; j<i; j++){
              printf("%d: %s\n",j, workers[j].person);
            }
            scanf(" %d", &userPrintOneInput);
            printf("Employee: %s  Rate: %.2f  Hours: %.2f \n", workers[userPrintOneInput].person, workers[userPrintOneInput].hourlyRate, workers[userPrintOneInput].hoursWorked);
            printf("\n");
        }

        if(userInput == 4){
            for(j=1; j<i; j++){
              printf("Employee: %s  Rate: %.2f  Hours: %.2f \n", workers[j].person, workers[j].hourlyRate, workers[j].hoursWorked);
            }    
            printf("\n");
        }

        if(userInput == 5){
            printf("Choose an employee. \n");
            for(j=1; j<i; j++){
              printf("%d: %s\n",j, workers[j].person);
            }
            scanf(" %d", &userCalcOneInput);
            userIncomeCalculations(&workers[userCalcOneInput].person, &workers[userCalcOneInput].hourlyRate, 
            &workers[userCalcOneInput].hoursWorked, &workers[userCalcOneInput].amountPaid, &workers[userCalcOneInput].overHoursRate);
            userOutputOne(userCalcOneInput);
        }

        if(userInput == 6){

          for(j=1; j<i; j++){
            if(workers[j].hoursWorked > 40){
            workers[j].overHoursRate = (workers[j].hoursWorked - 40)* workers[j].hourlyRate * 1.5 ;
            workers[j].amountPaid = workers[j].overHoursRate + (40* workers[j].hourlyRate);
            } else{
            workers[j].amountPaid  = workers[j].hourlyRate * workers[j].hoursWorked;
            }
            workers[j].taxesPaid = 0.2 * workers[j].amountPaid ;
            workers[j].takeHome = workers[j].amountPaid  -  workers[j].taxesPaid;
            totalGrossPay[j] = workers[j].amountPaid;
            }
            userOutput();
        }
    }while(userInput != 7);
}

  int PromptUser(int index){
      printf("Name: \n");
      scanf(" %s", &workers[index].person);
      printf("Hours: \n");
      scanf(" %lf", &workers[index].hoursWorked);
      printf("Rate: \n");
      scanf(" %lf", &workers[index].hourlyRate);
      printf("\n");
      return 0;
  }

  int userIncomeCalculations(char *pPerson, double *pHourlyRate, double *pHoursWorked, double *pAmountPaid, double *pOverHoursRate){
    for(j=1; j<i; j++){
      if(*pHoursWorked > 40){
          *pOverHoursRate = (*pHoursWorked - 40)* (*pHourlyRate) * 1.5 ;
            *pAmountPaid = *pOverHoursRate + (40* (*pHourlyRate));
        } else{
            *pAmountPaid = *pHourlyRate * *pHoursWorked;
        }
        workers[j].taxesPaid = 0.2 * *pAmountPaid;
        workers[j].takeHome = *pAmountPaid -  workers[j].taxesPaid;
      }
    for(j=1; j<i; j++){
        totalGrossPay[j] = workers[j].amountPaid;
    }  
    return 0;
  }

  double userTaxCalculations(double *pay){
    double temp;
    temp = 0.2 * *pay;
    return temp;
  }

  int userOutput(){
    for(j=1; j<i; j++){
      printf("\nPay to: %s \n", workers[j].person);
      printf("Hours worked: %.2f \n", workers[j].hoursWorked);
      printf("Hourly rate: %.2f \n", workers[j].hourlyRate);
      if(workers[j].hoursWorked >= 40){
          printf("Gross paid: $%.2f \n", workers[j].amountPaid);
          printf("Bass paid: $%.2f \n", 40*workers[j].hourlyRate);
          printf("Overtime pay: $%.2f \n", workers[j].overHoursRate);
      } else{
          printf("Gross paid: $%.2f \n", workers[j].amountPaid);
          printf("Bass paid: $%.2f \n", workers[j].amountPaid);
          printf("Overtime pay: $0 \n");
      }
    workers[j].taxesPaid = userTaxCalculations(&workers[j].amountPaid);
    workers[j].takeHome = workers[j].amountPaid - workers[j].taxesPaid;
    printf("Taxes paid: $%.2f \n", workers[j].taxesPaid);
    printf("Net pay: $%.2f \n\n", workers[j].takeHome);
    }

    double totalCalc = 0;
    for(j=1; j<i; j++){
      totalCalc += totalGrossPay[j];
    }
    printf("\nTotal Paid to all employees = $%.2f", totalCalc);
    printf("\n");
    printf("\n");
    return 0;
  }

  int userOutputOne(int index){
    printf("\nPay to: %s \n", workers[index].person);
    printf("Hours worked: %.2f \n", workers[index].hoursWorked);
    printf("Hourly rate: %.2f \n", workers[index].hourlyRate);
    if(workers[index].hoursWorked >= 40){
        printf("Gross paid: $%.2f \n", workers[index].amountPaid);
        printf("Bass paid: $%.2f \n", 40*workers[index].hourlyRate);
        printf("Overtime pay: $%.2f \n", workers[index].overHoursRate);
      } else{
        printf("Gross paid: $%.2f \n", workers[index].amountPaid);
        printf("Bass paid: $%.2f \n", workers[index].amountPaid);
        printf("Overtime pay: $0 \n");
      }
    workers[index].taxesPaid = userTaxCalculations(&workers[index].amountPaid);
    workers[index].takeHome = workers[index].amountPaid - workers[index].taxesPaid;
    printf("Taxes paid: $%.2f \n", workers[index].taxesPaid);
    printf("Net pay: $%.2f \n\n", workers[index].takeHome);
    return 0;
  }
  
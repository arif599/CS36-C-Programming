#include <stdio.h>

void userPrompt(char *pPerson, double *pHourlyRate, double *pHoursWorked);
void userIncomeCalculations();
double userTaxCalculations(double pay);
double totalPay(double *amountPaid);
void userOutput();

char person[5][25];
double hourlyRate[5];
double hoursWorked[5];
int userEntries;
double totalGrossPay[5];
double overHoursRate[5];
double amountPaid[5];
double taxesPaid[5];
double takeHome[5];
int i;

int main() {
  userPrompt(&person[0][0], hourlyRate, hoursWorked);
  scanf(" ");
  return 0;
}

void userPrompt(char *pPerson, double *pHourlyRate, double *pHoursWorked){

  int breakPerson[5];

  for(i=1; i<=5; i++){
    printf("Enter Name: ");
    scanf("%s", &person[i]);
    breakPerson[i] = strcmp(&person[i], "-1");
    if(breakPerson[i]==0){
        break;
    }

    printf("Enter hourly rate: ");
    scanf("%lf", &pHourlyRate[i]);
    if(pHourlyRate[i]==-1){
        break;
    }

    printf("Enter hours worked: ");
    scanf("%lf", &pHoursWorked[i]);
    if(pHoursWorked[i]==-1){
        break;
    }        
    printf("\n");
  }

  userIncomeCalculations(person, hourlyRate, hoursWorked);
}

void userIncomeCalculations(char *pPerson, double *pHourlyRate, double *pHoursWorked){
    userEntries = i-1;
    for(i=1; i<=userEntries; i++){
      if(hoursWorked[i] > 40){
             overHoursRate[i] = (hoursWorked[i] - 40)*hourlyRate[i]*1.5 ;
            amountPaid[i] = overHoursRate[i] + (40*hourlyRate[i]);
        } else{
            amountPaid[i] = hourlyRate[i] * hoursWorked[i];
        }

        taxesPaid[i] = 0.2 * amountPaid[i];
        takeHome[i] = amountPaid - taxesPaid;

    }
   
    totalGrossPay[i] = totalPay(&amountPaid[0]);
    userOutput();
         
  }

  double userTaxCalculations(double pay){
    int temp;
    temp = 0.2 * pay;
    return temp;
  }

  double totalPay(double *amountPaid){
    double total;
    for(i=1; i<=userEntries; i++){
      total += amountPaid[i];
    }
    return total;
  }

  void userOutput(){
     
     //printf("%d", userEntries);
      for(i=1; i<=userEntries; i++){

        printf("\nPay to: %s \n", person[i]);
        printf("Hours worked: %.2f \n", hoursWorked[i]);
        printf("Hourly rate: %.2f \n", hourlyRate[i]);
       

     if(hoursWorked[i] >= 40){
            printf("Gross paid: $%.2f \n", amountPaid[i]);
            printf("Bass paid: $%.2f \n", 40*hourlyRate[i]);
            printf("Overtime pay: $%.2f \n", overHoursRate[i]);
        } else{
            printf("Gross paid: $%.2f \n", amountPaid[i]);
            printf("Bass paid: $%.2f \n", amountPaid[i]);
            printf("Overtime pay: $0 \n");
        }


    takeHome[i] = amountPaid[i] - userTaxCalculations(amountPaid[i]);

    printf("Taxes paid: $%.2f \n", taxesPaid[i]);
    printf("Net pay: $%.2f \n\n", takeHome[i]);
      }

      printf("\nTotal Paid to all employees = $%.2f", totalGrossPay[i]);
  }
  
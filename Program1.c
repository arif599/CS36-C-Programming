#include <stdio.h>

int main() {
    char person [5][25];
    double hourlyRate[5];
    double hoursWorked[5];
    double amountPaid;
    double taxesPaid;
    double takeHome;
    int i;
    
    for(i=1; i<=5; i++){
        printf("Enter Name: ");
        scanf("%s", &person[i]);
        printf("Enter hourly rate: ");
        scanf("%lf", &hourlyRate[i]);
        printf("Enter hours worked: ");
        scanf("%lf", &hoursWorked[i]);
        printf("\nPay to: %s \n", person[i]);
        printf("Hourly rate: %.2f \n", hourlyRate[i]);
        printf("Hours worked: %.2f \n", hoursWorked[i]);

        if(hoursWorked[i] > 40){
            int overHoursRate = (hoursWorked[i] - 40)*hourlyRate[i]*1.5 ;
            amountPaid = overHoursRate + (40*hourlyRate[i]);
        } else{
            amountPaid = hourlyRate[i] * hoursWorked[i];
        }

        taxesPaid = 0.2 * amountPaid;
        takeHome = amountPaid - taxesPaid;

        printf("Amount paid: $%.2f \n", amountPaid);
        printf("Taxes paid: $%.2f \n", taxesPaid);
        printf("Take home: $%.2f \n\n", takeHome);
    }
    scanf(" ");
    return 0;
}
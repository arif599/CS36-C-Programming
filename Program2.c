#include <stdio.h>

int main() {
    char person [5][25];
    double hourlyRate[5];
    double hoursWorked[5];
    double amountPaid;
    double taxesPaid;
    double takeHome;
    int breakPerson[5];
    int breakHourlyRate[5];
    int breakHoursWorked[5];
    int i;
    
    for(i=1; i<=5; i++){
        printf("Enter Name: ");
        scanf("%s", &person[i]);
        breakPerson[i] = strcmp(person[i], "-1");
        if(breakPerson[i]==0){
            break;
        }
        

        printf("Enter hourly rate: ");
        scanf("%lf", &hourlyRate[i]);
        breakHourlyRate[i] = (int)hourlyRate[i];
        if(breakHourlyRate[i]==-1){
            break;
        }

        printf("Enter hours worked: ");
        scanf("%lf", &hoursWorked[i]);
        breakHoursWorked[i] = (int)hoursWorked[i];
        if(breakHoursWorked[i]==-1){
            break;
        }        
        printf("\n");
    }

        int entries = i-1;
        for(i=1; i<=entries; i++){
            if(breakPerson[i] != 0 && breakHourlyRate[i] != -1 &&  breakHoursWorked[i] != -1){
                printf("\nPay to: %s \n", person[i]);
                printf("Hourly rate: %.2f \n", hourlyRate[i]);
                printf("Hours worked: %.2f \n", hoursWorked[i]);

                if(hoursWorked[i] >= 40){
                    double overHoursRate = (hoursWorked[i] - 40)*hourlyRate[i]*1.5 ;
                    amountPaid = overHoursRate + (40*hourlyRate[i]);
                    printf("Gross paid: $%.2f \n", amountPaid);
                    printf("Bass paid: $%.2f \n", 40*hourlyRate[i]);
                    printf("Overtime pay: $%.2f \n", overHoursRate);
                } else{
                    amountPaid = hourlyRate[i] * hoursWorked[i];
                    printf("Gross paid: $%.2f \n", amountPaid);
                    printf("Bass paid: $%.2f \n", amountPaid);
                    printf("Overtime pay: $0 \n");
                }

                taxesPaid = 0.2 * amountPaid;
                takeHome = amountPaid - taxesPaid;

                printf("Taxes paid: $%.2f \n", taxesPaid);
                printf("Net pay: $%.2f \n\n", takeHome);
                }
        }
    scanf(" ");
    return 0;
}
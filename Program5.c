#include <stdio.h>

//function prototypes
char InputMode();
void EntryPoint();
 int PromptUser(int index);
void SaveEmployee();
void LoadEmployee();

//employee struct
struct Employee{
   char person[25];
   double hourlyRate;
   double hoursWorked;
   double overHoursRate;
   double amountPaid;
   double taxesPaid;
   double takeHome;
};
 
//gloabal variables
struct Employee workers[11]; //array of employees
FILE *caseFfile; //file for case f or F
FILE *caseTfile; //file for case t or T
char tFileName[25]; //name of t file
char fFileName[25]; // name of f file
int usedFfile = 0;
int loopContinue = 1;
int j=0;
int i=3;//number of input for 3 employees from a file or keyboard
 
int main() {
  int userInput;
  int userEditInput;
  int userPrintOneInput;
   
  EntryPoint(); //prompt user for the method of entering data
 
  //menu
   do{
      printf("\n");
      printf("Main Menu \n");
      printf("1. Add Employee \n");
      printf("2. Edit Employee \n");
      printf("3. Print Employee \n");
      printf("4. Print All Employees \n");
      printf("5. Quit \n ");
      scanf(" %d", &userInput);

      if(userInput == 1){
        if(i==10){ //max number of employee is 10
          printf("\nYOU HAVE REACHED MAX EMPLOYEE INPUT (10 is max)\n");
        }else{
          PromptUser(i); //prompts user to enter another employee into array at index i
          i++; // increments total employee count
        }
      }

      if(userInput == 2){
        //prints a list of employee names for editting one employee
        printf("Choose an employee to Edit. \n");
        for(j=1; j<i; j++){
          printf("%d: %s\n",j, workers[j].person);
        }
        scanf(" %d", &userEditInput);
        PromptUser(userEditInput); //replaces the selected employee with new data 
      }

      if(userInput == 3){
        //prints a list of employee names for printing one employee
          printf("Choose an employee to Print. \n");
          for(j=1; j<i; j++){
            printf("%d: %s\n",j, workers[j].person);
          }
          scanf(" %d", &userPrintOneInput);
          //prints out total information of selected employee
          printf("Employee: %s  Rate: %.2f  Hours: %.2f \n", workers[userPrintOneInput].person, workers[userPrintOneInput].hourlyRate, workers[userPrintOneInput].hoursWorked);
          printf("\n");
      }

      if(userInput == 4){
        //prints information for all employees in the array
          for(j=1; j<i; j++){
            printf("Employee: %s  Rate: %.2f  Hours: %.2f \n", workers[j].person, workers[j].hourlyRate, workers[j].hoursWorked);
          }   
          printf("\n");
      }

      if(userInput == 5){
        //before quiting the program, need to save/update data
        SaveEmployee();
        loopContinue = 0; //ends the program by making while statement equal to 0, hence false
      }

   }while(loopContinue != 0);
    system("pause"); 
    return 0;
}
 
char InputMode()
{
  //prompts user to select a type of entry
  char userInputChar;
  printf("Enter data for 3 Employees by keyboard(k) or upload a file(f)? \n");
  scanf("%c", &userInputChar);
  return userInputChar;
}
 
void EntryPoint()
{
   switch (InputMode())
   {
   case 'f':
   case 'F':
        //if case f or F, then input data from the file
        LoadEmployee();//loads data from file
       break;
   case 'k':
   case 'K':
        //if case k or K, then prompt user for the data
       for(i=1; i<=3; i++){
          PromptUser(i); //prompts user
       }
       break;
   default:
       break;
   }
}
 
 int PromptUser(int index){
    //prompts user for input at a specific index
    printf("Enter Name: ");
    scanf(" %s", &workers[index].person);
    printf("Enter Hours: ");
    scanf(" %lf", &workers[index].hoursWorked);
    printf("Enter Rate: ");
    scanf(" %lf", &workers[index].hourlyRate);
    printf("\n");
    return 0;
 }
 
 
void SaveEmployee(){
  //before ending program, this method saves the new updated data

  if(usedFfile == 1){ //if data WAS inputted from file

    caseFfile = fopen(fFileName, "w");//writes the new data into the imported file
    for(j=1; j<i; j++){//exporting and overriding file with new data
      fprintf(caseFfile, "\nName: %s", workers[j].person);
      fprintf(caseFfile, "\nHourly rate: %lf", workers[j].hourlyRate);
      fprintf(caseFfile, "\nHours worked: %lf\n", workers[j].hoursWorked);
    }
    printf("Your %s File Has Been Updated!\n", fFileName);

  }else{//if data WAS NOT inputted from file, but thorugh keyboard

      //prompts user to create a new file
      printf("Create a new File Name: (Example: sample.txt)\n");
      scanf("%s", &tFileName[0]);
      caseTfile = fopen(tFileName, "w");//writes data into the new created file

    for(j=1; j<i; j++){//exporting data into new file
      fprintf(caseTfile, "\nName: %s", workers[j].person);
      fprintf(caseTfile, "\nHourly rate: %lf", workers[j].hourlyRate);
      fprintf(caseTfile, "\nHours worked: %lf\n", workers[j].hoursWorked);
    }
    printf("Your Data Has Been Saved to %s\n",tFileName);
  }
}

void LoadEmployee(){
  //if case f or F is selected, then import data from that file
  printf("Enter File Name: (Example: sample.txt)\n");
  scanf("%s", &fFileName[0]);
  caseFfile = fopen(fFileName, "r");//read the opned file

  for(i=1; i<=3; i++){//insert 3 person data into employee array
    printf("\nEnter Name: ");
    fscanf(caseFfile,"%s\n", &workers[i].person);
    printf("%s", workers[i].person);
    printf("\nEnter hourly rate: ");
    fscanf(caseFfile,"%lf\n", &workers[i].hourlyRate);
    printf("%lf", workers[i].hourlyRate);
    printf("\nEnter hours worked: ");
    fscanf(caseFfile,"%lf\n", &workers[i].hoursWorked);
    printf("%lf", workers[i].hoursWorked);
    printf("\n");
  }
  usedFfile = 1;//indicates that a file was used to import data 
}


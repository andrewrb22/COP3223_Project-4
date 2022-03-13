#include <stdio.h>
#include <stdlib.h>

int checkCrn(int crn);       // returns 1 if crn is OK, 0 otherwise
int getCreditHours(int crn); // returns the credit hours of crn
char *printPrefix(int crn);  // prints the prefix of crn
//---------------------------

int checkCrn(int crn)
{
    int i = 0;
    int CRN[] = {4587, 4599, 8997, 9696, 4580, 4581, 4582, 4583, 3587, 4519, 6997, 9494};
    // For loop, start with i = 0,
    // when i < 12 run this loop and then go to the next one until i > 12.
    // For Loop rule , if i matches one CRN, change the value of i from 0 to 1
    for (i = 0; i < 12; i++)
        if (CRN[i] == crn)
            return 1;
    return 0;
}
//---------------------------
int getCreditHours(int crn)
{
    // Switch until crn matches and then return number of credit hours
    // each case represents course number and the return represents the credit hours
    switch (crn)
    {
    case 9696:
        return 5;
    case 4587:
        return 4;
    case 4599:
        return 3;
    case 8997:
        return 1;
    case 4580:
        return 3;
    case 4581:
        return 4;
    case 4582:
        return 2;
    case 4583:
        return 2;
    case 3587:
        return 4;
    case 4519:
        return 3;
    case 6997:
        return 1;
    case 9494:
        return 3;
    default:
        return 0;
    }
}
//---------------------------
char *printPrefix(int crn)
{
    // Switch on crn to matched course number and return Prefix
    // return presents prefix of course number
    switch (crn)
    {
    case 4587:
        return "MAT 236";
    case 4589:
        return "COP 220";
    case 8997:
        return "GOL 124";
    case 9696:
        return "COP 100";
    case 4580:
        return "MAT 230";
    case 4581:
        return "MAT 231";
    case 4582:
        return "MAT 232";
    case 4583:
        return "MAT 233";
    case 3587:
        return "MAT 256";
    case 4519:
        return "COP 420";
    case 6997:
        return "GOL 127";
    case 9494:
        return "COP 101";
    default:
        return "\t";
    }
}
//------------------------------
void main()
{
    // Values for invoince
    // ch is each credit hours, fee is the admin fee
    double ch = 120.25, fee = 35;
    // crn and hours have a max number for how many can be enter
    int crn[3], hours[3];
    //
    while (1)
    {
        // Total is the total amount for the invoice, starts at zero

        double total = 0;

        // index start at zero
        // sid is student ID , n is number of course enter
        // credsum is the sum of all credit hours, value start 0
        // flag, value for validation
        // c is for yes or not message to continue

        int i = 0, sid, n, credsum = 0, flag;
        char c;

        // Asking for student id
        printf("Enter the student id: \n");
        // Saving the answer into sid(student ID)
        scanf("%d", &sid);
        // Asking for number of course
        printf("Enter how many courses up to 3:  \n");
        // Saving the answer into n
        scanf("%d", &n);
        // If statment, if n (how many course) is greater than 3 or less than 1 run condition
        if (n > 3 || n < 1)
        {
            // Condition: print to the screen "Invalid..."
            printf("Invalid number of courses\n");
            n = 0;
            scanf("%d", &flag);
        }
        else
        {
            // Asking to enter the courses number, %d in the middle means to replace that value for whatever number is n(how many course)
            printf("Enter the %d course number(s)\n", n);
            // For loop, each number enter will be scan and save into crn[i]
            for (i = 0; i < n; i++)
                scanf("%d", &crn[i]);
            // For loop, for each course number conditions will be run until i is greater than n
            for (i = 0; i < n; i++)
            {
                // Condition: if - run checkCrn function above
                // compare crn[i](each value) and if one of them is  = 0 , then is an invalid course number
                if (checkCrn(crn[i]) == 0)
                {
                    // Print invalid message and flag = -1
                    printf("Sorry Invalid CRN(s)\n\n");
                    flag = -1;
                    break;
                }
                // after running if statement and checkCrn fucntion passes and compares every number enter
                //  hours are change to the correct credit hours crn
                hours[i] = getCreditHours(crn[i]);
                // sum of the credit changes to the sum between credsum and hours
                credsum = credsum + hours[i];
            }
        }
        // No more than 7 credit hours validation
        // If statement, if flag is not equal to -1 run
        if (flag != -1)
            // If credsum is greater than 7 print message
            if (credsum > 7)
                printf("Sorry we can't process more than 7 credit hours\n");
            else
            {
                printf("VALENCE COMMUNITY COLLEGE\n ORLANDO FL 10101\n");
                printf("---------------------\n\n");
                // print student id from sid collected above
                printf("Fee invoice prepared for Student V%d \n\n ", sid);
                // print the price of credit hours based on the value assigned at the begining
                printf("1 Credit hour = %.2f \n\n", ch);
                printf("CRN\tCR_PREFIX\tCR_HOURS\n");
                // For Loop, run for each until the index(amount of courses enter) is greater than n
                for (i = 0; i < n; i++)
                {
                    // Value for d is the hours for each course number(index/each of the hours) enter before times ch(price for each credit hour)

                    double d = hours[i] * ch;
                    // print to user the crn (course number)
                    // print the prefix after running printprefix funtion above and matching with one of the course entered
                    // print credit hours of that course numbre
                    // print the value for that class
                    printf("%d\t%s\t%d\t$ %.2f\n", crn[i], printPrefix(crn[i]), hours[i], d);
                    // total is each total + d
                    total = total + d;
                }
                // when loop finished, total is all the course together plus the fee value
                total = total + fee;
                // print fee value assigned above
                printf("\n\tHealth & id fees $ %.2f\n", fee);
                printf("--------------------------------------\n");
                // print the total value
                printf("\t Total Payments $ %.2f\n", total);
            }
        // After passing all validations and getting the invoice, ask user to run the program again
        printf("Would you like to continue Y=yes N=no\n");
        // Saving response from user to continue or not into c
        scanf("%c");
        scanf("%c", &c);
        // Do while loop, run based on user's answer While c is NOT equal to Y or y
        // If the value entered above IS EQUAL to Y or y, Run program again
        do
        {
            // if statment, if c is equal to N or n run condition below
            if (c == 'N' || c == 'n')
            {
                // Condition: print ,message and terminate program
                printf("Thank you for using the program, Goodbye!\n");
                exit(0);
            }
            // if statement, if c is NOT equal to Y or y run condition below
            if (c != 'Y' && c != 'y')
            {
                // Condition Print message below and save new answer into c
                printf("INVALID ENTRY It has to y or n\n");
                scanf("%c");
                scanf("%c", &c);
            }
            // While condition, run only if c is NOT equal to Y or y, otherwise, Run the program again
        } while (c != 'Y' && c != 'y');
    }
}

#include <stdio.h>
#include <stdlib.h>

int checkCrn(int crn);       // returns 1 if crn is OK, 0 otherwise
int getCreditHours(int crn); // returns the credit hours of crn
char *printPrefix(int crn);  // prints the prefix of crn
//---------------------------
void main()
{
    int crn1, crn2, crn3;
    printf("Enter your course numbers :");
    scanf("%d%d%d%d", &crn1, &crn2, &crn3);
    if (checkCrn(crn1) * checkCrn(crn2) * checkCrn(crn3) == 0)
        printf("Invalid crn!\n");
    else
    {
        printf("%d\t%s\t%d\n", crn1, printPrefix(crn1), getCreditHours(crn1));
        printf("%d\t%s\t%d\n", crn2, printPrefix(crn2), getCreditHours(crn2));
        printf("%d\t%s\t%d\n", crn3, printPrefix(crn3), getCreditHours(crn3));
    }
}
//---------------------------
int checkCrn(int crn)
{
    if (crn != 9696 && crn != 4587 && crn != 4599)
        return 0;
    return 1;
}
//---------------------------
int getCreditHours(int crn)
{
    switch (crn)
    {
    case 9696:
        return 5;
    case 4587:
        return 3;
    case 4599:
        return 1;
    }
}
//---------------------------
char *printPrefix(int crn)
{
    switch (crn)
    {
    case 9696:
        return "MAT 111";
    case 4587:
        return "COP 222";
    case 4599:
        return "STA 200";
    }
}

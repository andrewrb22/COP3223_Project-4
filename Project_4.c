#include <stdio.h>
#include <stdlib.h>

int checkCrn(int crn);       // returns 1 if crn is OK, 0 otherwise
int getCreditHours(int crn); // returns the credit hours of crn
char *printPrefix(int crn);  // prints the prefix of crn
//---------------------------

int checkCrn(int crn)
{
    if (crn != 9696 && crn != 4587 && crn != 4599 && crn != 4581 && crn != 8997 && crn != 4580 && crn != 4582 && crn != 4583 && crn != 3587 && crn != 4519 && crn != 6997 && crn != 9494)
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
    return"GOL 127";
  case 9494:
    return "COP 101";
  default:
    return "\t";                   
    }
}
//------------------------------
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


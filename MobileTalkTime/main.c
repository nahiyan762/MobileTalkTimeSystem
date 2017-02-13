#include <stdio.h>
#include <string.h>

char myNumber[15] = "+8801711360078";
int result;
char number[15];
int time;
int select;
float talkTime;
float fnfTaka;
float sameOperatorTaka;
float otherOperatorTaka;

void checkFnf()
{
    char fnf1[15] = "+8801666666666";
    char fnf2[15] = "+8801777777777";
    char fnf3[15] = "+8801888888888";

    if(strcmp(fnf1, number) == 0)
    {
        talkTime = time * fnfTaka;
    }
    else if(strcmp(fnf2, number) == 0)
    {
        talkTime = time * fnfTaka;
    }
    else if(strcmp(fnf3, number) == 0)
    {
        talkTime = time * fnfTaka;
    }
}


void checkCallRate()
{
    printf("Enter Talk Time : ");
    scanf("%d",&time);
    if(result == 1)
    {
       if(select == 3 && time > 90)
       {
           talkTime = time * 0.30;
       }
       else
       {
            talkTime = time * sameOperatorTaka;
       }

        checkFnf();
    }
    else if(result == 2)
    {
        talkTime = time * otherOperatorTaka;
        checkFnf();
    }
    else if(result == 3)
    {
        talkTime = time * 5.50;
    }

}

void checkOperator()
{
    int check;
    printf("Enter Number : ");
    scanf("%s", number);
    if(strlen(number) < 14)
    {
        printf("Number is Not Valid!\n");
        checkOperator();
    }

    check = strncmp(number, myNumber, 6);

    if(check == 0)
    {
        result = 1;
        checkCallRate();
    }
    else
    {
     check = strncmp(number, myNumber, 3);
     if(check == 0)
     {
        result = 2;
        checkCallRate();
     }
     else
     {
        result = 3;
        checkCallRate();
     }

    }
}

void checkPackage()
{
    printf("This number is in Youth Package; Package will be ACTIVATED 10pm - 8am!\n");
    printf("If you want to call at 10pm - 8am PRESS 1 else PRESS 2 : ");
    printf("If you want to bundle package PRESS 3 : ");
    scanf("%d",&select);
    if(select == 1)
    {
        fnfTaka = 0.15;
        sameOperatorTaka = 0.30;
        otherOperatorTaka = 1.00;
        checkOperator();
    }
    else if(select == 2)
    {
        fnfTaka = 0.25;
        sameOperatorTaka = 0.50;
        otherOperatorTaka = 1.30;
        checkOperator();
    }
    else if(select == 3)
    {
        fnfTaka = 0.20;
        sameOperatorTaka = 0.40;
        otherOperatorTaka = 1.10;
        checkOperator();
    }
    else
    {
        printf("You Press The Wrong Button! You Must Press in 1 to 2!\n");
    }
}

int main()
{
    checkPackage();
    printf("%f",talkTime);
    return 0;
}

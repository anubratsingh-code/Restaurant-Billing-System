#include <stdio.h>
#include "billing.h"

int main()
{
    int quantity[SIZE]={0};
    int choice;

    while(1)
    {
        printf("\n==============================");
        printf("\n RESTAURANT BILLING SYSTEM");
        printf("\n==============================");

        printf("\n1. New Order");
        printf("\n2. Print Bill");
        printf("\n3. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                for(int i=0;i<SIZE;i++)
                    quantity[i]=0;

                takeOrder(quantity);
                break;

            case 2:

                printBill(quantity);
                break;

            case 3:

                printf("\nThank You.\n");
                return 0;

            default:

                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}
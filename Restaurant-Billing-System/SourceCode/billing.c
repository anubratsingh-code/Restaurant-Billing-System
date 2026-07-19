#include <stdio.h>
#include "billing.h"

char food[SIZE][30] =
{
    "Burger",
    "Pizza",
    "Sandwich",
    "Cold Drink",
    "French Fries"
};

float price[SIZE] =
{
    120,
    250,
    80,
    50,
    100
};

void displayMenu()
{
    printf("\n============================");
    printf("\n      RESTAURANT MENU");
    printf("\n============================\n");

    for(int i=0;i<SIZE;i++)
    {
        printf("%d. %-20s Rs %.2f\n",
                i+1,
                food[i],
                price[i]);
    }

    printf("0. Finish Order\n");
}

void takeOrder(int quantity[])
{
    int choice, qty;

    while(1)
    {
        displayMenu();

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        if(choice==0)
            break;

        if(choice<1 || choice>SIZE)
        {
            printf("Invalid Choice.\n");
            continue;
        }

        printf("Enter Quantity : ");
        scanf("%d",&qty);

        quantity[choice-1]+=qty;

        printf("Item Added Successfully.\n");
    }
}

float calculateSubtotal(int quantity[])
{
    float subtotal=0;

    for(int i=0;i<SIZE;i++)
    {
        subtotal += quantity[i]*price[i];
    }

    return subtotal;
}

void printBill(int quantity[])
{
    float subtotal = calculateSubtotal(quantity);
    float gst = subtotal * GST;
    float total = subtotal + gst;

    printf("\n==========================================");
    printf("\n           RESTAURANT BILL");
    printf("\n==========================================");

    printf("\n%-20s %-10s %-10s",
            "Item",
            "Qty",
            "Amount");

    printf("\n------------------------------------------");

    for(int i=0;i<SIZE;i++)
    {
        if(quantity[i]>0)
        {
            printf("\n%-20s %-10d %.2f",
                    food[i],
                    quantity[i],
                    quantity[i]*price[i]);
        }
    }

    printf("\n------------------------------------------");
    printf("\nSubtotal : %.2f",subtotal);
    printf("\nGST (5%%) : %.2f",gst);
    printf("\nTotal    : %.2f",total);

    printf("\n==========================================");
    printf("\nThank You! Visit Again.");
    printf("\n==========================================\n");
}
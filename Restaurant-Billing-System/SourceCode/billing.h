#ifndef BILLING_H
#define BILLING_H

#define SIZE 5
#define GST 0.05

extern char food[SIZE][30];
extern float price[SIZE];

void displayMenu();
void takeOrder(int quantity[]);
float calculateSubtotal(int quantity[]);
void printBill(int quantity[]);

#endif
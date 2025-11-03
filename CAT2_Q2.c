
/*
  name:         Owuor Zephania Ulare
  reg:          PA106/G/29218/25
  description:   CAT_Q2
*/





#include <stdio.h>

int main() {
    float hours, wage;
    float grossPay, tax, netPay;
    
    // Ask user for input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    
    printf("Enter hourly wage: $");
    scanf("%f", &wage);
    
    // Calculate gross pay
    if(hours <= 40) {
        grossPay = hours * wage; // No overtime
    } else {
        grossPay = 40 * wage + (hours - 40) * wage * 1.5; // Overtime pay
    }
    
    // Calculate tax
    if(grossPay <= 600) {
        tax = 0.15 * grossPay; // 15% on first $600
    } else {
        tax = 0.15 * 600 + 0.20 * (grossPay - 600); // 20% on rest
    }
    
    // Calculate net pay
    netPay = grossPay - tax;
    
    // Print results
    printf("\nGross Pay: $%.2f\n", grossPay);
    printf("Tax: $%.2f\n", tax);
    printf("Net Pay: $%.2f\n", netPay);
    
    return 0;
}

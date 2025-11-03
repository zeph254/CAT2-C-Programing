/*
  name:         Owuor Zephania Ulare
  reg:          PA106/G/29218/25
  description:   CAT_Q1
*/




// 1. an array is a collection of elements of the same data type, stored in contiguous memory locations

//2.
int scores[2][2] = {
    {65, 92},
    {84, 72}
};
int scores2[2][2] = {
    {35, 70},
    {59, 67}
};
int scores[4][2] = {
    {65, 92},
    {84, 72},
    {35, 70},
    {59, 67}
};
//3.
#include <stdio.h>

int main() {
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };

    // Nested for loop to print elements
    for(int i = 0; i < 2; i++) {          // Loop through rows
        for(int j = 0; j < 2; j++) {      // Loop through columns
            printf("%d ", scores[i][j]);
        }
        printf("\n"); // New line after each row
    }

    return 0;
}
// output 
// [65 92]
// [84 72]


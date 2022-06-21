#include <stdio.h>
#include <stdlib.h>

// Function to input an array
int* inputArray(int size);

// Function to display an array
void displayArray(int* arrayObj, int size);

// Function to return multiplication
int findArrayProduct(int* arrayObj, int n, int left, int i);

int main() {
    // Setup the number of elements in Array
    int arraySize = 0;
    // Input the array
    printf("\nEnter number of elements in the array..");
    scanf("%d",&arraySize);
    int* inputArrayObj = inputArray(arraySize);
    // Display the array
    displayArray(inputArrayObj, arraySize);

    // Multiply array
    findArrayProduct(inputArrayObj, arraySize, 1, 0);
    displayArray(inputArrayObj, arraySize);
    return 0;
}

// Function to input an array
int* inputArray(int size){
    int* arrayObj = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        printf("Enter the element at %d position", i);
        scanf("%d", &arrayObj[i]);
    }
    return arrayObj;
};

// Function to display an array
void displayArray(int* arrayObj, int size){
    printf("\n");
    putchar('[');
    for(int i=0; i < size; i++){
        if(i==size-1){
            printf("%d",arrayObj[i]);
        } else {
            printf("%d,", arrayObj[i]);
        }
    }
    putchar(']');
};

// Product of arrays
int findArrayProduct(int* arrayObj, int n, int left, int i){
    if(n==1){
        // this is to cover for an array with single item
        return 1;
    } else {
        //base case - if it hits the last element!
        if (i == n) {
            printf("\nHit the base case at %d", i);
            return 1;
        }
        printf("\nFor %d run, left is %d", i, left);
        int bkp = arrayObj[i];
        printf("\nFor %d run , bkp is %d", i, arrayObj[i]);
        // initialize left=1 in the function call
        printf("\nFor %d run, the new left (left*arrayObj[i] is %d", i, left * arrayObj[i]);
        int right = findArrayProduct(arrayObj, n, left * arrayObj[i], i + 1);
        // as it comes out of recursion, lets assign the output of right to original left to the ith iteration of array
        printf("\nFor %d run, as it comes out of recursive action, the new right is %d", i, right);
        printf("\nFor %d run, as it comes out of recursive action, the left is %d", i, left);
        arrayObj[i] = left * right;
        printf("\nModifying the array in place for %d run with %d", i, arrayObj[i]);
        printf("\nReturning for %d run - %d", i, bkp * right);
        return bkp * right;
    }
}

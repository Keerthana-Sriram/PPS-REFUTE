#include <stdio.h>
#include <limits.h>  // For INT_MAX and INT_MIN

// Function to perform a simple bubble sort in ascending order
void sort_numbers(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to check if an integer is within the valid range (simulating overflow check)
int get_integer_input() {
    long long input;  // Use long long to check for overflow
    int result;

    // Try to read the number
    if (scanf("%lld", &input) != 1) {
        // If the input is not a valid integer
        printf("Invalid input! Please enter a valid integer.\n");
        result = INT_MIN;  // Use a sentinel value for invalid input
    } else {
        // Check for overflow beyond the range of int
        if (input < INT_MIN || input > INT_MAX) {
            printf("Input out of range! Please enter a number between %d and %d.\n", INT_MIN, INT_MAX);
            result = INT_MIN;  // Use a sentinel value for overflow
        } else {
            result = (int)input;
        }
    }

    return result;
}

int main() {
    int numbers[5];

    printf("Enter 5 integers to sort in ascending order:\n");

    // Loop to get 5 valid numbers from the user
    for (int i = 0; i < 5; i++) {
        int num = get_integer_input();

        // If an invalid input or overflow has occurred, stop the process
        if (num == INT_MIN) {
            return 1;  // Exit the program with an error code
        }

        numbers[i] = num;
    }

    // Sort the numbers in ascending order
    sort_numbers(numbers, 5);

    // Print the sorted numbers
    printf("The numbers in ascending order are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}


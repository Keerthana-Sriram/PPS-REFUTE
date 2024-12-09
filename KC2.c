#include <stdio.h>
#include <limits.h>  // For INT_MAX and INT_MIN
#include <math.h>    // For sqrt function

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;  // Numbers less than or equal to 1 are not prime
    }

    // Check divisibility up to the square root of the number
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;  // Not prime if divisible by any number other than 1 and itself
        }
    }

    return 1;  // Prime if no divisors found
}

// Function to get a valid integer input and check for overflow
int get_integer_input() {
    long long input;  // Use long long to check for overflow

    // Try to read the number
    if (scanf("%lld", &input) != 1) {
        printf("Invalid input! Please enter a valid integer.\n");
        return INT_MIN;  // Sentinel value for invalid input
    }

    // Check if input is within the valid range of int
    if (input < INT_MIN || input > INT_MAX) {
        printf("Input out of range! Please enter a number between %d and %d.\n", INT_MIN, INT_MAX);
        return INT_MIN;  // Sentinel value for overflow
    }

    return (int)input;  // Safe to cast to int
}

int main() {
    int number;

    printf("Enter an integer to check if it is prime: ");

    // Get a valid integer input
    number = get_integer_input();

    // If the input is invalid or out of range, exit
    if (number == INT_MIN) {
        return 1;  // Exit with error code
    }

    // Check if the number is prime
    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}







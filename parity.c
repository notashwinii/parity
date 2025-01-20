#include <stdio.h>
#include <string.h>

// Function to calculate the parity bit
// Takes the binary message and its length as input
// Returns the parity bit (0 or 1) for even or odd parity
int calculate_parity(const char *message, int length, int is_even_parity) {
    int count_ones = 0; // Counter to count the number of 1s in the message

    // Iterate through the message to count 1s
    for (int i = 0; i < length; i++) {
        if (message[i] == '1') {
            count_ones++;
        }
    }

    // Determine the parity bit based on the parity type
    if (is_even_parity) {
        // For even parity, return 1 if the count of 1s is odd, otherwise return 0
        return (count_ones % 2 == 0) ? 0 : 1;
    } else {
        // For odd parity, return 1 if the count of 1s is even, otherwise return 0
        return (count_ones % 2 == 0) ? 1 : 0;
    }
}

int main() {
    char message[100]; // Array to store the binary message input by the user
    int length;        // Length of the binary message

    // Prompt the user to enter a binary message
    printf("Enter a binary message (only 0s and 1s): ");
    scanf("%s", message);

    // Calculate the length of the binary message
    length = strlen(message);

    // Validate the input to ensure it contains only 0s and 1s
    for (int i = 0; i < length; i++) {
        if (message[i] != '0' && message[i] != '1') {
            printf("Error: Invalid binary message. Please enter only 0s and 1s.\n");
            return 1; // Exit the program with an error code
        }
    }

    // Calculate the even and odd parity bits
    int even_parity_bit = calculate_parity(message, length, 1); // Even parity bit
    int odd_parity_bit = calculate_parity(message, length, 0);  // Odd parity bit

    // Display the original message
    printf("\nOriginal binary message: %s\n", message);

    // Display the even parity bit and the message with the even parity bit appended
    printf("Even parity bit: %d\n", even_parity_bit);
    printf("Message with even parity bit appended: %s%d\n", message, even_parity_bit);

    // Display the odd parity bit and the message with the odd parity bit appended
    printf("Odd parity bit: %d\n", odd_parity_bit);
    printf("Message with odd parity bit appended: %s%d\n", message, odd_parity_bit);

    return 0; // Exit the program successfully
}

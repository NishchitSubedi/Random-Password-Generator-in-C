#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password with specified length
void generateRandomPassword(int length) {
    // Arrays of characters for password
    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$%^&*?-_+=<>";

    // Password array
    char password[length + 1]; // Adding 1 for the null terminator

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Ensure the password includes at least one of each type
    password[0] = numbers[rand() % strlen(numbers)];
    password[1] = lowercase[rand() % strlen(lowercase)];
    password[2] = uppercase[rand() % strlen(uppercase)];
    password[3] = symbols[rand() % strlen(symbols)];

    // Fill the rest of the password with random characters from all sets
    for (int i = 4; i < length; i++) {
        int randomCategory = rand() % 4;
        switch(randomCategory) {
            case 0: 
                password[i] = numbers[rand() % strlen(numbers)];
                break;
            case 1:
                password[i] = lowercase[rand() % strlen(lowercase)];
                break;
            case 2:
                password[i] = uppercase[rand() % strlen(uppercase)];
                break;
            case 3:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
        }
    }

    // Shuffle the password to randomize the placement of characters
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password and print it
    password[length] = '\0';
    printf("Generated Password: %s\n", password);
}

// Driver code
int main() {
    int length;
    printf("Enter the desired length for your password: ");
    scanf("%d", &length);

    // Ensure the password is at least 8 characters long for better security
    if (length < 8) {
        printf("Password length should be at least 8 characters for better security.\n");
        return 1;
    }

    // Generate the random password
    generateRandomPassword(length);

    return 0;
}

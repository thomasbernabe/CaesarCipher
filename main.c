/*
 Title: Caesar Cipher
 Created by: Thomas Bernabe-Bacilio 10/11/2022
 Description: This program takes in a plain text and produces an encryption/decryption
 of that text using the Caesar cipher
 */
#include <stdio.h>
#include <ctype.h>

void encrypt(char message[], int key);
//void decrypt(char message[], int key);

int main() {

    char message[100];
    char mode;
    int key;

    printf("Enter mode -- encrypt (e) or decrypt (d): \n");
    scanf(" %c", &mode);
    printf("Enter key (1-35): \n");
    scanf("%d", &key);
    printf("Enter text, ending with ##: ");
    scanf(" %c", &message);

    if(mode == 'e') {
        encrypt(message, key);
    }
    //else if(mode == 'd') {
        //decrypt(message, key);
    //}

    return 0;
}

void encrypt(char message[], int key) {
    char character;
    for (int i = 0; message[i] != '\0'; i++) {
        character = message[i];
        if (character >= 'a' && character <= 'z') {
            character = character + key;
        if (character > 'z') {
            character = character - 'z' + 'a' - 1;
        }
        message[i] = character;
        }
        if (character >= 'A' && character <= 'Z') {
            character += key;
        }
        else if (character > 'Z') {
            character = character - 'Z' + 'A' - 1;
        }
        message[i] = character;
    }
    printf("Encrypted Message: %s", message);
}
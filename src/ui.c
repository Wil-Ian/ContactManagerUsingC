#include <stdio.h>
#include <stdlib.h>
#include "../include/ui.h"

void displayHeader() {
    clearScreen();
    printf("==========================================\n");
    printf("     CONTACT LIST MANAGEMENT SYSTEM      \n");
    printf("          (Imperative C Demo)           \n");
    printf("==========================================\n");
}

void printDivider() {
    printf("------------------------------------------\n");
}

void displayFooter() {
    printf("\n==========================================\n");
    printf("  Developed for CS - Imperative Programming\n");
    printf("==========================================\n");
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pressToContinue() {
    printf("\nPress [Enter] to continue...");
    getchar(); // Catch the newline from previous scanf
    getchar(); // Wait for actual Enter press
}
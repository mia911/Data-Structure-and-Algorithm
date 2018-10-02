#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main () {
    char rock = 'R';
    char scissors = 'S';
    char paper = 'P';
    
    char player1, player2;
    printf("Player 1 input: "); scanf(" %c", &player1);
    printf("Player 2 input: "); scanf(" %c", &player2);
    
    if (player1 == rock) {
        if (player2 == rock) {
            printf("Draw \n");
        } else if (player2 == scissors) {
            printf("Player 1 wins \n");
        } else {
            printf("Player 2 wins \n");
        }
    } else if (player1 == scissors) {
        if (player2 == rock) {
            printf("Player 2 wins\n");
        } else if (player2 == scissors) {
            printf("Draw\n");
        } else {
            printf("Player 1 wins\n");
        }
    } else {
        if (player2 == rock) {
            printf("Player 1 wins\n");
        } else if (player2 == scissors) {
            printf("Player 2 wins\n");
        } else {
            printf("Draw\n");
        }
    }
    
    return 0;
}
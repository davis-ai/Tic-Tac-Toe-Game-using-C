#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define row 3
#define col 3

char board[3][3];

void resetBoard();
void printBoard();
void playerMove();
void computerMove();
int  checkFreeSpaces();
char checkWinner();
void printWinner(char);

const char playerOne = 'x';
const char playerTwo = 'o';



int main() {

    char winner = ' ';
    char replay;

    do {  

        winner = ' ';
        replay = ' ';  
        
        resetBoard();
    
        while ( winner == ' ' && checkFreeSpaces() != 0 )
        {
            printBoard();
            
            playerMove();
            winner = checkWinner();
            if ( winner != ' ' || checkFreeSpaces() == 0 )
            {
                break;

            }

            computerMove();
            winner = checkWinner();
            if ( winner != ' ' || checkFreeSpaces() == 0 )
                break; 


        }

        printBoard();
        printWinner( winner );

        printf("\nDo you Want to play Again? (Y/N) : ");
        scanf("%c");
        scanf(" %c", &replay);
        replay = toupper( replay );
        
    } while ( replay == 'Y' );
    

    
   

    return 0;
}

void resetBoard() {

    for ( int i = 0; i < row; i++ )
        for  ( int j = 0; j < col; j++ )
            board[i][j] = ' ';

}

void printBoard() {

    printf( " %c | %c | %c ", board[0][0], board[0][1], board[0][2] );
    printf( "\n---|---|---\n" );
    printf( " %c | %c | %c ", board[1][0], board[1][1], board[1][2] );
    printf( "\n---|---|---\n" );
    printf( " %c | %c | %c ", board[2][0], board[2][1], board[2][2] );
    printf("\n");


}

void playerMove() {

    int x, y;

   
     
    do {

        printf("\nEnter Row and Column like (1 1) : ");
        scanf("%d %d", &x, &y);
        x--; y--;

        if ( board[x][y] != ' ' )
        {
            printf("Invalid position! try again.. \n");

        } else {

            board[x][y] = playerOne;
            break;
        
        }

    } while ( board[x][y] != ' ' );


}

void computerMove() {
    
    srand(time(NULL));
    int x, y;

    if ( checkFreeSpaces() > 0 ) 
    {   

        do {

            x = rand() % 3;
            y = rand() % 3;
        } while ( board[x][y] != ' ' );

        board[x][y] = playerTwo;

    } else { printWinner(' '); }
     
}

int  checkFreeSpaces() {

    int freeSpaces = 9;

    for ( int i = 0; i < row; i++ )
        for ( int j = 0; j < col; j++ )
            if ( board[i][j] != ' ' )
                freeSpaces--;

    return freeSpaces;

}

char checkWinner() {
    
    for ( int i = 0; i < row; i++ )
        if ( board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];

    for ( int j = 0; j < col; j++ )
        if ( board[0][j] == board[1][j] && board[0][j] == board[2][j])
            return board[0][j];

    if ( board[0][0] == board[1][1] && board[0][0] == board[2][2] )
        return board[0][0];

     if ( board[0][2] == board[1][1] && board[0][2] == board[2][0] )
        return board[0][2];

    return ' ';

}

void printWinner ( char winner ) {
    if ( winner == playerOne )
        printf("\nPlayer One (x) won");
    else if ( winner == playerTwo )
        printf("\nComputer, player (o) won");
    else
        printf("\nDraw...!");
}








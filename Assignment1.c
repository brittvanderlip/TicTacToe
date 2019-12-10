/* Name: Brittany Vanderlip
   Date: July 13, 2019
*/

//Include appropriate libraries
#include <stdio.h>
#include <math.h>

//Function that initializes and creates the tic tac toe board
//Input: number of rows, number of columns, 2D Array
//Output: Stores values into array
void InitializeBoard(int m, int n, char board[][n]) {
  int c = 1;
  //for loop to store the cell numbers into the inital board
  for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++){
        board[i][j] = c + '0';
        c++;
      }
  }
}

//Function that prints the tic tac toe board
//Input: number of rows, number of columns, 2D Array
//Output: Prints the tic tac toe board
void PrintBoard(int m, int n, char board[][n]){

  //for loop that prints tic tac toe board
  for (int i = 0; i < m; i++){
    printf("    |    |\n"); //prints the top vertical lines
    for(int j = 0; j < n; j++){
      if(j < n-1)
        printf("  %c |", board[i][j]); //prints the board values until after the 1st column
      else
        printf("  %c \n", board[i][j]); //prints the board value in 2nd column of row with new line after
    }
    if(i < m-1)
      printf("____|____|____\n"); //Prints the horizontal and vertical lines after each cell
    else
      printf("    |    |\n");
  }
}

//Function allows user to put X's and O's on designated cells of their choice
//Input: number of rows, number of columns, 2D array
//Output: prints the board with the X's and O's the user inputed
void CreateBoard(int m, int n, char board[][n]){
  //declare variable cell as integer and XorO as character
  int cell;
  char XorO;

  //do while loop that prompts user to enter X or O into user specified cell. '-1' to exit.
  do {
  printf("Enter the number of the cell where you want to insert X or O or enter -1 to exit: ");
  scanf("%d", &cell);

  if(cell == -1)
    break;

  if(cell < 1 || cell > 9){
    printf("Invalid Input!\n");
    continue;
  }


  printf("Type (capital) X or O: ");
  scanf("%c", &XorO);
  XorO = getchar();

  //If user does not enter capital X or O, print "invalid input!"
  if(XorO != 'X' && XorO != 'O' ){
    printf("Invalid Input!\n");
    continue;
  }

  //switch case to store character X or O into array (cell of tic tac toe board)
  switch (cell) {
    case 1: board[0][0] = XorO; break;
    case 2: board[0][1] = XorO; break;
    case 3: board[0][2] = XorO; break;
    case 4: board[1][0] = XorO; break;
    case 5: board[1][1] = XorO; break;
    case 6: board[1][2] = XorO; break;
    case 7: board[2][0] = XorO; break;
    case 8: board[2][1] = XorO; break;
    case 9: board[2][2] = XorO; break;
  }
 } while(cell != -1);

 //print the newly created board by ccalling the PrintBoard function
  PrintBoard(m, n, board);
}

//Function to check if the tic tac toe board is valid or not
//Input: number of rows, number of columns, 2d Array
//Output: Returns 1 (true) if board is valid, returns 0 (false) if board is not valid
int IsValidBoard(int m, int n, char board[][n]){
  int countX = 0, countO = 0, difference;

  //For loop to count the number of X's and O's on the board
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 'X')
        countX += 1;
      if(board[i][j] == 'O')
        countO += 1;
    }
  }

  //Determine the difference of X's and O's
  difference = fabs(countX - countO);
  if(difference == 1 || difference == 0) //Note: The empty board will have a difference of 0. Therefore it is accounted for.
    return 1;
  else
    return 0;
}

//Function to determine the winning cells for each player
//Input: number of rows, number of columns, 2D Array
//Output: Prints the winning cells for each player
void ListWinningCells(int m, int n, char board[][n]){
int i = 0, j = 0;
char winningX[10], winningO[10];

//If the board is valid check for winning cells
if(IsValidBoard(m, n, board)){

  //If statements to determine the winning cells for player X
  //To check if winning cell is cell 3
  if((board[0][0] == 'X' && board[0][1] == 'X') || (board[1][1] == 'X' && board[2][0] == 'X')||(board[1][2] == 'X' && board[2][2] == 'X'))
  {
    if(board[0][0] != 'O'){
      winningX[i]= '3';
      i++;
    }
  }

  //To check if winning cell is cell 2
  if((board[0][0] == 'X' && board[0][2] == 'X')||(board[2][1] == 'X' && board[1][1] == 'X'))
  {
    if(board[0][1] != 'O'){
      winningX[i]= '2';
      i++;
    }
  }

  //To check if winning cell is cell 1
  if((board[0][1] == 'X' && board[0][2] == 'X')||(board[1][1] == 'X' && board[2][2] == 'X')||(board[1][0] == 'X' && board[2][0] == 'X'))
  {
    if(board[0][0] != 'O'){
      winningX[i]= '1';
      i++;
    }
  }

  //To check if winning cell is cell 6
  if((board[1][0] == 'X' && board[1][1] == 'X')||(board[0][2] == 'X' && board[2][2] == 'X'))
  {
    if(board[1][2] != 'O'){
      winningX[i]= '6';
      i++;
    }
  }

  //To check if winning cell is cell 5
  if((board[1][0] == 'X' && board[1][2] == 'X')|| (board[0][0] == 'X' && board[2][2] == 'X')||(board[0][0] == 'X' && board[2][0] == 'X')||(board[0][1] == 'X' && board[2][1] == 'X'))
  {
    if(board[1][1] != 'O'){
      winningX[i]= '5';
      i++;
    }
  }

  //To check if winning cell is cell 4
  if((board[1][1] == 'X' && board[1][2] == 'X')||(board[0][0] == 'X' && board[2][0] == 'X'))
  {
    if(board[1][0] != 'O'){
      winningX[i]= '4';
      i++;
    }
  }

  //To check if winning cell is cell 9
  if((board[2][0] == 'X' && board[2][1] == 'X')||(board[0][0] == 'X' && board[1][1] == 'X')||(board[0][2] == 'X' && board[1][2] == 'X'))
  {
    if(board[2][2] != 'O'){
      winningX[i]= '9';
      i++;
    }
  }

  //To check if winning cell is cell 8
  if((board[2][0] == 'X' && board[2][2] == 'X')||(board[0][1] == 'X' && board[1][1] == 'X'))
  {
    if(board[2][1] != 'O'){
      winningX[i]= '8';
      i++;
    }
  }

  //To check if winning cell is cell 7
  if((board[2][1] == 'X' && board[2][2] == 'X')||(board[0][2] == 'X' && board[1][1] == 'X')||(board[0][0] == 'X' && board[1][0] == 'X'))
  {
    if(board[2][0] != 'O'){
      winningX[i]= '7';
      i++;
   }
  }

  //Checking for winning cell for player O
  //To check if winning cell is cell 3
  if((board[0][0] == 'O' && board[0][1] == 'O') || (board[1][1] == 'O' && board[2][0] == 'O')||(board[1][2] == 'O' && board[2][2] == 'O'))
  {
    if(board[0][0] != 'X'){
      winningO[j]= '3';
      j++;
    }
  }

  //To check if winning cell is cell 2
  if((board[0][0] == 'O' && board[0][2] == 'O')||(board[2][1] == 'O' && board[1][1] == 'O'))
  {
    if(board[0][1] != 'X'){
      winningO[j]= '2';
      j++;
    }
  }

  //To check if winning cell is cell 1
  if((board[0][1] == 'O' && board[0][2] == 'O')||(board[1][1] == 'O' && board[2][2] == 'O')||(board[1][0] == 'O' && board[2][0] == 'O'))
  {
    if(board[0][0] != 'X'){
      winningO[j]= '1';
      j++;
    }
  }

  //To check if winning cell is cell 6
  if((board[1][0] == 'O' && board[1][1] == 'O')||(board[0][2] == 'O' && board[2][2] == 'O'))
  {
    if(board[1][2] != 'X'){
      winningO[j]= '6';
      j++;
    }
  }

  //To check if winning cell is cell 5
  if((board[1][0] == 'O' && board[1][2] == 'O')|| (board[0][0] == 'O' && board[2][2] == 'O')||(board[0][0] == 'O' && board[2][0] == 'O')||(board[0][1] == 'O' && board[2][1] == 'O'))
  {
    if(board[1][1] != 'X'){
      winningO[j]= '5';
      j++;
    }
  }

  if((board[1][1] == 'O' && board[1][2] == 'O')||(board[0][0] == 'O' && board[2][0] == 'O'))
  {
    if(board[1][0] != 'X'){
      winningO[j]= '4';
      j++;
    }
  }

  //To check if winning cell is cell 9
  if((board[2][0] == 'O' && board[2][1] == 'O')||(board[0][0] == 'O' && board[1][1] == 'O')||(board[0][2] == 'O' && board[1][2] == 'O'))
  {
    if(board[2][2] != 'X'){
      winningO[j]= '9';
      j++;
    }
  }

  //To check if winning cell is cell 8
  if((board[2][0] == 'O' && board[2][2] == 'O')||(board[0][1] == 'O' && board[1][1] == 'O'))
  {
    if(board[2][1] != 'X'){
      winningO[j]= '8';
      j++;
    }
  }

  //To check if winning cell is cell 7
  if((board[2][1] == 'O' && board[2][2] == 'O')||(board[0][2] == 'O' && board[1][1] == 'O')||(board[0][0] == 'O' && board[1][0] == 'O'))
  {
    if(board[2][0] != 'X'){
      winningO[j]= '7';
      j++;
    }
  }

  if (i == 0 && j ==0)
      printf("There are no winning cells.\n");

  //If statement to display the winning cells for player X
  if (i > 0){
      printf("Cells ");
      for (int k = 0, l = 0; k < i; k++){
        printf("#%c ", winningX[k]);
        l++;

        if(l < i)
        printf("and ");
      }
       printf(" are winning cells for player X.\n");
    }

  //If statement to display the winning cells for player O
    if (j > 0){
        printf("Cells ");
        for (int m = 0, n = 0; m <j; m++){
          printf("#%c ", winningO[m]);
          n++;

          if(n < j)
          printf("and ");
        }
        printf(" are winning cells for player O.\n");
       }
      }

  else
    printf("The board is invalid. Cannot predict winning cells for this board.\n");
}

//Begin program execution
int main(){

  //Declare integer and character variables
  int m = 3, n = 3, IsValidBoard();
  char board[m][n], menu;

  //Call function to initialize tic tac toe board
  InitializeBoard(m, n, board);

  //do while loop that prompts user to choose an option
  do{
    printf("press 'p' to print the tic-tac-toe board\n");
    printf("press 'c' to create a tic-tac-toe board with some X and O cells\n");
    printf("press 't' to test if a tic-tac-toe board is valid or invalid board\n");
    printf("press 'w' to predict winning cell for player X or O\n");
    printf("press 'e' to exit\n");
    scanf(" %c", &menu);

    //switch statement that calls the corresponding functions
    //breaks out of do while loop when user enters 'e'
    switch (menu) {
      case 'p': PrintBoard(m, n, board); break;
      case 'c': CreateBoard(m, n, board); break;
      case 't': if(IsValidBoard(m, n, board))
                  printf("The board is valid!\n");
                else
                  printf("The board is not valid!\n");
                break;
      case 'w': ListWinningCells(m, n, board);
                break;
      case 'e': break;
      default: printf("Not a valid menu option.\n");
    }
    printf("\n");
  }while(menu != 'e');

  return 0;
}//End program execution

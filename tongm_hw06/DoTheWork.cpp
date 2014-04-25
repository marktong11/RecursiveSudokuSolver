#include "DoTheWork.h"

/****************************************************************
 * Class for doing a Sudoku solution by brute force recursively. This class
 * reads in the data and then sends it to the Board class to be parsed. 
 * It then solves the sudoku puzzle recursively. 
 *
 * Author/copyright:  Duncan Buell. used with permission by Mark Tong
 * Date: 4 November 2013
 *
**/

static const string TAG = "DoTheWork: ";

/****************************************************************
 * Constructor.
**/
DoTheWork::DoTheWork()
{
}

/****************************************************************
 * Destructor.
**/
DoTheWork::~DoTheWork()
{
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/

/****************************************************************
 * The function to read in the sudoku puzzle. This function reads in a line
 * checks if it is empty and then sends it to the board class to be parsed.
 * Then displays initial state of the game and calls the recursive function to
 * solve the sudoku. 
 *
 * Parameters: Scanner& inStream: read in the file
 *             ostream& ouStream: write the file
 *
**/
void DoTheWork::doTheWork(Scanner& inStream, ostream& outStream){
  string line;

  while(inStream.hasMoreData()){
    line = inStream.nextLine();
    if(line.empty()){
      //if its an empty line dont do anything
    }
    else{
      board.readData(line);
    }
  }

  board.display(outStream << "");

  addSquare(ZERO, ZERO, outStream << "");
}


/****************************************************************
 * Recursive function for the assignment to solve the sudoku puzzle by
 * brute force. This function sets the current box to be solved and then 
 * checks the next box to be solved for validity. This allows the recursion to
 * backtrack to a previous state if no number is valid and holds each box 
 * for the previous box's value. The column count increments each time a new
 * box is checked and will increment the row count if it reaches nine (the end).
 *
 *
 * Parameters: int row: the row which to start the recursion
 *             int col: the column which to start the recursion
 *             ostream& outStream: file writer
 *
 * Returns: true if the puzzle is either solved or the next box is valid
 *          recursive function for the next box if it is a fixed number
 *          false if no number is valid and the function must backtrack
 *  
 *
**/
bool DoTheWork::addSquare(int row, int col, ostream& outStream){

  //increment rows because columns ended
  if (col==NINE){
    col = ZERO;
    row++;
    // puzzle is solved, there are no more possible rows
    if (row==NINE){   
      return true; 
    }
  }

  //if it is a fixed number
  if(board.getSquare(row,col) != DUMMY){
    //check the next box 
    return addSquare(row,col+ONE, outStream << "");
  }
  else{
    //guess a number
    for(int i = ONE; i <= NINE; i++){			
	    board.setSquare(row,col,i);
	    if((board.checkRow(row,col) == true) && (board.checkColumn(row,col) == true)
	    && (board.checkSection(row,col) == true)){
        board.display(outStream << " ");
        //if the number fits check the next box to make sure it is legal too
	      if(addSquare(row, col+ONE, outStream << "")){
		    return true;
		    }
	    }
    }

    //if no number fits then set the previous box back and start over
    board.setSquare(row, col, DUMMY);

    return false;
  }
}

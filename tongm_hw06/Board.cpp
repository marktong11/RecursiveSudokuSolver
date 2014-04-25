#include "Board.h"

/****************************************************************
 * Class for doing the board. Contains a display function to show the 
 * board. A readData function to add each line of the input file
 * to the board. Functions to check whether the board remains valid for 
 * and input value and functions to set a value in the board as well as
 * get values from the board. 
 *
 *
 * Author/copyright:  Duncan Buell. used with permission by Mark Tong
 * Date: 4 November 2013
 *
**/

static const string TAG = "Board: ";

/****************************************************************
 * Constructor.
**/
Board::Board()
{
}

/****************************************************************
 * Destructor.
**/
Board::~Board()
{
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/

/****************************************************************
 * Function for displaying the board.
**/
void Board::display(ostream& outStream)
{
  int count = ZERO;
  int count2 = ZERO;

  outStream << "**************************************************" << endl;
  for(int row = ZERO; row < NINE; ++row)
  {
    for(int col = ZERO; col < NINE; ++col)
    {
      vector<int> theRow = this->theBoard[row];
      if(DUMMY == theRow[col])
      {
        outStream << " . ";
        outStream.flush();
      }
      else
      {
        outStream << " " << theRow[col] << " ";
        outStream.flush();
      }
      count++;
      if((0 == count%THREE) && (col < NINE))
      {
        outStream << "|";
        outStream.flush();
      }
    
    } // for(int col = ONE; col <= NINE; ++col)
    outStream << endl;
    outStream.flush();
    count2++;
    if((0 == count2%THREE) && (row < NINE))
    {
      outStream << "---------|---------|---------" << endl;
      outStream.flush();
    }
  } // for(int row = ONE; row <= NINE; ++row)

  outStream << "**************************************************" << endl;

} // void Board::display()

/****************************************************************
 * Function to check a row for validity. Checks the row according to 
 * the value that was just input to make sure that the row does not already
 * contain this value. 
 *
 * Parameters: int row: the row the value was placed in
 *             int col: the column the value was placed in
 *
 *
 * Returns: false if the value is already in the row
 *          true if the value is not already in the row
 *
**/
bool Board::checkRow(int row, int col){
  for (int i = ZERO; i < NINE; i++){
    if (i != col){
      if (theBoard[row][i] == theBoard[row][col]){
        return false;
      }
    }
  }
  return true;
}

/****************************************************************
 * Function to check a column for validity. Checks the column according to 
 * the value that was just input to make sure that the column does not already
 * contain this value. 
 *
 * Parameters: int row: the row the value was placed in
 *             int col: the column the value was placed in
 *
 *
 * Returns: false if the value is already in the column
 *          true if the value is not already in the column
 *
**/
bool Board::checkColumn(int row, int col){
  for (int i = ZERO; i < NINE; i++){
    if (i != row){
      if (theBoard[i][col] == theBoard[row][col]){
        return false;
      }
    }
  }
  return true;
}

/****************************************************************
 * Function to check a 3x3 section of the board to make sure it does
 * not already contain the value. cuts the row and column into a third
 * and then checks this smaller 3x3 section for the input value to see
 * if it contains this value already.
 *
 * Parameters: int row: the row the value was placed in
 *             int col: the column the value was placed in
 *
 * Returns: false if the value is already contained in the section
 *          true if the value is not already contained in the section
 *
**/
bool Board::checkSection(int row, int col){
  int sectionCol = row/THREE;
  int sectionRow = col/THREE;

  //make sure to check the right section for value
  for (int i = sectionCol * THREE; i < (sectionCol*THREE + THREE); i++){
    for (int j = sectionRow * THREE; j < (sectionRow*THREE + THREE); j++) {
      if (i != row || j != col) {
        if (theBoard[row][col] == theBoard[i][j]) {
          return false;
        }
      }
    }
  }
  return true;
}

/****************************************************************
 * Function to return a value at the given place in the board. adds the 
 * row to a temporary vector then checks the location of the row and column
 * to find the value in the row.
 *
 * Parameters: int row: the row to look for the value
 *             int col: the column to look for the value
 *
 * Returns: the value at the specified location
 *          0 is there is an error and there is no value
 *
**/
int Board::getSquare(int row, int col){
  vector<int> temp;
 
  for(int i = ZERO; i < NINE; ++i){
  temp = theBoard[i];
    if(i == row){
      for(int j = ZERO; j < NINE; ++j){
        if(j == col){
          return temp[j];
        }
      }
    }
  }
  return 0;
}
  
/****************************************************************
 * Function to parse a line from the DoTheWork clas. Takes in a line
 * and adds it a temporary row vector. Then adds this row to the board
 * vector to create the board.
 *
 * Parameters: string inString: the line to be parsed
 *
**/
void Board::readData(string inString){
  ScanLine inScanLine;
  vector<int> row;
  string temp;
  int value;

  inScanLine.openString(inString);
  while(inScanLine.hasMoreData()){
    temp = inScanLine.next();
    if(temp == "."){
      row.push_back(DUMMY);
    }
    else{
      value = Utils::stringToInteger(temp);
      row.push_back(value);
    }
  }
  theBoard.push_back(row);
}

/****************************************************************
 * The function to set the value of a certain box in the sudoku puzzle.
 * at the specified row and column changes the location to the value
 * that was passed in. 
 *
 * Parameters: int row: the row to look for the value
 *             int col: the column to look for the value
 *             int value: the value which to change the board to
 *
**/
void Board::setSquare(int row, int col, int value){
  for(int i = ZERO; i < NINE; ++i){
    if(i == row){
      for(int j = ZERO; j < NINE; ++j){
        if(j == col){
          theBoard[i][j] = value;
        }
      }
    }
  }
}


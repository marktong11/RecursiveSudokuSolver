/****************************************************************
 * Header for the 'Board' class.
 *
 * Author/copyright:  Duncan Buell used with permission by Mark Tong
 * Date: 9 May 2013
 *
**/

#ifndef BOARD_H
#define BOARD_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"


#include "Constants.h"

class Board
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Board();
  virtual ~Board();

/****************************************************************
 * General functions.
**/
  bool isLegal();

  bool checkRow(int row, int col);
  bool checkColumn(int row, int col);
  bool checkSection(int row, int col);

  void display(ostream& outStream);
  int getSquare(int row, int col);
  void setSquare(int row, int col, int value);

  void readData(string inString);

private:
/****************************************************************
 * Variables.
**/
  vector< vector<int> > theBoard;

/****************************************************************
 * Functions.
**/
};

#endif // BOARD_H

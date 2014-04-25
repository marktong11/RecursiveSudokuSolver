/****************************************************************
 * Header for the 'DoTheWork' class.
 *
 * Author/copyright:  Duncan Buell used with permission by Mark Tong
 * Date: 9 May 2013
 *
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "Constants.h"

#include "Board.h"

class DoTheWork
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  DoTheWork();
  virtual ~DoTheWork();

/****************************************************************
 * General functions.
**/
  void doTheWork(Scanner& inStream, ostream& outStream);
  // checkLegal(minRow, maxRow, minCol, maxCol);

private:
/****************************************************************
 * Variables.
**/
  // int depth;
  Board board;

/****************************************************************
 * Functions.
**/
  bool addSquare(int row, int col, ostream& outStream);
};

#endif // DOTHEWORK_H

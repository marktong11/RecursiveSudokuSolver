GPP = g++ -O3 -Wall

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = Main.o
D = DoTheWork.o
B = Board.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $(M) $(D) $(B) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(D) $(B) $(SL) $(S) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c Main.cpp

DoTheWork.o: DoTheWork.h DoTheWork.cpp
	$(GPP) -o DoTheWork.o -c DoTheWork.cpp

Board.o: Board.h Board.cpp
	$(GPP) -o Board.o -c Board.cpp

ScanLine.o: $(SCANLINE)/ScanLine.h $(SCANLINE)/ScanLine.cpp
	$(GPP) -o ScanLine.o -c $(SCANLINE)/ScanLine.cpp

Scanner.o: $(SCANNER)/Scanner.h $(SCANNER)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(SCANNER)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean


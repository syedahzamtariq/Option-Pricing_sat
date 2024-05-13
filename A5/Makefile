output: BinomialTreeModel02.o Option05.o OptionPricer05.cpp Butterfly.o Strangle.o DoubDigitOpt.o
	g++ BinomialTreeModel02.o Option05.o OptionPricer05.cpp Butterfly.o Strangle.o DoubDigitOpt.o -o output

BinomialTreeModel02.o: BinomialTreeModel02.cpp BinomialTreeModel02.h
	g++ -c BinomialTreeModel02.cpp
	
Option05.o: Option05.cpp Option05.h
	g++ -c Option05.cpp

OptionPricer05.o: OptionPricer05.cpp OptionPricer05.h
	g++ -c OptionPricer05.cpp
	
DoubDigitOpt.o: DoubDigitOpt.cpp DoubDigitOpt.h
	g++ -c DoubDigitOpt.cpp

Butterfly.o: Butterfly.cpp Butterfly.h
	g++ -c Butterfly.cpp

Strangle.o: Strangle.cpp Strangle.h
	g++ -c Strangle.cpp

clean: 
	rm *.o output
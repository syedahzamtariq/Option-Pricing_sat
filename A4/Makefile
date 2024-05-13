output: BinomialTreeModel02.o Option05.o OptionPricer05.cpp DoubDigitOpt.o BullSpread.o BearSpread.o
	g++ BinomialTreeModel02.o Option05.o OptionPricer05.cpp DoubDigitOpt.o BullSpread.o BearSpread.o -o output

BinomialTreeModel02.o: BinomialTreeModel02.cpp BinomialTreeModel02.h
	g++ -c BinomialTreeModel02.cpp
	
Option05.o: Option05.cpp Option05.h
	g++ -c Option05.cpp

OptionPricer05.o: OptionPricer05.cpp OptionPricer05.h
	g++ -c OptionPricer05.cpp

DoubDigitOpt.o: DoubDigitOpt.cpp DoubDigitOpt.h
	g++ -c DoubDigitOpt.cpp

BullSpread.o: BullSpread.cpp BullSpread.h
	g++ -c BullSpread.cpp

BearSpread.o: BearSpread.cpp BearSpread.h
	g++ -c BearSpread.cpp

clean: 
	rm *.o output
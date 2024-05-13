CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

ComputedefInteg: ComputedefInteg.o  findDefinite.o
	$(CC) $(CFLAGS) -o ComputedefInteg ComputedefInteg.o  findDefinite.o

ComputedefInteg.o: ComputedefInteg.cpp defInteg.h
	$(CC) $(CFLAGS) -c ComputedefInteg.cpp

find_definte_integral.o:  defInteg.h findDefinite.cpp
	$(CC) $(CFLAGS) -c findDefinite.cpp
	
clean:
	rm -rf ComputedefInteg *.o

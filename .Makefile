#Make file for Thu Jan 01 02:01:14 1970
#Meluleki DubeCPP =g++
CPPFLAGS =-std=c++11
TARGET=main
SRC=main.cpp 
OBJECTS=main.o 


$(TARGET): $(OBJECTS)
	$(CPPFLAGS) $(OBJECTS)-o $@ $(CPPFLAGS)

$(OBJECTS): $(SRC)
	$(CPPFLAGS) $< -c $(SRC) $(CPPFLAGS)

run:
	./$(TARGET)clean:
	rm -f -r *.o bin/*.o# end of Makefile
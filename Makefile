CFLAGs=-Wall -Wextra -ggdb

all: searching searching.i searching.s

searching.o: main.cpp
		g++ $(CFLAGS) -Wa,-a=searching.lst -c main.cpp

searching: main.o
		g++ $(CFLAGS) -Bstatic -Wl,-Map=searching.map -o searching main.o

searching.i: main.cpp
		g++ -E main.cpp >searching.i

searching.s: main.cpp
		g++ -S main.cpp

# adding verbose for seeing all command line
verbose:
		g++ -v $(CFLAGS) -Wextra -c main.cpp

# cleaning after compilation
clean:
		rm -f searching searching.i main.s main.o searching.map searching.lst
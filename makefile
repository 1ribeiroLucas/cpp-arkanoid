ELEMENTS_PATH = src/elements

run: clean main

main: main.cpp pad
		g++ main.cpp pad.o -I./include -L./lib -lraylib -g -o main

pad: $(ELEMENTS_PATH)/classes/pad.cpp $(ELEMENTS_PATH)/classes/headers/pad.h
		g++ $(ELEMENTS_PATH)/classes/pad.cpp -c -o pad.o -Wall -pedantic

clean:
		rm -rf main *.o
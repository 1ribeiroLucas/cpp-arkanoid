ELEMENTS_PATH = src/elements

run: clean main

main: main.cpp pad src/utils/index.cpp
		g++ main.cpp *.o -I./include -L./lib -lraylib -g -o main -Wall -pedantic && ./main

pad: $(ELEMENTS_PATH)/classes/pad.cpp $(ELEMENTS_PATH)/classes/headers/pad.h
		g++ $(ELEMENTS_PATH)/classes/pad.cpp -c -o pad.o -Wall -pedantic

# utils: src/utils/drawWalls.cpp
# 		g++ src/utils/drawWalls.cpp -c -o utils.o -Wall -pedantic

clean:
		rm -rf main *.o
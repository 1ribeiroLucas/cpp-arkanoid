ELEMENTS_PATH = src/elements

run: clean main

main: main.cpp pad ball brick src/utils/index.cpp
		g++ main.cpp *.o -I./include -L./lib -lraylib -g -o main -Wall -pedantic && ./main

pad: $(ELEMENTS_PATH)/classes/pad.cpp $(ELEMENTS_PATH)/classes/headers/pad.h
		g++ $(ELEMENTS_PATH)/classes/pad.cpp -c -o pad.o -Wall -pedantic

ball: $(ELEMENTS_PATH)/classes/ball.cpp $(ELEMENTS_PATH)/classes/headers/ball.h
		g++ $(ELEMENTS_PATH)/classes/ball.cpp -c -o ball.o -Wall -pedantic

brick: $(ELEMENTS_PATH)/classes/brick.cpp $(ELEMENTS_PATH)/classes/headers/brick.h
		g++ $(ELEMENTS_PATH)/classes/brick.cpp -c -o brick.o -Wall -pedantic

clean:
		rm -rf main *.o
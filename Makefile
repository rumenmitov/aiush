CC     := g++
SRC    := src/main.cpp src/weigh.cpp
FLAGS  := -Wall

all: release


debug:
	@mkdir -p build/debug
	@$(CC) -o build/debug/aiush -I include $(SRC) $(FLAGS) -g -DDEBUG -DTESTS

release:
	@mkdir -p build/release
	@$(CC) -o build/release/aiush -I include $(SRC) $(FLAGS) -O3

clean:
	@rm -rf build/



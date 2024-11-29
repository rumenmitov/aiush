CC     := gcc
SRC    := src/main.c
FLAGS  := -Wall

all: release


debug:
	@mkdir -p build/debug
	@$(CC) -o build/debug/aiush $(SRC) $(FLAGS) -g -DDEBUG

release:
	@mkdir -p build/release
	@$(CC) -o build/release/aiush $(SRC) $(FLAGS) -O3

clean:
	@rm -rf build/



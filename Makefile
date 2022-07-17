all:
	@g++ -I include -L lib -o main src/main.cpp src/game.cpp src/rendering.cpp src/util/random.cpp src/util/time.cpp -lmingw32 -lSDL2main -llibSDL2
	@main.exe
	@del main.exe
# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TEST_TARGET = UnitTests
GAME_TARGET = game

# Source files
TEST_SRCS = fireMonster.cpp waterMonster.cpp earthMonster.cpp airMonster.cpp FirePlayer.cpp WaterPlayer.cpp EarthPlayer.cpp AirPlayer.cpp elementalDragon.cpp Player.cpp Spell.cpp unitTestMain.cpp unitTesting.h
GAME_SRCS = fireMonster.cpp waterMonster.cpp earthMonster.cpp airMonster.cpp FirePlayer.cpp WaterPlayer.cpp EarthPlayer.cpp AirPlayer.cpp elementalDragon.cpp Player.cpp Spell.cpp main.cpp
# Build and run tests

.PHONY: all

all: tests game

tests:
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)
	./$(TEST_TARGET)

game:
	$(CXX) $(CXXFLAGS) -o $(GAME_TARGET) $(GAME_SRCS)
	./$(GAME_TARGET)

# Clean rule

.PHONY: clean

clean:
	rm -f $(TEST_TARGET)
	rm -f $(GAME_TARGET)




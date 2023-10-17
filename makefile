# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TARGET = UnitTests

# Source files

SRCS = fireMonster.cpp waterMonster.cpp earthMonster.cpp airMonster.cpp FirePlayer.cpp WaterPlayer.cpp EarthPlayer.cpp AirPlayer.cpp elementalDragon.cpp Player.cpp Spell.cpp unitTestMain.cpp unitTesting.h
# Build and run tests

.PHONY: all

all:

	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

	./$(TARGET)

# Clean rule

.PHONY: clean

clean:

	rm -f $(TARGET)



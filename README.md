# YLUNIProject
Yaline and Lucas' Year 1 OOP Project

# Project Description
Our first ever C++ project in university, vital in introducing and appling the applications of Object Oriented Programming (OOP), as well as the fundemental concepts in project planning, software development and utilising UML diagrams. Although there is a game breaking bug where if you input a value that is different from the expected values, it would go into an infinite loop, I enjoyed working with my group member, to plan and create this project. The game allows for players to engage in strategic turn based battles while progressing through an immersive storyline, and save their progress locally. When players want to come back to their save, players can do so seamlessly in the main menu.

# Challenges and Potential Future Features
There was many challenges faced throughout the project, as well as bugs. Ideally, the project would first have to be refactored and the OOP principles would have to be better applied, since the many of the classes currently have hard coded code. During the planning, the vision for this project didn't fit the time we had to do this project as well as our skills in programming, so in the end, many of the wanted functionalites were scrapped and code were a bit rushed. 

How to compile the game:
1. Simply download the repository:
```
git clone https://github.com/JingZheLim/YLUNIProject.git
```
2. Copy paste into terminal:
```
g++ fireMonster.cpp waterMonster.cpp earthMonster.cpp airMonster.cpp FirePlayer.cpp WaterPlayer.cpp EarthPlayer.cpp AirPlayer.cpp elementalDragon.cpp Player.cpp Spell.cpp main.cpp -o Elementals
```

How to run unit test:
* In the terminal, enter "make" and hit enter 
* There is a total 10 unit test functions 

The game saves:
* The game saves after each battle
* Continuing the game from the menu takes player back into last saved battle 





COMP 2404 Final Exam

Author:
	Curtis Gauthier
	101102886

Purpose:
	This program simulates a game where hero objects move from the start of a grid to the end of the grid with goal of reaching the end before being defeated by fighters and dragons

Files:
	main.cc
	Control.cc Control.h
	View.cc View.h
	Game.cc Game.h
	Board.h
	QuestPLayers.cc QuestPlayers.h
	Heroes.cc Heroes.h
	Fighters.cc Fighters.h
	Dragon.cc Dragon.h
	Items.cc Items.h
	Shield.cc
	Sword.cc
	Potion.cc
	random.cc random.h
	Makefile
	README.txt
	

Compilation/Launching:
	make
	./Final

Usage:
	When prompted enter 1 to start the game or 0 to exit
	Once the game has finished, the user will be promted again until theydecide to exit

Innovative feature:
	The innovative feature implemented in the game is a new entity that the heroes are able to interect with in the game
	The base class "Items" has three subclasses; Sword, Shield and Potion
	At the initial startup of the game, one of each of these items are spawned in a random position on the board
	When a hero object collides with one, the item increases one of the hero's stats
	Shield, represented by '1': increases the hero's armour randomly by 1-3
	Sword, represented by '2': increases the hero's strength by 3
	Potion, represented by '3': increases the hero's health randomly by 5-7
	Once a potion has been used, the memory is dealloacted and removed from the game
	
	

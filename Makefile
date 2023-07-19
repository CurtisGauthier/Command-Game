Final:	main.o View.o Control.o QuestPlayers.o Heroes.o Dragon.o Game.o Fighters.o random.o Board.h Items.o Shield.o Sword.o Potion.o
	g++ -o Final main.o View.o Control.o QuestPlayers.o Heroes.o Dragon.o Game.o Fighters.o random.o Items.o Shield.o Sword.o Potion.o

main.o:	main.cc 
	g++ -c main.cc

View.o: View.cc View.h
	g++ -c View.cc

QuestPlayers.o: QuestPlayers.cc QuestPlayers.h
	g++ -c QuestPlayers.cc

Heroes.o: Heroes.cc Heroes.h
	g++ -c Heroes.cc

Dragon.o: Dragon.cc Dragon.h
	g++ -c Dragon.cc

Game.o: Game.cc Game.h
	g++ -c Game.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Fighters.o: Fighters.cc Fighters.h
	g++ -c Fighters.cc

random.o: random.cc random.h
	g++ -c random.cc

Items.o: Items.cc Items.h
	g++ -c Items.cc

Shield.o: Shield.cc Items.h
	g++ -c Shield.cc

Sword.o: Sword.cc Items.h
	g++ -c Sword.cc

Potion.o: Potion.cc Items.h
	g++ -c Potion.cc

clean:
	rm -f *.o Final

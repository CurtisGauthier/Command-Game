#include <iostream>
#include <list>
#include <string>
using namespace std;


#include "Game.h"

//constructor
Game::Game(){
   initQuesters();
}

//destructor
Game::~Game(){
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
    delete (*it);
  }
}

//main loop of the game
//iterates until a win condition of the game is met
void Game::play(){
  while(true){
    if (endGame()) break;
    createFighter();
    moveQuesters();
    removeFighters();
    updateBoard();
    board.print();
    cout << endl;
  }
  cout << winCon << endl;

}

//60% chance to create a new fighter object
void Game::createFighter(){
  int r = random(5);
  if (r<3) questerList.push_back(new Fighters());

}

//iterates through the list of QP and calls each of their move functions
//after moving checks if the object collides with any others at that position
void Game::moveQuesters(){
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
    (*it)->move();
    checkCollision(*it);
  }

}


//iterates through the list of QP to see if any object has the same position
//then handles the collision
void Game::checkCollision(QuestPlayers* qp){
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
    if (qp->getPositionX()==(*it)->getPositionX() && qp->getPositionY()==(*it)->getPositionY() && qp->getId()!=(*it)->getId()){
      collide(qp, (*it));
    }  
  }
}

//determines what type of QuestPlayer each object colliding is
//determines how to handle the collision based on the types pf QP
void Game::collide(QuestPlayers* qp1, QuestPlayers* qp2){

  //Collisions when the first pointer is a Hero
  Heroes* hp = dynamic_cast<Heroes*> (qp1);
  if (hp!=0){
    Fighters* fp = dynamic_cast<Fighters*> (qp2);
    if (fp!=0){
      int dmg = hp->getStrength();
      int dmg2 = fp->getStrength();
      fp->takeDamage(dmg);
      hp->takeDamage(dmg2);
      return;
    }
    Dragon* dp = dynamic_cast<Dragon*> (qp2);
    if (dp!=0){
      hp->die();   
      return;
    }
    //determines what stat to increase when an item is found
    Items* ip = dynamic_cast<Items*> (qp2);
    if (ip!=0){
      switch(ip->getType()){
        case 1:
	  hp->addArmour(ip->effect());
	  ip->use();
	  break;
	case 2:
	  hp->addStrength(ip->effect());
	  ip->use();
	  break;
	case 3:
	  hp->addHealth(ip->effect());
	  ip->use();
	  break;
      }
    }

    return;
  }
  
  //Collisions when the first pointer is a Fighter
  Fighters* fp = dynamic_cast<Fighters*> (qp1);
  if (fp!=0){
    Heroes* hp = dynamic_cast<Heroes*> (qp2);
    if (hp!=0){
      int dmg = hp->getStrength();
      int dmg2 = fp->getStrength();
      fp->takeDamage(dmg);
      hp->takeDamage(dmg2);

      return;
    }
    return;
  }
  
  //Collisions when the first pointer is a Dragon
  Dragon* dp = dynamic_cast<Dragon*> (qp1);
  if (dp!=0){
    Heroes* hp = dynamic_cast<Heroes*> (qp2);
    if(hp!=0){
      hp->die();
      return;
    }
    return;
  }

}

//iterates through the list to find any dead fighters
//deallocates their memory and removes them from the game
//also removes items
void Game::removeFighters(){
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
    Fighters* fp = dynamic_cast<Fighters*> (*it);
    if (fp!=0){
      if (fp->getDead()){
        delete(*it);
	it = questerList.erase(it);
	continue;
      }
    }
    Items* ip = dynamic_cast<Items*> (*it);
    if (ip!=0){
      if(ip->getUsed()){
        delete(*it);
	it = questerList.erase(it);
      }
    }
  } 
}

//Checks the win conditions of the game
//Returns true if:
//	A Hero reaches the emerald
//	All Heroes are dead
bool Game::endGame(){
  bool allDead = true;
  bool gotEmerald = false;
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
    //if the QP is a hero, checks if they have reached emerald/died
    Heroes* hp = dynamic_cast<Heroes*> (*it);
    if (hp!=0){
      if (hp->getDead()==false) allDead = false;
      if (hp->getEm()==true){
        winCon += "The winner is ";
        winCon+= hp->getName();
        return true;	
      }
    }
  } 
  if (allDead == true){
    winCon = "The Heroes have fallen";
    return true;
  }
  return false;
}

//updates the contents of the display
void Game::updateBoard(){
  //clears the board
  for (int i=0;i<5;i++){
    for (int k=0;k<25;k++){
      board.coord(i,k) = ' ';
    }
  }
  //inserts all QP at their position
  for(list<QuestPlayers*>::iterator it = questerList.begin();it !=questerList.end();++it){
     board.coord((*it)->getPositionY(),(*it)->getPositionX()) = (*it)->getAvatar();
  }  
}

//Initializes Timmy Harold and the Dragon
void Game::initQuesters(){
  questerList.push_back(new Dragon('D'));
  questerList.push_back(new Heroes("Timmy",'T',15,3,3));
  questerList.push_back(new Heroes("Harold",'H',15,5,1));  
  questerList.push_back(new Shield());
  questerList.push_back(new Sword());
  questerList.push_back(new Potion());
}

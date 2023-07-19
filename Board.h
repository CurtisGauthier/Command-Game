#ifndef BOARD_H
#define BOARD_H

#include <string>

//template class that prints a 5x25 grid of objects

template <class T>
class Board{
  public:
    Board();
    ~Board();
    void print();
    T& coord(int,int);
  private:
    T** elements;  

};

//constructor
template <class T>
Board<T>::Board(){
  elements = new T*[5];
  for (int i = 0;i<5;i++){
    elements[i] = new T[26];
  }
}

//destructor
template <class T>
Board<T>::~Board(){
  for (int i = 0;i<5;i++){
    delete [] elements[i];
  }
  delete [] elements;
}

//returns a pointer to a set of coordinates on the grid
template <class T>
T& Board<T>::coord(int a, int b){
    return elements[a][b];
}

//prints the grid with a border around it
template <class T>
void Board<T>::print(){
  cout << "|";
  for (int i =0;i<25;i++){cout << "-";}
  cout << "|" << endl;
  for (int i = 0;i<5;i++){
    cout << "|";
    for (int k = 0; k<25;k++){
      cout << elements[i][k];   
    }
    if(i==1 || i==3){
      cout << "=" <<endl;
    }else if(i==2){
      cout << "= *" << endl;
    }else{
      cout << "|" << endl;
    }  
  }
  cout << "|";
  for (int i = 0;i<25;i++) {cout << "-";}
  cout << "|" << endl;
}


#endif

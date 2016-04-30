#ifndef DEFAULT_MAP_H
#define DEFAULT_MAP_H

#include <iostream>
#include <cstdlib>
// #include "ObjectBase.h"
#include "Obj.h"

#define DEFAULT_ROWS 32
#define DEFAULT_COLS 100
using namespace std;

class DefaultMap {
  
  private:
    unsigned m_rows; //m shows it is a member variable
    unsigned m_cols;
    char ** arr;
  
  public: 
    DefaultMap(); 
    DefaultMap(unsigned, unsigned);
    void DisplayMap();
    void ChangeSize(unsigned, unsigned);
    void drawMap(Obj);
    void resetSpot(int x, int y);
  
    
};

#endif
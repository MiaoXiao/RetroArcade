#include "DefaultMap.h" 
#include "ObjectBase.h"
// #include "Obj.h"

DefaultMap::DefaultMap() {
    
    *this = DefaultMap(DEFAULT_ROWS, DEFAULT_COLS);
}

DefaultMap::DefaultMap(unsigned rows, unsigned cols) {
    m_rows = rows; 
    m_cols = cols;
    
    arr = (char **) malloc(sizeof(char *)*rows);        //you guys should have used a single array of size rows * cols so that you wouldnt have to do this
    
    for(unsigned i = 0; i < rows; i++) {
        
        arr[i] = (char *) malloc(sizeof(char)*cols);
        
        for(unsigned j= 0; j < cols; j++) {
            arr[i][j] = ' ';
            if(i > 0 && (j == 0 || j == cols - 1)) {
                arr[i][j] = '|';
            }
            else if (i == 0 || i == rows - 1) {
                arr[i][j] = '_';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
    
}
    

void DefaultMap::DisplayMap() {
    for(unsigned i = 0; i < m_rows; i++) {
        for(unsigned j= 0; j < m_cols; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void DefaultMap::ChangeSize(unsigned newRows, unsigned newCols) {
    
    //delete the old array
    for(int i = 0; i < m_rows; ++i){
        delete[] arr[i];
    }
    delete[] arr;
    
    //create the new one through your DefaultMap Constructor
    *this = DefaultMap(newRows, newCols);
}

// Member function for drawing the entire map, whatever is inside of it. 
//By default, the contents of the map should be set to a default character
//such as '.' This default value will mean that there is nothing there at that space.
//3 - Member function for setting the contents of the map. It is probably best 
//to be able to set a single spot in the 2D array, or a row, or column.

void DefaultMap::drawMap(Obj o){
     
     //DisplayMap();

    for (int i = o.getX(); i < o.getX() + o.getWidth(); i++) {
        for (int j = o.getY(); j < o.getY() + o.getHeight(); j++) {
            arr[i][j] = o.getVisual();
            // cout << "\033c";
        }
    }
    
    DisplayMap();
    
 }
 
void DefaultMap::resetSpot(int x, int y) {
// if egg found, clear it
        arr[x][y] = ' ';

}
 

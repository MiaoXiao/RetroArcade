#include <ctime>
#include <iostream>
using namespace std;

#include "ObjectBase.h"

int main(){

    //TIMER!!
    
    double stepTime = 1000.0 / 60.0; //(milliseconds)
    double accumulator = 0.0; 
    double prevTime, elapsedTime, currTime;
    
    //if(){ //EDIT: if game A chosen
        //EDIT: begin game A
        prevTime = (clock() / CLOCKS_PER_SEC) * 1000;
        while((clock() / CLOCKS_PER_SEC) <= 1){ //EDIT: CHANGE ARGUMENT to while game A not over
            currTime = (clock() / CLOCKS_PER_SEC) * 1000;
            elapsedTime = currTime - prevTime; 
            accumulator += elapsedTime; 
            while(accumulator >= stepTime){ 
                //EDIT: check player input
                //EDIT: update game behavior
                //EDIT: update map
                //EDIT: draw the map
                accumulator -= stepTime;
            }
        }
    //}
    
    //END OF TIMER CODE!!
    
    return 0;
}

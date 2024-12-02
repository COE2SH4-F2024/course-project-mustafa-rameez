#include "objPos.h"

objPos::objPos(){
    x=0; y=0; symbol = 0; //objPos intialization
}

objPos::objPos(int xPos, int yPos, char sym){
    x=xPos; y=yPos; symbol=sym; symbol = sym; //base input to dictate paramater of objPoS
}
//Copy ConstructorAdded
objPos::objPos(objPos &o){
    x=o.x; y=o.y; symbol=o.symbol;
}

void objPos::setObjPos(objPos o){
    x=o.x; y=o.y; symbol=o.symbol; //sets objPos paramters
}

void objPos::setObjPos(int xPos, int yPos, char sym){
    x=xPos; y=yPos; symbol=sym; //sets paramater of objPos
}

void objPos::getObjPos(objPos &returnPos){
    returnPos.setObjPos(x,y,symbol);
}

char objPos::getSymbol(){
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos){
    return (refPos->x==x&&refPos->y==y); //if refPos is == to curr objPos
}

char objPos::getSymbolIfPosEqual(const objPos* refPos){
    if(isPosEqual(refPos)){
        return getSymbol();}  //symbol returned 
    else{return 0;}  
}

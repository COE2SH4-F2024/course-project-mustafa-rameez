#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"

GameMechs::GameMechs(){
    input=0; //input control
    score=0; //score
    exitFlag=false; //set exitFlag condition for use later in main loop logic
    loseFlag=false; //case for collision mechanic
    boardSizeX=getBoardSizeX(); //x-board paramter initialization 
    boardSizeY=getBoardSizeY(); //y-board paramter intitialization 
    foodPos.setObjPos(-1,-1,'o'); //food initialization out of X & Y boundary
}

GameMechs::GameMechs(int boardX, int boardY){
    input=0;
    score=0;
    exitFlag=false;
    loseFlag=false;
    boardSizeX=boardX; //input sets x-board size 
    boardSizeY=boardY; //input sets y-board size
}

bool GameMechs::getExitFlagStatus(){   
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

char GameMechs::getInput(){
    if(MacUILib_hasChar()!=0){ //basic check input
        input=MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(){
    score++;
}

int GameMechs::getBoardSizeX(){
    return boardSizeX;
}

int GameMechs::getBoardSizeY(){
    return boardSizeY;
}


void GameMechs::setExitTrue(){
    exitFlag=true; 
}

void GameMechs::setLoseFlag()
{
    loseFlag=true;
}

void GameMechs::setInput(char this_input){
    input=this_input; //stores input
}

void GameMechs::clearInput(){
    input=0; 
}

void GameMechs::genFood(objPosArrayList *playerPosList){
    int count=0;
    int check=0;
    objPos temp_food_pos; //food created with objPos class
    objPos tempBody; //tempbody 
    srand(time(NULL)); //seed randomization
    getFoodPos(temp_food_pos);
    while(count<1){
        check=0;
        int xcoor=rand()%(boardSizeX-1)+1; //generate xcoor within xbound
        int ycoor=rand()%(boardSizeY-1)+1; //generate  ycoor within xbound
        for(int k=0;k<playerPosList->getSize();k++){
            playerPosList->getElement(tempBody,k);
            if(tempBody.x==xcoor&&tempBody.y==ycoor){
                check=1;}//check xcoor and ycoor of body 
            if(xcoor!=tempBody.x&&ycoor!=tempBody.y&&check==0){
                foodPos.setObjPos(xcoor,ycoor,'o');//sets foodPos on board
                count++;}}}
}

void GameMechs::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x,foodPos.y,'o'); //returns food paramater
}
#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
//classes
GameMechs* myGM;
Player* myPlayer;
objPos tempPos;
objPos temp_food_pos;
objPosArrayList* PlayerBody;
objPos tempBody;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void){
    Initialize();
    while(myGM->getExitFlagStatus()==false)  {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}

void Initialize(void){
    MacUILib_init();
    MacUILib_clearScreen();
    myGM= new GameMechs(30,15); 
    myPlayer=new Player(myGM);
    myGM->genFood(myPlayer->getPlayerPos());
}

void GetInput(void){
    myGM->getInput();
    if(myGM->getInput()==32){//Exit if SpaceBar entered
        myGM->setExitTrue();
    }
   
}

void RunLogic(void){
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer(); 
    if(myPlayer->checkFoodConsumption()){
        myPlayer->increasePlayerLength();
        myGM->incrementScore();
        myGM->genFood(myPlayer->getPlayerPos());
    }
    myPlayer->checkSelfCollision(); 
}

void DrawScreen(void){
    MacUILib_clearScreen();   
    bool drawn; //intialization of of flag if board drawn
    objPosArrayList* PlayerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    myGM->getFoodPos(temp_food_pos);
    for(int y=0;y<=myGM->getBoardSizeY();y++){
        for(int x=0;x<=myGM->getBoardSizeX();x++){
            drawn = false; //sets if everythingis drawn to false
            for(int k=0;k<PlayerBody->getSize();k++){
                PlayerBody->getElement(tempBody,k);
                if(tempBody.x==x&&tempBody.y==y){
                    MacUILib_printf("%c",tempBody.symbol);
                    drawn=true; //end of player being drawn of board
                    break;}}
            if(drawn) continue; //ensure player made first then basic draw routine for rest of board
            if(x==temp_food_pos.x&&y==temp_food_pos.y){
                MacUILib_printf("%c",temp_food_pos.symbol);}
            else if(y==myGM->getBoardSizeY()||y==0){
                MacUILib_printf("%c",'#');}
            else if(x==0&&y>0){
                MacUILib_printf("%c",'#');}
            else if(x==myGM->getBoardSizeX()){
                MacUILib_printf("%c",'#');
                MacUILib_printf("\n");}
            else if(x>0){
                MacUILib_printf("%c",' ');}}
        if(y==0){
            MacUILib_printf("%c",'\n');}}
    //print score
    MacUILib_printf("\nScore: %d",myGM->getScore());
}

void LoopDelay(void){
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void){
    MacUILib_clearScreen();    
    delete myGM; 
    delete myPlayer;
    delete PlayerBody;
}

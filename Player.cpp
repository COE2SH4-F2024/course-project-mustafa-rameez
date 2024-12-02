#include "Player.h"

Player::Player(GameMechs* thisGMRef){
    mainGameMechsRef=thisGMRef;
    myDir=STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*'); //intializaes head in middle of board
    playerPosList=new objPosArrayList();//creates array for playerPos
    playerPosList->insertHead(tempPos);
}
//destructor
Player::~Player(){
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos(){
    return playerPosList;
}
//PPA3 input processing
void Player::updatePlayerDir(){         
        char input=mainGameMechsRef->getInput();
        switch(input){
            case 'w':
                if(myDir==LEFT||myDir==RIGHT||myDir==STOP){
                    myDir=UP;}
                break;
            case 'd':
                if(myDir==UP||myDir==DOWN||myDir==STOP){
                    myDir=RIGHT;}
                break;
            case 'a':
                if(myDir==UP||myDir==DOWN||myDir==STOP){
                    myDir=LEFT;}
                break;
            case 's':
                if(myDir==LEFT||myDir==RIGHT||myDir==STOP){
                    myDir=DOWN;}}
}
//PPA3 Logic Implemented to movePlayer
void Player::movePlayer()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    switch (myDir)
    {
    case UP:
        currHead.y--;
        if(currHead.y==0){
            currHead.y=mainGameMechsRef->getBoardSizeY()-1;}
        break;
    case RIGHT:
        currHead.x++;
        if(currHead.x==mainGameMechsRef->getBoardSizeX()){
            currHead.x=1;}
        break;
    case LEFT:
        currHead.x--;
        if(currHead.x==0){
            currHead.x=mainGameMechsRef->getBoardSizeX()-1;}
        break;
    case DOWN:
        currHead.y++;
        if(currHead.y==mainGameMechsRef->getBoardSizeY()){
            currHead.y=1;}
        break;
    default:
        break;}
    playerPosList->insertHead(currHead);
    playerPosList->removeTail();
}
//check collison with food
bool Player::checkFoodConsumption(){
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    objPos foodPos;
    mainGameMechsRef->getFoodPos(foodPos);
    return(foodPos.isPosEqual(&currHead));
}
//lenght increase
void Player::increasePlayerLength(){
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}

bool Player::checkSelfCollision(){
    //collision logic
    objPos currHead;
    objPos tempBody;
    playerPosList->getHeadElement(currHead);
    for(int i=2;i<playerPosList->getSize();i++){
        playerPosList->getElement(tempBody,i);
        if(tempBody.isPosEqual(&currHead)){
            mainGameMechsRef->setLoseFlag(); //update LoseFlag to end program
            mainGameMechsRef->setExitTrue();}} //update exitFlag to end progeram
}
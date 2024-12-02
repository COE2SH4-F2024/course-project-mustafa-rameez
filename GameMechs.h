#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        objPos foodPos;
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        bool getExitFlagStatus(); 
        void setExitTrue();
        bool getLoseFlagStatus();
        void setLoseFlag();
        char getInput();
        void setInput(char this_input);
        void clearInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();
        void incrementScore();
        
        // More methods should be added here
        void genFood(objPosArrayList *playerPosList);
        void getFoodPos(objPos &returnPos);
};

#endif
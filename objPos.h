#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing

class objPos
{
    public:
        int x;
        int y;      
        char symbol;

        objPos();
        objPos(objPos &o);
        objPos(int xPos, int yPos, char sym);
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        void getObjPos(objPos &returnPos);
        char getSymbol();
        char getSymbolIfPosEqual(const objPos* refPos);

        bool isPosEqual(const objPos* refPos);
};

#endif
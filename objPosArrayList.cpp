#include "objPosArrayList.h"

objPosArrayList::objPosArrayList(){
    aList=new objPos[ARRAY_MAX_CAP]; //creates memory for a objPosArrayList
    listSize=0; //intializtion
    arrayCapacity=ARRAY_MAX_CAP; //ensures cap is not exceed 
}
//destructor
objPosArrayList::~objPosArrayList(){
    delete[] aList; 
}

int objPosArrayList::getSize(){
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos){
    //insert Head Logic
    if(listSize!=0&&listSize!=arrayCapacity){
        for(int i=listSize;i>0;i--){
            aList[i].setObjPos(aList[i-1]);}}
    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos){
    //insert Tail Logic
    if(listSize!=arrayCapacity){
        aList[listSize++].setObjPos(thisPos);}
}

void objPosArrayList::removeHead(){
    //Remove Head Logic
    for(int i=0;i<listSize;i++){
        aList[i].setObjPos(aList[i+1]);}
    listSize--;
}

void objPosArrayList::removeTail(){
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos){
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos){
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos,int index){
    returnPos.setObjPos(aList[index]);
}

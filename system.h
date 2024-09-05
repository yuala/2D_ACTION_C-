#pragma once

const int SCREEN_W = 1920;
const int SCREEN_H = 1080;

class Enemy;
class Player;
class Model;
class Dome;

class System
{
public:

    System();

    int screenH;
    int screenW;

    int gametime;
    int gamecount;
    int best=0;

    float timeY;
    float timeX;
   

    bool isClear;
    bool isReturn = true;

    int tmptime = 0;

    int CrWhite;
    int CrBlack;

    int HoleGraph;

    int timeframeGraph;
    int resultframeGraph;
    int scoreGraph;

    int timer;
    
    void InitScreen();
    void InitTime(bool&gameover);
    void DrawTime();
 
    void DrawResult(bool&title,bool&gameover, Model& model,Dome&dome);
};

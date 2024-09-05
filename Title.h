#pragma once

class System;
class Player;
class Fps;
class Enemy;
class Model;
class Dome;
struct Map;



class Title
{
public:
	int graph=LoadGraph("data/texture/Šª‚«•¨.jpg");
	int sound;
	int mainsound;

	int c = 0;
	int White = GetColor(255, 255, 255);

	void Draw(bool& drawtitle, bool& gameover, System& system, Map& map, Player& player, Fps& fps, Enemy& enemy, Model& model,Dome&dome,int &gametime,int &countdownn,bool &isC);
};

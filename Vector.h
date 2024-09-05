#pragma once

class Player;

typedef struct Vector
{

	float X, Y, Z;
	
}Vector;



//プロトタイプ宣言
void InitializeVec(Vector&vector,Player&player);
//Vector VGet(Vector& vector, Player& player);
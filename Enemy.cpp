#include "DxLib.h"
#include "Enemy.h"
#include"Player.h"
#include"system.h"

// エネミー初期化
void Enemy::Initialize()
{
	
	LoadDivGraph("data/texture/gr_3.png", 24, 24, 1, 120, 120, GraphGrRe);
	GetGraphSize(GraphGrRe[0], &W, &H);
		
	X = ENEMY_X;
		
	Y = 792.0f;

		DrawEmy = 0;
	
	G = START_G;

	Speed = DEFSPEED;

	animtime = 0;
	animRe = 6;


	
}

// エネミー更新
void Enemy::Update(Player&player,System&system,bool&gameover)
{
	
	

	animtime++;

		if (CheckHitKeyAll)
		{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				animRe--;
			}
		}
		if (animRe < 2)
		{
			animRe = 6;
		}



	// エネミーの座標を移動している方向に移動する
	if (X> -100)
	{
			X -= Speed;
		
	}
	else//エネミーが画面外に出たらその座標を画面右端にリセットする
	{
		X= 2000;
		if (system.gamecount < 55)
		{
			Speed = Speed + UPSPEED;
		}
			
			
		
	}

	if (system.gamecount > 40)
	{
				//ジャンプ
		if (Y == START_Y)
		{
			G = JUMPPOWER;
		}

		if (Y > START_Y)
		{
			Y = START_Y;
			G = START_G;
		}

		Y -= G;
		G -= FALLSPEED;


	}
	else
	{
		Y = START_Y;
	}
	

	
	if (hitshot[DrawEmy] == 1)
	{
		X = 2000;
		if(DrawEmy != 50)
		{
			DrawEmy++;
		}
		else
		{
			DrawEmy = 0;
		}
	}
	
	/*
	DrawLine(pos.x+20, pos.y+20, pos.x + W-20, pos.y+20, GetColor(255, 0, 0));//上横
	DrawLine(pos.x+20, pos.y + H-20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//下横
	DrawLine(pos.x+20, pos.y+20, pos.x+20, pos.y + H-20, GetColor(255, 0, 0));//左縦
	DrawLine(pos.x + W-20, pos.y+20, pos.x + W-20, pos.y + H-20, GetColor(255, 0,
	
	
	*/
	

	// プレイヤーとの当たり判定
	if ((player.pos.x + 20 <= X && player.pos.x + W - 20 >= X) && (player.pos.y + 20 <= Y + 20 && player.pos.y + H - 20 >= Y + 20))
	{
		//ヒット判定
		gameover = true;
	}
	if ((player.pos.x + 20 <= X && player.pos.x + W - 20 >= X) && (player.pos.y + 20 >= Y + 20 && player.pos.y + 20 <= Y + H - 20))
	{
		//ヒット判定
		gameover = true;
	}
	if ((player.pos.x + 20 >= X && player.pos.x + 20 <= X + W - 20) && (player.pos.y + 20 <= Y + 20 && player.pos.y + H - 20 >= Y + 20))
	{
		//ヒット判定
		gameover = true;
	}
	if ((player.pos.x + 20 >= X && player.pos.x + 20 <= X + W - 20) && (player.pos.y + 20 >= Y + 20 && player.pos.y + 20 <= Y + H - 20))
	{
		//ヒット判定
		gameover = true;
	}

	
}

// エネミー描画
void Enemy::Draw(System&system)
{
	
	DrawLine(X, Y + 20, X + W - 20, Y + 20, GetColor(255, 0, 0));//上横
	DrawLine(X, Y + H - 20, X + W - 20, Y + H - 20, GetColor(255, 0, 0));//下横
	DrawLine(X, Y + 20, X, Y + H - 20, GetColor(255, 0, 0));//左縦
	DrawLine(X + W - 20, Y + 20, X + W - 20, Y + H - 20, GetColor(255, 0, 0));//右縦

	/*
	SetFontSize(70);
	DrawFormatString(400, 400, GetColor(255, 100, 100), "エネミー\n上：%d\n下：%d\n右：%d\n左：%d", Y + 20, Y + H - 20, X + W - 20, X);
	SetFontSize(-1);
	*/
	

	if (system.gamecount > 20&& system.gamecount < 40 || system.gamecount > 70)
	{
		if (X>1500&&X<1700||X>700&&X<900)
		{
			
		}
		else
		{
			// エネミーを描画
			DrawGraph(X, Y, GraphGrRe[animRe], TRUE);

		}
	}
	else
	{
		// エネミーを描画
		DrawGraph(X, Y, GraphGrRe[animRe], TRUE);
		
	}
	
}

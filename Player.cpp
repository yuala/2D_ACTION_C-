#include "DxLib.h"
#include "Player.h"
#include"Vector.h"
#include"system.h"


// プレイヤー初期化
void Player::Initialize()
{
	// プレイヤーのグラフィックをメモリにロード＆表示座標を初期化
	LoadDivGraph("data/texture/red_4.png", 24, 24, 1, 120, 120, Graph);
	LoadDivGraph("data/texture/red_8_re.png", 24, 24, 1, 120, 120, GraphRE);
	LoadDivGraph("data/texture/gr_3.png", 24, 24, 1, 120, 120, GraphGrRe);
	
	jumpsound = LoadSoundMem("data/sound/se05.wav");

	G = START_G;
	anim = 5;
	animtime = 0;
	pos = VGet(START_X, START_Y, 0);
	GrX = 2200;
	GrY = 792;
	HitEmy = 0;
	animRe = 6;
	isMove = true;

	// ショットボタンが前のフレームで押されたかどうかを保存する変数にfalse(押されいない)を代入
	PrevShotFlag = false;

	// プレイヤーと弾の画像のサイズを得る
	GetGraphSize(Graph[anim], &W, &H);
}

// プレイヤーの更新処理
void Player::Update()
{
	
		animtime++;
		if (CheckHitKeyAll&& pos.y == START_Y)
		{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				anim++;
			}
		}
		if (anim > 8)
		{
			anim = 3;
		}
	



	// 矢印キーを押していたらプレイヤーを移動させる
	if (CheckHitKey(KEY_INPUT_SPACE)&&pos.y== START_Y)
	{
		PlaySoundMem(jumpsound, DX_PLAYTYPE_BACK);
		G = JUMPPOWER+3.0f;
	}
	
	if (pos.y > START_Y)
	{
		pos.y = START_Y;
		G = START_G;
	}
	
	pos.y -= G;
	G -= FALLSPEED;

	

	

	// プレイヤーが画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
	if (pos.x < 0)
	{
		pos.x = 0;
	}
	if (pos.x > 1920 - W)
	{
		pos.x = 1920 - W;
	}
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	if (pos.y >START_Y)
	{
		pos.y = START_Y;
	}
}

// プレイヤーの描画処理
void Player::Draw()
{
	// プレイヤーを描画
	/*
	SetFontSize(70);
	DrawFormatString(100, 400, GetColor(255, 100, 100), "プレイヤー\n上：%.0f\n下：%.0f\n右：%.0f\n左：%.0f", pos.y + 20, pos.y + H - 20, pos.x + W - 20, pos.x + 20);
	SetFontSize(-1);
	*/
	

		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);

	DrawLine(pos.x+20, pos.y+20, pos.x + W-20, pos.y+20, GetColor(255, 0, 0));//上横
	DrawLine(pos.x+20, pos.y + H-20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//下横
	DrawLine(pos.x+20, pos.y+20, pos.x+20, pos.y + H-20, GetColor(255, 0, 0));//左縦
	DrawLine(pos.x + W-20, pos.y+20, pos.x + W-20, pos.y + H-20, GetColor(255, 0, 0));//右縦
		
	if (HitEmy ==1)
	{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//以下に記述されるDraw関数のブレンドを変更する
			DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);//下記に記述されるDraw関数のブレンドをノーマルに変更する。
			HitEmy = 0;

	}
}


void Player::Drawtitle()
{
	// プレイヤーを描画
	



	if (isMove == true)
		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
	else if (isMove == false)
	{
		DrawGraph(pos.x, pos.y, GraphRE[animRe], TRUE);
		DrawGraph(GrX, GrY, GraphGrRe[animRe], TRUE);
	}

	if (HitEmy == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//以下に記述されるDraw関数のブレンドを変更する
		DrawGraph(pos.x, pos.y, Graph[anim], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);//下記に記述されるDraw関数のブレンドをノーマルに変更する。
		HitEmy = 0;

	}
}

// プレイヤーの更新処理
void Player::UpdateTitle()
{

	


	animtime++;
	if (isMove == true)
	{
		
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				anim++;
			}
			
		if (anim > 8)
		{
			anim = 3;
		}
	}
	else if (isMove == false)
	{
			if (animtime >= ANIMSPEED)
			{
				animtime = 0;
				animRe--;
			}
		if (animRe<2)
		{
			animRe = 6;
		}
	}

	// 矢印キーを押していたらプレイヤーを移動させる
	if (CheckHitKey(KEY_INPUT_SPACE) && pos.y == START_Y)
	{
		G = JUMPPOWER;
		PlaySoundMem(jumpsound, DX_PLAYTYPE_BACK);
	}

	if (pos.y > START_Y)
	{
		pos.y = START_Y;
		G = START_G;
	}

	pos.y -= G;
	G -= FALLSPEED;





	// プレイヤーが画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	if (pos.y > START_Y)
	{
		pos.y = START_Y;
	}


	if (isMove == true)
	{
		pos.x += 5;
	}
	else if (isMove == false)
	{
		pos.x -= 7;
		GrX -= 7;

	}
		

	if (pos.x > 2000)
	{
		isMove = false;
		GrX = 2200;
	}
	else if (GrX < -200)
		isMove = true;
	
}

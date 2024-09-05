#pragma once

//定数
const float JUMPPOWER = 22.0f;
const float START_X = 400.0f;
const float START_Y = 792.0f;
const float START_G = 0.0f;
const float FALLSPEED = 0.8f;
const float ANIMSPEED = 7;



// プロトタイプ宣言
class Shot;
class System;

// プレイヤー構造体.
class Player
{
public:
	int Graph[16];
	int GraphRE[16];
	int GraphGrRe[16];
	float GrX;
	float GrY;
	int animRe;
	int W;
	int H;
	float G;
	bool PrevShotFlag;

	int jumpsound;

	int anim;
	int animtime;
	bool HitEmy;
	bool isMove = true;

	VECTOR pos;//ポジション


	void Initialize();									// プレイヤー初期化
	void Update();	// プレイヤーの更新処理
	void Draw();										// プレイヤーの描画処理		
	void Drawtitle();										// プレイヤーの描画処理
	void UpdateTitle();	// タイトル画面のプレイヤーの更新処理

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; };

	void SetPos(const VECTOR set) { pos = set; };

};





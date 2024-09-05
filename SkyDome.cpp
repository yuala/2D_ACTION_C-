//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "SkyDome.h"
#include"system.h"



//初期化
void Dome::Init()
{
// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/ChickenModel/Dome_X501.pmx");

	//pos = VGet(0, 0, 0);
	pos = VGet(960, 520, -820);
	ang = 0;
	num = 0;
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, ang * DX_PI_F / 180.0f, 0.0f));//モデルの回転
}


//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Dome::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	
	/*
		// 上を押していたら上に進む
	if (Key & PAD_INPUT_UP)
	{
		pos.z += 1;
	}
	// 下を押していたら下に進む
	if (Key & PAD_INPUT_DOWN)
	{
		pos.z -= 1;
	}
	

	

	// 右を押していたら右に進む
	if (Key & PAD_INPUT_RIGHT)
	{
		pos.x += 1;
	}

	// 左を押していたら左に進む
	if (Key & PAD_INPUT_LEFT)
	{
		
	}
	
	pos.x -= 0.5;
	if (pos.x < 820)
	{
		pos.x = 1100;
	}
	
	*/

	MV1SetRotationXYZ(modelHandle, VGet(0.0f,ang * DX_PI_F / 180.0f, 0.0f));//モデルの回転
	
	if (ang >= 360)
	{
		ang = 0;
	}
	ang+=0.1;
	
	
	

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Dome::Draw()
{
	SetFontSize(100);
	//DrawFormatString(50, 50, GetColor(255, 255, 255), "X座標：%f\nY座標：%f\nZ座標：%f",pos.x,pos.y, pos.z);
	SetFontSize(-1);
	//MV1SetScale(modelHandle, VGet(4.0f, 4.0f, 4.0f));
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
	SetUseLighting(TRUE);
	SetUseZBuffer3D(FALSE);
}
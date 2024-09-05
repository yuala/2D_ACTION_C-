#pragma once

#include "DxLib.h"

class System;

class Dome final
{
public:
	
	int num;
	float ang;

	void Init();//初期化
	void Update();			// 更新.
	void Draw();			// 描画.


	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	int		modelHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.

};

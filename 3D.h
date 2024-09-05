#pragma once

#include "DxLib.h"

class System;

class Model final
{
public:

	int num;
	float ang;
	float size;
	bool isSize;
	float move;
	bool isMove;

	void Init();//初期化
	void Update(System& system);			// 更新.
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

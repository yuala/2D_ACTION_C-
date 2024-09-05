#include "DxLib.h"
#include "Enemy.h"
#include "Shot.h"
#include"Player.h"
#include"System.h"

// ショット初期化
void Shot:: Initialize(int shotGraph)
{
	// ショットのグラフィックをメモリにロード.
	Graph = shotGraph;

	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味するfalseを代入しておく
	visibleFlag = false;

	// 弾のグラフィックのサイズをえる
	GetGraphSize(Graph, &W, &H);
}

// ショット更新
void Shot::Update(Enemy& enemy)
{
	// 弾のあたり判定.
	// 弾iが存在している場合のみ次の処理に映る
	if (visibleFlag == 1)
	{
		// エネミーとの当たり判定
		if (((X > enemy.X[enemy.DrawEmy] && X < enemy.X[enemy.DrawEmy] + enemy.W[enemy.DrawEmy]) ||
			(enemy.X[enemy.DrawEmy] > X && enemy.X[enemy.DrawEmy] < X + W)) &&
			((Y > enemy.Y[enemy.DrawEmy] && Y < enemy.Y[enemy.DrawEmy] + enemy.H[enemy.DrawEmy]) ||
				(enemy.Y[enemy.DrawEmy] > Y && enemy.Y[enemy.DrawEmy] < Y + H)))
		{
			// 接触している場合は当たった弾の存在を消す
			visibleFlag = 0;

			// エネミーの顔を歪めているかどうかを保持する変数に『歪めている』を表すTRUEを代入
			enemy.DamageFlag[enemy.DrawEmy] = true;
			// エネミーの顔を歪めている時間を測るカウンタ変数に０を代入
			enemy.DamageCounter[enemy.DrawEmy] = 0;
			enemy.hitshot[enemy.DrawEmy] = 1;
			
		}
	}
}

// ショット描画
void Shot::Draw()
{
	// 自機の弾iの移動ルーチン( 存在状態を保持している変数の内容がtrue(存在する)の場合のみ行う )
	if (visibleFlag == true)
	{
		// 弾iを１６ドット右に移動させる
		X += 16;

		// 画面外に出てしまった場合は存在状態を保持している変数にfalse(存在しない)を代入する
		if (X > SCREEN_W)
		{
			visibleFlag = false;
		}

		// 画面に弾iを描画する
		DrawGraph(X, Y, Graph, TRUE);
	}
}
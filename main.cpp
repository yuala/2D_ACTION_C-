//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include"DxLib.h"
#include"Enemy.h"
#include"Player.h"
#include"system.h"
#include"Vector.h"
#include"SkyDome.h"
#include"3D.h"
#include"Fps.h"
#include"map.h"
#include"Title.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------

// WinMain関数
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeFont("ほにゃ字Re");
	//変数
	bool drawtitle = true;
	bool gameover = false;

	int gametime = GetNowCount();
	int countdown = ((GetNowCount() - gametime) / 1000);
	bool ready;
	bool isC = true;

	

	if (countdown >= 3)
	{
		ready = false;
	}
	else
	{
		ready = true;
	}

	

	System* system = new System();
	//Vector vector;
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Dome* dome = new Dome();
	Model* model = new Model();
	Fps* fps = new Fps();
	Map* map = new Map();
	Title* title = new Title();

	system->InitScreen();
	fps->Initialize();//fps設定の初期化

	// 画面モードの設定
	SetGraphMode(1920, 1080, 16);		// 解像度を640*480、colorを16bitに設定.
	ChangeWindowMode(FALSE);			// ウインドウモードを変更(FALSE＝フルクリーン)

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);



	// ゲームループ.
	while (1)
	{
		

		fps->Update();
		


		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();
		title->Draw(drawtitle, gameover, *system, *map, *player, *fps, *enemy, *model,*dome, gametime,countdown,isC);



		if (countdown<=2)
		{
			if (isC == true)
			{
				gametime = GetNowCount();
				isC = false;
			}

			countdown = ((GetNowCount() - gametime) / 1000);
			dome->Update();
			//model->Update(*system);
			player->Update();

			fps->Wait();
			dome->Draw();
			model->Draw();
			DrawMap(*map);
			player->Draw();	// プレイヤーを描画する
			SetFontSize(120);
			DrawBox(890, 260, 1040, 400, GetColor(112, 76, 56), TRUE);
			DrawBox(900, 270, 1030, 390, GetColor(226, 214, 207), TRUE);
			DrawFormatString(930, 275, GetColor(10, 10, 10), "%d", 3-countdown);
			SetFontSize(-1);
			// 裏画面の内容を表画面にコピーする（描画の確定）.
			ScreenFlip();
			if (countdown >=2.8)
			{
				system->InitTime(gameover);
			}
		}
		else if (countdown >=2)
		{

			//------------------------------//
			// プレイヤー、エネミールーチン
			//------------------------------//
			dome->Update();
			model->Update(*system);
			enemy->Update(*player, *system, gameover);
			player->Update();


			dome->Draw();
			model->Draw();
			DrawMap(*map);
			player->Draw();	// プレイヤーを描画する
			enemy->Draw(*system);//エネミーを描画



			//fps->Draw();
			fps->Wait();

			system->DrawTime();


			//クリア演出
			system->DrawResult(drawtitle, gameover, *model, *dome);


			if (CheckSoundMem(title->mainsound) == 1&&drawtitle==true)
			{
				StopSoundMem(title->mainsound);
				model->Init();
			}


			// 裏画面の内容を表画面にコピーする（描画の確定）.
			ScreenFlip();
		}
		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0)
		{
			
			DxLib_End();				// ＤＸライブラリ使用の終了処理
			return 0;					// ソフトの終了
			break;
		}
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			


			DxLib_End();				// ＤＸライブラリ使用の終了処理
			return 0;					// ソフトの終了
			break;
		}
	}

	ChangeFont("-1");

	delete(system);
	delete(player);
	delete(enemy);
	delete(dome);
	delete(model);
	delete(fps);
	delete(map);
	delete(title);

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;					// ソフトの終了
}

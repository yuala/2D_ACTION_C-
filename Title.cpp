#include"DxLib.h"
#include"Title.h"
#include"Fps.h"
#include"Player.h"
#include"Enemy.h"
#include"SkyDome.h"
#include"3D.h"
#include"system.h"
#include"map.h"

void Title::Draw(bool& drawtitle, bool& gameover, System& system, Map& map, Player& player, Fps& fps, Enemy& enemy, Model& model,Dome&dome,int &gametime,int &countdown,bool& isC)
{
	if (drawtitle == true && system.isReturn == true)
		{
		int selectFrame = 100;
		int i = 0;
		mainsound = LoadSoundMem("data/sound/main1.mp3");
		sound = LoadSoundMem("data/sound/title1.mp3");
		InitMap(map);//マップの初期化
		player.Initialize();	//プレイヤー初期化
		enemy.Initialize();		//エネミー初期化
		dome.Init();
		model.Init();//3dモデルの初期化

		gametime = GetNowCount();
		countdown = ((GetNowCount() - gametime) / 1000);
		isC = true;
		bool checkreturn = 0;
 




		
		if (CheckSoundMem(sound) == 0)
		{
			
			PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
		}
		
		while (1)
		{
			


			if (checkreturn == 1)
			{

				//ClearDrawScreen();                   // 裏画面のデータを全て削除

				//if (c >= 0 && c < 256)                    //cが0~256の時
					//SetDrawBright(c, c, c);        //段々あかるく(c= 0->255)
				//if (c >= 256 && c < 400)                  //cが256~400の時
					//SetDrawBright(255, 255, 255);  //通常の明るさ
				//if (c >= 400 && c < 400 + 256)              //cが400~400+256の時
				SetDrawBright(255 - c, 255 - c, 255 - c);//段々暗く(c= 255->0)

				DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), FALSE);  //画面全体に白い四角形を描画

				c += 5;;                                  //cをカウントアップ

				if (c > 256)
				{
					drawtitle = false;
					player.Initialize();	// プレイヤー初期化
					//enemy.Initialize();		//エネミー初期化
					system.InitTime(gameover);//systemの初期化
					model.Init();//3dモデルの初期化


					if (CheckSoundMem(sound) == 1)
					{
						StopSoundMem(sound);
						PlaySoundMem(mainsound, DX_PLAYTYPE_LOOP);
					}
					break;                 //暗くなり終わったら終了
				}
				ScreenFlip();
			}
			
			i++;
	
			if (i == 10)
			{
				selectFrame -= 1;
			}
			else if (i > 10)
			{
				i = 0;
			}
	
			if (selectFrame < 0)
			{
				selectFrame = 100;
			}
	
	
			ClearDrawScreen();
	
			fps.Update();
			fps.Wait();
			
			dome.Update();
			//model.Update(system);
			player.UpdateTitle();	// プレイヤーを更新する
			
			dome.Draw();
			model.Draw();
			DrawMap(map);
			
			



			SetFontSize(100);
			DrawFormatString(580, 170, GetColor(200, 30, 30), "どらごんらんなー", TRUE);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawBox(500, 320, 1420, 800, GetColor(112, 76, 56), TRUE);
			DrawBox(520, 340, 1400, 780, GetColor(226, 214, 207), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
			SetFontSize(60);
			DrawFormatString(550, 360, GetColor(0, 0, 0), "[ルール説明]\n\nジャンプ：スペースキー\n制限時間：90秒", TRUE);
			SetFontSize(40);
			DrawFormatString(560, 500, GetColor(0, 0, 0), "\n\n\n画面の右から襲い掛かるグリーンドラゴンを\nジャンプで避けて高スコア獲得を目指そう");
			
			player.Drawtitle();	// プレイヤーを描画する
			
			DrawGraph(0, 200, graph, TRUE);
			if ((selectFrame / 5) % 2 == 0)
			{
				SetFontSize(25);
				DrawFormatString(790, 860, GetColor(255, 255, 255), "エンターキーをおしてください", TRUE);
			}
			SetFontSize(-1);
	
	
			
			
	
	
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				checkreturn = 1;


				
			}
			else if (ProcessMessage() < 0)
			{
				DxLib_End();
				return;
				
			}
			// もしＥＳＣキーが押されていたらループから抜ける
			else if (CheckHitKey(KEY_INPUT_ESCAPE))
			{
				DxLib_End();
				return;
				

			}


			ScreenFlip();

	
		}
		
	
	}
}
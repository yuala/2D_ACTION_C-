#pragma once

class Fps
{
public:
	int mStartTime;      //測定開始時刻
	int mCount;          //カウンタ
	float mFps;          //fps
	const int N = 60;  //平均を取るサンプル数
	const int FPS = 60;  //設定したFPS

	void Initialize();
	bool Update();
	void Draw();
	void Wait();
};

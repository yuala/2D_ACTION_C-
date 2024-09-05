#include <math.h>
#include "DxLib.h"
#include "Fps.h"

//初期化
void Fps::Initialize() {
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}
//FPS制御
bool Fps::Update() {
    if (mCount == 0) { //1フレーム目なら時刻を記憶
        mStartTime = GetNowCount();
    }
    if (mCount == N) { //30フレーム目なら平均を計算する
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}
//FPS表示
void Fps::Draw()
{
    SetFontSize(20);
    DrawFormatString(1830, 10, GetColor(255, 255, 255), "FPS:%.0f", mFps);
    SetFontSize(-1);
}
void Fps::Wait() {
    int tookTime = GetNowCount() - mStartTime;  //かかった時間
    int waitTime = mCount * 1000 / FPS - tookTime;  //待つべき時間
    if (waitTime > 0) {
        Sleep(waitTime);  //待機
    }
}
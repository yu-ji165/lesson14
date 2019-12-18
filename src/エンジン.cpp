#include "エンジン.h"
#include "DxLib.h"

ゲームエンジン::ゲームエンジン()
{
}

ゲームエンジン::~ゲームエンジン()
{
}

int ゲームエンジン::初期化()
{
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(540, 960, 32);
	if (DxLib_Init() == -1) { return -1; }	// DXライブラリ初期化(エラーで終了)

	return 0; 
}

int ゲームエンジン::片付け()
{
	DxLib_End(); // DXライブラリの終了処理

	return 0;
}

int ゲームエンジン::更新()
{
	int 終わり？ = 0;

	// 時間更新処理
	LONGLONG μ時間 = GetNowHiPerformanceCount();
	LONGLONG 経過μ時間 = μ時間 - 前フレームのμ時刻_;
	if (1000000 < 経過μ時間) 経過μ時間 = 1000000;// 一秒の上限を入れる
	float 経過時間 =  0.000001f * static_cast<float>(経過μ時間);
	前フレームのμ時刻_ = μ時間;

	// いろいろなオブジェクトの更新処理
	// ...

	// 描画
	ClearDrawScreen();//裏画面消す
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

	// いろいろなオブジェクトの描画処理
	// ...::更新(経過時間);

	ScreenFlip();//裏画面を表画面にコピー

	return 終わり？;
}

int ゲームエンジン::実行() 
{
	int 返り値 = 0;

	返り値 = 初期化();
	if (返り値 != 0) return 返り値;

	// メインループ
	while (ProcessMessage() == 0)
	{
		if (更新() != 0) break;// 返り値の値で抜ける
	}

	返り値 = 片付け();

	return 返り値;
}

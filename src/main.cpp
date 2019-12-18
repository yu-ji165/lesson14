// メモリリークチェックコード
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// メモリリークチェックコード

#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// メモリリークチェックコード
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// メモリリークチェックコード

	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(540, 960, 32);
	if (DxLib_Init() == -1) { return -1; }	// DXライブラリ初期化(エラーで終了)

	// メインループ
	while (ProcessMessage() == 0)
	{
		// 描画
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		// 何かあるなら描画

		ScreenFlip();//裏画面を表画面にコピー
	}


	return 0;				// ソフトの終了 
}

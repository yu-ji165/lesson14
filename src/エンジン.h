#pragma once
#include "DxLib.h"

// クラス宣言
class ゲームエンジン
{
private:
	LONGLONG 前フレームのμ時刻_ = 0;

	int 初期化();
	int 更新();
	int 片付け();

public:
	ゲームエンジン();
	~ゲームエンジン();

	int 実行();
};

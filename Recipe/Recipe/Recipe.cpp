// Recipe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

void suspendCommandLine()
{
	char dummy[256];
	gets_s(dummy);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// wprintfで出力するための設定
	char *loc = setlocale(LC_ALL, "");

	// レシピデータの生成
	std::wstring recipeTitle(_T("オムライス"));

	// レシピの出力
	_tprintf(recipeTitle.c_str());


	suspendCommandLine();
	return 0;
}


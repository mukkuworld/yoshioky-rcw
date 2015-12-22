// Recipe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "RecipeData.h"

void suspendCommandLine()
{
	char dummy[256];
	gets_s(dummy);
}

/**
 * @brief	実行ファイルのディレクトリパスを取得します。
 * @retval	true	取得成功
 * @retval	false	取得失敗
 */
bool getDataFilePath(
	std::wstring& result	//!< [out]	結果の格納先
	)
{
	// 実行ファイルの完全パスを取得
	wchar_t exePath[MAX_PATH + 1];
	if( FALSE == ::GetModuleFileName( nullptr, exePath, MAX_PATH ) ){
		return false;
	}

	// パス名を構成要素に分解します
	wchar_t drive[MAX_PATH + 1];	// ドライブ名。			例「C:」
	wchar_t dir  [MAX_PATH + 1];	// ディレクトリパス。	例「\hoge\foo\」
	wchar_t fname[MAX_PATH + 1];	// ファイル名。			例「Recipe」
	wchar_t ext  [MAX_PATH + 1];	// ファイル拡張子。		例「.exe」
	::_wsplitpath_s( exePath, drive, dir, fname, ext );

	result.append( drive );
	result.append( dir );
	result.append( L"recipe-data.txt" );
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// wprintfで出力するための設定
	char *loc = setlocale(LC_ALL, "");

	// レシピデータの生成
	// RecipeDataを生成する方式に切り替えてください
	std::wstring dataFilePath;
	if( !getDataFilePath( dataFilePath ) ){
		return 1;
	}

	RecipeData data( dataFilePath );
	//std::wstring recipeTitle(_T("オムライス"));

	// レシピの出力
	const int lineSize = data.getTitles().size();
	for( int i = 0; i < lineSize; ++i ){
		if( !data.getTitles().at(i).empty() ){
			wprintf( &data.getTitles().at(i).at(0) );
		}
	}

	suspendCommandLine();
	return 0;
}


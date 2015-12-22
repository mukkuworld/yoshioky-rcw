// Recipe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "RecipeData.h"

RecipeData::RecipeData(const std::wstring& filePath)
{
	buildTitlesFromFile(filePath);
}

void RecipeData::buildTitlesFromFile(const std::wstring& filePath)
{
	m_titles.clear();
	m_titles.shrink_to_fit();

	std::ifstream ifs(filePath);

	// 実装途中です。すみません
	// ファイルから読み込む部分を作成してください

	return ;
}


const StringVector& RecipeData::getTitles() const
{
	return m_titles;
}
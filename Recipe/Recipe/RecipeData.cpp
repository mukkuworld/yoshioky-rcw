// Recipe.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "RecipeData.h"

RecipeData::RecipeData(const std::wstring& filePath)
: m_filePath( filePath )
{
	buildTitlesFromFile(filePath);
}

void RecipeData::buildTitlesFromFile(const std::wstring& filePath)
{
	m_titles.clear();
	m_titles.shrink_to_fit();

	// 実装途中です。すみません
	// ファイルから読み込む部分を作成してください

	std::wifstream ifs(filePath);
	if( ifs ){
		std::wstring tmpStr;
		while( !ifs.eof() ){
			tmpStr.clear();
			std::getline( ifs, tmpStr );
			this->m_titles.push_back( tmpStr );
		}
	}else{
		this->m_titles.push_back( std::wstring( L"オムライス" ) );
	}

	return;
}


const StringVector& RecipeData::getTitles() const
{
	return m_titles;
}

void RecipeData::save()
{
	// 書き出し
	std::wofstream outf( this->m_filePath );
	const int lineSize = this->m_titles.size();
	for( int i = 0; i < lineSize; ++i ){
		outf << this->m_titles[i] << std::endl;
	}
}

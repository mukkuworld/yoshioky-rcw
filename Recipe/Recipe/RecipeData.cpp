// Recipe.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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

	// �����r���ł��B���݂܂���
	// �t�@�C������ǂݍ��ޕ������쐬���Ă�������

	std::wifstream ifs(filePath);
	if( ifs ){
		std::wstring tmpStr;
		while( !ifs.eof() ){
			tmpStr.clear();
			std::getline( ifs, tmpStr );
			this->m_titles.push_back( tmpStr );
		}
	}else{
		this->m_titles.push_back( std::wstring( L"�I�����C�X" ) );
	}

	return;
}


const StringVector& RecipeData::getTitles() const
{
	return m_titles;
}

void RecipeData::save()
{
	// �����o��
	std::wofstream outf( this->m_filePath );
	const int lineSize = this->m_titles.size();
	for( int i = 0; i < lineSize; ++i ){
		outf << this->m_titles[i] << std::endl;
	}
}

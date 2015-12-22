// Recipe.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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

	// �����r���ł��B���݂܂���
	// �t�@�C������ǂݍ��ޕ������쐬���Ă�������

	return ;
}


const StringVector& RecipeData::getTitles() const
{
	return m_titles;
}
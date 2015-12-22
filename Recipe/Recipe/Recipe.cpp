// Recipe.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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
 * @brief	���s�t�@�C���̃f�B���N�g���p�X���擾���܂��B
 * @retval	true	�擾����
 * @retval	false	�擾���s
 */
bool getDataFilePath(
	std::wstring& result	//!< [out]	���ʂ̊i�[��
	)
{
	// ���s�t�@�C���̊��S�p�X���擾
	wchar_t exePath[MAX_PATH + 1];
	if( FALSE == ::GetModuleFileName( nullptr, exePath, MAX_PATH ) ){
		return false;
	}

	// �p�X�����\���v�f�ɕ������܂�
	wchar_t drive[MAX_PATH + 1];	// �h���C�u���B			��uC:�v
	wchar_t dir  [MAX_PATH + 1];	// �f�B���N�g���p�X�B	��u\hoge\foo\�v
	wchar_t fname[MAX_PATH + 1];	// �t�@�C�����B			��uRecipe�v
	wchar_t ext  [MAX_PATH + 1];	// �t�@�C���g���q�B		��u.exe�v
	::_wsplitpath_s( exePath, drive, dir, fname, ext );

	result.append( drive );
	result.append( dir );
	result.append( L"recipe-data.txt" );
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// wprintf�ŏo�͂��邽�߂̐ݒ�
	char *loc = setlocale(LC_ALL, "");

	// ���V�s�f�[�^�̐���
	// RecipeData�𐶐���������ɐ؂�ւ��Ă�������
	std::wstring dataFilePath;
	if( !getDataFilePath( dataFilePath ) ){
		return 1;
	}

	RecipeData data( dataFilePath );
	//std::wstring recipeTitle(_T("�I�����C�X"));

	// ���V�s�̏o��
	const int lineSize = data.getTitles().size();
	for( int i = 0; i < lineSize; ++i ){
		if( !data.getTitles().at(i).empty() ){
			wprintf( &data.getTitles().at(i).at(0) );
		}
	}

	suspendCommandLine();
	return 0;
}


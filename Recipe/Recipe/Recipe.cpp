// Recipe.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

void suspendCommandLine()
{
	char dummy[256];
	gets_s(dummy);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// wprintf�ŏo�͂��邽�߂̐ݒ�
	char *loc = setlocale(LC_ALL, "");

	// ���V�s�f�[�^�̐���
	std::wstring recipeTitle(_T("�I�����C�X"));

	// ���V�s�̏o��
	_tprintf(recipeTitle.c_str());


	suspendCommandLine();
	return 0;
}


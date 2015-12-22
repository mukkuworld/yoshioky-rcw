#pragma once 

typedef std::vector<std::wstring> StringVector;


//////////////////////////
// ���V�s
// 
class RecipeData
{
public:
	RecipeData() = default;
	~RecipeData() = default;
	RecipeData(const std::wstring& filePath);

	const StringVector& getTitles() const;

	/** @brief	�f�[�^���t�@�C���֕ۑ����܂��B */
	void save();

private:
	void buildTitlesFromFile(const std::wstring& filePath);

private:
	StringVector m_titles;
	std::wstring m_filePath;	//!< �f�[�^�t�@�C���̊��S�p�X

};
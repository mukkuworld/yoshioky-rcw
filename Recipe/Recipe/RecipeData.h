#pragma once 

typedef std::vector<std::wstring> StringVector;


//////////////////////////
// レシピ
// 
class RecipeData
{
public:
	RecipeData() = default;
	~RecipeData() = default;
	RecipeData(const std::wstring& filePath);

	const StringVector& getTitles() const;

	/** @brief	データをファイルへ保存します。 */
	void save();

private:
	void buildTitlesFromFile(const std::wstring& filePath);

private:
	StringVector m_titles;
	std::wstring m_filePath;	//!< データファイルの完全パス

};
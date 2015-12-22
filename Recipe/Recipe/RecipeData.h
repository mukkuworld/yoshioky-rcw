#pragma once 

typedef std::vector<std::wstring> StringVector;


//////////////////////////
// ƒŒƒVƒs
// 
class RecipeData
{
public:
	RecipeData() = default;
	~RecipeData() = default;
	RecipeData(const std::wstring& filePath);

	const StringVector& getTitles() const;

private:
	void buildTitlesFromFile(const std::wstring& filePath);

private:
	StringVector m_titles;
};
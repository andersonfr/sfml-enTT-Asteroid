#include "Resources.h"
#include <assert.h>

bool ResourceManager::LoadFont(EFont fontType)
{
	sf::Font font;
	assert((m_dicFonts.find(fontType) != m_dicFonts.end()) &&
		"This font does not exist");

	if (m_loadedFonts.find(fontType) == m_loadedFonts.end())
	{
		const std::string& fontFile = m_dicFonts[fontType];
		if (font.loadFromFile(fontFile)) 
		{
			m_loadedFonts.insert(std::make_pair(fontType, font));
		}
	}
	return false;
}

const sf::Font & ResourceManager::GetFont(EFont fontType)
{
	auto it = m_loadedFonts.find(fontType);
	if (it != m_loadedFonts.end()) 
	{
		return it->second;
	}
	else 
	{
		assert(LoadFont(fontType) && "Could not load font");
		return m_loadedFonts[fontType];
	}
}
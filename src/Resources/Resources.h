#pragma once
#include <map>
#include <SFML/Graphics/Font.hpp>

enum class EFont 
{
	Retro
};


class ResourceManager 
{
private:
	ResourceManager() 
	{
		if (m_dicFonts.empty()) 
		{
			m_dicFonts = 
			{
				{EFont::Retro , "Retrotown.ttf"}
			};
		}
		LoadFont(EFont::Retro);
	};
private:
	~ResourceManager() = default;
	bool LoadFont(EFont fontType);
public:
	static ResourceManager& GetInstance() 
	{
		static ResourceManager instance;
		return instance;
	}

public:
	ResourceManager(ResourceManager const&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager const&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

	const sf::Font& GetFont(EFont fontType);
	std::map<EFont, sf::Font> m_loadedFonts;
	std::map<EFont, std::string> m_dicFonts;
};
#include "FontManager.h"

FontMenager* FontMenager::s_FontMenager = nullptr;

FontMenager::FontMenager()
{
	if (s_FontMenager == nullptr)
		s_FontMenager = this;
}

void FontMenager::addFont(const std::string &filename)
{
	sf::Font *font;
	font = new sf::Font();

	if (!font->loadFromFile(filename))
	{
		std::cout << "FontMenager::addFont() Font not loaded";
		return;
	}

	s_FontMenager->m_fonts.push_back(*font);

}

sf::Font FontMenager::getFont(const int &number)
{
	return s_FontMenager->m_fonts[number];
}


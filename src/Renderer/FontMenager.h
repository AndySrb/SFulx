#ifndef FONTMENAGER_H
#define FONTMENAGER_H 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#warning Add documetation
#warning Do test

class FontMenager
{

	private:
		FontMenager(const FontMenager &obj);
		FontMenager(FontMenager &&obj);
		
		static FontMenager *s_FontMenager;
		std::vector<sf::Font> m_fonts;

	public:
		FontMenager();
		FontMenager(sf::Font);
		sf::Font getFont(const int &number);
		void addFont(const std::string &filename);
		

};

#endif

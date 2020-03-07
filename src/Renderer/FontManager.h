#ifndef FONTMANAGER_H
#define FONTMANAGER_H 

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


/*
 * This class is intended to hold font data and call it later add it in
 * sf::text
*/


class FontMenager
{

	private:
		FontMenager(const FontMenager &obj);
		FontMenager(FontMenager &&obj);
		
		static FontMenager *s_FontMenager;
		std::vector<sf::Font> m_fonts;

	public:
		FontMenager();
		sf::Font getFont(const int &number);
		void addFont(const std::string &filename);
		

};

#endif

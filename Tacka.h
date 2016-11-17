#pragma once
#include <string>
#include <iostream>

namespace kolokvijum
{
	class Tacka
	{
		int x, y;
		std::string naziv;
		friend std::ostream& operator<<(std::ostream&, const Tacka&);
		friend std::istream& operator >> (std::istream&, Tacka&);
	public:
		Tacka(char*, int, int);
		Tacka(int = 0, int = 0);
		~Tacka();
		bool operator==(const Tacka&)const;
		bool operator!=(const Tacka&);
		double operator-(const Tacka&);
		int getX()const;
		int getY()const;
		void setXY(int, int);
		operator double()const;

	};
	const Tacka nula;
}
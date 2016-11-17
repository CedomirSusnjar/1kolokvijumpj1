#include "Tacka.h"

namespace kolokvijum
{
	Tacka::Tacka(char *naziv, int x, int y) :naziv(naziv), x(x), y(y) {}

	Tacka::Tacka(int x, int y) : naziv(""), x(x), y(y) {}

	Tacka::~Tacka()
	{
	}

	bool Tacka::operator==(const Tacka &t)const
	{
		return x == t.x && y == t.y;
	}

	bool Tacka::operator!=(const Tacka &t)
	{
		return !(*this == t);
	}

	double Tacka::operator-(const Tacka &t)
	{
		double dx = x - t.x;
		double dy = x - t.y;
		return sqrt(dx*dx + dy*dy);
	}

	int Tacka::getX() const
	{
		return this->x;
	}

	int Tacka::getY() const
	{
		return this->y;
	}

	void Tacka::setXY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Tacka::operator double()const
	{
		return *this - nula;
	}


	std::ostream & operator<<(std::ostream &str, const Tacka &t)
	{
		return str << t.naziv << "(" << t.x << "," << t.y << ")";
	}

	std::istream & operator >> (std::istream &str, Tacka &t)
	{
		std::cout << "unesi tacku:";
		return str >> t.naziv >> t.x >> t.y;
	}

}

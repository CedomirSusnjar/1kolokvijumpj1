#pragma once
#include "Tacka.h"
#include <functional>
#include <algorithm>
namespace kolokvijum
{
	class Niz
	{
		int n;
		Tacka *niz;
		void copy(const Niz&);
		Niz transformisi(const std::function<int(int)>&);
		friend std::ostream& operator<<(std::ostream&, Niz&);
	public:
		Niz(int = 1);
		Niz(const Niz&);
		~Niz();
		Niz& operator=(const Niz&);
		Niz operator+=( int);
		Niz operator*=(const int);
		Niz operator-=(const int);
		Tacka& operator[](const int);
		Niz filtriraj(const std::function<bool(Tacka&)>&);

	};
}
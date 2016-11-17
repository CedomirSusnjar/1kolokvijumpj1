#include "Niz.h"
namespace kolokvijum
{
	void Niz::copy(const Niz &a)
	{
		if (this == &a)return;
		niz = new Tacka[this->n = a.n];
		std::copy(a.niz, a.niz + a.n, niz);
	}
	Niz Niz::transformisi(const std::function<int(int)>&f)
	{
		std::for_each(niz, niz + n, [&f](Tacka &t) {t.setXY(f(t.getX()), f(t.getY())); });
		return *this;
	}
	Niz::Niz(int n)
	{
		niz = new Tacka[this->n = n > 0? n :1 ];
	}
	Niz::Niz(const Niz &a)
	{
		copy(a);
	}
	Niz::~Niz()
	{
		delete[]niz;
	}
	Niz & Niz::operator=(const Niz &t)
	{
		if (this == &t)return *this;
		delete[]niz;
		copy(t);
		return *this;
	}
	Niz Niz::operator+=(const int i)
	{
		return transformisi([i](int j) {return j + i; });
	}
	Niz Niz::operator*=(const int i)
	{
		return transformisi([i](int j) {return i*j; });
	}
	Niz Niz::operator-=(const int i)
	{
		return transformisi([i](int j) {return i - j; });
	}
	Tacka& Niz::operator[](const int i)
	{
		if (i<0 || i>n)return niz[0];
		else return niz[i];
	}

	Niz Niz::filtriraj(const std::function<bool(Tacka&)>&fc)
	{
		int p = 0;
		Niz a(n);
		for (int i = 0; i < n; i++)
		{
			if (fc(niz[i]))
			{
				a.niz[p] = niz[i];
				p++;
			}

		}
		Niz b(p);
		std::copy(a.niz, a.niz + p, b.niz);
		if (b.n == 0)std::cout << "Niz je prazan!!" << std::endl;
		return b;
	}


	std::ostream & operator<<(std::ostream &str,  Niz& a)
	{
		std::for_each(a.niz, a.niz + a.n, [&str](Tacka& f) {str << f << std::endl; });
		return str;
	}
}
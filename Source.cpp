#include "Niz.h"
using namespace kolokvijum;
int main()
{
	Tacka a, b("B", 2, 4), c("C", 1, 2);
	Niz h(4);
	h[0] = a;
	h[1] = b;
	h[2] = c;
	std::cin >> h[3];
	std::cout << h.filtriraj([&h](const Tacka&r) {return r == h[3]; });
	std::cin.ignore();
	std::cin.get();
}
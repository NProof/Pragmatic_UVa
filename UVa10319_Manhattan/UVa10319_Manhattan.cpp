#include <iostream>

// data structure
struct City
{
	int S; // 0 < S <= 30
	int A; // 0 < A <= 30
	int m; // 0 < m <= 200
};

struct Router
{
	int s1, a1, s2, a2;
};

int main()
{
	int n;
	std::cin >> n;
	#ifdef DEBUG
	std::cout << n << std::endl;
	#endif
	while(n--)
	{
		City city;
		std::cin >> city.S >> city.A >> city.m;
		#ifdef DEBUG
		std::cout << city.S << city.A << city.m << std::endl;
		#endif
		int m = city.m;
		Router routers[m];
		while(m--)
		{
			std::cin >> routers[m].s1 >> routers[m].a1 >> routers[m].s2 >> routers[m].a2;
			#ifdef DEBUG
			std::cout << routers[m].s1 << routers[m].a1 << routers[m].s2 << routers[m].a2 << std::endl;
			#endif
		}
	}
	return 0;
}

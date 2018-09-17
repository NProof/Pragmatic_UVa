#include <iostream>
#include <vector>

struct Router;

struct City
{
	std::vector<Router> routers;
};

struct Router
{
	int s1, a1, s2, a2;
};

int main()
{
	int n;
	int S; // 0 < S <= 30
	int A; // 0 < A <= 30
	int m; // 0 < m <= 200
	std::cin >> n;
	#ifdef DEBUG
	std::cout << n << std::endl;
	#endif
	while(n--)
	{
		std::cin >> S >> A >> m;
		#ifdef DEBUG
		std::cout << S << A << m << std::endl;
		#endif
		City city;
		Router temp;
		while(m--)
		{
			std::cin >> temp.s1 >> temp.a1 >> temp.s2 >> temp.a2;
			temp.s1--; temp.a1--; temp.s2--; temp.a2--;
			city.routers.push_back(temp);
		}
		#ifdef DEBUG
		for(std::vector<Router>::iterator it = city.routers.begin(); it != city.routers.end(); it++)
		{
			std::cout << it->s1 << it->a1 << it->s2 << it->a2 << std::endl;
		}
		#endif
	}
	return 0;
}

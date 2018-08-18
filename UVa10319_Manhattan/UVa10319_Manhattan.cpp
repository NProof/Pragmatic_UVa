#include <iostream>

struct Router;

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
		int i = city.m;
		Router routers[i];
		while(i--)
		{
			std::cin >> routers[i].s1 >> routers[i].a1 >> routers[i].s2 >> routers[i].a2;
			routers[i].s1--; routers[i].a1--; routers[i].s2--; routers[i].a2--;
			#ifdef DEBUG
			std::cout << routers[i].s1 << routers[i].a1 << routers[i].s2 << routers[i].a2 << std::endl;
			#endif
		}
		bool sat = false, inter_sat;
		unsigned int sat_s, sat_a;
		sat_s = 0;
		while(!sat && (sat_s < (1<<city.S)))
		{
			sat_a = 0;
			while(!sat && (sat_a < (1<<city.A)))
			{
				inter_sat = true;
				for(i=0; inter_sat && (i<city.m); i++)
				{
					if(!(routers[i].s2 == routers[i].s1 && routers[i].a2 == routers[i].a1))
					{
						if(routers[i].s2 == routers[i].s1)
						{
							if(!((bool)(sat_s&(1<<routers[i].s1))==(routers[i].a2 > routers[i].a1)))
							{
								inter_sat = false;
								break;
							}
						}
						else if(routers[i].a2 == routers[i].a1)
						{
							if(!((bool)(sat_a&(1<<routers[i].a1))==(routers[i].s2 > routers[i].s1)))
							{
								inter_sat = false;
								break;
							}
						}
						else
						{
							if(!(((bool)(sat_a&(1<<routers[i].a1))==(routers[i].s2 > routers[i].s1)
								&&(bool)(sat_s&(1<<routers[i].s2))==(routers[i].a2 > routers[i].a1))
								||((bool)(sat_a&(1<<routers[i].a2))==(routers[i].s2 > routers[i].s1)
								&&(bool)(sat_s&(1<<routers[i].s1))==(routers[i].a2 > routers[i].a1))))
							{
								inter_sat = false;
								break;
							}
						}
					}
				}
				if(inter_sat)
				{
					sat = true;
					break;
				}
				sat_a++;
			}
			sat_s++;
		}
		std::cout << (sat ? "Yes" : "No") << std::endl;
	}
	return 0;
}

#include "main.h"

int main()
{
	int d;
	int u, comp, pS = 0, cS = 0;

	while (1)
	{
		if ((u = prompt()))
		{
			if (u == 9)
			{
				cout << "Alright! Till next time.." << endl;
				clearRecords();
				break;
			}
			if (u == 8)
				continue;
			d = logic(u, &comp);
			result(d, --u, comp, &pS, &cS);
		}
	}
	clearRecords();
	return 0;
}

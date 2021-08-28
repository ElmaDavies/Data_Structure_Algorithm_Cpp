#pragma once
#include"bank.h"
#include"../queue/queue.h"

int bestWindow(Queue<Customer> windows[], int nWin)
{
	int optWin = 0;
	int minSize = windows[0].getSize();
	for (int i = 1; i < nWin; i++)
	{
		if (minSize > windows[i].getSize())
		{
			minSize = windows[i].getSize();
			optWin = i;
		}
	}
	return optWin;
}
void simulate(int nwin, int servTime)
{
	Queue<Customer>* windows = new Queue<Customer>[nwin];
	for (int now = 0; now < servTime; now++)
	{
		if (rand() % (1 + nwin))
		{
			Customer c;
			c.time = 1 + rand() % 98;
			c.window = bestWindow(windows, nwin);
			windows[c.window].enqueue(c);
			std::cout << c.time <<"and"<<c.window << std::endl;
			
		}
		for (int i = 0; i < nwin; i++)
		{
			if (!windows[i].empty())
			{
				if (--windows[i].front().time <= 0)
				{
					
					windows[i].dequeue();
					std::cout << i << std::endl;
				}
			}
			
		}
	}
	delete[]windows;
}




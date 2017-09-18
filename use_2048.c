#include <stdio.h>
#include "2048.h"
#include <time.h>
#include <stdlib.h>

int main (void)
{
	char ch;
	int play[4][4];

	EmptyGame(play);
	srand(time(0));
	InputNumber(play);
	InputNumber(play);
	while (1)
	{
		StartGame(play);
		ch = getch();
		switch (ch)
		{
			case 'a':
			case 'A': 
			if (CanMove(play))
				   TurnLeft(play);
				   break ;
			case 'd':
			case 'D': 
			if (CanMove(play))
				TurnRight(play);
				   break;
			case 'w':
			case 'W':  
			if (CanMove(play))
				TurnUp(play);
				   break;
			case 's':
			case 'S':  
			if (CanMove(play))
				TurnDown(play);
				   break;
			case 'q':
			case 'Q': 
			printf("%29c木嘛~~~~~~~~~~~~~~~~~~~~~~\n", ' ');
				   exit (0);
			case 'r': 
			case 'R':  
			EmptyGame(play);
			InputNumber(play);	
			InputNumber(play);
			continue;
			default :  continue;
		}
		if (CanMove(play))
			InputNumber(play);
	}
	return 0;
}
			



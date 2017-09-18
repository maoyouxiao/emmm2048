#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2048.h"

static int randnum(void);
static int randrow(void);
static int randcol(void);
static void lefttero(int (*ar)[4]);
static void righttero(int (*ar)[4]);
static void uptero(int (*ar)[4]);
static void downtero(int (*ar)[4]);


void EmptyGame(int (*ar)[4])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			ar[i][j] = 0;
}

bool CanMove(int (*ar)[4])
{
	int i, j;
	bool flag = false;
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (ar[i][j] == 0)
				return true;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			if (ar[i][j] == ar[i][j+1] && ar[i][j] != 0)
				flag = true;
	for (j = 0; j < 4; j++)
		for (i = 0; i < 3; i++)
			if (ar[i][j] == ar[i+1][j] && ar[i][j] != 0)
				flag = true;
	return flag;
}

void InputNumber(int (*ar)[4])
{
	int num;
	int row, col;

	num = randnum();
	while (1)
	{
		row = randrow();
		col = randcol();
		if (ar[row][col] == 0)
		{
			ar[row][col] = num;
			break;
		}
	}
}

void TurnLeft(int (*ar)[4])
{
	int i, j;

	lefttero(ar);

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (ar[i][j] != 0)
			{
				if (ar[i][j] == ar[i][j+1])
				{
					ar[i][j] *= 2;
					int k;
					for (k = j+1; k < 3; k++)
						ar[i][k] = ar[i][k+1];
					ar[i][k] = 0;
				}
			}
		}
	}
}

void TurnRight(int (*ar)[4])
{
	int i, j;

	righttero(ar);

	for (i = 0; i < 4; i++)
	{
		for (j = 3; j > 0; j--)
		{
			if (ar[i][j] != 0)
			{
				if (ar[i][j] == ar[i][j-1])
				{
					ar[i][j] *= 2;
					int k;
					for (k = j-1; k > 0; k--)
						ar[i][k] = ar[i][k-1];
					ar[i][k] = 0;
				}
			}
		}
	}
}

void TurnUp(int (*ar)[4])
{
	int i, j;

	uptero(ar);

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (ar[i][j] != 0)
			{
				if (ar[i][j] == ar[i+1][j])
				{
					ar[i][j] *= 2;
					int k;
					for (k = i+1; k < 3; k++)
						ar[k][j] = ar[k+1][j];
					ar[k][j] = 0;
				}
			}
		}
	}
}

void TurnDown(int (*ar)[4])
{
	int i, j;

	downtero(ar);

	for (j = 0; j < 4; j++)
	{
		for (i = 3; i > 0; i--)
		{
			if (ar[i][j] != 0)
			{
				if (ar[i][j] == ar[i-1][j])
				{
					ar[i][j] *= 2;
					int k;
					for (k = i-1; k > 0; k--)
						ar[k][j] = ar[k-1][j];
					ar[k][j] = 0;
				}
			}
		}
	}
}

void StartGame(int (*ar)[4])
{
	int i, j;

	COORD pos = {0, 0};
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
	for (i = 5; i >= 0; i--)
		putchar ('\n');
	printf("%29c*********************\n", ' ');
	printf("%29c*       我真帅啊    *\n", ' ');
	printf("%29c*___________________*\n", ' ');
        printf("%29c", ' ');
	for (j = 0; j < 4; j++)
	{
		if (ar[0][j] != 0)
			printf("|%4d", ar[0][j]);
		else
			printf("|    ");
	}
	putchar('|');
	putchar('\n');
	printf("%29c|____|____|____|____|\n", ' ');
	printf("%29c", ' ');
	for (j = 0; j < 4; j++)
	{
		if (ar[1][j] != 0)
			printf("|%4d", ar[1][j]);
		else
			printf("|    ");
	}
	putchar('|');
	putchar('\n');
	printf("%29c|____|____|____|____|\n", ' ');
	printf("%29c", ' '); 
	for (j = 0; j < 4; j++)
	{
		if (ar[2][j] != 0)
			printf("|%4d", ar[2][j]);
		else
			printf("|    ");
	}
	putchar('|');
	putchar('\n');
	printf("%29c|____|____|____|____|\n", ' ');
	printf("%29c", ' ');
	for (j = 0; j < 4; j++)
	{
		if (ar[3][j] != 0)
			printf("|%4d", ar[3][j]);
		else
			printf("|    ");
	}
	putchar('|');
	putchar('\n');
	printf("%29c|____|____|____|____|\n", ' ');
	printf("\n%29c左A 右D 上W 下S 退出Q 重来R\n", ' ');
	if (!CanMove(ar))
	{
		printf("%29c亲亲亲加油~~~~~~~~~~~~~~~~~~~~\n", ' ');
		printf("%29c还玩嘛宝贝？               Y/N\n", ' ');
		char back = getch();
		if (back == 'Y' || back == 'y')
		{
			EmptyGame(ar);
			InputNumber(ar);
			InputNumber(ar);
		}
		else
		{
			printf("%29c木嘛~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", ' ');
			exit (0);
		}
	}
}


static int randnum(void)
{
	int num;
	num = rand() % 3;
	return num < 2 ? 2: 4;
}

static int randrow(void)
{
	return (rand() + 1314) % 4;
}

static int randcol(void)
{
	return (rand() + 6666) % 4;
}

static void lefttero(int (*ar)[4])
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (ar[i][j] == 0)
			{
				int k;
				for (k = j+1; k < 4; k++)
				{
					if (ar[i][k] != 0)
					{
						ar[i][j] = ar[i][k];
						ar[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

static void righttero(int (*ar)[4])
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 3; j > 0; j--)
		{
			if (ar[i][j] == 0)
			{
				int k;
				for (k = j-1; k >= 0; k--)
				{
					if (ar[i][k] != 0)
					{
						ar[i][j] = ar[i][k];
						ar[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

static void uptero(int (*ar)[4])
{
	int i, j;

	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (ar[i][j] == 0)
			{
				int k;
				for (k = i+1; k < 4; k++)
				{
					if (ar[k][j] != 0)
					{
						ar[i][j] = ar[k][j];
						ar[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

static void downtero(int (*ar)[4])
{
	int i, j;

	for (j = 0; j < 4; j++)
	{
		for (i = 3; i > 0; i--)
		{
			if (ar[i][j] == 0)
			{
				int k;
				for (k = i-1; k >= 0; k--)
				{
					if (ar[k][j] != 0)
					{
						ar[i][j] = ar[k][j];
						ar[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

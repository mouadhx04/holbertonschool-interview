#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: number of levels to draw
 */
void menger(int level)
{
	int column, row, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
				printf("%c", hash_space(column, row));
		printf("\n");
		}
	}
}

/**
 * hash_space - gets a character
 * @col: column
 * @row: row
 * Return: '#' or ' '
 */

char hash_space(int col, int row)
{
	while (col && row)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
		col /= 3, row /= 3;
	}
	return ('#');
}
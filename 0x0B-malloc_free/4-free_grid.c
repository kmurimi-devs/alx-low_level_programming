#include <stdio.h>
#include <stdlib.h>
/**
 * free_grid - frees 2D array
 * @grid: array to be freed
 * @height: height of array
 * Return: void returns nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}

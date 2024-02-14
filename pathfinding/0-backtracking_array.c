#include "pathfinding.h"

/**
* backtracking_array - backtracking algorithm
* @map: map
* @rows: the number of rows
* @cols: the number of columns
* @begin: the start point
* @end: the target point
* Return: queue of points
*/
queue_t *backtracking_array(char **map, int rows, int cols,

							point_t const *begin, point_t const *end)
{
	queue_t *path = queue_create(), *reverse_path = queue_create();
	char **mymap;

	int a;

	point_t *point;

	if (!path || !reverse_path)
		return (NULL);
	mymap = malloc(rows * sizeof(char *));
	if (!mymap)
		exit(1);
	for (a = 0; a < rows; a++)
	{
		mymap[a] = malloc(cols + 1);
		if (!mymap[a])
			exit(1);
		strcpy(mymap[a], map[a]);
	}

	if (backtrack(mymap, rows, cols, end, begin->x, begin->y, path))
	{
		while ((point = dequeue(path)))
			queue_push_front(reverse_path, point);
		free(path);
	}
	else
	{
		free(path);
		free(reverse_path);
		reverse_path = NULL;
	}
	for (a = 0; a < rows; a++)
		free(mymap[a]);
	free(mymap);
	return (reverse_path);
}

/**
* backtrack - backtracking algorithm
* @map: map
* @rows: number of rows
* @cols: number of columns
* @end: target point
* @k: current k
* @l: current l
* @path: path
* Return: 1 on success, 0 on failure
*/
int backtrack(char **map, int rows, int cols, point_t const *end,

			int k, int l, queue_t *path)
{
	point_t *point;

	if (k < 0 || k >= cols || l < 0 || l >= rows || map[l][k] != '0')
		return (0);

	map[l][k] = '1';

	point = calloc(1, sizeof(*point));

	if (!point)
		exit(1);

	point->x = k;
	point->y = l;

	queue_push_front(path, point);
	printf("Checking coordinates [%d, %d]\n", k, l);

	if (k == end->x && l == end->y)
		return (1);

	if (backtrack(map, rows, cols, end, k + 1, l, path) ||
		backtrack(map, rows, cols, end, k, l + 1, path) ||
		backtrack(map, rows, cols, end, k - 1, l, path) ||
		backtrack(map, rows, cols, end, k, l - 1, path))
		return (1);

	free(dequeue(path));

	return (0);
}

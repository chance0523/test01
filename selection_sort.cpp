#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int *a, int N)
{
	int min;
	int min_idx;
	int x, y;

	for (y = 0; y < N - 1; y++)
	{
		min_idx = y;
		min = a[y];
		for (x = y + 1; x < N; x++)
		{
			if (min > a[x])
			{
				min = a[x];
				min_idx = x;
			}
		}
		a[min_idx] = a[y];
		a[y] = min;
	}
}

void gen_selection_sort(void *base, int nelem, int width,
	int(*fcmp)(const void *, const void *))
{
	void *min;
	int min_idx;
	int x, y;

	min = malloc(width);
	for (y = 0; y < nelem - 1; y++)
	{
		min_idx = y;
		memcpy(min, (char*)base + y * width, width);
		for (x = y + 1; x < nelem; x++)
		{
			if (fcmp(min, (char*)base + x * width) > 0)
			{
				memcpy(min, (char*)base + x * width, width);
				min_idx = x;
			}
		}
		memcpy((char*)base + min_idx * width, (char*)base + y * width, width);
		memcpy((char*)base + y * width, min, width);
	}
	free(min);
}

int intcmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
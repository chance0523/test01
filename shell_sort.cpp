#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell_sort(int *a, int N)
{
	int i, j, k, h, v;
	for (h = N / 2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < N; j += h)
			{
				v = a[j];
				k = j;
				while (k > h - 1 && a[k - h] > v)
				{
					a[k] = a[k - h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
}
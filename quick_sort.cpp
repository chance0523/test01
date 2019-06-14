#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertion_sort.cpp"

#define MAX 100000
#define SIZE 3000
int stack[MAX];
int top;

void quick_sort(int *a, int N)
{
	int v, t;
	int i, j;
	if (N > 1)
	{
		v = a[N - 1];
		i = -1;
		j = N - 1;
		while (1) {
			while (a[++i] < v)
				while (a[--j] > v)
					if (i >= j)break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

		t = a[i];
		a[i] = a[N - 1];
		a[N - 1] = t;

		quick_sort(a, i);
		quick_sort(a + i + 1, N - i - 1);
	}
}

void quick_sort1(int *a, int N)
{
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = N - 1;
	push(r);
	push(l);
	while (!is_stack_empty()) {
		l = pop();
		r = pop();
		if (r - l + 1 > 1)
		{
			v = a[r];
			i = l - 1;
			j = r;
			while (1) {
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j)break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;

			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
	}
}

void quick_sort3(int *a, int N)
{
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = N - 1;
	push(r);
	push(l);
	while (!is_stack_empty())
	{
		l = pop();
		r = pop();
		if (r - l + 1 > 200)
		{
			t = rand() % (r - l + 1);
			v = a[t];
			a[t] = a[r];
			a[r] = v;
			i = l - 1;
			j = r;
			while (1) {
				while (a[++i] < v)
					while (a[j--] > v)
						if (l >= j)break;
				t = a[i];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else
			insert_sort(a + l, r - l + 1);
	}

}

void init_stack(void)
{
	top = -1;
}

int push(int t)
{
	if (top >= MAX - 1)
	{
		printf("Stack overflow!!!\n");
		return -1;
	}

	stack[++top] = t;
	return t;
}

int pop()
{
	if (top < 0)
	{
		printf("Stack underflow!!!\n");
		return -1;
	}

	return stack[top--];
}

int get_stack_top()
{
	return (top < 0) ? -1 : stack[top];
}

int is_stack_empty()
{
	return (top < 0);
}
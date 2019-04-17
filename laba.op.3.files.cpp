#include <iostream>
#include<string>
#include<fstream>
struct elem
{
	int data1, data2, data3;
	elem *prev, *next;
};
struct queue
{
	elem *back, *front, *dod;
	queue(void) :back(NULL), front(NULL), dod(NULL) {}
};
struct coo
{
	int a, b;
};
using namespace std;
void push_back(queue &a, coo &p, int &x);
void pop_back(queue &a, int &v1, int &v2, int &v3);
void alg(queue &one, coo &p, coo &k, coo &napram, int **A, int &i, int &j, int &h, int &g, int &w);
int main()
{
	queue one;
	coo napram;
	coo p, k;
	p.a = 2; p.b = 1; k.a = 9; k.b = 6;
	alg(one, p, k, napram, A, i, j, h, g, w);
}
void push_back(queue &a, coo &p, int &i)
{
	elem *temp = new elem;
	temp->data1 = p.a;
	temp->data2 = p.b;
	temp->data3 = i;
	temp->prev = NULL;
	if (!a.back)
	{
		a.back = a.front =a.dod= temp; temp->next = NULL;
	}
	else
	{
		temp->next = a.back;
		a.back->prev = temp;
		a.back = temp;
	}
}
void print(queue &a, coo &b)
{
	b.a = a.dod->data1;
	b.b = a.dod->data2;
	a.dod = a.dod->next;
}
void pop_back(queue &a, int &v1, int &v2, int &v3)
{
	if (!a.back->next)
	{
		v1 = a.back->data1;
		v2 = a.back->data2;
		v3 = a.back->data3;
		delete a.back;
		a.back = a.front = NULL;
	}
	else
	{
		v1 = a.back->data1;
		v2 = a.back->data2;
		v3 = a.back->data3;
		a.back = a.back->next;
		a.back->prev = NULL;
	}
}
void alg(queue &one, coo &p, coo &k, coo &napram, int **A, int &i, int &j, int &h, int &g, int &w)
{
	napram.a = p.a;
	napram.b = p.b;
	push_back(one, p, i);
	h = 1;
	w = h;
	while (i < j)
	{
		i++;
		j++;
		for (int r = 0; r < h; r++)
		{
			print(one, napram);
			if (A[napram.a][napram.b - 1] == -2)
			{
				g++; w++;
				napram.b = napram.b - 1;
				push_back(one, napram, i);
				if (napram.a == k.a&&napram.b == k.b)
				{
					j--;
					break;
				}
				napram.b = napram.b + 1;
			}
			if (A[napram.a][napram.b + 1] == -2)
			{
				g++; w++;
				napram.b = napram.b + 1;
				push_back(one, napram, i);
				if (napram.a == k.a&&napram.b == k.b)
				{
					j--;
					break;
				}
				napram.b = napram.b - 1;
			}
			if (A[napram.a - 1][napram.b] == -2)
			{
				g++; w++;
				napram.a = napram.a - 1;
				push_back(one, napram, i);
				if (napram.a == k.a&&napram.b == k.b)
				{
					j--;
					break;
				}
				napram.a = napram.a + 1;
			}
			if (A[napram.a + 1][napram.b] == -2)
			{
				g++; w++;
				napram.a = napram.a + 1;
				push_back(one, napram, i);
				if (napram.a == k.a&&napram.b == k.b)
				{
					j--;
					break;
				}
				napram.a = napram.a - 1;
			}
		}
		h = g;
		g = 0;
	}
	///////////////////////////////////////
	pop_back(one, h, g, j);
	napram.a = h; napram.b = g;
	A[h][g] = j;
	for (i = 0; i < w - 1; i++)
	{
		pop_back(one, h, g, j);
		if ((h == napram.a&&g == napram.b - 1) || (h == napram.a&&g == napram.b + 1) || (h == napram.a - 1 && g == napram.b) || (h == napram.a + 1 && g == napram.b))
		{
			napram.a = h; napram.b = g;
			A[h][g] = j;
		}
	}
}
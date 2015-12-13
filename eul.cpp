#include <stdio.h>
#include <stdlib.h>
class Graph
{
private:
	int **A;
	bool *visited;
public:
	int n;
	Graph(char arg[])
	{
		int N;
		FILE * f;
		f = fopen(arg, "r");
		fscanf(f, "%d", &N);
		this->n = N;
		visited = (bool *)calloc(sizeof(bool), N);
		A = (int **)calloc(sizeof(int*),N);
		for (int i = 0; i < N; i++) {
			A[i] = (int *)calloc(sizeof(int), N);
			for (int j = 0; j < N; j++)
			{
				fscanf(f, "%d", &(this->A[i][j]));
			}
		}
		fclose(f);
	}
	void print()
	{
		for (int i = 0; i < this->n; i++)
		{
			printf("\n");
			for (int j = 0; j < this->n; j++)
				printf("%d ", this->A[i][j]);
		}
		printf("\n");
	}
	bool Euler()
	{
		bool euler = true;
		int chet;
		for (int i = 0; i < this->n; i++) {
			chet = 0;
			for (int j = 0; j < this->n; j++)
			{
				chet += this->A[i][j];
			}
			if ((chet % 2) == 1)
				euler = false;
		}
		return euler;
	}
	bool Conn(int i, int j)
	{
		if (this->A[i][j] != 0)
			return true;
		else
		{
			return false;
		}
	}
	bool Gamil(int v,int w,int d)
	{
		if (d == 1 && Conn(w, v))
			return true;
		visited[v] = true;
		for (int t = 0; t < this->n; t++)
			if (Conn(t, v))
				if (!visited[t])
					if (Gamil(t, w, d - 1))
						return true;
		visited[v] = false;
		return false;
	}
};
int main(int argc, char *argv[])
{
	Graph *graph = new Graph(argv[1]);
	graph->print();
	if (graph->Gamil(0,0,graph->n))
		printf("Hamiltonian\n");
	else
	{
		printf("Not Hamiltonian\n");
	}
	if (graph->Euler())
		printf("Euler\n");
	else
	{
		printf("Not Euler\n");
	}
	return 0;
}

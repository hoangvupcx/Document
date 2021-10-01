#include <iostream>
#include <string.h>
#include <string>
#define MAX 100
using namespace std;

struct Stack
{
	char a[MAX][MAX];
	int sp;
};

void init(Stack &s)
{
	s.sp = -1;
}

void push(Stack &s, char x[])
{
	strcpy(s.a[++s.sp], x);
}

char* pop(Stack &s)
{
	return s.a[s.sp--];
}

bool checkOp(char op[])
{
	return strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0;
}

void cal(char s[])
{
	Stack st;
	init(st);
	char *p = strtok(s, " ");
	int t = 0;
	while (p != NULL)
	{
		if (checkOp(p) == true)
		{
			int b = atoi(pop(st));
			int a = atoi(pop(st));
			if (strcmp(p, "+") == 0)
				t = a + b;
			else
				if (strcmp(p, "-") == 0)
					t = a - b;
				else
					if (strcmp(p, "*") == 0)
						t = a * b;
					else
						if (strcmp(p, "/") == 0)
							t = a / b;
			char tmp[MAX];
			sprintf(tmp, "%d", t);
			push(st, tmp);
		}
		else
			push(st, p);
		p = strtok(NULL, " ");
	}
	cout << "Ket qua cua bieu thuc la: " << t << endl;
}



int main()
{
	char s[MAX];
	cout << "Nhap bieu thuc hau to can tinh: ";
	cin.get(s, MAX);
	cal(s);
	return 0;
}
#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* first;

void init(); // Khởi tạo danh sách rỗng
bool SNT(int snt);
void xuatSNT();

void Insearch_First(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}


bool SNT(int snt)
{
	if (snt == 0 || snt == 1)
		return false;
	else
	{
		if (snt < 0)
			snt = abs(snt);
		int i;
		for (i = 2; i < snt; i++)
		{
			if (snt % i == 0)
				return false;
		}
		return true;
	}
}

void XuatSNT()
{
	Node* p = first;
	while (p != NULL)
	{
		if (SNT(p->info))
			cout << p->info << endl;
			p = p->link;
	}
}


int main()
{
	int x;
	init();
	cout << "Nhap gia tri can them: ";
	cin >> x;
	Insearch_First(x);

}
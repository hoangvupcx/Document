#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100

void Nhap(int a[], int n);
void Xuat(int a[], int n);
void Tim_Xuat(int a[], int n, int x);

int main()
{
	int a[MAX], n, x;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Nhap(a, n);
	cout << "Mang dang luu tru: " << endl;
	Xuat(a, n);
	cout << "Nhap gia tri can tim: ";
	cin >> x;
	Tim_Xuat(a, n, x);
	system("pause");
	return 0;
}

void Nhap(int a[], int n)
{
	cout << "Nhap " << n << " phan tu: " << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}


void Tim_Xuat(int a[], int n, int x)
{
	int t = 0, dem = 0, flag = 0;
	for (int i = 0; i < n; i++)
		if (x == a[i])
		{
			dem++;
			t = 1;
		}
	if (t == 1)
		cout << "Tim thay " << x << " trong day " << endl;
	else
		cout << "Khong tim thay " << x << " trong day " << endl;
	cout << "So lan xuat hien cua " << x << " la: " << dem << endl;
	for (int j = 0; j < n; j++)
	{
		if (a[j] == x)
		{
			cout << "a[" << j <<"] ";
			flag = j + 1;
		}
		if (flag == 0)
			cout << "Cac vi tri ma " << x << " xuat hien la: ";
	}
	cout << endl;
}
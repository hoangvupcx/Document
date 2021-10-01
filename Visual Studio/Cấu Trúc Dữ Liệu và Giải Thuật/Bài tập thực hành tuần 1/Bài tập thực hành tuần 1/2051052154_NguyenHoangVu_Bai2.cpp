#include <iostream>
using namespace std;
#define MAX 100

void Nhap(int a[], int n);
void Xuat(int a[], int n);
void swap(int& a, int& b);
void QuickSort(int a[], int left, int right);
int main()
{
	int a[MAX], n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Nhap(a, n);
	cout << "Mang dang luu tru: " << endl;
	Xuat(a, n);
	cout << "Mang sau khi sap xep la: " << endl;
	QuickSort(a, 0, n - 1);
	Xuat(a, n);
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

void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
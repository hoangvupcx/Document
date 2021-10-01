#include <iostream>
using namespace std;
#define MAX 100

void Nhap(int a[], int n);
void Xuat(int a[], int n);
void swap(int& a, int& b);
void QuickSort(int a[], int left, int right);

int demgan = 0,demss = 0, demtoan = 0;
int main()
{
	int a[MAX], n;
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n < 0 && n > 100)
		cout << "Nhap sai. Nhap lai!" << endl;
	} while (n < 0 && n > 100);
	Nhap(a, n);
	cout << "Mang dang luu tru: " << endl;
	Xuat(a, n);
	cout << "Mang sau khi sap xep la: " << endl;
	QuickSort(a, 0, n - 1);
	cout << "So luong phep Gan la: " << demgan << endl;
	cout << "So luong phep So Sanh la: " <<demss << endl;
	cout << "So luong phep Toan la: " << demtoan << endl;;
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

void QuickSort(int a[MAX], int left, int right)
{
	int x = a[(left + right) / 2];
	demtoan++;
	int i = left;
	int j = right;
	demgan += 3;
	demss++;
	while (i < j)
	{
		demss++;
		while (a[i] < x)
		{
			i++;
			demtoan++;
			demgan++;
			demss++;
		}
		demss++;
		while (a[j] > x)
		{
			j--;
			demtoan++;
			demgan++;
			demss++;
		}
		demss++;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			demgan += 3;
			i++;
			j--;
			demtoan += 2;
			demgan += 2;
		}
	}

	demss++;
	if (left < j)
	{
		QuickSort(a, left, j);
	}

	demss++;
	if (i < right)
	{
		QuickSort(a, i, right);
	}
}
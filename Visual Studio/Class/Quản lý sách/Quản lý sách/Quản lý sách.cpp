#include <iostream>
#include <conio.h>
#define MAXSIZE 50
using namespace std;
struct NTN {
	int d, m, y;
};
struct Sach {
	char tenSach[21];
	char tenTG[21];
	NTN xb;
};

void nhap1Sach(Sach &s);
void xuat1Sach(Sach s);
void nhapDSS(Sach *ds, int n);
void xuatDSS(Sach *ds, int n);
void xuatDSTheoTG(Sach *ds, int n);
void chuyenThuong(char a[21]);
void sua1Sach(Sach &s);
void xoa1Sach(Sach *ds, int &n, int vt);
void sapXepXb(Sach *ds, int n);

int main() 
{
	int chon;
	bool in = false;
	Sach *dss;
	int n, vt;
	do {
		system("cls");
		cout << "Chuong trinh quan ly sach." << endl;
		cout << "1. Nhap danh sach cac sach." << endl;
		cout << "2. Xuat thong tin cac sach dang co." << endl;
		cout << "3. Xuat cac sach cua tac gia Tran Dung." << endl;
		cout << "4. Sua doi thong tin 1 sach." << endl;
		cout << "5. Xoa 1 sach." << endl;
		cout << "6. Sap xep theo ngay/thang/nam xuat ban tang dan." << endl;
		cout << "7. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			do {
				cout << "\n Ban can luu tru thong tin bao nhieu quyen sach: ";
				cin >> n;
				if (n <= 0 || n > MAXSIZE)
					cout << "Vui long nhap so luong tu 1 den " << MAXSIZE << endl;
			} while (n <= 0 || n > MAXSIZE);
			dss = new Sach[n];
			nhapDSS(dss, n);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Cac quyen sach dang luu tru: " << endl;
				xuatDSS(dss,n);
			}
			else
				cout << "Vui long nhap thong tin sanh sach truoc. " << endl;
			break;
		case 3:
			if (in)
			{
				xuatDSTheoTG(dss, n);
			}
			else
				cout << "Vui long nhap thong tin sanh sach truoc. " << endl;
			break;
		case 4:
			if (in)
			{
				cout << "Nhap vi tri can sua: ";
				cin >> vt;
				if (vt > 0 && vt <= n)
				{
					sua1Sach(dss[vt - 1]);
					cout << "Them thanh cong. Chon xuat de xem ket qua." << endl;
				}
				else
					cout << "Vi tri can sua khong hop le." << endl;
			}
			else
				cout << "Vui long nhap thong tin sanh sach truoc. " << endl;
			break;
		case 5:
			if (in)
			{
				cout << "Nhap vi tri can xoa: ";
				cin >> vt;
				if (vt > 0 && vt <= n)
				{
					xoa1Sach(dss, n, vt);
					cout << "Xoa thanh cong. Chon xuat danh sach de xem ket qua" << endl;
				}
				else
					cout << "Vi tri can xoa khong hop le." << endl;
			}
			else
				cout << "Vui long nhap thong tin sanh sach truoc. " << endl;
			break;
		case 6:
			if (in)
			{
				sapXepXb(dss, n);
				cout << "Sap xep thanh cong. Chon xuat de xem ket qua." << endl;
			}
			else
				cout << "Vui long nhap thong tin sanh sach truoc. " << endl;
			break;
		default:
			delete[] dss;
			dss = NULL;
			cout << "Thoat." << endl;
		}
		_getch();
	} while (chon >= 1 && chon <= 6);
	return 0;
}

void nhap1Sach(Sach &s)
{
	cin.ignore();
	cout << "+ Nhap ten sach: " << endl;
	cin.getline(s.tenSach, 21);
	cout << "+ Nhap ten tac gia: " << endl;
	cin.getline(s.tenTG, 21);
	cout << "+ Nhap ngay/thang/nam xuat ban theo kieu dd/mm/yyyy: " << endl;
	cin >> s.xb.d >> s.xb.m >> s.xb.y;
}
void xuat1Sach(Sach s)
{
	cout << "+ Ten sach: " << s.tenSach << endl;
	cout << "+ Tac gia: " << s.tenTG << endl;
	cout << "+ Ngay/thang/nam xuat ban: " << s.xb.d << s.xb.m << s.xb.y << endl;
}

void nhapDSS(Sach *ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sach thu " << i + 1 << endl;
		nhap1Sach(ds[i]);
	}
}

void xuatDSS(Sach *ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin quyen sach thu " << i + 1 << ": " << endl;
		xuat1Sach(ds[i]);
	}
}

void xuatDSTheoTG(Sach *ds, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		chuyenThuong((ds + i)->tenTG);
		if (strcmp((ds + i)->tenTG, "tran dung"))
		{
			dem++;
			if (dem == 1)
				cout << "\n Cac sach cua tac gia Tran Dung: " << endl;
			cout << "Quyen sach thu " << dem << ": " << endl;
			xuat1Sach(*(ds + i));
		}
	}
	if (dem == 0)
		cout << "Khong co quyen sach nao cua tac gia Tran Dung." << endl;

}

void chuyenThuong(char a[21])
{
	char *s = a;
	while (*s)
	{
		*s = tolower(*s);
		s++;
	}
}

void sua1Sach(Sach &s)
{
	int chon;
	do 
	{
		cout << "1. Sua ten sach." << endl;
		cout << "2. Sua ten tac gia." << endl;
		cout << "3. Sua ngay/thang/nam xuat ban." << endl;
		cout << "4. Sua toan bo thong tin." << endl;
		cout << "5. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cin.ignore();
			cout << "+ Nhap ten sach: ";
			cin.getline(s.tenSach, 21);
			break;
		case 2:
			cin.ignore();
			cout << "+ Nhap ten tac gia: ";
			cin.getline(s.tenTG, 21);
			break;
		case 3:
			cout << "Nhap ngay/thang/nam xuat ban: ";
			cin >> s.xb.d >> s.xb.m >> s.xb.y;
			break;
		case 4:
			nhap1Sach(s);
			break;
		default:
			cout << "Ket thuc qua trinh chinh sua." << endl;
		}
	} while (chon >= 1 && chon <= 4);
}

void xoa1Sach(Sach *ds, int &n, int vt)
{
	for (int i = vt - 1; i < n; i++)
		*(ds + i) = *(ds + i + 1);
	n--;
}

void sapXepXb(Sach *ds, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j =i + 1; j < n; j++)
			if ((ds + i)->xb.y > (ds + j)->xb.y)
			{
				Sach t = ds[i];
				ds[i] = ds[j];
				ds[j] = t;
			}
}
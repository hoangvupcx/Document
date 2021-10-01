#include <iostream>
using namespace std;
class GPG 
{
private:
	int h, m, s;
public:
	GPG()
	{
		h = m = s = 0;
	};
	~GPG() {}; // hàm hủy
	void set(int a, int b, int c);
	int geth();
	int getm();
	int gets();
	GPG khoangCach(GPG g1, GPG g2); 
	
};

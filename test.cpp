#include<iostream>
using namespace std;
class SuperPrime {
private:
	const int num;

public:
	bool isSurperPrime() const {
		int n = num;
		int d[20], index = 0;
		do {
			d[index++] = n % 10;
			n = n / 10;
		} while (n != 0);

	}

};
int main()
{
	int a, b, c;
	return 0; 
}

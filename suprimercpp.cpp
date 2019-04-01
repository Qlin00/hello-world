#include<iostream>
#include<vector>
using namespace std;
class Prime {
private:
	int val;
public:
	Prime(int n): val(n){}
	bool Isprime() {
		if (val <= 1)
			return 0;
		else {
			for (int i = 2; i < val; i++)
				if (val % i == 0)
					return 0;
			return 1;
		}
	}
};
class Superprime{
private:
	int val;
public:
	Superprime(int n): val(n){}
	bool IsSuperprime() {
		Prime v(val);
		Prime s(SumNumber());
		Prime m(MulityNumber());
		Prime q(SquareNumber());
		return v.Isprime() && s.Isprime() && m.Isprime() && q.Isprime();
	}
	int SumNumber() {
		int sum = 0;
		int temp = val;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		return sum;
	}
	int MulityNumber() {
		int mulity = 1;
		int temp = val;
		while (temp) {
			mulity *= temp % 10;
			temp /= 10;
		}
		return mulity;
	}
	int SquareNumber() {
		int temp = val;
		int sum = 0;
		while (temp) {
			sum += (temp % 10)*(temp % 10);
			temp /= 10;
		}
		return sum;
	}
};
class SuperprimeSets {
private:
	int front;
	int back;
	int count;
	int sum;
	int max;
	vector<int> all;
public:
	SuperprimeSets(int n, int m){
		front = n;
		back = m;
		count = 0;
		max = 0;
		sum = 0;
		for (int i = front; i <= back; i++) {
			Superprime sp(i);
			if (sp.IsSuperprime()) {
				count++;
				sum += i;
				all.push_back(i);
				if (i > max)
					max = i;
			}
		}
	}
	void show() {
		cout << front << "与" << back << "之间的超级素数有:" ;
		vector<int> ::iterator ite = all.begin();
		for (ite; ite != all.end(); ite++)
			cout << *ite << "  ";
		cout << endl;
		cout << front << "与" << back << "之间的超级素数有:" << count << "个"<< endl;
		cout << front << "与" << back << "之间的超级素数最大值为:" << max << endl;
		cout << front << "与" << back << "之间的超级素数和为:" << sum << endl;

	}
};
int main() {
	int n, m;
	cout << "请输入起始与结尾值：" << endl;
	cin >> n >> m;
	SuperprimeSets ss(n, m);
	ss.show();
	system("PAUSE");
	return 0;
}



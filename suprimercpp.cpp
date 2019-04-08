#include<iostream>
#include<vector>
using namespace std;
class Prime {//素数类 
private:
	int val;
public:
	Prime(){}
	Prime(int n): val(n){}//构造函数 
	bool Isprime() {//判断是否为素数 
		if (val <= 1)
			return 0;
		else {
			for (int i = 2; i < val; i++)
				if (val % i == 0)
					return 0;
			return 1;
		}
	}
	~Prime() {

	}
};
class Superprime{//超级素数 
private:
	int val;
public:
	Superprime(){}
	Superprime(int n): val(n){}
	bool IsSuperprime() {//判断是否为超级素数 
		const Prime v(val);
		const Prime s(SumNumber());
		const Prime m(MulityNumber());
		const Prime q(SquareNumber());
		return v.Isprime() && s.Isprime() && m.Isprime() && q.Isprime();
	}
	~Superprime() {

	}
	int SumNumber() {//数位之和 
		int sum = 0;
		int temp = val;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		return sum;
	}
	int MulityNumber() {//数位之积 
		int mulity = 1;
		int temp = val;
		while (temp) {
			mulity *= temp % 10;
			temp /= 10;
		}
		return mulity;
	}
	int SquareNumber() {//数位平方和 
		int temp = val;
		int sum = 0;
		while (temp) {
			sum += (temp % 10)*(temp % 10);
			temp /= 10;
		}
		return sum;
	}
};
class SuperprimeSets {//超级素数集合 
private:
	int front;
	int back;
	int count;
	int sum;
	int max;
	vector<int> all;
public:
	SuperprimeSets(){}
	SuperprimeSets(int n, int m){//直接在构造时给最大值，个数，和赋值，不需要每次都去调用函数 
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
	SuperprimeSets(const SuperprimeSets sp&) {
		
	}
	~SuperprimeSets() {

	}
	void show() const{//展示这个超级素数集合的内容 
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
//主函数 
int main() {
	int n, m;
	cout << "请输入起始与结尾值：" << endl;
	cin >> n >> m;
	SuperprimeSets ss(n, m);
	ss.show();
	system("PAUSE");
	return 0;
}



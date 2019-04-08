#include<iostream>
#include<vector>
using namespace std;
class Prime {//������ 
private:
	int val;
public:
	Prime(){}
	Prime(int n): val(n){}//���캯�� 
	bool Isprime() {//�ж��Ƿ�Ϊ���� 
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
class Superprime{//�������� 
private:
	int val;
public:
	Superprime(){}
	Superprime(int n): val(n){}
	bool IsSuperprime() {//�ж��Ƿ�Ϊ�������� 
		const Prime v(val);
		const Prime s(SumNumber());
		const Prime m(MulityNumber());
		const Prime q(SquareNumber());
		return v.Isprime() && s.Isprime() && m.Isprime() && q.Isprime();
	}
	~Superprime() {

	}
	int SumNumber() {//��λ֮�� 
		int sum = 0;
		int temp = val;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		return sum;
	}
	int MulityNumber() {//��λ֮�� 
		int mulity = 1;
		int temp = val;
		while (temp) {
			mulity *= temp % 10;
			temp /= 10;
		}
		return mulity;
	}
	int SquareNumber() {//��λƽ���� 
		int temp = val;
		int sum = 0;
		while (temp) {
			sum += (temp % 10)*(temp % 10);
			temp /= 10;
		}
		return sum;
	}
};
class SuperprimeSets {//������������ 
private:
	int front;
	int back;
	int count;
	int sum;
	int max;
	vector<int> all;
public:
	SuperprimeSets(){}
	SuperprimeSets(int n, int m){//ֱ���ڹ���ʱ�����ֵ���������͸�ֵ������Ҫÿ�ζ�ȥ���ú��� 
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
	void show() const{//չʾ��������������ϵ����� 
		cout << front << "��" << back << "֮��ĳ���������:" ;
		vector<int> ::iterator ite = all.begin();
		for (ite; ite != all.end(); ite++)
			cout << *ite << "  ";
		cout << endl;
		cout << front << "��" << back << "֮��ĳ���������:" << count << "��"<< endl;
		cout << front << "��" << back << "֮��ĳ����������ֵΪ:" << max << endl;
		cout << front << "��" << back << "֮��ĳ���������Ϊ:" << sum << endl;

	}
};
//������ 
int main() {
	int n, m;
	cout << "��������ʼ���βֵ��" << endl;
	cin >> n >> m;
	SuperprimeSets ss(n, m);
	ss.show();
	system("PAUSE");
	return 0;
}



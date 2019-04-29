#include<iostream>
#include<vector>
using namespace std;
class Number {
protected:
	const int num;
public:
	Number() {}
	Number(int n) : num(n){
		cout << "I am number" << endl;
	}
	Number(const Number & number) : num(number.num){}
	~Number(){
		cout << "number die" << endl;
	}
	bool isPrime() const {
		return false;
	}
	void show() const {
		cout << num << endl;
	}
};
class NumberSet {
private:
	//Number nums[20]; //调用构造函数
	Number *nums[20]; //不调用构造函数，
	int size;
public:
	NumberSet() {
		size = 0;
		for (int i = 0; i < 20; i++)
			nums[i] = NULL;
	}
	~NumberSet() {
		for (int i = 0; i < size; i++)
			delete nums[i];
	}
	bool add(const Number &n) { //&号为引用的意思
		//nums[size++] = &n //&号为取地址的意思。
		//nums[size++] = new Number(n); //new出来的对象要自己回收
		if (size != 20 && nums[size] == NULL) {
			nums[size] = new Number(n);
			size += 1；
				return true;
		}
		return false;
	}
};
class SuperPrime : public Number{
public:
	bool isSurperPrime() const {
		Number n(num);
		NumberSet ns = n.split();
		Number sum = ns.num();
		Number sqsum = ns.sqarue_sum();
		Number multi = ns.multi();
		if (n.isPrime() && sum.isPrime() && sqsum.isPrime() && multi.isPrime())
			return true;
		return false;
	}

};
int main()
{

}
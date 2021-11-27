#include <iostream>
using namespace std;

class Fraction {
	friend istream& operator>>(istream& in, Fraction& f) { return in >> f.m >> f.n; }
	friend ostream& operator<<(ostream& out, const Fraction& f) { return out << "M =" << f.m << " N =" << f.n; }
	friend Fraction operator +(Fraction f1, Fraction f2) { return Fraction((f1.m * f2.n) + (f1.m * f2.n), f1.n * f2.n).Set0(); }
	friend Fraction operator -(Fraction f1, Fraction f2) { return Fraction((f1.m * f2.n) - (f1.m * f2.n), f1.n * f2.n).Set0(); }
	friend Fraction operator *(Fraction f1, Fraction f2) { return Fraction(f1.m * f2.m,f1.n * f2.n).Set0(); }
	friend Fraction operator /(Fraction f1, Fraction f2) { return Fraction(f1.m * f2.n, f1.n * f2.m).Set0(); }
private:
	int m;
	int n;
public:
	Fraction() { m = n = 0; }
	Fraction(int m, int n);
	double getM() { return m; }
	void setM(int m) { this->m = m; }
	double getN() { return n; }
	void setN(int n) { this->n = n; }
	Fraction Set0();
	void SetValues();
	int num; 
	int denom;
	char sign;
	Fraction(int num, char sign, int denom)
	{
		this->num = num;
		this->sign = sign;
		this->denom = denom;
	}
	void simplify()
	{
		for (int i = denom; i >= 2; i--)
		{
			if (num % i == 0 && denom % i == 0)
			{
				num = num / i;
				denom = denom / i;
			}
		}
	}
};


int main()
{
	int num;
	int denom;
	char sign;
	cout << "Enter fraction like 100/2:";
	cin >> num >> sign >> denom;
	Fraction f1(num, sign, denom);
	if (sign != '/')
		exit(0); 

	f1.simplify();

	cout << "Simplified:";
	if (denom == 1)
		cout << f1.num;
	else
		cout << f1.num << "/" << f1.denom;
	cout << endl;

	return 0;
}
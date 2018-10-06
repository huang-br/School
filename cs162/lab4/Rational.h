#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
	private:
		int numerator;
		int denomenator;
	public:
		Rational();
		Rational(int num, int den);
		Rational(int call);
		friend std::ostream& operator<<(std::ostream& output const Rational& num);
		friend std::istream& operator>>(std::istream& input const Rational& number);
};
#endif


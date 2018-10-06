#include "Rational.h"

Rational::Rational()
{
	numerator = 0;
	denomenator = 1;
}

Rational::Rational(int wholenumber)
{
	numerator = wholenumber;
	denomenator = 1;
}

Rational::Rational(int num, int den)
{
	numerator = num;
	denomenator = den;
}

std::ostream operator<<(std::ostream& output, const Rational& x)
{
	output << x.numerator << '/' << x.denomenator ;
	return output;
}

std::istream operator>>(std::istream& input, const Rational& x)
{
	input >> x.numerator >> x.denomenator;
	return input;
}


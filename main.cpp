#include <iostream>
#include <cinttypes>

using namespace std;


int get_digit(int64_t val0)
{
	int res;

	int64_t val = val0 - 1;
	int64_t d = 0, digitsConsumedNext = 0, digitsConsumed = 0, mult = 1, multPrev = 1;
	while (digitsConsumedNext <= val)
	{
		d++;
		multPrev = mult;
		mult *= 10;
		digitsConsumed = digitsConsumedNext;
		digitsConsumedNext = d * (mult - multPrev) + digitsConsumed;

	}


	val -= digitsConsumed;

	long r = val % d;
	long n = multPrev + val / d;

	r = d - r;
	while (r > 1)
	{
		n /= 10;
		r--;
	}

	res = static_cast<int>(n % 10);

	return res;
}


int main()
{
	int64_t idig;

    int res = 1;
    idig = 1;
    for (int i = 0; i < 7; i++) {
        res *= get_digit(idig);
        idig*=10;
    }

    cout << res << endl;
	

    return 0;
}


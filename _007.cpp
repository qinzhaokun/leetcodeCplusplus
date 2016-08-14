class Solution {
public:
    int reverse(int x) {
	if (x < 10 && x > -10) return x;
	long t = x;
	bool isNegative = false;
	if (t < 0){
		isNegative = true;
		t = -t;
	}

	long base = 1;
	long tmp = t;
	while (tmp){
		base *= 10;
		tmp /= 10;
	}
	base /= 10;
	long highbase = base;
	long lowbase = 1;
	long ret = 0;
	while (t){
		if (t < 10){
			ret += t*highbase;
			break;
		}
		long low = t % 10;
		long high = t / base;
		ret += (low*highbase + high*lowbase);

		t %= base;
		t /= 10;
		base /= 100;
		highbase /= 10;
		lowbase *= 10;
	}

	if (isNegative){
		ret = -ret;
	}
	if (ret > INT_MAX || ret < INT_MIN) return 0;
	else return ret;
}
};

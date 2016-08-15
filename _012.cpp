string intToRoman(int num) {
	char a[] = { 'I','V','X','L','C','D','M' };
	int i = 0;
	string ret = "";
	while (num) {
		int t = num % 10;
		num /= 10;
		switch (t)
		{
		case 1:
			ret = a[i] + ret;
			break;
		case 2:
			ret =a[i] + ret;
			ret = a[i] + ret;
			break;
		case 3:
			ret = a[i] + ret;
			ret = a[i] + ret;
			ret = a[i] + ret;
			break;
		case 4:
			ret = a[i + 1] + ret;
			ret = a[i] + ret;
			break;
		case 5:
			ret = a[i + 1] + ret;
			break;
		case 6:
			ret = a[i] + ret;
			ret = a[i + 1] + ret;
			break;
		case 7:
			ret = a[i] + ret;
			ret = a[i] + ret;
			ret = a[i + 1] + ret;
			break;
		case 8:
			ret = a[i] + ret;
			ret = a[i] + ret;
			ret = a[i] + ret;
			ret = a[i + 1] + ret;
			break;
		case 9:
			ret = a[i + 2] + ret;
			ret = a[i] + ret;
			break;
		default:
			break;
		}
		i += 2;
	}
	return ret;
}

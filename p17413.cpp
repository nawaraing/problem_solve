#include <iostream>

using namespace std;

int		main(void)
{
	string		str;
	int		len;

	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			if (i != 0) {
				int	j = i - 1;
				while (str[j] != ' ' && str[j] != '>' && j >= 0) cout << str[j--];
			}
			while (str[i] != '>') cout << str[i++];
			cout << str[i];
		}
		if (str[i] == ' ') {
			int	j = i - 1;
			while (str[j] != ' ' && str[j] != '>' && j >= 0) cout << str[j--];
			cout << " ";
		}
	}
	len = str.length() - 1;
	while (str[len] != ' ' && str[len] != '>' && len >= 0) cout << str[len--];
	return (0);
}

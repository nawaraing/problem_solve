#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int		space, alpha[26];
string	poem;
int		flag = 0;
string	jemok;

int		is_capital(char c)
{
	if ('A' <= c && c <= 'Z') return (1);
	return (0);
}


int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, poem);
	// cout << poem << "\n";
	cin >> space;
	for (int i = 0; i < 26; i++)
		cin >> alpha[i];
	for (int i = 0; i < poem.size(); i++)
	{
		// cout << "poem[ " << i << " ] : " << poem[i] << "\n";
		if (i != 0 && poem[i] == poem[i - 1]) continue ;
		if (i == 0 || (poem[i - 1] == ' ' && poem[i] != ' ')) {
			jemok.push_back(poem[i]);
		} 
		if (poem[i] == ' ') {
			space--;
			if (space < 0) {
				flag = 1;
				break;
			}
		}
		else if (is_capital(poem[i])) {
			alpha[(int)(poem[i] - 'A')]--;
			if (alpha[(int)(poem[i] - 'A')] < 0) {
				flag = 2;
				break ;
			}
		}
		else {
			alpha[(int)(poem[i] - 'a')]--;
			if (alpha[(int)(poem[i] - 'a')] < 0) {
				flag = 3;
				break ;
			}
		}
	}
	// cout << "space : " << space << "\n";
	// for (int i =0; i < 26; i++) cout << alpha[i] << " ";
	// cout << "\n";
	if (flag > 0) {
		// cout << flag<<"\n";
		cout << -1;
	}
	else {
		for (int i =0; i < jemok.size(); i++)
		{
			if (is_capital(jemok[i])) {
				alpha[(int)(jemok[i] - 'A')]--;
				if (alpha[(int)(jemok[i] - 'A')] < 0) {
					flag = 1;
					break ;
				}
			}
			else {
				alpha[(int)(jemok[i] - 'a')]--;
				if (alpha[(int)(jemok[i] - 'a')] < 0)
				{
					flag = 1;
					break ;
				}
				jemok[i] = (char)(jemok[i] - 'a' + 'A');
			}
		}
		if (flag) cout << -1;
		else cout << jemok;
	}
	return (0);
}
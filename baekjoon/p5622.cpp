#include <iostream>
#include <map>

/*
* Problem
*     오래된 다이얼 전화기가 있다.
*     번호 하나를 눌러서 돌리고 다시 되돌아가는데 시간이 소요된다
*     1번은 2초가 소요되고, 번호가 1씩 커질 때마다 1초씩 추가로 소요된다
*     전화번호가 숫자가 아닌 대응된 알파벳으로 주어졌을 때,
*     해당 전화번호를 다 누르는데 소요되는 시간을 출력하여라
*
* Ideas
*     알파벳과 숫자를 map으로 대응시켜놓고, 문제를 풀자
*     모든 번호를 더한 후, 알파벳의 갯수만큼 더하면 해당 전화번호를 누르는데 걸리는 시간이 된다
*
* Comments
*/

using namespace std;

int main() {
	map<char, int> mp;
	mp['A']=2 ; mp['B']=2 ; mp['C']=2 ;
	mp['D']=3 ; mp['E']=3 ; mp['F']=3 ;
	mp['G']=4 ; mp['H']=4 ; mp['I']=4 ;
	mp['J']=5 ; mp['K']=5 ; mp['L']=5 ;
	mp['M']=6 ; mp['N']=6 ; mp['O']=6 ;
	mp['P']=7 ; mp['Q']=7 ; mp['R']=7 ; mp['S']=7 ;
	mp['T']=8 ; mp['U']=8 ; mp['V']=8 ;
	mp['X']=9 ; mp['W']=9 ; mp['Y']=9 ; mp['Z']=9 ;

	string	str;
	int		spend;

	cin >> str;
	spend += str.length();
	for (int i=0 ; i<str.length() ; i++) spend += mp[str[i]];
	cout << spend;
}
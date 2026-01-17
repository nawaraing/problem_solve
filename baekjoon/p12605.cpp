#include <iostream>
#include <stack>

using namespace std;

int n, found;
stack<string> st;
string line;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	// 버리기
	getline(cin, line);
	
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		while (true) {
			found = line.find(' ', 0);
			if (found == std::string::npos) {
				st.push(line);
				break;
			}
			st.push(line.substr(0, found));
			line = line.substr(found + 1);
		}

		// 출력부
		cout << "Case #" << i + 1 << ": ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}

}
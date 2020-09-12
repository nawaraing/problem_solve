#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> ans;
    
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)(v.size()) - 1; i++) {
        for (int j = i + 1; j < (int)(v.size()); j++) {
            if (v[i] + v[j] == ans.back()) continue ;
            ans.push_back(v[i] + v[j]);
        }
    }
    
    return ans;
}

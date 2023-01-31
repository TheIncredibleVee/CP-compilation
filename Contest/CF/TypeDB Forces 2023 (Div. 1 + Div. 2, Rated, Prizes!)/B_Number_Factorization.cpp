#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int res = 0;
        int temp = n;
        int maxi = 1;
        map<int, int> m;
        for(int i = 2; i <= sqrt(n); ++i)
        {
            if(temp % i == 0)
            {
                int c = 0;
                while(!(temp % i))
                {
                    c++;
                    temp /= i;
                }
                m[i] = c;
                maxi = max(c, maxi);
            }
        }
        if(temp != 1)
        {
            m[temp] = 1;
        }
        for(int i = 0; i < maxi; i++)
        {
            int count = 1;
            for(auto it : m)
            {
                if(it.second > 0)
                {
                    m[it.first] -= 1;
                    count *= it.first;
                }
            }
            res += count;
        }
        cout << res << endl;
    }

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> jimu_sum(vector<int> &blocks)
{
    vector<int> stk;
    for (int block : blocks)
    {
        stk.push_back(block);
        while (true)
        {
            bool merged = false;
            if (stk.back() == stk[stk.size() - 2])
            {
                int temp = stk.back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back(2 * temp);
                merged = true;
            }
            else
            {
                int total = 0;
                for (int i = stk.size() - 2; i >= 0; i--)
                {
                    total += stk[i];
                    if (total == stk.back())
                    {
                        int val = stk.back();
                        stk.erase(stk.begin() + i, stk.end());
                        stk.push_back(val * 2);
                        merged = true;
                        break;
                    }
                    else if (total > stk.back())
                    {
                        break;
                    }
                }
            }
            if (!merged)
                break;
        }
    }
    reverse(stk.begin(), stk.end());
    return stk;
}

int main()
{

    system("pause");
    return 0;
}

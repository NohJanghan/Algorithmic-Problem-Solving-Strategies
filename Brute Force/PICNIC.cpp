// PICNIC
#include <iostream>
using namespace std;

int friends;
bool isFriend[10][10] = {0, };

int countCase(bool isGrouped[10]) {
    int res = 0, initial = -1;
    for (int i = 0; i < friends; i++)
    {
        if(!isGrouped[i]) {
            initial = i;
            break;
        }
    }

    //기저사례: 모두 짝지어졌다면 1을 반환
    if(initial == -1) return 1;

    for (int i = initial + 1; i < friends; i++)
    {
        if(isFriend[initial][i] && !isGrouped[i]) {
            isGrouped[initial] = isGrouped[i] = true;
            res += countCase(isGrouped);
            
            isGrouped[initial] = isGrouped[i] = false;
        }
    }
    
    return res;
}

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int groupsNum;
        cin >> friends >> groupsNum;

        fill_n(&isFriend[0][0], 100, 0);
        for (int i = 0; i < groupsNum; i++)
        {
            int a, b;
            cin >> a >> b;
            isFriend[a][b] = true;
            isFriend[b][a] = true;
        }

        bool group[10] = {0, };
        cout << countCase(group) << endl;
        
    }
    

    return 0;
}
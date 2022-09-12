// BOGGLE
// 완전탐색으로 구현하여 TLE
// 예제는 통과
#include <iostream>
using namespace std;

char board[5][6] = {0, };
const int dyList[8] = {1, 0, -1, 1, -1, 1, 0, -1};
const int dxList[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool isInBoard(int y, int x) {
    if(y >= 0 && y <= 4 && x >= 0 && x <= 4) return true;
    else return false;
}

bool hasWord(const int y, const int x, const string& word) {
    if(!isInBoard(y, x)) return false;
    else if(board[y][x] != word[0]) return false;
    else if(word.length() <= 1) return true;

    for (int i = 0; i < 8; i++)
    {
        int nextY = y + dyList[i];
        int nextX = x + dxList[i];

        if(hasWord(nextY, nextX, word.substr(1))) return true;
    }
    return false;
}

bool isWordInBoard(const string& word) {
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if(hasWord(y, x, word)) return true;
        }
    }

    return false;
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%s", board[j]);
        }
        int wordCount;
        cin >> wordCount;
        
        string word;
        for (int i = 0; i < wordCount; i++)
        {
            cin >> word;
            cout << word << " " << (isWordInBoard(word) ? "YES" : "NO") << endl;
        }        
    }
    
    return 0;
}
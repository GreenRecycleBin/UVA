#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int MAX_SIZE = 50;

typedef pair<int, int> Position;
typedef set<Position> Positions;
typedef map<char, Positions> PositionMap;
typedef vector<vector<char> > Grid;

PositionMap HashPosition(const Grid &grid);
Position Find(const string &s, const Grid &grid, const PositionMap &position);
void PrintPosition(const Position&);

int main() {
    int n;
    scanf("%d", &n);

    while (n > 0) {
        int row, column;
        scanf("%d %d", &row, &column);

        Grid grid(row, vector<char>(column));

        getchar();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j)
                grid[i][j] = tolower(getchar());

            getchar();
        }

        PositionMap position = HashPosition(grid);

        int k;
        cin >> k;

        vector<string> words(k);

        getchar();

        for (int i = 0; i < k; ++i) {
            getline(cin, words[i]);
            transform(words[i].begin(), words[i].end(), words[i].begin(),
                      ptr_fun<int, int>(tolower));
        }

        vector<Position> positions(k);

        for (int i = 0; i < k; ++i)
            positions[i] = Find(words[i], grid, position);

        for_each(positions.begin(), positions.end(), PrintPosition);

        if (--n > 0) putchar('\n');
    }
}

PositionMap HashPosition(const Grid &grid) {
    if (grid.empty()) return PositionMap();

    int row = grid.size();
    int column = grid[0].size();

    PositionMap position;

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            position[grid[i][j]].insert(make_pair(i, j));

    return position;
}

Position Find(const string &s, const Grid &grid, const PositionMap &position) {
    if (s.empty()) return Position(-1, -1);

    const int MAX_ROW = grid.size();
    const int MAX_COLUMN = grid[0].size();

    Positions::const_iterator start = position.find(s[0])->second.begin();
    Positions::const_iterator end = position.find(s[0])->second.end();
    Positions::const_iterator previous = end;

    while (start != end && start != previous) {
        int row = start->first;
        int column = start->second;

        previous = start;

        switch(1) {
            int i;
            // up
        case 1:
            if (s.size() - 1 <= row)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row - i][column] != s[i])
                        break;

            if (i == s.size()) break;

            // down
        case 2:
            if (row + s.size() - 1 <= MAX_ROW)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row + i][column] != s[i])
                        break;

            if (i == s.size()) break;

            // left
        case 3:
            if (s.size() - 1 <= column)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row][column - i] != s[i])
                        break;

            if (i == s.size()) break;

            // right
        case 4:
            if (column + s.size() - 1 <= MAX_COLUMN)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row][column + i] != s[i])
                        break;

            if (i == s.size()) break;

            // up left
        case 5:
            if (s.size() - 1 <= row && s.size() - 1 <= column)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row - i][column - i] != s[i])
                        break;

            if (i == s.size()) break;

            // up right
        case 6:
            if (s.size() - 1 <= row && column + s.size() - 1 <= MAX_COLUMN)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row - i][column + i] != s[i])
                        break;

            if (i == s.size()) break;

            // down left
        case 7:
            if (row + s.size() - 1 <= MAX_ROW && s.size() - 1 <= column)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row + i][column - i] != s[i])
                        break;

            if (i == s.size()) break;

            // down right
        case 8:
            if (row + s.size() - 1 <= MAX_ROW &&
                column + s.size() - 1 <= MAX_COLUMN)
                for (i = 0; i < s.size(); ++i)
                    if (grid[row + i][column + i] != s[i])
                        break;

            if (i == s.size()) break;

            // no match
        default:
            ++start;
        }
    }

    if (start != end) return *start;

    return Position(-1, -1);
}

void PrintPosition(const Position &position) {
    printf("%d %d\n", position.first + 1, position.second + 1);
}

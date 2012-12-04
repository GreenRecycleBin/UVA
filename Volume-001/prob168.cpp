#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef map<char, vc> mcvc;
typedef map<char, bool> mcb;
typedef stack<char> sc;

mcvc adj_list;

void Solve(char minotaur_location, char theseus_location, int k)
{
  sc s;
  mcb is_visited;
  int step = 0;

  s.push(minotaur_location);

  while (!s.empty()) {

    minotaur_location = s.top();
    s.pop();

    if (step > 0 && step % k == 0) {
      is_visited[theseus_location] = true;
      printf("%c ", theseus_location);
      step = 0;
    }


    for (int i = 0; i < adj_list[minotaur_location].size(); ++i) {
      if (!is_visited[adj_list[minotaur_location][i]] &&
          adj_list[minotaur_location][i] != theseus_location) {
        s.push(adj_list[minotaur_location][i]);
        theseus_location = minotaur_location;
        ++step;

        break;
      }
    }
  }

  printf("/%c\n", minotaur_location);
}

int main()
{
  string line, token;
  char minotaur_location, theseus_location;
  int i = 0, k;

  while (cin >> line && line != "#") {
    stringstream ss(line);

    switch (i) {
      case 0:
        while (getline(ss, token, ';')) {
          size_t index = token.find_last_of(':'), size = token.size();
          char current_location = token[index - 1];

          if (token[size - 1] == '.') --size;

          for (int j = index + 1; j < size; ++j)
            adj_list[current_location].push_back(token[j]);
        }

        break;

      case 1:
        ss >> minotaur_location;

        break;

      case 2:
        ss >> theseus_location;

        break;

      case 3:
        ss >> k;

        break;
    }

    if (++i == 4) {
      Solve(minotaur_location, theseus_location, k);

      i = 0;
      adj_list = mcvc();
    }
  }

  return 0;
}

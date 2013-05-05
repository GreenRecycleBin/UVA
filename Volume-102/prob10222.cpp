#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

static map<char, char> decode;

int main()
{
    decode['='] = '0';
    decode['-'] = '9';
    decode['0'] = '8';
    decode['9'] = '7';
    decode['8'] = '6';
    decode['7'] = '5';
    decode['6'] = '4';
    decode['5'] = '3';
    decode['4'] = '2';
    decode['3'] = '1';

    decode['\\'] = '[';
    decode[']'] = 'p';
    decode['['] = 'o';
    decode['p'] = 'i';
    decode['o'] = 'u';
    decode['i'] = 'y';
    decode['u'] = 't';
    decode['y'] = 'r';
    decode['t'] = 'e';
    decode['r'] = 'w';
    decode['e'] = 'q';

    decode['\''] = 'l';
    decode[';'] = 'k';
    decode['l'] = 'j';
    decode['k'] = 'h';
    decode['j'] = 'g';
    decode['h'] = 'f';
    decode['g'] = 'd';
    decode['f'] = 's';
    decode['d'] = 'a';

    decode['/'] = ',';
    decode['.'] = 'm';
    decode[','] = 'n';
    decode['m'] = 'b';
    decode['n'] = 'v';
    decode['b'] = 'c';
    decode['v'] = 'x';
    decode['c'] = 'z';

    decode['\n'] = '\n';
    decode[' '] = ' ';

    char c;

    while(cin.get(c))
	putchar(decode[tolower(c)]);

    return 0;
}

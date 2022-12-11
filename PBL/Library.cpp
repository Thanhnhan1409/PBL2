#define _CRT_SECURE_NO_WARNINGS
#include"Library.h"
void Library::printLineColor(string line, int color_code)
{
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, color_code);
    cout << line;
    SetConsoleTextAttribute(color, 7);
}

void Library::printError(string status)
{
    printLineColor("ERROR ", 67);
    printLineColor(status, 4);
    cout << "\n";
}

void Library::printSuccess(string status)
{
    printLineColor("SUCCESS ", 37);
    printLineColor(status, 2);
    cout << "\n";
}
string Library::passwdIO()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    string input;
    getline(cin, input);
    SetConsoleMode(hStdin, mode);
    return input;
}
string Library::gettime()
{
    {
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d%m%Y%H%M%S", timeinfo);
        string str(buffer);
        return str;
    }
}
int Library::fail(string line) {
    int x;
    while (cin.fail())
    {
        Library::printError("Number please!");
        cin.clear();
        cin.ignore(32767, '\n');
        cout << line << ": ";
        cin >> x;
    }
    return x;
}
string Library::printRevenues(long long k, string symbol) {
    int l, c, i;
    string fin, s, u, rev;
    bool min = false;
    fin = "";
    c = 0;
    if (k < -999) {
        k *= -1;
        min = true;
    }
    s = to_string(k);
    if (k > 999) {
        l = s.length() - 1;
        for (i = l; i >= 0; i--) {
            fin += s[i];
            c++;
            if (c % 3 == 0) {
                fin += symbol;
            }
        }
        rev = fin;
        fin = "";
        l = rev.length() - 1;
        for (i = l; i >= 0; i--) {
            fin += rev[i];
        }
        u = fin[0];
        if (u == symbol) {
            fin.erase(fin.begin());
        }
        if (min) {
            fin.insert(0, "-");
        }
        return fin;
    }
    else {
        return s;
    }
}
void  Library::Toupper(char str[]) {
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
}
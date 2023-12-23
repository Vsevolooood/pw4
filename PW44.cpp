#include <iostream>
#include <string>
#include <cctype>

using namespace std;
    
void find(string symbol){
    cout << endl;
    char m[]{ '.' , '-', ',' , '!', '?', ';', ':', ' '};
    cout << "corect text:\n\n";
    for (int i = 0; i < symbol.length(); i++)
    {
        if (symbol[i] == m[7] && symbol[i] == symbol[i + 1] || symbol[i] == m[6] && symbol[i] == symbol[i + 1] || symbol[i] == m[5] && symbol[i] == symbol[i + 1] || symbol[i] == m[4] && symbol[i] == symbol[i + 1] || symbol[i] == m[2] && symbol[i] == symbol[i + 1] || symbol[i] == m[1] && symbol[i] == symbol[i + 1] || symbol[i] == m[0] && symbol[i] == symbol[i + 1] || symbol[i] == m[3] && symbol[i] == symbol[i + 1])
        {
            symbol.erase(i, 1);
        }
        if (isupper(symbol[i]) && isupper(symbol[i + 1]) || (islower(symbol[i]) && isupper(symbol[i + 1])))
        {
            symbol[i + 1] = tolower(symbol[i + 1]);
        }
        
        cout << symbol[i];
    }
    cout << endl << endl;
}

//задание 3 вариант 1
void revers(string task3) {
    cout << endl;
    int i, k, a = 0, dl = 0;
    cout << "revers string:\n";
    dl = task3.length();
    for (i = dl; i >= 0; i--) {
        if (task3[i] == ' ') {
            for (k = i + 1; k <= (i + a); k++) {
                cout << task3[k];
            }
            a = 0;
            cout << " ";
        }

        a++;
    }

    for (int i = 0; i < dl; i++) {
        if (task3[i] == ' ') break;
        cout << task3[i];
    }
    cout << "\n\n";
}

//задание 4 - 6
void task4(string task4) {
    cout << endl;
    cout << "vertical text:\n";
    char separator  = ' ';
    int i = 0;
    string s;
    while (task4[i] != '\0') {
        if (task4[i] != separator) {
            s += task4[i];
        }
        else {
            cout << s << endl;
            s.clear();
        }
        i++;
    }
    cout << s << endl << endl;
}

void linearSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++) 
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) 
        {
            cout << "Pattern found at index " << i << endl;
        }
    }

}

void badCharHeuristic(string str, int size,
    int badchar[256])
{
    int i;
    for (i = 0; i < 256; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int badchar[256];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            cout << "Pattern found at index: " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}
 
int main(){
	setlocale (LC_ALL, "0");
    string e; 
    string target;
    cout << "Please, enter 50 words:\n";
    string* text = NULL;
    getline(cin, e);
    if (e.length() < 600) {
        system("cls");
        cout << e << endl;
    }
    if (e.length() > 600) {
        system("cls");
        cout << "error\n" << "Enter again:\n";
    }
    int a;
    bool f = true;
    while (f) {
        cout << "choose task\n";
        cout << "1. corect text\n";
        cout << "2. revers\n";
        cout << "3. vertical text task\n";
        cout << "4. BoeraMura\n";
        cout << "5. exit\n";
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            find(e);
            system("pause");
            break;
        case 2:
            system("cls");
            revers(e);
            system("pause");
            break;
        case 3:
            system("cls");
            task4(e);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "please enter pattern:\n";
            cin.ignore();
            getline(cin, target);
            cout << "linearSearch:\n";
            linearSearch(e, target);
            system("pause");
            cout << "Moor:\n";
            search(e, target);
            system("pause");
            break;
        case 5:
            f = false;
        }
    }
}
#include <bits/stdc++.h>
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "SymbolTable.h"
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char op;
    int n;
    bool flag;
    cin >> n;
    SymbolTable table(n);

    while(cin >> op){
        if(op == 'I'){
            string name, type;
            cin >> name >> type;
            cout << op << " " << name << " " << type << "\n\n";
            flag = table.Insert(name,type);
            cout << endl;
        }
        else if(op == 'S'){
            cout << op << "\n\n";
            table.EnterScope();
            cout << endl;
        }
        else if(op == 'E'){
            cout << op << "\n\n";
            table.ExitScope();
            cout << endl;
        }
        else if(op == 'L'){
            string name;
            cin >> name;
            cout << op << " " << name << "\n\n";
            table.LookUp(name);
            cout << endl;
        }
        else if(op == 'D'){
            string name;
            cin >> name;
            cout << op << " " << name << "\n\n";
            flag = table.Remove(name);
            cout << endl;
        }
        else if(op == 'P'){
            char op1;
            cin >> op1;
            cout << op << " " << op1 << "\n\n\n";
            if(op1 == 'A')
                table.printAllScopeTable();
            else if(op1 == 'C')
                table.printCurrentScopeTable();
            cout << endl;
        }
    }
    return 0;
}

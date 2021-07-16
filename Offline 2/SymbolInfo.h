#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H
#include<bits/stdc++.h>
using namespace std;

class SymbolInfo
{
    private:
        string name;
        string type;
        SymbolInfo* nextsymbol;
    public:
        SymbolInfo();
        virtual ~SymbolInfo();
        void setName(string name);
        string getName();
        void setType(string type);
        string getType();
        void setNext(SymbolInfo* nextsymbol);
        SymbolInfo* getNext();

    protected:


};

#endif // SYMBOLINFO_H

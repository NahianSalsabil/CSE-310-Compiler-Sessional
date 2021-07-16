#ifndef SCOPETABLE_H
#define SCOPETABLE_H
#include "SymbolInfo.h"
#include<bits/stdc++.h>
using namespace std;

class ScopeTable
{
    private:
        SymbolInfo** symbolinfo;
        int n, scopecount;
        ScopeTable* parentscope;
        string id;
    public:
        ScopeTable(int n);
        virtual ~ScopeTable();
        void setID();
        void setID(int i);
        string getID();
        void setScopeCount();
        int getScopeCount();
        void setParentScope(ScopeTable* parentscope);
        ScopeTable* getParentScope();
        int hashfunction(string key);
        bool Insert(string name,string type);
        SymbolInfo* LookUp(string name);
        bool Delete(string name);
        void print();



};

#endif // SYMBOLTABLE_H

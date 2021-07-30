#ifndef SCOPETABLE_H
#define SCOPETABLE_H
#include "SymbolInfo.h"
#include<bits/stdc++.h>
using namespace std;
//ofstream logout("1705091_log.txt");

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
        bool Insert(ofstream& logout, string name,string type);
        SymbolInfo* LookUp(ofstream& logout, string name);
        bool Delete(ofstream& logout, string name);
        void print(ofstream& logout);



};

#endif // SYMBOLTABLE_H

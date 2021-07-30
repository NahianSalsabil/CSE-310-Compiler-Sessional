#include "SymbolTable.h"

SymbolTable::SymbolTable(int n)
{
    this->n = n;
    curscopetable = nullptr;
    EnterScope();
}

SymbolTable::~SymbolTable()
{
    //logout << "shesh\n";
}

void SymbolTable::EnterScope(){
    ScopeTable* scopetable = new ScopeTable(n);
    if(curscopetable == nullptr){
        scopetable->setParentScope(curscopetable);
        curscopetable = scopetable;
        curscopetable->setID(1);
    }
    else{
        scopetable->setParentScope(curscopetable);
        curscopetable = scopetable;
        curscopetable->getParentScope()->setScopeCount();
        curscopetable->setID();
        //logout << "New ScopeTable with id " + curscopetable->getID() + " created\n";
    }
}

void SymbolTable::ExitScope(){
    ScopeTable* temp = curscopetable->getParentScope();
    //logout << "ScopeTable with id " + curscopetable->getID() + " removed\n";
    delete curscopetable;
    curscopetable = temp;
}

bool SymbolTable::Insert(string name, string type){
    if(curscopetable->Insert(logout,name,type))
        return true;
    return false;
}

SymbolInfo* SymbolTable::LookUp(string name){
    ScopeTable* temp = curscopetable;
    SymbolInfo* info;
    while(temp != nullptr){
        info = temp->LookUp(logout,name);
        if(info != nullptr)
            return info;
        temp = temp->getParentScope();
    }
    //logout << "Not found\n";
    return nullptr;
}

bool SymbolTable::Remove(string name){
    if(curscopetable->Delete(logout,name))
        return true;
    return false;
}

void SymbolTable::printAllScopeTable(){
    ScopeTable * temp = curscopetable;
    while(temp != nullptr){
        temp->print(logout);
        logout << endl;
        temp = temp->getParentScope();
    }
}

void SymbolTable::printCurrentScopeTable(){
    curscopetable->print(logout);
}



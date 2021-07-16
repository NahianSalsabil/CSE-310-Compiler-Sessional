#include "ScopeTable.h"

ScopeTable::ScopeTable(int n)
{
    parentscope = nullptr;
    scopecount = 0;
    this->n = n;
    symbolinfo = new SymbolInfo*[n];
    for(int i = 0; i < n; i++)
        symbolinfo[i] = nullptr;
    //logout << "banailam\n";
}

ScopeTable::~ScopeTable()
{
    for (int i = 0; i < n; i++)
    {
        delete symbolinfo[i];
    }
    delete[] symbolinfo;
    //logout << "dhongsho\n";
}

void ScopeTable::setID(){
    this->id = parentscope->getID()+"."+ to_string(parentscope->getScopeCount());
}

void ScopeTable::setID(int i){
    this->id = to_string(i);
}

string ScopeTable::getID(){
    if(parentscope == nullptr)
        return to_string(1);
    return this->id;
}

void ScopeTable::setParentScope(ScopeTable* parentscope){
    if(parentscope == nullptr){
        this->parentscope = nullptr;
    }
    else
        this->parentscope = parentscope;
}

ScopeTable* ScopeTable::getParentScope(){
    return this->parentscope;
}

void ScopeTable::setScopeCount(){
    this->scopecount++;
}

int ScopeTable::getScopeCount(){
    return this->scopecount;
}

int ScopeTable::hashfunction(string key){
    int sum = 0;
    for(int i = 0; i < key.length(); i++){
        sum += int(key[i]);
    }
    return sum%n;
}

bool ScopeTable::Insert(ofstream& logout, string name,string type){
    if(LookUp(logout, name) != nullptr){
        //logout << /* "<"  + */ name << /* "," << type */ +" already exists in current ScopeTable\n";
        //logout << endl;
        return false;
    }
    int position = 0;
    int index = hashfunction(name);
    SymbolInfo *symbol = new SymbolInfo;
    symbol->setName(name);
    symbol->setType(type);
    symbol->setNext(nullptr);
    if(symbolinfo[index] == nullptr){
        symbolinfo[index] = symbol;
        //logout << "Inserted in Scopetable# "+ getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
        return true;
    }
    else{
        SymbolInfo *temp1 = new SymbolInfo;
        SymbolInfo *temp2 = new SymbolInfo;
        temp1 = symbolinfo[index];
        temp2 = temp1->getNext();
        while(temp2!= nullptr){
            temp1 = temp2;
            temp2 = temp1->getNext();
            position++;
        }
        position++;
        temp2 = symbol;
        temp1->setNext(temp2);
        //logout << "Inserted in Scopetable# " + getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
        return true;
    }
    return false;
}

SymbolInfo* ScopeTable::LookUp(ofstream& logout, string name){
    int index;
    int position = 0;
    index = hashfunction(name);
    SymbolInfo *temp = nullptr;
    if(symbolinfo[index] == nullptr){
        return nullptr;
    }
    if(symbolinfo[index]->getName() == name){
        //logout << "Found in ScopeTable# " + getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
        return symbolinfo[index];
    }

    temp = symbolinfo[index]->getNext();
    while(temp!= nullptr){
            position++;
        if(temp->getName() == name){
            //logout << "Found in ScopeTable# " + getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

bool ScopeTable::Delete(ofstream& logout, string name){
    int index;
    int position = 0;
    index = hashfunction(name);
    SymbolInfo *temp1 = nullptr;
    SymbolInfo *temp2 = nullptr;
    if(symbolinfo[index] == nullptr){
        //logout << name + " Not Found\n";
        return false;
    }
    if(symbolinfo[index]->getName() == name){
        //logout << "Found in ScopeTable# " + getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
        if(symbolinfo[index]->getNext() != nullptr){
            symbolinfo[index] = symbolinfo[index]->getNext();
        }
        else{
            symbolinfo[index] = nullptr;
        }
        //logout << "Deleted Entry " + to_string(index) + ", " + to_string(position) + " from current ScopeTable\n";
        return true;
    }
    temp1 = symbolinfo[index];
    temp2 = symbolinfo[index]->getNext();
    while(temp2 != nullptr){
        position++;
        if(temp2->getName() == name){
            //logout << "Found in ScopeTable# " + getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
            temp1->setNext(temp2->getNext());
            //logout << "Deleted Entry " + to_string(index) + ", " + to_string(position) + " from current ScopeTable\n";
            return true;
        }
        temp1 = temp2;
        temp2 = temp2->getNext();
    }
    //logout << name + " Not Found\n";
    return false;
}

void ScopeTable::print(ofstream& logout){
    logout << "ScopeTable# " + getID() << endl;
    SymbolInfo *symbol = nullptr;
    for(int i = 0; i < n; i++){
        if(symbolinfo[i] != nullptr){
            symbol = symbolinfo[i];
            logout << i << " -->";
            while(symbol != nullptr){
                logout << "  < " << symbol->getName() << " : " << symbol->getType() << " >";
                symbol = symbol->getNext();
            }
            logout << endl;
        }

    }
}

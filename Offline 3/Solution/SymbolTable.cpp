#include<bits/stdc++.h>
using namespace std;



class SymbolInfo
{
    private:
        string name;
        string type;
        string variable_type;
        string which_variable;
        bool defined;
        SymbolInfo* nextsymbol;
        vector<string> param_type;
    public:
        
    SymbolInfo()
    {
       // cout << "created\n";
    }

    ~SymbolInfo()
    {
    }

    void setName(string name){
        this->name = name;
    }

    string getName(){
        return this->name;
    }

    void setType(string type){
        this->type = type;
    }


    string getType(){
        return this->type;
    }

    void setVariableType(string variable_type){
        this->variable_type = variable_type;
    }


    string getVariableType(){
        return this->variable_type;
    }

    void setWhichVariable(string which_variable){
        this->which_variable = which_variable;
    }


    string getWhichVariable(){
        return this->which_variable;
    }

    void setDefined(bool defined){
        this->defined = defined;
    }

    bool getDefined(){
        return this->defined;
    }

    void setParamType(string param_type){
        this->param_type.push_back(param_type);
    }

    string getParamType(int i){
        return this->param_type.at(i);
    }

    int getParamSize(){
        return param_type.size();
    }

    void setNext(SymbolInfo* nextsymbol){
        this->nextsymbol = nextsymbol;
    }

    SymbolInfo* getNext(){
        return this->nextsymbol;
    }

};

class ScopeTable
{
    private:
        SymbolInfo** symbolinfo;
        int n, scopecount;
        ScopeTable* parentscope;
        string id;
    public:


    ScopeTable(int n)
    {
        parentscope = nullptr;
        scopecount = 0;
        this->n = n;
        symbolinfo = new SymbolInfo*[n];
        for(int i = 0; i < n; i++)
            symbolinfo[i] = nullptr;
    }

    ~ScopeTable()
    {
        for (int i = 0; i < n; i++)
        {
            delete symbolinfo[i];
        }
        delete[] symbolinfo;
//        cout << "dhongsho\n";
    }

    void setID(){
        this->id = parentscope->getID()+"."+ to_string(parentscope->getScopeCount());
    }

    void setID(int i){
        this->id = to_string(i);
    }

    string getID(){
        if(parentscope == nullptr)
            return to_string(1);
        return this->id;
    }

    void setParentScope(ScopeTable* parentscope){
        if(parentscope == nullptr){
            this->parentscope = nullptr;
        }
        else
            this->parentscope = parentscope;
    }

    ScopeTable* getParentScope(){
        return this->parentscope;
    }

    void setScopeCount(){
        this->scopecount++;
    }

    int getScopeCount(){
        return this->scopecount;
    }

    int hashfunction(string key){
        int sum = 0;
        for(int i = 0; i < key.length(); i++){
            sum += int(key[i]);
        }
        return sum%n;
    }

    bool Insert(ofstream & logout, string name, string type,string variable_type, string which_variable){
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
        symbol->setVariableType(variable_type);
        symbol->setWhichVariable(which_variable);
        symbol->setNext(nullptr);
        if(symbolinfo[index] == nullptr){
            symbolinfo[index] = symbol;
            //cout << "Inserted in Scopetable# "+ getID() + " at position " + to_string(index) + ", " + to_string(position) << endl;
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

    SymbolInfo* LookUp(ofstream& logout, string name){
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

    bool Delete(ofstream& logout, string name){
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

    void print(ofstream& logout){
        logout << "ScopeTable# " + getID() << endl;
        SymbolInfo *symbol = nullptr;
        for(int i = 0; i < n; i++){
            if(symbolinfo[i] != nullptr){
                symbol = symbolinfo[i];
                logout << i << " -->";
                while(symbol != nullptr){
                    logout << "  < " << symbol->getName() << " , " << symbol->getType() << " >";
                    symbol = symbol->getNext();
                }
                logout << endl;
            }

        }
    }



};

class SymbolTable
{
    private:
        ScopeTable* curscopetable;
        int scopecount;
        int n;
    public:


    SymbolTable(ofstream & logout, int n)
    {
        this->n = n;
        curscopetable = nullptr;
        EnterScope(logout);
    }

    ~SymbolTable()
    {
        //cout << "shesh\n";
    }

    void EnterScope(ofstream & logout){
        ScopeTable* scopetable = new ScopeTable(n);
        if(curscopetable == nullptr){
            scopetable->setParentScope(curscopetable);
            curscopetable = scopetable;
            curscopetable->setID(1);
            //cout << "New ScopeTable with id " + curscopetable->getID() + " created\n";
        }
        else{
            scopetable->setParentScope(curscopetable);
            curscopetable = scopetable;
            curscopetable->getParentScope()->setScopeCount();
            curscopetable->setID();
            //logout << "New ScopeTable with id " + curscopetable->getID() + " created\n";
        }
    }

    void ExitScope(ofstream & logout){
        ScopeTable* temp = curscopetable->getParentScope();
        //logout << "ScopeTable with id " + curscopetable->getID() + " removed\n";
        delete curscopetable;
        curscopetable = temp;
    }

    bool Insert(ofstream & logout, string name, string type, string variable_type, string which_variable){
        if(curscopetable->Insert(logout,name, type, variable_type, which_variable)){
            return true;
        }
        return false;
    }

    SymbolInfo* LookUp(ofstream& logout, string name){
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

    bool Remove(ofstream& logout, string name){
        if(curscopetable->Delete(logout,name))
            return true;
        return false;
    }

    void printAllScopeTable(ofstream& logout){
        ScopeTable * temp = curscopetable;
        while(temp != nullptr){
            temp->print(logout);
            logout << endl;
            temp = temp->getParentScope();
        }
    }

    void printCurrentScopeTable(ofstream& logout){
        curscopetable->print(logout);
    }

};


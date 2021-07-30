%{
#include<bits/stdc++.h>
#include"SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
ofstream errorout;
ofstream logout;
int line_count = 1;
int error_count = 0;

SymbolTable symboltable(logout, 30); 
string type;

void yyerror(char *s){
	logout << "Error at line " << line_count << ": Syntax Error\n";
	errorout << "Error at line " << line_count << ": Syntax Error\n";
	error_count++;
}

%}

%union{
	vector<SymbolInfo*>* vectorsymbol;
	SymbolInfo *symbol;
}


%token<symbol> IF ELSE FOR WHILE DO INT CHAR FLOAT VOID RETURN CONTINUE  NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD PRINTLN
%token<symbol>  COMMA SEMICOLON ADDOP MULOP INCOP DECOP LOGICOP RELOP ASSIGNOP
%token<symbol> ID CONST_INT CONST_FLOAT


%type<symbol> type_specifier
%type<vectorsymbol> declaration_list var_declaration func_declaration parameter_list unit factor unary_expression term simple_expression rel_expression logic_expression expression variable expression_statement arguments argument_list statement statements compound_statement func_definition program 

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
start : program{
			logout << "Line " << line_count-1 << ": start : program\n\n";
		}
	;

program : program unit 
	{	$$ = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : program unit\n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
				logout << " ";
			if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
				logout << "\n";
		}
		for(int i = 0; i < $2->size(); i++){
			logout << $2->at(i)->getName();
			$$->push_back($2->at(i));
			if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
				logout << " ";
			if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	}
	| unit
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : unit \n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
				logout << " ";
			if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	}
	; 
	
unit : var_declaration
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": unit : var_declaration\n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	}
     | func_declaration
     {
     		$$ = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_declaration\n\n";
     		for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void")
					logout << " ";
			}
		logout << "\n\n"; 
     }
     | func_definition
     {
     		$$ = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_definition\n\n";
     		for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					logout << " ";
				if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					logout << "\n";
			}
		logout << "\n\n"; 
     }
     ; 
 
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, $2->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				error_count++;
			}
			vector<string> param_name;       // Multiple declaration of parameter
			for(int i = 0; i < $4->size(); i++){  
				if($4->at(i)->getType() == "ID"){
					param_name.push_back($4->at(i)->getName());
					for(int j = 0; j < param_name.size()-1; j++){
						if($4->at(i)->getName() == param_name.at(j)){
							param_name.pop_back();
							logout << "Error at line " << line_count << ": Multiple declaration of " << $4->at(i)->getName() << " in parameter\n\n";
							errorout << "Error at line " << line_count << ": Multiple declaration of " << $4->at(i)->getName() << " in parameter\n\n";
							error_count++;
						}
					}
				}
			}
			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, $2->getName(),"ID",$1->getType(), "func");
			//---------------//

			// store parameter type sequentially
			if(inserted){   
				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());
				for(int i = 0; i < $4->size(); i++){
					if($4->at(i)->getType() == "INT" || $4->at(i)->getType() == "FLOAT" || $4->at(i)->getType() == "VOID")
						temp->setParamType($4->at(i)->getType());
				}
			}
			//----------//

			logout << $1->getName() << " " << $2->getName() << $3->getName();
			$$->push_back($1);
			$$->push_back($2);
			$$->push_back($3);

			for(int i = 0; i < $4->size(); i++){
				logout << $4->at(i)->getName();
				$$->push_back($4->at(i));
				if($4->at(i)->getName() == "int" || $4->at(i)->getName() == "float" || $4->at(i)->getName() == "void")
					logout << " ";
			}
			logout << $5->getName() << $6->getName() << "\n\n";
			$$->push_back($5);
			$$->push_back($6);
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON{
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, $2->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				error_count++;
			}
			//----------//

			logout << $1->getName() << " " << $2->getName() << $3->getName() << $4->getName() << $5->getName() << "\n\n";
			$$ = new vector<SymbolInfo*>();
			$$->push_back($1);
			$$->push_back($2);
			$$->push_back($3);
			$$->push_back($4);
			$$->push_back($5);

			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, $2->getName(),"ID",$1->getType(), "func");
			//---------------//
		}
		; 
	 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
				if(symboltable.LookUp(logout, $2->getName()) == nullptr)
					bool inserted = symboltable.Insert(logout, $2->getName(),"ID",$1->getType(), "func");
				
				//semantic error-----------//
				else if((symboltable.LookUp(logout, $2->getName()))->getWhichVariable() != "func"){
					logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					error_count++;
				}
				else if((symboltable.LookUp(logout, $2->getName()))->getDefined()){     // Function Already Defined
					logout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
					errorout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
					error_count++;
				}
				else if(!(symboltable.LookUp(logout, $2->getName()))->getDefined()){        // Return type doesn't match with declaration
					(symboltable.LookUp(logout, $2->getName()))->setDefined(true);
					if((symboltable.LookUp(logout, $2->getName()))->getVariableType() != $1->getType()){
						logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
						error_count++;
					}
				}

				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());
				temp->setDefined(true);
				
				
				vector<string> param_name;       // Multiple declaration of parameter
				for(int i = 0; i < $4->size(); i++){  
					if($4->at(i)->getType() == "ID"){
						param_name.push_back($4->at(i)->getName());
						for(int j = 0; j < param_name.size()-1; j++){
							if($4->at(i)->getName() == param_name.at(j)){
								param_name.pop_back();
								logout << "Error at line " << line_count << ": Multiple declaration of " << $4->at(i)->getName() << " in parameter\n\n";
								errorout << "Error at line " << line_count << ": Multiple declaration of " << $4->at(i)->getName() << " in parameter\n\n";
								error_count++;
							}
						}
					}
				}
				//------------//

				symboltable.EnterScope(logout);
				
				for (int i = 0; i < $4->size(); i++){      // Insert parameter into symboltable
					if($4->at(i)->getType() == "ID"){
						if($4->at(i-1)->getType() == "INT")
							bool inserted = symboltable.Insert(logout, $4->at(i)->getName(),"ID", "INT","var");
						else if($4->at(i-1)->getType() == "FLOAT")
							bool inserted = symboltable.Insert(logout, $4->at(i)->getName(),"ID", "FLOAT", "var");
						else if($4->at(i-1)->getType() == "VOID")
							bool inserted = symboltable.Insert(logout, $4->at(i)->getName(),"ID", "VOID", "var");
					}
				}
				
				if(temp->getParamSize() == 0){       // store parameter type sequentially
					for(int i = 0; i < $4->size(); i++){
					if($4->at(i)->getType() == "INT" || $4->at(i)->getType() == "FLOAT" || $4->at(i)->getType() == "VOID")
						temp->setParamType($4->at(i)->getType());
					}
				}
				else{          // function argument check with declaration
					vector<string> parameter_type;
					for(int i = 0; i < $4->size(); i++){
						if($4->at(i)->getType() == "INT" || $4->at(i)->getType() == "FLOAT" || $4->at(i)->getType() == "VOID"){
							parameter_type.push_back($4->at(i)->getType());
						}
					}
					if(parameter_type.size() != temp->getParamSize()){
						logout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << $2->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << $2->getName() << "\n\n";
						error_count++;
					} 
					else{
						for(int i = 0; i < temp->getParamSize(); i++){
							if(parameter_type.at(i) != temp->getParamType(i)){
								logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << $2->getName() <<"\n\n";
								errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << $2->getName() <<"\n\n";
								error_count++;
							}
						}
					}
				}
			} compound_statement { 
				symboltable.printAllScopeTable(logout);
				symboltable.ExitScope(logout);
			}
 		{
 			$$ = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << $1->getName() << " " << $2->getName() << $3->getName();
			$$->push_back($1);
			$$->push_back($2);
			$$->push_back($3);
			for (int i = 0; i < $4->size(); i++){
				logout << $4->at(i)->getName();
				$$->push_back($4->at(i));
				if($4->at(i)->getName() == "int" || $4->at(i)->getName() == "float" || $4->at(i)->getName() == "void")
					logout << " ";
			}
			logout << $5->getName();
			$$->push_back($5);
			for (int i = 0; i < $7->size(); i++){
				logout << $7->at(i)->getName();
				$$->push_back($7->at(i));
				if($7->at(i)->getName() == "int" || $7->at(i)->getName() == "float" || $7->at(i)->getName() == "void" || $7->at(i)->getName() == "return")
					logout << " ";
				if($7->at(i)->getName() == ";" || $7->at(i)->getName() == "{" || $7->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";
 		}
		| type_specifier ID LPAREN RPAREN {
				if(symboltable.LookUp(logout, $2->getName()) == nullptr)
					bool inserted = symboltable.Insert(logout, $2->getName(),"ID", $1->getType(), "func");
				
				//semantic error-----------//
				else{        // Return type doesn't match with declaration
					SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());
					if(temp->getVariableType() != $1->getType()){
						logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
						error_count++;
					}
				}
				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());  // Function Already Defined
				if(temp->getDefined()){
					logout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
					errorout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
					error_count++;
				}

				else
					temp->setDefined(true);
				
					
				//------------//

				symboltable.EnterScope(logout);
			}
			compound_statement {
				symboltable.printAllScopeTable(logout);
				symboltable.ExitScope(logout);
			}
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << $1->getName() << " " << $2->getName() << $3->getName() << $4->getName();
			$$->push_back($1);
			$$->push_back($2);
			$$->push_back($3);
			$$->push_back($4);
			for (int i = 0; i < $6->size(); i++){
				logout << $6->at(i)->getName();
				$$->push_back($6->at(i));
				if($6->at(i)->getName() == "int" || $6->at(i)->getName() == "float" || $6->at(i)->getName() == "void" || $6->at(i)->getName() == "return")
					logout << " ";
				if($6->at(i)->getName() == ";" || $6->at(i)->getName() == "{" || $6->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";
		}
 		;	


parameter_list  : parameter_list COMMA type_specifier ID
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier ID\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void")
					logout << " ";
			}
			logout << $2->getName() << $3->getName() << " " << $4->getName() << "\n\n"; 
			$$->push_back($2);
			$$->push_back($3);
			$$->push_back($4);
		}
		| parameter_list COMMA type_specifier
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << $2->getName() << $3->getName() << "\n\n";
			$$->push_back($2);
			$$->push_back($3);
		}
 		| type_specifier ID
 		{
 			logout << "line no " << line_count <<  ": parameter_list : type_specifier ID\n\n";
 			logout << $1->getName() << " " << $2->getName() << "\n\n";
 			$$ = new vector<SymbolInfo*>();
 			$$->push_back($1);
 			$$->push_back($2);
 		}
		| type_specifier
		{
			logout << "line no " << line_count <<  ": parameter_list : type_specifier\n\n";
			logout << $1->getName() << "\n\n";
			$$ = new vector<SymbolInfo*>();
			$$->push_back($1);
		}
 		; 


compound_statement : LCURL statements RCURL{
		    $$ = new vector<SymbolInfo*>();
		 	logout << "line no " << line_count <<  ": compound_statement : LCURL statements RCURL\n\n";
		 	logout << $1->getName() << "\n";
		 	$$->push_back($1);
		  	for(int i = 0; i < $2->size(); i++){
		  		$$->push_back($2->at(i));
		  		logout << $2->at(i)->getName();
				if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
					logout << " ";
				if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					logout << "\n";
		  	}
			logout << $3->getName() << "\n\n";
			$$->push_back($3);
		
		    }
 		    |LCURL RCURL
 		    {
 		    	$$ = new vector<SymbolInfo*>();
 		    	logout << "line no " << line_count <<  ": compound_statement : LCURL RCURL\n\n";
				logout << $1->getName() << $2->getName() << "\n\n";
				$$->push_back($1);
				$$->push_back($2);
 		    }
 		    ; 
     
var_declaration : type_specifier declaration_list SEMICOLON
		 {
		 	$$ = new vector<SymbolInfo*>();
		 	logout << "line no " << line_count <<  ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			
			// semantic error-----------//
			if($1->getType() == "VOID"){
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				error_count++;
			}
			//---------------//
		 	logout << $1->getName() << " ";
		 	$$->push_back($1);
		  	for(int i = 0; i < $2->size(); i++){
		  		$$->push_back($2->at(i));
		  		logout << $2->at(i)->getName();
		  	}
			
			logout << $3->getName() << "\n\n";
			$$->push_back($3);
		 }
 		 ;
	 
type_specifier : INT
		{
			logout << "line no " << line_count <<  ": type_specifier :  INT\n\n";
			logout << $1->getName() << "\n\n";
			$$ = $1;
			type = "INT";
		}
 
 		| FLOAT
 		{
 			logout << "line no " << line_count <<  ": type_specifier :  FLOAT\n\n";
			logout << $1->getName() << "\n\n";
			$$ = $1;
			type = "FLOAT";
 		}
 		| VOID
 		{
 			logout << "line no " << line_count <<  ": type_specifier :  VOID\n\n";
			logout << $1->getName() << "\n\n";
			$$ = $1;
			type = "VOID";
 		}
 		;

declaration_list : declaration_list COMMA ID
		  { 
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, $3->getName(),"ID",type,"var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << $3->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $3->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	$$ = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID\n\n";
		  	for(int i = 0; i < $1->size(); i++){
		  		$$->push_back($1->at(i));
		  		logout << $1->at(i)->getName();
		  	}
			logout << $2->getName() << $3->getName() << "\n\n";
			$$->push_back($2);
			$$->push_back($3);
		  }
		  |  declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, $3->getName(),"ID",type,"array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << $3->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $3->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	$$ = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n";
		  	for(int i = 0; i < $1->size(); i++){
		  		$$->push_back($1->at(i));
		  		logout << $1->at(i)->getName();
		  	}
			logout << $2->getName() << $3->getName() <<  $4->getName() << $5->getName() << $6->getName() << "\n\n";
			$$->push_back($2);
			$$->push_back($3);
			$$->push_back($4);
			$$->push_back($5);
			$$->push_back($6);
		  }
		  |  ID
 		  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")     // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, $1->getName(),"ID",type, "var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << $1->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $1->getName() << "\n\n";
				error_count++;
			}
			//--------//

			$$ = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID\n\n";
			logout << $1->getName() << "\n\n";
			$$->push_back($1);
 		  }
 		  | ID LTHIRD CONST_INT RTHIRD
 		  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, $1->getName(),"ID",type, "array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << $1->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $1->getName() << "\n\n";
				error_count++;
			}
			//--------//

 		  	$$ = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n";
 		  	logout << $1->getName() << $2->getName() << $3->getName() << $4->getName() << "\n\n";
 		  	$$->push_back($1);
 		  	$$->push_back($2);
 		  	$$->push_back($3);
 		  	$$->push_back($4);
 		  }
 		  ; 
 	  
statements : statement
	   {
		$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statement\n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
				logout << " ";
			if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	   }
	   | statements statement
	   {
	   	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statements statement\n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
				logout << " ";
			if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					logout << "\n";
		}
		for(int i = 0; i < $2->size(); i++){
			logout << $2->at(i)->getName();
			$$->push_back($2->at(i));
			if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
				logout << " ";
			if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	   }
	   ;
statement : var_declaration
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : var_declaration\n\n";
		for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
			if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	  }
	  | expression_statement
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : expression_statement\n\n";
	  	for(int i = 0; i < $1->size(); i++){
			logout << $1->at(i)->getName();
			$$->push_back($1->at(i));
		}
		logout << "\n\n";
	  }
	  |  {symboltable.EnterScope(logout);} compound_statement {symboltable.printAllScopeTable(logout); symboltable.ExitScope(logout);}
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : compound_statement\n\n";
	  	for(int i = 0; i < $2->size(); i++){
			logout << $2->at(i)->getName();
			$$->push_back($2->at(i));
			if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
				logout << " ";
			if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	  }
  	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
  	  {
  	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ":statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
	  	logout << $1->getName() << $2->getName();
	  	for(int i = 0; i < $3->size(); i++){
			logout << $3->at(i)->getName();
			$$->push_back($3->at(i));
		}
		for(int i = 0; i < $4->size(); i++){
			logout << $4->at(i)->getName();
			$$->push_back($4->at(i));
		}
		for(int i = 0; i < $5->size(); i++){
			logout << $5->at(i)->getName();
			$$->push_back($5->at(i));
		}
		logout << $6->getName();
		$$->push_back($6);
		for(int i = 0; i < $7->size(); i++){
			logout << $7->at(i)->getName();
			$$->push_back($7->at(i));
			if($7->at(i)->getName() == "int" || $7->at(i)->getName() == "float" || $7->at(i)->getName() == "void" || $7->at(i)->getName() == "return")
				logout << " ";
			if($7->at(i)->getName() == ";" || $7->at(i)->getName() == "{" || $7->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
  	  }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement\n\n";
	  	logout << $1->getName() << $2->getName();
	  	for(int i = 0; i < $3->size(); i++){
			logout << $3->at(i)->getName();
			$$->push_back($3->at(i));
		}
		logout << $4->getName();
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout << $5->at(i)->getName();
			$$->push_back($5->at(i));
			if($5->at(i)->getName() == "int" || $5->at(i)->getName() == "float" || $5->at(i)->getName() == "void" || $5->at(i)->getName() == "return")
				logout << " ";
			if($5->at(i)->getName() == ";" || $5->at(i)->getName() == "{" || $5->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
	  	logout << $1->getName() << $2->getName();
	  	for(int i = 0; i < $3->size(); i++){
			logout << $3->at(i)->getName();
			$$->push_back($3->at(i));
		}
		logout << $4->getName();
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout << $5->at(i)->getName();
			$$->push_back($5->at(i));
			if($5->at(i)->getName() == "int" || $5->at(i)->getName() == "float" || $5->at(i)->getName() == "void" || $5->at(i)->getName() == "return")
				logout << " ";
			if($5->at(i)->getName() == ";" || $5->at(i)->getName() == "{" || $5->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << $6->getName();
		$$->push_back($6);
		for(int i = 0; i < $7->size(); i++){
			logout << $7->at(i)->getName();
			$$->push_back($7->at(i));
			if($7->at(i)->getName() == "int" || $7->at(i)->getName() == "float" || $7->at(i)->getName() == "void" || $7->at(i)->getName() == "return")
				logout << " ";
			if($7->at(i)->getName() == ";" || $7->at(i)->getName() == "{" || $7->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
	  | WHILE LPAREN expression RPAREN statement
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : WHILE LPAREN expression RPAREN statement\n\n";
	  	logout << $1->getName() << $2->getName();
	  	for(int i = 0; i < $3->size(); i++){
			logout << $3->at(i)->getName();
			$$->push_back($3->at(i));
		}
		logout << $4->getName();
		$$->push_back($4);
		for(int i = 0; i < $5->size(); i++){
			logout << $5->at(i)->getName();
			$$->push_back($5->at(i));
			if($5->at(i)->getName() == "int" || $5->at(i)->getName() == "float" || $5->at(i)->getName() == "void" || $5->at(i)->getName() == "return")
				logout << " ";
			if($5->at(i)->getName() == ";" || $5->at(i)->getName() == "{" || $5->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
		if(symboltable.LookUp(logout, $3->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << $3->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << $3->getName() << "\n\n";
			error_count++;
		}
	  	logout << $1->getName() << $2->getName() << $3->getName() << $4->getName() << $5->getName() << "\n\n";
	  	$$->push_back($1);
	  	$$->push_back($2);
	  	$$->push_back($3);
	  	$$->push_back($4);
	  	$$->push_back($5);
	  }
	  | RETURN expression SEMICOLON 
	  {
	  	$$ = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : RETURN expression SEMICOLON\n\n";
	  	logout << $1->getName() << " ";
	  	$$->push_back($1);
	  	for(int i = 0; i < $2->size(); i++){
			logout << $2->at(i)->getName();
			$$->push_back($2->at(i));
		}
		logout << $3->getName() << "\n\n";
		$$->push_back($3);
	  }
	  ;

expression_statement 	: SEMICOLON		
			{
				logout << "line no: " << line_count <<  " expression_statement 	: SEMICOLON\n\n";
				logout << $1->getName() << "\n\n";
				$$ = new vector<SymbolInfo*>();
				$$->push_back($1);
			}	
			| expression SEMICOLON 
			{
				$$ = new vector<SymbolInfo*>();
				logout << "line no: " << line_count <<  " expression_statement : expression SEMICOLON \n\n";
				for(int i = 0; i < $1->size(); i++){
					logout << $1->at(i)->getName();
					$$->push_back($1->at(i));
				}
				logout << $2->getName() << "\n\n";
				$$->push_back($2);
			}
			;
			
variable :   ID
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " variable : ID\n\n";

		// semantic error-------//
		if(symboltable.LookUp(logout, $1->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << $1->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << $1->getName() << "\n\n";
			error_count++;
		}
		else{    // type mismatch error
			SymbolInfo *temp = symboltable.LookUp(logout, $1->getName());
			if(temp->getWhichVariable() == "array"){
				logout << "Error at line " << line_count << ": Type mismatch, " << $1->getName() << " is an array\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << $1->getName() << " is an array\n\n";
				error_count++;
			}
			else if(temp->getWhichVariable() == "func"){
				logout << "Error at line " << line_count << ": Type mismatch, " << $1->getName() << " is a function\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << $1->getName() << " is a function\n\n";
				error_count++;
			}
		}
		//-----------//
		logout << $1->getName() << "\n\n";
		$$->push_back($1);
		
	}	
	 | ID LTHIRD expression RTHIRD 
	 { 
	 	$$ = new vector<SymbolInfo*>();
	 	logout << "line no: " << line_count <<  " variable : ID LTHIRD expression RTHIRD\n\n";
		// semantic error-------//
		if(symboltable.LookUp(logout, $1->getName()) == nullptr){    // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << $1->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << $1->getName() << "\n\n";
			error_count++;
		}
		else{               // not an array
			SymbolInfo* temp = symboltable.LookUp(logout, $1->getName());
			if(temp->getWhichVariable() != "array"){      
				logout << "Error at line " << line_count << ": " << $1->getName() << " not an array\n\n";
				errorout << "Error at line " << line_count << ": " << $1->getName() << " not an array\n\n";
				error_count++;
			}
		}
		if($3->at(0)->getType() != "CONST_INT"){  // array index not integer
			logout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			error_count++;
		}
		
		//-----------//
	 	logout << $1->getName() << $2->getName() << $3->at(0)->getName() << $4->getName() << "\n\n";
	 	$$->push_back($1);
	 	$$->push_back($2);
		$$->push_back($3->at(0));
		$$->push_back($4);
	 }
	 ;
	 
	
expression : logic_expression	
 	  {
 	  	$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : logic_expression\n\n";

			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << "\n\n";
 	  }
	   | variable ASSIGNOP logic_expression
	   {
	   	$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : variable ASSIGNOP logic_expression\n\n";
			
			//semantic error----------//
			for(int i = 0; i < $3->size(); i++){     //  void function in expression
				if($3->at(i)->getType() == "ID" && symboltable.LookUp(logout, $3->at(i)->getName()) != nullptr){
					SymbolInfo* temp = symboltable.LookUp(logout, $3->at(i)->getName());
					if(temp->getWhichVariable() == "func" && temp->getVariableType() == "VOID"){
						logout << "Error at line " << line_count << ": Void function used in expression\n\n";
						errorout << "Error at line " << line_count << ": Void function used in expression\n\n";
						error_count++;
					}
				}
			}
			      
			if(symboltable.LookUp(logout, $1->at(0)->getName()) != nullptr){     // float assignment in integer error
				SymbolInfo *temp = symboltable.LookUp(logout, $1->at(0)->getName());
				if(temp->getVariableType() == "INT"){
					
					for(int i = 0; i < $3->size(); i++){
						if($3->at(i)->getType() == "CONST_FLOAT"){
							logout << "Error at line " << line_count << ": Type Mismatch\n\n";
							errorout << "Error at line " << line_count << ": Type Mismatch\n\n";
							error_count++;
							break;
						}
						
					}
				}
			}
			//------------//

			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << $2->getName();
			$$->push_back($2);
			for(int i = 0; i < $3->size(); i++){
				logout << $3->at(i)->getName();
				$$->push_back($3->at(i));
			}
			logout << "\n\n";
	   }
	   ;
		
logic_expression : rel_expression 	
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << "\n\n";
		}
		 | rel_expression LOGICOP rel_expression 	
		 {
		 	$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression LOGICOP rel_expression\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << $2->getName();
			$$->push_back($2);
			for(int i = 0; i < $3->size(); i++){
				logout << $3->at(i)->getName();
				$$->push_back($3->at(i));
			}
			logout << "\n\n";
		 }
		 ;
		 
rel_expression	: simple_expression 
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << "\n\n";
		}
		| simple_expression RELOP simple_expression	
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression RELOP simple_expression\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << $2->getName();
			$$->push_back($2);
			for(int i = 0; i < $3->size(); i++){
				logout << $3->at(i)->getName();
				$$->push_back($3->at(i));
			}
			logout << "\n\n";
		}
		;	
simple_expression : term 
		{	
			$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : term\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << "\n\n";
		}
		  | simple_expression ADDOP term 
		  {
		  	$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : simple_expression ADDOP term\n\n";
			for(int i = 0; i < $1->size(); i++){
				logout << $1->at(i)->getName();
				$$->push_back($1->at(i));
			}
			logout << $2->getName();
			$$->push_back($2);
			for(int i = 0; i < $3->size(); i++){
				logout << $3->at(i)->getName();
				$$->push_back($3->at(i));
			}
			logout << "\n\n";
		  }
		  ;
		  
term :   unary_expression
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " term :	unary_expression\n\n";
		for(int i = 0; i < $1->size(); i++){
	 		logout << $1->at(i)->getName();
	 		$$->push_back($1->at(i));
	 	}
	 	logout << "\n\n";
	}
        |  term MULOP unary_expression
        {
     		$$ = new vector<SymbolInfo*>();
     		logout << "line no: " << line_count <<  " term :  term MULOP unary_expression\n\n";

		// semantic error-----------//
		if($2->getName() == "%"){    // mod operand not integer
			if($1->size() == 1 && $3->size() == 1){
				if($1->at(0)->getType() != "CONST_INT" || $3->at(0)->getType() != "CONST_INT"){
					logout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
					errorout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
					error_count++;
				}
				else if($3->at(0)->getName() == "0"){
					logout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					errorout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					error_count++;
				}
			}
		}
			
		for(int i = 0; i < $1->size(); i++){
	 		logout << $1->at(i)->getName();
	 		$$->push_back($1->at(i));
	 	}
	 	logout << $2->getName();
	 	$$->push_back($2);
	 	for(int i = 0; i < $3->size(); i++){
	 		logout << $3->at(i)->getName();
	 		$$->push_back($3->at(i));
	 	}
	 	logout << "\n\n";
        }
     	;

unary_expression : ADDOP unary_expression 
		 {
		 	$$ = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : ADDOP unary_expression \n\n";
		 	logout << $1->getName();
		 	$$->push_back($1);
		 	for(int i = 0; i < $2->size(); i++){
		 		logout << $2->at(i)->getName();
		 		$$->push_back($2->at(i));
		 	}
		 	logout << "\n\n";
		 } 
		 | NOT unary_expression 
		 {
		 	$$ = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : NOT unary_expression \n\n";
		 	logout << $1->getName();
		 	$$->push_back($1);
		 	for(int i = 0; i < $2->size(); i++){
		 		logout << $2->at(i)->getName();
		 		$$->push_back($2->at(i));
		 	}
		 	logout << "\n\n";
		 	
		 }
  		 | factor 
  		 {
  		 	$$ = new vector<SymbolInfo*>();
  		 	logout << "line no: " << line_count <<  " unary_expression : factor \n\n";
  		 	for (int i = 0; i < $1->size(); i++){
  		 		logout << $1->at(i)->getName();
  		 		$$->push_back($1->at(i));
  		 	}
		 	logout << "\n\n";
  		 }
		 ;

factor	:  variable 
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable \n\n";
		for (int i = 0; i < $1->size(); i++){
	 		logout << $1->at(i)->getName();
	 		$$->push_back($1->at(i));
  		 }
  		 logout << "\n\n";
	}
	| ID LPAREN argument_list RPAREN
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : ID LPAREN argument_list RPAREN\n\n";

		//semantic error--------//
		if(symboltable.LookUp(logout,$1->getName()) == nullptr){
			logout << "Error at line " << line_count << ": Undeclared function " << $1->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared function " << $1->getName() << "\n\n";
			error_count++;
		}
		else{          // function argument check with declaration
			SymbolInfo* temp = symboltable.LookUp(logout, $1->getName());
			if(temp->getWhichVariable() != "func"){
				logout << "Error at line " << line_count << ": " << $1->getName() << " not a function" << "\n\n";
				errorout << "Error at line " << line_count << ": " << $1->getName() << " not a function"<< "\n\n";
				error_count++;
			}
			vector<string> parameter_type;
			for(int i = 0; i < $3->size(); i++){
				if($3->at(i)->getType() == "ID"){
					if(i != $3->size()-1){
						if($3->at(i+1)->getName() != "["){      // variable
							SymbolInfo* temp1 = symboltable.LookUp(logout, $3->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
						else if($3->at(i+2)->getType() == "CONST_INT" && $3->at(i+3)->getName() == "]"){   //array
							SymbolInfo* temp1 = symboltable.LookUp(logout, $3->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
					}
					else{       // variable
						SymbolInfo* temp1 = symboltable.LookUp(logout, $3->at(i)->getName());
						if(temp1 != nullptr)
							parameter_type.push_back(temp1->getVariableType());
					}
				}
				
				else if($3->at(i)->getType() == "CONST_INT"){
					if(i != 0){
						if($3->at(i-1)->getName() != "["){
							if($3->at(i-1)->getName() == ",")
								parameter_type.push_back("INT");
						}
					}
					else{
						parameter_type.push_back("INT");
					}
				}
				else if($3->at(i)->getType() == "CONST_FLOAT"){
					if(i != 0){
						if($3->at(i-1)->getName() != "["){
							if($3->at(i-1)->getName() == ",")
								parameter_type.push_back("FLOAT");
						}
					}
					else{
						parameter_type.push_back("FLOAT");
					}
				}
			}
			if(parameter_type.size() != temp->getParamSize()){
				logout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << $1->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << $1->getName() << "\n\n";
				error_count++;
			} 
			else{
				for(int i = 0; i < temp->getParamSize(); i++){
					if(parameter_type.at(i) != temp->getParamType(i)){
						logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << $1->getName() <<"\n\n";
						errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << $1->getName() <<"\n\n";
						error_count++;
						break;
					}
				}
			}
		}
		//---------------//
		logout << $1->getName() << $2->getName();
		$$->push_back($1);
		$$->push_back($2);
		for (int i = 0; i < $3->size(); i++){
	 		logout << $3->at(i)->getName();
	 		$$->push_back($3->at(i));
  		 }
  		 logout << $4->getName() << "\n\n";
		$$->push_back($4);
	}
	| LPAREN expression RPAREN
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : LPAREN expression RPAREN\n\n";
		logout << $1->getName();
		$$->push_back($1);
		for (int i = 0; i < $2->size(); i++){
	 		logout << $2->at(i)->getName();
	 		$$->push_back($2->at(i));
  		 }
  		 logout << $3->getName() << "\n\n";
		$$->push_back($3);
	}
	| CONST_INT 
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_INT\n\n";
		logout << $1->getName() << "\n\n";
		$$->push_back($1);
	}
	| CONST_FLOAT
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_FLOAT\n\n";
		logout << $1->getName() << "\n\n";
		$$->push_back($1);
	}
	| variable INCOP 
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable INCOP\n\n";
		for (int i = 0; i < $1->size(); i++){
	 		logout << $1->at(i)->getName();
	 		$$->push_back($1->at(i));
  		 }
  		 logout << $2->getName() << "\n\n";
  		 $$->push_back($2);
	}
	| variable DECOP
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable DECOP\n\n";
		for (int i = 0; i < $1->size(); i++){
	 		logout << $1->at(i)->getName();
	 		$$->push_back($1->at(i));
  		 }
  		 logout << $2->getName() << "\n\n";
  		 $$->push_back($2);
	}
	;
argument_list : arguments
		  {
			$$ = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : arguments\n\n";
			for (int i = 0; i < $1->size(); i++){
		 		logout << $1->at(i)->getName();
		 		$$->push_back($1->at(i));
	  		 }
	  		 logout << "\n\n";
		  }
		  |
		  {
			$$ = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : \n\n";
	  		logout << "\n\n";
		  }
		  ;

arguments : arguments COMMA logic_expression
		{
			$$ = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " arguments : arguments COMMA logic_expressionn\n";
			for (int i = 0; i < $1->size(); i++){
		 		logout << $1->at(i)->getName();
		 		$$->push_back($1->at(i));
	  		 }
	  		 logout << $2->getName();
	  		 $$->push_back($2);
	  		 for (int i = 0; i < $3->size(); i++){
		 		logout << $3->at(i)->getName();
		 		$$->push_back($3->at(i));
	  		 }
	  		 logout << "\n\n";
		}
	        | logic_expression
	        {
			$$ = new vector<SymbolInfo*>();
	      		logout << "line no: " << line_count <<  " arguments  : logic_expression\n\n";
			for (int i = 0; i < $1->size(); i++){
		 		logout << $1->at(i)->getName();
		 		$$->push_back($1->at(i));
	  		}
	  		logout << "\n\n";
		}
		;

%%

int main(int argc,char *argv[])
{

	if(argc!=2){
		cout << "Please provide input file name and try again\n";
		return 0;
	}
	
	FILE *infile=fopen(argv[1],"r");
	if(infile==NULL){
		cout << "Cannot open specified file\n";
		return 0;
	}
	
	logout.open("log.txt");
	errorout.open("error.txt");
	
	yyin=infile;
	yyparse();

	symboltable.printAllScopeTable(logout);
	logout << "Total lines: " << line_count-1 << endl;
    logout << "Total errors: " << error_count << endl;
	fclose(yyin);
	logout.close();
	errorout.close();
	
	
	return 0;
}
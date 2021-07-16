%{
#include<bits/stdc++.h>
#include"SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
ofstream errorout;
ofstream logout;
ofstream code;
ofstream optimized_code;
ifstream read_code;

int line_count = 1;
int error_count = 0;
int temp_variable_count = 0;
int label_count = 0;

SymbolTable symboltable(logout, 30); 
string type;
string initial_code = "";
vector<pair<string, string>> data_list;

void yyerror(char *s){
	logout << "Error at line " << line_count << ": Syntax Error\n";
	errorout << "Error at line " << line_count << ": Syntax Error\n";
	error_count++;
}

string makeScopeID(string id){
	string x = ".";
	string y = "_";
	size_t pos;
	while ((pos = id.find(x)) != std::string::npos) {
        id.replace(pos, 1, y);
    }
	return id;
}

string newTemp(){
	string temp_variable  = "t" + to_string(temp_variable_count);
	temp_variable_count++;
	data_list.push_back({temp_variable,"0"});
	return temp_variable;
}

string newLabel(){
	string label  = "l" + to_string(label_count);
	label_count++;
	return label;
}

void Optimized_Code(string filename){
	read_code.open(filename);
	optimized_code.open("optimized_code.asm");
	string first_line;
	string second_line;
	string first_words;
	string final_first_words;
	string second_words;
	string final_second_words;

	while(getline(read_code,first_line)){
		optimized_code << first_line << "\n";
		vector <string> first_tokens;
		vector <string> second_tokens;
		stringstream check_first(first_line);
      
		// Tokenizing w.r.t. space ' '
		while(getline(check_first, first_words, ' ')){	
			stringstream check_first_word(first_words);
			while(getline(check_first_word, final_first_words, ',')){
				first_tokens.push_back(final_first_words);
			}
		}
		
		if(first_tokens.size() == 3 && first_tokens.at(0) == "\tmov"){
			getline(read_code,second_line);
			
			stringstream check_second(second_line);

			while(getline(check_second, second_words, ' ')){
				stringstream check_second_word(second_words);
				while(getline(check_second_word, final_second_words, ',')){
					second_tokens.push_back(final_second_words);
				}
			}
			if(second_tokens.size() == 3 && second_tokens.at(0) == "\tmov"){
				int match = first_tokens.at(1).compare(second_tokens.at(2));
				int match2 = first_tokens.at(2).compare(second_tokens.at(1));

				if(match == 0 && match2 == 0){}
				else{
					optimized_code << second_line << "\n";
				}	
			}
			else
				optimized_code << second_line << "\n";	
		}		
	}
	optimized_code.close();
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
%type<vectorsymbol> declaration_list var_declaration func_declaration parameter_list unit factor unary_expression term simple_expression rel_expression logic_expression expression variable expression_statement arguments argument_list statement statements compound_statement func_definition program start

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
start : program{
			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i < $1->size(); i++)
				$$->push_back($1->at(i));

			logout << "Line " << line_count-1 << ": start : program\n\n";

			//assembly code
			if(error_count == 0){
				initial_code += ".MODEL small\n.STACK 100h\n.DATA\n\tprint_var dw ?\n\tret_temp dw ?\n";

				//$$->setCode(initial_code);
				for(int i = 0; i < data_list.size(); i++){
					if(data_list.at(i).second == "0")
						initial_code += "\t" + data_list.at(i).first + " dw ?\n";	
					else
						initial_code += "\t" + data_list.at(i).first + " dw " + data_list.at(i).second + " dup(?)\n";
				}
				initial_code += ".CODE\n";
				
				//print function
				initial_code += "print PROC\n";
				initial_code +=	"\tpush ax\n";
				initial_code += "\tpush bx\n"; 
				initial_code += "\tpush cx\n";
				initial_code += "\tpush dx\n";
				initial_code += "\tmov ax, print_var\n";
				initial_code += "\tmov bx, 10\n";
				initial_code += "\tmov cx, 0\n";

				initial_code += "printLabel1:\n";
				initial_code += "\tmov dx, 0\n";
				initial_code += "\tdiv bx\n";
				initial_code += "\tpush dx\n";
				initial_code += "\tinc cx\n";
				initial_code += "\tcmp ax, 0\n";
				initial_code += "\tjne printLabel1\n";

				initial_code += "printLabel2:\n";
				initial_code += "\tmov ah, 2\n";
				initial_code += "\tpop dx\n";
				initial_code += "\tadd dl, '0'\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tdec cx\n";
				initial_code += "\tcmp cx, 0\n";
				initial_code += "\tjne printLabel2\n";
				initial_code += "\tmov dl, 0Ah\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tmov dl, 0Dh\n";
				initial_code += "\tint 21h\n";
				initial_code += "\tpop dx\n";
				initial_code += "\tpop cx\n";
				initial_code += "\tpop bx\n";
				initial_code += "\tpop ax\n";
				initial_code += "\tret\n";
				initial_code += "print endp\n";


				code << initial_code;
				code << $$->at(0)->getCode();
				code << "END main\n";
			}	

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

		//assembly code
		$$->at(0)->setCode($$->at(0)->getCode() + $2->at(0)->getCode());
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
			cout << __LINE__ << $2->getName() << endl;
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
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
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
			cout << __LINE__ << $2->getName() << endl;
			//---------------//
		}
		; 
	 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
				if(symboltable.LookUp(logout, $2->getName()) == nullptr) {
					bool inserted = symboltable.Insert(logout, $2->getName(),"ID",$1->getType(), "func");
				}
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

						//assembly code
						string symbol = $4->at(i)->getName() + "_" + symboltable.getCurrentID();
						(symboltable.LookUp(logout, $4->at(i)->getName()))->setSymbol(makeScopeID(symbol));
						// data_list.push_back({makeScopeID(symbol),"0"});
					}
				}
				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());       // store parameter type and parameter name sequentially
				if(temp->getParamSize() == 0){       
					for(int i = 0; i < $4->size(); i++){
						if($4->at(i)->getType() == "INT" || $4->at(i)->getType() == "FLOAT" || $4->at(i)->getType() == "VOID")
							temp->setParamType($4->at(i)->getType());
						else if($4->at(i)->getType() == "ID"){
							
							//assembly code
							string symbol = $4->at(i)->getName() + "_" + symboltable.getCurrentID();
							(symboltable.LookUp(logout, $4->at(i)->getName()))->setSymbol(makeScopeID(symbol));
							data_list.push_back({makeScopeID(symbol),"0"});
							temp->setParamName(makeScopeID(symbol));
						}
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

			//assembly code
			string segment_code = "";
			segment_code += $2->getName() + " PROC\n";
			if($2->getName() == "main")
				segment_code += "\tmov ax, @data\n\tmov ds, ax\n";
			else 
				segment_code += "\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n";

			segment_code += $7->at(0)->getCode();
			if($2->getName() != "main")
				segment_code += "\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n";

			segment_code += $2->getName() + " ENDP\n";
			
			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
 		}
		| type_specifier ID LPAREN RPAREN {

			if(symboltable.LookUp(logout, $2->getName()) == nullptr)
			{
				bool inserted = symboltable.Insert(logout, $2->getName(),"ID", $1->getType(), "func");
				// Ekhane main wala symbolinfo ke defined set kore felse

				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());  // Function Already Defined
				temp->setDefined(false);

				// if(temp->getDefined()) {
				// 	cout << $2->getName() << " defined" << endl;
				// }
				// else {
				// 	cout << $2->getName() << " not defined" << endl;
				// }

			}
			else
			{        // Return type doesn't match with declaration
				SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());
				if(temp->getVariableType() != $1->getType())
				{
					logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
					errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
					error_count++;
				}
			}

			SymbolInfo* temp = symboltable.LookUp(logout, $2->getName());  // Function Already Defined
			if(temp->getDefined())
			{
				logout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
				errorout << "Error at line " << line_count << ": Multiple Definition of " << $2->getName() <<"\n\n";
				error_count++;
			}
			else
			{
				temp->setDefined(true);
			}
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

			//assembly code
			string segment_code = "";
			segment_code += $2->getName() + " PROC\n";
			if($2->getName() == "main")
				segment_code += "\tmov ax, @data\n\tmov ds, ax\n";
			else 
				segment_code += "\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n";

			segment_code += $6->at(0)->getCode();
			if($2->getName() != "main")
				segment_code += "\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n";

			segment_code += $2->getName() + " ENDP\n";
			
			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
			
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

			//assembly code
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


				//assembly code
				$$->at(0)->setCode($$->at(0)->getCode() + $2->at(0)->getCode());
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

			
			//assembly code
			string symbol = $3->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, $3->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),"0"});
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

			//assembly code
			string symbol = $3->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, $3->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),$5->getName()});
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

			//assembly code
			string symbol = $1->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, $1->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),"0"});
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

			//assembly code
			string symbol = $1->getName() + "_" + symboltable.getCurrentID();
			(symboltable.LookUp(logout, $1->getName()))->setSymbol(makeScopeID(symbol));
			data_list.push_back({makeScopeID(symbol),$3->getName()});
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

		//assembly code
		$$->at(0)->setCode($$->at(0)->getCode() + $2->at(0)->getCode());
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

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		
		string segment_code = "";
		segment_code += $3->at(0)->getCode();
		segment_code += label1 + ":\n";
		segment_code += $4->at(0)->getCode();
		segment_code += "\tmov ax, " + $4->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label2 + "\n";
		segment_code += $7->at(0)->getCode();
		segment_code += $5->at(0)->getCode();
		segment_code += "\tjmp " + label1 + "\n";
		segment_code += label2 + ":\n";

		$$->at(0)->setCode(segment_code);


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

		//assembly code
		string label = newLabel();
		string segment_code = "";
		segment_code += "\tmov ax, " + $3->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label + "\n";
		segment_code += $5->at(0)->getCode();
		segment_code += label + ":\n";

		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
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

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		string segment_code = "";

		segment_code += "\tmov ax, " + $3->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label1 + "\n";
		segment_code += $5->at(0)->getCode();
		segment_code += "\tjmp " + label2 + "\n";
		segment_code += label1 + ":\n";
		segment_code += $7->at(0)->getCode();
		segment_code += label2 + ":\n";

		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);

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

		//assembly code
		string label1 = newLabel();
		string label2 = newLabel();
		
		string segment_code = "";
		segment_code += label1 + ":\n";
		segment_code += $3->at(0)->getCode();
		segment_code += "\tmov ax, " + $3->at(0)->getSymbol() + "\n";
		segment_code += "\tcmp ax, 0\n";
		segment_code += "\tje " + label2 + "\n";
		segment_code += $5->at(0)->getCode();
		segment_code += "\tjmp " + label1 + "\n";
		segment_code += label2 + ":\n";

		$$->at(0)->setCode(segment_code);

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

		//assembly code
		string segment_code = "";
		segment_code += "\tmov ax, " + (symboltable.LookUp(logout, $3->getName()))->getSymbol() + "\n";
		segment_code += "\tmov print_var, ax\n";
		segment_code +=	"\tcall print\n";

		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
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

		//assembly code
		string segment_code = "";
		segment_code += $2->at(0)->getCode();
		segment_code += "\tmov ax, " + $2->at(0)->getSymbol() + "\n";
		segment_code += "\tmov ret_temp, ax\n";

		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);

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

				//assembly code
				$$->at(0)->setCode($1->at(0)->getCode());
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

		//assembly code
		$$->at(0)->setSymbol((symboltable.LookUp(logout, $1->getName()))->getSymbol());
		
		$$->at(0)->setCode("");
		
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
				$$->at(0)->setSymbol("");
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

		//assembly code
		$$->at(0)->setSymbol((symboltable.LookUp(logout, $1->getName()))->getSymbol());

		string segment_code = "";
		segment_code += "\tmov di, " + $3->at(0)->getSymbol() + "\n";
		segment_code += "\tadd di, di\n";
		$$->at(0)->setCode(segment_code);
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

			//assembly code
			string whichvariable = (symboltable.LookUp(logout, $1->at(0)->getName()))->getWhichVariable();
			string segment_code = "";
			string temp;
			
			if($3->size() == 4){
				temp = newTemp();
				segment_code += $3->at(0)->getCode();
				segment_code += "\tmov ax, " + $3->at(0)->getSymbol() + "[di]\n";
				segment_code += "\tmov " + temp + ", ax\n";
				segment_code += $1->at(0)->getCode();
				if(whichvariable != "array")
					segment_code += "\tmov " + $1->at(0)->getSymbol() + ", ax\n";
				else{
					segment_code += "\tmov ax, " + temp + "\n"; 
					segment_code += "\tmov " + $1->at(0)->getSymbol() + "[di], ax\n";
				}
			}

			else{
				segment_code += $3->at(0)->getCode();
				segment_code += $1->at(0)->getCode();
				segment_code += "\tmov ax, " + $3->at(0)->getSymbol() + "\n";
				
				if(whichvariable != "array")
					segment_code += "\tmov " + $1->at(0)->getSymbol() + ", ax\n";
				else
					segment_code += "\tmov " + $1->at(0)->getSymbol() + "[di], ax\n";
				
			}
			$$->at(0)->setCode(segment_code);
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

			//assembly code
			string label1 = newLabel();
			string label2 = newLabel();
			string temp = newTemp();

			string segment_code = "";
			if($2->getName() == "&&"){
				segment_code += "\tcmp " + $1->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tje " + label1 + "\n";
				segment_code += "\tcmp " +  $3->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tje " + label1 + "\n";
				segment_code += "\tmov " + temp + ", 1\n";
				segment_code += "\tjmp " + label2 + "\n";
				segment_code += label1 + ":\n";
				segment_code += "\tmov " + temp + ", 0\n";
				segment_code += label2 + ":\n";
			}
			else if($2->getName() == "||"){
				segment_code += "\tcmp " + $1->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tjne " + label1 + "\n";
				segment_code += "\tcmp " +  $3->at(0)->getSymbol() + ", 0\n";
				segment_code += "\tjne " + label1 + "\n";
				segment_code += "\tmov " + temp + ", 0\n";
				segment_code += "\tjmp " + label2 + "\n";
				segment_code += label1 + ":\n";
				segment_code += "\tmov " + temp + ", 1\n";
				segment_code += label2 + ":\n";
			}
			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
			$$->at(0)->setSymbol(temp);
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

			//assembly code
			string label1 = newLabel();
			string label2 = newLabel();
			string temp = newTemp();
			string segment_code = "";

			segment_code += $3->at(0)->getCode();
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "\n";
			segment_code += "\tcmp ax, " + $3->at(0)->getSymbol() + "\n";

			if($2->getName() == ">")
				segment_code += "\tjg " + label1 + "\n";
			else if($2->getName() == ">=")
				segment_code += "\tjge " + label1 + "\n";
			else if($2->getName() == "<")
				segment_code += "\tjl " + label1 + "\n";
			else if($2->getName() == "<=")
				segment_code += "\tjle " + label1 + "\n";
			else if($2->getName() == "==")
				segment_code += "\tje " + label1 + "\n";
			else if($2->getName() == "!=")
				segment_code += "\tjne " + label1 + "\n";

			segment_code += "\tmov " + temp + ", 0\n";
			segment_code += "\tjmp " + label2 + "\n";
			segment_code += label1 + ":\n";
			segment_code += "\tmov " + temp + ", 1\n";
			segment_code += label2 + ":\n";

			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
			$$->at(0)->setSymbol(temp);
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

			//assembly code

			string temp = newTemp();

			string segment_code = "";
			segment_code += $3->at(0)->getCode();
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "\n";
			if($2->getName() == "+")
				segment_code += "\tadd ax, " + $3->at(0)->getSymbol() + "\n";
			else
				segment_code += "\tsub ax, " + $3->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
			$$->at(0)->setSymbol(temp);
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
					if($3->at(0)->getType() != "CONST_INT"){
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

			//assembly code

			string temp = newTemp();

			string segment_code = "";
			segment_code += $3->at(0)->getCode();
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "\n";
			segment_code += "\tmov bx, " + $3->at(0)->getSymbol() + "\n";

			if($2->getName() == "*"){
				segment_code += "\tmul bx\n";
				segment_code += "\tmov " + temp + ", ax\n";
			}
				
			else if($2->getName() == "/"){
				segment_code += "\txor dx, dx\n";
				segment_code += "\tdiv bx\n";
				segment_code += "\tmov " + temp + ", ax\n";
			}
			else{   //operator % 
				segment_code += "\txor dx, dx\n";
				segment_code += "\tdiv bx\n";
				segment_code += "\tmov " + temp + ", dx\n";
			}
			
			$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
			$$->at(0)->setSymbol(temp);

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

		//assembly code
		string temp_var = newTemp();
		string segment_code = "";  
		vector<string> pushed_var;     

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
			int param_count = 0;
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
					//assembly code
					pushed_var.push_back((symboltable.LookUp(logout, $3->at(i)->getName()))->getSymbol());
					segment_code += "\tpush " + (symboltable.LookUp(logout, $3->at(i)->getName()))->getSymbol() + "\n";
					
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

			//assembly code
			for(int i = 0; i < $3->size(); i++){
				if($3->at(i)->getType() == "ID"){
					segment_code += "\tmov ax, " + (symboltable.LookUp(logout, $3->at(i)->getName()))->getSymbol() + "\n";
					segment_code += "\tmov " + temp->getParamName(param_count) + ", ax\n";
					param_count++;
				}
			}
			segment_code += "\tcall " + $1->getName() + "\n";
			segment_code += "\tmov ax, ret_temp\n";
			segment_code += "\tmov " + temp_var + ", ax\n";
			for(int i = pushed_var.size()-1; i >= 0; i--)
				segment_code += "\tpop " + pushed_var.at(i) + "\n";
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

		//assembly code
		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
		$$->at(0)->setSymbol(temp_var);

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

		//assembly code
		$$->at(0)->setSymbol($2->at(0)->getSymbol());
		$$->at(0)->setCode($$->at(0)->getCode() + $2->at(0)->getCode());
	}
	| CONST_INT 
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_INT\n\n";
		logout << $1->getName() << "\n\n";
		$$->push_back($1);

		//assembly code
		$1->setSymbol($1->getName());
	}
	| CONST_FLOAT
	{
		$$ = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_FLOAT\n\n";
		logout << $1->getName() << "\n\n";
		$$->push_back($1);

		//assembly code
		$1->setSymbol($1->getName());
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

		//assembly code
		string temp = newTemp();
		string segment_code = "";

		string whichvariable = (symboltable.LookUp(logout, $1->at(0)->getName()))->getWhichVariable();

		if(whichvariable != "array"){
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tinc " + $1->at(0)->getSymbol()  + "\n";
		}

		else if(whichvariable == "array"){
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "[di]\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tinc " + $1->at(0)->getSymbol()  + "[di]\n";
		}

		$$->at(0)->setSymbol(temp);
		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
	
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

		//assembly code
		string temp = newTemp();
		string segment_code = "";

		string whichvariable = (symboltable.LookUp(logout, $1->at(0)->getName()))->getWhichVariable();

		if(whichvariable != "array"){
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tdec " + $1->at(0)->getSymbol()  + "\n";
		}

		else if(whichvariable == "array"){
			segment_code += "\tmov ax, " + $1->at(0)->getSymbol() + "[di]\n";
			segment_code += "\tmov " + temp + ", ax\n";
			segment_code += "\tdec " + $1->at(0)->getSymbol()  + "[di]\n";
		}

		$$->at(0)->setSymbol(temp);
		$$->at(0)->setCode($$->at(0)->getCode() + segment_code);
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
	code.open("code.asm");
	
	yyin=infile;
	yyparse();

	symboltable.printAllScopeTable(logout);
	logout << "Total lines: " << line_count-1 << endl;
    logout << "Total errors: " << error_count << endl;
	fclose(yyin);
	logout.close();
	errorout.close();
	code.close();
	Optimized_Code("code.asm");

	
	return 0;
}

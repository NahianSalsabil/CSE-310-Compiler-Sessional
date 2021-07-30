%option noyywrap


%x MULTILINE_COMMENT_STATE

%{
#include<bits/stdc++.h>
#include"SymbolTable.cpp"
#include"y.tab.h"

using namespace std;

extern YYSTYPE yylval;
extern ofstream logout;
extern ofstream errorout;

extern SymbolTable symboltable;
extern int line_count;
extern int error_count;


%}
  
WHITESPACE [  \f\r\t\v]+
NEWLINE \r?\n
DIGIT [0-9]
DIGITS {DIGIT}+

ADDOP [+-]
MULOP [*/%]
INCOP ("++")
DECOP ("--")
RELOP ("<"|"<="|">"|">="|"=="|"!=")
ASSIGNOP [=]
LOGICOP ("&&"|"||")
NOT [!]
LPAREN [(]
RPAREN [)]
LCURL [{]
RCURL [}]
LTHIRD ("[")
RTHIRD ("]")
COMMA [,]
SEMICOLON [;]




IDENTIFIER [A-Za-z_][a-zA-Z0-9_]*

INTEGER_LITERAL {DIGITS}
FLOAT_LITERAL {DIGITS}?(\.{DIGITS})?([Ee][+-]?{DIGITS})?

CHAR '([ -~]{-}['\\])'
SPECIAL_CHAR '(\\[\\nfratbv0\"\'])'
CHARACTER_LITERAL {CHAR}|{SPECIAL_CHAR}


SINGLELINE_COMMENT \/\/(([\\]+([\n])?)?|([^\n])*)*

MULTILINE_COMMENT_START (\/\*)
MULTILINE_COMMENT (\/\*)([^\*]|\*[^\/])*(\*\/)

ILL_FORMED_NUMBER ({DIGIT}*([Ee][+-]?{DIGITS})+(\.{DIGITS})+)|({DIGITS}\.)+
TOO_MANY_DECIMAL_POINT ({DIGITS}\.{DIGITS}\.{DIGITS})+
MULTI_CHAR_CONST '(([ -~]{-}['\\])([ -~]{-}['\\])+)'

UNFINISHED_COMMENT (\/\*)([^\*]|\*[^\/])*

UNFINISHED_CHARACTER ('([ -~]{-}['\\])*)|('(\\[\\nfratbv0\"\'])*)

%%
{WHITESPACE}    {    }

 
"if"  {
		SymbolInfo *symbolinfo = new SymbolInfo();
		symbolinfo->setName(yytext);
		symbolinfo->setType("IF");
		yylval.symbol = symbolinfo;
		return IF;
	}   

"else"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("ELSE");
			yylval.symbol = symbolinfo;
			return ELSE;
		}
		
"for"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("FOR");
			yylval.symbol = symbolinfo;
			return FOR;
		}
		
"while"   {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("WHILE");
			yylval.symbol = symbolinfo;
			return WHILE;
		}
		
"do"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("DO");
			yylval.symbol = symbolinfo;
			return DO;
		}

"int"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("INT");
			yylval.symbol = symbolinfo;
			return INT;
		}
		
"float" {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("FLOAT");
			yylval.symbol = symbolinfo;
			return FLOAT;
		}
		
"void"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("VOID");
			yylval.symbol = symbolinfo;
			return VOID;
		}	
		
"return"   {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("RETURN");
			yylval.symbol = symbolinfo;
			return RETURN;
		}	
		
"printf"  {
			SymbolInfo *symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("PRINTLN");
			yylval.symbol = symbolinfo;
			return PRINTLN;
		}

		
{ADDOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("ADDOP");
			yylval.symbol = symbolinfo;
			return ADDOP;
}	
{MULOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("MULOP");
			yylval.symbol = symbolinfo;
			return MULOP;
}
{INCOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("INCOP");
			yylval.symbol = symbolinfo;
			return INCOP;
}
{DECOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("DECOP");
			yylval.symbol = symbolinfo;
			return INCOP;
}
{RELOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("RELOP");
			yylval.symbol = symbolinfo;
			return RELOP;
}
{ASSIGNOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("ASSIGNOP");
			yylval.symbol = symbolinfo;
			return ASSIGNOP;
}
{LOGICOP}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("LOGICOP");
			yylval.symbol = symbolinfo;
			return LOGICOP;
}
{NOT}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("NOT");
			yylval.symbol = symbolinfo;
			return NOT;
}
{LPAREN}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("LPAREN");
			yylval.symbol = symbolinfo;
			return LPAREN;
}
{RPAREN}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("RPAREN");
			yylval.symbol = symbolinfo;
			return RPAREN;
}
{LCURL}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("LCURL");
			yylval.symbol = symbolinfo;
			return LCURL;
}
{RCURL}     {	
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("RCURL");
			yylval.symbol = symbolinfo;
			return RCURL;
}
{LTHIRD}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("LTHIRD");
			yylval.symbol = symbolinfo;
			return LTHIRD;
}
{RTHIRD}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("RTHIRD");
			yylval.symbol = symbolinfo;
			return RTHIRD;
}
{COMMA}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("COMMA");
			yylval.symbol = symbolinfo;
			return COMMA;
}
{SEMICOLON}     {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("SEMICOLON");
			yylval.symbol = symbolinfo;
			return SEMICOLON;
}

{IDENTIFIER}  {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("ID");
			yylval.symbol = symbolinfo;
			return ID;
}	

{INTEGER_LITERAL}   {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("CONST_INT");
			yylval.symbol = symbolinfo;
			return CONST_INT;
}

{FLOAT_LITERAL}  {
			SymbolInfo * symbolinfo = new SymbolInfo();
			symbolinfo->setName(yytext);
			symbolinfo->setType("CONST_FLOAT");
			yylval.symbol = symbolinfo;
			return CONST_FLOAT;	
}

{NEWLINE} {
	line_count++;
}
 
{ILL_FORMED_NUMBER} {
		logout << "Error at line no "  << line_count << ": " << "Ill Formed Number " <<  yytext << endl;
		errorout << "Error at line no "  << line_count << ": " << "Ill Formed Number " <<  yytext << endl;
		logout << endl;
		error_count++;	
}

{TOO_MANY_DECIMAL_POINT} {
		logout << "Error at line no  " << line_count << ": " << "Too Many Decimal Points " <<  yytext << endl;
		errorout << "Error at line no  " << line_count << ": " << "Too Many Decimal Points " <<  yytext << endl;
		logout << endl;
		error_count++;	
}

([0-9]+[a-zA-Z_]+)|([a-zA-Z_]+[0-9]+) {
		logout << "Error at line no  " << line_count << ": " << "Invalid prefix on ID or invalid suffix on Number " <<  yytext << endl;
		errorout << "Error at line no  " << line_count << ": " << "Invalid prefix on ID or invalid suffix on Number " <<  yytext << endl;
		logout << endl;
		error_count++;
}

{MULTI_CHAR_CONST} {
		logout << "Error at line no  " << line_count << ": " << "Multi Character Constant Error " <<  yytext << endl;
		errorout << "Error at line no  " << line_count << ": " << "Multi Character Constant Error " <<  yytext << endl;
		logout << endl;
		error_count++;	
}

{UNFINISHED_COMMENT} {
		logout << "Error at line no  " << line_count << ": " << "Unterminated Comment " <<  yytext << endl;
		errorout << "Error at line no  " << line_count << ": " << "Unterminated Comment " <<  yytext << endl;
		for(int i = 0; i < strlen(yytext); i++){
			if(yytext[i] == '\n'){
				line_count++;
			}
		}
		error_count++;		
}


{UNFINISHED_CHARACTER} {
		logout << "Error at line no  " << line_count << ": " << "Unterminated Character " <<  yytext << endl;
		logout << endl;
		error_count++;	
}

'' {
		logout << "Error at line no  " << line_count << ": " << "Empty Character Constant Error" <<  yytext << endl;
		logout << endl;
		error_count++;
}

. {
		logout << "Error at line no  " << line_count << ": " << "Unrecognized Character " <<  yytext << endl;
		logout << endl;
		error_count++;
}
	
%%


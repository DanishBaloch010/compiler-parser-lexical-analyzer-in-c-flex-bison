%{

#include "pedestal.tab.h"
int tokens=0;

%}

%%

"pedestal start" {yylval.identifier = strdup(yytext); return PEDESTAL_START;}
"pedestal end" {yylval.identifier = strdup(yytext); return PEDESTAL_END;}

"into" {yylval.identifier = strdup(yytext); return INTO;} 
"put"  {yylval.identifier = strdup(yytext); return PUT;} 
"integerContainer" {yylval.identifier = strdup(yytext); return INT_CON;}
"floatContainer" {yylval.identifier = strdup(yytext); return FLOAT_CON;}
"stringContainer" {yylval.identifier = strdup(yytext); return STRING_CON;}
"repeatUntil" {yylval.identifier = strdup(yytext); return FOR_LOOP_KEYWORD;}
"and" {yylval.identifier = strdup(yytext); return AND;}
"show" {yylval.identifier = strdup(yytext); return PRINT;}

"isLessThan" {yylval.identifier = strdup(yytext); return FOR_LOOP_COND;}
"add" {yylval.identifier = strdup(yytext); return ADD;}
"sub" {yylval.identifier = strdup(yytext); return SUB;}
"updateInc" {yylval.identifier = strdup(yytext); return UPDATE;}

"define" {yylval.identifier = strdup(yytext); return DEFINE;}
"void" {yylval.identifier = strdup(yytext); return VOID;}

[;] {yylval.identifier = strdup(yytext); return SEMICOLON;}
[(] {yylval.identifier = strdup(yytext); return OPEN_BRACKET_ROUND;}
[)] {yylval.identifier = strdup(yytext); return CLOSE_BRACKET_ROUND;}
[{] {yylval.identifier = strdup(yytext); return OPEN_BRACKET_CURLY;}
[}] {yylval.identifier = strdup(yytext); return CLOSE_BRACKET_CURLY;}
[,] {yylval.identifier = strdup(yytext); return COMMA;}

[0-9]+ {yylval.integer_num = atoi(yytext); return INT; }
[0-9]*"."[0-9]+ {  yylval.float_num = atof(yytext); return FLOAT; }
\"(\\.|[^"\\])*\" {yylval.string_literal = strdup(yytext);  return STRING;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.identifier = strdup(yytext); return IDENTIFIER;}

[' '\t\n]+ {  } 
"//".*  {  }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  {  }
. { }

%%
int yywrap(void)
{
	return 1;
}
%{

int tokens=0;

%}

%%

[0-9]+ { tokens++; fprintf(yyout,"Integer Number : %s\n",yytext); }

[0-9]*"."[0-9]+ { tokens++; fprintf(yyout,"Float Number : %s\n",yytext); }

\"(\\.|[^"\\])*\" {tokens++; fprintf(yyout,"String LiteraL : %s\n",yytext); }

"put"|"into"|"integerContainer"|"show"|"and" {tokens++; fprintf(yyout,"Keyword : %s\n", yytext);} 

"add"|"mul"|"div"|"sub"|"updateInc"|"isLessThan" {tokens++; fprintf(yyout,"Operator : %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {tokens++; fprintf(yyout,"Identifier : %s\n",yytext); }

[(){}|,;] {tokens++; fprintf(yyout,"Seperator : %s\n", yytext); }

[' '\t\n]+ {  } 
"//".*  {  }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  {  }

. { fprintf(yyout," --> xX Invalid Char : %s  Xx <--\n",yytext); }

%%

int yywrap(void)
{
	return 1;
}

int main(int argc, char **argv)
{
	extern FILE *yyin , *yyout;
	yyin = fopen("source.pd" ,"r");
	yyout = fopen("source_TokenOut.txt","w");

	yylex();

	fclose(yyin);
	
	fprintf(yyout,"\n\n Number of TOKENS --> %d",tokens);
	fclose(yyout);
	printf ( "the output is printed in file.\n");
	return 0;
}
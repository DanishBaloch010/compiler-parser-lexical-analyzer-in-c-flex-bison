%{
  #include <cstdio>
  #include <iostream>
  using namespace std;

  // FLEX CONNECTION FUNCTIONS
  //lexer function , generates tokens .
  extern int yylex();
  //parser function , creates parse tree
  extern int yyparse();
  // file handling for input and output files
  extern FILE *yyin ;
  extern FILE *yyout;
 
 // error func this will invoke when a syntax error occurs
  void yyerror(const char *s);

  //extern void eat_to_newline(void);

%}

%union
{
  int integer_num;
  float float_num;
  char *string_literal;
  char *identifier;
}
%token <identifier>PEDESTAL_START
%token <identifier>PEDESTAL_END
%token <identifier> SEMICOLON
%token <identifier> OPEN_BRACKET_ROUND
%token <identifier> CLOSE_BRACKET_ROUND
%token <identifier> OPEN_BRACKET_CURLY
%token <identifier> CLOSE_BRACKET_CURLY
%token <identifier> INTO
%token <identifier> PUT
%token <identifier> INT_CON
%token <identifier> FLOAT_CON
%token <identifier> STRING_CON
%token <identifier> ADD
%token <identifier> SUB
%token <identifier> PRINT
%token <identifier> UPDATE
%token <identifier> AND
%token <identifier> FOR_LOOP_COND
%token <identifier> FOR_LOOP_KEYWORD
%token <identifier> COMMA
%token <identifier> VOID
%token <identifier> DEFINE


%token <integer_num> INT
%token <float_num> FLOAT
%token <string_literal> STRING
%token <identifier> IDENTIFIER

%%
// grammar rules of pedestal language
pedestal: header body_section footer 
{ cout << "End of file.." << endl; };
// the syntax is as " pedestal start string_literal ; "
header: PEDESTAL_START STRING SEMICOLON 
{   cout << "reading a pedestal program named as -> " << $1 << $2 << $3 << endl;
    //fprintf(yyout,"reading a pedestal program named as : %s %s %s \n", $1,$2,$3);
};
// body section(prod) can have body statements or nothing
body_section: body_statements | 
// body statements can be comprises of single body statement or multiple body statements
body_statements: body_statement | body_statements body_statement
// now body statement can be declerations, loops, operations or print statements
body_statement: declerations | loops | operations | printstatements | functions 

// these body statement productions are defined below.
// declerations can be of int or float or string
declerations: integer_dec | float_dec | string_dec 
// loops can only be of for_loop
loops : for_loop
// operations are or add or sub or updation(increment)
operations : addition | subtraction | updation
// print statement start
// the syntax is as " show("string_literal" , ID) ; "
printstatements : PRINT OPEN_BRACKET_ROUND STRING COMMA IDENTIFIER CLOSE_BRACKET_ROUND SEMICOLON
{
  cout << "bison found an print decleration as : " ;
  cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << " " << $7 <<endl ;
};
// print statement ends

// functions starts
functions : functionDefination | functionDecleration | functionCall

functionDecleration : DEFINE VOID IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND SEMICOLON
{
  cout << "bison found an fucntion decleration  as : " ;
  cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 <<endl ;
};
functionDefination: DEFINE VOID IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND OPEN_BRACKET_CURLY body_section CLOSE_BRACKET_CURLY
{
  cout << "bison found an fucntion Defination  as : " ;
  cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << $8 << " " <<endl ;
};

functionCall : IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND SEMICOLON
{
  cout << "bison found an fucntion Call  as : " ;
  cout << $1 << " " << $2 << " " << $3 << " " << $4 << endl ;
};
// functions ends 

// declerations starts
// the syntax is as "put integer_num into integerContainer con_name ;"
integer_dec: PUT INT INTO INT_CON IDENTIFIER SEMICOLON
{ cout << "bison found an INTEGER decleration as : " ;
	cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << endl ;
};
// the syntax is as "put float_num into floatContainer con_name ;"
float_dec  : PUT FLOAT INTO FLOAT_CON IDENTIFIER SEMICOLON
{ cout << "bison found an FLOAT decleration as : " ;
	cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << endl ;
};
// the syntax is as "put string into stringContainer con_name ;"
string_dec  : PUT STRING INTO STRING_CON IDENTIFIER SEMICOLON
{	cout << "bison found an STRING decleration as : " ;
	cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << endl ;
};
// declarations ends

// for loop starts
// the syntax is as "repeatUntil ( ID isLessThan INT ) { body_section } "
// the for loop body can have single or multiple body statements
for_loop : FOR_LOOP_KEYWORD OPEN_BRACKET_ROUND IDENTIFIER FOR_LOOP_COND INT CLOSE_BRACKET_ROUND OPEN_BRACKET_CURLY body_section CLOSE_BRACKET_CURLY
{
    cout << "bison found a for loop decleration as : " ;
    cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << " " << $7 << " " << " " << $9 << endl ;
};
// for loop ends

// operations starts
// the syntax is as "add ID and ID into ID ; "
addition : ADD IDENTIFIER AND IDENTIFIER INTO IDENTIFIER SEMICOLON
{
	cout << "bison found an addition decleration as : " ;
	cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << " " << $7 << endl ;
};
// the syntax is as "sub ID and ID into ID ; "
subtraction : SUB IDENTIFIER AND IDENTIFIER INTO IDENTIFIER SEMICOLON
{
	cout << "bison found an subtraction decleration as : ";
	cout << $1 << " " << $2 << " " << $3 << " " << $4 << " " << $5 << " " <<  $6 << " " << " " << $7 <<endl ;
};
// the syntax is as "updateINC ID ; "
updation : UPDATE IDENTIFIER SEMICOLON
{
	cout << "bison found an updation decleration as : " ;
	cout << $1 << " " << $2 << " " << $3 << endl ;
};
// operations ends

//footer starts
// the syntax is as " pedestal end string_literal ; "
footer: PEDESTAL_END STRING SEMICOLON
{
	cout << "Terminated a Pedestal Program Named As -> " << $1 << $2 << $3 << endl;
  //fprintf(yyout,"terminated a pedestal program named as : %s %s %s \n", $1, $2,$3);
};
//footer ends
%%

int main(int, char**) 
{
  // opening the files for read and write.
  FILE *myfile_read = fopen("source.pd", "r"); // read, input file
  //FILE *myfile_write = fopen("source_TokenOut.txt","w"); // read, output file

  // file error handling
  if (!myfile_read)
  {
    cout << "can't open source.pd!" << endl;
    return -1;
  }
  //if (!myfile_write) {
    //cout << "can't open source_TokenOut.txt!" << endl;
    //return -1;
  //}

  // setting flex to read from input file
  yyin = myfile_read;
  //yyout = myfile_write;

  // Parse :
  yyparse();

  fclose(yyin); // closing the input file
  //fclose(yyout); // closing the output file

}

void yyerror(const char *s) 
{
  //yyclearin;
  cout << " Parse Error! :  " << s << endl;
  exit(-1);
}

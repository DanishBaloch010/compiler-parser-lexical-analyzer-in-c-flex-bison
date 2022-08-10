// our language named as pedestal CFG
//pedestal: header body_section footer
//header: PEDESTAL_START STRING SEMICOLON 
//body_section: body_statements | null ;
//body_statements: body_statement | body_statements body_statement | error;
//body_statement: declerations | loops | operations | printstatements | functions ;
//declerations: integer_dec | float_dec | string_dec;
//loops : for_loop;
//operations : addition | subtraction | updation;
//int_dec - > PUT INT INTO INT_CON ID SEMICOLON
//float_dec - > PUT FLOAT INTO FLOAT_CON ID SEMICOLON
//string_dec  -> PUT STRING INTO STR_CON ID SEMICOLON
//for_loop -> FOR_LOOP_KEYWORD OPEN_BRACKET_ROUND IDENTIFIER FOR_LOOP_COND INT CLOSE_BRACKET_ROUND OPEN_BRACKET_CURLY body_section CLOSE_BRACKET_CURLY
//addition -> ADD IDENTIFIER AND IDENTIFIER INTO IDENTIFIER SEMICOLON
//subtraction : SUB IDENTIFIER AND IDENTIFIER INTO IDENTIFIER SEMICOLON
//updation : UPDATE IDENTIFIER SEMICOLON
//printstatements : PRINT OPEN_BRACKET_ROUND STRING COMMA IDENTIFIER CLOSE_BRACKET_ROUND SEMICOLON
//functions : functionDefination | functionDecleration | functionCall
//functionDecleration : DEFINE VOID IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND SEMICOLON
//functionDefination: DEFINE VOID IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND OPEN_BRACKET_CURLY body_section CLOSE_BRACKET_CURLY
//functionCall : IDENTIFIER OPEN_BRACKET_ROUND CLOSE_BRACKET_ROUND SEMICOLON
//footer: PEDESTAL_END STRING SEMICOLON




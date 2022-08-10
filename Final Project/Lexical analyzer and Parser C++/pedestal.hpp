#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// tokenizer functions
void createFile();
bool numerics(const std::string &str);
bool commentChecker(const std::string &str);
bool seperatorChecker(const std::string &str);
bool identifierChecker(const std::string &str);
bool boolChecker(const std::string &str);
bool stringConst(const std::string &str);

bool statementChecker(const std::string &str);
bool invalidChecker(const std::string &str);
bool operatorChecker(const std::string &str);

void tokenizer(const std::string &nameOfFile);
void printTokens(const vector<std::string>& tokens);
bool keywordChecker(const std::string &str);

// parser functions
void pedestal();
void header();

void body_section();
void body_statements();
void body_statement();

void declerations();
void loops();
void operations();
void printstatements();
void functions();

void int_dec();
void float_dec();
void string_dec();

void for_loop();

void addition();
void subtraction();
void updation();

void functionDefination();
void functionDecleration();
void functionCall();

void footer();

void parse();

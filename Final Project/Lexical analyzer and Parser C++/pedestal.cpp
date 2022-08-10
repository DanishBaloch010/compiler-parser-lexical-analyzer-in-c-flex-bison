#include "pedestal.hpp"
#include <fstream>
using namespace std;
// cs182019  Leader Danish Baloch 
// cs182008  Leader Sarfaraz Ahmed
// cs182041  Leader Shehmeer Ashfaq

ofstream fout;
ofstream tokens_out;
ofstream array_out;

bool syntax_correct = false;
bool addition_syntax_check = true;

int counter = 0;

string array[1000]={};
bool identifierChecker(const std::string &str)
{	
	// rule : if identifier is starting with number than return a error
	if(std::isdigit(str[0]))
		return false;

	int counter = 0;
	if(str[0] == '_')
	    counter++;
	
	for(; counter < str.size(); counter++)
		if(!(isalnum(str[counter])))
	    	return false;

	return true;
}

bool commentChecker(const string &str)
{
 	return str == "/*" || str == "//";
}

bool numerics(const string &str)
{
	
  	return all_of(str.begin(), str.end(), ::isdigit);
}

bool stringConst(const string &str)
{
  	return str[0] == '"' && str.back() == '"';
}

bool boolChecker(const string &str)
{
  	return str == "true" || str == "false";
}

bool keywordChecker(const string &str)
{
  	const vector<string> keywords{"integerContainer", "stringContainer" ,"put","into","show","pedestal","start","end","define","void"};
  	for(const auto& keyword : keywords)
  		if (keyword == str)
    		return true;

  	return false;
}

bool statementChecker(const string &str)
{
 	const vector<string> statements{"repeatUntil"};
 	for(const auto& statement : statements)
 		if (statement == str)
    	  	return true;

  	return false;
}

bool operatorChecker(const string &str)
{
  	const vector<string> operators{"isLessThan", "isGreaterThan", "isEqualnLessthan", "isEqualnGreaterThan", "mul", "add", "sub", "div", "equalto", "preSub", "preMul", "preAdd", "preDivide", "updateInc", "updateDec", "IsEqualto"};
  	// iterating through vector
 	for(const auto &op: operators)
 	{
 	 	if (op == str)
 	 	{
 	 		return true;
		}		
  	}
	
	return false;	
}

bool seperatorChecker(const string &str)
{
  	const vector<string> Separators{"{", "}", ",", "(", ")", ";"};
  	for(const auto& separate: Separators)
  		if (separate == str)
      		return true;
      
 	return false;
}

bool invalidChecker(const string &str)
{
  	return str == " " || str == "\n" || str == "\t";
}

void createFile()
{
	fout.open("tokens.txt");
	tokens_out.open("only_tokens.txt");
	array_out.open("array_out.txt");
}
int a=0;
void printTokens(const string& token)
{
	if(operatorChecker(token))
	{
		cout << "operator --> " << token  << endl;
		fout << "operator --> " << token  << endl;
		
		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
	
  	else if(seperatorChecker(token))
  	{
  		cout << "separator --> " << token << endl ;
  		fout << "separator --> " << token  << endl;
  		
  		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  	else if (numerics(token))
  	{
  		cout << "digit --> " << token << endl;
  		fout << "digit --> " << token  << endl;
  		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  		
  		
  	else if(keywordChecker(token))
  	{
  		cout << "keyword --> " << token << endl;
  		fout << "keyword --> " << token  << endl;
  		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  	 
  	  
  	else if(statementChecker(token))
  	{
  		cout << "statement --> " << token << endl;
  		fout << "statement --> " << token  << endl;
  		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  	 	
  	 	
  	else if (boolChecker(token))
  	{
  		cout << "boolean  --> " << token << endl;
  		fout << "boolean --> " << token  << endl;
  			tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  		
  		
  	else if(stringConst(token))
  	{
  		cout << "string Constant --> " << token  << endl ;
  		fout << "string Constant --> " << token  << endl;
  		tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
  	 	
  	else if(identifierChecker(token))
  	{
  		cout << "identifier --> " << token << endl;
  		fout << "identifier --> " << token  << endl;
  			tokens_out << token <<endl;
		array[a] = token;
		a++;
		array_out << token <<endl;
	}
      	
  	else if(commentChecker(token))
  	{
  		cout << "comment --> " << token << endl;
  		fout << "comment --> " << token  << endl;
  		tokens_out << token <<endl;
  		
	}
   	
  	else
  	{
	  
  		cout<<"---------------------------------------------------------\n";
    	cout << (" --->>           xX Invalid token Xx: " + token +"\n");
    	cout<<"---------------------------------------------------------\n";
    	fout<<"---------------------------------------------------------\n";
    	fout<< (" --->>           xX Invalid token Xx: " + token +"\n");
    	fout<<"---------------------------------------------------------\n";
    	
    	tokens_out << "Invalid -- > " << token <<endl;
    }
}

int i =0;
void parse()
{	
    pedestal();
}
void pedestal()
{
//	int i=0;
	header();
	body_section();
	footer();
	
	if(syntax_correct == false)
	{
		cout <<" Syntax Error  !" <<endl;
		exit(1);
	}
}

void header()
{
//	int check = 0;
	if(array[i]=="pedestal" && array[i+1]=="start")
	{
		string str_iteral=array[i+2];
		if(str_iteral[0] == '"' && str_iteral.back() == '"')
		{
			if(array[i+3]==";")
			{
				cout << "This is in Header Grammar as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << endl;
				i = i+4;
			}
			else
			{
				cout << "Error.. Put Semicolon In Header" << endl;			
				exit(1);	
			}
		}
		else
		{
			cout<< "Error..PLEASE DEFINE HEADER..";
			exit(1);
		}
	}
	else
	{
		cout <<" ERROR ! INCLUDE Header  !" <<endl;
		exit(1);
	}	
}
int MainBodysingleStatement = 0;
int yes = 1 ;
int for_LoopBody = 0;
int fucntionBody=0;
void body_section()
{	
	syntax_correct = false;
	if(array[i-1]=="{")
	{
		for_LoopBody = 0;
		if(array[i]=="put"||array[i]=="repeatUntil"||array[i]=="updateInc"||array[i]=="add"||array[i]=="show")
		{
			for_LoopBody++;
			while(array[i]=="put"||array[i]=="repeatUntil"||array[i]=="updateInc"||array[i]=="add"||array[i]=="show")
			{
				body_statements();
			}
			syntax_correct = false;

		}
		else if(for_LoopBody == 0)
		{
			syntax_correct = false;
			cout << "Warning...The BODY Is Empty.." <<endl;
		}
	}
	if(array[i]=="put"||array[i]=="repeatUntil"||array[i]=="updateInc"||array[i]=="add"||array[i]=="show"||array[i]=="define"||array[i-1]=="(")
	{	
		MainBodysingleStatement++;
		while(array[i]=="put"||array[i]=="repeatUntil"||array[i]=="updateInc"||array[i]=="add"||array[i]=="show"||array[i]=="define"||array[i-1]=="(")
		{
			body_statements();
		}
		syntax_correct = false;
	}
	else	
	{
		if(MainBodysingleStatement == 0)
		{
			syntax_correct = false;
			cout << "Warning...The Main Body Section Is Empty.." <<endl;
		}
	}
}
void body_statements()
{
	// for one statement
	if(MainBodysingleStatement == yes)
	{
//		syntax_correct = false;
		body_statement();			
	}
	else if(for_LoopBody == yes)
	{
//		syntax_correct = false;
		body_statement();
	}	
	// for multiple statements
	else
	{
//		syntax_correct = false;
		body_statements();
		body_statement();
	}
	
}
void body_statement()
{
	syntax_correct = false;
	declerations();
	loops();
	operations();
	printstatements();
	functions();
	
	// if didnnt mapped on any Production in CFG than terminate
	if(syntax_correct == false)
	{
		cout<< "Syntax Error !" <<endl;
		exit(1);
	}
	
}
void declerations()
{
	int_dec();
	float_dec();
	string_dec();
}

void int_dec()
{
	if(array[i]=="put")
	{
		if(array[i+2]=="into")
		{		
			if(array[i+3]=="integerContainer")
			{		
				if(array[i+5]==";")
				{
					cout<< "This is defined in integer_dec production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<< endl;
					i=i+6;
					syntax_correct = true;
				}
			}
		}
	}
	
}
void float_dec()
{
	if(array[i]=="put")
	{
		if(array[i+2]=="into")
		{
			if(array[i+3]=="floatContainer")
			{
				if(array[i+5]==";")
				{
					cout<< "This is defined in float_dec production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<< endl;
					i=i+6;
					syntax_correct = true;
				}
			}

		}
		
	}
} 

void string_dec()
{
	if(array[i]=="put")
	{
		if(array[i+2]=="into")
		{
			if(array[i+3]=="stringContainer")
			{
				if(array[i+5]==";")
				{
					cout<< "This is defined in string_dec production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<< endl;
					i=i+6;
					syntax_correct = true;
				}
	
			}
		}	
	}	
}
void loops()
{
	for_loop();
}
void for_loop()
{
	if(array[i] == "repeatUntil")
	{
		if(array[i+1]=="(")
		{
			if(array[i+3]=="isLessThan")
			{
				if(array[i+5]==")")
				{
					if(array[i+6] == "{")
					{
						string key= array[i];
						string OB= array[i+1];
						string ID = array[i+2];
						string cond= array[i+3];
						string num= array[i+4];
						string CB= array[i+5];
						string CO = array[i+6];
						i=i+7;
						body_section();
						if(array[i] == "}")
						{
							
							cout<< "This is in for_loop production as : " << key << " " << OB << " " << ID << " " << cond << " " << num << " " << CB << " " << CO << " " << array[i]<<endl;
							i=i+1;
							syntax_correct = true;
							
						}
					}
				}
			}
		}
	}
	else
	{
		return;
	}
}
void operations()
{	
		addition();	
		//subtraction();
		updation();

}
void addition()
{
	if(array[i] == "add")
	{
		if(array[i+2]=="and")
		{
			if(array[i+4]=="into")
			{
				if(array[i+6]==";")
				{
					cout<< "This is in addition production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<<" " <<array[i+6]<< endl;
					i=i+7;
					syntax_correct = true;
				}
			}	
		}
	}
	else
	{
		return;
	}
}
void updation()
{	
	if(array[i] == "updateInc")
	{
		if(array[i+2]==";")
		{
			cout << "This is in updation production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << endl; 
			i=i+3;
			syntax_correct = true;
		}
	}
	else
	{
		return;
	}
}
void printstatements()
{
	if(array[i] == "show")
	{
		if(array[i+1]=="(")
		{
			if(array[i+3]==",")
			{
				if(array[i+5]==")")
				{
					if(array[i+6]==";")
					{
						cout<< "This is in print production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<<" " <<array[i+6]<< endl;
						i = i + 7;
						syntax_correct = true;
						
					}
				}	
			}
	 	
		}
	}
	else
	{ 
		return;
	}
}
void functions()
{
	functionDefination();
	functionDecleration();
	functionCall();
}

void functionDefination()
{
	if(array[i]=="define")
	{
		if(array[i+1]=="void")
		{
			if(array[i+3]=="(")
			
				if(array[i+4]==")")
				{
					if(array[i+5]=="{")
					{
						string define= array[i];
						string VOID= array[i+1];
						string funcname = array[i+2];
						string OR= array[i+3];
						string CR= array[i+4];
						string CO= array[i+5];
						i=i+6;
						body_section();
						if(array[i] == "}")
						{
							cout<< "This is in function defination as : " << define << " " << VOID << " " << funcname << " " << OR << " " << CR << " " << CO << " " << array[i]<<endl;
							i=i+1;
							syntax_correct = true;
						}
					}
				}
			}
	}
	else
	{
		return;
	}
}
void functionCall()
{
	if(array[i+1]=="(")
	{
		if(array[i+2]==")")
		{
			if(array[i+3]==";")
			{
				cout<< "This is defined in fucntion call  as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3]<< endl;
				i=i+4;
				syntax_correct = true;
			}
		}
	}
	else
	{
		return;
	}
}
void functionDecleration()
{
	if(array[i]=="define")
	{
		if(array[i+1]=="void")
		{
			if(array[i+3]=="(")
			{
				if(array[i+4]==")")
				{
					if(array[i+5]==";")
					{
						cout<< "This is defined in fucntion decleration  as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << " " << array[i+4] << " " << array[i+5]<< endl;
						i=i+6;
						syntax_correct = true;
					}
				}
			
			}
		}
	}
	else
	{
		return;
	}
}

void footer()
{
	if(array[i]=="pedestal" && array[i+1]=="end")
	{
		string str_literal = array[i+2];
		if(str_literal[0] == '"' && str_literal.back() == '"')
		{
			if(array[i+3]==";")
			{
				cout << "This is in Footer production as : " << array[i] << " " << array[i+1] << " " << array[i+2] << " " << array[i+3] << endl;
				i=i+4;
				syntax_correct = true;
				cout << "Succesful Parsing.." ;
				exit(1);
			}
			else
			{
				cout << "Error.. Put Semicolon In Footer." << endl;
				exit(1);
			}
		}
		else
		{
				cout<< "Error..PLEASE DEFINE FOOTER..";
				exit(1);
		}
	}
//	else
//	{
//		cout <<" Syntax Error  !" <<endl;
//		exit(1);
//	}
}

void tokenizer(const string &fileName)
{
	createFile();
  	char ch;
  	string buffer;
  	fstream fin(fileName, fstream::in);

  	if (!fin.is_open())
  	{
  	  cout << "FILE ERROR !!\n";
  	  exit(0);
  	}
	bool multiLineComment = false;
  	bool signgleLineComment = false;
 	while (fin >> noskipws >> ch)
	{
 		if(signgleLineComment || multiLineComment){
 	     	if(signgleLineComment && ch == '\n')
 	   	    	signgleLineComment = false;
	
	     	if(multiLineComment && ch == '*')
	     	{
	       		fin >> ch;
	        	if(ch == EOF)
	          	break;
	
	        	if(ch == '/')
	          	multiLineComment = false;
	      	}
	      	continue;
	    }

	    if(ch == '/')
		{
	     	string comm(1, ch);
	     	fin >> ch;
	     	if(ch == EOF)
	     	{
	     		printTokens(comm);
	        	break;
	      	}

	      	if(ch == '*')
	      	{
	      	  	multiLineComment = true;
	      	  	comm += ch;
	      	}
	    	else if(ch == '/')
	    	{
	        	signgleLineComment = true;
   	    		comm += ch;
   	  		}
   	  		
   	   		if(multiLineComment || signgleLineComment)
   	  		{
   	    		printTokens(comm);
   	     		continue;
   	   		}
   	 	}

   		if(invalidChecker(string(1, ch)))
   	 	{
   	 	  	if(!buffer.empty())
   	 	  	{
   	 	  		printTokens(buffer);
   	 	  	 	buffer = "";
   	 	 	}
   	 	  	continue;
   	 	}

   		if(operatorChecker(string(1, ch)) && !operatorChecker(buffer))
    	{
      		if(!buffer.empty())
     		{
        		printTokens(buffer);
        		buffer = "";
      		}
    	}

    	if(!operatorChecker(string(1, ch)) && operatorChecker(buffer))
    	{
    	 	printTokens(buffer);
    		buffer = "";
    	}

   		if(seperatorChecker(string(1, ch)))
    	{
      		if(!buffer.empty())
      		{
      			printTokens(buffer);
      			buffer = "";
     		}
      		if(seperatorChecker(string(1, ch)))
      		{
        		printTokens(string(1, ch));
        		continue;
      		}
    	}
    	buffer += ch;
  	}
  	
  	int all_tokens = a ;
  	
  	fin.clear();
 	fin.close();
    fout.clear();
    fout.close();
    tokens_out.clear();
    tokens_out.close();
	array_out << "Total Tokens Are ---> " << all_tokens << endl<<endl;
    array_out.clear();
    array_out.close();
    
	cout << "Total Tokens Are -- > " << all_tokens << endl<<endl;
	
	cout << "<--- SYNTAX ANALYZER --- >"<<endl<<endl;
	parse();
    
}

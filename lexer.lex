%option noyywrap
%option noinput
%option nounput

%{
#include<iostream>
#include<cstdlib>
#include "Set.hpp"
#include "function.hpp"
#include<string>
using namespace std;
#include "parser.tab.hpp"
%}


%%
"to" return to__token;
"print" return print_token;
"check" return check_token;
"function" return function_token;
"sin" return sin_token;
"cos" return cos_token;
"x" return x_token;
"\\/" return unija_token;
"/\\" return presek_token;
"\\" return razlika_token;
"card" return card_token;
"UniversalSet" return universal_token;
"power_set" return partitive_token;
[0-9]+([\.][0-9]*)? {yylval.d=atof(yytext); return num_token;}
[A-Z]+[0-9]* {yylval.s=new string(yytext); return id_token;}
[a-z]+[0-9]* {yylval.s=new string(yytext); return idfun_token;}
[+\-*{}:<,;=()~\n\"\[\]] {return *yytext;}
[ \t] { }

.   {
    cerr<<"\tunknown character : "<<*yytext<<endl;
    exit(EXIT_FAILURE);
    }

%%

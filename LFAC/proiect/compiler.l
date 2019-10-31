%{
    #include "y.tab.h"
	#include <string>
	#include <string.h>
	#include <ctype.h>
    #include <stdlib.h>
	#include <iostream>
	using namespace std;
    void yyerror(char *);

	
%}



%%

"int"                           { return TYPEINT; }
"long"                          {return TYPELONG;}
"float"                         {return TYPEFLOAT;}
"double"                        {return TYPEDOUBLE;}
"char"                          {return TYPECHAR;}

"while(f!=0)"							{return WHILE;}
"if"							{return IF;}
"for"							{return FOR;}
"else"							{return ELSE;}

"printf"[ \t\n]*"(".*?";"       { yylval.cval = strdup(yytext); return PRINTF;}

"return"[ \t\n]+.*?";"          {return RETURN;}
"int"[ \t\n]+"main"[ \t\n]*"("[.]*")"        {return MAIN;}
"void"[ \t\n]+"main"[ \t\n]*"("[.]*")"        {return MAIN;}
"void"                          {return VOID;}
"#".*?">"                       {}
[{}]                            {}



[0-9]+                          { yylval.ival = atoi(yytext);  return INTVAL; }
[0-9]*"."[0-9]+                 { yylval.fval = atof(yytext);  return FLOATVAL; }
"'"[a-zA-z0-9]"'"               { yylval.cval = strdup(yytext); return CHARVAL; }


[a-zA-Z_][a-zA-Z0-9_]*{0,31}    { yylval.cval = strdup(yytext);   return VAR;}

[=]                             {return EQ;}
[;]                             {return SEM;}


[\n]                            {}

[ \t\n]+                        {}

.                              {return yytext[0];}

%%


int yywrap(void) {
    return 1;
}


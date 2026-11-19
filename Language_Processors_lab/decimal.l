
%{
#include <stdio.h>
%}

%%
[0-9]+(\.[0-9]+)?  { printf("Valid Number: %s\n", yytext); }
[ \t\n]+           ;
.                  { printf("Invalid Input: %s\n", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}

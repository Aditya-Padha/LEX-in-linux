//Write a lex code that removes spaces, tabs, lines from a given input file and write the remaining content into the output file. 

%{
#include <stdio.h>
%}

%%
[ \t]+   {}
[\n]+   {}
.   { fprintf(yyout, "%c", yytext[0]); }   
%%

int main() {
    FILE* input = fopen("input.txt", "r");
    if (!input) {
        printf("Unable to open input file\n");
        return 1;
    }
    FILE* output = fopen("output.txt", "w");
    if (!output) {
        printf("Unable to open output file\n");
        fclose(input);
        return 1;
    }
    yyin = input;
    yyout = output;
    yylex();
    fclose(input);
    fclose(output);
    return 0;
}
int yywrap(){
	return 1;
} 

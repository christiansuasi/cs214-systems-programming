/*Christian Suasi & Alec Fray
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
	char* input;
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate( char * ts ) {
	TokenizerT* token = malloc(sizeof(ts));
	token->input = ts;
	return token;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk ) {
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( TokenizerT * tk ){

	char *draft = tk->input; 
	int i = 0;
	int j = 0;
	char *word;
	int *dec = 0;
	int *oct = 0;
	int *hex = 0;
	
	//loop through each char in raw input string
	while(draft[i]!='\0'){

		//getting a word
		if( isalpha(draft[i])>0 && draft[i+1]!='\0' ){
			word[j] = draft[i];
			j++;
		}else{
			printf("word \"%s\"\n", word);
			return word;
		}
  	
		//binary operator switch table	
		switch(draft[i]){
			case '(' :
				printf("left paranthesis \"(\"\n");
				break;
			case ')' :
				printf("right paranthesis \")\"\n");
				break;
			case '[' :
				printf("left bracket \"[\"\n");
				break;
			case ']' :
				printf("right braket \"]\"\n");
				break;
			case '*' :
				printf("indirect or multiply \"*\"\n");
				break;
			case '&' :
				printf("address or bitwise and \"&\"\n");
				break;
			case '-' :
				printf("minus or subtract \"-\"\n");
				break;
			case '!' :
				printf("negate \"!\"\n");
				break;
			case '~' :
				printf("1's compliment \"~\"\n");
				break;
			case '+' :
				printf("add \"+\"\n");
				break;
			case '^' :
				printf("bitwise exclusive or \"^\"\n");
				break;
			case '|' :
				printf("bitwise or \"|\"\n");
				break;
			case '/' :
				printf("divide \"/\"\n");
				break;
			case '<' :
				printf("less than \"<\"\n");
				break;
			case '>' :
				printf("greater than \">\"\n");
				break;
			case '%' :
				printf("modulus \"%\"\n");
				break;
			case '\\' :
				printf("escape character \"\\\"\n");
				break;
		
			default :
				break;
			
		}



		i++;
	}
	
		
  return NULL;
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
	
	//argc stores number of command line args
	//argv stores the position of actual arg
	
	if( argc==2 ){
		printf("argument is %s\n", argv[1]);
	}else{
		printf("missing string input argument\n");
		exit(1);
	}

	
	//take input from command line
	char *inputString;	
	inputString = argv[1];;	
	//tokenize string
	
	TokenizerT *tok = TKCreate(inputString);
	TKGetNextToken( tok );
	//printf("print out %s\n", TKGetNextToken(tok));

	//print out each token
	//loop through tkgetnextoken
	//finish

	return 0;
}

//Tokenizer Lab for Theory of Operating Systems
//By: Jorge Dominguez (jdominguez11@miners.utep.edu)

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int stringLength(char* string){ //function that returns the length of a string
    int i =0;
    while(string[i] && string[i] != '\n') i++;
    return i;
}

int getNumberOfTokens(char* string, char delim)  //function that returns the number of tokens in a given string with the given delimiter
{
    int tokens = 0;
    int inToken = 0;
    for(int i = 0; i<stringLength(string);i++)
    {
    	char current = (char)string[i];
    	if(current == delim){ //if the current char is the delimiter we are not in a token
    		inToken = 0;
    		continue;
    	}
    	else{
    		if(inToken==0){ //we are not in a delimiter character and we were not in a token before (we are in a new token)
    			inToken = 1;
    			tokens++;
    		}
    	}
    }
    return tokens;
}

char *strcpy(char *s1, const char *s2) //function to copy a string I found online
{
    char *s = s1;
    while ((*s++ = *s2++) != 0)
    ;
    return (s1);
}

char ** mytoc(char *str, char delim)
{
    int tokens = getNumberOfTokens(str, delim);
    printf("%d tokens \n", tokens);

    char** r = (char **)malloc(sizeof(char*) * (tokens + 1));
    int lengthmap[tokens+1]; //create an array that holds the length of each token
    char* tokvector[tokens+1]; //array that will hold the tokens themselves

    int x = 0;
    while(x<tokens) //initialize the token length array to 0
    {
        lengthmap[x]=0;
        x++;
    }

    int inToken=0; //variable to indicate if we are currently in a token
    int currentToken = -1; //current token
    int tokenpos = 0; //position of token

    for(int j=0;j<stringLength(str);j++) //iterate whole string
    {
        char current = (char)str[j];
        if(current == delim){ //if the current char is the delimiter we are not in a token
            inToken = 0;
            continue;
        }
        else{
            if(inToken==0){ //if its not delimiter and we where not in a token
                tokenpos = 0; //we are at initial position of new token
                inToken = 1; //we are in a token
                // tokenlength=1;
                currentToken++; //increment current token

                // printf("token init ct[%d][%d] \n", currentToken, tokenpos);

                lengthmap[currentToken] = tokenpos+1; //store length of token
            }
            else{ //if not we are in an old token
                // tokenlength++;
                tokenpos++; //increment token position
                // printf("token increment ct[%d][%d] \n", currentToken, tokenpos);
                lengthmap[currentToken] = tokenpos+1; //store length of token
            }
        }
    }

    x = 0;
    while(x<tokens) //iterate number of tokens
    {
        char t[lengthmap[x]]; //initialize char array with length of token
        tokvector[x]= t; //store into our collection of tokens
        // strcpy() //i want to store the token by copying the chars
        x++;
    }

    for(int j =0;j<tokens;j++) //prints length of tokens
    {
        printf("[%d] = %d \n",j,lengthmap[j]);
    }
    r[tokens+1] = 0;
    return r;
}

int main(int argc, char **argv)
{
    char data[100];

    if(read(0, data, sizeof(data)) < 0) //read shell input into "data" buffer
    {
    	write(2, "An error occurred in the read.\n", 31); //display error message if something went wrong
    }
    else{
    	char** test = mytoc(data, ' '); //initialize tokenizer array to our mytoc function

    	// write(2, test[0], 30);
    }
    exit(0); //exit
}
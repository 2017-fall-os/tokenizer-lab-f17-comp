#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int stringLength(char* string){
    int i =0;
    while(string[i] && string[i] != '\n') i++;
    return i;
}

int getNumberOfTokens(char* string, char delim)
{
    int tokens = 0;
    int inToken = 0;
    for(int i = 0; i<stringLength(string);i++)
    {
    	char current = (char)string[i];
    	if(current == delim){
    		inToken = 0;
    		continue;
    	}
    	else{
    		if(inToken==0){
    			inToken = 1;
    			tokens++;
    		}
    	}
    }
    return tokens;
}

char *strcpy(char *s1, const char *s2)
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
    int lengthmap[tokens+1];
    char* tokvector[tokens+1];

    int x = 0;
    while(x<tokens)
    {
        lengthmap[x]=0;
        x++;
    }

    int inToken=0;
    int currentToken = -1;
    int tokenpos = 0;

    for(int j=0;j<stringLength(str);j++)
    {
        char current = (char)str[j];
        if(current == delim){
            inToken = 0;
            continue;
        }
        else{
            if(inToken==0){
                tokenpos = 0;
                inToken = 1;
                // tokenlength=1;
                currentToken++;
                // printf("token init ct[%d][%d] \n", currentToken, tokenpos);

                lengthmap[currentToken] = tokenpos+1;
            }
            else{
                // tokenlength++;
                tokenpos++;
                // printf("token increment ct[%d][%d] \n", currentToken, tokenpos);
                lengthmap[currentToken] = tokenpos+1;
            }
        }
    }

    x = 0;
    while(x<tokens)
    {
        char t[lengthmap[x]];
        tokvector[x]= t;
        // strcpy()
        x++;
    }

    for(int j =0;j<tokens;j++)
    {
        printf("[%d] = %d \n",j,lengthmap[j]);
    }
    r[tokens+1] = 0;
    return r;
}

int main(int argc, char **argv)
{
    char data[100];

    if(read(0, data, sizeof(data)) < 0)
    {
    	write(2, "An error occurred in the read.\n", 31);
    }
    else{
    	char** test = mytoc(data, ' ');

    	// write(2, test[0], 30);
    }
    exit(0);
}
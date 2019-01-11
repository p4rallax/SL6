#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mtable
{
    char type[10];
    char mnemonic[10];
    char opcode[10];
    int length;
   
}mt[16];

typedef struct mtable mterm;

struct stable
{
    char symbol[10];
    char address[10];
}st[10];

typedef struct stable sterm;


    

int main()
{
    mterm mt[16];
    int i;
   
    strcpy(mt[0].mnemonic,"MOVER");
    strcpy(mt[0].type,"IS");
    strcpy(mt[0].opcode,"01");
    mt[0].length=1;
   
    strcpy(mt[1].mnemonic,"MOVEM");
    strcpy(mt[1].type,"IS");
    strcpy(mt[1].opcode,"02");
    mt[1].length=1;
   
    strcpy(mt[2].mnemonic,"ADD");
    strcpy(mt[2].type,"IS");
    strcpy(mt[2].opcode,"03");
    mt[2].length=1;
   
   strcpy(mt[3].mnemonic,"SUB");
    strcpy(mt[3].type,"IS");
    strcpy(mt[3].opcode,"04");
    mt[3].length=1;
    
    strcpy(mt[4].mnemonic,"MULT");
    strcpy(mt[4].type,"IS");
    strcpy(mt[4].opcode,"05");
    mt[4].length=1;
    
    strcpy(mt[5].mnemonic,"DIV");
    strcpy(mt[5].type,"IS");
    strcpy(mt[5].opcode,"06");
    mt[5].length=1;
    
     strcpy(mt[6].mnemonic,"COMP");
     strcpy(mt[6].type,"IS");
     strcpy(mt[6].opcode,"07");
     mt[6].length=1;
   
     strcpy(mt[7].mnemonic,"BC");
     strcpy(mt[7].type,"IS");
     strcpy(mt[7].opcode,"08");
     mt[7].length=1;
     
     
     strcpy(mt[8].mnemonic,"READ");
     strcpy(mt[8].type,"IS");
     strcpy(mt[8].opcode,"09");
     mt[6].length=1;
     
     
     strcpy(mt[9].mnemonic,"STOP");
     strcpy(mt[9].type,"IS");
     strcpy(mt[9].opcode,"10");
     mt[9].length=1;
     
     strcpy(mt[10].mnemonic,"START");
     strcpy(mt[10].type,"AD");
     strcpy(mt[10].opcode,"1");
     mt[10].length=1;
     
     strcpy(mt[11].mnemonic,"ORIGIN");
     strcpy(mt[11].type,"AD");
     strcpy(mt[11].opcode,"2");
     mt[11].length=1; 
     
     strcpy(mt[12].mnemonic,"EQU");
     strcpy(mt[12].type,"AD");
     strcpy(mt[12].opcode,"3");
     mt[12].length=1;
     
     
     strcpy(mt[13].mnemonic,"LTROG");
     strcpy(mt[13].type,"AD");
     strcpy(mt[13].opcode,"4");
     mt[13].length=1;
     
     
     strcpy(mt[14].mnemonic,"DS");
     strcpy(mt[14].type,"DL");
     strcpy(mt[14].opcode,"1");
     mt[14].length=1;
     
     strcpy(mt[15].mnemonic,"DC");
     strcpy(mt[15].type,"DL");
     strcpy(mt[15].opcode,"2");
     mt[15].length=1;
     
    
    
    printf("\nMnemonic Type\tOpcode\tLength");
    for(i=0;i<17;i++)
    {
         printf("\n\n%s\t %s\t%s\t %d\n",mt[i].mnemonic,mt[i].type,mt[i].opcode,mt[i].length);
    }
    
const char filename[] = "doc.txt";
    FILE *fp;
    i = 0;
    char *words = NULL;
    char *word = NULL;
    int c,flag;
    int j,k;
    char * allwords[50];
    if ((fp = fopen(filename, "r")) == NULL)
    {
        /*Where doc txt is a normal file with plain text*/
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }   
    while ((c = fgetc(fp)) != EOF)
    {   
        if (c == '\n')	
            c = ' '; 
        words = (char *)realloc(words, ++i * sizeof(char));
        words[i-1] = c;
    }   
    word = strtok(words, " ");
    while (word != NULL)
    {   
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }   
    
    
    printf("\n");
	
	for (j=0; j<i; j++)
    {
    	for (k=0; k<5; k++)
    	{
       		flag=strcmp(allwords[j],mt[k].mnemonic);
       		if(flag == 0)
       		{
       			printf("%s\t%s\t%s\n",mt[k].type,mt[k].mnemonic,mt[k].opcode);
       		}
       	}
	}
	
	printf("\n");
    return(0);
}



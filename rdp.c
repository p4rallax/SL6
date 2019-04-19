#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
char token,stmt[20];
int i;
int EXP();
int ASSIGN();
int FACTOR();
int TERM();
// assumes no spaces in the statement
// assumes variable length 1
// assumes integer constant of length 1
main()
{
 int succ,l;
 clrscr();
 printf("\n enter assignment statement ");
 scanf("%s",stmt);
 i = 0;
 l = strlen(stmt);
 succ = ASSIGN();
 if((succ) && (i==l)) printf("valid assignment statement");
   else printf("invalid statement");
 getch();
 return(0);
}
int ASSIGN()
{
  int found;

  found = 0;
  token = stmt[i];
  if(isalpha(token))
	 {
	   token = stmt[++i];
	   if (token == '=')
	     {
	       token = stmt[++i];
	       if(EXP()) found = 1;
	     }
	 }
	if(found) return(1);
	    else return(0);
}
int EXP()
{
  int found = 0;
  if(TERM())
  {
    found = 1;
    while((token == '+') || (token =='-') && (found==1))
      {
	  token = stmt[++i];
	  if(!TERM()) found = 0;
      }
  }
  if(found) return(1);
     else return(0);
}
int TERM()
{
  int found = 0;
  if(FACTOR())
  {
    found = 1;
    while((token == '*') || (token =='/') && (found==1))
      {
	  token = stmt[++i];
	  if(!FACTOR()) found = 0;
      }
 }
  if(found) return(1);
    else return(0);
}
int FACTOR()
{
  int found = 0;
  if(isalpha(token)|| isdigit(token))
  {
    found = 1;
    token = stmt[++i];
   }
  else if (token == '(')
    {
      token = stmt[++i];
      if(EXP())
	if (token==')')
	  { found = 1; token = stmt[++i];}
     }
  if(found) return(1);
     else return(0);
}
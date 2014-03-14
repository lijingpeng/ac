#include <iostream>
using namespace std;
char str[2][11] ;
char spaces[11][11] = { 
      "",
      " ", 
      "  ", 
      "   ", 
      "    ",
      "     ",
      "      ",
      "       ",
      "        ",
      "         ",
      "          "
     };
int  main()
{
 int forward = 0 , k=0 , i ;
 while ( gets(str[++k%2]) )
 {
  i = 0;
  while ( str[k%2][i] == str[(k+1)%2][i] && str[k%2][i] )  ++i; 
  forward = ( ++forward > i ?  i : forward ) ;
  printf("%s%s\n",spaces[forward],str[k%2]);
 }
 return 0;
}

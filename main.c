#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// for Task 1
const int n=sizeof(int)*8;
char strdec1[(sizeof(int)*8)+1]="0                               \0";
int max;

// for Task 2
int res2=1;

int checkbit(const int value, const int position)
{
    int result;
    if ((value & (1 << position)) == 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

void DecToBin(int num,char* strb)
{
    //char strb[sizeof(int)*8]="";
    for (int i=0;i<n;i++)
    {
     if (checkbit(num,i)==1)
      strb[n-i-1]='1';
     else
      strb[n-i-1]='0';
    }
}

void DecToBinRec(int num,int pos)
{
 char temp;
 strdec1[pos]='\0';
 if (num==0) {max=pos; return;}
 if ((num%2)==0) temp='0';
 else temp='1';
 DecToBinRec(num/2,(pos+1));
 strdec1[max-pos-1]=temp;
 return;
}

int step(int a,int b) {
 if (b==0) return 1;
 int res=a;
 for (int i=1;i<b;i++) res*=a;
 return res;
}

int stepRec(int a,int b) {
 if (b==0) return 1;
 stepRec(a,--b);
 res2*=a;
 return res2;
}

// for Task 4
int stepRec2(int a,int b) {
 if (b%2==0) return stepRec(a*a,(b/2));
 return a*stepRec(a*a,(b-1)/2);
}


// for Task 5
#define HEIGHT 8
#define WIDTH 8

int board[HEIGHT][WIDTH];

int routes(int x,int y) {
 if (board[y][x]==0) {
  if (x==0 && y==0)
      return 1;
   else
    if (x==0 ^ y==0)
      return 1;
    else
      //      vertical       horizontal     diagonal
      return routes(x,y-1)+routes(x-1,y)+routes(x-1,y-1);}
 else return 0;
}

int ver_rand(int f) {
 return ( (rand()%100 > f) ? 0 : 1 );
}

void fill(int x, int y) {
    for (int i=0;i<y;++i)
     for (int j=0;j<x;++j)
      board[i][j]=ver_rand(10);
//        board[i][j]=0;

}

void printBoard(int x, int y) {
    for (int i=0;i<y;++i) {
     for (int j=0;j<x;++j)
      printf("%3d",board[i][j]);
     printf("\n");
    }
    printf("\n");
}

int main()
{
    // Task 1
     printf("\nTask 1\n");
     int a;
     printf("Enter number= ");
     scanf("%d",&a);
     char strdec[(sizeof(int)*8)+1]="                                \0";
     DecToBin(a, strdec);
     printf("Decimal number=%d, binary number=%s\n",a, strdec);
     DecToBinRec(a,0);
     printf("Decimal number=%d, binary number=%s\n",a, strdec1);

     // Task 2 & 3
     printf("\nTask 2 & 3\n");
     double a1,b1;
     printf("Enter number a = ");
     scanf("%lf",&a1);
     printf("Enter number b = ");
     scanf("%lf",&b1);
     printf("math: a^b=%f",exp(b1*log(a1)));
     printf("\niteration:  a^b=%d",step((int) a1, (int) b1));
     printf("\nrecursive:  a^b=%d",stepRec((int) a1, (int) b1));
     printf("\n");

     // Task 4
     printf("\nTask 4\n");
     res2=1;
     printf("\nfast recursive:  a^b=%d",stepRec2((int) a1, (int) b1));
     printf("\n");

     // Task 5
     srand(time(NULL));
     printf("\nTask 5\n");
     const int sizeX=5;
     const int sizeY=4;
     fill(sizeX,sizeY);
     board[0][0]=0;
     board[sizeY][sizeX]=0;
     printf("Output matrix with holes:\n\n");
     printBoard(sizeX,sizeY);
     printf("Number of king routes:\n\n");
     for (int y=0;y<sizeY;++y) {
      for (int x=0;x<sizeX;++x) {
       printf("%6d",routes(x,y));
      }
      printf("\n");
     }


     printf("\n");

    return 0;
}

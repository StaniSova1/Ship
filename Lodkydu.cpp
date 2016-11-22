#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int checkCode (int num);
void checkCodeUsingPtr(int *pnum);
void printArray(int array[8][8]);

	main() {
		
		int code1,code2,code3,code4;
		int field[8][8];
		int i,j;
		int position;
		int positionRow,positionCol;
		
		printf ("Welcome ! My name is Stanislav, I'm an author of this application.\n\n");
		printf ("Enter 1st code : ");
		scanf ("%d",&code1);
		printf ("Enter 2nd code : ");
		scanf ("%d",&code2);
		printf ("Enter 3rd code : ");
		scanf ("%d",&code3);
		printf ("Enter 4th code : ");
		scanf ("%d",&code4);
		
		code1=checkCode(code1);
		code2=checkCode(code2);
		checkCodePointer(&code3);
		checkCodePointer(&code4);
		
	//	printf ("\n%d %d %d %d",code1, code2, code3, code4);
	
for(j=7;j>=0;j--){
    int bit=code1 & 1;
    field[1][j]= bit *(-1);
    bit=code2 & 1;
    field[3][j]= bit *(-1);
    bit=code3 & 1;
    field[5][j]= bit *(-1);
    bit=code4 & 1; 
    field[7][j]= bit *(-1);
    code1=code1>>1;
    code2>>=1;
    code3>>=1;
    code4>>=1;
  }
  for(j=7;j>=0;j--){
    int bit=code1 & 1;   // bit=code1%2;
    field[0][j]= bit *(-1);
    bit=code2 & 1;   // bit=code2%2;
    field[2][j]= bit *(-1);
    bit=code3 & 1;   // bit=code3%2;
    field[4][j]= bit *(-1);
	bit=code4 & 1;   // bit=code4%2;
    field[6][j]= bit *(-1);
    code1>>=1;
    code2>>=1;
    code3>>=1;
    code4>>=1;
  }
  
  printArray(field);
  printf("\nEnter position of the ship <0;63> :");
  scanf("%d", &position);
  if(position<0 || position >63){
      printf("\nError. Wrong input: postion=%d",position);
      return 1;
  }
  
  positionRow=position/8;
  positionCol=position%8;
  if(field[positionRow][positionCol]==-1){
      printf("\nError. Wrong position - Island");
      return 2;
  }
  field[positionRow][positionCol]=-2;
  
  if(positionCol>0 && field[positionRow][positionCol-1]==0)
     field[positionRow][positionCol-1]=1;
  if(positionCol<7 && field[positionRow][positionCol+1]==0)
     field[positionRow][positionCol+1]=1;
  if(positionRow>0 && field[positionRow-1][positionCol]==0)
     field[positionRow-1][positionCol]=1;
  if(positionRow<7 && field[positionRow+1][positionCol]==0)
     field[positionRow+1][positionCol]=1;
  
  int count=1;

  while(count<39){
		  for(i=0;i<8;i++){
		     for(j=0;j<8;j++){
		         if(field[i][j]==count){
		         
				  if(j>0 && field[i][j-1]==0)
				     field[i][j-1]=count+1;
				  if(j<7 && field[i][j+1]==0)
				     field[i][j+1]=count+1;
				  if(i>0 && field[i-1][j]==0)
				     field[i-1][j]=count+1;
				  if(i<7 && field[i+1][j]==0)
				     field[i+1][j]=count+1;
				 }
			 }
		  }
		  count++;
  }
  
  printArray(field);
  
} 

int checkCode(int num){
     if(num>=0 && num<=pow(2,16)-1)  // interval <0;65535>
          return num;
     else
	      return 0;     
} 

void checkCodeUsingPtr(int *pnum){
     if(*pnum<0 || *pnum>(pow(2,16)-1))
         *pnum=0;
}

void printArray(int array[8][8]){
    int i,j;
    printf("\n ------------------------\n");
    
    for(i=0;i<8;i++){
       printf("|");
       for(j=0;j<8;j++){
           if(array[i][j]==0)
               printf("   ");
           else if(array[i][j]==-1)
               printf(" # ");
           else if(array[i][j]==-2) 
		       printf(" O ");   
		   else    
               printf("%2d ",array[i][j]);
       }
       printf("|\n");
	}
	printf(" ------------------------\n");
}

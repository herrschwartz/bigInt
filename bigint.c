#include <stdio.h>

void readBigint(int a[]);
void addBigint(int a[], int b[]);
void printBigint(int a[]);

const int SIZE = 100;

int main(){
  int int1[SIZE];
  memset(int1, 0, sizeof int1);
  readBigint( int1 );
  int int2[SIZE];
  memset(int2, 0, sizeof int2);
  readBigint( int2 );

  printf("%s", "First Int: " );
  printBigint(int1);
  printf("%s", "Second Int: " );
  printBigint(int2);
  addBigint(int1, int2);
  printf("%s", "Result: " );
  printBigint(int1);
  return 0;
}

void readBigint(int a[]){
  char in[SIZE];
  scanf("%s", in );
  int i;
  for (i=0; i<strlen(in); i++){
    a[SIZE-strlen(in)+i] = in[i] - '0';
  }
}

void addBigint(int a[], int b[]){
  int carry=0;
  int i;
  for(i = SIZE-1; i>=0; i--){
    int total = a[i] + b[i];
    if(carry == 0){
      a[i] = total%10;
      if(total > 9){
        carry = 1;
      } else {
        carry = 0;
      }
    } else {
      a[i] = (total+1)%10;
      if(total+1 > 9){
        carry = 1;
      } else {
        carry = 0;
      }
    }
  }
}

void printBigint( int a[] ){
  int j;
  for(j=0; j<SIZE-1; j++){
    if(a[j] != 0)
      break;
  }
  int i;
  for(i=j; i<SIZE; i++){
    printf("%d", a[i] );
  }
  printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void add(char a[],char b[],char result[]);
void karatsuba(char x[], char y[], char res[]);
void remove_zeros(char* a)
{
  int lena = strlen(a);
  int ind = 0;
  while (ind < lena && a[ind] == '0')
  {
    ++ind;
  }
  for (int i = ind; i < lena; ++i)
  {
    a[i - ind] = a[i];
  }
  a[lena - ind] = 0;
}
char* CreateArray(int len)
{
  char* res = malloc(len*sizeof(char));
  memset(res, '0', len);
  return res;
}
void sub(char* a, char* b, char* res)
{
  int lena = strlen(a);
  int lenb = strlen(b);
 
  //assert(lena >= lenb);
 
  int toSub = 0;
  for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
  {
    int x = a[inda] - '0';
    int y = indb >= 0 ? b[indb] - '0' : 0;
 
    if (toSub == 1)
    {
      x--;
    }
    int cur;
    if (x < y)
    {
      cur = x + 10 - y;
      toSub = 1;
    }
   else
   {
      cur = x - y;
      toSub = 0;
   }
 
    res[inda] = cur + '0';
  }
}
void mult10(char* a, int n)
{
  int lena = strlen(a);
  if (lena == 1 && a[0] == '0')
  {
    return;
  }
  for (int i = lena; i < lena + n; ++i)
  {
    a[i] = '0';
  }
  a[lena + n] = 0;
}
//----------------------------------------------------------------------------------------------------------
void main()
{
    char a[] = "1111";
    char b[] = "1111";

    char* result = CreateArray(20);
    
    
    printf("\n length == %d",strlen(result));
    printf("\na==%s",a);
    printf("\nb==%s", b);
    printf("\n >>result = %s", result);

    karatsuba(a,b,result);
    printf("result = %s\n", result);
    
   // karatsuba(a,b,result);

}
//----------------------------------------------------------------------------------------------------------

void add(char a[],char b[],char result[]){

    int i = strlen(a) ,carry = 0 , temp;
    int index_r = strlen(result) - 1;

    for (int i = strlen(a)-1; i >= 0; --i)
    {
        int val1 = a[i] - '0';
        int val2 = b[i] - '0';

        int ans = val1 + val2 + carry;

        if(ans >= 10){
            
            temp = ans % 10;
            result[index_r] = temp + '0'; 
            carry = ans/10;
        }
        else{
            result[index_r] =ans + '0';
        }
        index_r--;
    }

    result[index_r] = carry + '0';

}

void karatsuba(char x[], char y[], char res[]){

    int len = strlen(x);
    if (len == 1)
    {   
        int val = (x[0] - '0') * (y[0] - '0');
        if (val < 10) {
            res[0] = val + '0';
        }
        else
        {
            res[0] = (val / 10) + '0';    
            res[1] = (val % 10) + '0';
        }

    }
    else{
        char* xl = CreateArray(len);
        char* xr = CreateArray(len);
        char* yl = CreateArray(len);
        char* yr = CreateArray(len);


        int rightSize = len / 2;
        int leftSize = len - rightSize;
 
        strncpy(xl, x, leftSize);
        strcpy(xr, x + leftSize);
        strncpy(yl, y, leftSize);
        strcpy(yr, y + leftSize);
        int maxl = 3 * len;
        char* P1 = CreateArray(maxl);
        char* P2 = CreateArray(maxl);
        char* P3 = CreateArray(maxl);

        
        karatsuba(xl, yl, P1);
        karatsuba(xr, yr, P2);

        char* tmp1 = CreateArray(maxl);
        char* tmp2 = CreateArray(maxl);
        add(xl, xr, tmp1);
        add(yl, yr, tmp2);
        karatsuba(tmp1, tmp2, P3);
        sub(P3, P1, P3);
        sub(P3, P2, P3);
        mult10(P3, rightSize);
        mult10(P1, 2 * rightSize);
        add(P1, P2, res);
        add(res, P3, res);
        remove_zeros(res);
    }
}
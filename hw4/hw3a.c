/*
* Aditya Prasad
* ap45485
*/

#include <stdio.h>
#include <string.h>

typedef unsigned char *pointer;
 
void show_bytes(pointer start, int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    printf("%.2x", start[i]);
  }
  printf("\n");
} 
 
void float_f2d(int x)
{
  /*
   *  0xC2020000 = 1 10000100 00000100000000000000000 = 1.000001 x 2^5 = 100000.1 = -32.5
   */
  printf("%f\n", *(float *)&x);
}

void float_f2h(int x)
{
  float f = (float)x;
  printf("%d in single precision floating point is: 0x",x);
  show_bytes((pointer)&f, sizeof(int));
}

void main()
{
   printf("***Printing in Little Endian***\n");
   printf("1: ");
   float_f2h(-131);
   float twoa = 0x78;
   printf("2a: %f\n", twoa);
   float twob = 0x11.Ep0;
   printf("2b: %f\n", twob);
   float twoc = 0xAC.Bp0;
   printf("2c: %f\n", twoc);
   printf("2d: %x\n", 145);
   printf("2e: 0x%x\n", -0x01234567);
   printf("2f: 0x%x\n", 0x69 - 0x55);
   printf("2g: 0x%x\n", 0x01234567 | 0x0F0F0F0F);
   printf("2h: 0x%x\n", ~0x01234567);
   printf("2i: 0x%x\n", 0x74696669 << 5);
   printf("2j: 0x%x\n", 0x01234567 ^ 0x0F0F0F0F);
   printf("3: ");
   float_f2d(0xC2020000);
   printf("4: ");
   unsigned char str[] = "hello world";
   show_bytes(str, strlen(str));
}





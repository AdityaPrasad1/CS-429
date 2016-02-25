/*
 * CS:APP Data Lab
 *
 * <Aditya Prasad ap45485>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are notating: 3
 */
int logicalShift(int x, int n) {
  int ARShift = x >> n;

  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */;


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//////////////////////
// 1-point problems //
//////////////////////
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* exploit DeMorgan's law to create And */
  return ~(~x | ~y);
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  /* exploited property of TMin+TMin=0, any other integer+integer still equals a nonzero integer, !(!x) is to confirm that x is TMin because it equals either 0 (when x = 0) or 1 otherwise */
  return (!(!x)) & !(x + x);
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  /* exploited OR and shifting to set higher even bits to 1  */
  int i = 0x55;
  int mask = 0x55;
  i = i | (mask << 8);
  i = i | (mask << 16);
  i = i | (mask << 24);
  return i;
}
//////////////////////
// 2-point problems //
//////////////////////
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* exploited OR and shifting to get all odd bits in mask set to 1, then used XOR and & to check if x had all odd bits set to 1 */
  int i = 0xAA;
  int mask = 0xAA;
  i = i | (mask << 8);
  i = i | (mask << 16);
  i = i | (mask << 24);
  return !((x & i) ^ i);
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* exploited property of XORing a value by itself to get 0 */
  return !(x^y);
}
/* * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  /* used a mask that set the sign bit to 0 in uf, then checked if uf was NaN */
  unsigned neg = 0x01 << 31;
  unsigned NaN = (0xFF << 23) + 1;
  if((uf & ~neg) >= NaN) {
    return uf;
  }
  else {
    return (uf & ~neg);
  }
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) {
  /* exploited property of negating bitstrings to get least significant bit that equals 1*/
  return x & (~x + 1);
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  /* nbyte stores the nth byte, mbyte stores the mth byte, swapmask creates a mask where the mth and nth bytes are set to 0 in x, the bytes are then swapped using shifting and OR */
  int nbyte = (x >> (n << 3)) & 0xFF;
  int mbyte = (x >> (m << 3)) & 0xFF;
  int swapmask = ~0 ^ ((0xFF << (n << 3)) | (0xFF << (m << 3)));
  return (x & swapmask) | (nbyte << (m << 3)) | (mbyte << (n << 3));
}
//////////////////////
// 3-point problems //
//////////////////////
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  /* created a mask that set the nth byte in x to 0, then OR'd that byte with a shifted c to replace the nth byte with c */
  int rplcmask = ~0 ^ (0xFF << (n << 3));
  return (x & rplcmask) | (c << (n << 3));
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* if the sign of x and y are different then the sum cannot overflow (the double NOT is to get rid of the arithemtic shift), if they're the same then check if x and the sum have the same sign and if  y and the sum have the same sign. If so, it did not overflow, otherwise it overflowed */
  int xsign = x >> 31;
  int ysign = y >> 31;
  int sumsign = (x + y) >> 31;
  return !!(xsign ^ ysign) | (!(xsign ^ sumsign) & !(ysign ^ sumsign));
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* if x and y have the same sign, check which is greater. If the sign of (x + ~y) is 0, then x is greater, otherwise y is greater. If signs are different, check which one is greater by comparing signs using AND */
  int xsign = x >> 31;
  int ysign = y >> 31;
  int isSignSame = !(xsign ^ ysign);
  int greater = (x + ~y) >> 31;
  return !(isSignSame & greater) & !(xsign & !ysign); 
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* first add the negative of 0x30 to x, if x is smaller than 0x30, then the sign bit should be 1, otherwise it's 0. Then add the negative of x to 0x39, if x is smaller, then the sign bit should be 0. And the NOT of the first sign bit with the NOT of the second sign bit */
  return !((x + (~0x30 + 1)) >> 31) & !((0x39 + (~x + 1)) >> 31);
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  /* used a a mask to convert all the arithmetic 1s into 0s, shifted 1 by 31, then arithemtically shifted it n positions to the right then shifted 1 to the left. Once complemented, this mask had 0s in all the ARShifted positions and 1s in the rest*/
  int ARShift = x >> n;
  int LRSMask = ~(((1 << 31) >> n) << 1);
  return ARShift & LRSMask;
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n) {
  /* shift x by n to leave n 0 bits on the right, then use the methods employed in logicalShift above to isolate the bits that wrap around. After isolating both, combine the two with OR */
  int RLx = x << n;
  int LRSamt = 32 + (~n + 1);
  int ARShift = x >>LRSamt;
  int LRSMask = ~(((1 << 31) >> LRSamt) << 1);
  int wrap = ARShift & LRSMask;
  return RLx | wrap;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  /* first multiply x by 5 using shifts, then adjust for the arithmetic right shift that will happen when dividing by 8 (right shifting by 3) by adding 7 to 5x if it's negative (this helps to round to zero). Then shift right by 3 to divide by 8. */
  int timesFive = x + (x << 2);
  int signAdj = (timesFive >> 31) & 7;
  return (timesFive + signAdj) >> 3;
}
//////////////////////
// 4-point problems //
//////////////////////
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  /* when a nonzero integer is ORd with it's negative form, all the bits become 1 except for the LSB, when arithmetically right-shifted 31 bits, the integer becomes all 1s. If x is 0, the integer becomes all 0s. This represents the sign. Adding 1 to the sign shows whether the NOT is 0 or 1 */
  return ((x | (~x + 1)) >> 31) + 1;
}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /* if positive, adding the sign (0) doesn't change x and XORing with 0 will yied x again. If negative, adding the sign which is all 1s creates the complement of what is to be the magnitude. Once the complement is XOR'd with the sign, the magnitude is returned */
  int sign = x >> 31;
  return (x + sign) ^ sign;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* brute force through every bit to see whether it's 1 or 0, use &1 ot check */
  int sum = 0;
  sum += x & 1;
  sum += (x >> 1) & 1;
  sum += (x >> 2) & 1;
  sum += (x >> 3) & 1;
  sum += (x >> 4) & 1;
  sum += (x >> 5) & 1;
  sum += (x >> 6) & 1;
  sum += (x >> 7) & 1;
  sum += (x >> 8) & 1;
  sum += (x >> 9) & 1;
  sum += (x >> 10) & 1;
  sum += (x >> 11) & 1;
  sum += (x >> 12) & 1;
  sum += (x >> 13) & 1;
  sum += (x >> 14) & 1;
  sum += (x >> 15) & 1;
  sum += (x >> 16) & 1;
  sum += (x >> 17) & 1;
  sum += (x >> 18) & 1;
  sum += (x >> 19) & 1;
  sum += (x >> 20) & 1;
  sum += (x >> 21) & 1;
  sum += (x >> 22) & 1;
  sum += (x >> 23) & 1;
  sum += (x >> 24) & 1;
  sum += (x >> 25) & 1;
  sum += (x >> 26) & 1;
  sum += (x >> 27) & 1;
  sum += (x >> 28) & 1;
  sum += (x >> 29) & 1;
  sum += (x >> 30) & 1;
  sum += (x >> 31) & 1;
  return sum;
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* the first if-statement checks if the float is a special value (NaN, Infinity), if so return the float. The second statement checks if the FP is normalized, if so increment the exponent by 1 to simulate multiplying by 2. The final statement checks if the FP is denormalized. If so, shift the mantissa by 1 to multiply by 2. Finally combine the sign, exponent, and mantissa by using ORand return */
  unsigned S, E, M;
  S = uf & 0x80000000;
  E = (uf >> 23) & 0xFF;
  M = uf & 0x007FFFFF;
  if(E == 0xFF) {
    return uf;
  }
  else if(E > 0) {
    E++;
  }
  else {
    M = M << 1;
  }
  return S | (E << 23) | M;
}
/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  /* the first if-statement checks if uf is a special value (NaN, Infinity), if so it returns uf. The next if-statement checks if uf is normalized. Within it, there is a special case where the exponent equals 1. If so, halving uf makes the value denormalized and requires uf to  be adjusted for rounding. If the exponent is greater than 1, the exponent is decremented by 1 to simulate halving. For the denormalized cases, the mantissa has to be adjusted for rounding before it can be shifted right (halving). Once all the steps are completed, the sign, exponent, and mantissa are OR'd together */
  unsigned S, E, M;
  S = uf & 0x80000000;
  E = (uf >> 23) & 0xFF;
  M = uf & 0x007FFFFF;
  if(E == 0xFF) {
    return uf;
  }
  else if(E > 0) {
    if(E == 1) {
     if((M & 3) == 3) {
        M++;
      }
      M = (M >> 1) | 0x00400000;
    }
    E--;
  }
  else {
    if((M & 3) == 3) {
      M++;
    }
    M = M >> 1;
  }
  return S | (E << 23) | M;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}

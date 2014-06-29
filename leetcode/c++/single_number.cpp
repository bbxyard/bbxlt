/*
 * =====================================================================================
 *
 *       Filename:  single_number.cpp
 *
 *    Description:  Given an array of integers, every element appears twice except for one. 
 *                  Find that single one.
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 09时59分59秒
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  bbxyard (Brian), bbxyard@gmail.com 
 *      Copyright:  copyright (c) 2014, LGPL, bbxyard, http://www.bbxyard.com
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdio.h>

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            num ^= A[i];
        }
        return num;
    }
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *       Author:  bbxyard
 *      Created:  2014年06月29日 10时00分35秒
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
    Solution sln;
    int A[] = { 100, 200, 300, 100, 300 };
    int n = (int)(sizeof(A) / sizeof(A[0]));
    int num = sln.singleNumber(A, n);
    fprintf(stdout, "result is: %d\n", num);

    return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */

/*
 * =====================================================================================
 *
 *       Filename:  reverse_words_in_a_string.cpp
 *
 *    Description:  leetcode reverse sentence
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 04时09分28秒
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  bbxyard (Brian), bbxyard@gmail.com 
 *      Copyright:  copyright (c) 2014, LGPL, bbxyard, http://www.bbxyard.com
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;

        trim(s, ' ');
        if (!s.empty())
        {
            int len = reverse_words(&s.at(0));
            s = s.substr(0, len);
        }
    }
private:
    void ltrim(string& s, char ch)
    {
        int i = 0;
        for (; i < s.length() && s[i] == ch; ++i)
            ;
        s = s.substr(i);
    }
    void trim(string& s, char ch)
    {
        int i = 0;
        for (; i < s.length() && s[i] == ch; ++i)
            ;
        int j = s.length() - 1;
        for (; i < j && s[j] == ch; --j)
            ;
        ++j; // point to ' ' or \0
        if (i < j)
            s = s.substr(i, j - i);
        else
            s = s.substr(i);
    }

    // 左闭右开区间
    void reverse_words(char* begin, char* end)
    {
        -- end;
        while (begin < end)
        {
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
            ++ begin;
            -- end;
        }
    }

    int reverse_words(char* sent)
    {
        char* p = sent; // begin position
        char* q = sent; // end postion
        while (*p != 0)
        {
            for (q = p; *q != 0 && *q != ' '; ++q)
                ;
            // here q == 0 or space
            reverse_words(p, q);
            if (*q == 0)
            {
                break;
            }
            
            // skip space and to next
            char* qn = ++q;
            for (; *qn != 0 && *qn == ' '; ++qn)
                ;
            if (q != qn)
                do_strmove(q, qn);
            p = q;
        }
        // reverse whole sentence.
        int len = q - sent;
        reverse_words(sent, q);
        return len;
    }
    void do_memmove(char* p, char* q, int count)
    {
        while (count-- > 0)
        {
            *p++ = *q++;
        }
    }
    void do_strmove(char* p, char* q)
    {
        while (*q != 0)
            *p++ = *q++;
        *p = 0;
    }
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *       Author:  bbxyard
 *      Created:  2014年06月29日 04时10分11秒
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
    Solution sln;
    std::string s = "this is iflytek";
    if (argc >= 2)
        s = argv[1];
    sln.reverseWords(s);
    std::cout << "after reverse s is: *" << s << "*" << std::endl;

    return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */


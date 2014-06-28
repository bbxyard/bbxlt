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

        ltrim(s, ' ');
        if (!s.empty())
            reverse_words(&s.at(0));
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

    void reverse_words(char* sent)
    {
        char* p = sent; // begin position
        char* q = sent; // end postion
        while (*p != 0)
        {
            for (q = p; *q != 0 && *q != ' '; ++q)
                ;
            // here q == 0 or space
            reverse_words(p, q);
            // skip space and to next
            p = q;
            if (*p != 0)
                ++ p;
        }
        // reverse whole sentence.
        reverse_words(sent, p);
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


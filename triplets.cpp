//
//  triplets.cpp
//  algorithms
//
//  Created by Wentao Deng on 8/29/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
#include <time.h>
#include "triplets.h"

// ramdomly generate one tripplet.
std::string triplet()
{
    static std::string password = "google";
    std::set<int> digits;
    
    while (digits.size() < 3)
    {
        int d = rand() % 6;
        digits.insert(d);
    }
    
    // Set is ordered.If all non-ordered triplets are equaly distributed, then ordered triplets should distributed equaly as well.
    std::string result;
    for (std::set<int>::const_iterator it = digits.begin(); it != digits.end(); ++it)
    {
        result += password[*it];
    }
    
    return result;
}

// normalize to frequencies when repeat=20
void normalize(int* array, int size, int repeat)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > 0)
        {
            array[i] = (array[i] * 20. / repeat) + 0.5; //0.5 to round up
        }
    }
}

// first is frequencies of chars appearing in the first position of triplets, and mid the 2nd.
//假设a b c d e f 是password字符的位置，而 x y z 是返回字符的位置。
//x 可能是{a,b,c,d}
//y 可能是{b,c,d,e}
//z 可能是{c,d,e,f}
//所有的组合是C(6,3) = 20种。
//每个字符pos出现的概率表如下：
//        x       y         z
//a    10/20      0         0
//b     6/20     4/20       0
//c     3/20     6/20      1/20
//d     1/20     6/20      3/20
//e      0       4/20      6/20
//f      0        0        10/20
std::string getfirst(int* first, int* mid)
{
    std::string result = "----";
    
    for (int i = 0; i < 26; ++i)
    {
        int cnt = first[i];
        if (cnt > 0)
        {
            char ch = 'a' + i;
            
            // when count is 10, it could be char in position a or dups in positions b-f.
            if (cnt == 10)
            {
                if (mid[ch - 'a'] > 10)
                {
                    result[1] = ch; result[2] = ch; result[3] = ch;
                }
                else
                {
                    result[0] = ch;
                }
                continue;
            }
            //This is based on the frequency table
            switch(cnt)
            {
                case 1:
                    result[3] = ch;
                    break;
                case 3:
                    result[2] = ch;
                    break;
                case 6:
                    result[1] = ch;
                    break;
                case 10:
                    result[0] = ch;
                    break;
                    
                // frequency can only be 1/3/6/10 in first position if no dup.
                // so when it's 4 in column x, it must be a sum of 3 and 1 according to the frequency table.
                // so when it's 7 in column x, it must be a sum of 6 and 1 according to the frequency table.
                case 4:
                    result[3] = ch; result[2] = ch;
                    break;
                case 7:
                    result[3] = ch; result[1] = ch;
                    break;
                case 9:
                    result[2] = ch;result[1] = ch;
                    break;
                case 11:
                    result[0] = ch; result[3] = ch;
                    break;
                case 13:
                    result[0] = ch; result[2] = ch;
                    break;
                case 16:
                    result[0] = ch; result[1] = ch;
                    break;
                case 17:
                    result[0] = ch; result[1] = ch; result[3] = ch;
                    break;
                case 14:
                    result[0] = ch; result[2] = ch; result[3] = ch;
                    break;
                case 19:
                    result[0] = ch; result[1] = ch; result[2] = ch;
                    break;
                case 20:
                    result[0] = ch; result[1] = ch; result[2] = ch; result[3] = ch;
                    break;
                default:
                    break;
            }
        }
    }
    
    return result;
}

void printFrequency(int* a, int size)
{
    for(int i=0; i< size; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int mainT()
{
    srand(time(NULL));
    int f[26] = {0};
    int m[26] = {0};
    int t[26] = {0};
    std::vector<std::string> triplets;
    int repeat = 3000;
    for (int i = 0; i < repeat; ++i)
    {
        std::string str = triplet();
        f[str[0] - 'a']++;
        m[str[1] - 'a']++;
        t[str[2] - 'a']++;
        triplets.push_back(str);
    }
    
    // normalize
    normalize(f, 26, repeat);
    normalize(m, 26, repeat);
    normalize(t, 26, repeat);
    printFrequency(f, 26);
    printFrequency(m, 26);
    printFrequency(t, 26);
    
    std::string firstpart = getfirst(f, m);
    std::string secondpart = getfirst(t, m); // The frequency table is symetric, so reuse the same function, but the output is reversed.
    std::string result = firstpart + secondpart[1] + secondpart[0];
    std::cout << result <<"\n";
    return 0;
}
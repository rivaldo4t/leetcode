#include <iostream>
using namespace std;

class Solution 
{
public:
    string intToRoman(int num) 
    {
        string s;
        switch(num%10)
        {
            case 1: s.insert(0, "I");break;
            case 2: s.insert(0, "II");break;
            case 3: s.insert(0, "III");break;
            case 4: s.insert(0, "IV");break;
            case 5: s.insert(0, "V");break;
            case 6: s.insert(0, "VI");break;
            case 7: s.insert(0, "VII");break;
            case 8: s.insert(0, "VIII");break;
            case 9: s.insert(0, "IX");break;
        }
        if(num/10 != 0)
        {
            num/=10;
            switch(num%10)
            {
                case 1: s.insert(0, "X");break;
                case 2: s.insert(0, "XX");break;
                case 3: s.insert(0, "XXX");break;
                case 4: s.insert(0, "XL");break;
                case 5: s.insert(0, "L");break;
                case 6: s.insert(0, "LX");break;
                case 7: s.insert(0, "LXX");break;
                case 8: s.insert(0, "LXXX");break;
                case 9: s.insert(0, "XC");break;
            }
        }
        if(num/10 != 0)
        {
            num/=10;
            switch(num%10)
            {
                case 1: s.insert(0, "C");break;
                case 2: s.insert(0, "CC");break;
                case 3: s.insert(0, "CCC");break;
                case 4: s.insert(0, "CD");break;
                case 5: s.insert(0, "D");break;
                case 6: s.insert(0, "DC");break;
                case 7: s.insert(0, "DCC");break;
                case 8: s.insert(0, "DCCC");break;
                case 9: s.insert(0, "CM");break;
            }
        }
        if(num/10 != 0)
        {
            num/=10;
            switch(num%10)
            {
                case 1: s.insert(0, "M");break;
                case 2: s.insert(0, "MM");break;
                case 3: s.insert(0, "MMM");break;
            }
        }
        return s;
    }
};

int main() 
{
    int a = 967;
    Solution S;
    cout << S.intToRoman(a) << endl;
}

/**************************************
 * R exp(n)
 * R is a rational number, 0<= n <=25
 * return resutlt
 * ***********************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef int IntegerType;

const int MAX = 1024;
int multiply(const char* A, const char* B, int* res)
{
    unsigned int ALen = strlen(A);
    unsigned int BLen = strlen(B);
    //int* res = (int*)malloc( sizeof(int*) * (ALen + BLen) );
    //if(res)
    //    memset(res, 0, ALen+BLen);
    //else
    //    return -1;

    // Multiply
    for(int i = 0; i < ALen; i++)
        for(int j = 0; j < BLen; j++)
        {
            res[ i + j + 1] += (A[i] - '0') * (B[j] - '0');
        }
    
    for(int i  = ALen + BLen - 1; i >= 0; i--)
    {
        res[i - 1] += res[i] / 10;
        res[i] = res[i] % 10;
    }

    return 0;
}
int main()
{
    string r, n;
    while(cin >> r >> n)
    {
        const char *nTmp = n.c_str();
        int dotPos = 0;
        dotPos = r.find('.');
        dotPos = dotPos == -1 ? 0: dotPos;
        int rLen = r.length();

        string pureNum("");
        int endPos = 0;
        if(dotPos) // has dot
        {
            string tmp = r.substr(0, dotPos);
            if(tmp[0] != '0')
                pureNum += tmp;

            tmp = r.substr(dotPos + 1);
            int tmpLen = tmp.length();
            endPos = tmpLen;
            for(int i=tmpLen - 1; i >= 0; i--)
            {
                if(tmp[i] == '0')
                    endPos = i;
                else
                    break;
            }
            pureNum += tmp.substr(0, endPos);
            //if()
        }
        else
            pureNum = r;
        cout << pureNum << " " << n << endl;
        //cout << dotPos << endl;

        int nNum = atoi(nTmp);
        unsigned int pureNumLen = pureNum.length();
        int*  res = (int*)calloc(2 * pureNumLen, sizeof(int*));
        char* resChar = (char*)calloc(pureNumLen, sizeof(char));
        memcpy(resChar, pureNum.c_str(), pureNumLen);
        for(int i = 2; i < nNum; i = i * 2)
        {     
            res = (int*)realloc(res, sizeof(int*) * ( pureNumLen * i) );
            if(res)
                memset(res, 0, pureNumLen * i);
            else
                return -1;

            multiply(resChar, resChar, res);
            resChar = (char*)realloc(resChar, i * pureNumLen * sizeof(char));
            for(int j=0; j< pureNumLen * i; j++)
            {
                resChar[j] = res[j] + '0';
                cout << resChar[j];
            }
            cout<<endl;
        }
    }
    return 0;
}

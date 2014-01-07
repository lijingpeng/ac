/**************************************
 * R exp(n)
 * R is a rational number, 0<= n <=25
 * return resutlt
 * ***********************************/

#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

const int MAX = 1024;
void rexpn(string r, const char* b, char* res)
{
    //1找小数点
    int dotPos = 0;
    dotPos = r.find('.');
    dotPos = dotPos == -1 ? 0: dotPos;
    
    //2删除小数点并删除无效的0
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
     }
     else
        pureNum = r;
     
     //3计算乘法
      
    int rLen = pureNum.length();
    int bLen = strlen(b);
    int intRes[MAX*MAX+1];
    memset(intRes, 0, MAX*MAX+1);
    for(int i = 0; i < rLen; i++)
        for(int j = 0; j < bLen; j++)
        {
            intRes[ i + j + 1] += (pureNum[i] - '0') * (b[j] - '0');
        }
    
    for(int i  = rLen + bLen - 1; i >= 0; i--)
    {
        intRes[i - 1] += intRes[i] / 10;
        intRes[i] = intRes[i] % 10;
        res[i] = intRes[i] + '0' ;
    }
/*
    string resStr("");
    sringstream ss;
	string tmp("");
    for(int i = 0; i < ALen+BLen; i++)
    {
	if(res[0] == 0)
	{
		continue;
	}
	ss.clear();
	tmp = "";
	ss << res[i];
	ss >> tmp;
	resStr += tmp;
    }*/
    return;
}
char res[MAX * MAX + 1];
int main()
{
    string r;
    int n;
    while(cin >> r >> n)
    {
       memset(res, 0, MAX*MAX+1);
       rexpn(r, r.c_str(), res);
       //cout << res << endl;
       //memset(res, 0, MAX*MAX+1);
       for(int i = 2; i < n; i++)
       {
            rexpn(r, res, res);
       }
       cout << res << endl;
    }
    return 0;
}   

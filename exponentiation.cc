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
string trimzero(string r)
{
	string validStr("");
	int dotPos = r.find('.');
	bool flag = false;
	dotPos = dotPos == -1 ? 0 : dotPos;
	if (dotPos)
	{
		for(int i = dotPos + 1; i < r.length(); i++)
		{
			if (r[i] != '0')
			{
				flag = true;
				validStr = r;
				break;
			}
		}
	}
	else
		validStr = r;
	
	if (!flag && dotPos)
	{
		validStr = r.substr(0, dotPos);
	}
	return validStr;
}
void rexpn(string r, const char* b, char* res)
{
	//1找小数点
	int dotPos = 0, i = 0, j = 0;
	dotPos = r.find('.');
	string bStr(b);
	int dotPosB = bStr.find('.');
	dotPosB = dotPosB == -1 ? 0 : dotPosB; dotPos = dotPos == -1 ? 0 : dotPos;

	//2删除小数点并删除无效的0
	int dotCount = 0;
	int dotCountb = 0;
	string pureNum("");
	string pureNumb("");
	int endPos = 0;
	if (dotPos) // has dot
	{
		string tmp = r.substr(0, dotPos);
		string tmpb = bStr.substr(0, dotPosB);
		if (tmp[0] != '0')
			pureNum += tmp;
		if (tmpb[0] != '0')
			pureNumb += tmpb;

		tmp = r.substr(dotPos + 1);
		tmpb = bStr.substr(dotPosB + 1);
		int tmpLen = tmp.length();
		endPos = tmpLen;
		for (i = tmpLen - 1; i >= 0; i--)
		{
			if (tmp[i] == '0')
				endPos = i;
			else
				break;
		}
		pureNum += tmp.substr(0, endPos);
		dotCount = tmp.substr(0, endPos).length();
        if(endPos == 0)
            dotPos = 0;

		tmpLen = tmpb.length();
		endPos = tmpLen;
		for ( i = tmpLen - 1; i >= 0; i--)
		{
			if (tmpb[i] == '0')
				endPos = i;
			else
				break;
		}
		pureNumb += tmpb.substr(0, endPos);
		dotCountb = tmpb.substr(0, endPos).length();
	}
	else
	{
		pureNum = r;
		pureNumb = bStr;
	}


	//3计算乘法 
	int rLen = pureNum.length();
	int bLen = pureNumb.length();
	int intRes[MAX+MAX + 1];
	memset(intRes, 0, MAX+MAX + 1);
	for ( i = 0; i < rLen; i++)
		for ( j = 0; j < bLen; j++)
		{
			intRes[i + j + 1] += (pureNum[i] - '0') * (pureNumb[j] - '0');
		}

	for ( i = rLen + bLen - 1; i >= 0; i--)
	{
		intRes[i - 1] += intRes[i] / 10;
		intRes[i] = intRes[i] % 10;
		res[i] = intRes[i] + '0';
	}
    res[rLen + bLen] = '\0';

	//5 remove zero
	string noPreZeroStr("");
	int startPos = -1;
	for (i = 0; i < rLen + bLen; i++)
	{
		if (res[i] == '0')
		{
			startPos = i;
		}
		else
			break;
	}
	for ( i = startPos+1; i < rLen + bLen; i++ )
	{
		noPreZeroStr += res[i];
	}
	//4 dot
	if (dotPos)
	{
		int noDotLen = noPreZeroStr.length();
		if (noDotLen >= dotCount + dotCountb)
		{
			noPreZeroStr.insert(noDotLen - dotCountb - dotCount, ".");
		}
		else if (noDotLen < dotCount + dotCountb)
		{
			int distence = dotCount + dotCountb - noDotLen ;
			for ( i = 0; i < distence; i++)
			{
				noPreZeroStr.insert(i, "0");
			}
			noPreZeroStr.insert(0, ".");
		}

	}
	memset(res, 0, MAX+MAX + 1);
	memcpy(res, noPreZeroStr.c_str(), noPreZeroStr.length());
	res[noPreZeroStr.length()] = '\0';


	return;
}

char res[MAX + MAX + 1];
int main()
{
	string r;
	int n;
	while (cin >> r >> n)
	{
		string realNum = trimzero(r);
		if (n == 0)
			cout << "1" << endl;
		else if (n == 1)
			cout << realNum << endl;
		else
		{
			memset(res, 0, MAX+MAX + 1);
			rexpn(realNum, realNum.c_str(), res);
			//cout << res << endl;
			//memset(res, 0, MAX+MAX+1);
			for (int i = 2; i < n; i++)
			{
				rexpn(realNum, res, res);
			}
			cout << res << endl;
		}
	}
	return 0;
}



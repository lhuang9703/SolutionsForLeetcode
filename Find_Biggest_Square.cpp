// Source : homework of data structure
// Number : **
// Author : HL
// Date   : 2018-09-14
// Kill   : ***

/********************************************************************************** 
Description
在图像识别中，常常需要对图片进行预处理。例如，一张二值图片，需要在图片中切割出正方形，试求能切割出的最大正方形面积与切割方法。
提示：在nxn的矩形区域中，寻找最大的全0正方形，并输出最大的正方形有几个。注：正方形的边与区域边际平行，不要把问题复杂化。
Input
n
a11 a12 ... a1n
 ...    ...   ...  ...
an1 an2 ... ann
n、aij均为整型。0<n<200，0≤ai≤10
Output
最大的正方形的面积 有多少种选择：
ans1 ans2
Sample Input
7
1 0 1 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 1 0
0 1 0 0 0 0 1
1 1 0 0 0 0 0
1 0 1 0 0 0 0
1 0 1 1 0 0 1
Sample Output
9 3
Bonus
1 复杂度达到O(n^3)
1 复杂度达到O(n^2)
**********************************************************************************/

#include <iostream>
#include<fstream>

using namespace std;

int Minest(int a,int b,int c)
{
    int result = a>b ? b : a;
    if(c < result)
        result = c;
    return result;
}

// 动态规划的思想
int main()
{
    int n,i,j,count=0,maxLength=0;
    ifstream fin("in.txt");
    if(fin.is_open())
    {
        fin>>n;
        int **arr = new int*[n];
        int **brr = new int*[n];
        for(i=0; i<n; i++)
        {
            arr[i] = new int[n];
            for(j=0; j<n; j++)
                fin>>arr[i][j];
        }
        for(i=0; i<n; i++)
        {
            brr[i] = new int[n];
            for(j=0; j<n; j++)
                brr[i][j] = 1 - arr[i][j];
        }
        for(i=1; i<n; i++)
        {
            for(j=1; j<n; j++)
            {
                if(brr[i][j] == 1)
                {
                    brr[i][j] = Minest(brr[i-1][j-1],brr[i][j-1],brr[i-1][j]) + brr[i][j];
                    if(brr[i][j] > maxLength)
                        maxLength = brr[i][j];
                }
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(brr[i][j] == maxLength)
                    count++;
            }
        }
        fin.close();
    }
    ofstream fout("out.txt");
    fout<<maxLength*maxLength<<endl;
    fout<<count<<endl;
    fout.close();
    
    return 0;
}

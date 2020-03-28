//
// Created by lica-pc on 3/28/20.
//
#include <sstream>
#include <cctype>
#include "funciones.h"

bool isNum(const string& s)
{
    for (char i : s)
        if (isdigit(i) == 0)
            return false;
    return true;
}

bool verificar(int **A[], int a, int *B[], int b, int C[], int c, vector<string> arr)
{
    if (arr.size() != 4)
        return false;
    else
    {
        if (isNum(arr[1]) && isNum(arr[3]))
        {
            if (arr[0] == "A" & arr[2] == "B")
            {
                int pos1 = stoi(arr[1]), pos2 = stoi(arr[3]);
                if (pos1 < a && pos2 < b)
                {
                    A[pos1] = &B[pos2];
                    return true;
                } else
                    return false;
            }
            else if (arr[0] == "B" & arr[2] == "C")
            {
                int pos1 = stoi(arr[1]), pos2 = stoi(arr[3]);
                if (pos1 < b && pos2 < c)
                {
                    B[pos1] = &C[pos2];
                    return true;
                } else
                    return false;
            } else
                return false;
        } else
            return false;
    }
}


void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
    string linea;
    vector<bool> resultados;
    while(getline(cin,linea))
    {
        if (linea.empty())
            break;
        else
        {
            istringstream esp(linea);
            vector<string> arr((istream_iterator<string>(esp)),istream_iterator<string>());
            resultados.push_back(verificar(A,a,B,b,C,c,arr));
        }
    }

    for(auto i: resultados)
        cout << i << endl;
}

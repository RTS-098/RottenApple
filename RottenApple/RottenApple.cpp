#include <iostream>
#include <string>

using namespace std;

void readnum(string line, int &i, int &x1,int &x2) {
    
    int num1 = 0;
    int num2 = 0;
    if (line.size() -i > 4) {
        while ((line[i] == ',' || line[i] == '(' || line[i] == ')' || line[i] == ' ') && i < line.size())
        {
            i++;
        }
        while ((line[i] != ',' && line[i] != '(' && line[i] != ')' && line[i] != ' ') && i < line.size())
        {
            num1 = num1 * 10 + (line[i] - 48);
            i++;
        }

        while ((line[i] == ',' || line[i] == '(' || line[i] == ')' || line[i] == ' ') && i < line.size())
        {
            i++;
        }
        while ((line[i] != ',' && line[i] != '(' && line[i] != ')' && line[i] != ' ') && i < line.size())
        {
            num2 = num2 * 10 + (line[i] - 48);
            i++;
        }

        x1 = num2;
        x2 = num1;
    }
  
}

void readsize(int &m, int &n, string line) {
    int i = 0;
    int sum = 0;
    while (i < line.size() && (line[i] != 'x' && line[i]!= ' '))
    {
        sum=sum * 10 + (line[i] - 48);
        i++;
    }
    m = sum;
    sum = 0;
    while (i < line.size() && (line[i] == 'x' || line[i] == ' '))
    {
        i++;
    }
    while (i < line.size() && (line[i] != 'x' && line[i] != ' '))
    {
        sum = sum * 10 + (line[i] - 48);
        i++;
    }
    n = sum;
}


void rotten(int** A, int x1, int x2,int days,int n,int m)
{
    //there are no zero rows or columns
    x1 = x1 - 1;
    x2 = x2 - 1;
    m = m - 1;
    n = n - 1;
    A[x1][x2] = 0;
    for (int y = 1; y <= days; y++)
    {
        for (int i = 0-y; i <= y; i++)
        {
            for (int j = 0-y; j <= y; j++)
            {
                if ((x1 + i)>=0 && (x2 + j)>=0 && (x1 + i)<=m && (x2 + j) <= n)
                {
                    A[x1 + i][x2 + j] = 0;
                }
                
            }
        }
    }
}

void print(int** A,int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(A[i][j] == 1)
            { 
                cout << "O";
            }
            if (A[i][j] == 0)
            {
                cout << "X";
            }
            
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    string size;
    
    cout << "Enter the size of the box: ";
    cin >> size;
    readsize(n, m, size);
    cin.get();
    string coordinates;
    cout << "Enter the coordinates of the rotten apples:  ";
    getline(cin,coordinates);
  
    
    int days;
    cout << "After how many days will you come back: ";
    cin>>days;
    days = days / 3;
    
    
    //m = 10; n = 20;
    int** A = new int* [m];
    for (int i = 0; i < m; i++)
    {
        A[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 1;
        }
    }
   
    int i = 0;
    int x1, x2;
    while (coordinates.size() - i > 4)
    {
       readnum(coordinates, i, x1, x2);
       rotten(A, x1, x2, days,n,m);
    }
    print(A, m, n);
    

    return 0;
}

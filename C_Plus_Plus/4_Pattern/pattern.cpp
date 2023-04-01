#include<iostream>
using namespace std;
void numberPattern(int i,int j,int n,int c);
void trianglePattern(int i,int j,int n,int c);
void alphabetTriPattern(int i,int j,int n,char c);
void alphabetPattern(int i,int j,int n,char c);
void Zpattern(int i, int j, int n);
void digonalPattern(int i ,int space, int rows);
void Pattern(int i ,int space, int rows);
void reverseDigonal();
int main()
{
    int i,j,n,c;
    i=1;
    n=10;
    c=1;
    int space=1;
    // numberPattern(i,j,n,c);
    // trianglePattern(i,j,n,c);
    // alphabetTriPattern(i,j,n,c);
    // alphabetPattern(i,j,n,c);
    // Zpattern(i,j,n);
    // digonalPattern(i,space,10);
    // Pattern(i,space,5);
    reverseDigonal();
    
}

void numberPattern(int i,int j,int n,int c)
{
    while (i<n)
    {
        j=1;
        while (j<n)
        {
            cout<<"\t"<<c;
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }

}

void trianglePattern(int i,int j,int n,int c)
{
    while (i<n)
    {
        j=1;
        while (j<=i)
        {
            cout<<"\t"<<i-j+1;
            c++;
            j++;
        }
        cout<<"\n";
        i++;
    }
    
}

void alphabetTriPattern(int i,int j,int n,char c)
{

  c='A';  
    while (i<n)
    {
        j=1;
        while (j<=i)
        {
            cout<<"\t"<<c;
            c++;
            j++;
        }
        cout<<"\n";
        i++;
    }

}

void alphabetPattern(int i,int j,int n,char c)
{
   
     while (i<n)
    {
        j=1;
         c = 'A';
        while (j<n)
        {
            cout<<"\t"<<c;
            c++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

void Zpattern(int i, int j, int n)
{
    for(i=1;i<n;i++)
    {
        for (j= 1; j <n; j++)
        {
            if (i==1||i==n-1||(j==n-i))
            {
                cout<<"\t*";   
            }
            else
            {
                cout<<"\t ";
            }
            
            
        }
        cout<<endl;
        
    }

}

void digonalPattern(int i ,int space, int rows)
{
        int k=0;
     for (i = 1; i <= rows; ++i) 
     {

      for (space = 1; space <= rows - i; ++space)
        {
             printf("  ");
        }
        
        k=0;
      while (k != 2 * i - 1)
       {
         printf("* ");
         ++k;
       }
      printf("\n");
    }
}

void Pattern(int i ,int space, int rows)
{
        int k=0;
     for (i = 1; i <= rows; ++i) 
     {

      for (space = 1; space <= rows - i; ++space)
        {
             cout<<" "<<space;
        }
        k=0;
      while (k != 2 * i - 1)
       {
         printf(" * ");
         ++k;
       }
        for(int jspace=rows-1;jspace>=rows-space;--jspace)
        {
            cout<<" "<<jspace;
        }
        
 
      printf("\n");
    }
}

void reverseDigonal()
{
    int i,j,n;
    n=10;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            cout<<" "<<j;
        }
        cout<<endl;
    }
}

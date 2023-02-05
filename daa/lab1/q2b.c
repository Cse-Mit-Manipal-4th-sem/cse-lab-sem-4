#include <stdio.h>

int main()
{
int n;
char edge='n';
printf("Enter number of vertices\n");
scanf("%d",&n);

int arr[n][n];
int a;

for (int i = 0; i < n; i++)
{
for (int j = i; j < n; j++)
{
printf("Is there any edge between %d and %d \n",i+1,j+1);
printf("y/n\n");

scanf(" %c",&edge);
if(edge=='y'){
arr[i][j]=arr[j][i]=1;
}
else{
arr[i][j]=arr[j][i]=0;
}
edge='n';

}
}

 printf("Adjacency Matrix: \n");


for (int i = 0; i < n; ++i)
{
for (int j = 0; j < n; ++j)
{
printf("%d ",arr[i][j]);
}
printf("\n");

}
return 0;
}
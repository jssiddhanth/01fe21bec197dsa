#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data[100];
    int top;
};
void push(struct stack *sptr,int element);
int pop(struct stack *sptr);
int peek(struct stack *sptr);
void display(struct stack *sptr);
int main()
{
    int k,element,first,last,n,a[100];
    struct stack s;
    struct stack *sptr;
    sptr=&s;
    sptr->top=-1;
    FILE *fp,*fp1,*fp2,*fp3;
    fp=fopen("input1.txt","w+");
    fp1=fopen("push.txt","a");
    fp2=fopen("pop.txt","a");
    fp3=fopen("operation.txt","a");
     FILE *fp4;
    fp4=fopen("Stack.txt","a");
    printf("Enter the interval\n");
    scanf("%d%d",&first,&last);
    printf("Enter number of random numbers to be generated\n ");
    scanf("%d",&n);
    int count=0;
    for(int i=0;i<n;i++)
    {

        a[i]=(rand()%(last+1-first)+first);
        fprintf(fp,"%d ",a[i]);

    }
    while(1)
    {
        printf("1:push 2:pop 3:display 4:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&k);
        switch(k)
        {

            case 1:
                   element=a[count];
                   count++;
                   fprintf(fp1,"%d\n",element);
                   fprintf(fp3,"%d was pushed\n",element);
                //   printf("%d",element);
                   push(sptr,element);
                   break;
            case 2:element=pop(sptr);
                   if(element==-1)
                   {
                       printf("stack underflow\n");
                   }
                   else
                   {
                       printf("The poped element is %d\n",element);
                      fprintf(fp2,"%d\n",element);
                      fprintf(fp3,"%d was poped\n",element);
                   }
                   break;
            case 3:display(sptr);
                   break;
            case 4:fclose(fp);
                  fclose(fp1);
                  fclose(fp2);
                  fclose(fp3);
                  fclose(fp4);
                exit(0);
                  break;
        }
    }
}
void push(struct stack *sptr,int element)
{
    if(sptr->top==100)
    {
        printf("Stack overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}
int pop(struct stack *sptr)
{
     int element;
    if(sptr->top==0)
    {
        return -1;
    }
    else
    {
        element=sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}
void display(struct stack *sptr)
{
    int k;
    k=sptr->top;
    FILE *fp4;
    fp4=fopen("Stack.txt","a");
    for(int j=k;j>=0;j--)
    {
        printf("%d\n",sptr->data[j]);
        fprintf(fp4,"%d\n",sptr->data[j]);
    }
}

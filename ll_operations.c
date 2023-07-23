#include<stdio.h>
struct Node
{
    int data;
    struct node *next;
};
typedef struct Node *node;
node head,newnode,temp,cur,prev,del;
int pos,ele,c;
node getnode();
node insertend(node);
node insertbeg(node);
void display(head);
node deleteend(head);
node deletebeg(head);
node insertatpos(newnode,pos);
node deleteatpos(head,pos);
node read_details(newnode);
node rev(newnode);


void main()
{
    int choice;
    while(1)
    {
        printf("1-->Insert at end\n2-->Insert at beg\n3-->Display nodes\n4-->Insert at pos\n5-->Delete at end\n6-->Delete at beg\n7-->Delete at pos\n");
        printf("enter choice:\n");
        scanf("%d",&choice);
    switch(choice)
        {
        case 1: head=insertend(newnode);break;
        case 2: head=insertbeg(newnode);break;
        case 3: display(head);break;
        case 4: printf("After how many nodes\n");
                scanf("%d",&pos);
                    if(pos<1 ||pos>count(head)+1)
                        printf("Not valid\n");
                    else
                    {
                        newnode=(struct Node*)malloc(sizeof(struct Node));
                       printf("Enter data\n");
                       scanf("%d",&newnode->data);
                        head=insertatpos(newnode,pos);
                    }
                    break;
        case 5: head=deleteend(head);break;
        case 6: head=deletebeg(head);break;
        case 7: printf("After how many nodes\n");
                   scanf("%d",&pos);
                    if(pos<1 ||pos>count(head)+1)
                        printf("i=Invalid pos\n");
                    else
                        head=deleteatpos(head,pos);
                    break;
        case 8: head=rev(head);
                printf("Reversed ll is\n");
                display(head);break;
         default: printf("Invalid\n");
        }
    }
}

node getnode()
{
 newnode=(node)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
return newnode;
}

node read_details(node newnode)
{
    printf("Enter data\n");
    scanf("%d",&newnode->data);
     newnode->next=NULL;
    return newnode;
}

node insertend(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
             temp=temp->next;
        }
        temp->next=newnode;
        return(head);
    }
}

node insertbeg(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return(head);
    }
}

void display(node head)
{
    if(head==NULL)
    {
        printf("No data\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
node insertatpos(node newnode,int pos)
{
    int p;
    node temp1;
    if(pos==1)
        head=insertbeg(newnode);
    else
    {
        p=1;
        temp=head;
        while(p!=pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=newnode;
        newnode->next=temp;
    }
    return head;
}
int count(node head)
{
    int count = 0;
    cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}
node deleteend(node head)
{
    if(head==NULL)
    {
        printf("No data\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleted node=%d\n",head->data);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
            temp=head;
            cur=head->next;
            while(cur->next!=NULL)
            {
                temp=temp->next;
                cur=cur->next;
            }
            printf("Node deleted is=%d\n",cur->data);
            free(cur);
            temp->next=NULL;
            return(head);
        }
    }
}
node deletebeg(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleted=%d\n",head->data);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
            temp=head;
            head=temp->next;
            printf("deleted=%d\n",temp->data);
            free(temp);
            return(head);
        }
    }
}
node deleteatpos(node head,int pos)
{
    int p;
    node temp1;
    if(pos==1)
        head=deletebeg(head);
    else
    {
        p=1;
        temp=head;
        while(p!=pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=temp->next;
        printf("Deleted node is %d\n",temp->data);
        free(temp);
    }
    return(head);
}
node rev(node head)
{
    prev=NULL;
    cur=head;
    temp=NULL;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
    return head;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    
    int priority;
    char a[20];
    char b[20];
    struct node* link;
};


struct queue{
    int data;
    struct queue* link;
};





void enqueue(struct node** front,int priority,char* a,char* b);
struct node* create_node();
struct node* dequeue(struct node** front);
void collection_amt_enqueue(int n,int c,struct queue** front,struct queue** rear);
struct queue* create_queue();
int  show_collection(struct queue* front);

int main()
{
    
    int n,priority;
    struct node* front=NULL;
    printf("WELCOME TO INDIANA CHECK POST 🛣️\n");
    printf("TO AVOID TRAFFIC IN  THE CHECK POSTS...PLS COOPERATE🚦🚦🚦\n");
    printf("--------------------------------");
    printf("\n");
    char a[20],b[20];
    int c;
    int coll;
    struct queue* front1=NULL;
    struct queue* rear=NULL;
    while(1)
    {
        printf("PLS SELECT THE CATEGORY✍️✍️\n\n");
        printf("CITIZEN🧍‍♂️🧍‍♀️-FARE-50/- PRESS 1\nEMERGENCY🚑🚒 SERVICES FARE-0/- PRESS 2\nCIVIL SERVANT👨‍✈️️-FARE-0/- PRESS 3\nMLA 👨‍💼️ 👩‍💼️-FARE-0/- PRESS 4\nMINISTER 🙎‍♂️️-FARE-0/- PRESS 5\nACTOR🕺️💃️ FARE-100/- PRESS 6\nTO CLOSE THE CHECK POST🆑️ PRESS 0\nTO KNOW THE COLLECTION PRESS-7\n\n");
        scanf("%d",&n);
        if(n!=0 && n!=7)
        {
        printf("ENTER YOUR VEHICLE.NO:");
        scanf("%s",a);
        printf("ENTER THE TIME:");
        scanf("%s",b);
        printf("ENTER THE FARE:");
        scanf("%d",&c);
        collection_amt_enqueue(n,c,&front1,&rear);
        }
        if(n==0)
        break;
        
        switch(n)
        {
            case 1:
            priority=6;
            break;
            
            case 2:
            priority=1;
            break;
            
            case 3:
            priority=4;
            break;
            
            case 4:
            priority=3;
            break;
            
            case 5:
            priority=2;
            break;
            
            case 6:
            priority=5;
            break;
            
            case 7:
            coll=show_collection(front1);
            printf("COLLLECTION IS:%d\n",coll);
            priority=8;
            break;
            
            default:
            printf("PLS ENTER VALID INPUT\n");
            
        }
        if(priority!=8)
        enqueue(&front,priority,a,b);
        
        
    }
    printf("WELCOME TO ROMEX CHECK POST\n\n");
    printf("---------------------------\n");
    struct node* temp=NULL;
    while(front!=NULL)
    {
        temp=dequeue(&front);
        
        switch(temp->priority)
        {
            case 1:
            printf("EMERGENCY VECHICLE LEFT......\nVECHICLE.NO:%s\nTIME:%s \n",temp->a,temp->b);
            break;
            
            case 2:
            printf("MINISTER'S VECHICLE LEFT..... VECHICLE.NO:%s TIME:%s\n",temp->a,temp->b);
            break;
            
            case 3:
            printf("MLA'S VECHICLE LEFT....VECHICLE.NO:%s TIME:%s\n",temp->a,temp->b);
            break;
            
            case 4:
            printf("CIVIL SERVANTS'S VECHICLE LEFT.... VECHICLE.NO:%s TIME:%s\n",temp->a,temp->b);
            break;
            
            case 5:
            printf("ACTOR'S VECHICLE IS OUT...VECHICLE.NO:%s TIME:%s\n",temp->a,temp->b);
            break;
            
            case 6:
            printf("CITIZEN CAR IS OUT.....VECHICLE.NO:%s  TIME:%s\n",temp->a,temp->b);
            break;
            
            default:
            printf("check is empty\n");
            
        }
        
    }
    
    coll=show_collection(front1);
    printf("TOTAL COLLECTION IS:%d\n",coll);
    
    return 0;
}

void enqueue(struct node** front,int priority,char* a,char* b)
{
    
   if(*front==NULL)
   {
       (*front)=create_node();
       (*front)->priority=priority;
       strcpy((*front)->a,a);
       strcpy((*front)->b,b);        
       (*front)->link=NULL;
       return;
   }
   
   struct node* current=NULL;
   current=create_node();
   current->priority=priority;
   strcpy(current->a,a);
   strcpy(current->b,b);  
    struct node* ptr=NULL;
    ptr=(*front);
    
    struct node* prev=NULL;
    
    while(ptr && ptr->priority<=priority)
    {
       prev=ptr; 
       ptr=ptr->link;
        
    }
    
    if(ptr==NULL)
        prev->link=current;
        
    if(ptr)
    {
        if(ptr==(*front))
        {
            current->link=ptr;
            (*front)=current;
            return;
        }
        
        prev->link=current;
        current->link=ptr;
    }
    
    
}

struct node* create_node()
{
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    
    if(temp==NULL)
    {
        printf("memoery not alloacted\n");
        return NULL;
    }
    
    return temp;
}

struct node* dequeue(struct node** front)
{
    if(front==NULL)
    {
        printf("queue is empty...check post is closed\n");
        return 0;
    }
    struct node* temp=(*front); 
    (*front)=(*front)->link;
    
    return temp;
}

void collection_amt_enqueue(int n,int c,struct queue** front,struct queue** rear)
{
if((*front)==NULL)
{
     (*front)=create_queue();
     (*front)->data=c;
     (*front)->link=NULL;
     (*rear)=(*front);
return;
}
     struct queue* temp=NULL;
     temp=create_queue();
     temp->data=c;
     temp->link=NULL;

     (*rear)->link=temp;
     (*rear)=temp;

}

struct queue* create_queue()
{
    
    struct queue* temp=NULL;
    temp=(struct queue*)malloc(sizeof(struct queue));
    
    if(temp==NULL)
    {
        printf("memory not alloacted\n");
        return NULL;
    }
    return temp;
    
}

int show_collection(struct queue* front)
{
    int coll=0;
    if(front==NULL)
    {
        printf("NO COLLECTION RECEIVED\n");
        return 0;
    }
    
    struct queue* ptr=NULL;
    ptr=front;
    
    while(ptr)
    {
        coll=coll+ptr->data;
        ptr=ptr->link;
    }
    
    return coll;
}

 

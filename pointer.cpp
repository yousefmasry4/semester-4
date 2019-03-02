//1->6
#include <stdio.h>
#include <stdlib.h>
struct node{
   struct node* next;
   int data;
};
struct node* creat(int x){
   struct node* node=(struct node*)malloc(sizeof(struct node));
   node->next=NULL;
   node->data=x;
   return(node);
}
void insert_in_b(struct node** head,int x){//q6
   struct node* temp=(*head);
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->next=temp;
   newnode->data=x;
   (*head)=newnode;
}
void insert_in_middle(struct node** head,int x){//q6
   struct node* temp=(*head);
   struct node* temp2=(*head);
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=x;
   int size=0;
   while(temp2){
      size++;
      temp2=temp2->next;
   }
   free(temp2);
   int loc=size/2;
   printf("**%d\n",loc);
   for(int i=0;i<loc-1;i++){
      temp=temp->next;
   }
   newnode->next=temp->next;
   temp->next=newnode;
}
void insert_at_the_end(struct node** head,int x){//q6
   struct node* temp=(*head);
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   newnode->next=NULL;
   newnode->data=x;
   while(temp->next){
      temp=temp->next;
   }
   temp->next=newnode;
}
void printlist(struct node** header){ //question 1
   struct node* temp=(*header);
   while(temp){
      printf("%d\t",temp->data);
      temp=temp->next;
   }
   puts("");
}
void count_max_min(struct node** header){//q2
   struct node* temp=(*header);
   int c=0;
   int max=temp->data,min=temp->data;
   while(temp){
      c++;
      if(temp->data > max){
         max=temp->data;
      }
      if(temp->data < min){
         min=temp->data;
      }
      temp=temp->next;
   }
   printf("count = %d\nmax val= %d\nmin val=%d\n",c,max,min);
}
void find_Non_recursive(struct node** header,int x){//q3
   struct node* temp=(*header);
   int counter=1;
   while(temp){
      if(temp->data == x){
         printf("********************\nyo yo i found it \n");
         printf("in %p\nin the loc %d of the list\n",temp,counter);
         return; 
      }
      else{
         temp=temp->next;
      }
      counter++;
   }
   printf("404 not found \n");
}
void find_recursive(struct node** header,int x,int counter){//q3
   struct node* temp=(*header);
   if(temp->data == x){
      printf("********************\nyo yo i found it \n");
      printf("in %p\nin the loc %d of the list\n",temp,counter);
      return;
   }
   else{
      if(temp->next != NULL){
         printf("404 not found \n");
      }
      else{
         temp=temp->next;
         find_recursive(&temp,x,counter+1);
      }
   }
}
void print_lost(struct node** main_l,struct node** main_p){//q5
   struct node* l=(*main_l);
   while(l){
      struct node* p=(*main_p);
      int m=1;
      while(p){
         if(m == l->data){
            printf("in the position of %d i found %d\n",l->data,p->data);
         }
         p=p->next;
         m++;
      }
      l=l->next;
   }
}
void union_l(struct node ** h1,struct node** h2){
   struct node * l=(*h1);
   while(l){
      struct node* p=(*h2);
      while(p){
        if(l->data == p->data){
            l->data=NULL;
         }
         p=p->next;
      }
   l=l->next;
   }
   struct node * l2=(*h1);
   struct node* p2=(*h2);
   while(l2){
      if(l2->data != NULL){
         insert_at_the_end(&p2,l2->data);
      }
      l2=l2->next;
   }

}
void revers(struct node** head){
   struct node* current=(*head);
   struct node* next=NULL;
   struct node* prev=NULL;
   while(current != NULL){
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
   }
   *head=prev;
}
int main(){
   struct node* newnode=creat(5);
   insert_in_b(&newnode,4);
   insert_at_the_end(&newnode,6);
   insert_at_the_end(&newnode,7);
   count_max_min(&newnode);
   printlist(&newnode);
   find_recursive(&newnode,4,1);
   find_Non_recursive(&newnode,4);
   struct node* l=creat(1);
   struct node* p=creat(1);
   for(int i=2;i<8;i++){//just example
      insert_at_the_end(&l,i);
      insert_at_the_end(&p,i*5);
   }
   printlist(&l);
   printlist(&p);
   print_lost(&l,&p);
   insert_in_middle(&newnode,99);
   printlist(&newnode);
   puts("before");//q8
   printlist(&p);
   printlist(&l);
   union_l(&l,&p);
   puts("after");
   printlist(&p);
   revers(&p);//q10
   printlist(&p);
}

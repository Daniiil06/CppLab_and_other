#include <iostream>
using namespace std;

struct Stack {
    int info;
    Stack *next, *past;
} *t, *p; 

Stack *AddStack (Stack *, Stack **, int);
Stack *Addbegin (Stack *, Stack **, int);
void View (Stack *);
void Dell_All (Stack *);
Stack *Select(Stack *, Stack **);
void View_back (Stack *);



  

int main (){
    Stack *begin1, *end; int j, k, N;
    begin1=end=NULL;
    restart:
    cout<<"Add Stack end - 1"<<endl<<"Add Stack begin - 2"<<endl<<"Introduce number - ";
    cin>>N;

switch (N){

   case 1: cout<<"Vvedite kol-vo elementov ocheredi: "; cin>>j; cout<<endl;
    for (int i=0; i<j; i++){ 
        k=-50+rand()% 100;
        begin1=AddStack(begin1, &end, k);}
    break;   
   case 2:   cout<<"Vvedite kol-vo elementov ocheredi: "; cin>>j; cout<<endl;
    for (int i=0; i<j; i++){ 
         k=-50+rand()% 100;
        begin1=Addbegin(begin1, &end, k);}
    break;  
   default: {cout<<"___ PLEASE ENTER 1 OR 2 ___"<<endl; goto restart; }
}


  
   cout<<"Ochered do sortirovki:"<<endl;
  View (begin1); cout<<endl; 

begin1=Select(begin1, &end);

 cout<<"Ochered posle sortirovki:"<<endl;
  View (begin1); cout<<endl; 


 cout<<"Ochered naoborot:"<<endl;
  View_back (end); cout<<endl; 

  Dell_All (begin1);
  
  
  }











Stack *Select(Stack *p, Stack **end){
    int min=51, max=-51; int p_max, p_min, k; k=0;
    Stack *max_a,   *min_a,   *next_max,  *next_min,  *past_max,   *past_min, *begin1=p;

begin1=Addbegin(begin1, end, 0);
begin1=AddStack(begin1, end, 0);


 while ((p->next)!=NULL){
     k++; 
     if( min>(p->info)){
     min=p->info;
     min_a=p;
     past_min=p->past;
     next_min=p->next;
     p_min=k;
     }
     if(max<(p->info)){
     max=p->info;
     max_a=p;
     past_max=p->past;
     next_max=p->next;
     p=p->next;
     p_max=k;
     } else p=p->next;
 }
 
 cout<<"max element: "<<max<<" pos - "<<p_max<<endl;
 cout<<"min element: "<<min<<" pos - "<<p_min<<endl;
 


p=begin1;
Stack*m, *z, *o, *n;
  m=past_max;
  z=past_min;
  o=next_max;
  n=next_min;

if (p_max-p_min==1 || p_min-p_max==1){
     if (p_min-p_max==1){
max_a->next=n;
max_a->past=min_a;


min_a->next=max_a;
min_a->past=m;

n->past=max_a;
m->next=min_a;
     }
     if (p_max-p_min==1){
       
max_a->next=min_a;
max_a->past=z;


min_a->next=o;
min_a->past=max_a;

z->next=max_a;
o->past=min_a;
     }
}
else{
  min_a->next=o;
  min_a->past=m;

  max_a->next=n;
  max_a->past=z;


   m->next=min_a;
   o->past=min_a;

   z->next=max_a;
   n->past=max_a;
}

t=begin1; begin1=begin1->next; begin1->past=NULL; delete t;
t=*end; *end=(*end)->past; (*end)->next=NULL; delete t;  

 return begin1;
}

   Stack *AddStack (Stack *begin1, Stack **end, int in){
    
    t= new Stack;
    t->info= in;
    t->next=NULL; 
    t->past=(*end);   
    if ((*end)==NULL) begin1=t;
    else (*end)->next=t;
    (*end)=t;

    return begin1;
}

void View (Stack *p){
    while(p!=NULL){
        if ((p->info)<0)
        cout<<p->info<<endl;
        else cout<<" "<<p->info<<endl;
        p=p->next;
        
    } 
}


void View_back (Stack *p){
    while(p!=NULL){
        if ((p->info)<0)
        cout<<p->info<<endl;
        else cout<<" "<<p->info<<endl;
        p=p->past;
    } 
}

void Dell_All (Stack *begin1){
    while(begin1!=NULL){
        t=begin1;
        begin1=begin1->next;
        delete t;
    }

}

   Stack *Addbegin (Stack *begin1, Stack **end, int in){
    
    t= new Stack;
    t->info= in;
   t->past=NULL;
    t->next=begin1;   
    if (begin1==NULL) *end=t;
    else begin1->past=t;
    begin1=t;

    return begin1;
}
#include "heap.h"
static void h_swap(Heap h, int index, int largest){
    ITEM t_item;
    int t_pr;
    t_item = h->V[index].item;
    t_pr = h->V[index].p;
    h->V[index].item = h->V[largest].item;
    h->V[index].p = h->V[largest].p;
    h->V[largest].item = t_item;
    h->V[largest].p = t_pr; 
}
static int cmp_item(int l_p,int i_p){
    return l_p>i_p?1:0;
}
Heap heap_init(int maxSize){
    Heap h = NEW(h);
    h->V = NEW_VECT(maxSize,h->V);
    h->size = 0;
    return h;
}
void heap_append(Heap h,ITEM Item,int pr){
    int i = h->size++;
    h->V[i].item = Item;
    h->V[i].p = pr;
}
int heap_display(Heap h, void (*print_item)(ITEM)){
    int i;
    if(!print_item){
        return 1;
    }
    for(i=0;i<h->size;i++)print_item(h->V[i].item);
    return 0;
}

void heapify(Heap h,int index){
    int largest=index;
    int l = LEFT(index);
    int r = RIGHT(index);
    //If left (or right) item is greater than index return 1
    if (l<h->size && cmp_item(h->V[l].p,h->V[index].p))
        largest = l;
    if (r<h->size && cmp_item(h->V[r].p,h->V[index].p))
        largest = r;
    if(largest!=index){
        h_swap(h, index, largest);
        heapify(h,largest);
    }
}
void heap_build(Heap h){
    int i;
    for(i=PARENT(h->size-1);i>=0;i--)
        heapify(h,i);
}
void heap_sort(Heap h){
    int tempsize = h->size;
    while(h->size){
        heap_build(h);
        h_swap(h,0,h->size-1);
        h->size--;
    }
    h->size = tempsize;
}
void heap_free(Heap h,void (*free_item)(ITEM)){
    int i;
    if(!free_item) free(h->V);
    else
        for(i=0;i<h->size;i++) free_item(h->V[i].item);
    free(h);
}
#include <stdio.h>
#include <stdlib.h>

struct array
{
    int a[10];//*a;
    int size;
    int len;
};
void displaythearray(struct array arr)
{
    int i;
    for(i=0;i<arr.len;i++)
    {
        printf("%d ",arr.a[i]);
    }
    printf("\n");
}
void append(struct array *arr,int x)
{
    if(arr->len < arr->size)
    {
        arr->a[arr->len++]=x;
    }
}
void insert(struct array *arr,int index,int x)
{
    if(index>=0 && index<=arr->len)
    {
        for(int i=arr->len;i>index;i--)
        {
            arr->a[i]=arr->a[i-1];
        }
        arr->a[index]=x;
        arr->len++;
    }
}
void deletee(struct array *arr,int index)
{
    int x=0;
    if(index>=0 && index<arr->len)
    {
        x=arr->a[index];
        for(int i=index;i<arr->len-1;i++)
        {
            arr->a[i]=arr->a[i+1];
        }
        arr->len--;
        return x;
    }
}
int linear(struct array arr,int key)
{
    for(int i=0;i<arr.len;i++)
    {
        if(key==arr.a[i])
        {
            return i;
        }

    }
    return -1;
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int imp2linear(struct array *arr,int key)
{
    for(int i=0;i<arr->len;i++)
    {
        if(key==arr->a[i])
        {
            swap(&arr->a[i],&arr->a[0]);
            return i;
        }
    }
}
int imp1linear(struct array *arr,int key)
{
    for(int i=0;i<arr->len;i++)
    {
        if(key==arr->a[i])
        {
            swap(&arr->a[i],&arr->a[i-1]);
            return i-1;
        }
    }
}
int binary(struct array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.len-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.a[mid])
        {
            return mid;
        }
        else if(key<arr.a[mid])
        {
            h=mid-1;
        }
        else
        {
             l=mid+1;
        }
    }
    return -1;
}
int binsearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h){
    mid=(l+h)/2;
    if(key==a[mid])
    {
        return mid;
    }
    else if(key<a[mid])
    {
        return binsearch(a,l,mid-1,key);
    }
    else{
        return binsearch(a,mid+1,h,key);
    }
    }
    return -1;
}
int main()
{
   struct array arr={{2,4,6,8,1},10,5};//struct array arr;
  // printf("tell us the size\n");
   //scanf("%d",&arr.size);
   //arr.a=(int*)malloc(arr.size*sizeof(int));
   //arr.len=0;
   //int n,i;
   //printf("how many elements do you want to fill?\n");
   //scanf("%d",&n);
   //for(i=0;i<n;i++)
   //{
     //  scanf("%d",&arr.a[i]);
   //}
   //arr.len=n;

   append(&arr,10);
   insert(&arr,3,7);
   deletee(&arr,2);
   displaythearray(arr);
   printf("%d\n",linear(arr,1));
   printf("%d\n",imp1linear(&arr,7));
   displaythearray(arr);
   printf("%d\n",imp2linear(&arr,10));
   displaythearray(arr);
   printf("%d\n",binary(arr,8));
   displaythearray(arr);
   printf("%d\n",binsearch(arr.a,0,arr.len,6));

}

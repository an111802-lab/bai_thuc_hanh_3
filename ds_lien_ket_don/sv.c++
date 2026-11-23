#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char hoten[30];
    int msv;
    double d1, d2, d3;
} data;
typedef struct tagnode
{
    data in4;
    struct tagnode *link;
} Node;
typedef struct
{
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
// hàm khởi tạo
void initList(LList *L)
{
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptylist(LList L)
{
    return (L.spt == 0);
}
// thêm đầu
void insert_head(LList *L, data x)
{
    Node *pp;                          // khai báo
    pp = (Node *)malloc(sizeof(Node)); // cấp phát bộ nhớ
    // khởi tạo dữ liệu
    pp->link = NULL;
    pp->in4 = x;
    if (emptylist(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
    }
    else
    {
        L->pHead = pp->link;
        L->pHead = pp;
    }
    L->spt++;
}
// thêm đuôi
void insert_tail(LList *L, data x)
{
    Node *pp;                          // khai báo
    pp = (Node *)malloc(sizeof(Node)); // cấp phát bộ nhớ
    // khởi tạo dữ liệu
    pp->link = NULL;
    pp->in4 = x;
    if (emptylist(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
    }
    else
    {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}
// thêm giữa
void insert_after(LList *L, Node *q, data x)
{
    Node *pp;
    if (q == NULL)
        return;
    else
    {
        pp->in4 = x;
        pp->link = NULL;
        pp->link = q->link;
        q->link = pp;
        if (q == L->pTail)
            L->pTail = pp;
        L->spt++;
    }
}
void nhap(data *x)
{
    printf("Nhap ma sv: ");
    scanf("%d", &(x->msv));
    if (x->msv > 0)
    {
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(data x)
{
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n",
           x.hoten, x.msv, x.d1, x.d2, x.d3);
}
void processList(LList L)
{
    Node *pp = L.pHead;
    while (pp != NULL)
    {
        in(pp->in4);
        pp = pp->link;
    }
}
// tach danh sach
void tachds(LList *L1, LList *L2, LList L)
{
    initList(L1);
    initList(L2);
    Node *pp = L.pHead;
    while (pp != NULL)
    {
        //sv truot mon
        if (pp->in4.d1 < 4 || pp->in4.d2 < 4 || pp->in4.d3 < 4)
        {
            insert_head(L1, pp->in4);
        }
        else
        {
            insert_head(L2, pp->in4);
        }
        pp = pp->link;
    }
}
//ghep danh sach
//tim kiem theo ten/diem...
Node *search(LList L,char name[30]){
    Node *pp;
    pp=L.pHead;
    while(pp!=NULL&&!strstr(pp->in4.hoten,name)){
        pp=pp->link;
    }
    return pp;
}
//chuc nang xoa theo ten, diem...
//xoa dau
void del_head(LList *L){
    Node *pp;
    if(emptylist(*L)) return;
    else{
        pp=L->pHead;
        L->pHead=pp->link;
        free(pp);
        L->spt--;
        if(L->pHead==NULL) L->pTail==NULL;
    }
}
//xoa sau
void del_after(LList *L,Node *q){
    Node *pp;
    if(q==NULL) return;
    else{
        pp=q->link;
        if(q->link==L->pTail) L->pTail=q;
        q->link=pp->link;
        free(pp);
        L->spt--;

    }
}
//xoa theo ten
void del_ten(LList *L,char ten[30]){
    Node *pp=L->pHead;
    Node *q;
    while(pp!=NULL&&!strstr(pp->in4.hoten,ten)){
        q=pp;
        pp=pp->link;
    }
    if(pp==NULL) return;
    else{
        if(pp==L->pHead) del_head(L);
        else del_after(L,q);
    }

}

int main()
{
   LList L;
	int kt = 0;
	data x;
    char name[30];
    Node *kq,*q;
    initList(&L);
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n4: Xoa nut theo ten");
        printf("\n5: Tim theo ten");
        printf("\n6: Sua thong tin");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
            case 1: 
	            printf("Nhap so thong tin sv can them\n");
	            nhap(&x);
	            if(x.msv > 0) 
                	insert_head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thong tin sv can them\n");
	            nhap(&x);
	            if(x.msv > 0) 
                	insert_tail(&L, x);
            	break;
            case 3:
	            printf("Nhap so thong tin sv can them\n");
	            nhap(&x);
	            if(x.msv > 0) 
                	insert_after(&L,q,x);
            	break;
            case 5:
                printf("Ban muon tim ai");
                scanf("%s",name);
                kq=search(L,name);
                if(kq==NULL){
                    printf("Khong co nguoi can sua");
                }else in(kq->in4);
                break;
            case 4:
                printf("Ban muon xoa ai");
                scanf("%s",name);
                del_ten(&L,name);
                break;
            case 6:
                printf("Ban muon sua ai");
                scanf("%s",name);
                kq=search(L,name);
                if(kq==NULL){
                    printf("Khong co nguoi can sua");
                }else{
                    printf("Nhap so thong tin sv can them\n");
                    nhap(&x);
                    kq->in4=x;
                    break;
                }
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
    
}

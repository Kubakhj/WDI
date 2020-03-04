#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
};
void wypisz(node* h)
{
    if(h==NULL)
    {
    cout<<"PUSTA";
    return;
    }
    do
    {
    cout<<h->data<<" ";
    h=h->next;
    }
    while(h!=NULL);
}

void dodajdolisty(node* &h,int element)
{
    node* t=h;
    node* n;
    while((t!=NULL)&&(t->next!=NULL))
    {
        t=t->next;
    }
    n=new node;
    n->data=element;
    n->next=NULL;
    if(t==NULL) h=n;
    else t->next=n;
    }
void wyczyscliste(node* &h)
{
    h=NULL;
    return;
}
void dodajnapoczatek(node* &h,int element)
{
    node* t;
    t=new node;
    t->data=element;
    t->next=h;
    h=t;
    return;
}
void usunzlisty(node* &h)
{
    if(h==NULL) return;
    if(h->next==NULL)
    {
        h=NULL;
        return;
    }
    node* t=h;
    while(((t->next)->next)!=NULL)
    {
        t=t->next;
    }
    t->next=NULL;
}
void usuncodrugi(node* &h)
{
    if(h==NULL) return;
    node* t=h;

    while (((t->next)!=NULL)&&(((t->next)->next)!=NULL))
    {
    t->next=((t->next)->next);
    t=t->next;
    }
    t->next=NULL;
    return;
}
void parzystenapoczatek(node* &h)
{
    if(h==NULL) return;
    node* t=h;
    node* p;
    while(t->next!=NULL)
    {
    if(((t->next)->data)%2==0)
    {
        p=t->next;
        (t->next)=p->next;
        p->next=h;
        h=p;
    }
    else
    {
        t=t->next;
    }
    }
    return;

}
void parzystenapoczatek2(node* &h)
{
    node* wartownik;
    wartownik=new node;
    wartownik->next=h;
    node* prev=wartownik;
    node* p=h;
    while(p!=NULL)
    {
        if((p->data%2==0)&(p!=h))
        {
            prev->next=p->next;
            p->next=h;
            h=p;
            wartownik->next=h;
            p=prev->next;
        }
        else
        {
            prev=p;
            p=p->next;
        }
    }
    return;
}
void usunklucz(node* &h, int klucz)
{
    if(h==NULL) return;
    if(h->data==klucz)
    {
        h=h->next;
        return;
    }

    node* t=h;

    while((t->next)!=NULL)
    if(((t->next)->data)==klucz)
    {
        if (((t->next)->next)==NULL)
        {
            t->next=NULL; return;
        }
        else
        {
            t->next=((t->next)->next);
            return;
        }
        t=t->next;
    }
    return;
}
void usunpod(node* &h)
{
    if(h==NULL) return;
    node* start;
    node* koniec;
    node* t=h;
    node* wartownik=new node;
    wartownik->next=h;
    node* prev=wartownik;
    int dlugoscmax=1;
    while((t!=NULL)&&(t->next!=NULL))
    {
        if(t->data!=(t->next)->data)
        {
            prev=t;
            t=t->next;
        }
        else
        {
            int dlugosctemp=1;
            while((t->next!=NULL)&&(t->data==(t->next)->data))
            {
                dlugosctemp++;
                t=t->next;
            }
            if(dlugosctemp>dlugoscmax)
            {
                start=prev;
                koniec=t->next;
                dlugoscmax=dlugosctemp;
            }
            else if (dlugosctemp==dlugoscmax)
            {
                start=NULL;
            }
            prev=t;
            t=t->next;
        }
    }
    if(start!=NULL)
    {
        if(start->next==h)
        {
            h=koniec;
        }
        start->next=koniec;
    }
}
void dodaj_w_porzadku(node* &h,int a) //Funkcja wstawiajaca liczbe do posortowanej listy tak, aby dalej byla ona posortowana
{
    node* p;
    node* n;
    if(h==NULL)
    {
        p=new node;
        p->data=a;
        h=p;
        return;
    }
    p=h;
    if(a<=(p->data))
    {
        n=new node;
        n->data=a;
        n->next=h;
        h=n;
        return;
    }
    while(p->next!=NULL)
    {
        if ((a>=(p->data))&&((a<=((p->next)->data))))
        {
            n=new node;
            n->data=a;
            n->next=p->next;
            p->next=n;
            return;
        }
        p=p->next;
    }
    if(a>=(p->data))
    {
        n=new node;
        n->data=a;
        n->next=NULL;
        p->next=n;
        return;
    }
}
void Insert_sort(node* &h)
{
    node* h1=NULL;
    while(h!=NULL)
    {
        node* p=h;
        dodaj_w_porzadku(h1,p->data);
        h=h->next;
        delete p;
    }
    h=h1;
}
void ListSwap(node *p1, node *p2)
{
    int temp=p1->data;
    p1->data=p2->data;
    p2->data=temp;
}
void QuickSort(node *h,node *p)
{
    if((h==NULL)||(h==p)) return;
    node* x=h;
    node* y=h;
    node* prevY;
    while(x!=p)
    {
        if(x->data<=p->data)
        {
            ListSwap(x,p);
            prevY=y;
            y=y->next;
        }
        x=x->next;
    }
    ListSwap(x,y);
    QuickSort(h,prevY);
    QuickSort(y->next,p);
}
node* tail(node* h)
{
    while((h!=NULL)&&(h->next!=NULL))
    {
        h=h->next;
    }
    return h;
}
int main()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    // Na start deklaruje pusta liste:
    node* n;
    node* h;
    n=NULL;
    h=NULL;
    for(;;)
    {
    node* l1=NULL;
    node* l2=NULL;
    cout<<"Twoja lista: "<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); //Ustawiam kolor wyswietlanej listy
    wypisz(h);
    SetConsoleTextAttribute( hOut, 7 );
    cout<<endl<<endl;
    cout<<"Wybierz opcje: "<<endl;
    cout<<"[1] Dodaj element na poczatek listy"<<endl;
    cout<<"[2] Dodaj element na koniec listy"<<endl;
    cout<<"[3] Usun ostatni element z listy"<<endl;
    cout<<"[4] Usun co drugi element listy"<<endl;
    cout<<"[5] Usun klucz z listy"<<endl;
    cout<<"[6] Przenies parzyste elementy na poczatek listy"<<endl;
    cout<<"[7] Wyczysc liste"<<endl;
    cout<<"[8] Usun najdluzsza stala podliste z listy"<<endl;
    cout<<"[9] Posortuj przez wstawianie"<<endl;
    cout<<"[10] Sortuj przez QuickSort//NOT DONE"<<endl;
    cout<<"Wybor: ";
    int wybor;
    cin>>wybor;
    switch(wybor)
    {

    case 1:
        cout<<"Jaki element chcesz dodac? ";
        int elementp;
        cin>>elementp;
        dodajnapoczatek(h,elementp);
        break;
    case 2:
        cout<<"Jaki element chcesz dodac? ";
        int element;
        cin>>element;
        dodajdolisty(h,element);
        break;
    case 3:
        usunzlisty(h);
        break;
    case 4:
        usuncodrugi(h);
        break;
    case 5:
        cout<<"Podaj klucz: ";
        int klucz;
        cin>>klucz;
        usunklucz(h,klucz);
        break;
    case 6:
        parzystenapoczatek2(h);
        break;
    case 7:
        wyczyscliste(h);
        break;
    case 8:
        usunpod(h);
        break;
    case 9:
        Insert_sort(h);
        break;
    case 10:
        QuickSort(h,tail(h));
        break;

    }
    system("CLS");
    }
    return 0;
    }

/*Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers*/


#include <iostream>
#include<string.h>
using namespace std;
struct data
{
    char name[30];
    long  telephone_no;
};
class hash1
{
private:
    int n,sym,x,c,i,j;
    char client_name[30];
    long no;
    struct data d[10];
public:
    hash1(){
        for (int i = 0; i < 10; i++)
        {
            d[i].telephone_no=0;
            strcpy(d[i].name,"NIL");
        }
    }
    void linear_probing_insert();
    void search();
    void display();
    void delete_entries();
    void quadratic_probing_insert();
};

void hash1::linear_probing_insert()
{
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name: ";
        cin>>client_name;
        cout<<"Enter the number: ";
        cin>>no;
        int sum=0;
        for (int i = 0; i < strlen(client_name); i++)
        {
            sum=sum+client_name[i];
        }
        x=(sum/strlen(client_name))%10;
        c=x;
        while (1)
        {
            if (d[x].telephone_no==0)
            {
                strcpy(d[x].name,client_name);
                d[x].telephone_no=no;
                break;
            }
            x=(x+1)%10;                             // Linear Probing
            if(c==x){
                cout<<"Hash table is full"<<endl;
                break;
            }
        }
    }
}

void hash1::quadratic_probing_insert(){
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name: ";
        cin>>client_name;
        cout<<"Enter the number: ";
        cin>>no;
        int sum=0;
        for (int i = 0; i < strlen(client_name); i++)
        {
            sum=sum+client_name[i];
        }
        x=(sum/strlen(client_name))%10;
        cout<<"The hash value for this entry is: "<<x<<endl;
        c=x;

        for (int j=1; j <=10; j++ )        
        {
            if (d[x].telephone_no==0)
            {
                strcpy(d[x].name,client_name);
                d[x].telephone_no=no;
                break;
            }
            x=(x + j*j) % 10;                       // Quadratic Probing
            if(c==x){
                cout<<"Hash table is full"<<endl;
                break;
            }
        }
    }
    

}

void hash1::search(){
    cout<<"\n\nEnter the name to search :";
    cin>>client_name;
    int sum=0;
    for (int  i = 0; i < strlen(client_name); i++)
    {
        sum=sum+(int)client_name[i];
    }
    x=(sum/strlen(client_name))%10;
    c=x;
    while (1)
    {
        if(!strcmp(d[x].name, client_name)){
            cout<<"Data found : Telephone No. : "<<d[x].telephone_no<<endl;
            break;
        }
        x=(x+1)%10;
        if(c==x){
            cout<<"Data not found "<<endl;
            break;
        }
    }
    
}
void hash1::display(){
    cout<<"Records are : ";
    for (int i = 0; i < 10; i++)
    {
        cout<<endl<<d[i].name<<" "<<d[i].telephone_no;
    }
    
}

void hash1::delete_entries(){

    char del[30];
    cout<<"Enter the name of the client to be deleted: ";
    cin>>del;

    int sum=0;
    for (int  i = 0; i < strlen(del); i++)
    {
        sum=sum+(int)del[i];
    }
    x=(sum/strlen(del))%10;
    c=x;
    while (1)
    {
        if(!strcmp(d[x].name, del)){
            d[x].telephone_no=0; 
            strcpy(d[x].name,"NIL"); 
            cout<<"\nRecord erased successfully\n"<<endl;
            cout<<"The updated list is: "<<endl;
            display(); 
            break;
        }
        x=(x+1)%10;
        if(c==x){
            cout<<"Data not found "<<endl;
            break;
        }
    }
}

int main(){
    hash1 h;
    int op;

    do{
        cout<<"----------------------------"<<endl;
        cout<<"1.Insert using linear probing "<<endl;
        cout<<"2.Insert using quadratic probing"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.Search"<<endl;
        cout<<"5.deleted entries"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";

        cin>>op;
        switch(op)
        {
            case 1:
                h.linear_probing_insert();
                break;
            case 2:
                h.quadratic_probing_insert();
                break;
            case 3:
                h.display();
                break;
            case 4:
                h.search();
                break;
            case 5:
                h.delete_entries();
                break;
            
            case 6:
                cout<<"Exit from programm"<<endl;
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
            
        }
    }while(op!=7);
    return 0;
}

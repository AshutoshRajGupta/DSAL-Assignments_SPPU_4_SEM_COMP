#include<iostream>
using namespace std;

class node{
    public:
    string key;
    string meaning;
    node *left,*right;
};
class AVL{
    node * root;
    public:
    AVL(){
        root=NULL;
    }
    void create();
    node * insert(node * root,node * temp);
    node* balance(node * temp);
    int diff(node * temp);
    int height(node * temp);
    int maximum(int a,int b);

    node *LL(node *par);
    node *RR(node *par);
    node *LR(node *par);
    node *RL(node *par);

    void ascending(node * temp);
    void descending(node * temp);
    void display();
    bool search (node * cur,string key1);
    void search_value();

};

void AVL::create(){
    char ch;
    node * temp;
    do{
        temp=new node();
        cout<<"enter keyword : ";
        cin>>temp->key;
        cout<<"enter meaning: ";
        cin>>temp->meaning;
        temp->left=temp->right=NULL;

            root=insert(root,temp);

        cout<<"Do you want to continue (Y || N)"<<endl;
        cin>>ch;
    }while(ch=='y');
}

node * AVL::insert(node *root,node *temp)
{
    if(root==NULL)
    {
        return temp;
    }
    if(temp->key<root->key){
        root->left=insert(root->left,temp);
        root=balance(root);
    }
    else if(temp->key>root->key)
    {
        root->right=insert(root->right,temp);
        root=balance(root);
    }
    return root;
}

node * AVL::balance(node *temp)
{
    int bal;
    bal=diff(temp);
    if(bal>=2)
    {
        if(diff(temp->left)<0)
        temp=LR(temp);
        else
        temp=LL(temp);
    }
    else if(bal<=-2)
    {
        if(diff(temp->right)<0)
        temp=RR(temp);
        else
        temp=RL(temp);
    }
    return temp;
}

int AVL::diff(node * temp)
{
    int l,r;
    l=height(temp->left);
    r=height(temp->right);
    return (l-r);
}

int AVL::height(node * temp)
{
    if(temp==NULL)
    return (-1);
    else
    return (max(height(temp->left),height(temp->right))+1);
}

int AVL::maximum(int a ,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

void AVL::ascending(node * temp)
{
    if(temp!=NULL)
    {
        ascending(temp->left);
        cout<<"\n\t"<<temp->key<<":"<<temp->meaning;
        ascending(temp->right);
    }
}
void AVL::descending(node * temp){
    if(temp!=NULL)
    {
        descending(temp->right);
        cout<<"\n\t"<<temp->key<<":"<<temp->meaning;
        descending(temp->left);
    }
}

void AVL::display(){
    cout<<"\n The keywords in asscending order are: \n";
    ascending(root);
    cout<<"\n The keywords in descending order are: \n";
    descending(root);
}

node * AVL::LL(node *par)
{
    node *temp,*temp1;
    temp=par->left;
    temp1=temp->right;
    temp->right=par;
    par->left=temp1;
    return temp;
}
node * AVL::RR(node *par)
{
    node *temp,*temp1;
    temp=par->right;
    temp1=temp->left;
    temp->left=par;
    par->right=temp1;
    return temp;
}

node * AVL::LR(node *par)
{
    par->left=RR(par->left);      //rotating left subtree and then rotate parent
    return (LL(par));
}

node * AVL::RL(node *par)
{
    par->right=LL(par->right);      //rotating RIGHT subtree and then rotate parent
    return (RR(par));
}

bool AVL::search(node * cur,string key1)
{
    if(cur)
    {
        if(cur->key==key1)
        return true;
    
    if(cur->key>key1)
    return search(cur->left,key1);

    else
    return search(cur->right,key1);
    
    }
    return false;
    
}

void AVL::search_value()
{
    string key2;
    cout<<"\n Enter the keyword to be search : ";
    cin>>key2;
    if(search(root,key2))
    cout<<"the enter keyword is present"<<endl;
    else
    cout<<"the enter keyword is not present"<<endl;
}

int main(){
    char c;
    int ch;
    AVL a;
    do{
        cout<<"-----MAIN MENU------"<<endl;
        cout<<"1. insert in tree"<<endl;
        cout<<"2. display in tree"<<endl;
        cout<<"3. search in tree"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            a.create();
            break;

            case 2:
            a.display();
            break;

            case 3:
            a.search_value();
            break;

            default:
            cout<<"wrong choice enter"<<endl;

        }
        cout<<"Do you want to continue(y||n)"<<endl;
        cin>>c;

    }while(c=='y');
    return 0;
}
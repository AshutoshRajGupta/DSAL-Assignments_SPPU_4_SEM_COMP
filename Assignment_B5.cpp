/*A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. Find the time and space requirements of your method.*/

#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

//Node declaration
struct Node
{
    char data[10];
    int count;
    struct Node *child[10];
}*root;        //declaring root here

//class declaration
class GeneralTree
{
    public:
        void create_tree();
        void display(Node * r1);

        GeneralTree()
        {
            root=NULL;            //first we have initialises null to root node
        }
};

void GeneralTree::create_tree()
{
    int tbooks,tchapters,i,j,k;
    root = new Node;                 //created new  root node
    cout<<"Enter name of book : ";
    cin>>root->data;              //entering root data
    cout<<"Enter no of chapters in book : ";
    cin>>tchapters;
    root->count=tchapters;

    for(i=0;i<tchapters;i++)    //loop for chapters node in tree
    {
        root->child[i] = new Node;
        cout<<"Enter chapter name : ";
        cin>>root->child[i]->data;
        cout<<"Enter no of sections in chapter : "<<root->child[i]->data;
        cin>>root->child[i]->count;

    for (j=0;j<root->child[i]->count;j++)    //loop for sections in chapters in tree
    {
        root->child[i]->child[j] = new Node;
        cout<<"Enter section "<< j+1 <<"name : ";
        cin>>root->child[i]->child[j]->data;
    }
    }
}

void GeneralTree::display(Node *r1)
{
    int i,j,k,tchapters;
    if(r1!=NULL)
    {
        cout<<"\n ------BOOK HIERARCHY------<<endl";
        cout<<"\n Book Title : "<<r1->data;      //printing root data
        tchapters=r1->count;

        for(i=0;i<tchapters;i++)
        {
            cout<<"\n chapter "<<i+1;
            cout<<" "<<r1->child[i]->data;  //printing chapters node data
            cout<<"\n sections";

        for(j=0;j<r1->child[i]->count;j++)
        {
            cout<<"\n "<<r1->child[i]->child[j]->data;      //printing sections node data
        }
        }
    }
}

int main()
{
    int choice;
    GeneralTree gt;
    while ((1))
    {
        cout<<"-------------------"<<endl;
        cout<<"BOOK TREE CREATION"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                    gt.create_tree();
                    break;
            case 2:
                    gt.display(root);
                    break;
            case 3:
                    exit(1);
            default:
                    cout<<"Wrong choice"<<endl;
        }
    }
    
}
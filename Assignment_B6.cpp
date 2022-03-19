/* DSAL Grp B-6:
Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, 
ii. Find number of nodes in longest path from root, 
iii. Minimum data value found in the tree,
iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
v. Search a value
*/

#include <iostream>
using namespace std;
// Binary Tree
struct node{
    int data;
    node *left, *right;
};
class tree{

    public:
        node *root, *temp;
        tree(){
            root = NULL;
        }

        void create_tree();
        void insert(node* , node*);
        void Inorder(node* root);
        void search(node* root, int x);
        void minimum(node* root);
        int longestpath(node *temp);
        void mirror(node * root);
};

void tree::create_tree()
{
    root=NULL;
    char ch;
    do{
        temp = new node;          //creating root node here
        cout<<"Enter data : ";
        cin>>temp->data;
        temp->left=NULL;          //assigning null to left and right child of node
        temp->right=NULL;

        if(root==NULL){      //if there is not any node so it will create a new node
            root = temp;
        }
        else{
            insert(root,temp);     //and if there already a node so it will create a child node
                }
        cout<<"Do you want to continue?(Y or N) ";
        cin>>ch;
    }
    while(ch=='y');
}

void tree::insert(node * root, node* temp)
{
    char ch1;
    if(temp->data < root->data)
    {
        if(root->left == NULL){
            root->left = temp;       
        }
        else{
            insert(root-> left, temp);
        }
    }
    else if(temp->data > root->data)
    {
        if(root->right == NULL){
            root->right = temp;
        }
        else{
            insert(root->right, temp);
        }
    }
}

void tree::Inorder (node* root)
{
    if (root!=NULL)
    {
        
        Inorder(root->left);
        cout<<root->data<<endl;
        Inorder(root->right);
    }
}

void tree::search(node* root, int x)
{
    int flag = 0;
    while(root!=NULL)
    {
        if(x < root->data){
            root = root->left;
        }
        else if (x > root->data){
            root = root->right;
        }
        else if (x == root->data){
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        cout<< "Data found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}

void tree::minimum(node* root)
{
    while(root->left!=NULL)
    root=root->left;
    cout<<root->data<<endl;
}

int tree::longestpath(node* root)
{
    if(root==NULL)
    return 0;

     //calculating the depth of left subtree
    int leftpath=longestpath(root->left);
    //calculating depth of right subtree
    int rightpath=longestpath(root->right);

    ///return max(leftpath,rightpath)+1;
    if(leftpath>rightpath)
        return leftpath+1;
    else
        return rightpath+1;
}

void tree::mirror(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        node *ptr;
        mirror(root->left);
        mirror(root->right);
        //swapping left and right child nodes
        ptr = root->left;
        root->left = root->right;
        root->right = ptr; 
    }
}

int main()
{
    tree t;
    int op,x;

    do{
        cout<<"----------------------------"<<endl;
        cout<<"operations on BST"<<endl;
        cout<<"1.Create BST "<<endl;
        cout<<"2.Inorder display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4 minimum"<<endl;
        cout<<"5.Longest path"<<endl;
        cout<<"6.Mirror"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice : ";

        cin>>op;
        switch(op)
        {
            case 1:
                t.create_tree();
                break;
            case 2:
                t.Inorder(t.root);
                break;
            case 3:
                cout<<"Enter the elemnt to search : ";
                cin>>x;
                t.search(t.root,x);
                break;
            case 4:
                cout<<"Minimum element is:";
                t.minimum(t.root);
                break;
            case 5:
                cout<<"number of nodes in longest path from root is : ";
                cout<<t.longestpath(t.root)<<endl;
                break;
            case 6:
                t.mirror(t.root);
                t.Inorder(t.root);
                break;
            case 7:
                    cout<<"Exit from programm"<<endl;
                    exit(1);
            default:
                    cout<<"Wrong choice"<<endl;
            
        }
    }while(op!=8);
    return 0;
}
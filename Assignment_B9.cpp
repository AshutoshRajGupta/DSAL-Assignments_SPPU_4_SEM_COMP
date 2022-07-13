/*Convert given binary tree into threaded binary tree.
 Analyze time and space complexity of the algorithm.*/

#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        int lbit;       
        int rbit;
    
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        lbit = 0;
        rbit = 0;
    }
};

class tree{
    public:
        node* create(node* root);                     
        void insert(node* root, int val);    
        void inorder(node* head);
        


};

node* tree::create(node* root)
{
    char ch;
    int data;
    node* head;
    
    do{
        cout<<"Enter the data for the node: "<<endl;
        cin >> data;
        node* temp = new node(data);        

        // node* root = temp;

        if(root==NULL)                      // if the tree is empty initially
        {
            root = temp;
            head= new node(-999);           // creation of the dummy node (called as the head node here)

            head->left=root;                // left pointer of the dummy node points to the root node
            head->right=head;               // the right pointer points to itself
            head->lbit=1;
            head->rbit=1;
            root->left=head;    
            root->right=head;
        }
        else
        {
            insert(root,data);
        }
    
    cout<<"Do u want to insert any new node?";
    cin>>ch;
        
    }while(ch=='y' || ch=='Y');
    return head;

}


void tree::insert(node* root, int val)       
{
    if(val < root->data)                    // this is a BST too
    {
        if(root->lbit == 0)                 // check if there is no child present
        {
            node* temp = new node(val);
            temp->left=root->left;          // inorder predecessor
            temp->right=root;               // inorder successor
            root->left=temp;
            root->lbit=1;
        }
        else                                // if there is a child to the node we're inserting, move on to the next node according to BST
        {
            insert(root->left,val);
        }
    }
    else
    {
        if(root->rbit == 0)
        {
            node* temp = new node(val);
            temp->left=root;
            temp->right=root->right;
            root->right=temp;
            root->rbit=1;
        }
        else
        {
            insert(root->right,val);
        }
    }
}

void tree::inorder (node* head)
{
    node* t = head->left;                   // temporary pointer
    do
    {
        while(t->lbit!=0)
        {
            t = t->left;
        }
        cout<< t->data<<" ";
        while(t->rbit == 0)
        {
            t = t->right;
            if (t == head){
                return;
            }
            cout << t->data<<" ";
        }
        t = t->right;
    }while (t != head);
}




int main()
{
    
    tree t1;
    node* root = NULL;
    node* head = NULL;
    head = t1.create(root);

    cout << "Inorder traversal of the tree: "<<endl;
    t1.inorder(head);
    cout<<endl;
    return 0;
}
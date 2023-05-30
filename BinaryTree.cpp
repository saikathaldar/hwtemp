#include<iostream>

struct Btree {
    int node;
    struct Btree * left;
    struct Btree * right;
};

Btree * NewNode(int val)
{
    Btree * NewNode;
    NewNode = new Btree;
    NewNode->node=val;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;

}

void InsertNode(Btree * node, int val)
{

    if(val < node->node)
    {
        if((node->left)==NULL)
            node->left=NewNode(val);
        else
            InsertNode(node->left,val);
    }
    else{
        if((node->right)==NULL)
            node->right=NewNode(val);
        else
            InsertNode(node->right,val);
    }

}

void TraverseNode(Btree * node)
{
    if((node->left)!=NULL)
        TraverseNode(node->left);
    
    std::cout << node->node<< ' ';
    
    if((node->right)!=NULL)
        TraverseNode(node->right);
}

bool  SearchNode(Btree * node,int i)
{
    bool ret;
    if((node->left)!=NULL)
    {
        ret=SearchNode(node->left,i);
        if (ret == true)
            return true;
    }
    
    if(node->node == i)
    {
      return true;
    }
    
    if((node->right)!=NULL)
    {
        ret=SearchNode(node->right,i);
        if(ret == true)
            return true;
    }
    return false;
}

int main()
{
    int no;
    Btree * root = NewNode(5);
    InsertNode(root,2);
    InsertNode(root,1);
    InsertNode(root,3);
    InsertNode(root,4);
    InsertNode(root,9);
    InsertNode(root,10);

    TraverseNode(root);
    std::cout << "Give the number: ";
    std::cin >> no;
    if(SearchNode(root,no)==true)
        std::cout << "found";
    else
        std::cout << "not found";
    

    return 0;
}
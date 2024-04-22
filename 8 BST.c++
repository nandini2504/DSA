#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(){
        left=right=NULL;
    }
};
class Bst{
    public:
        Node*root;
//---------------------------------------
        Node* getroot(){
            return root;
        }
//----------------------------------------
        void insert(int data){
            Node*temp;
            Node*t=root;
            Node*r;
            if(root==NULL){
                temp=new Node();
                temp->data=data;
                root=temp;
                cout<<"Inserted"<<endl;
                return;
            }
            while(t!=NULL){
                r=t;
                if(t->data>data){
                    t=t->left;
            }
            else if(t->data<data){
                t=t->right;
            }
            else{
                return;
            }

        }
        temp=new Node();
        temp->data=data;
        if(r->data>data){
            r->left=temp;
        }
        else {
            r->right=temp;
        }
        cout<<"Inserted"<<endl;
        }
//----------------------------------------
        Node* search(int data){
            Node*temp;
            Node*t=root;
        
        while(t!=NULL){
            if(t->data==data){
                cout<<"Found"<<endl;
                return t;
            }
            else if(t->data<data){
                t=t->left;
            }
            else if(t->data>data){
                t=t->right;
            }
        }
            
                cout<<"Not Found"<<endl;
            
        }
//--------------------------------------
        void Inorder(Node*t){
            if (t){
                Inorder(t->left);
                cout<<t->data<<" ";
                Inorder(t->right);
            }  
            cout<<endl;
        }
//--------------------------------------
        void minnode(Node*root){
                Node*t=root;
                while(t->left!=NULL){
                    t=t->left;
                }
                cout<<t->data<<endl;
        }
//---------------------------------------
        void Mirror(Node*temp){
            if(temp==NULL){
                return;
            }
            else{
                Node*ptr;
                Mirror(temp->left);
                Mirror(temp->right);
                ptr=temp->left;
                temp->left=temp->right;
                temp->right=ptr;
            }
        }
//---------------------------------------
        int noofHeight(Node* node){
            if(node==NULL){
                return 0;
            }
            return max(1+noofHeight(node->left),1+noofHeight(node->right));
        }

};
int main(){
Bst bst;
 int ch;
 cout<<"1.Insert\n2.no of Nodes in Longest Path\n3.Minimum value\n4.Swapped Value\n5.Search\n6.Inorder Display\n7.Exit\n";
    do{
    cout<<"Enter your Choice : "<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter the Data :";
            int a;
            cin>>a;
            bst.insert(a);
            break;
        case 2:
            cout<<"no of nodes in longest Path : ",bst.noofHeight(bst.getroot());
            break;

        case 3:
            cout<<"Minimum data value found : ",bst.minnode(bst.getroot());
            break;

        case 4:
            cout<<"swapped"<<endl;
            bst.Mirror(bst.getroot());
            break;

        case 5:
            cout<<"Enter the Data to be Searched : "<<endl;
            cin>>a;
            bst.search(a);
            break;
        
        case 6:
            bst.Inorder(bst.getroot());
            break;
    }

    }while(ch!=7);
}

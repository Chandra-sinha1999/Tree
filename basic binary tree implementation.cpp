#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int d){
        val = d;
        left = NULL;
        right = NULL;
    }
};
node* buildtree(int x){
    if(x == -1) return NULL;
    node* root = new node(x);
    return root;
}
node* maketree(int *a,int n){
    node* root = NULL;
    queue<node*> q;
    for(int i = 0; i < n;){
        if(i == 0) {
            root = new node(a[i]);
            if(root) q.push(root);
        }
        int s = q.size();
        if(s == 0) break;
        while(s--){
            node* temp = q.front();
            //cout<<temp -> val<<endl;
            q.pop();
            i++;
            temp -> left = buildtree(a[i]);
            i++;
            temp -> right = buildtree(a[i]);
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
    return root;
}
//level order traversal
void printlevel(node* root){
    queue<node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            node* temp = q.front();
            q.pop();
            cout << temp -> val<<" ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
            if(!temp -> right){
            }
        }
        cout<<endl;
    }
}
//print recursive
void print(node* root){
    if(root == NULL) return;
    cout<<root -> val<<endl;
    print(root -> left);
    print(root -> right);
}
void preorder(node* root){
    if( root == NULL) return;
    cout<<root -> val<<"  ";
    preorder(root -> left);
    preorder(root -> right);
}
void inorder(node* root){
    if( root == NULL) return;
    inorder(root -> left);
    cout<<root -> val<<"  ";
    inorder(root -> right);
}
void postorder(node* root){
    if( root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> val<<"  ";
}
int main(void){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    node* root = maketree(a,n);
    //printlevel(root);
    //print(root);
    cout<<"preorder : ";
    preorder(root);
    cout<<endl<<"Inorder : ";
    inorder(root);
    cout<<endl<<"Postorder : ";
    postorder(root);
}


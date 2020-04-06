#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
int k = 0;
node* pretree(int *pre,int *in,int s,int e){
    if(s > e) return NULL;
    int index;
    node* root = new node(pre[k++]);
    for(int i = s; i <= e; i++){
        if(in[i] == root -> val){
            index = i;
            break;
        }
    }
    root -> left = pretree(pre,in,s,index - 1);
    root -> right = pretree(pre,in,index+1,e);
    return root;
}
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
int main(void){
    int n;
    cin>>n;
    int pre[n] , in[n];
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    node* root = pretree(pre,in,0,n-1);
    printlevel(root);
}

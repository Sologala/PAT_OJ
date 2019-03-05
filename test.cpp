#include<string>
#include<iostream>
using namespace std;
const int maxn = 100;
bool isRoot[maxn] = { true };
struct Node{
	string data;
	int l, r;
}a[maxn];

string DFS(int root){
    if (a[root].l == -1 && a[root].r == -1){
        return a[root].data;
    }
    if (a[root].l == -1 && a[root].r != -1){
        return "(" + a[root].data + DFS(a[root].r) + ")";
    }
    if (a[root].l != -1 && a[root].r != -1){
        return "(" + DFS(a[root].l) + a[root].data + DFS(a[root].r) + ")";
    }
    return "";
}

int main(){
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i].data >> a[i].l >> a[i].r;
		if (a[i].l != -1) isRoot[a[i].l] = true;
		if (a[i].r != -1) isRoot[a[i].r] = true;
	}
	int root = 1;
	while (isRoot[root] == false) root++;
	string ans = DFS(root);
	if (ans[0] == '(') ans = ans.substr(ans[1], ans.size() - 2);
	cout << ans << endl;
	return 0;
}
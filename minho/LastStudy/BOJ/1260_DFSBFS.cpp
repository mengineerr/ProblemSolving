#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>


using namespace std;


void BFS(vector <int> s[], int start, int size){
    int check[size+1] ={0,};
    int loc = start;
    queue <int> q;
    q.push(loc);
    check[loc] = 1;

    while(!q.empty()){
        loc = q.front();
        int len = s[loc].size();
        cout << loc << "\t";
        q.pop();
        for(int i = 0; i <len ; i++){
            if(check[s[loc][i]]==0){
                q.push(s[loc][i]);
                check[s[loc][i]] = 1;
            }
        }
    }

   
}


void DFS_Stack(vector <int> s[], int start,int size){
    int check[size+1] = {0,};

    int loc = start;

    stack <int> st;

    st.push(loc);
    check[loc] = 1;
    cout << loc << "\t";

    while(!st.empty()){
        loc = st.top();
        st.pop();

        int len = s[loc].size();

        for(int i = 0; i<len ; i++){
            int next_node = s[loc][i];

            if(check[next_node]==0){
                std:: cout << next_node <<"\t";
                check[next_node] = 1;
                st.push(loc);
                st.push(next_node);
                break;
            }
        }
    }

}


//재귀함수 구현
void DFS_Recursion(vector <int> s[], int start,int size, int check[]){
    
    int loc = start;
    if(check[loc]==0){
        check[loc] = 1;
        cout << loc << "\t";
    }
    
    int len = s[loc].size();
    for(int i = 0; i < len;i++){
        int next_node = s[loc][i];
        if(check[next_node]==0){
            cout << next_node << "\t";
            check[next_node] = 1;
            return DFS_Recursion(s,next_node,size,check);
        }
    }
}


int main()
{
    int N,M,L = 0; 
    cin >> N >> M >> L;
    vector <int> data[1000];
    int front,back = 0;

    for(int i = 0; i < M; i++){
        cin  >> front >> back;
        data[front].push_back(back);
        data[back].push_back(front);
    }

    for(int i = 1; i<=N; i++){
        sort(data[i].begin(),data[i].end());
    }

    for(int i = 1; i<=N; i++){
        int len = data[i].size();
        //cout <<  i << "'s vector : ";
        for(int j = 0; j<len; j++){
            //cout  << data[i][j] << "\t";
        }
        //cout << "\n";
    }

    int check[N+1] = {0,};
    //DFS_Stack(data,L,N);
    DFS_Recursion(data, L, N, check);

    std::cout << "\n";
    
    BFS(data, L, N);

    std::cout << "\n";

    
}
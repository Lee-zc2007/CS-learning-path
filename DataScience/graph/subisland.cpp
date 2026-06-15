#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//用dfs遍历
bool dfs(int **grid1, int **grid2, int m, int n, int x, int y){
    //只有grid2对应1的时候才被调用，设置为0防止重复搜索
    grid2[x][y] = 0;
    bool isSub = true;
    //检查是不是子图
    if (grid1[x][y] == 0) isSub == false;

    //遍历搜索，找到连接的1形成岛屿
    for (int k = 0; k<4; k++){
        //dx和dy拆开能在这里统一，不需要分情况写
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;//超过边界就进行下一次
        if (grid2[nx][ny] == 1){
            if (dfs(grid1, grid2, m, n, nx, ny) == false) isSub = false;//递归检查，连接着的点如果不符合子图，就不符合
        }
    }

    return isSub;
}


int main(){
    int m , n;
    cin >> m >> n;
    int **grid1 = new int* [m];
    int **grid2 = new int* [m];
    for (int i = 0; i<n; i++){
        grid1[i] = new int[n];
        grid2[i] = new int[n];
    }

    for (int i=0; i<m; i++){
        for (int j = 0; j<n; j++)
        cin >> grid1[i][j];
    }

    for (int i=0; i<m; i++){
        for (int j = 0; j<n; j++)
        cin >> grid2[i][j];
    }

    int ans = 0;
    for (int i=0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid2[i][j] == 1){
                if (dfs(grid1, grid2, m, n, i, j) == true) ans++
            }
        }
    }

    cout << ans << endl;
    return 0;
}
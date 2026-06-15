#include <iostream>
using namespace std;

const int MAXN = 1000;
int rear = 0, int front = 0;//分别指向队首和队尾
int qx[MAXN];
int qy[MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//bfs原则：先计算距离，再入队，出队直接使用这个距离
int bfs(char **grid, int **dist, int m, int n, int sx, int sy){
    qx[rear] = sx;
    qy[rear] = sy;
    rear++;

    while (front < rear){
        int x = qx[front];
        int y = qy[front];
        front++;

        if (grid[x][y] == 'A') return dist[x][y];

        //不是目标点就遍历周围的点
        for (int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >=m || ny < 0|| ny >=n) continue;//越界就跳过
            if (dist[nx][ny] != -1) continue;//访问过就跳过
            dist[nx][ny] = dist[x][y] + 1;
            //将周围的四个点入队
            qx[rear] = nx;
            qy[rear] = ny;
            rear++;
        }//rear = front后保证全部遍历
    }
    
    return -1;
}

int main(){
    int m, n;
    cin >> m >> n;
    char **grid = new char* [m];
    int **dist = new int* [m];

    for (int i=0; i<m; i++){
        grid[i] = new char[n];
        dist[i] = new int* [n];
        for (int j = 0; j<n; j++) dist[i][j] == -1;
    }

    int sx, sy;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S'){sx = i; sy = j;}
        }
    }

    cout << bfs(grid, dist, m, n, sx, sy) <<endl;
    return 0;
}
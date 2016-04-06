#include<iostream>
#include<queue>
using namespace std;
struct Point {
    int x, y;
    int step;
};
int main() {
    int maze[100][100];
    int n, i, j;
    Point tmp, next;
    queue<Point > q;
    for (cin >> n; n != 0; cin >> n) {
        while (!q.empty()) q.pop();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        maze[0][0] = 1;
        tmp.x = 0;
        tmp.y = 0;
        tmp.step = 1;
        q.push(tmp);
        while (!q.empty()) {
            tmp = q.front();
            if (tmp.x == n - 1 && tmp.y == n - 1) break;
            if (tmp.x - 1 >= 0 && !maze[tmp.x - 1][tmp.y]) {
                next.x = tmp.x - 1;
                next.y = tmp.y;
                next.step = tmp.step + 1;
                q.push(next);
                maze[tmp.x - 1][tmp.y] = 1;
            }
            if (tmp.y - 1 >= 0 && !maze[tmp.x][tmp.y-1]) {
                next.x = tmp.x;
                next.y = tmp.y-1;
                next.step = tmp.step + 1;
                q.push(next);
                maze[tmp.x][tmp.y-1] = 1;
            }
            if (tmp.x + 1 < n && !maze[tmp.x + 1][tmp.y]) {
                next.x = tmp.x + 1;
                next.y = tmp.y;
                next.step = tmp.step + 1;
                q.push(next);
                maze[tmp.x + 1][tmp.y] = 1;
            }
            if (tmp.y + 1 < n && !maze[tmp.x][tmp.y+1]) {
                next.x = tmp.x;
                next.y = tmp.y+1;
                next.step = tmp.step + 1;
                q.push(next);
                maze[tmp.x][tmp.y+1] = 1;
            }
            q.pop();
        }
        if (tmp.x == n - 1 && tmp.y == n - 1) cout << q.front().step << endl;
        else cout << "0" << endl;
    }
}                                 

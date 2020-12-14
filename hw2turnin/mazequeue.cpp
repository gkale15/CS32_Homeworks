#include <iostream>
#include <queue>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};



bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    queue<Coord> coordQueue;
    coordQueue.push(Coord(sr,sc));
    maze[sr][sc] = '#';

    while (!coordQueue.empty()) {
        Coord curr = coordQueue.front();
        coordQueue.pop();
        if (curr.r() == er && curr.c() == ec) {
            return true;
        }
        if (maze[curr.r()][curr.c()+1] == '.')  {
            coordQueue.push(Coord(curr.r(),curr.c()+1));
            maze[curr.r()][curr.c()+1] = '#';
        }
        if (maze[curr.r()+1][curr.c()] == '.')  {
            coordQueue.push(Coord(curr.r()+1,curr.c()));
            maze[curr.r()+1][curr.c()] = '#';
        }
        if (maze[curr.r()][curr.c()-1] == '.')  {
            coordQueue.push(Coord(curr.r(),curr.c()-1));
            maze[curr.r()][curr.c()-1] = '#';
        }
        if (maze[curr.r()-1][curr.c()] == '.')  {
            coordQueue.push(Coord(curr.r()-1,curr.c()));
            maze[curr.r()-1][curr.c()] = '#';
        }
    }

    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X...X..X.X",
        "X.XXX....X",
        "X.X.XXXX.X",
        "XXX......X",
        "X...X.XX.X",
        "X.X.X..X.X",
        "X.XXXX.X.X",
        "X..X...X.X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10,10, 4,3, 1,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}



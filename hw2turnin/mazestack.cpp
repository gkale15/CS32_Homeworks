#include <iostream>
#include <stack>
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
    stack<Coord> coordStack;
    //Push the starting coordinate (sr,sc) onto the coordinate stack and
    //update maze[sr][sc] to indicate that the algorithm has encountered
    //it (i.e., set maze[sr][sc] to have a value other than '.').
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '#';

    //While the stack is not empty,
    while (!coordStack.empty()) {
        //Pop the top coordinate off the stack. This gives you the current
        //(r,c) location that your algorithm is exploring.
        Coord curr = coordStack.top();
        coordStack.pop();
        if (curr.r() == er && curr.c() == ec) {
            return true;
        }
        if (maze[curr.r()][curr.c()+1] == '.')  {
            coordStack.push(Coord(curr.r(),curr.c()+1));
            maze[curr.r()][curr.c()+1] = '#';
        }
        if (maze[curr.r()+1][curr.c()] == '.')  {
            coordStack.push(Coord(curr.r()+1,curr.c()));
            maze[curr.r()+1][curr.c()] = '#';
        }
        if (maze[curr.r()][curr.c()-1] == '.')  {
            coordStack.push(Coord(curr.r(),curr.c()-1));
            maze[curr.r()][curr.c()-1] = '#';
        }
        if (maze[curr.r()-1][curr.c()] == '.')  {
            coordStack.push(Coord(curr.r()-1,curr.c()));
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




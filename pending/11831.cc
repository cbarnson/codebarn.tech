// Problem    : UVa 11831 - Sticker Collector Robot
// Time limit : 1.000 second
// Difficulty : 3
// Author     : Cody Barnson
// Date       : Feb. 3, 2018
#include <bits/stdc++.h>
using namespace std;

const int N = 100, M = 100, S = 5e4;

int n, m, s;
int dir[] = { 0, 1, 2, 3 }; // N, E, S, W
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
string s_dir = "NLSO";

struct state {
   state(int rr, int cc, int dd) : r(rr), c(cc), d(dd) {}
   int r, c, d;
};

state curr(0, 0, 0);
int stars = 0;
bool open[N][M];
bool star[N][M];

void init() {
   for (int i = 0; i < N; i++) {
      fill(open[i], open[i]+M, true);
      fill(star[i], star[i]+M, false);
   }
   stars = 0;
}

void check(int r, int c, char ch) {
   if (ch == '*') {
      star[r][c] = true;
   } else if (ch == '#') {
      open[r][c] = false;
   } else if (ch == '.') {
      return;
   } else {
      size_t f = s_dir.find(ch);
      if (f == string::npos)
	 exit(1);
      curr.r = r;
      curr.c = c;
      curr.d = (int)f;
   }
}

int main() {
   
   while (cin >> n >> m >> s >> ws) {

      // set all spaces to open and not starred
      init();
      
      if (cin.peek() == EOF) {
	 break;
      }

      for (int i = 0; i < n; i++) {
	 for (int j = 0; j < m; j++) {
	    char c;
	    cin.get(c);
	    check(i, j, c);
	 }
	 cin >> ws;
      }

      string cmds;
      getline(cin, cmds);

      int len = cmds.length();
      for (int i = 0; i < len; i++) {

	 if (cmds[i] == 'D') {
	    curr.d = (curr.d + 1) % 4;
	 } else if (cmds[i] == 'E') {
	    curr.d = (curr.d + (4 - 1)) % 4;
	 } else {
	    int nr = curr.r + dr[curr.d];
	    int nc = curr.c + dc[curr.d];
	    if (nr < 0 || nc < 0 || nr >= n || nc >= m || !open[nr][nc]) {
	       continue;
	    } else {
	       curr.r = nr, curr.c = nc;
	       if (star[nr][nc]) {
		  star[nr][nc] = false;
		  stars++;
	       }
	    }
	 }
      }
      cout << stars << endl;
   }
   
   return 0;
}

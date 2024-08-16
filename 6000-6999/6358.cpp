#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

int read() {
  int ans = 0, c;
  while (!isdigit(c = getchar()));
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans;
}

typedef unsigned long long ULL;

struct Msg {
  ULL sumX, sumY, sumXY, sumS;
  Msg() : sumX(0), sumY(0), sumXY(0), sumS(0) {}
  Msg(ULL sx, ULL sy, ULL sxy, ULL sb) : sumX(sx), sumY(sy), sumXY(sxy), sumS(sb) {}
  inline Msg operator+(const Msg &t) const {
    return Msg(sumX + t.sumX, sumY + t.sumY, sumXY + t.sumXY, sumS + t.sumS);
  }
};

struct Tag {
  // first add, then set
  ULL addX, addY, addXY, addC; // S += addX * X + addY * Y + addXY * XY + addC
  ULL setX, setY; // = 0: not set
  Tag() : addX(0), addY(0), addXY(0), addC(0), setX(0), setY(0) {}
  Tag(ULL ax, ULL ay, ULL axy, ULL ac, ULL sx, ULL sy)
    : addX(ax), addY(ay), addXY(axy), addC(ac), setX(sx), setY(sy) {}

  operator bool() const { return addX || addY || addXY || addC || setX || setY; } // check if tag is non trivial

  // tag1 * tag2: first apply tag2, then apply tag1
  inline Tag operator*(const Tag &t) const {
    ULL ax = t.addX, ay = t.addY, axy = t.addXY, ac = t.addC;
    ULL sx = t.setX, sy = t.setY;

    if (sx) {
      ac += addX * sx;
      if (sy) {
        ac += addXY * sx * sy;
      } else {
        ay += addXY * sx;
      }
    } else {
      ax += addX;
      if (sy) {
        ax += addXY * sy;
      } else {
        axy += addXY;
      }
    }

    if (sy) {
      ac += addY * sy;
    } else {
      ay += addY;
    }

    ac += addC;

    if (setX) sx = setX;
    if (setY) sy = setY;

    return Tag(ax, ay, axy, ac, sx, sy);
  }

  inline Msg apply(const Msg &m, ULL len) const { // len: length of range
    return Msg(/* sumX  */ setX ? setX * len : m.sumX,
               /* sumY  */ setY ? setY * len : m.sumY,
               /* sumXY */ setX ? (setY ? setX * setY * len : setX * m.sumY) : (setY ? m.sumX * setY : m.sumXY),
               /* sumS  */ m.sumS + addX * m.sumX + addY * m.sumY + addXY * m.sumXY + addC * len);
  }
};

const int N = 250050;
const int NN = 550000;

Tag tag[NN];
Msg msg[NN];

inline void upd(int o, int l, int r) {
  msg[o] = tag[o].apply(msg[o << 1] + msg[o << 1 | 1], r - l + 1);
}

inline void app(int o, int l, int r, const Tag &t) {
  tag[o] = t * tag[o];
  msg[o] = t.apply(msg[o], r - l + 1);
}

inline void pushd(int o, int l, int r) {
  if (tag[o]) {
    int m = (l + r) / 2;
    app(o << 1, l, m, tag[o]);
    app(o << 1 | 1, m + 1, r, tag[o]);
    tag[o] = Tag();
  }
}

void Modify(int o, int l, int r, int L, int R, const Tag &t) {
  if (L <= l && r <= R) {
    app(o, l, r, t);
    return;
  }
  pushd(o, l, r);
  int m = (l + r) / 2;
  if (L <= m) Modify(o << 1, l, m, L, R, t);
  if (R > m) Modify(o << 1 | 1, m + 1, r, L, R, t);
  upd(o, l, r);
}

ULL QueryS(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return msg[o].sumS;
  pushd(o, l, r);
  int m = (l + r) / 2;
  ULL ans = 0;
  if (L <= m) ans += QueryS(o << 1, l, m, L, R);
  if (R > m) ans += QueryS(o << 1 | 1, m + 1, r, L, R);
  return ans;
}

struct Qry {
  int l, r, id;
  bool operator <(const Qry &t) const {
    return r < t.r;
  }
} Q[N];

int n, m, A[N], B[N];
int sA[N], sB[N];
ULL ans[N];

int main() {
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  read();
  n = read();
  for (int i = 1; i <= n; ++i) A[i] = read();
  for (int i = 1; i <= n; ++i) B[i] = read();
  // Init(1, 1, n);
  m = read();
  for (int i = 0; i < m; ++i) {
    Q[i].l = read();
    Q[i].r = read();
    Q[i].id = i;
  }
  std::sort(Q, Q + m);
  int lA = 0, lB = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (lA && A[sA[lA]] < A[i]) --lA;
    while (lB && B[sB[lB]] < B[i]) --lB;
    Modify(1, 1, n, sA[lA] + 1, i, Tag(0, 0, 0, 0, A[i], 0)); // set X
    Modify(1, 1, n, sB[lB] + 1, i, Tag(0, 0, 0, 0, 0, B[i])); // set Y
    Modify(1, 1, n, 1, i, Tag(0, 0, 1, 0, 0, 0)); // S += X * Y
    sA[++lA] = sB[++lB] = i;
    for (; j < m && Q[j].r == i; ++j)
      ans[Q[j].id] = QueryS(1, 1, n, Q[j].l, i);
  }
  for (int i = 0; i < m; ++i)
    printf("%llu\n", ans[i]);
}

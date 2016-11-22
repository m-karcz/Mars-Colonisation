

struct Node{ //polaczenie
  int cost; //koszt polaczenia do xy
  int x;
  int y;
};

struct Point{ //punkt na mapie
  bool visited; //czy byl odwiedzony dla algorytmu
  long cost=INT_MAX; //koszt sumaryczny
  vector<Node> nodes; //talbica dostepnych punktow
};

struct Graph{ //graf
  vector<vector<Point>> points;
  get_transposed();
};


struct Base{ //baza
  int x;
  int y;
};

struct Bases{
  long achievable_points=0;
  vector<Base> bases;
}

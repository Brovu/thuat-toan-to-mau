#include <iostream>
#include <vector>
#include <iomanip>

const int oo = 999999;

#define X first
#define Y second

using namespace std;

vector <string> name;
vector <pair<int, int> > point;
vector <double> slope;
int n;

char sosanh(int a, int b)
{
  if(a == b) return '=';
  else if(a < b) return '<';
  else return '>';
}

int main()
{
  cout << "Nhap so dinh da giac: "; 
  cin >> n;
  cout << "Nhap toa do (ten dinh, x, y): ";

  for(int i = 0, x, y; i < n; ++i)
  {
    string ten;
    cin >> ten >> x >> y;
    name.push_back(ten);
    point.push_back({x, y});
  }
  int ymin=oo, ymax=0;
  for(int i = 0, x1, y1, x2, y2; i < n; ++i)
  {
    x1=point[i].X;
    x2=point[(i+1)%n].X;
    y1=point[i].Y;
    y2=point[(i+1)%n].Y;
    if(ymin > y1) ymin = y1;
    if(ymax < y1) ymax = y1;
    if(y1==y2){
      slope.push_back(1);
    }
    else if(x1 == x2)
    {
      slope.push_back(0);
    }
    else slope.push_back(1.0*(x2-x1)/(y2-y1));
  }
  cout << "He so goc: \n";
  for(int i = 0; i < n; ++i)
  {
    cout << name[i] << name[(i+1)%n] << ' ' << slope[i] << '\n';
  }
  for(int y = ymin; y <= ymax; ++y)
  {
    cout << "y = " << y << '\n';
    for(int i = 0, x1, y1; i < n; ++i)
    {
      cout << "Xet " << name[i] << name[(i+1)%n] << ' ';
      cout << "y" << name[i] << sosanh(point[i].Y, y) << y << " va " << "y" <<name[(i+1)%n] << sosanh(point[(i+1)%n].Y, y) << y << ' ';
      if(min(point[i].Y, point[(i+1)%n].Y) <= y && y <= max(point[i].Y, point[(i+1)%n].Y))
      {
        x1=point[i].X;
        y1=point[i].Y;
        double gd;
        gd = 1.0*x1 + 1.0*(y-y1)*slope[i];
        cout << "x" << name[i] << "+" << "m" << name[i] << name[(i+1)%n] << "(y-y"  << name[i] << ")="
        << x1 << "+" << slope[i] << "(" << y << "-" << y1 << ")="
        << gd;
      }
      else{
        cout << "Khong co giao diem";
      }
      cout << '\n';
    }
  }
  cout << ymax;
  cout << '\n';
  return 0;
}

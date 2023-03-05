#include <iostream>

using namespace std;

class Zanpakto
{
public:
  void shikai();
  void bankai();
};

void Zanpakto::bankai()
{
  cout << "BANKAI" << endl;
}
void Zanpakto::shikai()
{
  cout << "SHIKAI" << endl;
}

int main()
{

  Zanpakto *z;
  z = new Zanpakto();
  (*z).bankai();
  return 0;
}
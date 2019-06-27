#include "recorder.hpp"

#include <fstream>
#include <iostream>

void rename_script(std::string in_name, std::string out_name)
{
    // std::rename("recorded.m", "ja.m");
    std::ifstream in(in_name+".m");
    std::ofstream out(out_name+".m");
    std::string v1, v2;
    in >> v1 >> v2;
    v2 = "[y,a]="+out_name+"(x)";
    out << v1 << " " << v2;
    out << in.rdbuf();
    out.close();
    in.close();

    std::remove(in_name.append(".m").c_str());
}


int main(){

  double p = 7;

  Recorder x;
  Recorder y;
  Recorder t;

  x <<= 2;
  y <<= 5.5;
  t <<= 6+1.0/3;

  std::cout << "t:" << t << std::endl;
  t = 5;
  std::cout << "t:" << t << std::endl;
  t = t+3;
  std::cout << "t:" << t << std::endl;

  std::cout << "x:" << x << std::endl;
  x = x+3;
  std::cout << "x:" << x << std::endl;
  x = x+3;
  std::cout << "x:" << x << std::endl;
  x = x+t;
  std::cout << "x:" << x << std::endl;

  t = x;
  std::cout << "t:" << t << std::endl;
  t = 99;
  std::cout << "t:" << t << std::endl;
  Recorder z = x+y;

  if (z>=20) {
    z = z+50;
  } else {
    z = z+3;
  }


  z = z*(x>=0);
  z = sin(z);
  std::cout << "z:" << z << std::endl;

  double znum;
  z >>= znum;

  Recorder::stop_recording();

  std::cout << znum << std::endl;

  rename_script("recorded", "dyn");

  return 0;
}

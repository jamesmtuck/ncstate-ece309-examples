#include <iostream>
#include <string>

class Report {
  std::string s;
public:
  Report(std::string a_s = "")
  {
    s = a_s;

    std::cout << "Constructed " << s << "\n";
  }

  ~Report() {
    std::cout << "Destructed " << s << "\n";
  }
};

Report r_global("in the global data section.");

int main()
{
  std::cout << "main starts!\n";
  Report rs("on the stack.");

  Report *rh = new Report("on the heap.");

  Report rs2("another one on the stack.");

  delete rh;
  
  // rs.~Report() and rs2.~Report() are being called
  // the compiler does it for us!
  std::cout << "main ends!\n";
  return 0;
}

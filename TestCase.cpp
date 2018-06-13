#include "TestCase.hpp"
using namespace std;

TestCase& TestCase::print(){
os_err << nameCheck << ": " << fails << " failed, " << success << " passed, " << fails+success <<" total."<< endl;
os_err<<"---"<<endl;
return (*this);
}


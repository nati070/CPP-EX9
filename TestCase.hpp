
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TestCase{
    

    string nameCheck;
    ostream& os_err;
    int success = 0;
    int fails = 0;
 
    //constractur
    TestCase(string nameCheck , ostream& os) 
    : nameCheck(nameCheck),os_err(os){}

    // check  if tow object the same
    template<typename T>
    TestCase& check_equal(T a , T b){
        if(a == b){
        success++;
    }
    else{
        fails++;
        cout<< nameCheck << ": Failure in test #" << success + fails << ": " << a << " should equal " << b << "!" << endl;
    }  
    
    return (*this);
}

    // check  if tow object are different from each other
    template<typename T>
    TestCase& check_different(T a , T b){
    if(a != b){
        success++;
    }
    else{
        fails++;
       	cout<< nameCheck  <<": Failure in test #"<< success + fails<<": "<< a << " should differ than " << b <<"!" << endl;
    }
    
    return (*this);
}
    template< typename F , typename S1 ,typename S2 >
    TestCase& check_function(F f , S1 a , S2 b){
    if(f(a) == b){
        success++;
    }
    else{
        fails++;
        	cout<< nameCheck <<": Failure in test #"<< success + fails<<": Function should return "<< b <<" but returned "<< f(a) << "!" <<endl;
    }

    return (*this);
    }

    //check if the output identical to the template object;
    template<typename T >
    TestCase& check_output(T a , string s ){
    std::stringstream ss;
    ss << a;
    std::string stra = ss.str();
    if(stra.compare(s) == 0){
        success++;
    }
    else{
      fails++;
      cout<< nameCheck <<": Failure in test #"<< success + fails <<": string value should be "<< s <<" but is "<< stra << endl;
    }
    
    return (*this);
    }
    TestCase& print();  // declertion on function print
 
};



    

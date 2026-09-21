#include<vector>
#include<iostream>
#include<string>
using namespace std;
namespace std__{
    class complex{
        public:
            inline static int x=85;
        public:
            class innerClass{
                private:
                    std::string obj_name = "KundanMaurya";
                public:
                    inline static int k = 10;
                    std::string print_name(){
                        return obj_name;
                    }
                    friend std::string getName(std__::complex::innerClass &obj);

            };
    };

}

class frnd{
    private:
        int l = 40;
    public:
        friend int temp(frnd &obj);

};
int temp(frnd &obj){
    return obj.l;
}



std::string getName(std__::complex::innerClass &xl){
    // return xl.obj_name;
    return "Hi";
}
std::vector<int>vc;

int main(){
    
    vc.push_back(10);
    std::cout<<vc.at(0);
    std::cout << std::endl;
    std::cout << std__::complex::x;
    std__::complex::x = 40;
    std::cout<<std::endl;

    std::cout<<std__::complex::innerClass::k<<std::endl;

    //creating innerClass object and access private data members
    std__::complex::innerClass obj;
    std::cout<<obj.print_name() <<std::endl;
    //creating friend function 
    // std::cout<<getName(obj);

    frnd fr;
    cout << temp(fr);

    std::cout<<std::endl;
    return 0;
}


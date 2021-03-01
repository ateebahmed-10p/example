#include <iostream>
using namespace std;


class Cust
{
    private :
    public:
        const std::string& first;
        const std::string& last;
        int id;
        Cust(const std::string& f, const std::string& l , int i = 0) :
         first(f) , last(l) , id(i)
         {
         }

};

int main(){

    std::string f("some");
    std::string l("Ateeb");

    Cust c(f , l , 0);
    f[0] = 'a';
    cout << f << " " << l << endl;
    cout << c.first << endl;
    return 0;
}








#include <iostream>
using namespace std;

class Operations{
    private:
        bool x;
        bool y;
    public:
        Operations(){
            x=true;
            y=true;
        }
        Operations(bool value1, bool value2){
            x=value1;
            y=value2;
        }
        void conjunction(){
            cout << "Conjunction of x and y is : " << (x&&y) << endl;
            return;
        }
        void disjunction(){
            cout << "Disjunction of x and y is : " << (x||y) << endl;
            return;
        }
        void exclusiveor(){
            cout << "Exclusive-Or of x and y is : " << (x^y) << endl;
            return;
        }
        void conditional(){
            cout << "Conditional of x and y is : " << ( (!x)||(y) ) << endl;
            return;
        }
        void biconditional(){
            cout << "Bi-Conditional of x and y is : " << ( !(x^y) ) << endl;
            return;
        }
        void exclusivenor(){
            cout << "Exclusive-Nor of x and y is : " << ( !(x^y) ) << endl;
            return;
        }
        void negation(){
            cout << "Negation of x : " << (!x) << endl;
            cout << "Negation of y : " << (!y) << endl;
            return;
        }
        void nand(){
            cout << "Nand of x and y is : " << ( !(x&&y) ) << endl;
            return;
        }
        void nor(){
            cout << "Nand of x and y is : " << ( !(x||y) ) << endl;
            return;
        }
        void get(){
            cout << "Enter value of x : ";
            cin >> x;
            cout << "Enter value of y : ";
            cin >> y;
            return;
        }   
        
};

int main(){
    Operations a;
    a.get();
    cout<<endl;
    a.conjunction();
    a.disjunction();
    a.exclusiveor();
    a.conditional();
    a.biconditional();
    a.exclusivenor();
    a.negation();
    a.nand();
    a.nor();
    
    return 0;
}
#include <iostream>
using namespace std;

class Example1
{
	protected:
		int a;
		const static int b =30 ;
    public:
        friend void setval(Example1);
        int c ;
};
void setval(Example1 ex)
{

    ex.b++;
    cout<<ex.b;
}
class Example2:public Example1
{
	public:
		void init_a(int a)
		{
			this->a=a;
		}
		void print_a()
		{
			cout<<"a: "<<a<<endl;
			cout<<"b: "<<b<<endl;
			cout<<"c: "<<c<<endl;
		}
};

int main()
{
	//derived class object
	Example1 ex2 ;
	setval(ex2);
	//ex2.b =10 ;
	Example2 Ex;
	Ex.init_a(100);
	Ex.c = 20 ;
	Ex.print_a();

	return 0;
}


 #include "std_lib_facilities.h"

	class B1{
		public:
		virtual void vf() const {cout<< "B1::vf()"<<endl;}
		void f() const {cout << "B1::f()"<<endl;}
		virtual void pvf() =0;
	};
	
	
	class D1 : public B1{
		public:
		void vf() const override {cout<<"D1::vf()"<<endl;}
	};
	
	class B2{
		public: 
		virtual void pvf() = 0;
	};

	void f(B2& b) {b.pvf();}

	
	class D2 : public D1{
		public:
		void pvf() override {cout<<"D2::pvf()"<< endl;}
	};
		
		
	class D21 : public B2{
		string s = "hello world";
		public:
			void pvf() override { cout << s << endl; }
	};
		
	class D22 : public B2{
		int i=0;
		public:
		void pvf() override {cout << i << endl;}
	
	};
			
	
int main(){
	/*
	B1 asd;
	asd.vf();
	asd.f();

	D1 qwe;
	qwe.vf();
	qwe.f();
	
	B1& jkl = qwe;
	jkl.vf();
	jkl.f();
	*/
	
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	
	D21 d21;
	f(d21);
	
	D22 d22;
	f(d22);
	return 0;
}

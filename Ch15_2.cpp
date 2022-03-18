#include "std_lib_facilities.h"
	
	struct Person{
	   private:
		   string first_name;
		   string last_name;
		   int age;
	   public:
	   	   Person() {}
	   	   Person(string f, string l, int a);
	   	   string f_name() {return first_name;}
		   string l_name() {return last_name;}
		   int get_age() {return age;}
	};
		
	Person::Person(string f, string l, int a)
			: first_name{f}, last_name{l}, age{a} 
	{
		if (a < 0 || 150 < a) error("invalid age");
    
    string n = f + l;
    for (char c : n) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("bad char in names");
                break;
            default:
                break;
        }
    }
	}
		
	ostream& operator<<(ostream& os, Person& pp){
		return os<<pp.f_name()<<" "
				<<pp.l_name()<<" "
				<<pp.get_age()<<endl;
	}
	

	istream& operator>>(istream& is, Person& pp){
		int A;
		string F;
		string L;
		is >> F >> L >> A;
		pp= Person(F, L, A);

		return is;
	}	
	
	
	
	
	
int main()
try{
	/*
	Person asd_1;
	asd_1.set_name("Goofy");
	asd_1.set_age(63);

	cout << asd_1<< endl;
	cin>>asd_1;
	cout<<asd_1;
	*/

	Person qwe_1;
	vector<Person> men;

	cout<<"Please type firs, then last name, and age. "
	<<endl<<"For exit set firstname to exit"<< endl;

	while(cin >> qwe_1){
        if (qwe_1.f_name() == "exit") break;
        men.push_back(qwe_1);
    }
    cout<<"\nThe list of names and ages:\n";
    for (int i = 0; i < men.size(); i++){
        cout << men[i];
    }

	return 0;
}
catch(exception& e) {
	cerr << "Unknown error"<< endl;
	return 1;
}
catch (...) {
    cerr << "Unknown error!\n";
    return 2;
}
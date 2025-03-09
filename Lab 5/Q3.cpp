#include <iostream>
#include <string>
using namespace std;

class ValidateString{
	private:
		string word;
		
		
	public:
		ValidateString(string w): word(w){}
		
		void checkString() const{
			bool valid=true;
			for (int i=0;i<word.length();i++){
				if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))){
					valid = false;
				}
				
			}
			if(valid == true){
				cout<<"Valid string \n";
			}
			else cout<<"Invalid string \n";
		
		}	
};

int main(){
	ValidateString s1("Sameed"),s2("Hello123"),s3("#5Class");
	s1.checkString();
	s2.checkString();
	s3.checkString();
}

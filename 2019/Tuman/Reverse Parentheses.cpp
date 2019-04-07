#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string S;
	string Result = "";
	getline(cin, S);
	
	stack<char> Stck;
	int i = 0;
	while(i < (int)S.length()) {
		if(S[i] == '%' && i < ((int)S.length() - 2)) {
			if(S[i+1] == '2' && S[i+2] == '0') { // space
				if(!Stck.empty()) Stck.push(' ');
				else Result += ' ';
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == 'C') { // ,
				if(!Stck.empty()) Stck.push(',');
				else Result += ',';
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == '2') { // "
				if(!Stck.empty()) Stck.push((char)34);
				else Result += (char)34;  
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == '7') { // '
				if(!Stck.empty()) Stck.push((char)39);
				else Result += (char)39;
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == '1') { // !
				if(!Stck.empty()) Stck.push('!');
				else Result += '!';  
				i += 3;
			} else if(S[i+1] == '3' && S[i+2] == 'F') { // ?
				if(!Stck.empty()) Stck.push('?');
				else Result += '?';
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == '8') { // (
				Stck.push('(');
				i += 3;
			} else if(S[i+1] == '2' && S[i+2] == '9') { // )
				string TmpReverese = "";
				while(!Stck.empty() && Stck.top() != '(') {
					TmpReverese += Stck.top();
					Stck.pop();
				}
				if(Stck.top() == '(') {
					Stck.pop();
				}
				if(!Stck.empty()) {
					for(auto C : TmpReverese) {
						Stck.push(C);
					}
				} else {
					for(auto C : TmpReverese) {
						Result += C;
					}
				}
				
				i += 3;
			} else {
				//bukan unicode, bisa aja %%20 , yang artinya %(spasi)
				if(!Stck.empty()) {
					Stck.push(S[i]);
				} else {
					Result += S[i];
				}
				i++;
			}
		} else {
			if(!Stck.empty()) {
				Stck.push(S[i]);
			} else {
				Result += S[i];
			}
			i++;
		}
	}
	cout << Result << endl;
	
	return 0;
}
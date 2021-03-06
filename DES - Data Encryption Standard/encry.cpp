#include "uni.h"
string encrypt(string pt){
	string pt_bits=hexToBin(pt);
	/*for(int i=0;i<pt_bits.length();i+=64){}*/
	string ip=pt_bits;
	for(int i=0;i<64;i++)
		ip[i]=pt_bits[ip_arr[i]-1];
	cout<<"ip: "<<ip<<endl;
	string l[17],r[17];
	l[0]=ip.substr(0,32);
	r[0]=ip.substr(32,32);
	for(int i=1;i<=16;i++){
		l[i]=r[i-1];
		r[i]=_xor(l[i-1],_f(r[i-1],roundKeys[i-1]) );
	}
	string ans=r[16]+l[16];
	string ans_final_perm=string(64,' ');
	for(int i=0;i<64;i++) ans_final_perm[i]=ans[ip_inv_arr[i]-1];
	return ans_final_perm;
}
int main(){
    string key,pt;
	key="133457799BBCDFF1";//cin>>key;
	keyGenerate(key);
	pt="0123456789ABCCEF";//cin>>pt;
	if(pt.length()%16!=0){
		int i=pt.length()%16;
		while(i--){
			pt+='\0';
		}
	}
	string ee=encrypt(pt);
	cout<<"ee: "<<ee<<endl;
	cout<<"ee in hex: "<<binToHex(ee)<<endl;
    return 0;
}
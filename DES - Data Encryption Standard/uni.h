//#include <bits/stdc++.h>
#include "sboxes.h"
using namespace std;
int pc1[56]={57   ,49,    41,   33 ,   25 ,   17 ,   9,
               1 ,  58 ,   50,   42 ,   34,    26,   18,
              10   , 2,    59,   51,    43 ,   35 ,  27,
              19,   11 ,    3 ,  60 ,   52  ,  44  , 36,
              63 ,  55  ,  47  , 39  ,  31   , 23   ,15,
               7  , 62   , 54   ,46   , 38    ,30,   22,
              14   , 6    ,61 ,  53    ,45  ,  37 ,  29,
              21  , 13     ,5  , 28    ,20   , 12  ,  4};
int pc2[48]={14  ,  17,   11,    24,     1,    5,
             3 ,   28  , 15  ,   6  ,  21  , 10,
            23  ,  19   ,12   ,  4   , 26   , 8,
            16   ,  7,   27    ,20    ,13,    2,
            41    ,52 ,  31,    37,    47 ,  55,
            30,    40  , 51 ,   45 ,   33  , 48,
            44 ,   49   ,39   , 56  ,  34   ,53,
            46  ,  42  , 50  ,  36   , 29,   32};
int p_arr[32]={16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2,
8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
int e_arr[48]={32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12,
13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
int ip_arr[64]={58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49,
41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37,
29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
int ip_inv_arr[64]={40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4,
44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10,
50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
string leftShifts="1122222212222221";
string roundKeys[16];//each key is of 48-bits
string reverse_str(string s){
	char c;
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		c=s[i];s[i]=s[j];s[j]=c;
	}
	return s;
}
string leftRotate(string s,int shift){
	string ans="";
	for(int i=0;i<s.length();i++)
		ans+=s[(i+shift)%s.length()];
	return ans;
}
string hexToBin(string k){
	string ans="";
	for(int i=0;i<k.length();i++){
		int a=(int)(k[i]-'0');
		if(k[i]>='A') a=(int)(k[i]-'A')+10;
		int itr=0;
		string t="";
		while(itr<4){
			t+=(a%2)?"1":"0";
			itr++;
			a=a/2;
		}
		ans+=reverse_str(t);
	}
	return ans;
}
int _pow(int a,int b){if(b==0) return 1;return a*pow(a,b-1);}
char getHexChar(int a){
	if(a==10) return 'A';
	if(a==11) return 'B';
	if(a==12) return 'C';
	if(a==13) return 'D';
	if(a==14) return 'E';
	return 'F';
}
string binToHex(string k){
	string ans="";
	for(int i=0;i<k.length();i+=4){
		string s=k.substr(i,4);
		int a=0;
		for(int i=0;i<4;i++) a+=(int)(s[i]-'0')*(_pow(2,3-i));
		//cout<<"a: "<<a<<endl;
		if(a>=10) {ans+=string(1,getHexChar(a));}
		else ans+=string(1,(char)(a+'0'));
	}
	return ans;
}
void keyGenerate(string key){
	string key_56="";
	string key_bits=hexToBin(key);
	/*cout<<"64bit key: ";
	for(int i=0;i<key_bits.length();i+=8)
		cout<<key_bits.substr(i,8)<<" ";
	cout<<endl;*/
	for(int i=0;i<56;i++)
		key_56+=string(1,key_bits[pc1[i]-1]);
	string c[17],d[17];
	c[0]=key_56.substr(0,28);
	d[0]=key_56.substr(28,28);
	//cout<<"c0: "<<c[0]<<endl;
	//cout<<"d0: "<<d[0]<<endl;
	for(int i=1;i<=16;i++){
		c[i]=leftRotate(c[i-1],leftShifts[i-1]-'0');
		d[i]=leftRotate(d[i-1],leftShifts[i-1]-'0');
		/*cout<<"i: "<<i<<" , c: "<<c[i]<<endl;
		cout<<"i: "<<i<<" , d: "<<d[i]<<endl;*/
		string ss=c[i]+d[i];
		roundKeys[i-1]=string(48,' ');
		for(int j=0;j<48;j++){
			roundKeys[i-1][j]=ss[pc2[j]-1];
		}
	}
	/*cout<<"roundKeys-\n";
	for(int i=0;i<16;i++){
		for(int j=0;j<roundKeys[i].length();j+=6) cout<<roundKeys[i].substr(j,6)<<" ";
		cout<<endl;
	}*/
}
string _xor(string a,string b){
	string res="";
	for(int i=0;i<a.length();i++){
		if(a[i]==b[i]) res+="0";
		else res+="1";
	}
	return res;
}
string decToBin(int n){
	string ans="";
	int itr=4;
	while(itr>0){
		ans+=(n%2==1)?"1":"0";
		n=n/2;
		itr--;
	}
	return reverse_str(ans);
}
string _f(string r,string roundKey){
	string ans="",xor_result="";
	string s_box_res="";
	string r_48=string(48,' ');
	for(int i=0;i<48;i++)
		r_48[i]=r[e_arr[i]-1];
	xor_result=_xor(r_48,roundKey);
	for(int i=0;i<48;i+=6){
		string s=xor_result.substr(i,6);
		int s_int[6];for(int i=0;i<6;i++) s_int[i]=(int)(s[i]-'0');
		int r=s_int[0]*2+s_int[5];
		int c=s_int[1]*8+s_int[2]*4+s_int[3]*2+s_int[4];
		s_box_res+=decToBin(s_boxes[i/6][r][c]);
	}
	string s_box_perm=string(32,' ');
	for(int i=0;i<32;i++){
		s_box_perm[i]=s_box_res[p_arr[i]-1];
	}
	return s_box_perm;
}
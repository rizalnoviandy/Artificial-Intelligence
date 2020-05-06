#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	cout<<"Rizal akan memberikan tips tambahan kepada pengebudi GO-JEK sebesar 0-20% dari pembayaran, dilihat dari :\n\t a. Pelayanan (0-10)\n\t b. Kecepatan (0-10)\n";
	float pel, kec, has;
	cout<<"Tips yang diterapkan :\n  -Jika Pelayanan JELEK atau Kecepatan PELAN, maka tipnya RENDAH\n  -Jika Pelayanan SEDANG, maka tipnya SEDANG\n  -Jika Pelayanan BAGUS atau Kecepatan CEPAT, maka tipnya TINGGI\n";
	cout<<"\n Masukkan penilaian anda terhadap Pelayanan :"; cin>>pel;
	cout<<"\n Masukkan penilaian anda terhadap Kecepatan :"; cin>>kec;
	cout<<"\n Didapatkan :\n\t a. Pelayanan ="<<pel<<"\n\t b. Kecepatan ="<<kec;
	cout<<"\n--------------------------------------------------------------------\n";
	float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
	cout<<"Masukkan titik-titik x untuk grafik pelayanan :";
	cin>>a>>b>>c>>d>>e>>f>>g;
	
	//Jelek
	float f1, f2, f3, f4, f5, f6, f7, f8, f9, fy1, fy2, fy3, fy4;
	//------fungsi pelayanan--------
	if(pel>=a && pel<=c){
		f1=(c-pel)/(c-a);
		cout<<"\n f-jelek ="<<f1;
	//}else{f1=0;
	}else{
			f1=0;
		};
	
	if(pel>=b && pel<=d){
		f2=(pel-b)/(d-b);
		cout<<"\n f-sedang ="<<f2;
	//}else{f2=0;
	}else{
			f2=0;
		};
	
	if(pel>d && pel<=f){
		f3=(f-pel)/(f-d);
		cout<<"\n f-sedang ="<<f3;
	//}else{f3=0;
	}else{
			f3=0;
		};
		
	if(pel>=e && pel<=g){
		f4=(pel-e)/(g-e);
		cout<<"\n f-bagus ="<<f4;
	}else{
			f4=0;
		};
	
	//------fungsi kecepatan-------
	cout<<"\n\n Masukkan titik-titik x untuk grafik kecepatan :";
	cin>>h>>i>>j>>k>>l>>m;
	if(kec>=h && kec<i){
		f5=1;
		cout<<"\n f-pelan ="<<f5;
	}else{
			f5=0;
		};	
	
	if(kec>=i && kec<=j){
		f6=(j-kec)/(j-i);
		cout<<"\n f-pelan ="<<f6;
	}else{
			f6=0;
		};
	
	if(kec>j && kec<k){
		f7=0;
		cout<<"\n f-pelan ="<<f7;
	}else{
			f7=0;
		};
	
	if(kec>=k && kec<=l){
		f8=(kec-k)/(l-k);
		cout<<"\n f-cepat ="<<f8;
	}else{
			f8=0;
		};
		
	if(kec>l && kec<=m){
		f9=1;
		cout<<"\n f-cepat ="<<f9;
	}else{
			f9=0;
		};	
	
//--------menerapkan operator fuzzy ke pers tips------
float a1, a2, a3;
a1=max(max(f5,f6),f1);
a2=max(f2,f3);
a3=max(max(f8,f9),f4);

//cout<<"hasil max :"<<a1<<" "<<a2<<" "<<a3;

//--------menerapkan fungsi implikasi---------

cout<<"\n\n Masukkan titik-titik x untuk grafik hasil :";
	cin>>n>>o>>p>>q>>r;
	
	fy1=o-a1*(o-n);//fungsi murah
	fy2=a2*(p-o)+o;//fungsi biasa
	fy3=q-a2*(q-p);//fungsi biasa
	fy4=a3*(r-q)+q;//fungsi mahal
	
float t1, t2, t3, t4, ar1, ar2, ar3, ar4;

	t1=0.5*(o-n)+n;
	t2=0.5*(p-o)+o;
	t3=0.5*(q-p)+p;
	t4=0.5*(r-q)+q;
	
	if(fy1>=n && fy1<o && a1>0){
		cout<<"\n has-murah x="<<fy1;
		ar1=(0.5*(o-n))-(0.5*(fy1-n)*(1-a1));
	}else{
			fy1=0;
			ar1=0;
		};	
	
	if(fy2>=o && fy2<=p && a2>0){
		cout<<"\n has-sedang x="<<fy2;
		ar2=(0.5*(p-o))-(0.5*(p-fy2)*(1-a2));
	}else{
			fy2=0;
			ar2=0;
		};
	
	if(fy3>p && fy3<=q && a2>0){
		cout<<"\n has-sedang x="<<fy3;
		ar3=(0.5*(q-p))-(0.5*(fy3-p)*(1-a2));
	}else{
			fy3=0;
			ar3=0;
		};
	
	if(fy4>q && fy4<=r && a3>0){
		cout<<"\n has-mahal x="<<fy4;
		ar4=(0.5*(r-q))-(0.5*(r-fy4)*(1-a3));
	}else{
			fy4=0;
			ar4=0;
		};
		
		
//------DEfuzzyfikasi--------
float z;

z=(ar1*t1+ar2*t2+ar3*t3+ar4*t4)/(ar1+ar2+ar3+ar4);

//cout<<"Luas area :"<<ar1<<" "<<ar2<<" "<<ar3<<" "<<ar4;
//cout<<"Titik :"<<t1<<" "<<t2<<" "<<t3<<" "<<t4;

cout<<"\n\n ---------------------------------- \n Hasilnya adalah :"<<z;
cout<<"\n >>Sehingga tips tambahan yang perlu Rizal berikan adalah "<<z<<"%";

		

	//cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4;
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g;
	
	
	return 0;
}

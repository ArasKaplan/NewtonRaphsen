#include<stdio.h>
#include<math.h>
#include <cstdlib>

double Fonksiyon_deger_bul(double x,double fonksiyon[100],int n){
	int i;
	int j;
	double deger;
	deger=0;
	double z;
	for(i=0;i<=n;i++){
		z=1;
		for(j=0;j<i;j++){
			z=z*x;
		}
		deger=deger+z*fonksiyon[i];
	}
	return deger;
}

double Turev_deger_bul(double x,int fonksiyon[100],int n){
	int i,j;
	double deger;
	deger=0;
	double z;
	for(i=0;i<=n;i++){
		z=1;
		for(j=0;j<i-1;j++){
			z=z*x;
		}
		deger=deger+z*fonksiyon[i]*i;
	}
	return deger;
}
int main(){
	double x;
	int derece;
	double fonksiyon[100];
	double c;
	double epsilon;
	printf("X degeri giriniz");
	scanf("%lf",&x);
	printf("epsilon giriniz");
	scanf("%lf",&epsilon);
	double fx;
	double x1;
	double fdx;
	printf("Fonksiyon derece giriniz");
	scanf("%d",&derece);
	int i;
	for(i=0;i<=derece;i++){
		printf("%d nc, dereceden elemanin katsayisi",i);
		scanf("%d",&fonksiyon[i]);
	}
	double a;
	a=5;
	while(epsilon<(a)){
		fx=Fonksiyon_deger_bul(x,fonksiyon,derece);
		fdx=Turev_deger_bul(x,fonksiyon,derece);
		x1=x-(fx/fdx);
		a=fabs(fabs(x1)-fabs(x));
		x=x1;
	}
printf("Kok=%lf",x);

system("pause");

return 0;
}

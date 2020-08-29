//SEFA ENES ERGİN-sefaenesergin@gmail.com
//Noktalar arası mesafe bulan esnek argümanlı fonksiyon
#include <stdio.h>
#include <math.h>
#include <stdarg.h> //va_ ile ilgili fonksiyonların çalışması için gereken kütüphane.
void mesafeler(int n,...){//geriye bir şey döndürmüyor.
    int noktalar[100][2];//100 nokta,her noktanın 2 koordinatı var.
    va_list liste;  //listeyi tanımladık.
    va_start(liste,n); //listeyi kullanıma hazır hale getirdik.
    for (int i=0; i<n; i++) {
        noktalar[i][0]=va_arg(liste,int); //x koordinatı atadık.
        noktalar[i][1]=va_arg(liste,int); //y koordinatı atadık.
    }
    va_end(liste); // sonlandırdık.
    float mes;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            mes=sqrt(   pow((noktalar[i][0]-noktalar[j][0]),2.0)   + pow((noktalar[i][1]-noktalar[j][1]),2.0) );
            printf(".%d ile .%d arasındaki mesafe : %f \n ",i+1,j+1,mes);
        }
    }
}
int main(int argc, const char * argv[]) {
    mesafeler(2,5,8,-4,9);//ilk yazılan 2 rakamı , 2 tane nokta koyacağımızı belirtiyor.
    // ikinci yazılan 5 ise ilk noktanın x koordinatını, 8 ise y koordinatını belirtiyor.
    return 0;
}

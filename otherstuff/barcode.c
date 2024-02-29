#include <stdio.h>

int barcodeDigit(int barcode) {
    int sumODD ,sumEven,M=0; 
    for (int i =0; i<11; i++){
        int barcodetemp = barcode;
        if (i %2!=0 || i==0){
            int temp = barcodetemp %10; 
            barcodetemp/=10;
            sumODD+=temp;
        }
    }
    M=sumODD*3; 
    for (int i =1;i<12;i++){
        int barcodetemp2 = barcode;
        if (i%2==0){
            int temp = barcode %10; 
            barcodetemp2/=10; 
            sumEven+=temp;
        }
    }
    M+=sumEven;
    M = M%10; 
    if (M==0){
        return 0;
    }else{
        return (10-M);
    }



}

int main(void){
    int num = barcodeDigit(03600029145);
}
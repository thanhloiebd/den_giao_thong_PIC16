#include <16f877a.h>
#use delay (clock=4000000)
#use fast_io(d)
#use fast_io(b)
#use fast_io(c)
#use fast_io(a)
#byte portd=0x08
#bit ra0=0x05.0 // Binh thuong
#bit ra1=0x05.1 // Gio cao diem
#bit ra2=0x05.2 // Ban dem
#bit ra3=0x05.3 // nut manual
#bit rb0=0x06.0 // led1
#bit rb1=0x06.1 // led2
#bit rb2=0x06.2 // led3
#bit rb3=0x06.3 // led4
#bit rc0=0x07.0 // x1
#bit rc1=0x07.1 // v1
#bit rc2=0x07.2 // d1
#bit rc3=0x07.3 // x2
#bit rc4=0x07.4 // v2
#bit rc5=0x07.5 // d2
#define bat 1
#define tat 0
//--------------------------------
int m[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int num1,donvi1,chuc1;
int num2,donvi2,chuc2;     


int status = 0; // trang thai cho che do nut ra: den xanh den do
void delay(int ms)
 {
  int a,b;
  for(a=0;a<ms;a++)
   for(b=0;b<50;b++)
    {
    }
 }
//!//-------------hien thi---------------------
void ht1(void)
 {
  int c;
  for(c=0;c<50;c++)
   {
   chuc1=num1/10;
   donvi1=num1%10;
   output_d(m[chuc1]);
   rb2=bat;
   delay(10);
   rb2=tat;
   output_d(m[donvi1]);
   rb3=bat;
   delay(10);
   rb3=tat;
   chuc2=num2/10;
   donvi2=num2%10;
   output_d(m[chuc2]);
   rb0=bat;
   delay(10);
   rb0=tat;
   output_d(m[donvi2]);
   rb1=bat;
   delay(10);
   rb1=tat;
   }
 }

//------------------Che do ra3------------------
void ra3_mode() {
    if (!ra3) {
        delay_ms(1000); // Loc nhieu nut nhan
        while (!ra3);  // doi nut nhan
        status = !status; // chuyen doi trang thai giua xanh 2 do 1 và xanh 1 do 2

        if (status == 0) { /// che do xanh 1 do 2
            delay_ms(500);
            rc0 = bat; // Xanh 1
            rc5 = bat; // do 2
            rc3 = tat; // Xanh 2 t?t
            rc4 = tat;
            rc1= tat;
            rc2= tat;
        } else { /// che do xanh 2 do 1
            
            delay_ms(500);
            rc3 = bat; // Xanh 2
            rc2 = bat; // Ð? 1
            rc0 = tat; // Xanh 1 t?t
            rc5 = tat;
            rc1=tat;
            rc4= tat;   
        }
    }
}

void main(void) {
    set_tris_d(0x00);
    set_tris_b(0xff);
    set_tris_c(0x00);
    set_tris_a(0xff);
    output_d(0xFF);
    rc0 = tat;
    rc5 = tat;
    rc1 = tat;
    rc2 = tat;
    rc3 = tat;
    rc4 = tat;

    while (true) {
        ///--------------che do binh thuong -----------------
        if (!ra0) {
            delay_ms(100);
            while (!ra0) {
                binhthuong:  
                num1 = 35; // tru 1
                num2 = 30; // tru 2
                do { 
                    set_tris_b(0x00); // turn 1 :do1 xanh 2
                    rc0 = tat; //x1
                    rc5 = tat; //do2
                    rc1 = tat; //v1
                    rc2 = bat; // do1
                    rc3 = bat; //x2
                    rc4 = tat; //v2
                    ht1();
                    num1--;
                    num2--;
                } while (num2 != 0);
                num2 = num1 = 5;
                do {
                    set_tris_b(0x00);
                    rc1 = tat;
                    rc5 = tat;
                    rc0 = tat;
                    rc2 = bat; // do1
                    rc3 = tat;
                    rc4 = bat; //v2
                    ht1();
                    num1--;
                    num2--;
                } while (num2 != 0); //turn 2: xanh 1 do 2
                num1 = 30;
                num2 = 35;
                do {
                    set_tris_b(0x00);
                    rc2 = tat; 
                    rc3 = tat;
                    rc0 = bat; //xanh1
                    rc1 = tat;
                    rc4 = tat;
                    rc5 = bat; //do2
                    ht1();
                    num1--;
                    num2--;
                } while (num1 != 0);
                num1 = num2 = 5;
                do {
                    set_tris_b(0x00);
                    rc2 = tat;
                    rc4 = tat;
                    rc0 = tat;
                    rc1 = bat;
                    rc3 = tat;
                    rc5 = bat;
                    ht1();
                    num1--;
                    num2--;
                } while (num1 != 0);
                goto binhthuong;
            }
        }
        //---------------gio cao diemm--------------------------
        if (!ra1) {
            delay_ms(100);
            while (!ra1) {
                caodiem:
                num1 = 60;
                num2 = 55;
                do { 
                    set_tris_b(0x00);
                    rc0 = tat; //x1
                    rc5 = tat; //do2
                    rc1 = tat; //v1
                    rc2 = bat; // do1
                    rc3 = bat; //x2
                    rc4 = tat; //v2
                    ht1();
                    num1--;
                    num2--;
                } while (num2 != 0);
                num2 = num1 = 5; 
                do {
                    set_tris_b(0x00);
                     rc1 = tat;
                    rc5 = tat;
                    rc0 = tat;
                    rc2 = bat; // do1
                    rc3 = tat;
                    rc4 = bat; //v2
                    ht1();
                    num1--;
                    num2--;
                } while (num2 != 0);
                num1 = 55;
                num2 = 60;
                do {
                    set_tris_b(0x00);
                   rc2 = tat; 
                    rc3 = tat;
                    rc0 = bat; //xanh1
                    rc1 = tat;
                    rc4 = tat;
                    rc5 = bat; //do2
                    ht1();
                    num1--;
                    num2--;
                } while (num1 != 0);
                num1 = num2 = 5;
                do {
                    set_tris_b(0x00);
                     rc2 = tat;
                    rc4 = tat;
                    rc0 = tat;
                    rc1 = bat;
                    rc3 = tat;
                    rc5 = bat;
                    ht1();
                    num1--;
                    num2--;
                } while (num1 != 0);
                goto caodiem;
            }
        }

        //-------------------ban dêm---------------
        if (!ra2) {
            delay_ms(100);
            while (!ra2) {
                dem:
                delay_ms(500);
                rc4 = bat;
                rc1 = bat;
                rc0= tat;
                rc2= tat; 
                rc3= tat; 
                rc5= tat;
             
                delay_ms(1000);
                rc4 = tat;
                rc1 = tat;
                rc2= tat; 
                rc3= tat;
                rc0= tat;
                rc5= tat;
                delay_ms(500);
                goto dem;
            }
        }
        //------------------Ch? d? ra3------------------
        ra3_mode(); 
    }
}


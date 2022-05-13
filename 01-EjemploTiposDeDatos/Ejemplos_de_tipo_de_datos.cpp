//#include<iostream>
#include<cassert>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std::literals; //std::literals para poder usar la "s" de string//

int main(){
//  - Prueba de tipo de dato int -
    assert(-1);
    assert(2);
    assert(2 == 1+1);     //igualdad y  suma
    assert(0 == 1-1);       //igualdad y resto
    assert(5*5 == 25);      //multiplicacion e igualdad
    assert(20/4 == 5);      //divicion e igualdad
    assert(8 >= 4);         //mayo igual
    assert(10 <= 23);       //menor igual
    assert(20 >= 20);       //mayor igual
    assert(2 != 5);         //distinto
    assert(10%2 == 0);      //resto e igualdad
    assert(-65 <= -60);     //menor igual
//===========================================================================================================================================================================================//
//  - prueba de tipo de dato bool -
	assert(true);               
    assert(false==false);       //igualdad
    assert(true!=false);        //distinto
    assert(not false);          //negacion
    assert(not false==true);    //negacion e igualdad
    assert(false or true);      //diyuncion
    assert(true and true);      //conyuncion
    assert(false or true and false==false);     //diyuncion, conjuncion e igualdad
    assert((false or true) and false==false);   //diyuncion entre parentecis, conjuncion e igualdad
    assert(true or true and false);     //diyuncion y conjuncion
//===========================================================================================================================================================================================//
//  - prueba de tipo de dato double - 
    //no utilizar compraracion mediante igualdad con tipo double
    assert(2.0 == 1.0 + 1.0);   //igualdad y suma
    assert(1 == 1.0);           //igualdad
    assert(2.0 == 3 - 1.0);     //igualdad y resta
    assert(2 == 1 + 1.0);       //igualdad y suma
    assert(6.89 == 5.3 * 1.3);  //igualdad y multiplicacion
    assert(10 == 100 / 10.0);   //igualdad y divicion
    assert(6.9 < 7.3);          //menor a
    assert(100.94 >= 100.22);   //mayor igual a
    assert(0.0 == 1 - 1.0);   //igualdad y resta
    assert(0.1 == 1.0 / 10.0);  //igualdad y divicion
    assert(1.0 != 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1); //distinto y suma
//===========================================================================================================================================================================================//
//  - prueba de tipo de dato string - 
    assert("G"s != "g"s);
    assert("ezequiel"s == "ez"s + "equiel"s);
    assert("ezequiel"s.length() == 8); 
    assert("ddd"s >= "dd"s);
    assert("ddd"s <= "dde");
//===========================================================================================================================================================================================//
//  - prueba de tipo de dato char -
    assert('a');
    assert('B' == 66);      //igualdad
    assert('A' <= 'H');     //menor igual a
    assert('z' == 'z');     //igualdad
    assert('E' != 'e');     //distinto
    assert('A'*'E' == 4485);    //multiplicacion e igualdad
    assert('A'/'B' == 0);   //divicion e igualdad
    assert('e'-'d' == 1);   //resta e igualdad
    assert(5 != '10' + '5');    //distinto e igualdad
    assert(1 == 'B' % 'A');      //igualdad y resto
//===========================================================================================================================================================================================//
//  - Prueba de tipo de dato unsigne -
    //usamos "u" para uilizar valores no signados
    assert(1500u == 1500u);     //igualdad
    assert(200u >= 150u);       //mayor igual a
    assert(432u != 120);        //distinto
    assert(10u <= 32u);         //menor igual a 
    assert(100u == 45u + 55u);  //igualdad y suma
    assert(1u == 100u - 99u);   //igualdad y resta
    assert(36u == 4u * 9u);     //igualdad y multiplicacion
    assert(12u == 144u / 12u);  //igualdad y divicion
    assert(0u == 45u % 5u);     //igualdad y resto
    
    system("pause");
}





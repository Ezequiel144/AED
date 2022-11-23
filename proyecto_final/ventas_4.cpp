#include<iostream>
#include<fstream>
#include<array>
#include<vector>

using namespace std;

template<typename T>

std::ostream& writeblock(std::ostream& os,const T& block){

    return os.write(reinterpret_cast<const char*>(&block),sizeof(block));
}

// - Estrcuturas - //
struct Venta{
    unsigned mes, importe;
};
vector<Venta> ventasVendedor1;


// - Prototypos - //
void promedio(array<array<array<unsigned,12>,3>,4> total);
/*unsigned mayor(array<array<array<unsigned,12>,3>,4> total);*/
unsigned mayor(array<array<array<unsigned,12>,3>,4> total, array<unsigned,3> &lista);

int main(){
    array<string,3> vendedores{"vendedor 1","vendedor 2","vendedor 3"};
    array<array<array<unsigned,12>,3>,4> total{};
    
    fstream archivo;
    archivo.open("datos_entrada.txt",ios::in);
    if(archivo){
        cout<<"Leyendo archivo\n";
        for(unsigned vent,mes,reg,cant; archivo >> reg >> vent >> mes >> cant ;){
        total.at(reg-1).at(vent-1).at(mes-1) += cant;
        if(vent==1){
                ventasVendedor1.push_back({mes, cant});
            }
        }
    }

    ofstream out("ventas",std::ios::binary);
    ofstream outVend1("vendedor1", ios::binary);

    //Mostrando datos//
    for(int i=0; i<4 ; i++){
        cout<<"\n - Region "<<i+1<<" -\n";
        for(int j=0; j<3 ; j++){
            cout<<"\n"<<"Vendedor "<<j+1<<"\n\n";
            for(int k=0; k<12 ; k++){
                cout<<"mes "<<k+1<<"->cant: "<<total[i][j][k]<<"\n";
            }
        }
    }
    
    writeblock(out,total);
     for(auto i: ventasVendedor1)
        writeblock(outVend1, i);

    cout<<" \n- Promedio de vendedores - ";
    promedio(total);

    /*cout<<"\n\n- El vendedor con la mayor venta es "<<vendedores.at(mayor(total));*/

    // - otra manera del mayor - //

    cout<<"\n\n - cantidad de ventas por vendedor - ";
    array<unsigned,3> cantidades{};
    cout<<"\nEl Vendedor con la mayor venta es el "<<vendedores.at(mayor(total,cantidades));
    cout<<"\nvendedor  1 ---> cant: "<<cantidades[0];
    cout<<"\nvendedor  2 ---> cant: "<<cantidades[1];
    cout<<"\nvendedor  3 ---> cant: "<<cantidades[2];
}


void promedio(array<array<array<unsigned,12>,3>,4> total){
    //array<unsigned,3> promed{0,0,0};
    unsigned prom_ven_1{0};
    unsigned cont_1 = 0;
    unsigned prom_ven_2{0};
    unsigned cont_2 = 0;
    unsigned prom_ven_3{0};
    unsigned cont_3 = 0;
    for(unsigned i{0};i<4;i++){
        for(unsigned j{0};j<3;j++){
            for(unsigned k{0};k<12;k++){
                if(total[i][j][k] != 0 and total[i][j][k] == total[i][0][k]){
                    //promed.at(0) += total[i][j][k];
                    prom_ven_1 += total[i][j][k];
                    cont_1++;
                }
                else if(total[i][j][k] != 0 and total[i][j][k] == total[i][1][k]){
                    //promed.at(1) += total[i][j][k];
                    prom_ven_2 += total[i][j][k];
                    cont_2++;
                }
                else if(total[i][j][k] != 0 and total[i][j][k] == total[i][2][k]){
                    //promed.at(2) += total[i][j][k];
                    prom_ven_3 += total[i][j][k];
                    cont_3++;
                }
            }
        }
    }
    
    //cout<<"\nPromedio del vendedor 1: "<<(promed[0]/*/cont_1*/);
    //cout<<"\nPromedio del vendedor 2: "<<(promed[1]/*/cont_2*/);
    //cout<<"\nPromedio del vendedor 3: "<<(promed[2]/*/cont_3*/);
    
    
    cout<<"\nPromedio del vendedor 1: "<<prom_ven_1/cont_1;
    cout<<"\nPromedio del vendedor 2: "<<prom_ven_2/cont_2;
    cout<<"\nPromedio del vendedor 3: "<<prom_ven_3/cont_3;
}


unsigned mayor(array<array<array<unsigned,12>,3>,4> total, array<unsigned,3> &lista){
    
    unsigned cont_1 {0};
    unsigned cont_2 {0};
    unsigned cont_3 {0};
    for(unsigned i{0};i<4;i++){
        for(unsigned j{0};j<3;j++){
            for(unsigned k{0};k<12;k++){
                if(total[i][j][k] != 0 and total[i][j][k] == total[i][0][k]){
                    lista.at(0) += total[i][j][k];
                    cont_1++;
                }
                else if(total[i][j][k] != 0 and total[i][j][k] == total[i][1][k]){
                    lista.at(1) += total[i][j][k];
                    cont_2++;
                }
                else if(total[i][j][k] != 0 and total[i][j][k] == total[i][2][k]){
                    lista.at(2) += total[i][j][k];
                    cont_3++;
                }
            }
        }
    }

    unsigned aux{0};

    for(unsigned i{1};i<=2;i++){
       if (lista[i] > lista[aux]){
            aux=i;
       }
    }
    return aux;
} 

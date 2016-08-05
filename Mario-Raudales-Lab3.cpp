#include <iostream>
#include <string>

using namespace std;

char[] binarioadecimal(char[]);
char[] decimalabinario(char[]);
char[] suma(char[]);
void laberinto();

int main(){
	int menu;
	char resp;
	cout<<"Menu\nOpcion 1:Laberinto\nOpcion 2:Calculadora\nDigite su eleccion: ";
	do{
		switch(menu){
			case 1:
				laberinto();
				break;
			case 2:
				break;
			default:
				cout<<"Opcion no valida"
		}
		cout<<"Desea continuar";
		cin>>resp;
	}while(resp == 's' || resp == 'S');
}


void laberinto(){
	int tamano;
	cout <<"Ingrese el tamano del laberinto";
	cin>>tamano;
	if(tamano<10){
		cout<<"Tamano no valido";
	}else{
		char** matriz = new char*[tamano];
		for(int i = 0;i<tamano;i++){
			matriz[i] = new char[tamano];
		}
		string fila;
		int contadorentrada = 0,contadorsalida = 0,contadorcinco = 0;
		for(int i = 0;i<tamano;i++){
			cout<<"Ingrese la fila"<<i<<": ";
			cin>>fila;
			for(int j = 0;j < tamano;j++;){
				matriz[i][j] = fila[j];
				if(fila[j] == "3"){
					contadorsalida++;
				}else if(fila[j] == "2"){
					contadorentrada++;
				}else if(fila[j] == "5"){
					contadorcinco++;
				}
			}
		}
		if(contadorsalida == 1 && contadorentrada == 1 && contadorcinco){
			
		}else{
			cout<<"Ingrese un numero no valido O mas de una salida o entrada";
		}
		for(int i=0;i<tamano;i++){
			delete[] matriz[i];
		}
		delete[] matriz;
	}
}



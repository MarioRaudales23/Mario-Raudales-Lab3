#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

void sumadebinario(int,int);
int binarioadecimal(int);
void  decimalabinario(int);
void laberinto();
void impresion(char**,int);
void movimiento(char**,int );
int continua(char**,int);
void colocar(char**,int);
void calculadora();

int bandera = 0;

int main(){
	int menu;
	char resp;
	do{
		cout<<"Menu\nOpcion 1:Laberinto\nOpcion 2:Calculadora\nDigite su eleccion: ";
		cin>>menu;
		switch(menu){
			case 1:
				laberinto();
				break;
			case 2:
				calculadora();
				break;
			default:
				cout<<"Opcion no valida";
		}
		cout<<"Desea continuar: ";
		cin>>resp;
	}while(resp == 's' || resp == 'S');
}


void laberinto(){
	int tamano;
	cout <<"Ingrese el tamano del laberinto: ";
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
			for(int j = 0;j < tamano;j++){
				matriz[i][j] = fila[j];
				if(fila[j] == '3'){
					contadorsalida++;
				}else if(fila[j] == '2'){
					contadorentrada++;
				}else if(fila[j] == '5'){
					contadorcinco++;
				}
			}
		}
		if(contadorsalida == 1 && contadorentrada == 1 && contadorcinco == 0){
			movimiento(matriz,tamano);
		}else{
			cout<<"\nIngrese un numero no valido O mas de una salida o entrada.";
		}
		for(int i=0;i<tamano;i++){
			delete[] matriz[i];
		}
		delete[] matriz;
	}
}

void impresion(char** matriz,int tamano){
	for(int i = 0;i<tamano;i++){
		for(int j = 0;j<tamano;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
}

void movimiento(char** matriz,int tamano){
	int puntaje = 0,turno = 0;
	while(continua(matriz,tamano)){
		if(turno == 5){
			colocar(matriz,tamano);
			turno = 0;
		}
		int x,y;
		for(int i=0;i<tamano;i++){
			for(int j=0;j<tamano;j++){
				if(matriz[i][j] == '2'){
					x = i;
					y = j;
				}
			}
		}
		impresion(matriz,tamano);
		char letra;
		cout<<"Ingrese el movimiento: ";
		cin>>letra;
		if(letra == 'w'||letra == 'w'){
			if(matriz[x-1][y] == '1'||matriz[x-1][y] == '3'||matriz[x-1][y] == '5'||matriz[x-1][y] == '*'){			
				if(matriz[x-1][y] == '1'){
					puntaje++;
				}else if(matriz[x-1][y] == '5'){
					puntaje-=5;
				}
				matriz[x][y] = '*';
				matriz[x-1][y] = '2';
				turno++;
			}			
		}else if(letra == 's'||letra == 'S'){
			if(matriz[x+1][y] == '1'||matriz[x+1][y] == '3'||matriz[x+1][y] == '5'||matriz[x+1][y] == '*'){
				if(matriz[x+1][y] == '1'){
					puntaje++;
				}else if(matriz[x+1][y] == '1'){
					puntaje-=5;
				}
				matriz[x+1][y] = '2';
				matriz[x][y] = '*';
				turno++;
			}
		}else if(letra == 'd'||letra == 'D'){
			if(matriz[x][y+1] == '1'||matriz[x][y+1] == '3'||matriz[x][y+1] == '5'||matriz[x][y+1] == '*'){
				if(matriz[x][y+1] == '1'){
					puntaje++;
				}else if(matriz[x][y+1] == '5'){
					puntaje-=5;
				}
				matriz[x][y+1] = '2';
				matriz[x][y] = '*';
				turno++;
			}
		}else if(letra == 'a'||letra == 'A'){
			if(matriz[x][y-1] == '1'||matriz[x][y-1] == '3'||matriz[x][y-1] == '5'||matriz[x][y-1] == '*'){
				if(matriz[x][y-1]=='1'){
					puntaje++;
				}else if(matriz[x][y-1] == '5'){
					puntaje -=5;
				}
				matriz[x][y-1] = '2';
				matriz[x][y] = '*';
				turno++;
			}
		}
	}
	cout<<"Ganador\nSu puntaje es: "<<puntaje;
}


int continua(char** matriz,int tamano){
	int haysalida = 0;
	for(int i= 0;i<tamano;i++){
		for(int j = 0;j<tamano;j++){
			if(matriz[i][j] == '3'){
				haysalida++;
			}
		}
	}
	if(haysalida == 1){
		return true;
	}else{
		return false;
	}
}

void calculadora(){
	int menu;
	cout<<"Opcion 1:Binario-Decimal\nOpcion 2:Decimal-Binario\nOpcion 3:Suma Binario\nDigite su eleccion: ";
	cin>>menu;
	switch(menu){
		case 1:
			int binario;
			cout<<"Ingrese el numero binario: ";
			cin>>binario;
			cout<<"El numero cambiado es: "<<binarioadecimal(binario);
			break;
		case 2:
			int numero;
			cout<<"Ingrese el numero a convertir: ";
			cin>>numero;
			decimalabinario(numero);
			break;
		case 3:
			int numero1,numero2;
			cout<<"Ingrese el primer numero: ";
			cin>>numero1;
			cout<<"Ingrese el Segundo numero: ";
			cin>>numero2;
			sumadebinario(numero1,numero2);
			break;
	}
}
void colocar(char** matriz,int tamano){
	for(int i =0;i<tamano;i++){
		for(int j=0;j<tamano;j++){
			if(matriz[i][j] == '1'){
				matriz[i][j] == 5;
				break;
			}
		}
	}
}

int binarioadecimal(int binario){
	int potencia,numero;
	while(binario >= 10){
		if(binario%10 == 1)
			numero+=pow(2,potencia);
			binario = binario/10;
			potencia++;
	}
	if(binario%10==1)
		numero+=pow(2,potencia);
	return numero;
}

void  decimalabinario(int numero){
	int  binario[7];
	for(int i =7;i>=0;i--){
		binario[i] = numero%2;
		numero=numero/2;
	}
	for(int i = 0;i<=7;i++){
		cout<<binario[i];
	}
}

void sumadebinario(int numero1,int numero2){
	int binario1[7],binario2[7],respuesta[7];
	for(int i=7;i>=0;i--){
		binario1[i] = numero1%2;
		binario2[i] = numero2%2;
		numero1/=2;
		numero2/=2;
	}
	cout<<"Hola";
	int carry = 0;
	for(int i=7;i>=0;i--){
		if(binario1[i] + binario2[i] + carry == 0){
			respuesta[i] =  0;
			carry = 0;
		}else if(binario1[i] + binario2[i] + carry == 1){
			respuesta[i] = 1;
			carry = 0;
		}else if(binario1[i] + binario2[i] + carry == 2){
			respuesta[i] = 0;
			carry = 1;
		}else if(binario1[i] + binario2[i] + carry == 3){
			respuesta[i] = 1;
			carry = 1;
		}
	}
	cout<<"La sumatoria es: ";
	for(int i = 0;i<=7;i++){
		cout<<respuesta[i];
	}
}

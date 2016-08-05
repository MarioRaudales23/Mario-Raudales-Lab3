#include <iostream>
#include <string>

using namespace std;

string binarioadecimal(char[]);
string decimalabinario(char[]);
string suma(char[]);
void laberinto();
void impresion(char**,int);
void movimiento(char**,int );
int continua(char**,int);

int main(){
	int menu;
	char resp;
	cout<<"Menu\nOpcion 1:Laberinto\nOpcion 2:Calculadora\nDigite su eleccion: ";
	cin>>menu;
	do{
		switch(menu){
			case 1:
				laberinto();
				break;
			case 2:
				break;
			default:
				cout<<"Opcion no valida";
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
		impresion(matriz,tamano);
		if(contadorsalida == 1 && contadorentrada == 1 && contadorcinco == 0){
			movimiento(matriz,tamano);
		}else{
			cout<<"Ingrese un numero no valido O mas de una salida o entrada";
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
	while(continua(matriz,tamano)){
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
			if(matriz[x+1][y] == '1'||matriz[x+1][y] == '3'){
				matriz[x+1][y] = '2';
				matriz[x][y]='x';
			}			
		}else if(letra == 's'||letra == 'S'){
			if(matriz[x-1][y] == '1'||matriz[x-1] == '3'){
				matriz[x-1][y] = '2';
				matriz[x][y] = '*';
			}
		}else if(letra == 'd'||letra == 'D'){
			cout<<"hola";
			if(matriz[x][y+1] == '1'||matriz[x][y+1] == '3'){
				cout<<"xy";
				matriz[x][y+1]='2';
				matriz[x][y] = '*';
			}
		}else if(letra == 'a'||letra == 'A'){
			if(matriz[x][y-1] == '1'||matriz[x][y-1] == '3'){
				matriz[x][y-1] = '2';
				matriz[x][y] = '*';
			}
		}
	}
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

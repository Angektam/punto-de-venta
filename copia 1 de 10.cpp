#include<iostream>
#include<string.h>
 
using namespace std;
 int  to_string;


	
	int vegeFruts[3]; //vegetales y frutas
	vegeFruts[0] = 2; //tomates
	vegeFruts[1] = 4; //papas
	vegeFruts[2] = 4; //lechuga

	int breadRep[3]; //panaderia y reposteria
	breadRep[0] = 2; //pan
	breadRep[1] = 4; //pastel
	breadRep[2] = 2; //dona

	int snack[3]; //snacks
	snack[0] = 2; //mani
	snack[1] = 3; //nuez
	snack[2] = 4; //papas fritas

	int drink[3]; //bebidas
	drink[0] = 5; //soda
	drink[1] = 5; //jugo
	drink[2] = 4; //te
	
	int money = 2000, minusMoney = 0, multProduct = 0, opc = 0, indFil = 0, indCol = 0;
	string shoppCart[16];
	
	string totalProductNum[16];
	
	string totalProduct[3][4];

	//vegetales y frutas
	totalProduct[0][0] = "Tomate";
	totalProduct[1][0] = "Papa";
	totalProduct[2][0] = "Lechuga";
	
	//panaderia y reposteria
	totalProduct[0][1] = "Pan";
	totalProduct[1][1] = "Pastel";
	totalProduct[2][1] = "Dona";
	
	//snack
	totalProduct[0][2] = "Mani";
	totalProduct[1][2] = "Nuez";
	totalProduct[2][2] = "Mani confitado";

	//bebidas
	totalProduct[0][3] = "Soda";
	totalProduct[1][3] = "Jugo";
	totalProduct[2][3] = "Te";
	string multProductString;
	bool run = true;
 
	for(int i = 0; i < 16; i++){
		shoppCart[i] = "[vacio]";
	}
	while(run){
		do{
			system("cls");
			cout<<"\t--- Bienvenido a la tienda ---\numero cuenta con "<<money<<" de dinero."<<endl;
			
			cout<<"1. Vegetales y frutas.\n2. Panaderia y reposteria.\n3. Snacks.\n4. Bebidas.\n5. Ver carrito.\n6. Salir."<<endl;
			cin>>opc;
			
			indCol = opc-1;
			
		}while(opc < 1 || opc > 6);
		
		switch(opc){ //opciones
		
			case 1: //vegetales y frutas
			
				do{
					system("cls");
					
					cout<<"1. Tomate | $2\n2. Papa | $4\n3. Lechuga | $4"<<endl;
					cin>>opc;
					
					indFil = opc-1;
					
				}while(opc <= 0 || opc > 3);
				
				minusMoney = vegeFruts[opc-1];
				
			break;
			case 2: //panaderia y reposteria
				do{system("cls");
				
					cout<<"1. Pan | $2\n2. Pastel | $4\n3. Dona | $2"<<endl;
					cin>>opc;
					
					indFil = opc-1;
					
				}while(opc <= 0 || opc > 3);
				
				minusMoney = breadRep[opc-1];
			break;
			
			case 3: //snack
				do{
					system("cls");
					
					cout<<"1. Mani | $2\n2. Nuez | $3\n3. Mani confitado | $4"<<endl;
					cin>>opc;
					
					indFil = opc-1;
					
				}while(opc <= 0 || opc > 3);
				
				minusMoney = snack[opc-1];
			break;
			
			case 4: //bebidas
				do{
					system("cls");
					
					cout<<"1. Soda | $5\n2. Jugo | $4\n3. Te | $4"<<endl;
					cin>>opc;
					
					indFil = opc-1;
					
				}while(opc <= 0 || opc > 3);
				
				minusMoney = drink[opc-1];
			break;
			
			case 5: //carrito
				do{
					
					system("cls");
					
					for(int i = 0; i < 16; i++){
						
						if(shoppCart[i] == "[vacio]"){
							
							cout<<i+1<<". "<<shoppCart[i]<<endl;
							
						}else{
							
							cout<<i+1<<". "<<totalProductNum[i]<<" x "<<shoppCart[i]<<endl;
						}
					}
					
					cout<<"1: Quitar producto del carro. | 2: Salir."<<endl;
					cin>>opc;
					
					if(opc == 1){
						do{
							
							cout<<"Escriba el numero que corresponde al producto que desea retirar; 0 para salir."<<endl;
							cin>>opc;
							
							if(opc == 0){
								break;
							}
							
							shoppCart[opc-1] = "[vacio]";
						}while(opc <= 0 || opc > 16 || shoppCart[opc-1] == "[vacio]");
					}else if(opc == 2){
						break;
					}
				}while(opc <= 0 || opc > 2);
				opc = 5;
			break;
			case 6: //salir
				run = false;
		}
		if(opc < 5){
			do{
				cout<<"Cantidad: "; cin>>multProduct; //multiplicar el precio del producto segun la cantidad
			}while(multProduct <= 0);
			
			multProductString = multProduct;
			minusMoney *= multProduct;
			
			if(money - minusMoney > 0){ //restar dinero
				money -= minusMoney;
				
			}else{
				
				cout<<"No hay suficiente dinero."<<endl;
				system("pause");
				
			}
			for(int i = 0; i < 16; i++){
				
				if(shoppCart[i] == "[vacio]"){
					
					totalProductNum[i] = to_string(multProduct);
					
					shoppCart[i] = "[" + totalProduct[indFil][indCol] + "]";
					
					break;
				}
			}
		}
	}
 
	return 0;
}


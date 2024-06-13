#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>

using namespace std;

struct InfoFecha { //Extructura anidada
    int dia;
    int mes;
    int anio;
};

struct DatosProducto {
    string nombre;
    int cantidad;
    struct InfoFecha fecha;
    float valor_unitario;
    string detalle;
} productos[100];

struct DatosEmpresa {
    string nombre;
    string direccion;
    string pais;
    string capital;
} empresa;

void registrarDatosEmpresa() {
    system("cls");
    cout << "INGRESE EL NOMBRE DE LA EMPRESA: " << endl;
    cin.ignore(); //Limpia el buffer
    getline(cin, empresa.nombre);
    cout << "INGRESE LA LOCALIDAD DE LA EMPRESA (PAIS):" << endl;
    getline(cin, empresa.pais);
    cout << "INGRESE LA LOCALIDAD DE LA EMPRESA (DEPARTAMENTO): " << endl;
    getline(cin, empresa.capital);
    cout << "INGRESE LA DIRECCI"<<char(224)<<"N DE LA EMPRESA: " << endl;
    getline(cin, empresa.direccion);
    cout << "USTED HA REGISTRADO EXITOSAMENTE LOS DATOS DE LA EMPRESA ;D" << endl;
    getch();
    system("cls");
}

void registrarProducto(int& i){
    bool continuar = true; 
    char respuesta[3];
    
    while (continuar) {
        system("cls");
        cout << "INGRESE EL NOMBRE DEL PRODUCTO: " << endl;
        cin.ignore(); //Limpiar el buffer
        getline(cin, productos[i].nombre);
		
		cout << "INGRESE EL VALOR UNITARIO DEL PRODUCTO: " << endl;
        cin >> productos[i].valor_unitario;
		
		cout << "INGRESE EL TIPO DE MOVIMIENTO: " <<endl;
		cout << "* COMPRA " << endl;
		cout << "* VENTA " << endl;
		cin.ignore();
		getline(cin, productos[i].detalle);
        
		cout << "INGRESE LA CANTIDAD DEL PRODUCTO: " << endl;
        cin >> productos[i].cantidad;

        while (productos[i].cantidad <= 0) {
            cout << "LA CANTIDAD INGRESADA NO ES VALIDA" << endl;
            cout << "INGRESE LA CANTIDAD DEL PRODUCTO: " << endl;
            cin >> productos[i].cantidad;
        }

        cout << "INGRESE LA FECHA (DD MM AAAA): " << endl;
        cin >> productos[i].fecha.dia >> productos[i].fecha.mes >> productos[i].fecha.anio;

        cout << "DESEA CONTINUAR (si/no)? " << endl;
        cin >> respuesta;
        strlwr(respuesta); //volver la variable respuesta en minuscula

        while (strcmp(respuesta, "no") != 0 && strcmp(respuesta, "si") != 0) {
            system("cls");
            cout << "LA RESPUESTA NO ES V"<<char(181)<<"LIDA" << endl;
            cout << "DESEA CONTINUAR (si/no)? " << endl;
            cin >> respuesta;
            strlwr(respuesta);
        }

        if (strcmp(respuesta, "no") == 0) {
            cout << "USTED HA REGISTRADO EXITOSAMENTE LOS DATOS DEL PRODUCTO ;D" << endl;
            getch();
            system("cls");
            continuar = false;
        }

        i++;
    }
}

void imprimirReporte(int numProductos) {
    system("cls");
    cout << "NOMBRE DE LA EMPRESA: " << empresa.nombre << endl;
    cout << "LOCALIDAD DE LA EMPRESA: " << empresa.pais << " - " << empresa.capital << endl;
    cout << "DIRECCI"<<char(224)<<"N DE LA EMPRESA: " << empresa.direccion << endl;
    cout << endl;

   				cout << endl;
    			cout <<endl;
    			cout << right << setw(125) << "-----------------------------------------------------------------------------" << endl;
    			cout << right << setw(48) << "|" << right << setw(18) << " ENTRADAS" << setw(8) << "|" << setw(18) << "SALIDAS"
        			 << setw(8) << "|" << setw(17) << "SALDO" << setw(9) << "|" << endl;
    			cout << setw(126) << setfill('-') << " " << endl;
    			cout << setfill(' ') << "N"<< left<< setw(2)<<char(167)<<"|" << setw(11)<< "FECHA" << setw(2) << "|" << setw(10) << "DETALLE" << setw(2) << "|" << right <<setw(13) << "VALOR UNITARIO"
         			 << setw(5) << "|" << setw(11) << "CANTIDAD" << setw(3) << "|" << setw(8) << "TOTAL" << setw(4) << "|"
         			 << setw(11) << "CANTIDAD" << setw(3) << "|" << setw(8) << "TOTAL" << setw(4) << "|"
         			 << setw(11) << "CANTIDAD" << setw(3) << "|" << setw(8) << "TOTAL" << setw(4) << "|" << endl;
    			cout << setw(125) << setfill('-') << " ";
    			cout << setfill(' ') << endl;

    			for (int j = 0; j < numProductos; j++) {
        			cout << setw(2) << j + 1 << ".|" << setw(2) << productos[j].fecha.dia<<"/" <<productos[j].fecha.mes<<"/"<<productos[j].fecha.anio<< setw(2) << "|"
             			 << setw(10) << productos[j].detalle << setw(2) << "|" << setw(16)<<productos[j].valor_unitario
             			 << setw(4) << "|" << setw(9) << productos[j].cantidad << setw(5) << "|"
            			 << setw(8) << "TOTAL" << setw(4) << "|" << setw(11) << "CANTIDAD" << setw(3) << "|"
             			 << setw(8) << "TOTAL" << setw(4) << "|" << setw(11) << "CANTIDAD" << setw(3) << "|"
             			 << setw(8) << "TOTAL" << setw(4) << "|" << endl;
        			cout << setw(126) << setfill('-') << " ";
        			cout << setfill(' ') << endl;
    			}

    getch();
    system("cls");
}

int main() {
    int opcion1, i = 0;

    do {
    	system("cls");
        cout << setw(15) << "MEN"<<char(233) << endl;
        cout << right << setw(17) << "------" << endl;
        cout << endl;
        cout << "1. REGISTRAR DATOS DE LA EMPRESA" << endl;
        cout << "2. REGISTRAR PRODUCTO" << endl;
        cout << "3. IMPRIMIR REPORTE" << endl;
        cout << "4. SALIR" << endl;
        cout << endl;
        cout << "SELECCIONA LA OPCI"<<char(224)<<"N: ";
        cin >> opcion1;
        
        switch (opcion1) {
            case 1:
                registrarDatosEmpresa();
                break;
            case 2:
                registrarProducto(i);
                break;
            case 3:
                imprimirReporte(i);
                break;
            case 4:
                system("cls");
                cout << "USTED HA SALIDO DEL MEN"<<char(233)<<" ;D" << endl;
                return 0;
            default:
                cout << "\nOPCI"<<char(224)<<"N NO VALIDA, INTENTE DE NUEVO." << endl;
                getch();
                break;
        }
    } while (true);

    return 0;
}


//Carlos GOnzalez Garita examen 3
//Si hay problemas con las tildes me disculpo, pero por algun motivo las tildes me suelen causar problemas
#define PALABRAS 10
#define LETRAS 13
#define totalDeLetrasDelAlfabeto 26
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Encriptacion {
private:
    int mat[PALABRAS][LETRAS]; 		// define la colección de palabras cifradas
    char vec[26]; 			// define las letras del abecedario, en el orden usual
    int posicionDeLaPalabra;
public:
    Encriptacion() {
        // Llena la matriz con valores -1
        for (int i = 0; i < PALABRAS; i++) {
            for (int j = 0; j < LETRAS; j++) {
                mat[i][j] = -1;
            }
        }
        // Llena el vector con  las  letras del abecedario según el orden descrito.
        int posicion = 0;
	    for(char letra = 'a'; letra <= 'z'; letra++){
		vec[posicion] = letra;
		posicion++;
	    }
        posicionDeLaPalabra = 0; //la fila en la que se debe de poner la palabra
    }
    ~Encriptacion() {}
    //inserte aquí los métodos que faltan
    int getPosicionDeLaPalabra() {
        return posicionDeLaPalabra;
    }
    void setPosicionDeLaPalabra(int posicionDeLaPalabra) {
        this->posicionDeLaPalabra = posicionDeLaPalabra;
    }
    //encriptar la palabra
    void encriptar(string palabra){
        for (int i = 0; i < totalDeLetrasDelAlfabeto; i++){
            for (int j = 0; j < palabra.length(); j++){
                //si hay un espacio en blanco se debe de escrbir en la siguiente fila
                if (palabra[j] == vec[i]){
                    mat[posicionDeLaPalabra][j] = i;
                }
            }
        }
        posicionDeLaPalabra = posicionDeLaPalabra + 1;
    }
    //separa la frase en palabras

    //desencriptar una palabra
    string desencriptar(){
        stringstream ss;
        for (int j = 0; j < PALABRAS; j++){
            for (int i = 0; i < LETRAS; i++){
                if (mat[j][i] != -1){
                    ss << vec[mat[j][i]];
                }
            }
            ss << " ";
        }
        return ss.str();;
    }
    //imprime la matriz
    string toString() {
        stringstream ss;
        for (int i = 0; i < PALABRAS; i++) {
            for (int j = 0; j < LETRAS; j++) {
                ss << mat[i][j] << " ";
            }
            ss << endl;
        }
        return ss.str();
    }
};

int main() {
    string frase;
    string palabra;
    cout << "---------Creando una coleccion -----------" << endl;
    Encriptacion e;
    cout << "---------------------------" << endl;
    cout << "Ingreso  del mensaje por encriptar..." << endl;
    getline(cin, frase);

    //separar la frase en palabras
    stringstream ss(frase);
    while (getline(ss, palabra, ' ')) {
        e.encriptar(palabra);
    }

    cout << "Mostrar matriz de encriptaci�n..." << endl;
    cout << "--------------------------------------------" << endl;
    cout << e.toString() << endl;


    cout <<"El mensaje descifrado es: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << e.desencriptar() << endl;
    return 0;
}

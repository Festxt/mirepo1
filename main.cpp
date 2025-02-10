#include <iostream>
using namespace std;

// Función para calcular la suma de los dígitos de un número
int sumaDigitos(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

// Lógica para calcular la tarifa
double calcularTarifa(int horas, int dia) {
    const double TARIFA_PRIMERA_HORA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_HORAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    // Validar límite de horas
    if (horas > LIMITE_HORAS) {
        return -1;
    }

    double totalPagar = 0.0;

    // Calcular la tarifa base
    if (horas == 1) {
        totalPagar = TARIFA_PRIMERA_HORA;
    } else if (horas > 1 && horas <= 3) {
        totalPagar = TARIFA_PRIMERA_HORA + (horas - 1) * TARIFA_1_A_3;
    } else if (horas > 3 && horas <= 5) {
        totalPagar = TARIFA_PRIMERA_HORA + 2 * TARIFA_1_A_3 + (horas - 3) * TARIFA_3_A_5;
    } else {
        totalPagar = TARIFA_FIJA;
    }

    // Aplicar incremento si es fin de semana (día 6 o 7)
    if (dia == 6 || dia == 7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }

    // Aplicar descuento si la suma de los dígitos es múltiplo de 3
    if (sumaDigitos(horas) % 3 == 0) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int horas;
    int dia;

    // Leer los valores de entrada
    cout << "Digite el numero de horas: ";
    cin >> horas;
    cout << "Digite el numero del dia (1-7): ";
    cin >> dia;
    cout << "____________________________________________" << endl;
    double resultado = calcularTarifa(horas, dia);
    if (resultado == -1) {
        cout << "ERROR: Número de horas excede el limite de 24 orbitas ." << endl;
    } else {
        cout << "la Tarifa es: ";
        printf("%.2f", resultado);
        cout << " creditos intergalacticos" << endl;
    }

    return 0;
}

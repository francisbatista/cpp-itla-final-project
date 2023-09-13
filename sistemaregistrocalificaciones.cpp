#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

int main()
{
    cout << ".:Sistema de registro de calificaciones:." << endl;
    cout << "Digite el nombre del estudiante: ";
    string nombreEstudiante;
    cin >> nombreEstudiante;
    cin.clear();
    cin.ignore(250, '\n');
    cout << "Digite el apellido del estudiante: ";
    string apellidoEstudiante;
    cin >> apellidoEstudiante;
    cin.clear();
    cin.ignore(250, '\n');
    cout << "Cuantas materias desea registrar?: ";
    int cantidadMaterias = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, calificacion = 0;
    m = scanf("%d", &cantidadMaterias);
    fflush(stdin);
    while (!m)
    {
        cout << "debes ingresar un numero no letras! intentelo de nuevo" << endl;
        cout << "Cuantas materias desea registrar?: ";
        m = scanf("%d", &cantidadMaterias);
        fflush(stdin);
        l++;
        if (l == 4)
        {
            cout << "has excedido el numero de intentos!" << endl;
            break;
        }
    }
    vector<string> materias(0);
    vector<int> calificaciones(0);
    vector<string> materiasReprobadas(0);
    vector<int> calificacionesReprobadas(0);
    float promedioCalificaciones = 0.0;
    if (l != 4)
    {
        bool keepInLoop = true;
        string userChoise, materia;
        while (keepInLoop)
        {
            cout << "ingrese la materia #" << (j + 1) << ": ";
            cin >> materia;
            fflush(stdin);
            materias.push_back(materia);
            cout << "ingrese la calificacion para la materia " << materia << ": ";
            n = scanf("%d", &calificacion);
            fflush(stdin);
            if (calificacion <= 100 and calificacion >= 0 and n)
            {
                calificaciones.push_back(calificacion);
            }
            else
            {
                cout << "error, la calificacion ingresada no es valida, el rango es de 0 a 100" << endl;
                while (calificacion > 100 or calificacion < 0 or !n)
                {
                    cout << "vuelva a ingresar la calificacion para la materia " << materia << ": ";
                    n = scanf("%d", &calificacion);
                    fflush(stdin);
                    k++;
                    if (k == 4)
                    {
                        cout << "has excedido el numero de intentos!" << endl;
                        break;
                    }
                }
                if (k == 4)
                {
                    cout << "programa finalizado" << endl;
                    break;
                }
                else
                {
                    calificaciones.push_back(calificacion);
                    k = 0;
                }
            }
            i++, j++;
            if (i == cantidadMaterias)
            {
                cout << "Desea agregar mas materias? y/n" << endl;
                cin >> userChoise;
                fflush(stdin);
                if (userChoise == "y")
                {
                    cout << "Cuantas materias desea registrar?: ";
                    m = scanf("%d", &cantidadMaterias);
                    fflush(stdin);
                    i = 0;
                    l = 0;
                    while (!m)
                    {
                        cout << "debes ingresar un numero no letras! intentelo de nuevo" << endl;
                        cout << "Cuantas materias desea registrar?: ";
                        m = scanf("%d", &cantidadMaterias);
                        fflush(stdin);
                        l++;
                        if (l == 4)
                        {
                            cout << "has excedido el numero de intentos!" << endl;
                            break;
                        }
                    }
                }
                else if (userChoise == "n")
                {
                    break;
                }
                else
                {
                    cout << "error (" << userChoise << ") no es un comando reconocido" << endl;
                    break;
                }
            }
        }
    }
    int sumaCalificaciones = 0;
    for(size_t i = 0; i < calificaciones.size(); i++) {
        if(calificaciones[i] < 70) {
            materiasReprobadas.push_back(materias[i]);
            calificacionesReprobadas.push_back(calificaciones[i]);
        }
        sumaCalificaciones += calificaciones[i];
    }
    promedioCalificaciones = sumaCalificaciones / stof(to_string(calificaciones.size()));
    cout << "Materias reprobadas: " << endl;
    for(size_t i = 0; i < materiasReprobadas.size(); i++) {
        cout << materiasReprobadas[i] << ": " << calificacionesReprobadas[i] << endl;
    }
    cout << "Promedio de calificaciones: ";
    printf("%.2f", promedioCalificaciones);
    cout << endl;
    system("pause");
    return 0;
}
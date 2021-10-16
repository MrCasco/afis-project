#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

/* Examen 2 Programacion Avanzada
    Fernando Camacho
    Ernesto Casco
    David Gaona
*/

int ult_minucia = 0;

typedef struct {
  int x, y;
  float angulo;
  uint8_t tipo;
} Minucia;

typedef struct {
  Minucia *arr;
  int longitud;
} ArregloMinucias;

ArregloMinucias *queuePtr;

Minucia *crearMinucia(int x, int y, float angulo, int tipo) {
  queuePtr->arr[ult_minucia].x = x;
  queuePtr->arr[ult_minucia].y = y;
  queuePtr->arr[ult_minucia].angulo = angulo;
  queuePtr->arr[ult_minucia].tipo = tipo;
  ult_minucia++;
}

ArregloMinucias *crearArregloMinucias(int n) {
  ArregloMinucias* queuePtr = (ArregloMinucias*)malloc(sizeof(ArregloMinucias));
  queuePtr->arr = (Minucia*)calloc(n, sizeof(Minucia));
  queuePtr->longitud = n;
  return queuePtr;
}

void inicializarMinucias() {
  int n = queuePtr->longitud;
  for (int i = 0; i < n; i++) {
    crearMinucia(0, 0, 0.0, 0);
    ult_minucia = 0;
  }
}

void liberarArregloMinucias(ArregloMinucias* queuePtr) {
  free(queuePtr->arr);
  free(queuePtr);
  ult_minucia = 0;
}

void devolverTipoMinucia(Minucia* minucia){
  uint8_t num = minucia->tipo;
  uint8_t x = (num >> 6) & 0x3;
  if(x == 0){
    printf("Terminacion");
  }
  if(x == 1){
    printf("Division");
  }
  if(x == 2){
    printf("Punto");
  }
  if(x == 3){
    printf("Desconocido");
  }
}

float calcularDistancia(int a, int b) {
    int ax = queuePtr->arr[a].x;        int bx = queuePtr->arr[b].x;
    int ay = queuePtr->arr[a].y;        int by = queuePtr->arr[b].y;
    float ao = queuePtr->arr[a].angulo; float bo = queuePtr->arr[b].angulo;
    int abx = (ax-bx)*(ax-bx);
    int aby = (ay-by)*(ay-by);
    float abo = (ao-bo)*(ao-bo);
    return sqrt(abx+aby+abo);
}

int encontrarCentroide() {
    float arr[ult_minucia];
    int i = 0;
    int j = 0;
    float sumDist;
    for(i = 0; i < ult_minucia; i++){
        sumDist = 0;
        for(j = 0; j < ult_minucia; j++){
            sumDist += calcularDistancia(i, j);
        }
        arr[i] = sumDist;
    }
    float min = 999999;
    int minp;
    for(i = 0; i < ult_minucia; i++){
        if(arr[i] < min){
            min = arr[i];
            minp = i;
        }
    }
    return minp;
}

int main() {
  printf("EXAMEN 2 - PROGRAMACION AVANZADA\n");
  printf("Fernando Camacho\n");
  printf("Ernesto Casco\n");
  printf("David Gaona\n");
  printf("Favor de leer los comentarios en el main del codigo para interpretar los resultados :)\n");
  queuePtr = crearArregloMinucias(5);
  inicializarMinucias();

  // Primer conjunto de minucias
  crearMinucia(1, 0, 0.0, 0x40);   //0
  crearMinucia(-1, 0, 0.0, 0x80);  //1
  crearMinucia(0, 1, 0.0, 0xc0);   //2
  crearMinucia(0, -1, 0.0, 0x00);  //3
  crearMinucia(0, 0, 0.0, 0x00);   //4 <--- CENTROIDE
  //Este conjunto de minucias está acomodado en dos "Dimensiones", esto imaginando que la variable angulo de cada minucia actuara como una tercera dimension.
  //La minucia marcada como 4 debería ser el centroide.
  /* DIAGRAMA
             [2]
              |
         [1]-[4]-[0]
              |
             [3]
  */
  Minucia centroide = queuePtr->arr[encontrarCentroide()];
  printf("\nCentroide encontrado en la minucia con coordenadas (%d,%d) y angulo de %f grados, de tipo ",centroide.x,centroide.y,centroide.angulo);
  devolverTipoMinucia(&centroide);
  //Liberamos el espacio en el arreglo para introducir un nuevo conjunto de minucias
  liberarArregloMinucias(queuePtr);
  queuePtr = crearArregloMinucias(4);
  inicializarMinucias();

  //Segundo conjunto de minucias
  crearMinucia(20,20,30.0,0xc0); //0
  crearMinucia(10,20,30.0,0x40); //1 <--- CENTROIDE
  crearMinucia(10,30,30.0,0x80); //2
  crearMinucia(10,20,40.0,0x00); //3
  //Este conjunto se encuentra en tres "Dimensiones", acomodadas como si una fuera uno de los vertices de un cubo y las otras 3 fueran los vertices adyacentes a este.
  //En este caso la minucia marcada como 1 deberia ser el centroide.
  /* DIAGRAMA

                [3]
                 |
            [0]-[1]
                   \
                    [2]

  */
  centroide = queuePtr->arr[encontrarCentroide()];
  printf("\nCentroide encontrado en la minucia con coordenadas (%d,%d) y angulo de %f grados,  de tipo ",centroide.x,centroide.y,centroide.angulo);
  devolverTipoMinucia(&centroide);
  //Liberamos el espacio en el arreglo para introducir un nuevo conjunto de minucias
  liberarArregloMinucias(queuePtr);
  queuePtr = crearArregloMinucias(7);
  inicializarMinucias();

  //Tercer conjunto de minucias
  crearMinucia(260,500,45.0,0x00); //0
  crearMinucia(240,500,45.0,0x40); //1
  crearMinucia(250,500,45.0,0x80); //2 <--- CENTROIDE
  crearMinucia(250,550,45.0,0xc0); //3
  crearMinucia(250,450,45.0,0x00); //4
  crearMinucia(250,500,25.0,0x40); //5
  crearMinucia(250,500,65.0,0x80); //6
  //De nuevo tenemos un conjunto de minucias en tres dimensiones, pero ahora acomodadas alrededor de una minucia en el centro de la estructura como un nucleo.
  //La minucia marcada como 2 deberia ser el centroide.
  /* DIAGRAMA

            [5] [3]
               \ |
            [1]-[2]-[0]
                 | \
                [4] [6]

  */
  centroide = queuePtr->arr[encontrarCentroide()];
  printf("\nCentroide encontrado en la minucia con coordenadas (%d,%d) y angulo de %f grados,  de tipo ",centroide.x,centroide.y,centroide.angulo);
  devolverTipoMinucia(&centroide);
  //Liberamos el espacio en el arreglo para introducir un nuevo conjunto de minucias
  liberarArregloMinucias(queuePtr);
  queuePtr = crearArregloMinucias(3);
  inicializarMinucias();

  //Cuarto conjunto de minucias
  crearMinucia(50,50,360.0,0x40); //0
  crearMinucia(50,50,90.0,0xc0);  //1 <--- CENTROIDE
  crearMinucia(50,50,0.0,0x80);   //2
  //Esta vez tenemos tres minucias en el mismo punto, pero cuyos angulos son diferentes, es decir, tres minucias en fila.
  //La minucia marcada como 1 deberia ser el centroide.
  /* DIAGRAMA

    [0]
       \
        [1]
           \
            [2]

  */
  centroide = queuePtr->arr[encontrarCentroide()];
  printf("\nCentroide encontrado en la minucia con coordenadas (%d,%d) y angulo de %f grados,  de tipo ",centroide.x,centroide.y,centroide.angulo);
  devolverTipoMinucia(&centroide);
  return 0;
}

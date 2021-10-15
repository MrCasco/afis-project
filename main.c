#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int ult_minucia = 0;

typedef struct {
  int x, y;
  float angulo;
  int tipo;
} Minucia;

typedef struct {
  Minucia *arr;
  int longitud;
} ArregloMinucias;

ArregloMinucias *queuePtr;

ArregloMinucias *crearArregloMinucias(int n) {
  ArregloMinucias* queuePtr = (ArregloMinucias*)malloc(sizeof(ArregloMinucias));
  queuePtr->arr = (Minucia*)calloc(n, sizeof(Minucia));
  queuePtr->longitud = n;
  return queuePtr;
}

void liberarArregloMinucias(ArregloMinucias* queuePtr) {
  free(queuePtr->arr);
  free(queuePtr);
  ult_minucia = 0;
}

Minucia *crearMinucia(int x, int y, float angulo, int tipo) {
  queuePtr->arr[ult_minucia].x = x;
  queuePtr->arr[ult_minucia].y = y;
  queuePtr->arr[ult_minucia].angulo = angulo;
  queuePtr->arr[ult_minucia].tipo = tipo;
  ult_minucia++;
}
void devolverTipoMinucia(ArregloMinucias* queuePtr){
uint8_t num =  queuePtr->arr[ult_minucia].tipo;
uint8_t x;
x= num & 0x3;
  
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

float calcularDistancia(int a, int b){
    int ax = queuePtr->arr[a].x;        int bx = queuePtr->arr[b].x;
    int ay = queuePtr->arr[a].y;        int by = queuePtr->arr[b].y;
    float ao = queuePtr->arr[a].angulo; float bo = queuePtr->arr[b].angulo;
    int abx = (ax-bx)*(ax-bx);
    int aby = (ay-by)*(ay-by);
    float abo = (ao-bo)*(ao-bo);
    return sqrt(abx+aby+abo);
}

int encontrarCentroide(){
    float arr[ult_minucia];
    int i = 0;
    int j = 0;
    float sumDist;
    for(i = 0; i < ult_minucia; i++){
        sumDist = 0;
        for(j = 0; j < ult_minucia; j++){
            sumDist += calcularDistancia(i,j);
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
    return arr[minp];
}

int main(){
  queuePtr = crearArregloMinucias(5);
  crearMinucia(1, 0, 45.0, 0x00);
  crearMinucia(-1, 0, 45.0, 0x00);
  crearMinucia(0, 1, 45.0, 0x00);
  crearMinucia(0, -1, 45.0, 0x00);
  crearMinucia(0, 0, 45.0, 0x00);
  encontrarCentroide();
  return 0;
}

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

int main(){
  queuePtr = crearArregloMinucias(3);
  crearMinucia(0, 0, 45.0, 0x00);
  return 0;
}

#include <stdio.h>
#include <math.h>
float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos [5][3], float *a, float *b, float *c, float *d, float *e, float *f, float *baricentro);
float calcularArea(float a, float b, float c);
float calcularVolumen(float puntos [5][3], float baricentro, float area1);

int main(int argc, char const *argv[])
{
    float puntos [5][3]= {{0,0,0},{3,0,0},{0,0,3},{1,7,1},{1,0,1}};
    float per, a, b, c, d, e, f,baricentro;
    

    float perimetro = calcularPerimetro(puntos,&a,&b,&c,&d,&e,&f,&baricentro);
    float area1 = calcularArea(a,b,c);
    float area2 = calcularArea(b,d,e);
    float area3 = calcularArea(a,e,f);
    float area4 = calcularArea(e,f,a);
    float areasuperficial = area1+area2+area3+area4;
    float volumen = calcularVolumen(puntos,baricentro,area1);

    printf("El perimetro es: %f\n", perimetro);
    printf("El area superficial es: %f\n", areasuperficial);
    printf("El volumen  es: %f\n", volumen);
    return 0;
}

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2){
    float dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    return dist;
}

float calcularPerimetro(float puntos [5][3], float *a, float *b, float *c, float *d, float *e, float *f, float *baricentro){
    *a = calcularDistancias (puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
    *b = calcularDistancias (puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    *c = calcularDistancias (puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
    *d = calcularDistancias (puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    *e = calcularDistancias (puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    *f = calcularDistancias (puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    *baricentro = calcularDistancias (puntos[4][0],puntos[4][1],puntos[4][2],puntos[3][0],puntos[3][1],puntos[3][2]);
    float per=*a+*b+*c+*d+*e+*f;
    return per;
}

float calcularArea(float a, float b, float c){
    float s=(a+b+c)/2;
    float area= sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

float calcularVolumen(float puntos [5][3], float baricentro, float area1){
    float volumen = ((area1)*(baricentro)/3);
    return volumen;
}
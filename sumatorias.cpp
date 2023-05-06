#include <iostream>


float determinante(float a1,float b1,float c1,float a2,float b2,float c2,float a3,float b3,float c3)//calcula el determinante de una matrix 3x3
{
    return (a1*b2*c3 + a2*b3*c1 + a3*b1*c2)-(c1*b2*a3 + c2*b3*a1 + c3*b1*a2);  
}

double calA(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de a
{   

    float ds{},da{};
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema
    da=determinante(d1,b1,c1,d2,b2,c2,d3,b3,c3); //se calcula el determinante de a, reemplazando la columna de a con los valores de la ultima columna

    return da/ds; //se divide el determinante de a por el determinante del sistema para calcular a y retornar el valor
}

double calB(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de b
{
    float ds{},db{}; 
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema  
    db=determinante(a1,d1,c1,a2,d2,c2,a3,d3,c3); //se calcula el determinante de b, reemplazando la columna de b con los valores de la ultima columna


    return db/ds; //se divide el determinante de b por el determinante del sistema para calcular b y retornar el valor                  
}

double calC(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de b
{
    float ds{},dc{}; 
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema                  
    dc=determinante(a1,b1,d1,a2,b2,d2,a3,b3,d3); //se calcula el determinante de c, reemplazando la columna de c con los valores de la ultima columna

    return dc/ds; //se divide el determinante de c por el determinante del sistema para calcular c y retornar el valor
}
int main()
{

    float x[5]  ={0,1,2,3,4};
    float y[5]  ={0.5,1,1.34,2,3.7};
    float x2[5] ={0,0,0,0,0};
    float x3[5] ={0,0,0,0,0};
    float x4[5] ={0,0,0,0,0};
    float xy[5] ={0,0,0,0,0}; 
    float x2y[5]={0,0,0,0,0};
    float sumx{},sumy{},sumx2{},sumx3{},sumx4{},sumxy{},sumx2y{}; //sumatorias

    for (int i=0;i<5;i++) //se calculan las sumatorias
    {   
        //se calcula cada variable y se le asigna una posicion en el arreglo correspondiente
        x2[i]=x[i]*x[i]; 
        x3[i]=x[i]*x[i]*x[i];
        x4[i]=x[i]*x[i]*x[i]*x[i];
        xy[i]=x[i]*y[i];
        x2y[i]=x2[i]*y[i];

        //se calculan las sumatorias 
        sumx +=x[i]; // sumx = sumx + x[i]
        sumy +=y[i]; 
        sumx2+=x2[i]; 
        sumx3+=x3[i];
        sumx4+=x4[i];
        sumxy+=xy[i];
        sumx2y+=x2y[i];

    }

    /*float matrixRegresion [3][4]={{sumx2, sumx,  5  , sumy },  
                                    {sumx3,sumx2, sumx,sumxy },
                                    {sumx4,sumx3,sumx2,sumx2y}};
    */

    double a{},b{},c{};

    if (0!=determinante(sumx2,sumx,5,sumx3,sumx2,sumx,sumx4,sumx3,sumx2)) //verificar que la matrix sea invertible
    {   
        //se calculan los valores de los coeficientes
        a=calA(sumx2,sumx,5,sumy,sumx3,sumx2,sumx,sumxy,sumx4,sumx3,sumx2,sumx2y); 
        b=calB(sumx2,sumx,5,sumy,sumx3,sumx2,sumx,sumxy,sumx4,sumx3,sumx2,sumx2y);
        c=calC(sumx2,sumx,5,sumy,sumx3,sumx2,sumx,sumxy,sumx4,sumx3,sumx2,sumx2y);
    } 
    else
    {
        std::cout<< "el sistema tiene soluciones infinitas";
    }                           

    std::cout << "a= " << a <<'\n';
    std::cout << "b= " << b <<'\n';
    std::cout << "c= " << c <<'\n';
    std::cout << "el polinomio de orden cuadratico es: " << a << "x^2 + (" << b << "x) " << "+ (" << c << ")." << '\n';
    std::cout << "fin";

    return 0;
}
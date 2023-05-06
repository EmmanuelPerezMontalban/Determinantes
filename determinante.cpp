#include <iostream>

int determinante(float a1,float b1,float c1,float a2,float b2,float c2,float a3,float b3,float c3)//calcula el determinante de una matrix 3x3
{
    return (a1*b2*c3 + a2*b3*c1 + a3*b1*c2)-(c1*b2*a3 + c2*b3*a1 + c3*b1*a2);  
}

int a(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de a
{   

    float ds{},da{};
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema
    da=determinante(d1,b1,c1,d2,b2,c2,d3,b3,c3); //se calcula el determinante de a, reemplazando la columna de a con los valores de la ultima columna

    return da/ds; //se divide el determinante de a por el determinante del sistema para calcular a y retornar el valor
}

int b(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de b
{
    float ds{},db{}; 
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema  
    db=determinante(a1,d1,c1,a2,d2,c2,a3,d3,c3); //se calcula el determinante de b, reemplazando la columna de b con los valores de la ultima columna


    return db/ds; //se divide el determinante de b por el determinante del sistema para calcular b y retornar el valor                  
}

int c(float a1,float b1,float c1,float d1,float a2,float b2,float c2,float d2,float a3,float b3,float c3,float d3)//esta funcion calcula el valor de b
{
    float ds{},dc{}; 
    ds=determinante(a1,b1,c1,a2,b2,c2,a3,b3,c3); //se calcula el determinante del sistema                  
    dc=determinante(a1,b1,d1,a2,b2,d2,a3,b3,d3); //se calcula el determinante de c, reemplazando la columna de c con los valores de la ultima columna

    return dc/ds; //se divide el determinante de c por el determinante del sistema para calcular c y retornar el valor
}



int main(){

    float matrix[3][4]={{1,-3,2,-3},
                        {5,6,-1,13},
                        {4,-1,3, 8}};

    std::cout << c(matrix[0][0],matrix[0][1],matrix[0][2],matrix[0][3],
                   matrix[1][0],matrix[1][1],matrix[1][2],matrix[1][3],
                   matrix[2][0],matrix[2][1],matrix[2][2],matrix[2][3]) << '\n';
    std::cout << "fin";
    return 0;

}
//ESTE ES EL CAMBIO QUE REALICE

//OTRA PERSONA HACE UN CAMBIO 

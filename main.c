#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Прототип

double func (double x);
unsigned int method_choose( void );
double method_of_halving ( double x1, double x2, double epsilon, unsigned int iteration_variant, unsigned int iteration_step);
double hord_method ( double x1, double x2, double epsilon, unsigned int iteration_variant, unsigned int iteration_step);
//================================================================================================================
//Виклик
int main(){

unsigned int method, iteration_variant;
double x1, x2, epsilon,  root, delta_time;
int iteration_step = 5;
time_t start, end;


do{
    printf("\nEnter your input values:");
    printf("\n\nX1=");// 0
    scanf("%lf", &x1);
    printf("\nX2=");// 50
    scanf("%lf", &x2);
    printf("\nepsilon=");
    scanf("%lf", &epsilon);

}while( func(x1) * func(x2) > 0);

do{
     system("cls");
     printf("\nOutput each iteration?");
     printf("\n\n1.Yes\n2.No\n\n>");
     scanf("%u", &iteration_variant);

}while( iteration_variant != 1 && iteration_variant != 2 );

method = method_choose();

start = clock();

switch(method){

    case 1:
        root = method_of_halving ( x1, x2, epsilon, iteration_variant, iteration_step);
        system("cls");
        printf("\n\n root=%lf\n\n F(x)=%lf", root, func(root));
    break;

    case 2:
        root = hord_method ( x1, x2, epsilon, iteration_variant, iteration_step);
        system("cls");
        printf("\n\n root=%lf\n\n F(x)=%lf", root, func(root));

    break;

}

end = clock();
delta_time = ( end - start )/1000;
printf("\n\n work time:%.3f seconds\n", delta_time);

return 0;
}

//================================================================================================================
//Опис функції
double func (double x){

 return (pow(x,3)/30)-(4*pow(x,2))+50;
}

//===============================================================================================================
//Опис вибору варіанту
unsigned int method_choose( void ){

unsigned int var;

printf("\nChoose your method:");
printf("\n\n\t1.Method of halving");
printf("\n\t2.Chord method.\n\n>");
scanf("%u", &var);

    while( var != 1 && var != 2 ){

        printf("\n!!!! Invalid variant of method !!!!\n");
        printf("\nEnter the method number again:/n>");
        scanf("%u", &var);
    }

return var;
}

//================================================================================================================
//Опис методу половинного ділення
double method_of_halving ( double x1, double x2, double epsilon, unsigned int iteration_variant, unsigned int iteration_step){

double Xi;
unsigned int iteration_count = 0;

    if(iteration_variant == 1){

    do{
    int continuation_option = 0;
    iteration_count ++;

    Xi = (x1+x2)/2;

    if ( func(Xi) * func(x1) > 0)
    x1 = Xi;

    else
    x2 = Xi;

    if (iteration_count = iteration_step ){
    printf("\n%d iterations done", iteration_count);
    printf("\n X=%lf\n F(x)=%lf", Xi, func(Xi));
    printf("\n 1.Continue execution");//продовження виконання програми з такою же кількістю ітерацій
    printf("\n 2.Complete the program until the root is found");//Продовжити виконання поки не буде знайдено корінь
    printf("\n 3.Display the intermediate result and exit the program");//вивести поточні значення та вийти з програми

    while( continuation_option !=1 && continuation_option != 2 && continuation_option != 3 ){
    printf("\n>");
    scanf("%u", &continuation_option);

    }

    if(continuation_option == 1){

    iteration_step = iteration_count + 5;
                        }

    if(continuation_option == 2){

    iteration_step = iteration_step * 0;

                        }

    if(continuation_option == 3){

    break;
                        }

                }


    }
    while(fabs(x1-x2)>= epsilon);
    }


    if(iteration_variant == 2){

    do{

    Xi = (x1+x2)/2;

    if ( func(Xi) * func(x1) > 0)
    x1 = Xi;
    else
    x2 = Xi;

    }while(fabs(x1-x2)>= epsilon);

    }

    return Xi;
}

//================================================================================================================
//Опис методу хорд

double hord_method ( double x1, double x2, double epsilon, unsigned int iteration_variant, unsigned int iteration_step){

unsigned int iteration_count = 0;
double Xi = 0;

    if(iteration_variant == 1){

    do{
    int continuation_option = 0;
    iteration_count ++;

    x1 = x2 - (x2 - x1) * func(x2) / (func(x2) - func(x1));
    Xi = x1 - (x1 - x2) * func(x1) / (func(x1) - func(x2));

    if (iteration_count = iteration_step ){

    printf("\n%d iterations done", iteration_count);
    printf("\n X=%lf\n F(x)=%lf", Xi, func(Xi));
    printf("\n 1.Continue execution");//продовження виконання програми з такою же кількістю ітерацій
    printf("\n 2.Complete the program until the root is found");//Продовжити виконання поки не буде знайдено корінь
    printf("\n 3.Display the intermediate result and exit the program");//вивести поточні значення та вийти з програми

    while( continuation_option !=1 && continuation_option != 2 && continuation_option != 3 ){
    printf("\n>");
    scanf("%u", &continuation_option);

                        }

    if(continuation_option == 1){

    iteration_step = iteration_count + 5;
                        }

    if(continuation_option == 2){

    iteration_step = iteration_step * 0;
                        }

    if(continuation_option == 3){

    break;
                        }
              }

    }while(fabs(Xi - x1) > epsilon);

    }

    if(iteration_variant == 2){

    do{

    x1 = x2 - (x2 - x1) * func(x2) / (func(x2) - func(x1));
    Xi = x1 - (x1 - x2) * func(x1) / (func(x1) - func(x2));

    }while(fabs(Xi - x1) > epsilon);

    }

return Xi;
}
//===========================================================================================

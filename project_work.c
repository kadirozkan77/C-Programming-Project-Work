#include <stdio.h>
#include <math.h>
#include<stdlib.h>
const double PI=3.14159265359; // for circle calculations

double summation(double x1, double x2){
    return x1+x2;
}

double subtraction(double x1, double x2){
    return x1-x2;
}

double division(double x1, double x2){
    return x1/x2;
}

double multiplication(double x1, double x2){
    return x1*x2;
}
double square_root(double x1){
    return sqrt(x1);
}
double area_circ(double x1){
    return PI*x1*x1;
}
double circumference_circ(double x1){
    return 2*PI*x1;
}
double deg_to_rad(double x1){
    return (x1*PI)/180;
}

double exponential_f(double x1, int exponent){
    double mult=1.0;
    for (int i = 0; i < exponent; i++)
    {
        mult*=x1;
    }
    return mult;
    
}

double factoriel(int x1){
    int mult=1;
    for(int i=1;i<=x1;i++){
        mult*=i;
    }
    return mult;
}

double average(int length,int arr[]){
    int tot=0;
    for(int i=0;i<length;i++){
        tot+=arr[i];
    }
    return (double) tot/length;
}

double std(int length, int arr[]){
    int mean=average(length,arr);
    int tot=0;
    for(int i=0;i<length;i++){
        tot+=(arr[i]-mean)*(arr[i]-mean);
    }
    return sqrt(tot)/length;
}




int main(){
    int choice,calc_space,index=0,angle,exponent,f_number; // angle is for deg_to_rad; exponent is for exponential ; f_number is for factoriel
    double x1,x2,result;
    double* calc_hist; 
    int arr_length; // length of the below array
    int array[arr_length]; // this array is for mean and standart deviation calculations
    //char calc_str[15]; // calculation string will be added to calc_hist
    printf("How many calculations do you want to make? ");
    scanf("%d",&calc_space);
    calc_hist= (double*) malloc(calc_space*sizeof(int));
    if (calc_hist==NULL)
    {
        printf("Memory allocation has been failed! \n");
    }
    else{
        printf("Memory allocation has been succeeded. \n");
    }
    
    
    do
    {
        printf("MENU\n");
        printf("---------------\n");
        printf("1) Summation: \n");
        printf("2) Subtraction: \n");
        printf("3) Multiplication: \n");
        printf("4) Division: \n");
        printf("5) Show history. \n");
        printf("6) Square root: \n");
        printf("7) Area of the circle: \n");
        printf("8) Circumference of the circle: \n");
        printf("9) Convert degree to rad: \n");
        printf("10) Exponential (x^y) : \n");
        printf("11) Factoriel : \n");
        printf("12) Average of the given numbers : \n");
        printf("13) Standart deviation of the given list of numbers : \n");
        printf("14) Exit. \n");
        printf("Please enter your choice 1-14: ");
        scanf("%d",&choice);
        if (choice>14 || choice<1)
        {
            printf("Please enter number between 1 and 5.\n");
        }
        else
        {
            
            if (choice==1) // summation
            {
                printf("Please enter the first number: ");
                scanf("%lf",&x1);
                printf("Please enter the second number: ");
                scanf("%lf",&x2);
                result=summation(x1,x2);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf + %lf = %lf \n",x1,x2,result);
            }
            if (choice==2) // subtraction
            {
                printf("Please enter the first number: ");
                scanf("%lf",&x1);
                printf("Please enter the second number: ");
                scanf("%lf",&x2);
                result=subtraction(x1,x2);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf - %lf = %lf \n",x1,x2,result);
            }
            if (choice==3) // multiplication
            {
                printf("Please enter the first number: ");
                scanf("%lf",&x1);
                printf("Please enter the second number: ");
                scanf("%lf",&x2);
                result=multiplication(x1,x2);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf * %lf = %lf \n",x1,x2,result);
            }
            if (choice==4) // divison
            {
                printf("Please enter the first number: ");
                scanf("%lf",&x1);
                printf("Please enter the second number: ");
                scanf("%lf",&x2);
                result=division(x1,x2);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf / %lf = %lf \n",x1,x2,result);
            }
            if (choice==5) // history save
            {
                for(int i=0;i<index;i++){
                    printf("%d. calculation: %lf \n",i+1,*(calc_hist+i));
                }
            }
            if (choice==6) // square root
            {
                printf("Please enter the first number: ");
                scanf("%lf",&x1);
                result=square_root(x1);
                *(calc_hist+index)=result;
                index=index+1;
                printf("sqrt(%lf) = %lf \n",x1,result);
            }
            if (choice==7) // area of the circle
            {
                printf("Please enter the radius of the circle: ");
                scanf("%lf",&x1);
                result=area_circ(x1);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf * %lf * %lf = %lf \n",PI,x1,x1,result);
            }
            if (choice==8) // circumference of the circle
            {
                printf("Please enter the radius of the circle: ");
                scanf("%lf",&x1);
                result=circumference_circ(x1);
                *(calc_hist+index)=result;
                index=index+1;
                printf("2 * %lf * %lf = %lf \n",PI,x1,result);
            }
            if (choice==9) // degrees to rad
            {
                printf("Please enter an angle in degrees to convert rad: ");
                scanf("%d",&angle);
                result=deg_to_rad(angle);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%d degrees = %lf \n",angle,result);
            }
            if (choice==10)
            {
                printf("Please enter the base: ");
                scanf("%lf",&x1);
                printf("Please enter the exponent: ");
                scanf("%d",&exponent);
                result=exponential_f(x1,exponent);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%lf ^ %d = %lf \n",x1,exponent,result);
            }
            if (choice==11)
            {
                printf("Please enter the number to achieve factoriel: ");
                scanf("%d",&f_number);
                result=factoriel(f_number);
                *(calc_hist+index)=result;
                index=index+1;
                printf("%d ! = %d \n",f_number,(int)result);
            }
            if (choice==12)
            {
                printf("Please enter the lenght of the list of numbers: ");
                scanf("%d",&arr_length);
                for(int i=0;i<arr_length;i++){
                    printf("Please enter a number to add the list: ");
                    scanf("%d",&array[i]); // appending numbers to array
                }
                result=average(arr_length,array);
                *(calc_hist+index)=result;
                index=index+1;
                printf("Average of the given numbers is: %lf \n",result);
            }
            if (choice==13)
            {
                printf("Please enter the lenght of the list of numbers: ");
                scanf("%d",&arr_length);
                for(int i=0;i<arr_length;i++){
                    printf("Please enter a number to add the list: ");
                    scanf("%d",&array[i]); // appending numbers to array
                }
                result=std(arr_length,array);
                *(calc_hist+index)=result;
                index=index+1;
                printf("Standart deviation of the given numbers is: %lf \n",result);
            }
        }
        
        
    } while (choice!=14);
    printf("Exit the program.\n");
    free(calc_hist);

    return 0;
    
}

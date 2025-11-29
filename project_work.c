#include <stdio.h>
#include <math.h>
#include<stdlib.h>

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


int main(){
    int choice,calc_space,index=0;
    double x1,x2,result;
    double* calc_hist; 
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
        printf("6) Exit. \n");
        printf("Please enter your choice 1-6: ");
        scanf("%d",&choice);
        if (choice>6 || choice<1)
        {
            printf("Please enter number between 1 and 5.\n");
        }
        else
        {
            
            if (choice==1)
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
            if (choice==2)
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
            if (choice==3)
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
            if (choice==4)
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
            if (choice==5)
            {
                for(int i=0;i<index;i++){
                    printf("%d. calculation: %lf \n",i+1,*(calc_hist+i));
                }
            }
        }
        
        
    } while (choice!=6);
    printf("Exit the program.\n");
    free(calc_hist);

    return 0;
    
}

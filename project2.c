#include <stdio.h>
#include <math.h>

int prime_control(int);
int fibonacci(int);

int main()
{
    int day,x,p,f,age,code;
    char letter;
        printf("Please enter your birtday between 1 and 7 (example Monday=1 Tueasday=2...)\n");
        
        do
        {
            scanf("%d",&day);
            getchar();
            if(day<1 || day>7)printf("Please enter a appropriate day!\n");
        }while(day<1 || day>7);

        printf("Please enter initial letter of your name(Capital english letters only)\n");

        do
        {
            scanf("%c",&letter);
            getchar();
            if(letter<'A' || letter>'Z')printf("\nPlease enter a appropriate letter!\n");
        }while(letter<'A' || letter>'Z');

        printf("%c--->%d\n",letter,letter%4);

        printf("What is the %dth power of %d?\n",day,letter%4);

        do
        {
            scanf("%d",&x);
            if(x != pow(letter%4,day))printf("It is not correct!\n");
        }while(x != pow(letter%4,day));

        printf("How many prime numbers can you count until %d?\n",x);

        do
        {
            scanf("%d",&p);
            if(p != prime_control(x))printf("It is not correct!\n");
        }while(p != prime_control(x));

        printf("Enter the %dth element of fibonacci series\n",p);

        do
        {
            scanf("%d",&f);
            if(f != fibonacci(p))printf("It is not correct!\n");
        }while(f != fibonacci(p));

        printf("Enter your age (between of 1-100)\n");
        
        do
        {
            scanf("%d",&age);
            if(age<1 || age>100)printf("This is not correct!\n");
        }while(age<1 || age>100);

        printf("What is the result of %d*%d?\n",age,f);

        do
        {
            scanf("%d",&code);
            if(code != age*f)printf("This is not correct!\n");
        }while(code != age*f);

        printf("Congratulations! YOu found the code! The code is %d",code);

        return 0;
}

int prime_control(int a)
{
    int i,j,x=0;

        if(a<2)return 0;

        for(j=2;j<=a;j++)
        {
            for(i=2;i<=j;i++)
            {
                if(j==i)
                {
                    x++;
                    break;
                }
                else if(j%i==0)break;
            }
        }
    return x;
}

int fibonacci(int a)
{
    int i,number=1,conumber=1;

    if(a==0)return 0;

    for(i=1;i<a;i++)
    {
        number =  number + conumber;
        conumber = number - conumber;
    }

    return conumber;
}

// 1 1 2 3 5 8 13 21
#include <stdio.h>
/*
质数又称素数，定义为在大于1的自然数中
除了1和它本身没有其他的因数
*/
int main()
{
    for (int i=1; i<=200 ; i+=2){ //偶数一定是不是素数，则只需要判断其中的奇数
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    return 0;
}
//判断是否为素数，则是判断在其平方根区间里是否存在能被其整除的自然数，如果有则非素数，否则就是素数
int  isPrime(n){
    if (n == 1) return 0;
  //下面的两句语句可以不写，写的原因就是增加它的通用性
    if (n == 2) return 1;
    if (n%2 == 0) return 0; // 所有偶数都不是素数

    for (int i = 3; i * i <= n; i += 2)  // 只需要检查奇数
        if (n%i == 0) return 0;
    return 1;
}

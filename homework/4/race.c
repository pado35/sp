#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define LOOPS 100000
int account_balance = 1000; // 初始帳戶餘額
int deposit_amount = 50; // 每次存款金額
int withdraw_amount = 30; // 每次提款金額
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *deposit(void *arg) {
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex1);
        int temp = account_balance;
        temp += deposit_amount;
        account_balance = temp;

        if ((account_balance - deposit_amount) + deposit_amount != account_balance) {
            printf("Error in deposit: account_balance=%d\n", account_balance);
        }
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}

void *withdraw(void *arg) {
    for (int i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex1);
        int temp = account_balance;
        temp -= withdraw_amount;
        account_balance = temp;

        if ((account_balance + withdraw_amount) - withdraw_amount != account_balance) {
            printf("Error in withdraw: account_balance=%d\n", account_balance);
        }
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, deposit, NULL);
    pthread_create(&thread2, NULL, withdraw, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("Final account_balance=%d\n", account_balance);
    return 0;
}

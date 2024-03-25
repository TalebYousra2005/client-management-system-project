#include <studio.h>

#define MAX_CLIENTS 100

int clientQueue[MAX_CLIENTS];
int clientCount = 0;
int servedClients[3]= {0};

void registerClient(){
    clientQueue[clientCount++] = clientCount + 1;
    printf("Client %d has been registered \n", clientCount);
};

void serveClient(int employeeNumber){
    if(clientCount > 0){
        printf("Employee %d is serving client %d",employeeNumber, clientQueue[0]);
        servedClients[employeeNumber - 1]++;
        for (int i=0; i < clientCount; i++){
            clientQueue[i]=clientQueue[i + 1];
        }
        clientCount--;
    }else{
        printf("no clients in queue");
    }
}

void productivityReport(){
    printf("Employee 1 has served %d clients \n", servedClients[0]);
    printf("Employee 2 has served %d clients \n", servedClients[1]);
    printf("Employee 3 has served %d clients \n", servedClients[2]);
}

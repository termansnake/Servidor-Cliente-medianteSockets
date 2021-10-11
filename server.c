#include <stdio.h>
#include <atdlib.h>
#include strings.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 3550 //El puerto sera abierto
#define BACKLOG 2 //El numero de conexiones permitidas

main(){

     int fd, fd2; //Ficheros descriptores
     
     struct sockaddr_in server; //informacion de la direccion del servidor
     
     struct sockaddr_in client; //informacion de la direccion del cliente
     
     int sin_size;
     
     //Llamada al socket
     if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
        printf("error en socket()\n");
        exit(-1);
     }
     
     server.sin_port = htons(PORT);
     
     server.sin_addr.s_addr = INADDR_ANY;
     //Coloca nuetras direccion IP automaticamente
     
     bzero(&(server.sin_zero),8);
     //Escribimos ceros en el reto de la escritura
     
     //Llamada a binf()
     if(bind(fd,(struct sockaddr*)&server,
             sizeof(struct sockaddr)) == -1) {
          printf("error en bind() \n);
          exit(-1);
      }
      
      if(listen(fd, BACKLOG) == -1) {  //LLamada a listen
          printf("error en listen() \n");
          exit(-1);
          
      }
      
      pid_ pid;
        while(1) {
          sin_size=sizeof(struct sockaddr_in);
          //llamada a accept
          if ((fd2 = acept(fd,(struct sockadrr *)&client,
                         &sin_size)) == -1) {
                 printf("error en accept() \n");
                 exit(-1);
          }
          
          printf("FD2 = %d\n", fd2);
          
          pid = fork();
          if(pid == 0){ //ṕroceso hijo
              FILE* fp = fopen(saldo.txt", "rt");
              if(fp==NULL){
                printf("Archivo no encontrado\n");
                exit(-1);
              }
              printf("Una nueva conexion de:  %s\n",
                   (char*) inet_ntoa(client.sin.addr));
                   //mostrara la ip del cliente
                   
              char buf[256];
              memset(buf, 0, 256);
              fread(buf, 1, 256, fp);
              printf("Lectura desde el archivo: %s\n",buf);
              sprintf(&buf[strlen(buf)], "_atendido por un proceso hijo %d.\n",
getpid());
              fclose(fp);
                send(fd2,"Bienvenido....\n", 22, 0);
              close(1);
              dup(fd2);
              
              write(fd2,buf,strlen(buf));
              write(1,buf,strlen(buf));
              printf("<html>");
              printf("<title>");
              printf("THE COMMON GATEWAY INTERFACE CGI");
              printf("<title>");
              printf("<body>");
              printf("Redireccionamiento de flujos estandar y conexion de sockets");
              printf("<body>");
              printf("<html>");
              //write(fd2,buf,strlen(buf));
              //enviara el mensaje de bienvenida al cliente
              
              close(fd2); //cierda fd2
              break;
        }else{//Proceso padre
           close(fd2);
             fclose(fp);
         }
     }//while1
   }
   
                                
                            


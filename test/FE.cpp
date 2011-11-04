#include <iostream>
#include "FrontEnd.h"
#include "Ping_FE.h"


int main(int argc, char *argv[])
{
   /* Start the front-end side of the network */
   FrontEnd *FE = new FrontEnd();
   FE->Init("topology_1x4.txt", "./BE", NULL);

   /* Load the protocols the network understand */
   FrontProtocol *prot = new Ping();
   FE->LoadProtocol( prot )  ;

   /* Execute protocol "PING" */
   Protocol *p;
   FE->Dispatch("PING", p);

   /* Shutdown the network */
   FE->Shutdown();

   return 0;
}



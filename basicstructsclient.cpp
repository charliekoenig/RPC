#include "basicstructs.idl"

#include "rpcproxyhelper.h"

#include "c150debug.h"
#include "c150grading.h"
#include <fstream>
#include <ctime>
#include <random>

using namespace std;          // for C++ std library
using namespace C150NETWORK;  // for all the comp150 utilities 

// forward declarations
void setUpDebugLogging(const char *logname, int argc, char *argv[]);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                    Command line arguments
//
// The following are used as subscripts to argv, the command line arguments
// If we want to change the command line syntax, doing this
// symbolically makes it a bit easier.
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

const int serverArg = 1;     // server name is 1st arg


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                           main program
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
int 
main(int argc, char *argv[]) {

     //
     //  Set up debug message logging
     //
     setUpDebugLogging("simplefunctionclientdebug.txt",argc, argv);

     //
     // Make sure command line looks right
     //
     if (argc != 2) {
       fprintf(stderr,"Correct syntxt is: %s <servername> \n", argv[0]);
       exit(1);
     }

     //
     //  DO THIS FIRST OR YOUR ASSIGNMENT WON'T BE GRADED!
     //
     
     GRADEME(argc, argv);

     //
     //     Call the functions and see if they return
     //
     try {
       //
       // Set up the socket so the proxies can find it
       //
       rpcproxyinitialize(argv[serverArg]);

       // 
       // Call (possibly remote) add
       //

       srand(time(NULL));

        StructWithArrays x[10];
       for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                // Person p;
                // p.firstname = "lol";
                // p.lastname = "hi";
                // p.age = rand() % 100;
                x[i].people[j].age = rand() % 100;
        }
       }

       int firstInd = rand() % 10;
       int secondInd = rand() % 10;
       int maxAge = (rand() % 100) + 100;

//        x[firstInd].people[secondInd].firstname = "old";
//        x[firstInd].people[secondInd].lastname = "bob";
       x[firstInd].people[secondInd].age = maxAge;

      //  for (int i = 0; i< 10; i++) {
      //   for (int j = 0; j < 10; j++) {
      //       printf("[%d][%d]: %d\n", i, j, x[i].people[j].age);
      //   }
      //  }

       printf("Calling Person oldestAge(StructWithArrays x[10])\n");
       int result = oldestAge(x);                       // remote call (we hope!)
       printf("Returned from oldestAge(StructWithArrays x[10]). Result=%d, should be %d\n",result, maxAge);

     }

     //
     //  Handle networking errors -- for now, just print message and give up!
     //
     catch (C150Exception& e) {
       // Write to debug log
       c150debug->printf(C150ALWAYSLOG,"Caught C150Exception: %s\n",
			 e.formattedExplanation().c_str());
       // In case we're logging to a file, write to the console too
       cerr << argv[0] << ": caught C150NetworkException: " << e.formattedExplanation() << endl;
     }

     return 0;
}

void setUpDebugLogging(const char *logname, int argc, char *argv[]) {
     ofstream *outstreamp = new ofstream(logname);
     DebugStream *filestreamp = new DebugStream(outstreamp);
     DebugStream::setDefaultLogger(filestreamp);

     c150debug->setPrefix(argv[0]);
     c150debug->enableTimestamp(); 

     c150debug->enableLogging(C150ALLDEBUG | C150RPCDEBUG | C150APPLICATION | C150NETWORKTRAFFIC | 
			      C150NETWORKDELIVERY); 
}

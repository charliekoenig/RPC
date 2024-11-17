// --------------------------------------------------------------
//
//                        arithmeticclient.cpp
//
//        Author: Noah Mendelsohn         
//   
//
//        This is a test program designed to call a few demonstration
//        functions, after first enabling the COMP 150-IDS rpcproxyhelper.
//        (The purpose of the helper is to open a TCP stream connection
//        to the proper server, and to leave the socket pointer where
//        the generated proxies can find it.
//
//        NOTE: Although this example does nothing except test the
//        functions, we may test your proxies and stubs with client
//        applications that do real work. 
//
//        NOTE: When actually testing your RPC submission, you will use
//        a different client application for each set of functions. This
//        one is just to show a simple example.
//
//        NOTE: The only thing that makes this different from 
//        an ordinary local application is the call to
//        rpcproxyinitialize. If you commented that out, you could
//        link this with the local version of simplefunction.o
//        (which has the remotable function implementations)			      
//
//        COMMAND LINE
//
//              arithmeticclient <servername> 
//
//        OPERATION
//
//
//       Copyright: 2012 Noah Mendelsohn
//     
// --------------------------------------------------------------


// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE REMOTING. OF COURSE, THE PARTICULAR IDL FILE
// IS CHOSEN ACCORDING TO THE TEST OR APPLICATION
// 
// NOTE THAT THIS IS THE SAME IDL FILE INCLUDED WITH THE PROXIES
// AND STUBS, AND ALSO USED AS INPUT TO AUTOMATIC PROXY/STUB
// GENERATOR PROGRAM


#include "rpcproxyhelper.h"

#include "c150debug.h"
#include "c150grading.h"
#include <fstream>
#include <string>

using namespace std;          // for C++ std library
#include "stringstruct.idl"
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
       string result; 

       //
       // Set up the socket so the proxies can find it
       //
       rpcproxyinitialize(argv[serverArg]);

       Person p;
       p.firstname = "charlie";
       p.lastname = "koenig";
       p.age = 22;
       // 
       // Call (possibly remote) add
       //
       printf("Calling findLastName(p)\n");
       result = findLastName(p);                          // remote call (we hope!)
       printf("Returned from findLastName(p). Result=%s\n",result.c_str());

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



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//
//                     setUpDebugLogging
//
//        For COMP 150-IDS, a set of standards utilities
//        are provided for logging timestamped debug messages.
//        You can use them to write your own messages, but 
//        more importantly, the communication libraries provided
//        to you will write into the same logs.
//
//        As shown below, you can use the enableLogging
//        method to choose which classes of messages will show up:
//        You may want to turn on a lot for some debugging, then
//        turn off some when it gets too noisy and your core code is
//        working. You can also make up and use your own flags
//        to create different classes of debug output within your
//        application code
//
//        NEEDSWORK: should be factored into shared code w/pingstreamserver
//        NEEDSWORK: document arguments
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
void setUpDebugLogging(const char *logname, int argc, char *argv[]) {
     ofstream *outstreamp = new ofstream(logname);
     DebugStream *filestreamp = new DebugStream(outstreamp);
     DebugStream::setDefaultLogger(filestreamp);

     c150debug->setPrefix(argv[0]);
     c150debug->enableTimestamp(); 

     c150debug->enableLogging(C150ALLDEBUG | C150RPCDEBUG | C150APPLICATION | C150NETWORKTRAFFIC | 
			      C150NETWORKDELIVERY); 
}

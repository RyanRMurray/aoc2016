 1 #include <hashlibpp.h>
 2 #include <string>
 3 #include <iostream>  //for "cerr"
 4 
 5 /*
 6  * creating a wrapper object
 7  */
 8 hashwrapper *myWrapper = new md5wrapper();
 9 
10 try
11 {
12         /*
13          * create a hash from a string
14          */
15         std::string hash1 = myWrapper->getHashFromString("Hello World");
16 
17         /*
18          * create a hash based on a file
19          */
20         std::string hash2 = myWrapper->getHashFromFile("README.TXT");
21 }
22 catch(hlException &e)
23 {
24 
25         std::cerr << "Error(" 
26                   << e.error_number()
27                   << "): "
28                   << e.erro_message()
29                   << std::endl;
30 }
31 
32 delete myWrapper;
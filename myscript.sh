Script started on Sat 16 Mar 2019 12:55:28 AM PDT
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ls
EditDistance.cpp  input1.txt  input2.txt  input3.txt  Makefile  sample.txt  typescript
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ make
==================================================
To build your code, use:
  make edit      # For EditDistance.cpp

To clean this subdirectory (remove object files
and other junk), use:
  make clean
==================================================
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ make edit
g++ -g -O3 -g -o EditDistance.o -c EditDistance.cpp
g++ -O3 -g -o edit EditDistance.o
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit sample.txt


Edit Distance =  54

Operation       	 cost 	 Total 	 z 
------------------------------------------------------------------
initial string  	 0 	 0 	 electrical engineering
delete          	 2 	 2 	 lectrical engineering
delete          	 2 	 4 	 ectrical engineering
delete          	 2 	 6 	 ctrical engineering
right           	 0 	 6 	 ctrical engineering
insert          	 3 	 9 	 cotrical engineering
insert          	 3 	 12 	 comtrical engineering
insert          	 3 	 15 	 comptrical engineering
insert          	 3 	 18 	 computrical engineering
right           	 0 	 18 	 computrical engineering
insert          	 3 	 21 	 computerical engineering
right           	 0 	 21 	 computerical engineering
delete          	 2 	 23 	 computercal engineering
delete          	 2 	 25 	 computeral engineering
delete          	 2 	 27 	 computerl engineering
delete          	 2 	 29 	 computer engineering
right           	 0 	 29 	 computer engineering
delete          	 2 	 31 	 computer ngineering
replace         	 4 	 35 	 computer sgineering
replace         	 4 	 39 	 computer scineering
right           	 0 	 39 	 computer scineering
delete          	 2 	 41 	 computer scieering
delete          	 2 	 43 	 computer sciering
right           	 0 	 43 	 computer sciering
delete          	 2 	 45 	 computer scieing
delete          	 2 	 47 	 computer scieng
right           	 0 	 47 	 computer scieng
insert          	 3 	 50 	 computer sciencg
replace         	 4 	 54 	 computer science
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit input1.txt


Edit Distance =  1816

]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit input2.txt


Edit Distance =  1824

]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit input2.txt


Edit Distance =  1824

]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit input3.e[Ktxt


Edit Distance =  1829

]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ./edit
Please input .txt file name
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ m[Kls
[0m[01;32medit[0m              EditDistance.o  input2.txt  Makefile    typescript
EditDistance.cpp  input1.txt      input3.txt  sample.txt
[m]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ make clean
rm -f core *.o *~ edit
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ ls
EditDistance.cpp  input1.txt  input2.txt  input3.txt  Makefile  sample.txt  typescript
]0;tmyat@bondi:hw4[tmyat@bondi hw4]$ exit
exit

Script done on Sat 16 Mar 2019 12:56:27 AM PDT

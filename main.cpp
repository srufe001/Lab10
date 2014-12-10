//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab10/
/// @brief Lab 10 for CS 12 Fall 2014
///
/// @author Samuel Rufer [srufe001@ucr.edu]
/// @date December 9, 2013
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Ali
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include "Music_collection.h"
#include<iostream>

using namespace std;

int main()
{
   Tune a("sing song ding dong");
   Tune b("let it go");
   Tune c("discovery channel monkey song");
   Tune d("O Tannenbaum");
   Tune e("Dancing Queen");
   Tune f("Gimme Gimme Gimme");
   Music_collection A;
   A.add_tune(a);
   A.add_tune(b);
   A.add_tune(c);

   //explicitly call copy constructor to create B
   Music_collection B(A);
   B.set_tune(1, d);

   Music_collection C;
   //copy assignment operator
   C = B;

   B.add_tune(e);

   C.set_tune(2, f);

   cout << "#####collection a#####\n" << A << "#####collection b#####\n" << B
        << "#####collection c#####\n" << C; 
      
   return 0;
}

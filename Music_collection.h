//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab10/Music_collection.h
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
#ifndef __MUSIC_COLLECTION_H__
#define __MUSIC_COLLECTION_H__

#include<string>

using namespace std;

//Tune class

class Tune
{
  private:
   string title;
  public:
   Tune();
   Tune(const string & n);
   const string & get_title() const;
};

//Music_collection class

class Music_collection
{
  private:
   int number;
   int max;
   Tune * collection;
  public:
   //Constructors
   //sets max to 100
   Music_collection();
   //sets max to n
   Music_collection(int n);

   //Destructor
   ~Music_collection();

   //Copy constructor
   Music_collection(const Music_collection &m);

   //copy assignment operator
   Music_collection & operator=(const Music_collection &m);

   //returns true if add was successful, false otherwise
   bool add_tune(const Tune &t);

   //sets Tune at position index in collection to t, returns true if
   //index < number
   bool set_tune(int index, const Tune &t);

   //overloaded stream insertion operator
   //outputs the title fo each Tune in collection on a seperate line
   friend ostream & operator<<(ostream &out, const Music_collection &m);
};

#endif

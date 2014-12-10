//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab10/Music_collection.cpp
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
#include<string>
#include<iostream>

using namespace std;

Music_collection::Music_collection()
: max(100), number(0), collection(new Tune [max])
{ }

Music_collection::Music_collection(int n)
: max(n), number(0), collection(new Tune [max])
{ }

Music_collection::~Music_collection()
{
   delete[] collection;
}

Music_collection::Music_collection(const Music_collection & m)
: max(m.max), number(m.number), collection(new Tune [max])
{
   //copy each tune from m into this
   for (int i = 0; i < number; ++i)
   {
      collection[i] = m.collection[i];
   }
}

Music_collection & Music_collection::operator=(const Music_collection & m)
{
   //check for self-assignment
   if (this != &m)
   {
      //shallow-copy max and number
      max = m.max;
      number = m.number;
      //delete and recreate current collection
      delete[] collection;
      collection = new Tune [max];
      //deep-copy collection
      for (int i = 0; i < number; ++i)
      {
         collection[i] = m.collection[i];
      }
   }
   //return itself
   return *this;
}

bool Music_collection::add_tune(const Tune & t)
{
   //check if collection is full
   if (number == max) return false;

   //add the tune and increment number of tunes
   collection[number++] = t;
   return true;
}

bool Music_collection::set_tune(int index, const Tune & t)
{
   //check if index already contains a tune
   if (index >= number) return false; 

   //insert the new tune
   collection[index] = t;

   //return true since a tune was replaced
   return true;
}

ostream & operator<<(ostream & out, const Music_collection & m)
{
   //add all tunes to the stream, with newlines after each tune
   for (int i = 0; i < m.number; ++i)
   {
      out << m.collection[i].get_title() << "\n";
   }
   return out;
}

//Tune methods

Tune::Tune()
: title()
{ }

Tune::Tune(const string & n)
: title(n)
{ }

const string & Tune::get_title() const
{
   return title;
}

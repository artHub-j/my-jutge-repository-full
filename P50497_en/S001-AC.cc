/*
Write a function that tells if s is a palindrome or not. Remember that a word is a palindrome if it reads the same from left to right than from right to left. In this exercise, s can be rather large; this is why it is passed by reference.

In order to compare the efficiency of your solution against the efficiency of the solution of the Judge, start checking s from its ends.
*/
#include <iostream>

using namespace std;

bool is_palindrome(const string& s){
  unsigned long size = s.size();
  if (size == 1) return true;
  for (unsigned long i = size-1; i >= size/2; --i){
    if (s[i] != s[(size-1)-i]) return false;
  }
  return true;
}

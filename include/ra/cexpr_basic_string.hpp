//Author: Tania Akter, V00810640

#ifndef cexpr_basic_string_hpp
#define cexpr_basic_string_hpp

#include <cstddef>
#include <iostream>

namespace ra::expr {
  template <class T, std::size_t M>
  class cexpr_basic_string
  {
    public:
      // An unsigned integral type used to represent sizes.
      using size_type = std::size_t ;

      // The type of each character in the string (i.e., an alias for
      // the template parameter T).
      using value_type = T;

      // The type of a mutating pointer to each character in the string.
      using pointer = T *;

      // The type of a non-mutating pointer to each character in the
      // string.
      using const_pointer = const T *;

      // The type of a mutating reference to a character in the string.
      using reference = T &;

      // The type of a non-mutating reference to a character in the
      // string.
      using const_reference = const T &;

      // A mutating iterator type for the elements in the string.
      using iterator = pointer ;

      // A non-mutating iterator type for the elements in the string.
      using const_iterator = const_pointer ;

      // Creates an empty string (i.e., a string containing no
      // characters).
      constexpr cexpr_basic_string ()
      {
        str[0] = value_type(0); 
      }

      // Explicitly default some special members.
      constexpr cexpr_basic_string (const cexpr_basic_string &) =
      default;
      
      constexpr cexpr_basic_string & operator=(
      const cexpr_basic_string &) = default;
      ~cexpr_basic_string () = default;

      // Creates a string with the contents given by the
      // null-terminated character array pointed to by s.
      // If the string does not have sufficient capacity to hold
      // the character data provided, an exception of type
      // std::runtime_error is thrown.
      constexpr cexpr_basic_string (const value_type * s )
      {
          size_type i = 0;
          for(i; s[i] != value_type(0) ; ++i)
          {
            if(i >= M)
            {
              std::cout << std::endl;
              std::cout << "Scream and Die" << std::endl;
            }
            str[i] = s[i];
          }

          str[i] = s[i];
      }

      // Creates a string with the contents specified by the characters
      // in the iterator range [first, last).
      // If the string does not have sufficient capacity to hold
      // the character data provided, an exception of type
              // // std::runtime_error is thrown.
      constexpr cexpr_basic_string ( const_iterator first ,
      const_iterator last );

      // Returns the maximum number of characters that can be held by a
      // string of this type.
      // The value returned is the template parameter M.
      static constexpr size_type max_size ();

      // Returns the maximum number of characters that the string can
      // hold. The value returned is always the template parameter M.
      constexpr size_type capacity () const;

      // Returns the number of characters in the string (excluding the
      // dummy null character).
      constexpr size_type size () const;

      // Returns a pointer to the first character in the string.
      // The pointer that is returned is guaranteed to point to a
      // null-terminated character array.
      // The program shall not alter the dummy null character stored
      // at data() + size().
      pointer data ();
      const value_type * data () const;

      // Returns an iterator referring to the first character in the
      // string.
      constexpr iterator begin ();
      constexpr const_iterator begin () const;

      // Returns an iterator referring to the fictitious
      // one-past-the-end character in the string.
      constexpr iterator end ();
      constexpr const_iterator end () const;

      // Returns a reference to the i-th character in the string if i
      // is less than the string size; and returns a reference to the
      // dummy null character if i equals the string size.
      // Precondition: The index i is such that i >= 0 and i <= size().
      constexpr reference operator[]( size_type i );
      constexpr const_reference operator[]( size_type i) const;

      // Appends (i.e., adds to the end) a single character to the
      // string. If the size of the string is equal to the capacity,
      // an exception of type std::runtime_error is thrown.
      constexpr void push_back (const T& x );

      // Erases the last character in the string.
      // If the string is empty, an exception of type std::runtime_error
      // is thrown.
      constexpr void pop_back ();
      // Appends (i.e., adds to the end) to the string the
      // null-terminated string pointed to by s.
      // Precondition: The pointer s must be non-null.
      // If the string has insufficient capacity to hold the new value
      // resulting from the append operation, the string is not modified
      // and an exception of type std::runtime_error is thrown.
      constexpr cexpr_basic_string & append (const value_type * s );

      // Appends (i.e., adds to the end) to the string another
      // cexpr_basic_string with the same character type (but
      // possibly a different maximum size).
      // If the string has insufficient capacity to hold the new value
      // resulting from the append operation, the string is not modified
      // and an exception of type std::runtime_error is thrown.
      template <size_type OtherM>
      constexpr cexpr_basic_string & append (
      const cexpr_basic_string < value_type , OtherM >& other );

      // Erases all of the characters in the string, yielding an empty
      // string.
      constexpr void clear ();
    
    private:
      value_type str[M];
      
  };
  
  // Alias template
  template <std::size_t M >
  using cexpr_string = cexpr_basic_string <char, M>;

  constexpr std::size_t to_string ( std::size_t n , char* buffer ,
          std::size_t size , char** end );
}
#endif

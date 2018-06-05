//Author: Tania Akter, V00810640

#ifndef cexpr_basic_string_hpp
#define cexpr_basic_string_hpp

#include <cstddef>
#include <iostream>

namespace ra{
namespace expr {
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

          while(s[i] != value_type(0))
          {
            if(i >= M)
            {
              throw std::runtime_error("String cannot hold value");
            }
            str[i] = s[i];
            ++i;
          }
          str[i] = s[i];
      }

      // Creates a string with the contents specified by the characters
      // in the iterator range [first, last).
      // If the string does not have sufficient capacity to hold
      // the character data provided, an exception of type
              // // std::runtime_error is thrown.
      constexpr cexpr_basic_string ( const_iterator first ,
      const_iterator last )
      {
        size_type size_s = 0;
        while(first != last)
        {
          if(size_s > M)
          {
            // std::cout << *first << std::endl;
            // std::cout << size_s << std::endl;
            throw std::runtime_error("String does not have sufficent capacity to hold string passed by start and end iterator");
          }
          str[size_s] = *first;
          ++first;
          ++size_s;
        }
        str[size_s] = value_type(0);
      }

      // Returns the maximum number of characters that can be held by a
      // string of this type.
      // The value returned is the template parameter M.
      static constexpr size_type max_size ();

      // Returns the maximum number of characters that the string can
      // hold. The value returned is always the template parameter M.
      constexpr size_type capacity () const
      {
        return M;
      }

      // Returns the number of characters in the string (excluding the
      // dummy null character).
      constexpr size_type size () const
      {
        const_pointer v = str;
        size_type size = 0;
        
        //stop before the dummy characterS
        while(*v != value_type(0))
        {
          ++v;
          ++size;          
        }
        return size;
      }

      // Returns a pointer to the first character in the string.
      // The pointer that is returned is guaranteed to point to a
      // null-terminated character array.
      // The program shall not alter the dummy null character stored
      // at data() + size().
      value_type * data ()
      {
        return str;
      }

      const value_type * data () const
      {
        return str;
      }

      // Returns an iterator referring to the first character in the
      // string.
      constexpr iterator begin ()
      {
        return str;
      }

      constexpr const_iterator begin () const
      {
        return str;
      }

      // Returns an iterator referring to the fictitious
      // one-past-the-end character in the string.
      constexpr iterator end ()
      {
        return str + size() + 1;
      }
      constexpr const_iterator end () const
      {
        return str + size() + 1;        
      }

      // Returns a reference to the i-th character in the string if i
      // is less than the string size; and returns a reference to the
      // dummy null character if i equals the string size.
      // Precondition: The index i is such that i >= 0 and i <= size().

      //TODO: ASK WHAT THE PRECONDITION DOES, do we throw otherwise?
      constexpr reference operator[]( size_type i )
      {
        return str[i];
      }

      constexpr const_reference operator[]( size_type i) const
      {
        return str[i];
      }

      // Appends (i.e., adds to the end) a single character to the
      // string. If the size of the string is equal to the capacity,
      // an exception of type std::runtime_error is thrown.
      constexpr void push_back (const T& x )
      {
        if(size() == M)
        {
          throw std::runtime_error("Size of the string is equal to its capacity.");
        }
        str[size()] = x;
      }

      // Erases the last character in the string.
      // If the string is empty, an exception of type std::runtime_error
      // is thrown.
      constexpr void pop_back ()
      {
        if(size() == 0)
        {
          throw std::runtime_error("Size of the string is equal to its capacity.");          
        }
        str[size()-1] = value_type(0);
      }
      // Appends (i.e., adds to the end) to the string the
      // null-terminated string pointed to by s.
      // Precondition: The pointer s must be non-null.
      // TODO: ASK WHAT HAPPENS IF PRECONDITION IS NOT MET
      // If the string has insufficient capacity to hold the new value
      // resulting from the append operation, the string is not modified
      // and an exception of type std::runtime_error is thrown.
      constexpr cexpr_basic_string & append (const value_type * s )
      {
        //check for the string length of the input
        const_pointer v = s;
        size_type  size_s = 0;
        
        //stop before the dummy characterS
        while(*v != value_type(0))
        {
          ++v;
          ++size_s;          
        }

        if(size() + size_s > M)
        {
          throw std::runtime_error("Insufficient capacity in the string to hold new string with append");
        }

        size_s = 0;        
        size_type i = size();
        while(s[size_s] != value_type(0))
        {
          str[i] = s[size_s];
          ++size_s;
          ++i;
        }
        str[i] = value_type(0);

        return *this;
      }

      // Appends (i.e., adds to the end) to the string another
      // cexpr_basic_string with the same character type (but
      // possibly a different maximum size).
      // If the string has insufficient capacity to hold the new value
      // resulting from the append operation, the string is not modified
      // and an exception of type std::runtime_error is thrown.
      template <size_type OtherM>
      constexpr cexpr_basic_string & append (
      const cexpr_basic_string < value_type , OtherM >& other )
      {
        const_pointer s = other.data();
        if(size() + other.size() > M)
        {
          throw std::runtime_error("Insufficient capacity in the string to hold new string with append");
        }

        size_type i = size();
        size_type size_s = 0;

        while(*s != value_type(0))
        {
          str[i] = *s;
          ++s;
          ++i;
        }
        str[i] = value_type(0);

        return *this;
      }

      // Erases all of the characters in the string, yielding an empty
      // string.
      constexpr void clear ()
      {
        str[0] = value_type(0);
      }
    
    private:
      value_type str[M+1] = {0};
      
  };
  
  // Alias template
  template <std::size_t M >
  using cexpr_string = cexpr_basic_string <char, M>;

  constexpr std::size_t to_string ( std::size_t n , char* buffer , std::size_t size , char** end )
    {
      std::size_t i = 0;
      char *p = buffer;

      while(n != 0)
      {
        if( i >= size)
        {
          throw std::runtime_error("Buffer does not hold sufficent size to convert int to string.");
        }
        //get the remainder
        std::size_t r = n%10;
        
        //or add 48 since '0' is 48 is ASCII
        p[i] = r + '0';
        n /= 10;
        ++i;
      }
      
      p[i] = '\0';

      if(end != nullptr)
      {
        *end = &buffer[i];
      }
      return i;
    }
}
}
#endif

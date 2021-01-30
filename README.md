# HMK_Container-Array
a Safe array for C++

## Array::Array()
(1) None  
(2) fill of value `x`  
(3) initializer_list  
## Array::~Array()
None
## member function
### Array::begin()
return begin iterator
### Array::end()
return end iterator
### Array::cbegin()
return const begin()
### Array::cend()
return const end()
### Array::operator[]
if the argument is out of range  
return `-32767`  
  
if the argument is greater or equal than 0  
return `data[argument]`  
  
if the argument is less than 0  
return `data[Length-argument]`  
### Array::size()
return the size of Array

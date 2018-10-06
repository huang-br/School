#ifndef VECTOR_H
#define VECTOR_H

/*Below is a simple macro that specifies the type to be used in our vectors.
 * There is an #ifndef guard around it so that the compiler has the option of
 * defining a different type. For this assignment you are expected to refer
 * to elements in vectors as having type TYPE, though you may assume they are
 * numeric.*/
#ifndef TYPE
#define TYPE double
#endif /*ndef TYPE*/

/*Classes don't exist in C but the Object-Oriented Paradigm can still be
 * followed. structs are like class definitions, but these objects only
 * have variable fields and no methods/functions.*/
typedef struct {
	TYPE* values;
	int size;
} vector;

/*We can write functions the behave similar to constructors. This function
 * will return a pointer to a new vector of the given size.*/
vector* new_vector(int size);

/*We can write functions that behave like class methods, we just need to
 * pass in the pointer to the object in question as an additional argument.
 * */

/*eg: This function might have been vector::random_fill(min,max) in C++
 * This funtions fills in the vector with random values in the range
 * [min,max].*/
void vector_random_fill(vector* to_fill_ptr,TYPE min, TYPE max);

/*eg: This function might have been vector::copy() in C++
 * This function returns a pointer to a new vector that is a copy of the
 * first one.*/
vector* copy_of_vector(vector* to_copy_ptr);

/*eg: This function might have been vector::sub_copy(begin,end) in C++
 * This function returns a pointer to a new vector that is a copy of the
 * values from indices [begin,end).*/
vector* copy_of_sub_vector(vector* to_copy_ptr,int begin,int end);

/*This function behaves similar to a destructor in C++*/
void free_vector(vector* to_delete_ptr);

#endif /*ndef VECTOR_H*/

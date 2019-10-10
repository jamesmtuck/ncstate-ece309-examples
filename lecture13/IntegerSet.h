#ifndef INTEGER_SET
#define INTEGER_SET

// To keep things simple for now, we’ll just assume
// integers
class IntegerSet {
public:
   virtual bool insert(int) = 0;
   virtual bool find(int) = 0;
   virtual void remove(int) = 0;
};


#endif //INTEGER_SET
